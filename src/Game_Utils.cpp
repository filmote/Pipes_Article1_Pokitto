#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* ----------------------------------------------------------------------------
 *  Return the upper 4 bits of a byte.
 */
byte Game::leftValue(byte val) {

  return val >> 4; 
      
}


/* ----------------------------------------------------------------------------
 *  Return the lower 4 bits of a byte.
 */
byte Game::rightValue(byte val) {

  return val & 0x0F; 
      
}


/* ----------------------------------------------------------------------------
 *  Initialise the board.
 */
void Game::initBoard(byte puzzleNumber) {

  byte x = 0;
  byte y = 0;
  byte byteRead = 0;

  for (int i = (puzzleNumber * 15); i < (puzzleNumber + 1) * 15; i++) {

  	byteRead = pgm_read_byte(&puzzles_5x5[i]);

  
    // Load up the left hand value ..

    board[y][x] = 0;
    if (leftValue(byteRead) > 0) {
      board[y][x] = 0xF0 | leftValue(byteRead);
    }
    x++;

  
    // Are we still in the confines of the board?

    if (x <= PUZZLE_X) {         
      board[y][x] = 0;
      if (rightValue(byteRead) > 0) {
        board[y][x] = 0xF0 | rightValue(byteRead);
      }
    }

      
    x++;
  	  
    if (x >= PUZZLE_X) { y++; x = 0; }
  		  
  }

}


/* ----------------------------------------------------------------------------
 *  Is the position nominated a node?
 */
bool Game::isNode(byte x, byte y) {

  return (board[y][x] & 0xF0) == 0xF0;
  
}


/* ----------------------------------------------------------------------------
 *  Get the node value for the position.
 */
byte Game::getNodeValue(byte x, byte y) {
  
  return (board[y][x] & 0x0F);

}
