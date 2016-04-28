/*********************************************************************
 ** Program Filename: a6.cpp
 ** Author: Daniel Lee
 ** Date: 3/13/2016
 ** Description: Plays minesweeper
 ** Input: None
 ** Output: None
 *********************************************************************/ 

#include <iostream>
#include <stdlib.h>

using namespace std;

//prototypes
void welcome_screen(int, int, int);
void create_boards(int, int, int);
void fill_boards_in(char**, char**, int, int, int);
void fill_answer_board_in(char**, char**, int, int);
void place_mines(char**, char**, int, int, int);
void print_boards(char**, char**, int, int);
void main2(char**, char**, int, int);
int get_player_choice(char**, char**, int, int*, int*, int, int); 
int get_location_1(char**, char**, int**, int**, int, int);
void flag_the_board(char**, char**, int***, int***, int, int);
int get_location_2(char**, char**, int**, int**, int, int);
void open_the_board(char**, char**, int***, int***, int, int);
void open_ze_boards_1(char**, char**, int, int, int, int);
void open_ze_boards_2(char**, char**, int, int, int, int, char);
void open_topside(char**, char**, int, int, char);
void open_bottomside(char**, char**, int, int, char);
void open_leftside(char**, char**, int, int, char);
void open_rightside(char**, char**, int, int, char);
void open_topleft_corner(char**, char**, int, int, char);
void open_bottomright_corner(char**, char**, int, int, char);
void open_bottomleft_corner(char**, char**, int, int, char);
void open_topright_corner(char**, char**, int, int, char);
void open_surroundings(char**, char**, int, int, char);
bool check_solved(char**, char**, bool, int, int);
void end_game(char**, int, int);
void game_end(char**, char**, int, int);
void delete_the_arrays(char**, char**, int, int);
int new_stats();

/*********************************************************************
 ** Function: main
 ** Description: starts the minesweeper game
 ** Parameters: argc and argv
 ** Pre-Conditions: argc must be greater than 2 and argv must be correct
 ** Post-Conditions: the rows, columns, and mines are set
 *********************************************************************/ 
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

/*********************************************************************
 ** Function: welcome_screen
 ** Description: just lets the user know how many of each element they have
 ** Parameters: rows, cols, mines
 ** Pre-Conditions: rows, cols, and mines must be ints
 ** Post-Conditions: rows, cols, and mines must be ints
 *********************************************************************/ 
void welcome_screen(int rows, int cols, int mines){
	cout << "Welcome to minesweeper!" << endl << endl;
	cout << "Rows: " << rows << " rows | Columns: " << cols << " | Mines: " << mines << endl;
	create_boards(rows, cols, mines);
}

/*********************************************************************
 ** Function: create_boards
 ** Description: creates the two game boards
 ** Parameters: rows, cols, and mines
 ** Pre-Conditions: rows, cols and mines must be ints
 ** Post-Conditions: creates 2 2d dynamic arrays.
 *********************************************************************/ 
void create_boards(int rows, int cols, int mines){
	char** answer_board=new char*[rows];
	for(int i=0; i<rows; i++)
		answer_board[i]=new char[cols];

	char** game_board=new char*[rows];
	for(int i=0; i<rows; i++)
		game_board[i]=new char[cols];

	fill_boards_in(answer_board, game_board, rows, cols, mines);
}

/*********************************************************************
 ** Function: fill_boards_in
 ** Description: fills both the boards with the starting values O.
 ** Parameters: the two game boards, rows, cols, and mines
 ** Pre-Conditions: 2d arrays must be correct and rows cols mines must be ints
 ** Post-Conditions: the two boards will be filled with 'O'
 *********************************************************************/ 
void fill_boards_in(char** answer_board, char** game_board, int rows, int cols, int mines){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			answer_board[i][j]='O';
			game_board[i][j]='O';
		}
	}

	place_mines(answer_board, game_board, rows, cols, mines);
}

/*********************************************************************
 ** Function: place_mines
 ** Description: fills the answer board with the mines
 ** Parameters: answerboard, gameboard, rows, cols, mines
 ** Pre-Conditions: arrays must be valid with 'O' and the rest must be valid ints
 ** Post-Conditions: fills the answerboard with the mines as '?'
 *********************************************************************/ 
void place_mines(char** answer_board, char** game_board, int rows, int cols, int mines){
	int mine_row, mine_cols;
	for(int i=0; i<mines; i++){
		mine_row=(rand()%rows);
		mine_cols=(rand()%cols);
		answer_board[mine_row][mine_cols]='?';
	}
	fill_answer_board_in(answer_board, game_board, rows, cols);
}

/*********************************************************************
 ** Function: fill_answer_board_in
 ** Description: fills the answerboard with the values around the mines
 ** Parameters: answerboard, gameboard, rows, cols
 ** Pre-Conditions: everything must be valid
 ** Post-Conditions: sends the answerboard array to be filled in
 *********************************************************************/ 
void fill_answer_board_in(char** answer_board, char** game_board, int rows, int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			open_ze_boards_1(answer_board, game_board, i, j, rows, cols);
		}
	}
	cout << endl;
	main2(answer_board, game_board, rows, cols);
}

/*********************************************************************
 ** Function: print_boards
 ** Description: prints out the gameboard each round for the user
 ** Parameters: answerboard, gameboard, rows and cols
 ** Pre-Conditions: the game must not have been solved yet.
 ** Post-Conditions: none
 *********************************************************************/ 
void print_boards(char** answer_board, char** game_board, int rows, int cols){
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
}

/*********************************************************************
 ** Function: main2
 ** Description: runs the game
 ** Parameters: answerboard, gameboard, rows and cols
 ** Pre-Conditions: all values must be valid and the game must not have been solved yet
 ** Post-Conditions: none
 *********************************************************************/ 
void main2(char** answer_board, char** game_board, int rows, int cols){
	bool solved;
	int player_choice, row_choice, col_choice; 
	print_boards(answer_board, game_board, rows, cols);
	while(solved==false){
		get_player_choice(answer_board, game_board, player_choice, &row_choice, &col_choice, rows, cols);
		solved=check_solved(answer_board, game_board, solved, rows, cols);
		if(solved==true)
			game_end(answer_board, game_board, rows, cols);
	}
}

/*********************************************************************
 ** Function: get_player_choice
 ** Description: gets the choice to flag, open, or quit
 ** Parameters: answerboard, gameboard, playerchoice, rowchoice, colchoice, rows, cols
 ** Pre-Conditions: everything must be valid by now
 ** Post-Conditions: sends everything to different functions based on the choice
 *********************************************************************/ 
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

/*********************************************************************
 ** Function: get_location_1
 ** Description: gets a location to flag
 ** Parameters: answerboard, gameboard, rowchoice, colchoice, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: actually flags the board
 *********************************************************************/ 
int get_location_1(char** answer_board, char** game_board, int** row_choice, int** col_choice, int rows, int cols){
	cout << "Choose a row and column to flag.\nRow: ";
	cin >> **row_choice; 
	cout << "Column: ";
	cin >> **col_choice;

	cout << "You picked row " << **row_choice << " and column " << **col_choice << endl;
	flag_the_board(answer_board, game_board, &row_choice, &col_choice, rows, cols);
}

/*********************************************************************
 ** Function: flag_the_board
 ** Description: changes the loaction that the user chose to a flag
 ** Parameters: answerboard, gameboard, rowchoice, colchoice, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the gameboard
 *********************************************************************/ 
void flag_the_board(char** answer_board, char** game_board, int*** row_choice, int*** col_choice, int rows, int cols){
	game_board[***row_choice][***col_choice]='?';
}

/*********************************************************************
 ** Function: get_loaction_2
 ** Description: gets location to open
 ** Parameters: answerboard, gameboard, rowchoice, colchoice, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: sends the arrays to be changed
 *********************************************************************/ 
int get_location_2(char** answer_board, char** game_board, int** row_choice, int** col_choice, int rows, int cols){
	cout << "Choose a row and column to open.\nRow: ";
	cin >> **row_choice; 
	cout << "Column: ";
	cin >> **col_choice;
	while(game_board[**row_choice][**col_choice]!='O'){
		cout << "Error, you already picked that. Try again." << endl;
		cout << "Choose a row and column to open.\nRow: ";
		cin >> **row_choice; 
		cout << "Column: ";
		cin >> **col_choice;
	}
	open_the_board(answer_board, game_board, &row_choice, &col_choice, rows, cols);
}

/*********************************************************************
 ** Function: open_the_board
 ** Description: determines how to open the board up
 ** Parameters: answerboard, gameboard, rowchoice, colchoice, rows, cols
 ** Pre-Conditions: game must not have been solved yet
 ** Post-Conditions: changes the gameboard
 *********************************************************************/ 
void open_the_board(char** answer_board, char** game_board, int*** row_choice, int*** col_choice, int rows, int cols){
	if(answer_board[***row_choice][***col_choice]=='?'){
		end_game(answer_board, rows, cols);
	}else if(answer_board[***row_choice][***col_choice]>48) 
		game_board[***row_choice][***col_choice]=answer_board[***row_choice][***col_choice];
	else if(answer_board[***row_choice][***col_choice]==48){
		game_board[***row_choice][***col_choice]=answer_board[***row_choice][***col_choice];
	}
}

/*********************************************************************
 ** Function: openzeboards1
 ** Description: sends the arrays to a funciton to open
 ** Parameters: answerboard, gameboard, i, j, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: opens the board up 
 *********************************************************************/ 
void open_ze_boards_1(char** answer_board, char** game_board, int i, int j, int rows, int cols){
	char counter;
	if(answer_board[i][j]=='?')
		return;
	if(i==0 || j==0 || i==(rows-1) || j==(cols-1))
		open_ze_boards_2(answer_board, game_board, i, j, rows, cols, counter);
	if(i>0 && j>0 && i<(rows-1) && j<(cols-1))
		open_surroundings(answer_board, game_board, i, j, counter);
}

/*********************************************************************
 ** Function: openzeboards2
 ** Description: determines how to open the gameboard
 ** Parameters: answerboard, gameboard, i, j, rows, cols, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_ze_boards_2(char** answer_board, char** game_board, int i, int j, int rows, int cols, char counter){
	if(i==0 && j==0) open_topleft_corner(answer_board, game_board, i, j, counter);
	if(i==(rows-1) && j==(cols-1)) open_bottomright_corner(answer_board, game_board, i, j, counter);
	if(i==(rows-1) && j==0) open_bottomleft_corner(answer_board, game_board, i, j, counter);
	if(i==0 && j==(cols-1)) open_topright_corner(answer_board, game_board, i, j, counter);
	if(i==0 && j<cols && j>0) open_topside(answer_board, game_board, i, j, counter);
	if(i==(rows-1) && j<cols && j>0) open_bottomside(answer_board, game_board, i, j, counter);
	if(i>0 && i<rows-1 && j==0) open_leftside(answer_board, game_board, i, j, counter);
	if(i>0 && j<rows && j==(cols-1)) open_rightside(answer_board, game_board, i, j, counter);
}

/*********************************************************************
 ** Function: openrightside
 ** Description: opens the right side oft he board
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_rightside(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i-1][j]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: openleftside
 ** Description: opens the left side of the board
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_leftside(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(answer_board[i+1][j]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open bottomside
 ** Description: opens the bottom of the board
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_bottomside(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open topside
 ** Description: opens the top side of the board
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_topside(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: opentopleftcorner
 ** Description: opens the top left corner
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_topleft_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open bottomright corner
 ** Description: opens the bottom right corner
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_bottomright_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open bottomleft corner
 ** Description: opens the bottom left corner
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_bottomleft_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open topright corner
 ** Description: opens the top right corner
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_topright_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: open surroundings
 ** Description: opens all 8 parts around the loaction
 ** Parameters: answerboard, gameboard, i, j, counter
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: changes the board
 *********************************************************************/ 
void open_surroundings(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

/*********************************************************************
 ** Function: endgame
 ** Description: ends the game
 ** Parameters: answerboard, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: ends the game
 *********************************************************************/ 
void end_game(char** answer_board, int rows, int cols){
	int repeat;
	cout << "You hit a mine! Game over!" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(answer_board[i][j]=='?'){
				answer_board[i][j]='X';
			}
			cout << answer_board[i][j] << " ";
		} cout << endl;
	}
	cout << "Do you want to play again?\n(1)yes\n(2)no" << endl;
	cin >> repeat;
	if(repeat==2) exit(1);
}

/*********************************************************************
 ** Function: check solved
 ** Description: checks to see if the game is solved
 ** Parameters: answerboard, gameboard, solved, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: ends the game
 *********************************************************************/ 
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
	if(yolo==total) return solved=true;
	print_boards(answer_board, game_board, rows, cols);
}

/*********************************************************************
 ** Function: gameend
 ** Description: ends the game
 ** Parameters: answerboard, gameboard, rows, cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: ends the game
 *********************************************************************/ 
void game_end(char** answer_board, char** game_board, int rows, int cols){
	int repeat;
	cout << "Congrats! You solved the game! Here's the answer board" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(answer_board[i][j]=='?'){
				answer_board[i][j]='X';
			}
			cout << answer_board[i][j] << " ";
		} cout << endl;
	}
	delete_the_arrays(answer_board, game_board, rows, cols);
	cout << "Do you want to play again?\n(1)yes\n(2)no" << endl;
	cin >>repeat;
	if(repeat==1)
		new_stats();
	if(repeat==2)
		exit(1);
}

/*********************************************************************
 ** Function: newstats
 ** Description: gets new stats for the next game
 ** Parameters: none
 ** Pre-Conditions: game must be solved
 ** Post-Conditions: none
 *********************************************************************/ 
int new_stats(){
	int rows, cols, mines;
	cout << "Enter how many rows you want: ";
	cin >> rows;
	cout << "Enter how many columns you want: ";
	cin >> cols;
	cout << "Enter how many mines you want: ";
	cin >> mines;
	welcome_screen(rows, cols, mines);
}

/*********************************************************************
 ** Function: delete the arrays
 ** Description: deletes the arrays
 ** Parameters: answerboard, gameboard, rows cols
 ** Pre-Conditions: all things must be valid
 ** Post-Conditions: delets the arrays
 *********************************************************************/ 
void delete_the_arrays(char** answer_board, char** game_board, int rows, int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			delete [] answer_board[j];
			delete [] game_board[j];
		}
		delete [] answer_board[i];
		delete [] game_board[i];
	}
}