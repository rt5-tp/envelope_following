#include "../src/EnvelopeFollower.hpp"
#include "../src/AudioFile.h"

#include <gtest/gtest.h>

std::vector<short> envelope_buffer{};

// Tests that output from enevelope follower matches expected values of given audio
TEST(envelopFollowerTest, ReturnsExpectedValues){

    // Load audio file
    AudioFile<float> audio;
    bool loadedOK = audio.load("test-audio.wav");
    assert(loadedOK);

    int no_frames = audio.getNumSamplesPerChannel();
    int fs = audio.getSampleRate();

    EnvelopeFollower follower(fs,10);

    follower.registerCallback((DataProcessed)([](const std::vector<short> &buffer){
        for(auto element: buffer){
            envelope_buffer.push_back(element);
        }
    }));

    std::vector<short> buffer;

    for (int i = 0; i < no_frames; i++)
    {
        short sample = (short)(audio.samples[0][i]*10000);
        buffer.push_back(sample);

        if (buffer.size() == 4096) {

            follower.audio_callback(buffer);

            buffer.clear();
        }
    }

    EXPECT_EQ(envelope_buffer[0], 0);
    EXPECT_EQ(envelope_buffer[100000], 214);
    EXPECT_EQ(envelope_buffer[200000], 286);
    EXPECT_EQ(envelope_buffer[300000], 133);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
