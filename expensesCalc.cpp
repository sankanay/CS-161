/******************************************************
** Program Filename: assignment3.cpp
** Author: Yash Sankanagouda
** Date: Feb. 14, 2021
** Description: Calculate Expenses
** Input: Player's Spending
** Output: Total expense, total reimbursement, what left too pay
******************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;


int get_departure_time();
int get_arrival_time();
void get_travel_cost();
int vehicle();
void calculate_vehicle_fee();
string get_parking_fee_by_day(int);
string get_hotel_cost(int, char *);
string get_breakfast_fee_for_day(int, string);
string get_lunch_fee_for_day(int, string);
string get_dinner_fee_for_day(int, string);
double breakfast_cost_by_day(int, string);
double lunch_cost_by_day(int, string);
double dinner_cost_by_day(int, string);
bool is_valid_parking_cost(string);

/******************************************************
** Function: get_days_spent
** Description: Prints out days of the trip
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_days_spent(){
    int num_days = 0;
    cout << "Enter the number of days on your trip: ";
    cin >> num_days; 
    while(cin.fail() == 1 || (cin.fail() == 0 && num_days < 0)){
        cout << "Invalid input! Enter again: " << endl;
        num_days = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> num_days;
    }
    return (num_days);
}

/******************************************************
** Function: get_departure_time
** Description: Gets departure time
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_departure_time(){
    int depart_time = 0;
    cout << "Enter your departure time (just the hour on the first day in 24-hour format (i.e, 16 for 4pm): " << endl;
    cin >> depart_time;
    while(cin.fail() == 1 || (cin.fail() == 0 && (depart_time < 0 || depart_time > 24))){
        cout << "Invalid input! Enter again: " << endl;
        depart_time = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> depart_time;
    }
    return(depart_time);
}

/******************************************************
** Function: get_arrival_time
** Description: Gets arrival time
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int get_arrival_time(){
    int arrive_time = 0;
    cout << "Enter your arrival time (just the hour on the first day in 24-hour format (i.e, 16 for 4pm): " << endl;
    cin >> arrive_time;
    while(cin.fail() == 1 || (cin.fail() == 0 && (arrive_time < 0 || arrive_time > 24))){
        cout << "Invalid input! Enter again: " << endl;
        arrive_time = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> arrive_time;
    }
    return(arrive_time);
}

/******************************************************
** Function: get_airfare_cost
** Description: Gets airfare cost
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_airfare_cost(){
    double airfare_cost = 0;
    cout << "Enter total amount of airfare, in $: " << endl;
    cin >> airfare_cost;
    while(cin.fail() == 1 || (cin.fail() == 0 && airfare_cost < 0)){
        cout << "Invalid input! Enter again: " << endl;
        airfare_cost = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> airfare_cost;
    }
    return(airfare_cost);
}

/******************************************************
** Function: get_seminar_cost
** Description: Gets seminar cost
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_seminar_cost(){
    double seminar_cost = 0;
    cout << "Enter total conference or seminar fees, in $:" << endl;
    cin >> seminar_cost;
    while(cin.fail() == 1 || (cin.fail() == 0 && seminar_cost < 0)){
        cout << "Invalid input! Enter again: " << endl;
        seminar_cost = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> seminar_cost;
    }
    return(seminar_cost);
}

/******************************************************
** Function: vehicle
** Description: did user rent car or use taxi
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int vehicle(){
    int car_or_taxi = 0;
    cout << "Did you 1: rent a car or 2: use taxi during your trip? Enter 1 or 2: " << endl;
    cin >> car_or_taxi;
    while(cin.fail() == 1 || (cin.fail() == 0 && (car_or_taxi < 1 || car_or_taxi > 2))){
        cout << "Invalid input! Enter again: " << endl;
        car_or_taxi = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> car_or_taxi;
    }
    return(car_or_taxi);
}

/******************************************************
** Function: get_rental_fee
** Description: Gets rental fee
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_rental_fee(){
    double rental_money = 0;
    cout << "Enter your total rental fee, including gas fee, in $: " << endl;
    cin >> rental_money;
    while(cin.fail() == 1 || (cin.fail() == 0 && rental_money < 0)){
        cout << "Invalid input! Enter again: " << endl;
        rental_money = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> rental_money;
    }
    return(rental_money);
}

/******************************************************
** Function: get_taxi_fee
** Description: Gets taxi fee
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_taxi_fee(){
    double taxi_money = 0; 
    cout << "Enter your total taxi fee, in $: " << endl;
    cin >> taxi_money;
    while(cin.fail() == 1 || (cin.fail() == 0 && taxi_money < 0)){
        cout << "Invalid input! Enter again: " << endl;
        taxi_money = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> taxi_money;
    }
    return(taxi_money);
}

/******************************************************
** Function: get_parking_fee_by_day
** Description: Gets parking fee oper day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_parking_fee_by_day(int num_days){
    string parking_fees;
    string parking_fee;
    int day_count = 1;
    while(day_count <= num_days){
        cout << "Enter parking fee for day " << day_count << ", in $: " << endl;
        cin >> parking_fee;
        while(cin.fail() == 1 ){
            cout << "Invalid input! Enter again: " << endl;
            parking_fee = "";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> parking_fee;
        }
        
         if(day_count == 1){
            parking_fees = parking_fee;
        }
        else{
            parking_fees = parking_fees + "," + parking_fee;
        }
        day_count = day_count + 1;
    }
    return(parking_fees);
}

/******************************************************
** Function: is_valid_parking_cost
** Description: checks to see is cost is valid
** Parameters: has to be greater than 0
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

bool is_valid_parking_cost(string parking_fee){
    char *parkingptr;
    parkingptr = &parking_fee[0];
    double d_parking = atof (&parkingptr[0]);
    if(d_parking < 0){
        return(false);
    }
    else{
        return(true);
    }
}

/******************************************************
** Function: get_parking_cost_by_day
** Description: Gets parking cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_parking_cost_by_day(int day, string parking_fees){
    string s_cost;
    double cost;
    int index = 0;
    int comma_count = 0;
    while(index <= parking_fees.length()){
        if(day == 1){
            if(parking_fees[index] != ','){
                s_cost = s_cost + parking_fees[index];
            }
            else{
                break;
            }
        }
        else{
            if(comma_count == (day - 1)){
                s_cost = s_cost + parking_fees[index];
            }
            if(parking_fees[index] == ','){
                comma_count++;
            }
            if(comma_count == (day)){
                break;
            }
        }
        index++;
    }
    char *costptr;
    costptr = &s_cost[0];
    cost = atof (&costptr[0]);
    return (cost);
}

/******************************************************
** Function: get_hotel_cost
** Description: Gets hotel cost per night
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_hotel_cost(int num_days, char *hotel_fees_ptr){
    string hotel_fees = "";
    string hotel_cost = "";
    int day_spent_in_hotel = 1;
    while (day_spent_in_hotel <= num_days - 1){
        cout << "Enter hotel fee for night " << day_spent_in_hotel << ", in $: " << endl;
        if (day_spent_in_hotel == 1){
            cin >> hotel_fees;
        }
        if (day_spent_in_hotel > 1){
            cin >> hotel_cost;
            hotel_fees = hotel_fees + "," + hotel_cost;
        } 
        day_spent_in_hotel++;
    }
    hotel_fees_ptr = &hotel_fees[0];
    return (hotel_fees);
}    

/******************************************************
** Function: get_hotel_cost_by_day
** Description: adds hotel cost per night togeth
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double get_hotel_cost_by_day(int day, string hotel_fees){
    string s_cost;
    double cost;
    int index = 0;
    int comma_count = 0;
    while(index <= hotel_fees.length()){
        if(day == 1){
            if(hotel_fees[index] != ','){
                s_cost = s_cost + hotel_fees[index];
            }
            else{
                break;
            }
        }
        else{            
            if(comma_count == (day - 1)){
                s_cost = s_cost + hotel_fees[index];
            }
            if(hotel_fees[index] == ','){
                comma_count++;
            }
            if(comma_count == (day)){
                break;
            }
        }
        index++;
    }
    char *costptr;
    costptr = &s_cost[0];
    cost = atof (&costptr[0]);
    return (cost);
}

/******************************************************
** Function: get_b_fees_by_day
** Description: Gets breakfast cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_b_fees_by_day(int num_days, char *breakfast_fees_ptr){
    string meal_cost = "";
    int day_counter = 1;
    int breakast_fee;
    
    string breakfast_fees = "";
  
    while (day_counter <= num_days){
        cout << "Day " << day_counter << "\n";
        breakfast_fees = get_breakfast_fee_for_day(day_counter, breakfast_fees);
    
        day_counter++;
    }
    breakfast_fees_ptr = &breakfast_fees[0];
    return(breakfast_fees);

}

/******************************************************
** Function: get_l_fees_by_day
** Description: Gets lunch cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_l_fees_by_day(int num_days, char *lunch_fees_ptr){
    string meal_cost = "";
    int day_counter = 1;
    
    int lunch_fee;
 
    string lunch_fees = "";
    
    while (day_counter <= num_days){
        cout << "Day " << day_counter << "\n";
        
        lunch_fees = get_lunch_fee_for_day(day_counter, lunch_fees);
      
        day_counter++;
    }
    
    lunch_fees_ptr = &lunch_fees[0];
    return(lunch_fees);
    
}

/******************************************************
** Function: get_d_fees_by_day
** Description: Gets dinner cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_d_fees_by_day(int num_days, char *dinner_fees_ptr){
    string meal_cost = "";
    int day_counter = 1;
    int dinner_fee;
    string dinner_fees = "";
    while (day_counter <= num_days){
        cout << "Day " << day_counter << "\n";
        dinner_fees = get_dinner_fee_for_day(day_counter, dinner_fees);
        day_counter++;
    }
    dinner_fees_ptr = &dinner_fees[0];
    return(dinner_fees);

}

/******************************************************
** Function: get_breakfast_fee_for_day
** Description: Gets breakfast cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_breakfast_fee_for_day(int day_counter, string breakfast_fees){
    string breakfast_fee;
    cout << "Enter breakfast fee for day " << day_counter << ", in $: " << endl;
    if (day_counter == 1){
        cin >> breakfast_fee;
        breakfast_fees = breakfast_fee;
    }
    if (day_counter > 1){
        cin >> breakfast_fee;
        breakfast_fees = breakfast_fees + "," + breakfast_fee;
    } 
    return (breakfast_fees);
}

/******************************************************
** Function: get_breakfast_cost_by_day
** Description: Gets breakfast cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double breakfast_cost_by_day(int day, string breakfast_fees){
    string s_cost;
    double cost;
    int index = 0;
    int comma_count = 0;
    while(index <= breakfast_fees.length()){
        if(day == 1){
            if(breakfast_fees[index] != ','){
                s_cost = s_cost + breakfast_fees[index];
            }
            else{
                break;
            }
        }
        else{
            if(comma_count == (day - 1)){
                s_cost = s_cost + breakfast_fees[index];
            }
            if(breakfast_fees[index] == ','){
                comma_count++;
            }
            if(comma_count == (day)){
                break;
            }
        }
        index++;
    }
    char *costptr;
    costptr = &s_cost[0];
    cost = atof (&costptr[0]);
    return (cost);
}

/******************************************************
** Function: get_lunch_fee_for_day
** Description: Gets lunch cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_lunch_fee_for_day(int day_counter, string lunch_fees){
    string lunch_fee;
    cout << "Enter lunch fee for day " << day_counter << ", in $: " << endl;
    if (day_counter == 1){
        cin >> lunch_fee;
        lunch_fees = lunch_fee;
    }
    if (day_counter > 1){
        cin >> lunch_fee;
        lunch_fees = lunch_fees + "," + lunch_fee;
    } 
    return (lunch_fees);
}

/******************************************************
** Function: get_lunch_cost_for_day
** Description: Gets lunch cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double lunch_cost_by_day(int day, string lunch_fees){
    string s_cost;
    double cost;
    int index = 0;
    int comma_count = 0;
    while(index <= lunch_fees.length()){
        if(day == 1){
            if(lunch_fees[index] != ','){
                s_cost = s_cost + lunch_fees[index];
            }
            else{
                break;
            }
        }
        else{            
            if(comma_count == (day - 1)){
                s_cost = s_cost + lunch_fees[index];      
            }
            if(lunch_fees[index] == ','){
                comma_count++;
            }
            if(comma_count == (day)){
                break;
            }
        }
        index++;
    }
    char *costptr;
    costptr = &s_cost[0];
    cost = atof (&costptr[0]);
    return (cost);
}

/******************************************************
** Function: get_dinner_fee_for_day
** Description: Gets dinner cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

string get_dinner_fee_for_day(int day_counter, string dinner_fees){
    string dinner_fee;
    cout << "Enter dinner fee for day " << day_counter << ", in $: " << endl;
    if (day_counter == 1){
        cin >> dinner_fee;
        dinner_fees = dinner_fee;
    }
    if (day_counter > 1){
        cin >> dinner_fee;
        dinner_fees = dinner_fees + "," + dinner_fee;
    } 
    return (dinner_fees);
}

/******************************************************
** Function: get_dinner_fee_for_day
** Description: Gets dinner cost per day
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double dinner_cost_by_day(int day, string dinner_fees){
    string s_cost;
    double cost;
    int index = 0;
    int comma_count = 0;
    while(index <= dinner_fees.length()){
        if(day == 1){
            if(dinner_fees[index] != ','){
                s_cost = s_cost + dinner_fees[index];
            }
            else{
                break;
            }
        }
        else{
            
            if(comma_count == (day - 1)){
                s_cost = s_cost + dinner_fees[index];
      
            }
            if(dinner_fees[index] == ','){
                comma_count++;
            }
            if(comma_count == (day)){
                break;
            }
        }
        index++;
    }
    char *costptr;
    costptr = &s_cost[0];
    cost = atof (&costptr[0]);
    return (cost);
}

/******************************************************
** Function: calculate_total_expense
** Description: Gets total expense of the trip
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double calculate_total_expense(bool reimbursement, int num_days, double airfare_cost, double seminar_fees, int car_or_taxi, double rental_money, double taxi_money, string parking_fees, string hotel_fees, string breakfast_fees, string lunch_fees, string dinner_fees){
    double total_expense = 0;
    total_expense = airfare_cost + seminar_fees;
    int day_counter = 1;
    if(car_or_taxi == 1){
        //rental car
        total_expense = total_expense + rental_money;
        double parking_expense = 0;
        while(day_counter <= num_days){
            parking_expense = get_parking_cost_by_day(day_counter, parking_fees);
            if(!reimbursement){
                total_expense = total_expense + parking_expense;
            }
            else{
                double max_parking_expense = 6;
                if(parking_expense > max_parking_expense){
                    total_expense = total_expense + max_parking_expense;
                  
                }
                else{
                    total_expense = total_expense + parking_expense;
                }
            }   
            day_counter++;      
        }
    }
    if(car_or_taxi == 2){
        //taxi
        if(!reimbursement){
            total_expense = total_expense + taxi_money;
        }
        else{
            double max_taxi_expense = num_days * 10;
            if(taxi_money > max_taxi_expense){
                total_expense = total_expense + max_taxi_expense;
            }
            else{
                total_expense = total_expense + taxi_money;
            }
        }
    }
    day_counter = 1;
    double hotel_money = 0;
    while(day_counter <= num_days){
        hotel_money = get_hotel_cost_by_day(day_counter, hotel_fees);
        if(!reimbursement){
            total_expense = total_expense + hotel_money;
        }
        else{
            double max_hotel_expense = 90;
            if(hotel_money > max_hotel_expense){
                total_expense = total_expense + max_hotel_expense;
            }
            else{
                total_expense = total_expense + hotel_money;
          
            }
        }
        day_counter++;
    }
    if(!reimbursement){
        day_counter = 1;
        while(day_counter <= num_days){
            total_expense = total_expense + breakfast_cost_by_day(day_counter, breakfast_fees);
            day_counter++;
        }
        day_counter = 1;
        while(day_counter <= num_days){
            total_expense = total_expense + lunch_cost_by_day(day_counter, lunch_fees);
            day_counter++;
        }
        day_counter = 1;
        while(day_counter <= num_days){
            total_expense = total_expense + dinner_cost_by_day(day_counter, dinner_fees);
            day_counter++;
        }
    }
    return (total_expense);
}


/******************************************************
** Function: update_total
** Description: update the total cost, reimbursement and money left over
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void update_total (double *total_expense, double *total_reimbursement, double expense_to_add, double reimbursement_to_add){
    cout << "Total expense: " << *total_expense <<endl;
    *total_reimbursement = *total_reimbursement + reimbursement_to_add;
    cout << "Total reimbursement: " << *total_reimbursement << endl;
    cout << "You need to pay: " << *total_expense - *total_reimbursement << endl;
} 

/******************************************************
** Function: meal_fee_b
** Description: only count meal fee when it meets reimbursement criteria
** Parameters: departure time has to be before 7
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double meal_fee_b(int days_of_trip, double depart_time, double arrival_time, double *meal_expense, double *meal_reimbursement, double *meal_personal, string breakfast_fees){
    int day_counter = 1;
    double b_expense = 0;
    double b_reim = 0;
    double b_personal = 0;
    bool add = false;
    while(day_counter <= days_of_trip){
        double b_cost = breakfast_cost_by_day(day_counter, breakfast_fees);        
        if((day_counter == 1 && depart_time < 7) || (day_counter == days_of_trip && arrival_time > 8)){
            b_expense = b_expense + b_cost;
            add = true;
        }
        if(day_counter > 1){
            b_expense = b_expense + b_cost;
            add = true;
        }
        if(add){
            if(b_cost > 9){
                b_reim = b_reim + 9; 
                b_personal = b_personal + (b_cost - 9);
            }
            else{
                b_reim = b_reim + b_cost;
                b_personal = b_personal + 0;
            }
        }
        add = false;    
        day_counter++;

    }
    *meal_expense = b_expense;
    *meal_reimbursement = b_reim;
    *meal_personal = b_personal;
}

/******************************************************
** Function: meal_fee_l
** Description: only count meal fee when it meets reimbursement criteria
** Parameters: departure time has to be before 12
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double meal_fee_l(int days_of_trip, double depart_time, double arrival_time, double *meal_expense, double *meal_reimbursement, double *meal_personal, string lunch_fees){
    int day_counter = 1;
    double l_expense = 0;
    double l_reim = 0;
    double l_personal = 0;
    bool add = false;
    while(day_counter <= days_of_trip){
        double l_cost = lunch_cost_by_day(day_counter, lunch_fees);
        if((day_counter == 1 && depart_time < 12) || (day_counter == days_of_trip && arrival_time > 13)){
            l_expense = l_expense + l_cost;
            add = true;
        }
        if(day_counter > 1){
            l_expense = l_expense + l_cost;
            add = true;
        }
        if(add){
            if(l_cost > 12){
                l_reim = l_reim + 12; 
                l_personal = l_personal + (l_cost - 12);
            }
            else{
                l_reim = l_reim + l_cost;
                l_personal = l_personal + 0;
            }
        }
        add = false;    
        day_counter++;        
    }
    *meal_expense = *meal_expense + l_expense;
    *meal_reimbursement = *meal_reimbursement + l_reim;
    *meal_personal = *meal_personal + l_personal;
}

/******************************************************
** Function: meal_fee_d
** Description: only count meal fee when it meets reimbursement criteria
** Parameters: departure time has to be before 6
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

double meal_fee_d(int days_of_trip, double depart_time, double arrival_time, double *meal_expense, double *meal_reimbursement, double *meal_personal, string dinner_fees){
    int day_counter = 1;
    double d_expense = 0;
    double d_reim = 0;
    double d_personal = 0;
    bool add = false;
    while(day_counter <= days_of_trip){
        double d_cost = dinner_cost_by_day(day_counter, dinner_fees);
        if((day_counter == 1 && depart_time < 18) || (day_counter == days_of_trip && arrival_time > 19)){
            d_expense = d_expense + d_cost;
            add = true;
        }
        if(day_counter > 1){
            d_expense = d_expense + d_cost;
            add = true;
        }
        if(add){
            if(d_cost > 16){
                d_reim = d_reim + 16; 
                d_personal = d_personal + (d_cost - 16);
            }
            else{
                d_reim = d_reim + d_cost;
                d_personal = d_personal + 0;
            }
        }
        add = false;    
        day_counter++;
        
    }
    *meal_expense = *meal_expense + d_expense;
    *meal_reimbursement = *meal_reimbursement + d_reim;
    *meal_personal = *meal_personal + d_personal;
}

/******************************************************
** Function: meal_fee
** Description: calculate all the meal fees
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void meal_fee (int days_of_trip, double depart_time, double arrival_time, double *meal_expense, double *meal_reimbursement, double *meal_personal, string breakfast_fees, string lunch_fees, string dinner_fees){
    meal_fee_b(days_of_trip, depart_time, arrival_time, meal_expense, meal_reimbursement, meal_personal, breakfast_fees);
    meal_fee_l(days_of_trip, depart_time, arrival_time, meal_expense, meal_reimbursement, meal_personal, lunch_fees);
    meal_fee_d(days_of_trip, depart_time, arrival_time, meal_expense, meal_reimbursement, meal_personal, dinner_fees);
} 

/******************************************************
** Function: main
** Description: execute all funcions together at the same time
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){

    int num_days;
    int depart_time;
    int arrive_time;
    double airfare_cost;
    double *meal_expense;
    double *meal_reimbursement;
    double *meal_personal;
    double meal_total_expense;
    double meal_reimbursement_expense;
    double meal_personal_expense;
    double *total_reimbursement;
    double *total_expense;
    double total;
    double reimburse;
    bool play_game = true;
    char *hotel_fees_ptr;
    string breakfast_fees;
    string lunch_fees;
    string dinner_fees;
    char *breakfast_fees_ptr;
    char *lunch_fees_ptr;
    char *dinner_fees_ptr;
    int car_or_taxi;
    double seminar_fees = 0;
    double rental_money;
    double taxi_money;
    string parking_fees;
    string hotel_fees;


    while(play_game){
        int restart = 0;

        total = 0;
        reimburse = 0;
        total_expense = &total;
        total_reimbursement = &reimburse;
        meal_total_expense = 0;
        meal_reimbursement_expense = 0;
        meal_personal_expense = 0;
        meal_expense = &meal_total_expense;
        meal_reimbursement = &meal_reimbursement_expense;
        meal_personal = &meal_personal_expense;
        num_days = get_days_spent();
        depart_time = get_departure_time();
        arrive_time = get_arrival_time();
        airfare_cost = get_airfare_cost();
        seminar_fees = get_seminar_cost();
        car_or_taxi = vehicle();
        if(car_or_taxi == 1){
            rental_money = get_rental_fee();
            parking_fees = "";
            parking_fees = get_parking_fee_by_day(num_days);
        }
        else{
            taxi_money = get_taxi_fee();
        }
        hotel_fees = get_hotel_cost(num_days, hotel_fees_ptr);
        breakfast_fees = get_b_fees_by_day(num_days, breakfast_fees_ptr);
        lunch_fees = get_l_fees_by_day(num_days, lunch_fees_ptr);
        dinner_fees = get_d_fees_by_day(num_days, dinner_fees_ptr);
        meal_fee(num_days, depart_time, arrive_time, meal_expense, meal_reimbursement, meal_personal, breakfast_fees, lunch_fees, dinner_fees);
        *total_expense = calculate_total_expense(false, num_days, airfare_cost, seminar_fees, car_or_taxi, rental_money, taxi_money, parking_fees, hotel_fees, breakfast_fees, lunch_fees, dinner_fees);
        *total_reimbursement = calculate_total_expense(true, num_days, airfare_cost, seminar_fees, car_or_taxi, rental_money, taxi_money, parking_fees, hotel_fees, breakfast_fees, lunch_fees, dinner_fees);
        update_total (total_expense, total_reimbursement, meal_total_expense, meal_reimbursement_expense);
        cout << "Do you want to play again? (1-yes 0-no) " << endl;
        cin >> restart;
        play_game = false;
        if (restart == 1){
            play_game = true;
        }
    }

    return 0;
}
