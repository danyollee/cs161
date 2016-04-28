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
void open_the_board_a_lot(char**, char**, int***, int***, int, int);
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
	cout << "Rows: " << rows << " rows | Columns: " << cols << " | Mines: " << mines << endl;
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
			game_board[i][j]='O';
		}
	}

	place_mines(answer_board, game_board, rows, cols, mines);
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
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			open_ze_boards_1(answer_board, game_board, i, j, rows, cols);
		}
	}
	cout << endl;
	main2(answer_board, game_board, rows, cols);
}

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
	cout << endl << "Answer board" << endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << answer_board[i][j] << " ";
		} cout << endl;
	}
}

void main2(char** answer_board, char** game_board, int rows, int cols){
	bool solved;
	int player_choice, row_choice, col_choice; 
	while(solved==false){
		print_boards(answer_board, game_board, rows, cols);
		get_player_choice(answer_board, game_board, player_choice, &row_choice, &col_choice, rows, cols);
		cout << "You picked row " << row_choice << " and column " << col_choice << endl;
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
	print_boards(answer_board, game_board, rows, cols);
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
	}else if(answer_board[***row_choice][***col_choice]>48) 
		game_board[***row_choice][***col_choice]=answer_board[***row_choice][***col_choice];
	else if(answer_board[***row_choice][***col_choice]==48){
		game_board[***row_choice][***col_choice]=answer_board[***row_choice][***col_choice];
		open_the_board_a_lot(answer_board, game_board, row_choice, col_choice, rows, cols);
	}
}

void open_the_board_a_lot(char** answer_board, char** game_board, int*** row_choice, int*** col_choice, int rows, int cols){
	int i=1;
	while(answer_board[***row_choice+i][***col_choice]==48 && ***row_choice<rows && ***col_choice<cols){
		game_board[***row_choice+i][***col_choice]=answer_board[***row_choice+i][***col_choice];
		i++;
	}
	/*while(answer_board[***row_choice-i][***col_choice]==48 && ***row_choice>=0 && ***col_choice>=0){
		game_board[***row_choice-i][***col_choice]=answer_board[***row_choice-i][***col_choice];
		i++;
	}
	while(answer_board[***row_choice][***col_choice+i]==48 && ***col_choice<cols && ***row_choice<rows){
		game_board[***row_choice][***col_choice+i]=answer_board[***row_choice][***col_choice+i];
		i++;
	}
	while(answer_board[***row_choice][***col_choice-i]==48 && ***col_choice>=0 && ***row_choice>=0){
		game_board[***row_choice][***col_choice-i]=answer_board[***row_choice][***col_choice-i];
		i++;
	}*/
}

void open_ze_boards_1(char** answer_board, char** game_board, int i, int j, int rows, int cols){
	char counter;
	if(answer_board[i][j]=='?')
		return;
	if(i==0 || j==0 || i==(rows-1) || j==(cols-1))
		open_ze_boards_2(answer_board, game_board, i, j, rows, cols, counter);
	if(i>0 && j>0 && i<(rows-1) && j<(cols-1))
		open_surroundings(answer_board, game_board, i, j, counter);
}

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

void open_topleft_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i+1][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

void open_bottomright_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i-1][j-1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

void open_bottomleft_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i-1][j]=='?') counter++;
	if(answer_board[i][j+1]=='?') counter++;
	if(answer_board[i-1][j+1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

void open_topright_corner(char** answer_board, char** game_board, int i, int j, char counter){
	counter=48;
	if(answer_board[i+1][j]=='?') counter++;
	if(answer_board[i][j-1]=='?') counter++;
	if(answer_board[i+1][j-1]=='?') counter++;
	if(counter>48) answer_board[i][j]=counter;
	if(counter==48) answer_board[i][j]=counter;
}

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