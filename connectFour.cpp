/******************************************************
** Program Filename: assignment5.cpp
** Author: Yash Sankanagouda
** Date: March 14, 2021
** Description: Connect four
** Input: Game piece
** Output: The game board with the pieces placed
******************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

/******************************************************
** Function: init_board
** Description: Initialize the board
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void init_board(char **board, int rows, int cols){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            board[i][j] = ' ';
        }
    }
}

/******************************************************
** Function: delete_board
** Description: Free the memory after running the program
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void delete_board (char **board, int rows, int cols, int *drop_col, int *drop_row){

    for (int i = 0; i < rows; i++){
        delete [] board[i];
    }
    delete [] board;
    board = 0;

    delete [] drop_col;
    delete [] drop_row;
}

/******************************************************
** Function: draw_board
** Description: Draw the board with the correct colors
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void draw_board(char **board, int rows, int cols){
    
    for (int i = 1; i <= cols; i++){
        if (i < 10){
            cout << " " << i << "  ";
        }
        else{
            cout << i << "  ";
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i % 2 == 0 && j % 2 == 0){
                cout << "|\033[30;47m " << board[i][j] << " ";
            }
            else if (i % 2 == 1 && j % 2 == 1){
                cout << "|\033[30;47m " << board[i][j] << " ";
            }
            else{
                cout << "|\033[0m " << board[i][j] << " ";
                cout << "\033[0m";
            }
        }
        cout << endl;
    }
    cout << "\033[0m";
}

/******************************************************
** Function: get_who_goes_next
** Description: Determine which player goes next
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_who_goes_next(bool player_one, bool player_two, bool cpu){
//This function is over 20 lines. This function is focused on deciding who goes first and it cannot be broken down any further. 
//This function is 26 lines long. 


    if(player_one == false && player_two == false){
        //player_one = true;
        if(cpu){
            int go_first = 0;
            cout << "Player 1, do you want to go first? (1-yes 0-no)" << endl;
            cin >> go_first;
            while(cin.fail() == 1 || (cin.fail() == 0 && (go_first < 0 || go_first > 1))){
                cout << "Invalid choice! Re-enter: ";
                go_first = 0;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> go_first;
            }
            if(go_first == 1){
                player_one = true;
            }
            else{
                player_two = true;
            }
        }
        if(!cpu){
            player_one = true;
        }
    }
    else if(player_one == true && player_two == false){
        player_one = false;
        player_two = true;
    }
    else if(player_one == false && player_two == true){
        player_one = true;
        player_two = false;
    }
    if(player_one == true){
        return 1;
    }
    else if(player_two == true){
        return 2;
    }
    return -1;
}

/******************************************************
** Function: check_horizontal
** Description: Check horizontally to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_horizontal(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < cols; i++){
        if(board[drop_row][i] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << "Horizontal Match found!" << endl;
            return true;
        }
    }
    return false;
}

/******************************************************
** Function: check_vertical
** Description: Check vertically to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_vertical(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < rows; i++){
        if(board[i][drop_col] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << "Vertical Match found!" << endl;
            return true;
        }
    }
    return false;
}

/******************************************************
** Function: check_diagonal_up_left
** Description: Check diagonal up left to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_diagonal_up_left(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < 4; i++){
        if(board[drop_row - i][drop_col - i] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << " Up left diagonal match found!" << endl;
            return true;
        }
        if(drop_row - i - 1 < 0){
            break;
        }
        else if(drop_col - i - 1 < 0){
            break;
        }
    }
    return false;
}

/******************************************************
** Function: check_diagonal_down_left
** Description: Check diagonal down left to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_diagonal_down_left(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < 4; i++){
        if(board[drop_row + i][drop_col - i] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << " down left diagonal match found!" << endl;
            return true;
        }
        if(drop_row + i + 1 > rows - 1){
            break;
        }
        else if(drop_col - i - 1 < 0){
            break;
        }
    }
    return false;
}

/******************************************************
** Function: check_diagonal_up_right
** Description: Check diagonal up right to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_diagonal_up_right(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < 4; i++){
        if(board[drop_row - i][drop_col + i] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << " Up right diagonal match found!" << endl;
            return true;
        }
        if(drop_row - i - 1 < 0){
            break;
        }
        else if(drop_col + i + 1 > cols){
            break;
        }
    }
    return false;
}

/******************************************************
** Function: check_diagonal_down_right
** Description: Check diagonal down right to see if there is a match
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_diagonal_down_right(char **board, int cols, int rows, int drop_col, int drop_row){

    char dropchar = board[drop_row][drop_col];
    int match = 0;

    for (int i = 0; i < 4; i++){
        if(board[drop_row + i][drop_col + i] == dropchar){
            match++;
        }
        else{
            match = 0;
        }
        if(match >= 4){
            cout << " down right diagonal match found!" << endl;
            return true;
        }
        if(drop_row + i + 1 > rows - 1){
            break;
        }
        else if(drop_col + i + 1 > cols - 1){
            break;
        }
    }
    return false;
}

/******************************************************
** Function: check_drop_location
** Description: Checks to see if the drop location is valid
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_drop_location(int drop_row, int drop_col){

    if(drop_row < 0){
        return false;
    }
    else{
        return true;
    }
}

/******************************************************
** Function: empty_slots
** Description: Checks for empty slots on the board
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int empty_slots(char **board, int rows, int cols){

    int count = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(board[i][j] == ' '){
                count++;
            }
        }
    }
    return count;
}

/******************************************************
** Function: get_input_col
** Description: Gets the input from the players/cpu
** Parameters: n/a
** Pre-conditions: To see how many players are playing
** Post-conditions: n/a
******************************************************/

int get_input_col(bool player_one, bool player_two, bool cpu, int cols){
    int drop_col = 0;
    if(player_one == true){
        cout << "Player one, pick a column: ";
        cin >> drop_col;  
    }
    else if(player_two == true ){
        if(!cpu){
            cout << "Player two, pick a column: ";
            cin >> drop_col; 
            
        }
        if(cpu){
            cout << "Cpu's turn...." << endl;
            drop_col = rand() % cols + 1;
            cout << "Cpu droped in column " << drop_col << endl;
        }
    }
    while(cin.fail() == 1 || (cin.fail() == 0 && (drop_col < 0 || drop_col > cols))){
        cout << "Invalid column! Re-enter: ";
        drop_col = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> drop_col;
    }
    return drop_col;
}

/******************************************************
** Function: get_user_input_for_players
** Description: Replaces the empty slot with the correct game piece
** Parameters: n/a
** Pre-conditions: To see how many players are playing
** Post-conditions: n/a
******************************************************/

void get_user_input_for_players(bool player_one, bool player_two, char **board, int cols, int rows, bool cpu, int *d_row, int *d_col){

    int drop_row = -1;
    int drop_col = get_input_col(player_one, player_two, cpu, cols);

    drop_col = drop_col - 1;
    for(int i = rows - 1; i >= 0; i--){
        char tempchar = board[i][drop_col];
        if(tempchar == ' '){
            drop_row = i;
            break;
        }
    }
    if(drop_row >= 0){
        if(player_one == true){
            board[drop_row][drop_col] = 'X';
        }
        else if(player_two == true){
            board[drop_row][drop_col] = 'O';
        }
    }
    *d_row = drop_row;
    *d_col = drop_col;
}

/******************************************************
** Function: check_win
** Description: Checks to see if there is a match found in order to determine a winner
** Parameters: n/a
** Pre-conditions: To see how many players are playing
** Post-conditions: n/a
******************************************************/

bool check_win(char **board, int cols, int rows, int drop_row, int drop_col){

    bool ch = check_horizontal(board, cols, rows, drop_col, drop_row);
    bool cv = check_vertical(board, cols, rows, drop_col, drop_row);
    bool dul = check_diagonal_up_left(board, cols, rows, drop_col, drop_row);
    bool dur = check_diagonal_up_right(board, cols, rows, drop_col, drop_row);
    bool ddr = check_diagonal_down_right(board, cols, rows, drop_col, drop_row);
    bool ddl = check_diagonal_down_left(board, cols, rows, drop_col, drop_row);

    if(ch || cv || dul || dur || ddr || ddl){
        return true;
    }
    return false;
}

/******************************************************
** Function: get_players
** Description: Gets the number of players in the command line arguement
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_players(int argc, char *argv[], bool valid_inputs){
    int players = 0;
    if(valid_inputs){
        for(int i = 0; i < argc; ++i){
            if (i == 1){
                players = atoi(argv[i]);
                while (players < 0 || players > 2){
                    cout << "Invalid number of players! Enter again: " << endl;
                    cin >> players;
                }
                return players;
            }
        }
    }
    else{
        cout << "Enter number of players: " << endl;
        cin >> players;
        while (players < 0 || players > 2){
            cout << "Invalid number of players! Enter again: " << endl;
            cin >> players;
        }
        return players;
    }
    return 0;
}

/******************************************************
** Function: get_rows
** Description: Gets the number of rows in the command line arguement
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_rows(int argc, char *argv[], bool valid_inputs){
    int rows = 0;
    if(valid_inputs){
        for(int i = 0; i < argc; ++i){
            if (i == 2){
                rows = atoi(argv[i]);
                while (rows < 4 || rows > 20){
                    cout << "Invalid number of rows! Enter again: " << endl;
                    cin >> rows;
                }
                return rows;
            }
        }
    }    
    else{
        cout << "Enter number of rows: " << endl;
        cin >> rows;
        while (rows < 4 || rows > 20){
            cout << "Invalid number of rows! Enter again: " << endl;
            cin >> rows;
        }
        return rows;
    }
    return 0;
}

/******************************************************
** Function: get_cols
** Description: Gets the number of columns in the command line arguement
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_cols(int argc, char *argv[], bool valid_inputs){
    int cols = 0;
    if(valid_inputs){
        for(int i = 0; i < argc; ++i){
            if (i == 3){
                cols = atoi(argv[i]);
                while (cols < 4 || cols > 20){
                    cout << "Invalid number of cols! Enter again: " << endl;
                    cin >> cols;
                }
                return cols;
            }
        }
    }
    else{
        cout << "Enter number of columns: " << endl;
        cin >> cols;
        while (cols < 4 || cols > 20){
            cout << "Invalid number of cols! Enter again: " << endl;
            cin >> cols;
        }
        return cols;
    }
    return 0;
}

/******************************************************
** Function: display_winner
** Description: To display the name of the winner
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool display_winner(bool player_one, bool player_two, bool cpu){
    if (player_one){
        cout << "Player 1 is the winner!" << endl;
    }
    else if (player_two){
        if(!cpu){
            cout << "Player 2 is the winner!" << endl;                   
        }
        else{
            cout << "CPU is the winner!" << endl;
        }
    }
    bool play = false;
    cout << "Do you want to play again? (1-yes 0-no)" << endl;
    cin >> play;
    while(cin.fail() == 1 || (cin.fail() == 0 && (play < 0 || play > 1))){
        cout << "Invalid option! Re-enter: ";
        play = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> play;
    }

    return play;
}

/******************************************************
** Function: display_boardfull
** Description: To prompt users if they would like to restart when the game is a tie
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool display_boardfull(){
    bool play = false;
    cout << "All slots are full! Tie Game!" << endl;
    cout << "Do you want to play again? (1-yes 0-no)" << endl;
    cin >> play;
    
    return play;
}

/******************************************************
** Function: initialize
** Description: Combine two functions in order to make the main smaller. Initialize the board
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void initialize(char **board, int rows, int cols){
    init_board(board, rows, cols);
    draw_board(board, rows, cols);
}

/******************************************************
** Function: check_arguments
** Description: Check to see if the number of arguments is valid
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool check_arguments(int argc){
    
    if(argc != 4){
        cout << "Invalid set of arguments!" << endl;
        return false;
    }
    return true;
}


/******************************************************
** Function: main
** Description: To place all the functions together and execute the program
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(int argc, char *argv[]){ 
//This function is over 20 lines. The relavent functions have already been created. This function, mainly ensures the game flow. I wasn't able to find the oppurtunity to break this function any further.
//To make it under 20 lines. 

    int rows = 0;
    int cols = 0;
    int players = 0;
    int restart = 0;
    int *drop_row = (int*) malloc(sizeof(int));
    int *drop_col = (int*) malloc(sizeof(int));
    bool player_one = false;
    bool player_two = false;
    bool cpu = false;
    bool play = true;
    bool reset = false;
    char **board;

    bool valid_inputs = check_arguments(argc); 
    players = get_players(argc, argv, valid_inputs);
    rows = get_rows(argc, argv, valid_inputs);
    cols = get_cols(argc, argv, valid_inputs);
   
    board = new char* [rows];
    for (int i = 0 ;i < rows; ++i){
        board[i] = new char [cols];
    }

    if (players == 1){
        cpu = true;
    }

    initialize(board, rows, cols);
    
    while(play){
        int i = get_who_goes_next(player_one, player_two, cpu);
        if(i == 1){
            player_one = true;
            player_two = false;
        }
        if(i == 2){
            player_one = false;
            player_two = true;
        }
        int empty_spaces = empty_slots(board, rows, cols);
        if(empty_spaces > 0){
            bool valid = false;
            while(!valid){
                get_user_input_for_players(player_one, player_two, board, cols, rows, cpu, drop_row, drop_col);
                valid = check_drop_location(*drop_row, *drop_col);
                if(!valid){
                    cout << "The column is full!" << endl;
                }
            }
            if(valid){
                bool win = check_win(board, cols, rows, *drop_row, *drop_col);
                draw_board(board, rows, cols);
                if (win){
                    play = display_winner(player_one, player_two, cpu);
                    if(play){
                        reset = true;
                    }
                    else{
                        reset = false;
                        play = false;
                    }
                }
            }
        }
        else{
            play = display_boardfull();
            reset = true;
            if(play){
                reset = true;
            }
            else{
                reset = false;
                play = false;
            }
        }
        if(reset){
            initialize(board, rows, cols);
            player_one = false;
            player_two = false;
            play = true;
            reset = false;
        }
    }
    
    delete_board (board, rows, cols , drop_col, drop_row);

    return 0;
}
