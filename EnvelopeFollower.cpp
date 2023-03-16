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

float EnvelopeFollower::Process(float sample){

    // Full-wave recitifier
    sample = abs(sample);

    // Low-pass filter
    out = filter.filter(sample);

    return out;
}