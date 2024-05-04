#include "board.hpp"

using namespace chess;
using namespace ui;
using std::make_unique;

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(Board, getSet) {
	Board board;
	Position test(3, 4);
	board.getCase(test).setPiece(nullptr);
	EXPECT_EQ(nullptr , board.getCase(test).getPieceInfo());

	King piece (Color::White);
	board.setCase(test,make_unique<King>(King(Color::White)));
	EXPECT_EQ(piece.getColor(), (board.getCase(test).getPieceInfo())->getColor());
	EXPECT_EQ(piece.getTypePiece(), (board.getCase(test).getPieceInfo())->getTypePiece());
	
}

TEST(Board, emptyCase) {
	Board board;
	Position test(2, 1);
	board.setCase(test, nullptr);
	EXPECT_EQ(true, board.isEmptyCase(test));
	board.setCase(test, make_unique<Tower>(Tower(Color::White)));
	EXPECT_EQ(false, board.isEmptyCase(test));
}

TEST(Board, isColor) {
	Board board;
	Position test(5, 7);
	board.setCase(test, make_unique<Knight>(Knight(Color::Black)));
	EXPECT_EQ(true, board.isColor(Color::Black, test));
	board.setCase(test, make_unique<Knight>(Knight(Color::White)));
	EXPECT_EQ(false, board.isColor(Color::Black, test));
	
}
TEST(Board, kingPosition) {
	Board board;
	Position whiteKing(5, 7);
	Position blackKing(0,3);
	Position whiteTower(6, 1);
	Position blackKnight(1, 0);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));

	EXPECT_EQ(whiteKing, board.kingPosition(Color::White));
	EXPECT_EQ(blackKing, board.kingPosition(Color::Black));
}

TEST(Board, inVerseColor) {
	Board board;
	
	EXPECT_EQ(Color::White, board.getInverseColor(Color::Black));
	EXPECT_EQ(Color::Black, board.getInverseColor(Color::White));
	
}
TEST(Board, kingPosition) {
	Board board;
	Position whiteKing(5, 7);
	Position blackKing(0, 3);
	Position whiteTower(6, 1);
	Position blackKnight(1, 0);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));

	EXPECT_EQ(whiteKing, board.kingPosition(Color::White));
	EXPECT_EQ(blackKing, board.kingPosition(Color::Black));
}

TEST(Board, emptyBoard) {
	Board board;
	Position whiteKing(5, 7);
	Position blackKing(0, 3);
	Position whiteTower(6, 1);
	Position blackKnight(1, 0);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.emptyBoard();
	bool failed = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!board.isEmptyCase(Position(i, j))) {
				failed = true;
				break;
			}
		}
	}
	EXPECT_EQ(false, failed);
	
}

TEST(Board, moveTo) {
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveTo(blackKnight, whiteTower);
	EXPECT_EQ(nullptr, board.getCase(blackKnight).getPieceInfo());
	EXPECT_EQ(Color::Black, board.getCase(whiteTower).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(whiteTower).getPieceInfo()->getTypePiece());
	
}

TEST(Board, moveToValid) {
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveToValid(blackKnight, whiteTower);
	EXPECT_EQ(Color::Black, board.getCase(blackKnight).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(blackKnight).getPieceInfo()->getTypePiece());
	Position validPosition(6, 5);
	board.moveToValid(blackKnight, validPosition);
	EXPECT_EQ(Color::Black, board.getCase(validPosition).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(validPosition).getPieceInfo()->getTypePiece());
}

TEST(Board, check) { //to do
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveToValid(blackKnight, whiteTower);
	EXPECT_EQ(Color::Black, board.getCase(blackKnight).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(blackKnight).getPieceInfo()->getTypePiece());
	Position validPosition(6, 5);
	board.moveToValid(blackKnight, validPosition);
	EXPECT_EQ(Color::Black, board.getCase(validPosition).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(validPosition).getPieceInfo()->getTypePiece());
}

TEST(Board, checkmate) { //to do
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveToValid(blackKnight, whiteTower);
	EXPECT_EQ(Color::Black, board.getCase(blackKnight).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(blackKnight).getPieceInfo()->getTypePiece());
	Position validPosition(6, 5);
	board.moveToValid(blackKnight, validPosition);
	EXPECT_EQ(Color::Black, board.getCase(validPosition).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(validPosition).getPieceInfo()->getTypePiece());
}
TEST(Board, allMovements) { //to do
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveToValid(blackKnight, whiteTower);
	EXPECT_EQ(Color::Black, board.getCase(blackKnight).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(blackKnight).getPieceInfo()->getTypePiece());
	Position validPosition(6, 5);
	board.moveToValid(blackKnight, validPosition);
	EXPECT_EQ(Color::Black, board.getCase(validPosition).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(validPosition).getPieceInfo()->getTypePiece());
}
TEST(Board, filteredMovements) {//to do
	Board board;
	Position whiteKing(0, 0);
	Position blackKing(7, 7);
	Position whiteTower(3, 3);
	Position blackKnight(4, 1);
	board.setCase(whiteKing, make_unique<King>(King(Color::White)));
	board.setCase(blackKing, make_unique<King>(King(Color::Black)));
	board.setCase(whiteTower, make_unique<Tower>(Tower(Color::White)));
	board.setCase(blackKnight, make_unique<Knight>(Knight(Color::Black)));
	board.moveToValid(blackKnight, whiteTower);
	EXPECT_EQ(Color::Black, board.getCase(blackKnight).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(blackKnight).getPieceInfo()->getTypePiece());
	Position validPosition(6, 5);
	board.moveToValid(blackKnight, validPosition);
	EXPECT_EQ(Color::Black, board.getCase(validPosition).getPieceInfo()->getColor());
	EXPECT_EQ(TypePiece::Knight, board.getCase(validPosition).getPieceInfo()->getTypePiece());
}
#endif