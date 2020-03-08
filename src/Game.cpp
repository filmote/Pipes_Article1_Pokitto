#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* ----------------------------------------------------------------------------
 *   Get ready !
 */
void Game::setup() { 

  // Nothing!

}


/* ----------------------------------------------------------------------------
 *   Play pipes !
 */
void Game::loop() {
    
  PC::buttons.pollButtons();

  switch (gameState) {

    case STATE_SPLASH_INIT:
      initSplash();
      [[fallthrough]]

    case STATE_SPLASH_RENDER:
      renderSplash();
      break;

    case STATE_INIT_GAME:
      play_InitGame();
      [[fallthrough]]

    case STATE_PLAY_GAME:
      play_DisplayBoard();
      break;


  }

}


/* ----------------------------------------------------------------------------
 *   Initialise the game based on the selected level and puzzle numbers.
 */
void Game::play_InitGame() {

  initBoard(0);
  gameState = STATE_PLAY_GAME;
  
}


/* ----------------------------------------------------------------------------
 *   Render the board.
 */
void Game::play_DisplayBoard() {
  
  renderBoard();

  if (PC::buttons.pressed(BTN_A)) {
    gameState = STATE_SPLASH_INIT;
  }

}

