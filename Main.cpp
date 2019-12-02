#include <stdio.h>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;
int *totalmaze;
int start_maze[3];
int finish_maze[3];
int maze_end_location;
int maze[3];
bool *visited;
stack <string> s;

//pointer struct for storing the next node;
struct adjNode{
    string id;
    adjNode *next;
};

void createMaze();

/*this function takes in a location of the node and will check the given parameters on where it can traverse.
if the node cannot find the end it returns NULL so the call before it can traverse as needed*/
adjNode* find_end(int location){
    adjNode *Node = new adjNode();
    
    Node->next = NULL;
    if(visited[location]==true){
        
        return NULL;
    }
   
    visited[location] = true;
    if(location ==maze_end_location){
        
        visited[location] == false;
        return Node;
    }


    if(totalmaze[location*6] == 1){
        Node->next = find_end(location-maze[2]);
        
        if (Node->next!=NULL){
            s.push("N");
            return Node;
        }
        Node->next = NULL;
    }
    if((totalmaze[location*6+1])==1){
         Node->next = find_end(location+1);
         
      if(Node->next!=NULL){
          s.push("E");
            return Node;
        }
        Node->next = NULL;
    }
     if((totalmaze[location*6+2])==1){
         Node->next = find_end(location+maze[2]);
         
         if(Node->next!=NULL){
             s.push("S");
            return Node;
        }
        Node->next = NULL;
    }
     if((totalmaze[location*6+3])==1){
         Node->next = find_end(location-1);
        
        if(Node->next!=NULL){
            s.push("W");
            return Node;
        }
        Node->next = NULL;
    }
     if((totalmaze[location*6+4])==1){
         Node->next = find_end(location+(maze[2]*maze[1]));
         
         if(Node->next!=NULL){
             s.push("U");
            return Node;
        }
        Node->next = NULL;
    }
     if((totalmaze[location*6+5])==1){
         Node->next = find_end(location-(maze[1]*maze[2]));
         
        if(Node->next!=NULL){
            s.push("D");
            return Node;
        }
        Node->next = NULL;
    }
    
    return NULL;

}
///////////////////////////////////////////////////////////////////////////////

//main function////////////////////////////////////////
int main(){
    createMaze();    
    return 0;
}
///////////////////////////////////////////////////////


/*format the input file and call the traversing function
This then outputs the needed info to the output file*/
void createMaze()
{
    ifstream input_file;
    ofstream output_file;

    input_file.open("input.txt");
    output_file.open("output.txt");
    int maze_Num = 0;
    input_file >> maze_Num;
    //setup input for the 6 ponts for start and finish

    for(int pointer = 0; pointer < maze_Num; pointer++){
    for (int i = 0; i < 3; i++)
    {
        input_file >> maze[i];
    }
    for (int i = 0; i < 3; i++)
    {
        input_file >> start_maze[i];
    }
    for (int i = 0; i < 3; i++)
    {
        input_file >> finish_maze[i];
    }

    totalmaze = new int[(maze[0] * maze[1] * maze[2] * 6)];
    

    visited = new bool[maze[0] * maze[1] * maze[2]];

    for (int i = 0; i < maze[0] * maze[1] * maze[2]; i++)
    {
        int temp;
        input_file >> temp;
        visited[i] = false;
        for (int j = 0; j < 6; j++)
        {
            int temp_value = temp % 2;

            totalmaze[(i * 6) + 5 - j] = temp_value;
            temp = temp / 10;
        }
    }

    
    
    
    int location = (start_maze[0]*maze[1]*maze[2]+ start_maze[1]*maze[2] + start_maze[2]);
    maze_end_location = ((finish_maze[0])*maze[1]*maze[2] + (finish_maze[1])*maze[2] + (finish_maze[2]));
    
    adjNode *root = new adjNode();
    root = find_end(location);

    while (!s.empty()) { 
        output_file << s.top() << " ";
        s.pop(); 
    } 
    
    output_file << "\n\n";

    }

    input_file.close();
    output_file.close();
}