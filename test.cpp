#include <Iir.h>
#include <AudioFile.h>
#include <stdio.h>
#include <cmath>
#include "EnvelopeFollower.hpp"

int main()
{
    // Load audio file
    AudioFile<float> audio;
    bool loadedOK = audio.load("test-audio.wav");
    assert(loadedOK);

    const int no_frames = audio.getNumSamplesPerChannel();
    const int fs = audio.getSampleRate();

    FILE *finput = fopen("Input.txt", "wt");
    FILE *foutput = fopen("Envelope.txt", "wt");

    // IIR Filter
    EnvelopeFollower follower(fs,10);

    for (int i = 0; i < audio.getNumSamplesPerChannel(); i++)
    {
        for (int channel = 0; channel < audio.getNumChannels(); channel++)
        {

            float sample = audio.samples[channel][i];

            fprintf(finput, "%f\n", sample);

            float out = follower.Process(sample);

            fprintf(foutput, "%f\n", out);
        }
    }

    return 0;
}
