/*
AUTHOR: ZACHARY WOLFE
DATE: 9/30/2022
PURPOSE: 
CREATE A TICTACTOE GAME THAT ALLOWS THE USER TO SELECT WHICH POSITION THEY WANT ON THE BOARD.
SWAP BETWEEN PLAYER 1 AND PLAYER 2 TO LET THEM PLAY AGAINST EACHOTHER, WINNER WILL BE PRINTED.
PRINT WHERE THE USER SELECTED ONTO THE NEW BOARD ALONG WITH THE OLD SELECTIONS.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

//FUNCTIONS USED.
bool redflag(vector< vector <string> > a, bool b, int input);
int winner(vector< vector <string> > a, bool b);
int printboard(vector< vector<string> > a);
bool tie(vector<string> a, vector< vector<string>> b);

//GLOBAL VARIABLE FOR SUMMING FUNCTION TO TIE.
int sum = 0;

//STRINGS TO PRINT.
string print = "\nTIC-TAC-TOE\n";
int main()
{
    //PRINT WELCOME TO TIC-TAC-TOE.
    cout << print << endl;

    // VARIABLES && DECLARATIONS.
    int sum = 0;
    int selection;
    bool contains_element;
    bool player1 = true;
    int win;
    vector<string> tievector;
    vector<vector<string>> board = {{"1","2","3"},
                                    {"4","5","6"},
                                    {"7","8","9"}};
                                    
    //PRINT FIRST ITERATION OF THE BOARD.
    printboard(board);
    cout << endl;
    do
    {   
        while (player1)
            {                
                if (win == 1 || win == 2)
                    {
                        if (win == 1)
                        {
                            cout << "The game has been won by Player1. \"X\" \n" << endl;
                            exit(1);
                        }
                        else
                        {
                            cout << "The game has been won by Player2. \"O\" \n" << endl;
                            exit(1);
                        }                        
                        
                    }
                    else
                        {
                            cout << "\nPlayer1, enter your selection on the board: ";
                            cin >> selection;
                            if (redflag(board, contains_element, selection))
                                {
                                    cout << "False input, please enter another value. ";
                                    continue;
                                }
                            if (tie(tievector, board))
                            {
                                cout << "TIE" << endl;
                                exit(1);
                            }
                                else
                                {
                                    string x = "X";
                                    switch (selection)
                                    {
                                    case 1:
                                        board[0][0] = x;
                                        printboard(board);          
                                        break;
                                    case 2:
                                        board[0][1] = x;    
                                        printboard(board);      
                                        break;
                                    case 3:
                                        board[0][2] = x;          
                                        printboard(board); 
                                        break;
                                    case 4:
                                        board[1][0] = x;            
                                        printboard(board);
                                        break;
                                    case 5:
                                        board[1][1] = x; 
                                        printboard(board);           
                                        break;
                                    case 6:
                                        board[1][2] = x;            
                                        printboard(board);
                                        break;
                                    case 7: 
                                        board[2][0] = x;
                                        printboard(board);           
                                        break;
                                    case 8:
                                        board[2][1] = x; 
                                        printboard(board);          
                                        break;
                                    case 9:          
                                        board[2][2] = x; 
                                        printboard(board);  
                                        break;                                                              
                                    default:
                                        break;
                                    }
                                    win = winner(board, win); 
                                    tievector.push_back(to_string(selection)); 
                                    player1 = false;
                                }
                    }    
            }
        while (!player1)
            {
                if (win == 1 || win == 2)
                    {
                        if (win == 1)
                        {
                            cout << "The game has been won by Player1. \"X\" \n" << endl;
                            exit(1);
                        }
                        else
                        {
                            cout << "The game has been won by Player2. \"O\" \n" << endl;
                            exit(1);
                        }                        
                        
                    }
                    else
                        { 
                            cout << "\nPlayer2, enter your selection on the board: ";
                            cin >> selection;
                            string o = "O";
                            if (redflag(board, contains_element, selection))
                                {
                                    cout << "False input, please enter another value. ";
                                    continue;
                                }
                            if (tie(tievector, board))
                            {
                                cout << "TIE" << endl;
                                exit(1);
                            }              
                                else
                                {
                                    switch (selection)
                                    {
                                        case 1:
                                            board[0][0] = o;
                                            printboard(board);          
                                            break;
                                        case 2:
                                            board[0][1] = o;
                                            printboard(board);            
                                            break;
                                        case 3:
                                            board[0][2] = o;
                                            printboard(board);            
                                            break;
                                        case 4:
                                            board[1][0] = o;
                                            printboard(board);            
                                            break;
                                        case 5:
                                            board[1][1] = o;
                                            printboard(board);            
                                            break;
                                        case 6:
                                            board[1][2] = o;
                                            printboard(board);            
                                            break;
                                        case 7:
                                            board[2][0] = o;
                                            printboard(board);            
                                            break;
                                        case 8:
                                            board[2][1] = o;
                                            printboard(board);            
                                            break;
                                        case 9:
                                            board[2][2] = o;
                                            printboard(board);            
                                            break;
                                        default:
                                            break;
                                    }
                                    win = winner(board, win);
                                    tievector.push_back(to_string(selection));   
                                    player1 = true;    
                                }                                             
                    }
            }     
    } while (true);  
    return 0;
}
bool redflag(vector<vector<string>> a, bool b, int input)
{   
    string value;
    switch (input)
    {
    case 1:
        value = a[0][0];
        return value == "X" || value == "O";        
        break;
    case 2:
        value = a[0][1];
        return value == "X" || value == "O";     
        break;
    case 3:
        value = a[0][2];
        return value == "X" || value == "O";           
        break;
    case 4:
        value = a[1][0]; 
        return value == "X" || value == "O";            
        break;
    case 5:
        value = a[1][1];
        return value == "X" || value == "O";  
        break;
    case 6:
        value = a[1][2];
        return value == "X" || value == "O";             
        break;
    case 7: 
        value = a[2][0];
        return value == "X" || value == "O"; 
        break;
    case 8:
        value = a[2][1]; 
        return value == "X" || value == "O"; 
        break;
    case 9:          
        value = a[2][2]; 
        return value == "X" || value == "O"; 
        break;                                                              
    default:
        return false;
        break;
    }
    return false;
}
int printboard(vector< vector<string> > a)
{
    for(auto row_obj : a)
    {
        for (auto elem: row_obj)
        {
            cout << elem << "   ";
        }
        cout << "\n" << endl;
    }
    return 0;
}
int winner(vector< vector <string>> a, bool b)
{
    //IF 3 IN A ROW FOR VECTOR ROWS == "X" || "O" THEN WINNER = TRUE.
    if (
        ((a[0][0] == "X") && (a[0][1] == "X") && (a[0][2] == "X")) 
        ||
        ((a[1][0] == "X") && (a[1][1] == "X") && (a[1][2] == "X"))  
        ||
        ((a[2][0] == "X") && (a[2][1] == "X") && (a[2][2] == "X"))
       )
        {
            return 1;
        }
    if (
        ((a[0][0] == "O") && (a[0][1] == "O") && (a[0][2] == "O")) 
        ||
        ((a[1][0] == "0") && (a[1][1] == "0") && (a[1][2] == "0"))
        ||
        ((a[2][0] == "O") && (a[2][1] == "O") && (a[2][2] == "O"))
        )
        {
            return 2;
        }
    
    //IF 3 IN A ROW FOR VECTOR COLUMNS == "X" || "O" THEN WINNER = TRUE.
    if (
        ((a[0][0] == "X") && (a[1][0] == "X") && (a[2][0] == "X"))
        || 
        ((a[0][1] == "X") && (a[1][1] == "X") && (a[2][1] == "X"))
        ||
        ((a[0][2] == "X") && (a[1][2] == "X") && (a[2][2] == "X"))
       )
        {
            return 1;
        }
    if (        
        ((a[0][0] == "O") && (a[1][0] == "O") && (a[2][0] == "O"))
        || 
        ((a[0][1] == "O") && (a[1][1] == "O") && (a[2][1] == "O"))
        ||
        ((a[0][2] == "O") && (a[1][2] == "O") && (a[2][2] == "O"))
        )
        {
            return 2;
        }
    
    //IF DIAGONALS 3 IN A ROW == "X" || "O" THEN WINNER = TRUE.
    if (
        ((a[0][0] == "X") && (a[1][1] == "X") && (a[2][2] == "X"))
        ||
        ((a[0][2] == "X") && (a[1][1] == "X") && (a[2][0] == "X"))
        )
        {
            return 1;
        }
    if (        
        ((a[0][0] == "O") && (a[1][1] == "O") && (a[2][2] == "O"))
        ||
        ((a[0][2] == "O") && (a[1][1] == "O") && (a[2][0] == "O"))
        )
        {
            return 2;
        }
    
    //IF NONE JUST RETURN FALSE BECAUSE THERE IS NO WINNING COMBINATIONS ON BOARD.
    return false;
}
bool tie(vector<string> a, vector< vector<string>> b)
{
    int sumadd = 0;
    //FOR THE SIZE OF THE 2D VECTOR, GO THROUGH THE ROWS AND COLUMS, THEN ADD THE SIZE OF THEM TO SUM.
    //IF THE LENGTH OF THE VECTOR == 81 (ALL POSSIBLE SUMS FOR COMBINATIONS ON BOARD HAVE BEEN USED), THEN THERE IS A TIE BECAUSE FUNCTION WIN RUNS WITH EACH ITERATION OF WHILE LOOP.
    for (int i = 0; i < b.size(); i++)
        {
            sumadd = b.at(i).size();
            sum = sum + sumadd;
        }
    if (sum == 81)
    {
        return true;
    }
    else
    {
        return false;
    }
}