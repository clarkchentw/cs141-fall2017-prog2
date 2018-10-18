/* --------------------------------------------------------
 * Traffic.cpp
 *     Text-based version of the game RushHour, where the
 *     object is to move the vehicles such that the small
 *     car can exit the right of the board.
 *
 * Class: Program #2 for CS 141, Fall 2017.  
 * Lab: ???,
 * TA ???
 * System: Mac OS X
 * Author: ??? ???
 */

#include <iostream>
#include <cctype>      // for toupper()
#include <stdio.h>      // for getche()
#include <cmath>        // for abs()
using namespace std;

// Global variables and constants
// Variables to store the board pieces
char  p1, p2, p3, p4, p5, p6,
      p7, p8, p9,p10,p11,p12,
     p13,p14,p15,p16,p17,p18,
     p19,p20,p21,p22,p23,p24,
     p25,p26,p27,p28,p29,p30,
     p31,p32,p33,p34,p35,p36;
int numOfMoves = 0;
bool endGame = false;


//--------------------------------------------------------------------
// Display ID info
void displayIDInfo()
{
    printf("Author:  ??? ????          \n");
    printf("Lab:     Mon 5am            \n");
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
    cout << endl;
    cout << "- - - - - - -" << endl;
    cout << "|" << p1  << " " << p2  << " " << p3  << " " << p4  << " " << p5  << " " << p6  << " |" << endl;
    cout << "|" << p7  << " " << p8  << " " << p9  << " " << p10 << " " << p11 << " " << p12 << " |" << endl;
    cout << "|" << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " " << p18 << " " << endl;
    cout << "|" << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " |" << endl;
    cout << "|" << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " " << p30 << " |" << endl;
    cout << "|" << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " " << p36 << " |" << endl;
    cout << "- - - - - - -" << endl;
}//end displayBoard()



//--------------------------------------------------------------------
// To write value into variable px
// parameter address is the x in px, value is the new value assign to it.
void writeP(int address, char value)
{
    switch(address) {
        case 1:
            p1 = value;
            break;
        case 2:
            p2 = value;
            break;
        case 3:
            p3 = value;
            break;
        case 4:
            p4 = value;
            break;
        case 5:
            p5 = value;
            break;
        case 6:
            p6 = value;
            break;
        case 7:
            p7 = value;
            break;
        case 8:
            p8 = value;
            break;
        case 9:
            p9 = value;
            break;
        case 10:
            p10 = value;
            break;
        case 11:
            p11 = value;
            break;
        case 12:
            p12 = value;
            break;
        case 13:
            p13 = value;
            break;
        case 14:
            p14 = value;
            break;
        case 15:
            p15 = value;
            break;
        case 16:
            p16 = value;
            break;
        case 17:
            p17 = value;
            break;
        case 18:
            p18 = value;
            break;
        case 19:
            p19 = value;
            break;
        case 20:
            p20 = value;
            break;
        case 21:
            p21 = value;
            break;
        case 22:
            p22 = value;
            break;
        case 23:
            p23 = value;
            break;
        case 24:
            p24 = value;
            break;
        case 25:
            p25 = value;
            break;
        case 26:
            p26 = value;
            break;
        case 27:
            p27 = value;
            break;
        case 28:
            p28 = value;
            break;
        case 29:
            p29 = value;
            break;
        case 30:
            p30 = value;
            break;
        case 31:
            p31 = value;
            break;
        case 32:
            p32 = value;
            break;
        case 33:
            p33 = value;
            break;
        case 34:
            p34 = value;
            break;
        case 35:
            p35 = value;
            break;
        case 36:
            p36 = value;
            break;
        default:
            break;
    }
}//end writeP()

//--------------------------------------------------------------------
// To read value of variable px
// parameter address is the x in px, it will return the value assign to that variable.
char readP(int address)
{
    char returnValue;
    switch(address) {
        case 1:
            returnValue = p1;
            break;
        case 2:
            returnValue = p2;
            break;
        case 3:
            returnValue = p3;
            break;
        case 4:
            returnValue = p4;
            break;
        case 5:
            returnValue = p5;
            break;
        case 6:
            returnValue = p6;
            break;
        case 7:
            returnValue = p7;
            break;
        case 8:
            returnValue = p8;
            break;
        case 9:
            returnValue = p9;
            break;
        case 10:
            returnValue = p10;
            break;
        case 11:
            returnValue = p11;
            break;
        case 12:
            returnValue = p12;
            break;
        case 13:
            returnValue = p13;
            break;
        case 14:
            returnValue = p14;
            break;
        case 15:
            returnValue = p15;
            break;
        case 16:
            returnValue = p16;
            break;
        case 17:
            returnValue = p17;
            break;
        case 18:
            returnValue = p18;
            break;
        case 19:
            returnValue = p19;
            break;
        case 20:
            returnValue = p20;
            break;
        case 21:
            returnValue = p21;
            break;
        case 22:
            returnValue = p22;
            break;
        case 23:
            returnValue = p23;
            break;
        case 24:
            returnValue = p24;
            break;
        case 25:
            returnValue = p25;
            break;
        case 26:
            returnValue = p26;
            break;
        case 27:
            returnValue = p27;
            break;
        case 28:
            returnValue = p28;
            break;
        case 29:
            returnValue = p29;
            break;
        case 30:
            returnValue = p30;
            break;
        case 31:
            returnValue = p31;
            break;
        case 32:
            returnValue = p32;
            break;
        case 33:
            returnValue = p33;
            break;
        case 34:
            returnValue = p34;
            break;
        case 35:
            returnValue = p35;
            break;
        case 36:
            returnValue = p36;
            break;
        default:
			returnValue = 0;
            break;
	return returnValue;
    }
}//end readP(int address)

//--------------------------------------------------------------------
// Moving Action
void startMove(int origin, int dest){
    writeP(dest, readP(origin));
    writeP(origin, '.');
}

//--------------------------------------------------------------------
// Validate Moving Action
bool validateMove(int origin, int dest){
    if (readP(dest) != '.'){
        cout << "*** Move was attempted, but couldn't be completed. ***" << endl << endl;
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
        return false;
    }
}

//--------------------------------------------------------------------
// Move the selected vehicle vertically
// Parameter C  is the vehicle to be moved, 
// D  is the direction (u=up, d=down)
// N  is the number of squares to move it
void moveV(char C, char D, int N)
{
    // tempx are for temp location info of the car
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    // Search for the position of the car
    for (int i = 36; i >= 1; i--){
        if (readP(i) == C){
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
    // check if car is vertical or horizontal
    if (abs(temp1-temp2) == 1){
        cout << "    *** Move was attempted, but couldn't be completed. ***  " << endl;
        return;
    }
    
    if (D == 'U'){
        if (temp3 != 0){
            if (!validateMove(temp3, temp3-6)){
                return;
            }
        }
        if (!validateMove(temp2, temp2-6)){
            return;
        }
        if (!validateMove(temp1, temp1-6)){
            return;
        }
    }
    else if (D == 'D'){
        if (!validateMove(temp1, temp1+6)){
            return;
        }
        if (!validateMove(temp2, temp2+6)){
            return;
        }
        if (temp3 != 0){
            if (validateMove(temp3, temp3+6)){
                return;
            }
        }
    }
}//end moveV(char C, char D, int N)


//--------------------------------------------------------------------
// Move the selected vehicle horizontally
// Parameter C  is the vehicle to be moved, 
// D  is the direction (l=left or r=right)
// N  is the number of squares to move it
void moveH(char C, char D, int N)
{
    // tempx are for temp location info of the car
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    
    // Search for the position of the car
    for (int i = 36; i >= 1; i--){
        if (readP(i) == C){
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
    
    // check if car is vertical or horizontal
    if (abs(temp1-temp2) == 6){
        cout << "*** Move was attempted, but couldn't be completed. ***" << endl;
        return;
    }
    
    if (D == 'L'){
        if (temp3 != 0){
            if (!validateMove(temp3, temp3-1)){
                return;
            }
        }
        if (!validateMove(temp2, temp2-1)){
            return;
        }
        if (!validateMove(temp1, temp1-1)){
            return;
        }
    }
    else if (D == 'R'){
        if (!validateMove(temp1, temp1+1)){
            return;
        }
        if (!validateMove(temp2, temp2+1)){
            return;
        }
        if (temp3 != 0){
            if (!validateMove(temp3, temp3+1)){
                return;
            }
        }
    }
}//end moveH(char C, char D, int N)

//--------------------------------------------------------------------
// Reset the board
void resetBoard(){
    numOfMoves = 0;
    // Set the board values
     p1='G'; p2='G'; p3='.'; p4='.'; p5='.'; p6='Y';
     p7='P'; p8='.'; p9='.';p10='B';p11='.';p12='Y';
    p13='P';p14='R';p15='R';p16='B';p17='.';p18='Y';
    p19='P';p20='.';p21='.';p22='B';p23='.';p24='.';
    p25='O';p26='.';p27='.';p28='.';p29='T';p30='T';
    p31='O';p32='.';p33='F';p34='F';p35='F';p36='.';
} // end resetBoard();

//--------------------------------------------------------------------
// exit the game
void exitGame(){
    if (p18 = 'R'){
        cout << "*** Congratulations, you did it! ***" << endl << endl;
        
    }
    cout << endl;
    cout << "Thank you for playing.  Exiting..." << endl;
    exit(0);
}

//--------------------------------------------------------------------
// Input Check: check for special function key, and make sure user
// input a valid command length
bool inputCheck(char userInput){
    bool pass = true;
    // cheat code for testing
    if (userInput == '`'){
        p18 = 'R';
    }
    else if (userInput == 'X'){
        exitGame();
    }
    else if (userInput == '-'){
        resetBoard();
    }
    else if (userInput == '\n'){
        pass = false;
    }
    return pass;
}
//--------------------------------------------------------------------
// Create custom board
void createBoard(){
    char ignore;
    for (int i = 1; i <= 36; i++){
        // To fix problem during copy and paste
        if (i % 6 == 1){
            ignore = getchar();
        }
        char userInput = getchar();
        if (((userInput != '\n') && (isalpha(userInput))) || (userInput == '.')){
            writeP(i, userInput);
        }
        else{
            i-1;
        }
    }
    cout << endl << endl << endl << endl << endl << endl << endl << "Your new board has been successfully created!" << endl << endl;
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
    // Prevent user enter too many character
    if (!inputCheck(N)){
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
        if (readP(i) == C){
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
                moveH(C, D, N);
            }
            cout << endl << endl;
        }
        else if (D == 'U' || D == 'D'){
            for (int i=N;i>0;i--){
                moveV(C, D, N);
            }
            cout << endl << endl;
        }
        else{
            cout << "invalid command (D)" << endl << endl;
        }
    }
} // end controlUnit()

//--------------------------------------------------------------------
// win the game
void winGame(){
    cout << "*** Congratulations, you did it! ***" << endl;
    cout << "You may now create you own game!!" << endl << endl;
    createBoard();
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
    //displayBoard();    // you must fill in that function for this to work
    
    // 
    while (!endGame){
        displayBoard();
        controlUnit();
        if (p18 == 'R'){
            winGame();
        }
    }
    
    return 0;
}//end main()



