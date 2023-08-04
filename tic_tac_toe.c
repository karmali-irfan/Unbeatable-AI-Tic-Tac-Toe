//Irfan Karmali 
//Basic Tic_Tac_Toe Game written purely in C
//23.12.2021

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Function with all possible winning permutations
bool win (int x[]){
    if (x[1] == x[4] &&  x[1] ==  x[7]){
        return true;
    }
    else if ( (x[2] ==  x[5]) &&  (x[2] ==  x[8])){
        return true;
    }
    else if ( x[3] ==  x[6] &&  x[6] ==  x[9]){
        return true;
    }
    else if ( x[1] ==  x[2] &&  x[2] ==  x[3]){
        return true;
    }
    else if ( x[4] ==  x[5] &&  x[5] ==  x[6]){
        return true;
    }
    else if ( x[7] ==  x[8] &&  x[8] ==  x[9]){
        return true;
    }
    else if ( x[1] ==  x[5] &&  x[5] ==  x[9]){
        return true;
    }
    else if ( x[3] ==  x[5] &&  x[5] ==  x[7]){
        return true;
    }
    else {
        return false;
    }
}
//Function to print the tic-tac-toe grid
void print_table (int matrix[3][3]){
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3 ; j++){
            printf(" %c ", matrix[i][j]); 
        }
        printf("\n");
    }
}
//Function for assigning the letters to the grid
int arr2matrix (int matrix[3][3], int pos, char i){
    if (pos == 1){
        return matrix[0][0] = i;
    }
    else if (pos == 2) {
        return matrix[0][1] = i;
    }
    else if (pos == 3) {
        return matrix[0][2] = i;
    }
    else if (pos == 4) {
        return matrix[1][0] = i;
    }
    else if (pos == 5) {
        return matrix[1][1] = i;
    }
    else if (pos == 6) {
        return matrix[1][2] = i;
    }
    else if (pos == 7) {
        return matrix[2][0] = i;
    }
    else if (pos == 8) {
        return matrix[2][1] = i;
    }
    else {
        return matrix[2][2] = i;
    }
}


//Main function
int main () {
    int random;
    int matrix[3][3];
    //For loop for assigning '_' to every element in the matrix
    for (int i = 0 ; i < 3 ; i ++){
        for (int j = 0 ; j < 3 ; j++){
            matrix[i][j] = 95;
        }
    } //Loops for setting all the elements in the matrix to _
    int x[9] = {3,4,5,6,7,8,9,10,11} ; //Array for x
    int o[9] = {3,4,5,6,7,8,9,10,11}; //Array for y
    char i;
    int position = 1;
    int arr_pos[9] = {0,0,0,0,0,0,0,0,0}; 
    int count = 3;
    int count1 = -1;
    printf("\nThe rules of the game are simple! It's tic tac toe \n\n"); 
    printf("Do you want to play? (y/n) \n");

    //While aksing user if they want to play
    while (1){ //While loop for user input (y/n)
        scanf("%c", &i);
        getchar();
        if (i == 'n'){
            exit(1);
        }  
        else if ( i == 'y'){
            break;
        }
        else {
            printf("Do you want to play? (y/n) \n");
        }
    }
    printf("Single Player or Double Player (s/d)?\n");
    //While loop asking user if they want a single player game or double
    while (1){ //While loop for user input (y/n)
        scanf("%c", &i);
        getchar();
        if (i == 's'){
            break;
        }  
        else if ( i == 'd'){
            break;
        }
        else {
            printf("Single Player or Double Player \n");
        }
    }
    //If condition asking if the player wants to start, in a Single Player Game
    if (i == 's'){ 
        printf("Do you want to start? (y/n) \n");
        while (1){ //While loop for user input (y/n)
            scanf("%c", &i);
            getchar();
            if (i == 'y'){
                break;
            }  
            else if ( i == 'n'){
                break;
            }
            else {
                printf("Do you want to start? (y/n) \n");
            }
        }
    }
    printf("\nThe positions of the grid are as follows: \n\n");
    //For loop for printing the positions of the matrix
    for (int i = 0; i < 3 ;i++){
        for (int j = 0 ; j < 3 ; j++){
            printf("  %d  ", position + j); 
        }
        printf("\n\n");
        position = position + 3 ;
    }//Loops for printing the position of the grid
    printf("Best of luck! \n\n");
   
    //While loop for Single Player game, when AI starts
while (i == 'n'){
    while(count % 2 != 0){
        count++;
        srand(time(NULL));
        random = (rand() % 9) + 1;
        for (int j  = 0; j < 8 ; j++){
            if (random == arr_pos[j]){
                count--;
                break;
            }
        }
        position = random;
    }
    count1++;
            x[position] = 1;
            arr_pos[count1] = position;
            arr2matrix(matrix, position, 'x');
            print_table(matrix);
            if ( win(x) == true ){
                printf("Player 2 won!\n");
                break;
            }
    while (count %2 == 0){
            count++; 
            printf("You are player one, your letter is o \n");
            printf("Choose position: "); 
            scanf("%d", &position);
            for (int j  = 0; j < 8 ; j++){
                if (position == arr_pos[j]){
                    printf("Position is already taken!\n");
                    printf("Please choose another one.\n");
                    count--;
                    break;
                }
                else if (position > 9){
                    printf("Position is invalid\n");
                    printf("Please choose another one.\n");
                    count--;
                    break;
                }
            }//For loop to check if position is already taken or invalid 
        }
        count1++;
        o[position] = 1; 
        arr_pos[count1] = position;
        arr2matrix(matrix, position, 'o');
        print_table(matrix);
        if ( win(o) == true ){
            printf("You won!\n");
            break;
        }
        printf("\n");
}

//While loop for Single Player, when Player wants to start
while (i == 'y'){
    while (count %2 != 0){
        count++; 
        printf("You are player one, your letter is x \n");
        printf("Choose position: "); 
        scanf("%d", &position);
        for (int j  = 0; j < 8 ; j++){
            if (position == arr_pos[j]){
                printf("Position is already taken!\n");
                printf("Please choose another one.\n");
                count--;
                break;
            }
            else if (position > 9){
                printf("Position is invalid\n");
                printf("Please choose another one.\n");
                count--;
                break;
            }
        }//For loop to check if position is already taken or invalid 
    }
        count1++;
        x[position] = 1; 
        arr_pos[count1] = position;
        arr2matrix(matrix, position, 'x');
        print_table(matrix);
        if (count1 == 8){
            break;
        }
        
        if ( win(x) == true ){
            printf("You won!\n");
            break;
        }
        printf("\n");

    while (count % 2 == 0){
        count++;
        srand(time(NULL));
        random = (rand() % 9) + 1;
        for (int j  = 0; j < 8 ; j++){
            if (random == arr_pos[j]){
                count--;
                break;
            }
        }
        position = random;
    }
        printf("AI has decided to play the following. \n");
        count1++;
        o[position] = 1;
        arr_pos[count1] = position;
        arr2matrix(matrix, position, 'o');
        print_table(matrix);
        if ( win(o) == true ){
            printf("AI won!\n");
            break;
        }

}

    //While loop for Double Players
    while (i == 'd'){
        while (count %2 != 0){
                count++; 
                printf("You are player one, your letter is x \n");
                printf("Choose position: "); 
                scanf("%d", &position);
                for (int j  = 0; j < 8 ; j++){
                    if (position == arr_pos[j]){
                        printf("Position is already taken!\n");
                        printf("Please choose another one.\n");
                        count--;
                        break;
                    }
                    else if (position > 9){
                        printf("Position is invalid\n");
                        printf("Please choose another one.\n");
                        count--;
                        break;
                    }
                }//For loop to check if position is already taken or invalid 
            }
            count1++;
            x[position] = 1; 
            arr_pos[count1] = position;
            arr2matrix(matrix, position, 'x');
            print_table(matrix);
            if (count1 == 8){
                break;
            }
            
            if ( win(x) == true ){
                printf("Player 1 won!\n");
                break;
            }
            printf("\n");
                while (count % 2 == 0){
                    count++; 
                    printf("You are player two, your letter is o \n");
                    printf("Choose position: "); 
                    scanf("%d", &position);
                    for (int j  = 0; j < 8 ; j++){
                        if (position == arr_pos[j]){
                            printf("Position is already taken!\n");
                            printf("Please choose another one.\n");
                            count--;
                            break;
                        }
                        else if (position > 9){
                            printf("Position is invalid\n");
                            printf("Please choose another one.\n");
                            count--;
                            break;
                        }//For loop to check if position is taken or invalid
                    }
                }
            count1++;
            o[position] = 1;
            arr_pos[count1] = position;
            arr2matrix(matrix, position, 'o');
            print_table(matrix);
            if ( win(o) == true ){
                printf("Player 2 won!\n");
                break;
            }
    }
    if (count1 == 8){
        printf("The game is a tie! \n");
    }
    return 0; 
}