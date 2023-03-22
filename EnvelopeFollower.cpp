#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>
#include "EnvelopeFollower.hpp"

EnvelopeFollower::EnvelopeFollower(int fs, int fc = 10){
    // Initialising the Envelope Follower object, including starting the thread.
    fs = fs;
    fc = fc;

    // setup lowpass filter
    filter.setup(fs, fc);

    start();
}

EnvelopeFollower::~EnvelopeFollower(){
    stop();
}

void EnvelopeFollower::start(){
    followerThread = new std::thread(&EnvelopeFollower::exec, this)
}

void EnvelopeFollower::stop(){
    if (follower.joinable()){
        {
            std::unique_lock<std::mutex> lock(mtx);
            stopThread = true;
        }
        cv.notify_one();
        follower.join();
    }
}

void EnvelopeFollower::registerCallback(DataAvailableCallback cb){
    callback = cb;
}

void EnvelopeFollower::Process(float sample){

    // Full-wave recitifier
    sample = abs(sample);

    // Low-pass filter
    out = filter.filter(sample);

    if (callback) {
        callback(out);
    }
}

static void EnvelopeFollower::exec(EnvelopeFollower* cppThread){
    cppThread->Process();
}