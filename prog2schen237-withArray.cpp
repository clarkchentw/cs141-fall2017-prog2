/* --------------------------------------------------------
 * Traffic.cpp
 *     Text-based version of the game RushHour, where the
 *     object is to move the vehicles such that the small
 *     car can exit the right of the board.
 *
 * Class: Program #2 for CS 141, Fall 2017.  
 * Lab: Tues 9am
 * TA: Moumita Samanta 
 * System: Cloud9
 * Author: Clark Chen
 */

#include <iostream>
#include <cctype>      // for toupper()
#include <stdio.h>      // for getche()
#include <cmath>        // for abs()
using namespace std;

// Global variables and constants
// Variables to store the board pieces
int numOfMoves = 0;
char pointData[37];

//--------------------------------------------------------------------
// Display ID info
void displayIDInfo()
{
    printf("Author:  Clark Chen          \n");
    printf("Lab:     Tues 9am            \n");
    printf("Program: #2, Traffic \n");
    printf(" \n");
}//end displayIDInfo()


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to the traffic game!                          " << endl
         << "                                                      " << endl
         << "Move the vehicles so that the Red car (RR) can exit   " << endl
         << "the board to the right. Each move should be of the    " << endl
         << "of the form:   CDN   where:                           " << endl
         << "   C  is the vehicle to be moved                      " << endl
         << "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
         << "   N  is the number of squares to move it             " << endl
         << "For example GR2  means move the G vehicle to the right" << endl
         << "2 squares.  Lower-case input such as   gr2  is also   " << endl
         << "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl;
}//end displayInstructions()



//--------------------------------------------------------------------
// Display the board, using the current values in the global variables.
void displayBoard( )
{
    cout << "- - - - - - -" << endl;
    cout << "|" << pointData[1]  << " " << pointData[2]  << " " << pointData[3]  << " " << pointData[4]  << " " << pointData[5]  << " " << pointData[6]  << " |" << endl;
    cout << "|" << pointData[7]  << " " << pointData[8]  << " " << pointData[9]  << " " << pointData[10] << " " << pointData[11] << " " << pointData[12] << " |" << endl;
    cout << "|" << pointData[13] << " " << pointData[14] << " " << pointData[15] << " " << pointData[16] << " " << pointData[17] << " " << pointData[18] << " " << endl;
    cout << "|" << pointData[19] << " " << pointData[20] << " " << pointData[21] << " " << pointData[22] << " " << pointData[23] << " " << pointData[24] << " |" << endl;
    cout << "|" << pointData[25] << " " << pointData[26] << " " << pointData[27] << " " << pointData[28] << " " << pointData[29] << " " << pointData[30] << " |" << endl;
    cout << "|" << pointData[31] << " " << pointData[32] << " " << pointData[33] << " " << pointData[34] << " " << pointData[35] << " " << pointData[36] << " |" << endl;
    cout << "- - - - - - -" << endl;
}//end displayBoard()

//--------------------------------------------------------------------
// Moving Action
// function for moving the piece.
// "origin" is it's original point, and "dest" is the destination point
void startMove(int origin, int dest){
    pointData[dest] = pointData[origin];
    pointData[origin] = '.';
}

//--------------------------------------------------------------------
// Validate Moving Action
// Make sure they are not moving out of bound or moving onto another
// piece.
bool validateMove(int origin, int dest){
    if (pointData[dest] != '.'){
        cout << "*** Move was attempted, but couldn't be completed. ***" << endl << endl;
        numOfMoves--;
        return false;
    }
    // validation for horizontal move
    if (abs(origin-dest) == 1 && ((origin / 6) == (dest / 6) || (dest % 6 == 0 && (origin / 6) == (dest / 6)-1) || (origin % 6 == 0 && (origin / 6)-1 == (dest / 6)))){
        startMove(origin, dest);
        return true;
    }
    // validation for vertical move
    else if (abs(origin-dest) == 6 && ((origin % 6) == (dest % 6))){
        startMove(origin, dest);
        return true;
    }
    else{
        cout << "    *** Move was attempted, but couldn't be completed. ***  " << endl << endl;
        numOfMoves--;
        return false;
    }
}

//--------------------------------------------------------------------
// Move the selected vehicle vertically
// Parameter C  is the vehicle to be moved, 
// D  is the direction (u=up, d=down)
// N  is the number of squares to move it
bool moveV(char C, char D, int N)
{
    // tempx are for temp location info of the car
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    // Search for the position of the car
    for (int i = 36; i >= 1; i--){
        if (pointData[i] == C){
            if (temp1 == 0){
                temp1 = i;
            }
            else if (temp2 == 0){
                temp2 = i;
            }
            else if (temp3 == 0){
                temp3 = i;
            }
        }
    }
    // check to make sure the car can move vertically
    if (abs(temp1-temp2) == 1){
        cout << "    *** Move was attempted, but couldn't be completed. ***  " << endl;
        numOfMoves--;
        return false;
    }
    if (D == 'U'){
        if (temp3 != 0){
            if (!validateMove(temp3, temp3-6)){
                return false;
            }
        }
        if (!validateMove(temp2, temp2-6)){
            return false;
        }
        if (!validateMove(temp1, temp1-6)){
            return false;
        }
    }
    else if (D == 'D'){
        if (!validateMove(temp1, temp1+6)){
            return false;
        }
        if (!validateMove(temp2, temp2+6)){
            return false;
        }
        if (temp3 != 0){
            if (!validateMove(temp3, temp3+6)){
                return false;
            }
        }
    }
    return true;
}//end moveV(char C, char D, int N)


//--------------------------------------------------------------------
// Move the selected vehicle horizontally
// Parameter C  is the vehicle to be moved, 
// D  is the direction (l=left or r=right)
// N  is the number of squares to move it
bool moveH(char C, char D, int N)
{
    // tempx are for temp location info of the car
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    
    // Search for the position of the car
    for (int i = 36; i >= 1; i--){
        if (pointData[i] == C){
            if (temp1 == 0){
                temp1 = i;
            }
            else if (temp2 == 0){
                temp2 = i;
            }
            else if (temp3 == 0){
                temp3 = i;
            }
        }
    }
    
    // check to make sure the car can move horizontally
    if (abs(temp1-temp2) == 6){
        cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
        numOfMoves--;
        return false;
    }
    
    if (D == 'L'){
        if (temp3 != 0){
            if (!validateMove(temp3, temp3-1)){
                return false;
            }
        }
        if (!validateMove(temp2, temp2-1)){
            return false;
        }
        if (!validateMove(temp1, temp1-1)){
            return false;
        }
    }
    else if (D == 'R'){
        if (!validateMove(temp1, temp1+1)){
            return false;
        }
        if (!validateMove(temp2, temp2+1)){
            return false;
        }
        if (temp3 != 0){
            if (!validateMove(temp3, temp3+1)){
                return false;
            }
        }
    }
    return true;
}//end moveH(char C, char D, int N)

//--------------------------------------------------------------------
// Reset the board
void resetBoard(){
    numOfMoves = 0;
    // Set the board values
     pointData[1]='G'; pointData[2]='G'; pointData[3]='.'; pointData[4]='.'; pointData[5]='.'; pointData[6]='Y';
     pointData[7]='P'; pointData[8]='.'; pointData[9]='.';pointData[10]='B';pointData[11]='.';pointData[12]='Y';
    pointData[13]='P';pointData[14]='R';pointData[15]='R';pointData[16]='B';pointData[17]='.';pointData[18]='Y';
    pointData[19]='P';pointData[20]='.';pointData[21]='.';pointData[22]='B';pointData[23]='.';pointData[24]='.';
    pointData[25]='O';pointData[26]='.';pointData[27]='.';pointData[28]='.';pointData[29]='T';pointData[30]='T';
    pointData[31]='O';pointData[32]='.';pointData[33]='F';pointData[34]='F';pointData[35]='F';pointData[36]='.';
} // end resetBoard();

//--------------------------------------------------------------------
// exit the game
void exitGame(){
    cout << endl;
    cout << "Thank you for playing.  Exiting..." << endl;
    exit(0);
}


//--------------------------------------------------------------------
// Create custom board
void createBoard(bool needDirection){
    if (needDirection){
        cout << "You have chosen to reset the board." << endl;
        cout << "Enter 36 characters for the new board:" << endl;
    }
    // Ignore the letter not input by the user
    char ignore;
    for (int i = 1; i <= 36; i++){
        char userInput = getchar();
        if (((userInput != '\n') && (isalpha(userInput))) || (userInput == '.')){
            pointData[i] = userInput;
        }
        else{
            i--;
        }
        // exit check
        if (userInput == 'X'){
            exitGame();
        }
    }
    
    // Fix extra enter entry at the end
    ignore = getchar();
    
    cout << endl << endl << endl << endl << endl << endl << endl << "Your new board has been successfully created!" << endl << endl;
}

//--------------------------------------------------------------------
// Input Check: check for special function key, and make sure user
// input a valid command length
bool inputCheck(char userInput){
    bool pass = true;
    if (userInput == 'X'){
        exitGame();
    }
    else if (userInput == '-'){
        createBoard(true);
        pass = false;
    }
    else if (userInput == '\n'){
        pass = false;
    }
    return pass;
}


//--------------------------------------------------------------------
// Process user command
void controlUnit(){
    char C;
    char D;
    int N;
    char captureEnterKey;
    cout << numOfMoves << ". Your move -> ";
    C = getchar();
    C = toupper(C);
    // Prevent user enter too many character
    if (!inputCheck(C)){
        return;
    };
    D = getchar();
    D = toupper(D);
    // Prevent user enter too many character
    if (!inputCheck(D)){
        return;
    };
    N = getchar() - '0';
    // Prevent user enter too many character, and make sure the input is number
    if (!inputCheck(N) || (isdigit(N) && N <= 4)){
        return;
    };
    
    captureEnterKey = getchar();
    // Prevent user enter too many character
    if (captureEnterKey != '\n'){
        return;
    }
    
    // Loop through the board to check if the car(C) exist
    bool validCar = false;
    for(int i = 1; i <= 36; i++){
        if (pointData[i] == C){
            validCar = true;
            break;
        }
    }

    if (!validCar){
        cout << "invalid command (C)" << endl << endl;
    }
    else if(!(0 < N < 10)){
        cout << "invalid command (N)" << endl << endl;
    }
    else{
        // Increase move count by 1
        numOfMoves += 1;
        if (D == 'L' || D == 'R'){
            for (int i=N;i>0;i--){
                if (!moveH(C, D, N)){
                    break;
                }
            }
            cout << endl << endl;
        }
        else if (D == 'U' || D == 'D'){
            for (int i=N;i>0;i--){
                if (!moveV(C, D, N)){
                    break;
                }
            }
            cout << endl << endl;
        }
        else{
            cout << "invalid command (D)" << endl << endl;
            numOfMoves--;
        }
    }
} // end controlUnit()

//--------------------------------------------------------------------
// win the game
void winGame(){
    cout << "*** Congratulations, you did it! ***" << endl;
    exitGame();
}

//--------------------------------------------------------------------
/*  Board and corresponding global variable values are:
           - - - - - - - -
         1 | G G . . . Y |
         7 | P . . B . Y |
        13 | P R R B . Y >
        19 | P . . B . . |
        25 | O . . . T T |
        31 | O . F F F . |
           - - - - - - - -
 */
int main()
{
    // Declare your variables here
    // ...
    char userInput;
    displayIDInfo();        // Display ID info
    displayInstructions();  // Display game instructions
    
    // Set the board values
    resetBoard();
    
    // Display the initial board
    
    // 
    while (true){
        displayBoard();
        controlUnit();
        if (pointData[18] == 'R'){
            winGame();
        }
    }
    
    return 0;
}//end main()



