#include <Iir.h>
#include <stdio.h>
#include <cmath>
#include <vector>

typedef void (*DataProcessed)(const std::vector<short> &);

class EnvelopeFollower {
public:
    EnvelopeFollower(int fs, int fc);
    ~EnvelopeFollower();
    void registerCallback(DataProcessed cb);
    void Process(std::vector<short> buffer);

private:
    DataProcessed callback;
    Iir::Butterworth::LowPass<4> filter;
    int fs;
    int fc;
    
};