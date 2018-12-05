#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X)
  {
    turn = O;
  }
  else
    turn = X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece cur_piece = turn;
  if (row >= BOARDSIZE || column >= BOARDSIZE)
  {
    return Invalid;
  }
  else if (board[row][column] == X || board[row][column] == O)
  {
    return board[row][column];
  }
  else
  {
    board[row][column] = cur_piece;
    toggleTurn();
    return cur_piece;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE)
  {
    return Invalid;
  } 
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece winner;

  //Check to see if any of the rows are the same
  for (int i = 0; i <= 2; i++)
  {
    if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=Blank)
    {
      winner = board[i][0];
      return winner;
    }
  }

  //Check to see if any of the columns are the same
  for (int i = 0; i <= 2; i++)
  {
    if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=Blank)
    {
      winner = board[0][i];
      return winner;
    }
  }

  //Check the diagonal from the top left corner
  if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=Blank)
  {
    winner = board[0][0];
    return winner;
  }

  //Check the diagonal from the top right corner
  if (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!=Blank)
  {
    winner = board[0][2];
    return winner;
  }

  // Check to see if there are any blank spaces and game isn't over
  for (int i = 0; i <= BOARDSIZE; i++)
  {
    for (int j = 0; j <= BOARDSIZE; j++)
    {
      if (board[i][j] == Blank)
      {
        return Invalid;
      }
    }
  }

  //No winner so we have a tie!
  winner = Blank;
  return winner;
}
