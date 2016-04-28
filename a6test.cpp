#include <iostream>
#include <stdlib.h>

using namespace std;

//prototypes
void welcome_screen(int, int, int);
void create_board(int, int);
void fill_board_in(int**, int, int);
void place_mines(int**, int, int, int);
void print_board(int**, int, int);

int main(int argc, char** argv){
	int rows, cols, mines, **board;
	srand(time(NULL));
	if(argc!=7){
		cout << "Error, not enough elements." << endl;
		return 1;
	}

	for(int i=1; i<argc; i+=2){
		if(argv[i][0]=='-' && argv[i][1]=='r' && argv[i][2]=='\0') rows=atoi(argv[i+1]);
		if(argv[i][0]=='-' && argv[i][1]=='c' && argv[i][2]=='\0') cols=atoi(argv[i+1]);
		if(argv[i][0]=='-' && argv[i][1]=='m' && argv[i][2]=='\0') mines=atoi(argv[i+1]);}

	cout << "rows is " << rows << ", columns is " << cols << ", and mines are " << mines << endl;

	welcome_screen(rows, cols, mines);
	create_board(rows, cols);
	place_mines(board, rows, cols, mines);
	print_board(board, rows, cols);

	return 0;
}

void welcome_screen(int rows, int cols, int mines){
	cout << "Welcome to minesweeper!" << endl << endl;
	cout << "Rows is " << rows << ", columns is " << cols << ", and mines are " << mines << "." << endl;
}

void create_board(int rows, int cols){
	int** board=new int*[rows];
	for(int i=0; i<rows; i++)
		board[i]=new int[cols];

	fill_board_in(board, rows, cols);
}

void fill_board_in(int** board, int rows, int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			board[i][j]=0;
		}
	}

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void place_mines(int** board, int rows, int cols, int mines){
	int mine_row, mine_cols;
	cout << "Yay, it got to place_mines!" << endl;
	mine_row=(rand()%rows);
	mine_cols=(rand()%cols);
	board[mine_row][mine_cols]=1;
	cout << "mine row is " << mine_row << " and mine cols is " << mine_cols << endl;
}

void print_board(int** board, int rows, int cols){
	cout << "Got to print board!" << endl << endl;
	/*for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
}