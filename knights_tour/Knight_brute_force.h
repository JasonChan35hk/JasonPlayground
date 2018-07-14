#include "common.h"

class Knight_brute_force {
public:
	int boardSize;
	int totalMoves;
	int found;
	int board[MaxBoardSize][MaxBoardSize];
	int result[MaxBoardSize][MaxBoardSize];

	Knight_brute_force(int n){
		if (n > MaxBoardSize) {
			assert(false);
			return;
		}

		boardSize = n;
		totalMoves = n * n;
		found= 0;

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				result[i][j] = 0;

		resetBoard();
	}

	void resetBoard() {
		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				board[i][j] = 0;
	}

	__forceinline bool safe(int x, int y) {
		return x >= 0 && x < boardSize && y >= 0 && y < boardSize && board[x][y] == 0;
	}

	void dumpBoard() {
		for(int i = 0; i < boardSize; i++){
			for(int j = 0; j < boardSize; j++){
				printf("%5d",board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	void dumpResult() {
		for(int i = 0; i < boardSize; i++){
			for(int j = 0; j < boardSize; j++){
				printf("%5d", result[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	void resolveAll() {
		resolve(0,0);
		/*
		for(int i = 0; i < boardSize; i++) {
			for(int j = 0; j < boardSize; j++) {
				result[i][j] += resolve(i, j);
			}
		}
		dumpResult();
		*/
	}

	int resolve(int x, int y) {
		return doStep(x, y, 1);
	}

	int doStep(int x, int y, int steps) {
		if (!safe(x,y)) return 0;

		if (steps >= totalMoves) {
			//dumpBoard();
			found++;
			if (found % 10 == 0) {
				printf("found: %d\n", found);
			}
			board[x][y] = 0; // restore
			return 1;
		}

		board[x][y] = steps;
		int c = 0;
		steps++;
		c += doStep(x + 1, y + 2, steps);
		c += doStep(x + 2, y - 1, steps);
		c += doStep(x + 2, y + 1, steps);
		c += doStep(x + 1, y - 2, steps);
        
		c += doStep(x - 1, y - 2, steps);
		c += doStep(x - 1, y + 2, steps);
		c += doStep(x - 2, y - 1, steps);
		c += doStep(x - 2, y + 1, steps);

		board[x][y] = 0; // restore
		return c;
	}
};