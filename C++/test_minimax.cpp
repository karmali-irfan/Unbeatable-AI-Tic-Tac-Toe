#include <iostream> 
#include "minimax.h"

using namespace std; 

int main (){
    Grid g; 
    Move m;
    initialize_grid(g); //Initializing a grid 
    print_grid(g); //Printing a grid

    while(1) { //While loop to allow user to play with AI
        bestmove(g);
        print_grid(g);
        check_grid(g);
        user_input(g);
        print_grid(g);
        check_grid(g);
    }
    
    return 0;
}