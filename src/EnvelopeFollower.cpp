#include "EnvelopeFollower.hpp"
#include <Iir.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>

EnvelopeFollower::EnvelopeFollower(int fs, int fc = 10){
    // Initialising the Envelope Follower object, including starting the thread.
    this->fs = fs;
    this->fc = fc;

    // setup lowpass filter
    filter.setup(fs, fc);
}

EnvelopeFollower::~EnvelopeFollower(){
    
}

void EnvelopeFollower::registerCallback(DataProcessed cb){
    callback = cb;
}

void EnvelopeFollower::Process(std::vector<short> buffer){

    std::vector<short> out;

    for (auto sample : buffer){

        // Full-wave recitifier
        sample = abs(sample);

        // Low-pass filter
        out.push_back(filter.filter(sample));
    }

    if (callback) {
        callback(out);
    }
}