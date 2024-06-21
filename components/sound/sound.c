#include "sound.h"

Audio newAudio(Sound sound) {
    return (Audio) {sound, false};
}

void PlayAudio(Audio audio) {
    PlaySound(audio.sound);
}