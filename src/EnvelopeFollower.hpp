#include <Iir.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>

typedef void (*DataProcessed)(const std::vector<short> &);

class EnvelopeFollower {
public:
    int fs;
    int fc;

    Iir::Butterworth::LowPass<4> filter;

    float out;

    EnvelopeFollower(int fs, int fc);
    ~EnvelopeFollower();
    void registerCallback(DataProcessed cb);
    void Process(std::vector<short> buffer);
    static void exec();

    std::thread followerThread;

private:
    DataProcessed callback;
    
};