#include "Main.h"
#include "AStar.h"
#include "AStar.cpp"

int main(){
//Functional testing
ASTAR newMaze;
    if (newMaze.buildAdjList("C://Users//Zach's PC//CLionProjects//AStar//test-maze.txt"))
        cout << "Able to input and build the AdjList \n";
}