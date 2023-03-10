# Envelope Following

Various types of envelope follower are described by Rick Lyons [1]. At their most basic, they consist of a lowpass filter, which removes the higher frequecy 'carrier' frequencies from a signal to just leave the lower frequecy waveform of the shape the signal makes. This is the same as the decoding of an Amplitude Modulated radio signal. Additionally, the envelope should be entirely
positive-valued, so the negative values should be removed by
performing half or full-wave rectification. According to the
figures provided by Rick Lyons, the latter (asynchronous full-wave envelope detection) provides a smoother output, so this will be attempted.

My first attempt, then, will consist simply of an 'absolute'
operation then a lowpass IIR filter [2]. This will be tested using a wav imported using the AudioFile module [3].

**Tips**

To compile:
    "g++ envelope_follower.cpp -o envelope_follower -liir"

To convert wav files to raw use this terminal command:
    "ffmpeg -i input.wav -ac 1 -f s16le output.raw"

**Comments**

'AudioFile.h' is used to access the AudioFile module, since there was an issue installing the module properly. It is a direct copy from the AudioFile repository [3]. 'test-audio.wav' is also borrowed from the AudioFile repository.

**Citations**

[1] Lyons, Richard. (2017). Digital Envelope Detection: The Good, the Bad, and the Ugly [Tips and Tricks]. IEEE Signal Processing Magazine. 34. 183-187. 10.1109/MSP.2017.2690438.

[2] http://berndporr.github.io/iir1/

[3] https://github.com/adamstark/AudioFile 
