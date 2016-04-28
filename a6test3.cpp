#include <iostream>
#include <stdlib.h>

using namespace std;

//prototypes
void welcome_screen(int, int, int);
void create_boards(int, int, int);
void fill_boards_in(char**, char**, int, int, int);
void fill_answer_board_in(char**, char**, int, int);
void place_mines(char**, char**, int, int, int);
void print_board(char**, char**, int, int);
void main2(char**, char**, int, int);
int get_player_choice(char**, char**, int, int*, int*, int, int); 
int get_location_1(char**, char**, int**, int**, int, int);
void flag_the_board(char**, char**, int***, int***, int, int);
int get_location_2(char**, char**, int**, int**, int, int);
void open_the_board(char**, char**, int***, int***, int, int);
char surroundings(char**, char**, int, int, int, int, char);
char corners(char**, char**, int, int, int, int, char);
char other_corners(char**, char**, int, int, int, int, char);
char top_side(char**, char**, int, int, int, int, char);
char bottom_side(char**, char**, int, int, int, int, char);
char left_side(char**, char**, int, int, int, int, char);
char right_side(char**, char**, int, int, int, int, char);
bool check_solved(char**, char**, bool, int, int);
void end_game(char**, int, int);

int main(int argc, char** argv){
	int rows, cols, mines;
	srand(time(NULL));
	if(argc!=7){
		cout << "Error, not enough elements." << endl;
		return 1;
	}

	for(int i=1; i<argc; i+=2){
		if(argv[i][0]=='-' && argv[i][1]=='r' && argv[i][2]=='\0') rows=atoi(argv[i+1]);
		if(argv[i][0]=='-' && argv[i][1]=='c' && argv[i][2]=='\0') cols=atoi(argv[i+1]);
		if(argv[i][0]=='-' && argv[i][1]=='m' && argv[i][2]=='\0') mines=atoi(argv[i+1]);
	}
	welcome_screen(rows, cols, mines);

	return 0;
}

void welcome_screen(int rows, int cols, int mines){
	cout << "Welcome to minesweeper!" << endl << endl;
	cout << "Rows: " << rows << " | Columns: " << cols << " | Mines: " << mines << endl;
	create_boards(rows, cols, mines);
}

void create_boards(int rows, int cols, int mines){
	char** answer_board=new char*[rows];
	for(int i=0; i<rows; i++)
		answer_board[i]=new char[cols];

	char** game_board=new char*[rows];
	for(int i=0; i<rows; i++)
		game_board[i]=new char[cols];

	fill_boards_in(answer_board, game_board, rows, cols, mines);
}

void fill_boards_in(char** answer_board, char** game_board, int rows, int cols, int mines){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			answer_board[i][j]='O';
			game_board[i][j]='0';
		}
	}

	place_mines(answer_board, game_board, rows, cols, mines);
	print_board(answer_board, game_board, rows, cols);
}

void place_mines(char** answer_board, char** game_board, int rows, int cols, int mines){
	int mine_row, mine_cols;
	for(int i=0; i<mines; i++){
		mine_row=(rand()%rows);
		mine_cols=(rand()%cols);
		answer_board[mine_row][mine_cols]='?';
	}
	fill_answer_board_in(answer_board, game_board, rows, cols);
}

void fill_answer_board_in(char** answer_board, char** game_board, int rows, int cols){
	char counter;
	cout << "HI" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(i==0 && j==0 || i==(rows-1) && j==(cols-1)) answer_board[i][j]=corners(answer_board, game_board, i, j, rows, cols, counter);
			if(i>0 && j>0 && i<(rows-1) && j<(cols-1)) answer_board[i][j]=surroundings(answer_board, game_board, i, j, rows, cols, counter);
			if(i==(rows-1) && j==0 || i==0 && j==(cols-1)) answer_board[i][j]=other_corners(answer_board, game_board, i, j, rows, cols, counter);
			if(i==0 && j>0) answer_board[i][j]=top_side(answer_board, game_board, i, j, rows, cols, counter);
			if(i==(rows-1) && j>0 && j<(cols-1)) answer_board[i][j]=bottom_side(answer_board, game_board, i, j, rows, cols, counter);
			if(i>0 && j==0) answer_board[i][j]=left_side(answer_board, game_board, i, j, rows, cols, counter);
			if(i>0 && j==(cols-1)) answer_board[i][j]=right_side(answer_board, game_board, i, j, rows, cols, counter);
		}
	}
}

void print_board(char** answer_board, char** game_board, int rows, int cols){
	for(int i=0; i<cols; i++) cout << "C ";
	cout << endl;
	for(int i=0; i<cols; i++) cout << i << " ";
	cout << endl;
	for(int i=0; i<cols; i++) cout << "- ";
	cout << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << game_board[i][j] << " ";
		} cout << "|" << "Row " << i << endl;
	}
	cout << endl << "Answer board" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << answer_board[i][j] << " ";
		} cout << endl;
	}
	main2(answer_board, game_board, rows, cols);
}

void main2(char** answer_board, char** game_board, int rows, int cols){
	bool solved;
	int player_choice, row_choice, col_choice; 
	while(solved==false){
		get_player_choice(answer_board, game_board, player_choice, &row_choice, &col_choice, rows, cols);
		cout << row_choice << " and " << col_choice << endl;
		solved=check_solved(answer_board, game_board, solved, rows, cols);
	}
}

int get_player_choice(char** answer_board, char** game_board, int player_choice, int* row_choice, int* col_choice, int rows, int cols){
	cout << "Do you want to (1)flag (2)open a box? (3)quit?: ";
	cin >> player_choice;
	if(player_choice==1){
		get_location_1(answer_board, game_board, &row_choice, &col_choice, rows, cols);
	}
	if(player_choice==2){
		get_location_2(answer_board, game_board, &row_choice, &col_choice, rows, cols);
	}
	if(player_choice==3){
		cout << "Okay, see ya! Just a quick note... \nI enjoyed this term a lot and I feel like I learned a lot of good fundamentals for my future CS classes. \nI'm grateful for all of the TA's and the work and help that they offer. \nI kinda wish to be a TA as well someday because of the influence that you guys had on me. \nEven though I might have to retake this class again later, I'm glad that I was able to learn what I learned. \nHave a good break! \nYou guys rock." << endl;
		exit(1);
	}
}

int get_location_1(char** answer_board, char** game_board, int** row_choice, int** col_choice, int rows, int cols){
	cout << "Choose a row and column to flag.\nRow: ";
	cin >> **row_choice; 
	cout << "Column: ";
	cin >> **col_choice;
	flag_the_board(answer_board, game_board, &row_choice, &col_choice, rows, cols);
}

void flag_the_board(char** answer_board, char** game_board, int*** row_choice, int*** col_choice, int rows, int cols){
	game_board[***row_choice][***col_choice]='?';
	print_board(answer_board, game_board, rows, cols);
}

int get_location_2(char** answer_board, char** game_board, int** row_choice, int** col_choice, int rows, int cols){
	cout << "Choose a row and column to open.\nRow: ";
	cin >> **row_choice; 
	cout << "Column: ";
	cin >> **col_choice;
	open_the_board(answer_board, game_board, &row_choice, &col_choice, rows, cols);
}

void open_the_board(char** answer_board, char** game_board, int*** row_choice, int*** col_choice, int rows, int cols){
	if(answer_board[***row_choice][***col_choice]=='?'){
		end_game(answer_board, rows, cols);
	}
}

char surroundings(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(counter>0) game_board[i][j]=counter;
	if(counter==48) game_board[i][j]='O';
	return counter;

	print_board(answer_board, game_board, rows, cols);
}

char corners(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(i==0 && j==0){
		if(answer_board[i+1][j]=='?') counter++;
		if(answer_board[i][j+1]=='?') counter++;
		if(answer_board[i+1][j+1]=='?') counter++;
	}
	else if(i==rows && j==cols){
		if(answer_board[i-1][j]=='?') counter++;
		if(answer_board[i][j-1]=='?') counter++;
		if(answer_board[i-1][j-1]=='?') counter++;
	}
	return counter;
}

char other_corners(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(i==rows && j==0){
		if(answer_board[i-1][j]=='?') counter++;
		if(answer_board[i][j+1]) counter++;
		if(answer_board[i-1][j+1]) counter++;
	}
	if(i==0 && j==cols){
		if(answer_board[i+1][j]) counter++;
		if(answer_board[i][j-1]) counter++;
		if(answer_board[i+1][j-1]) counter++;
	}
	return counter;
}

char top_side(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i+1][j+1]) counter++;
	if(answer_board[i][j+1]) counter++;
	return counter;
}

char bottom_side(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j+1]) counter++;
	if(answer_board[i][j+1]) counter++;
	return counter;
}

char left_side(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i+1][j+1]) counter++;
	if(answer_board[i+1][j]) counter++;
	return counter;
}

char right_side(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j-1]) counter++;
	if(answer_board[i+1][j]) counter++;
	return counter;
}

void end_game(char** answer_board, int rows, int cols){
	cout << "You hit a mine! Game over!" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(answer_board[i][j]=='?'){
				answer_board[i][j]='X';
			}
			cout << answer_board[i][j] << " ";
		} cout << endl;
	}
	exit(1);
}

bool check_solved(char** answer_board, char** game_board, bool solved, int rows, int cols){
	int yolo=0, total;
	total=rows*cols;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(game_board[i][j]==answer_board[i][j]){
				yolo++;
			}
		}
	}
	cout << yolo << " " << total << endl;
}