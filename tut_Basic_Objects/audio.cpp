#include "irrKlang.h"
irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();
irrklang::ISoundEngine* GunEngine = irrklang::createIrrKlangDevice();

void gunAudio() {
    GunEngine->setSoundVolume(0.1f);
    GunEngine->play2D("media/gun_fire.wav", false);
}

void zombieDeathAudio() {
    SoundEngine->setSoundVolume(0.1f);
    SoundEngine->play2D("media/death_zombie.wav", false);
}

void heroDamageAudio(){
    SoundEngine->setSoundVolume(0.5f);
    SoundEngine->play2D("media/hero-damage_sound.mp3", false);
}

void reloadGunAudio() {
    SoundEngine->setSoundVolume(0.5f);
    SoundEngine->play2D("media/reloading_gun.mp3", false);
}






