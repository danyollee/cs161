
#include <iostream>
#include <stdlib.h>

using namespace std;

void move(int constant, int** board, int source, int dest,int disks) {
	for (int i = 0; i <= constant; i++) {
		if (board[i][source] != 0) {
			for (int j = 0; j <= constant; j++) { //in this for loop, I'm swapping the disks
				if (board[j][dest] != 0) {
					board[j-1][dest] = board[i][source];
					board[i][source] = 0;
					break;
				}
				if (board[0][dest] == 0 && board[1][dest] == 0 && board[2][dest] == 0) {
					board[2][dest] = board[i][source];
					board[i][source] = 0;
					break;
				}
			}
			for (int m = 0; m < 3; m++) { //in this for loop, I'm printing out the results
				for (int n = 0; n < constant; n++) {
					cout << board[m][n] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
			break;
		}
	}
}

void towers(int constant, int disks, int** board, int source, int dest, int spare) {
	if (disks == 0)
		return;
	else {
		towers(constant, disks - 1, board, source, spare, dest);
		move(constant, board, source, dest, disks);
		towers(constant, disks - 1, board, spare, dest, source);
	}
}

void emptyArray(int **board, int disks) {
	for (int m = 0; m < 3; m++) { //in this for loop, I'm printing out the results
		for (int n = 0; n < disks; n++) {
			board[m][n] = 0;
		}
	}
}

int ** createArray(int disks) {
	int ** board = new int*[3];
	for (int i = 0; i < 3; i++) board[i] = new int[disks];
	emptyArray(board, disks);
	for (int i = 0; i < disks; i++) {
		board[i][0] = disks - (disks - i - 1); //prints out the disk #
	}
	return board;
}

int main() {
	cout << "Enter the amount of disks you want in this.\n";
	int input, input2; cin >> input;
	system("clear");
	int ** board = createArray(input);
	for (int m = 0; m < 3; m++) { //in this for loop, I'm printing out the results
		for (int n = 0; n < input; n++) {
			cout << board[m][n] << " ";
		}
		cout << endl;
	}
	cout << endl;
	input2 = input;
	towers(input2, input, board, 0, 1, 2);
    return 0;
}


