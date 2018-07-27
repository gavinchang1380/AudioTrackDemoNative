#include <stdio.h>
#include <media/AudioTrack.h>
#include <math.h>
#include <binder/IPCThreadState.h>

int main()
{
    int16_t buffer[960 * 2];
    android::AudioTrack *at = new android::AudioTrack();
    android::status_t status = at->set(AUDIO_STREAM_MUSIC,
                                       48000,
                                       AUDIO_FORMAT_PCM_16_BIT,
                                       AUDIO_CHANNEL_OUT_STEREO,
                                       960,
                                       AUDIO_OUTPUT_FLAG_FAST,
                                       NULL,
                                       NULL,
                                       0,
                                       NULL,
                                       true,
                                       AUDIO_SESSION_ALLOCATE,
                                       android::AudioTrack::TRANSFER_SYNC,
                                       NULL,
                                       -1, -1,
                                       NULL
    );

    for (int i = 0; i < 960; i++) {
        buffer[2 * i + 1] = static_cast<int16_t>(sin(2 * 3.1415926 * i / 48) * 32767 * 1);
        buffer[2 * i] = 0;
    }
    printf("AudioTrack create: %d\n", status);
    status = at->start();
    printf("AudioTrack start: %d\n", status);
    at->dump(STDOUT_FILENO, android::Vector<android::String16>());
    while (1) {
        at->write(buffer, sizeof(buffer));
    }


	return 0;
}
