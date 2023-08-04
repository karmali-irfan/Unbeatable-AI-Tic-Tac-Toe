#include <iostream> 

using namespace std; 

//Declaring a struct for a move
struct Move{
    int row; 
    int col;
};

//Declaring a struct for a Grid
struct Grid {
    string grid[3][3];
}; 

void print_grid(Grid g); 

void initialize_grid(Grid &g);

bool moves_left(Grid g);

bool win(Grid g, string str);

void randomizer(Grid &g);

void user_input(Grid &g);

int minimax (Grid g, int depth, bool AI); 

void bestmove(Grid &g);

void check_grid(Grid g);
