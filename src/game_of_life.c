/*
 * game_of_life.c
 *
 *  Created on: Dec 21, 2015
 *      Author: rafael
 */

#include "game_of_life.h"

int _liveSituation(int **board, int boardRowSize, int boardColSize, int row,
		int col) {
	int liveNum = 0;

	// left-top
	if (row > 0 && col > 0) {
		liveNum += board[row - 1][col - 1] & 0x01 ? 1 : 0;
	}

	// left
	if (col > 0) {
		liveNum += board[row][col - 1] & 0x01 ? 1 : 0;
	}

	// left-bottom
	if (row < boardRowSize - 1 && col > 0) {
		liveNum += board[row + 1][col - 1] & 0x01 ? 1 : 0;
	}

	// bottom
	if (row < boardRowSize - 1) {
		liveNum += board[row + 1][col] & 0x01 ? 1 : 0;
	}

	// right-bottom
	if (row < boardRowSize - 1 && col < boardColSize - 1) {
		liveNum += board[row + 1][col + 1] & 0x01 ? 1 : 0;
	}

	// right
	if (col < boardColSize - 1) {
		liveNum += board[row][col + 1] & 0x01 ? 1 : 0;
	}

	// right-top
	if (row > 0 && col < boardColSize - 1) {
		liveNum += board[row - 1][col + 1] & 0x01 ? 1 : 0;
	}

	// top
	if (row > 0) {
		liveNum += board[row - 1][col] & 0x01 ? 1 : 0;
	}

	return liveNum;
}

void gameOfLife(int **board, int boardRowSize, int boardColSize) {
	int row = 0;
	int col = 0;

	// update for next generation
	for (row = 0; row < boardRowSize; row++) {
		for (col = 0; col < boardColSize; col++) {
			int liveNum = _liveSituation(board, boardRowSize, boardColSize, row,
					col);

			if (liveNum < 2 || liveNum > 3) {
				// dies anyway
			} else if (liveNum == 2) {
				board[row][col] |= board[row][col] & 0x01 ? 0x02 : 0x00;
			} else if (liveNum == 3) {
				board[row][col] |= 0x02;
			}
		}
	}

	// refresh to next generation
	for (row = 0; row < boardRowSize; row++) {
		for (col = 0; col < boardColSize; col++) {
			board[row][col] >>= 1;
		}
	}
}

void printBoard(int **board, int boardRowSize, int boardColSize) {
	int row = 0;
	int col = 0;

	for (row = 0; row < boardRowSize; row++) {
		for (col = 0; col < boardColSize; col++) {
			printf("%d ", board[row][col]);
		}

		printf("\n");
	}

	printf("\n");
}

void _run() {
	int i[2] = { 1, 1 };
	int ii[2] = { 1, 0 };

	int *boardTest[2] = { i, ii };

	printBoard((int **) boardTest, 2, 2);
	gameOfLife((int **) boardTest, 2, 2);
	printBoard((int **) boardTest, 2, 2);
}

void game_of_life() {
	_run();
}
