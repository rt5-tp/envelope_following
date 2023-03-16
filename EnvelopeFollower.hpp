#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>

class EnvelopeFollower {
    public:
        int fs;
        int fc;

        Iir::Butterworth::LowPass<4> filter;
        
        float out;

        EnvelopeFollower(int fs, int fc);

        float Process(float sample);
};