#include <iostream>

using namespace std;

void hanoi(int, int, int, int);

int main() {
  int disks; 

  cout << "How many disks?: ";
  cin >> disks;
  //Move all 3 disks from peg 0 to peg 1 using peg 2 as a temporary.
  hanoi(disks, 0, 1, 2);
  return 0;
}

void hanoi(int disk, int source, int dest, int spare) {
  if(disk == 0)
  {
    cout << "Move disk " << disk << " from peg " << source << " to peg " << dest << endl;
  }
  else
  {
    //Move all disks smaller than this one over to the spare.
    //So if diskSize is 5, we move 4 disks to the spare. This leaves us with 1 disk
    //on the source peg.
    //Note the placement of the params.
    //We are now using the dest peg as the spare peg. This causes each recursion to ping-pong
    //the spare and dest pegs.
    hanoi(disk - 1, source, spare, dest);

    //Move the remaining disk to the destination peg.
    cout << "Move disk "  << disk << " from peg " << source << " to peg " << dest << endl;

    //Move the disks we just moved to the spare back over to the dest peg.
    hanoi(disk - 1, spare, dest, source);
  }
}