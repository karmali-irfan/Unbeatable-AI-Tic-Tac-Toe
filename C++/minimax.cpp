#include <iostream>
#include "minimax.h"
#include <cstdlib>
#include <limits>
using namespace std;

bool AI;

//Function for printing grid
void print_grid(Grid g){ 
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3 ; j++){
            cout << g.grid[i][j] << " ";
        }
        cout << endl ;
    }
    cout << endl;
}

//Function to initialize grid 
void initialize_grid(Grid &a){
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3 ; j++){
            a.grid[i][j] = "_"; 
        }
    }
}

//Function to check if any moves are left
bool moves_left(Grid g){
    for (int i = 0; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (g.grid[i][j] == "_"){
                return true;
            }
        }
    }
    return false;
}

//Randomizer function
void randomizer(Grid &g){
    srand((int) time(0));
    while (1) {
        int i = rand() % 2 + 1;
        int j = rand() % 2 + 1;
        if (g.grid[i][j] == "_"){
            g.grid[i][j] = "o";
            break; 
        }
    }
}

//Function for user input 
void user_input(Grid &g){
    Move m; 
    while (1){
        cout << "Enter row:";
        cin >> m.row; 
        cout << "Enter col:";
        cin >> m.col;
        if (g.grid[m.row - 1][m.col - 1] == "_"){
            g.grid[m.row - 1][m.col - 1] = "o";
            cout << "Valid input!" << endl ;
            break;
        }
        else {
            cout << "Invalid Input! Choose a valid position" << endl;
        }
    }
}

//Function to check for a winner
bool win(Grid g, string str){
    //Horizontal wins
    if (g.grid[0][0] == str && g.grid[0][1] == str && g.grid[0][2] == str){
        return true;
    }
    else if (g.grid[1][0] == str && g.grid[1][1] == str && g.grid[1][2] == str){
        return true;
    }
    else if (g.grid[2][0] == str && g.grid[2][1] == str && g.grid[2][2] == str){
        return true;
    }
    //Vertical wins
    else if (g.grid[0][0] == str && g.grid[1][0] == str && g.grid[2][0] == str){
        return true;
    }
    else if (g.grid[0][1] == str && g.grid[1][1] == str && g.grid[2][1] == str){
        return true;
    }
    else if (g.grid[0][2] == str && g.grid[1][2] == str && g.grid[2][2] == str){
        return true;
    }
    //Diagonal Wins 
    else if (g.grid[2][0] == str && g.grid[1][1] == str && g.grid[0][2] == str){
        return true;
    }
    else if (g.grid[0][0] == str && g.grid[1][1] == str && g.grid[2][2] == str){
        return true;
    }
    else {
        return false;
    }
}

//Implementation of the minimax algorithm 
int minimax (Grid g, int depth, bool AI){
    if (win(g, "x") ==  true){
        return 10; 
    }//Tries to win 
    if (win(g, "o") ==  true){
        return -10; 
    }//Prevents a loss
    if (moves_left(g) == false){
        return 0;
    }//Forces a draw

    if (AI == true){
        int best = -9999;//numeric_limits<int>::min(); 
        for (int i = 0; i < 3 ; i++){
            for (int j = 0; j < 3 ; j++){
                if (g.grid[i][j] == "_"){
                    g.grid[i][j] = "x";
                    best = max(best, minimax(g, depth + 1, false));
                    g.grid[i][j] = "_";
                } 
            }
        }
        return best;
    }
    else { 
        int best = 9999;//numeric_limits<int>::max(); 
        for (int i = 0; i < 3 ; i++){
            for (int j = 0; j < 3 ; j++){
                if (g.grid[i][j] == "_"){
                    g.grid[i][j] = "o";
                    best = min(best, minimax(g, depth + 1, true)); 
                    g.grid[i][j] = "_";
                }
            }
        }
        return best;
    } 
}

//Function to check for the best move
void bestmove(Grid &g){
    Move m; 
    m.row = 2; 
    m.col = 2;
    int bestval = -1000;
   for (int i = 0; i < 3 ; i++){
       for (int j = 0; j < 3 ; j++){
           if(g.grid[i][j] == "_"){
               g.grid[i][j] = "x";
               int val = minimax(g, 0, false);
               g.grid[i][j] = "_";
               if (val > bestval){
                   bestval = val; 
                   m.row = i; 
                   m.col = j;
               }
           }
       }
    }
    g.grid[m.row][m.col] = "x"; 
}

//Checking for a winner
void check_grid(Grid g) {
    if (win(g, "x") ==  true) {
        cout << "AI wins!" << endl;
        exit(1);
    }
    if (win(g, "o") ==  true) {
        cout << "Human Player wins!" << endl; 
        exit(1);
    }
    if (moves_left(g) == false){
        cout << "Game is a draw!" << endl;
        exit(1);
    }
}
