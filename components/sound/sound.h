#ifndef SOUND_H
#define SOUND_H

#include "../common.h"

struct Audio {
    Sound sound;
    bool isPlayed;
};

typedef struct Audio Audio;

Audio newAudio(Sound sound);

void PlayAudio(Audio audio);

#endif //SOUND_H