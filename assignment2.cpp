/******************************************************
** Program Filename: assignment2.cpp
** Author: Yash Sankanagouda
** Date: Jan. 30, 2021
** Description: TwentyOne
** Input: Player's Decisions
** Output: Card outcome and player wallet
******************************************************/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

/******************************************************
** Function: InvalidPlayers
** Description: Prints out invalid players if there are invalid number of players
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int InvalidPlayers(){
    cout << "Invalid number of players!" << endl;
    return 0;
}

/******************************************************
** Function: GameOver
** Description: Prints game over when everyone is out of money
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int GameOver(){
    cout << "Game Over!" << endl;
    return 0;
}


/******************************************************
** Function: main
** Description: Runs TwentyOne
** Parameters: Checks how many players, their score and whether they win or not
** Pre-conditions: n/a
** Post-conditions: Return score to player after drawing card
******************************************************/

int main(){

    srand(time(NULL));

    int num_players = 0;
    int amount_money_one = 0;
    int amount_money_two = 0;
    int amount_money_three = 0;
    int amount_money_four = 0;
    int money_bet_one = 0;
    int money_bet_two = 0;
    int money_bet_three = 0;
    int money_bet_four = 0;
    int y_or_n = 1;
    int score_one = 0;
    int score_two = 0;
    int score_three = 0;
    int score_four = 0;
    int running_total_one = 0;
    int running_total_two = 0;
    int running_total_three = 0;
    int running_total_four = 0;
    int dealer_score = 0;
    int dealer_runningtotal = 0;
    int dealer_yn = 0;
    int restart = 1;
    int gameplayed = 0;
    int validplayers = 0;

    //Ensures there are a valid number of players.
    while (num_players <= 0 or num_players > 4){
        cout << "How many players do you have (1-4)? ";
        cin >> num_players; 
        if(num_players <= 0 or num_players > 4){
            cout << InvalidPlayers() << endl;
        }
    }
    int playerindex = 1;
    //Getting starting money for each player.
    while(playerindex < (num_players + 1)){
        cout << "Player "<< playerindex << ", how much money are you starting with? ";
        if(playerindex == 1){
            cin >> amount_money_one;
            //Ensures there is a valid amount of money.
            while (amount_money_one <= 0){
                cout << "Invalid money!" << endl;
                cout << "Player "<< playerindex << ", how much money are you starting with? ";
                cin >> amount_money_one;             
            }          
        }
        if(playerindex == 2){
            cin >> amount_money_two;
            //Ensures there is a valid amount of money.
            while (amount_money_two <= 0){
                cout << "Invalid money!" << endl;
                cout << "Player "<< playerindex << ", how much money are you starting with? ";
                cin >> amount_money_two;             
            } 
        }
        if(playerindex == 3){
            cin >> amount_money_three;
            //Ensures there is a valid amount of money.
            while (amount_money_three <= 0){
                cout << "Invalid money!" << endl;
                cout << "Player "<< playerindex << ", how much money are you starting with? ";
                cin >> amount_money_three;             
            } 
        }
        if(playerindex == 4){
            cin >> amount_money_four;
            //Ensures there is a valid amount of money.
            while (amount_money_four <= 0){
                cout << "Invalid money!" << endl;
                cout << "Player "<< playerindex << ", how much money are you starting with? ";
                cin >> amount_money_four;             
            } 
        }
        playerindex = playerindex + 1;
    }

    //The game restarts and ensures the running total and scores are reset.
    while(restart == 1){ 
        playerindex = 1;
        //Checks to see if all the players have valid money, if not game over.
        if(num_players > 0){
            if(num_players == 1 and amount_money_one <= 0){
                cout << "Players do not have sufficient money, " << GameOver() << endl; 
                break;
            }
            else if(num_players == 2 and amount_money_one <= 0 and amount_money_two <= 0){
                cout << "Players do not have sufficient money, " << GameOver() << endl; 
                break;
            }
            else if(num_players == 3 and amount_money_one <= 0 and amount_money_two <= 0 and amount_money_three <= 0){
                cout << "Players do not have sufficient money, " << GameOver() << endl; 
                break;
            }
            else if(num_players == 4 and amount_money_one <= 0 and amount_money_two <= 0 and amount_money_three <= 0 and amount_money_four <=0){
                cout << "Players do not have sufficient money, " << GameOver() << endl; 
                break;
            }
        }
        //Game starts here.
        while(playerindex < (num_players + 1)){
            int playerskip = 0;
            if(playerindex == 1){
                running_total_one = 0;
                score_one = 0;
                if(amount_money_one <= 0){
                    cout << "Player " << playerindex << " is skipped..." << endl;
                    playerskip = 1;
                }
            }
            if(playerindex == 2){
                running_total_two = 0;
                score_two = 0;
                if(amount_money_two <= 0){
                    cout << "Player " << playerindex << " is skipped..." << endl;
                    playerskip = 1;
                }
            }
            if(playerindex == 3){
                running_total_three = 0;
                score_three = 0;
                if(amount_money_three <= 0){
                    cout << "Player " << playerindex << " is skipped..." << endl;
                    playerskip = 1;
                }
            }
            if(playerindex == 4){
                running_total_four = 0;
                score_four = 0;
                if(amount_money_four <= 0){
                    cout << "Player " << playerindex << " is skipped..." << endl;
                    playerskip = 1;
                }
            }
            //Valid player
            if(playerskip == 0){           
                dealer_runningtotal = 0;
                dealer_score = 0;
                int betvalid = 0;
                //this block ensures that the player doesn't eneter the wrong bet value.
                while(betvalid == 0){        
                    cout << "Player " << playerindex << " how much do you bet you can beat the dealer: ";
                    if(playerindex == 1){
                        cin >> money_bet_one;
                        if(money_bet_one < 0 ){
                            cout << "Invalid bet!" << endl;
                            betvalid = 0;
                        }
                        else if(money_bet_one > amount_money_one ){
                            cout << "You don't have enough money to bet." << endl;
                            betvalid = 0;                
                        }
                        else{
                            betvalid = 1;
                        }           
                    }
                    if(playerindex == 2){
                        cin >> money_bet_two;
                        if(money_bet_two < 0 ){
                            cout << "Invalid bet!" << endl;
                            betvalid = 0;
                        }
                        else if(money_bet_two > amount_money_two){
                            cout << "You don't have enough money to bet." << endl;
                            betvalid = 0;               
                        }
                        else{
                            betvalid = 1;
                        }           
                    }          
                    if(playerindex == 3){
                        cin >> money_bet_three;
                        if(money_bet_three < 0 ){
                            cout << "Invalid bet!" << endl;
                            betvalid = 0;
                        }
                        else if(money_bet_three > amount_money_three){
                            cout << "You don't have enough money to bet." << endl;
                            betvalid = 0;
                        }
                        else{
                            betvalid = 1;
                        }
                    }
                    if(playerindex == 4){
                        cin >> money_bet_four;
                        if(money_bet_four < 0 ){
                            cout << "Invalid bet!" << endl;
                            betvalid = 0;
                        }
                        else if(money_bet_four > amount_money_four){
                            cout << "You don't have enough money to bet." << endl;
                            betvalid = 0;
                        }
                        else{
                            betvalid = 1;
                        }
                    }
                }
                //Assigning random values to players.
                if(playerindex == 1){
                    running_total_one = rand()% 11 + 1;
                    score_one = running_total_one + score_one;
                    cout << "You got " << running_total_one << ". Your running total is " << score_one << ". Do you want another number? (1-yes 0-no)" << endl;
                    cin >> y_or_n;
                }
                if(playerindex == 2){
                    running_total_two = rand()% 11 + 1;
                    score_two = running_total_two + score_two;
                    cout << "You got " << running_total_two << ". Your running total is " << score_two << ". Do you want another number? (1-yes 0-no)" << endl;
                    cin >> y_or_n;
                }
                if(playerindex == 3){            
                    running_total_three = rand()% 11 + 1;
                    score_three = running_total_three + score_three;
                    cout << "You got " << running_total_three << ". Your running total is " << score_three << ". Do you want another number? (1-yes 0-no)" << endl;
                    cin >> y_or_n;
                }
                if(playerindex == 4){            
                    running_total_four = rand()% 11 + 1;
                    score_four = running_total_four + score_four;
                    cout << "You got " << running_total_four << ". Your running total is " << score_four << ". Do you want another number? (1-yes 0-no)" << endl;
                    cin >> y_or_n;
                }

                dealer_yn = 1;
                //Determine if players want to draw a card or not.
                while(y_or_n == 1){
                    if(playerindex == 1){
                        running_total_one = rand()% 11 + 1;
                        score_one = running_total_one + score_one;
                        cout << "You got " << running_total_one << ". Your running total is " << score_one << ". Do you want another number? (1-yes 0-no)" << endl;
                        if(score_one > 21){
                            cout << "You bust!" << endl;
                            amount_money_one = amount_money_one - money_bet_one;
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_one << endl;
                            break;                              
                        }
                        else if(score_one ==  21){
                            cout << "You won!" << endl;
                            cout << "Player" << playerindex << " total points are " << score_one << endl;
                            amount_money_one = amount_money_one + money_bet_one;
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_one << endl;
                            break;
                        }
                        cin >> y_or_n;
                    }
                    if(playerindex == 2){
                        running_total_two = rand()% 11 + 1;
                        score_two = running_total_two + score_two;
                        cout << "You got " << running_total_two << ". Your running total is " << score_two << ". Do you want another number? (1-yes 0-no)" << endl;
                        if(score_two > 21){
                            cout << "You bust!" << endl;
                            amount_money_two = amount_money_two - money_bet_two;  
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_two << endl;
                            break;
                        }
                        else if(score_two ==  21){
                            cout << "You won!" << endl;
                            cout << "Player" << playerindex << " total points are " << score_two << endl;
                            amount_money_two = amount_money_two + money_bet_two;
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_two << endl;
                            break;                
                        }
                        cin >> y_or_n;
                    }
                    if(playerindex == 3){
                        running_total_three = rand()% 11 + 1;
                        score_three = running_total_three + score_three;
                        cout << "You got " << running_total_three << ". Your running total is " << score_three << ". Do you want another number? (1-yes 0-no)" << endl;
                        if(score_three > 21){
                            cout << "You bust!" << endl;
                            amount_money_three = amount_money_three - money_bet_three;  
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_three << endl;
                            break;
                        }
                        else if(score_three ==  21){
                            cout << "You won!" << endl;
                            cout << "Player" << playerindex << " total points are " << score_three << endl;
                            amount_money_three = amount_money_three + money_bet_three;
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_three << endl;
                            break;           
                        }
                        cin >> y_or_n;
                    }
                    if(playerindex == 4){
                        running_total_four = rand()% 11 + 1;
                        score_four = running_total_four + score_four;
                        cout << "You got " << running_total_four << ". Your running total is " << score_four << ". Do you want another number? (1-yes 0-no)" << endl;
                        if(score_four > 21){
                            cout << "You bust!" << endl;
                            amount_money_four = amount_money_four - money_bet_four;  
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_four << endl;
                            break;
                        }
                        else if(score_four ==  21){
                            cout << "You won!" << endl;
                            cout << "Player" << playerindex << " total points are " << score_four << endl;
                            amount_money_four = amount_money_four + money_bet_four;
                            dealer_yn = 0;
                            cout << "Player " << playerindex << " total money is " << amount_money_four << endl;
                            break;         
                        }
                        cin >> y_or_n;
                    }
                }
    
                //Player VS Dealer//
                dealer_score = 0;
                dealer_runningtotal = 0;
                //Execute dealers turn, under conditions.
                while(dealer_yn == 1){
                    cout << "Dealer's turn..." << endl;
                    dealer_runningtotal = rand()% 11 + 1;
                    dealer_score = dealer_runningtotal + dealer_score;
                    cout << "You got " << dealer_runningtotal << ". Your running total is " << dealer_score << endl;
                    if(dealer_score > 21){
                        //Dealer lost, adjusting players money.
                        cout << "Dealer bust!" << endl;
                        if(playerindex == 1){
                            amount_money_one = amount_money_one + money_bet_one;
                            cout << "Your total points are " << amount_money_one << endl;
                        }
                        if(playerindex == 2){
                            amount_money_two = amount_money_two + money_bet_two;
                            cout << "Your total points are " << amount_money_two << endl;
                            
                        }
                        if(playerindex == 3){
                            amount_money_three = amount_money_three + money_bet_three;
                            cout << "Your total points are " << amount_money_three << endl;
                        }
                        if(playerindex == 4){
                            amount_money_four = amount_money_four + money_bet_four;
                            cout << "Your total points are " << amount_money_four << endl;
                        }
                        //Stops dealer from drawing cards.
                        dealer_yn = 0;
                        break;
                    }
                    else if(dealer_score ==  21){
                        //Dealer won, adjust players money.
                        cout << "You lost!" << endl;
                        if(playerindex == 1){
                            amount_money_one = amount_money_one - money_bet_one;
                            cout << "Your total points are " << amount_money_one << endl;
                        }
                        if(playerindex == 2){
                            amount_money_two = amount_money_two - money_bet_two;
                            cout << "Your total points are " << amount_money_two << endl;
                        }
                        if(playerindex == 3){
                            amount_money_three = amount_money_three - money_bet_three;
                            cout << "Your total points are " << amount_money_three << endl;
                        }
                        if(playerindex == 4){
                            amount_money_four = amount_money_four - money_bet_four;
                            cout << "Your total points are " << amount_money_four << endl;
                        }
                        dealer_yn = 0;
                        break;
                    }
                    else{
                        //Checking if player ties with the dealer.
                        if(playerindex == 1){
                            if(dealer_score == score_one){
                                cout << "Tie Game!" << endl;
                                cout << "Player " << playerindex << " total points are " << score_one << endl;
                            }
                        }
                        if(playerindex == 2){
                            if(dealer_score == score_two){
                                cout << "Tie Game!" << endl;
                                cout << "Player " << playerindex << " total points are " << score_two << endl;
                            }
                        }
                        if(playerindex == 3){
                            if(dealer_score == score_three){
                                cout << "Tie Game!" << endl;
                                cout << "Player " << playerindex << " total points are " << score_three << endl;
                            }
                        }
                        if(playerindex == 4){
                            if(dealer_score == score_four){
                                cout << "Tie Game!" << endl;
                                cout << "Player " << playerindex << " total points are " << score_four << endl;
                            }
                        }
                    }

                    //Dealer decides whether to draw card or not.
                    dealer_yn = rand() % 2;  

                    if(dealer_yn == 0){
                        if(playerindex == 1){
                            if(dealer_score > score_one){
                                cout << "You lost!" << endl;
                                amount_money_one = amount_money_one - money_bet_one;
                                cout << "Your total points are " << amount_money_one << endl;
                            }
                            else{
                                cout << "You won!" << endl;
                                amount_money_one = amount_money_one + money_bet_one;
                                cout << "Your total points are " << amount_money_one << endl;
                            }
                        }
                        if(playerindex == 2){
                            if(dealer_score > score_two){
                                cout << "You lost!" << endl;
                                amount_money_two = amount_money_two - money_bet_two;
                                cout << "Your total points are " << amount_money_two << endl;
                            }
                            else{
                                cout << "You won!" << endl;
                                amount_money_two = amount_money_two + money_bet_two;
                                cout << "Your total points are " << amount_money_two << endl;
                            }
                        }
                        if(playerindex == 3){
                            if(dealer_score > score_three){
                                cout << "You lost!" << endl;
                                amount_money_three = amount_money_three - money_bet_three;
                                cout << "Your total points are " << amount_money_three << endl;
                            }
                            else{
                                cout << "You won!" << endl;
                                amount_money_three = amount_money_three + money_bet_three;
                                cout << "Your total points are " << amount_money_three << endl;
                            }
                        }
                        if(playerindex == 4){
                            if(dealer_score > score_four){
                                cout << "You lost!" << endl;
                                amount_money_four = amount_money_four - money_bet_four;
                                cout << "Your total points are " << amount_money_four << endl;
                            }
                            else{
                                cout << "You won!" << endl;
                                amount_money_four = amount_money_four + money_bet_four;
                                cout << "Your total points are " << amount_money_four << endl;
                            }
                        }
                        break;
                    }  
                }
            }
            //Go to the next player.
            playerindex = playerindex + 1;
        }
        cout << "Do you want to play again (0-no or 1-yes)?" << endl;
        cin >> restart;
    }
    return 0;
}

