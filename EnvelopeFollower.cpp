#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>
#include "EnvelopeFollower.hpp"

EnvelopeFollower::EnvelopeFollower(int fs, int fc = 10){

    fs = fs;
    fc = fc;

    // setup lowpass filter
    filter.setup(fs, fc);
}

EnvelopeFollower::~EnvelopeFollower(){
    stop();
}

void EnvelopeFollower::start(){
    follower = std::thread(&EnvelopeFollower::Process, this)
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

void EnvelopeFollower::register

float EnvelopeFollower::Process(float sample){

    // Full-wave recitifier
    sample = abs(sample);

    // Low-pass filter
    out = filter.filter(sample);

    return out;
}

uthread = new std::thread(EnvelopeFollower::exec, this);

static void EnvelopeFollower::exec(EnvelopeFollower* cppThread){
    cppThread->Process();
}

//New idea: fly-wheel