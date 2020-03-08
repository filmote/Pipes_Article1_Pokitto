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
      void play_NoSelection();
      void play_NodeSelected();
      void renderBoard();
      void play_DisplayBoard();

      // Manu handling options ..

      void renderBackground();


      // Splash screen handling ..

      void initSplash();
      void renderSplash();


      // Utilities ..

      byte leftValue(byte val);
      byte rightValue(byte val);
      byte getNodeValue(byte x, byte y);
      byte getNumberOfPuzzles(byte puzzleLevel);
      byte calculateTopRow();

      void initBoard(byte puzzleNumber);
      bool isNode(byte x, byte y);


    private:

      const byte* nodes[11] = { 0, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8, Node9, Node10 };
      byte board[5][5];
      byte gameState = STATE_SPLASH_INIT;
      byte splash_counter;

};