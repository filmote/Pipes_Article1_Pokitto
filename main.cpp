#include "Pokitto.h"

#include "src/Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

Game game;

int main() {

    PC::begin();
    PD::setInvisibleColor(0);
    PD::setColor(0);
    PD::loadRGBPalette(paletteCGA); 


    // Play game!

    game.setup();

    while (PC::isRunning()) {
    
        if (!PC::update()) continue;
        game.loop();
    
    }
    
    return 0;

}