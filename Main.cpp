#include <stdio.h>
#include <fstream>

using namespace std;

struct node{
    bool north = false;
    bool south = false;
    bool west = false;
    bool east = false;
    bool up = false;
    bool down = false;
    bool discovered = false;
    struct node* UP;
    struct node* DOWN;
    struct node* WEST;
    struct node* EAST;
    struct node* NORTH;
    struct node* SOUTH;
};

void createMaze(){
    ifstream input_file;
    ofstream output_file;

    input_file.open("input.txt");
    int maze_Num = 0;
    input_file>>maze_Num;
    //setup input for the 6 ponts for start and finish
    //make the matrix values stored in a giant 2d array and traverse that way with nodes of 6 and create the node
    //check values of each node to see directions they can go
}