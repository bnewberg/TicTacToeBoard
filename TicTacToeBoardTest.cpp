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

TEST(TicTacToeBoardTest, toggleTurnFromX)
{
        TicTacToeBoard obj;
        Piece outcome = obj.toggleTurn();
        Piece expected_value = O;
	ASSERT_EQ(outcome,expected_value);
}

/*
TEST(TicTacToeBoardTest, toggleTurnFromO)
{
        TicTacToeBoard obj;
        obj.turn = O;
        Piece outcome = obj.toggleTurn();
        Piece expected_value = X;
	ASSERT_EQ(outcome,expected_value);
}
*/
