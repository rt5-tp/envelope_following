
#include <Iir.h>
#include "AudioFile.h"
#include <stdio.h>


int main(){
    // Input data

    // Load audio file
    AudioFile<float> audio;
    bool loadedOK = audio.load("test-audio.wav");
    assert (loadedOK);

    const int no_frames = audio.getNumSamplesPerChannel();
    const int fs = audio.getSampleRate();

    // Recitification

    // IIR Filter
    // initialise lowpass filter
    Iir::Butterworth::LowPass<4> filter;
    filter.setup(fs, 20);

    for (int i = 0; i < audio.getNumSamplesPerChannel(); i++){
        for (int channel = 0; channel < audio.getNumChannels(); channel++){

            float frame;
            frame = frame - 2250;
            frame = filter.filter(frame);

            std::cout << "looped" << std::endl;
        }
    }

    // Plot output

    return 0;
}

