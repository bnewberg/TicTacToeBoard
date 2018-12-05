/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleTurnToO)
{
        TicTacToeBoard obj;
        Piece outcome = obj.toggleTurn();
        Piece expected_value = O;
	ASSERT_EQ(outcome,expected_value);
}

TEST(TicTacToeBoardTest, toggleTurnToX)
{
        TicTacToeBoard obj;
        obj.toggleTurn();
        Piece turn2 = obj.toggleTurn();
        Piece expected_value = X;
	ASSERT_EQ(turn2,expected_value);
}

TEST(TicTacToeBoardTest, XPlacedOnEmpty)
{
        TicTacToeBoard obj;
        Piece piece_placed = obj.placePiece(0,0);
        Piece expected_piece = X;
	ASSERT_EQ(piece_placed,expected_piece);
}

TEST(TicTacToeBoardTest, OPlacedOnEmpty)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        Piece target_piece = obj.placePiece(0,1);
        Piece expected_piece = O;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, placedPieceOnNonEmptyX)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        Piece target_piece = obj.placePiece(0,0);
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, placedPieceOnNonEmptyO)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        obj.placePiece(0,1);
        Piece target_piece = obj.placePiece(0,1);
        Piece expected_piece = O;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, outOfBoundsRow)
{
        TicTacToeBoard obj;
        Piece target_piece = obj.placePiece(3,0);
        Piece expected_piece = Invalid;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, outOfBoundsCol)
{
        TicTacToeBoard obj;
        Piece target_piece = obj.placePiece(1,4);
        Piece expected_piece = Invalid;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, getPieceX)
{
        TicTacToeBoard obj;
        obj.placePiece(1,1);
        Piece target_piece = obj.getPiece(1,1);
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, getPieceO)
{
        TicTacToeBoard obj;
        obj.placePiece(1,1);
        obj.placePiece(0,1);
        Piece target_piece = obj.getPiece(0,1);
        Piece expected_piece = O;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, outOfBoundsRowPieceRetrival)
{
        TicTacToeBoard obj;
        Piece target_piece = obj.getPiece(3,2);
        Piece expected_piece = Invalid;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, outOfBoundsColPieceRetrival)
{
        TicTacToeBoard obj;
        Piece target_piece = obj.getPiece(1,3);
        Piece expected_piece = Invalid;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, XisWinner1stRow)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        obj.placePiece(1,0);
        obj.placePiece(0,1);
        obj.placePiece(1,1);
        obj.placePiece(0,2);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, XisWinner1stCol)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        obj.placePiece(0,1);
        obj.placePiece(1,0);
        obj.placePiece(0,2);
        obj.placePiece(2,0);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, XisWinner1stDiag)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        obj.placePiece(0,1);
        obj.placePiece(1,1);
        obj.placePiece(0,2);
        obj.placePiece(2,2);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, XisWinner2ndDiag)
{
        TicTacToeBoard obj;
        obj.placePiece(0,2);
        obj.placePiece(0,1);
        obj.placePiece(1,1);
        obj.placePiece(0,0);
        obj.placePiece(2,0);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = X;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, blankSpaces)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = Invalid;
	ASSERT_EQ(target_piece,expected_piece);
}

TEST(TicTacToeBoardTest, Tie)
{
        TicTacToeBoard obj;
        obj.placePiece(0,0);
        obj.placePiece(1,0);
        obj.placePiece(0,1);
        obj.placePiece(0,2);
        obj.placePiece(1,2);
        obj.placePiece(1,1);
        obj.placePiece(2,0);
        obj.placePiece(2,1);
        obj.placePiece(2,2);
        Piece target_piece = obj.getWinner();
        Piece expected_piece = Blank;
	ASSERT_EQ(target_piece,expected_piece);
}