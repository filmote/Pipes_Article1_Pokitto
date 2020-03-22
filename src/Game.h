#pragma once

#include "Pokitto.h"

#include "puzzles/Puzzles.h"
#include "images/nodes/Nodes.h"
#include "images/pipes/Pipes.h"
#include "images/Heading.h"

class Game {
    
    public:


      // Overall game play ..

      void setup();
      void loop(void);

      void play_InitGame();
      void renderBoard();
      void play_DisplayBoard();

      // Manu handling options ..

      void renderBackground();


      // Splash screen handling ..

      void initSplash();
      void renderSplash();


      // Utilities ..

      uint8_t leftValue(uint8_t val);
      uint8_t rightValue(uint8_t val);
      uint8_t getNodeValue(uint8_t x, uint8_t y);

      void initBoard(uint8_t puzzleNumber);
      bool isNode(uint8_t x, uint8_t y);


    private:

      const uint8_t* nodes[11] = { nullptr, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8, Node9, Node10 };
      uint8_t board[5][5];
      uint8_t gameState = STATE_SPLASH_INIT;
      uint8_t splash_counter;

};