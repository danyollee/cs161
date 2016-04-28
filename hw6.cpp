#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void draw_board(int, int, int);
void draw_answer_board(int, int, int);
void place_mines(int, int, int, char**);
void flag_or_open(int, int, int, char**, char**);
void flag_board(char**, int, int);
void open_board(char**, char**, int, int, int, int);
void game_end(char**, int, int);

int main(int argc, char *argv[])
{

  srand(time(NULL));

  char **board;
  char **answer_board;

  int rows = atoi(argv[2]);
  cout <<"Rows: " << rows;

  int columns = atoi(argv[4]);
  cout <<"  | Columns: " << columns;

  int mines = atoi(argv[6]);
  cout <<"  | Mines: " << mines << endl;

  cout << endl;
  cout <<"Hello! Welcome to Minesweeper! " << endl;

  draw_board(rows, columns, mines);
  draw_answer_board(rows, columns, mines);
  flag_or_open(mines, rows, columns, board, answer_board);

  return 0;
}

void draw_board(int rows, int columns, int mines)
{
  char **board = new char*[rows];
  for (int i=0; i<rows; i++)
    board[i] = new char[columns];

  for(int i=0; i<rows; i++)
    for(int j=0; j<columns; j++)
      board[i][j] = '0';

      for(int i=0; i<rows; i++)
      {
        for(int j=0; j<columns; j++)
        {
          cout <<" " << board[i][j];
        }
        cout <<" " << endl;
      }
      cout << endl;

  /*for(int i=0; i<r; i++)
    delete[] array[i];
  delete[] array;*/
}

void draw_answer_board(int rows, int columns, int mines)
{
  char **answer_board = new char*[rows];
  for (int i=0; i<rows; i++)
    answer_board[i] = new char[columns];

  for(int i=0; i<rows; i++)
    for(int j=0; j<columns; j++)
      answer_board[i][j] = '0';

      cout << endl;

      place_mines(mines, rows, columns, answer_board);
}

void place_mines(int mines, int rows, int columns, char** answer_board)
{
  int randr, randc;

  cout <<"There are " << mines << " mines on the board. " << endl;
  cout << endl;

  for(int i = 0; i < mines; i++)
  {
    randr = (rand()%rows); // Randomly assign for Row
    randc = (rand()%columns); // Randomly assign for Columns

    answer_board[randr][randc] = '*';
  }

  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<columns; j++)
    {
      cout <<" " << answer_board[i][j];
    }
    cout <<" " << endl;
  }
  cout << endl;
}

void flag_or_open(int mines, int rows, int columns, char** board, char** answer_board)
{
  int choice, flagr, flagc, openr, openc;
  cout <<"Would you like to Flag(1) or Open(2)? " << endl;
  cin >> choice;

  if(choice == 1)
  {
    //flag_board(answer_board, flagr, flagc);
    game_end(answer_board, rows, columns);
  }

  else if(choice == 2)
  {
    open_board(board, answer_board, openr, openc, rows, columns);
  }

  else
  {
    cout <<"Invalid Choice! " << endl;
  }
}

void flag_board(char** answer_board, int flagr, int flagc)
{
  cout <<"Enter the row: ";
  cin >> flagr;
  cout <<"Enter a column: ";
  cin >> flagc;

  /*if(answer_board[flagr][flagc] == '0')
  {
    cout <<"EYYYY" << endl;
  }*/
  cout <<"  EYYYY " << endl;
}

void open_board(char** board, char** answer_board, int openr, int openc, int rows, int columns)
{
  cout << "Enter a row: ";
  cin >> openr;
  cout << "Enter a column: ";
  cin >> openc;
  cout << "Here" << endl;

  for(int i=0; i<rows; i++)
    for(int j=0; j<columns; j++)
      answer_board[i][j] = '0';

      cout << endl;
  /*if(answer_board[openr][openc] == '*')
  {
    //game_end(answer_board, rows, columns);
    cout <<"You lose! " << endl;
  }
  else
  {
    cout <<"you okay " << endl;
  }*/

  cout << "here1" << endl;
}

void game_end(char** answer_board, int rows, int columns)
{
  cout <<"Game over! " << endl;
  cout <<"Sorry, you lost. " << endl;

  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<columns; j++)
    {
      cout << answer_board[i][j] << " ";
    }
    cout << endl;
  }

}
