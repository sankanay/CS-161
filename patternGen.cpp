/******************************************************
** Program Filename: assignment4v2.cpp
** Author: Yash Sankanagouda
** Date: Feb. 27, 2021
** Description: Display a pattern of stars
** Input: Number of stars and column to be shifted
** Output: Pattern of the stars
******************************************************/

#include <iostream>
using namespace std;

/******************************************************
** Function: pattern
** Description: generates the pattern
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void pattern(int n, int col){
        
    if(n > 0){
        pattern(n-2, col+1);
        for(int i = 0; i < col; i++){
            cout << "  ";
        }
        for(int i = 0; i < n; i++){
            cout << "* ";
        }
        cout << endl;
        pattern(n-2, col+1);
    }
}

/******************************************************
** Function: main
** Description: Prompts the user with the number of stars and the column
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){

    int n;
    int col;

    cout << "Enter number of stars: ";
    cin >> n;

    cout << "Enter column: ";
    cin >> col;

    cout << endl;

    pattern(n, col);


    return 0;
}
