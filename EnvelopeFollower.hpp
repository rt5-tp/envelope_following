#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>

class EnvelopeFollower {
    public:
        int fs;
        int fc;

        Iir::Butterworth::LowPass<4> filter;
        
        float out;

        EnvelopeFollower(int fs, int fc);
        ~EnvelopeFollower();
        void start();
        void stop();
        void registerCallback();
        void Process(float sample);
        static void exec();

        std::thread followerThread;
};