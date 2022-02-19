/******************************************************
** Program Filename: assignment4.cpp
** Author: Yash Sankanagouda
** Date: Feb. 27, 2021
** Description: Perform letter swap, reverse string, and word frequency
** Input: String/text
** Output: Letter swap, reverse string, and word frequency
******************************************************/

#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;

/******************************************************
** Function: letter_swap
** Description: swaps the second letter inputted with the first
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//function for letter swap
void letterswap(char *input_text, char *output_text){

    char first_letter;
    char second_letter;
    int length = 0;
    //find length of the string
    length = strlen(input_text);
    //letter to be replaced
    cout << "Enter letter to be replaced: ";
    cin >> first_letter;
    //rerror handling
    while(int(first_letter) >= 48 && int(first_letter) <= 57){
        cout << "Invalid! Re-enter: ";
        cin >> first_letter;
    }
    //letter to replace with
    cout << "Enter letter to replace it with: ";
    cin >> second_letter;
    //error handling
    while(int(second_letter) >= 48 && int(second_letter) <= 57){
        cout << "Invalid! Re-enter: ";
        cin >> second_letter;
    }
    for(int i = 0; i < length; i++){
        char tempchar = input_text[i];
        if(tempchar == first_letter){
            tempchar = second_letter;
        }
        output_text[i] = tempchar;
        
    }
    //original and modfied text
    cout << "Original text: " << input_text << endl;
    cout << "Modified text: " << output_text << endl;
}

/******************************************************
** Function: reverse_string
** Description: reverses the string
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//fuction to reverse the string
void reversestring(char *input_text, char *output_text){

    int length = 0;
    int output_text_counter = 0;
    //find length of the string
    length = strlen(input_text);
    //flips the characters in the string on at a time
    for(int i = length - 1; i >= 0; i--){
        char tempchar = input_text[i];
        output_text[output_text_counter] = tempchar;
        output_text_counter++;
    }
    //original and modified text
    cout << "Original text: " << input_text << endl;
    cout << "Modified text: " << output_text << endl;

}

/******************************************************
** Function: get_num_words_from_user
** Description: prompts the user with how many words they would like to search for
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//how many words the user wants to search for word frequency
int get_num_words_from_user(){
    int words_count = 0;
    //prompt user and ask how many words to search
    cout << "How many words would you like to search?" << endl;
    cin >> words_count;
    //error handling
    while(cin.fail() == 1 || (cin.fail() == 0 && (words_count > 3 || words_count < 1))){
        cout << "Invalid input! Enter again: " << endl;
        words_count = 0;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> words_count;
    }
    return(words_count);
}

/******************************************************
** Function: convert_to_upper
** Description: converts all letters to uppercase to make it case insensitive
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//converts all letters to uppercase to make it case insensitive
void convert_to_upper(char *word){

    int length = strlen(word);

    for(int i = 0; i < length; i++){
        char tempchar = word[i];
        word[i] = toupper(tempchar);
    }
}

/******************************************************
** Function: clean_input_text
** Description: cleans up the text and removes any special characters
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//cleans up the text and removes any special characters
char* clean_input_text(char *input_text){

    int length = strlen(input_text);
    int count = 0;
    string cleaned_text;
    //removes special characters
    for(int i = 0; i < length; i++){
        char tempchar = input_text[i];
        if((int(tempchar) >= 97 && int(tempchar) <= 122) || int(tempchar) == 32 || (int(tempchar) >= 65 && int(tempchar) <= 90)){
            cleaned_text = cleaned_text + tempchar;
            count++;
        }
    }
    char *cleaned_text_ptr = &cleaned_text[0];
    return (cleaned_text_ptr);
}

/******************************************************
** Function: wordsfrequency
** Description: find the frequency of the words
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

//function for word frequency
void wordsfrequency(char *input_text){

    int words_count = 0;
    int length = 0;
    string word_input_str = "";
    char *cleaned_input_text_ptr;
    
    cleaned_input_text_ptr = clean_input_text(input_text);
    words_count = get_num_words_from_user();


    string words[words_count];
    int wordsfrequency[words_count];
    string word = "";
    for(int i = 0; i < words_count; i++){
        word = "";
        cout << "Enter word " << (i + 1) << ": " << endl;
        cin >> word;
        words[i] = word;
        wordsfrequency[i] = 0;
    }

    length = strlen(input_text);
    //separate the words with a space and store it into an array
    for(int i = 0; i < length; i++){
        char tempchar = cleaned_input_text_ptr[i];
        if(tempchar != ' ' || i == length - 1){
            word_input_str = word_input_str + tempchar;
        }
        if(tempchar == ' ' || i == length - 1){
            for(int j = 0; j < words_count; j++){
                char *word_one = &word_input_str[0];
                word = words[j];
                char *word_two = &word[0];
                convert_to_upper(word_one);
                convert_to_upper(word_two);
                if(strcmp(word_one, word_two) == 0){
                    wordsfrequency[j]++;
                }               
            }
            word_input_str = "";
        }
    }
    //prints out the frequency of the words searched for
    for(int j = 0; j < words_count; j++){
        cout << words[j] << ": " << wordsfrequency[j] << endl;
    }
}

/******************************************************
** Function: get_text_from_user
** Description: gets the string from the user
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

void get_text_from_user(char* input_text){

    cout << "Enter text: ";
    cin.getline(input_text, 1023);

}

/******************************************************
** Function: main
** Description: executes all the fuctions together at the same time
** Parameters: n/a
** Pre-conditions: n/a
** Post-conditions: n/a
******************************************************/

int main(){

    char *input_text_ptr = (char*)malloc(1023); //only allows a character count of 1023
    char *output_text_ptr = (char*)malloc(1023); //only allows a character count of 1023
    int operation;
    int restart = 1;
    
    get_text_from_user(input_text_ptr);


    while(restart == 1){

        cout << "What would you like to perform? 1-Letter Swap 2-Flip the String 3-Word Frequency" << endl;
        cin >> operation;

        while(cin.fail() == 1 || (cin.fail() == 0 && (operation > 3 || operation < 1))){
            cout << "Invalid input! Enter again: " << endl;
            operation = 0;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> operation;
        }

        if(operation == 1){
            letterswap(input_text_ptr, output_text_ptr);
        }

        if(operation == 2){
            reversestring(input_text_ptr, output_text_ptr);
        }

        if(operation == 3){
        wordsfrequency(input_text_ptr);
        }
        cout << "Would you like to restart? 1-yes 0-no" << endl;
        cin >> restart;
        while(restart < 0 || restart > 1){
            cout << "Invalid! Re-enter: ";
            cin >> restart;
        }
    }

    return 0;
}
