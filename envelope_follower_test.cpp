
#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>


int main(){
    // Load audio file
    AudioFile<float> audio;
    bool loadedOK = audio.load("test-audio.wav");
    assert (loadedOK);

    const int no_frames = audio.getNumSamplesPerChannel();
    const int fs = audio.getSampleRate();

    FILE *finput = fopen("Input.txt", "wt");
    FILE *foutput = fopen("20HzEnvelope.txt","wt");

    // IIR Filter
    // initialise lowpass filter
    Iir::Butterworth::LowPass<4> filter;
    filter.setup(fs, 20);

    for (int i = 0; i < audio.getNumSamplesPerChannel(); i++){
        for (int channel = 0; channel < audio.getNumChannels(); channel++){

            float sample = audio.samples[channel][i];

            fprintf(finput, "%f\n", sample);

            //Recitifcation
            sample = abs(sample);

            // low-pass filter
            float out = filter.filter(sample);

            // output
            // std::cout << out << std::endl;

            fprintf(foutput, "%f\n", out);
        }
    }

    // Plot output

    return 0;
}

