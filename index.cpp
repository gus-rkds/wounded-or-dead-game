#include <iostream>
#include <ctime>
using namespace std;

int floor(float num) {
    /*
    Function that returns the floor of a number
    input: a float number
    output: the floor of the number
    */

    int floor = int(num);
    // (if the number is negative, the floor is the number minus one)
    if (num < 0) {
        floor--;
    }
    return floor;
}

int randomNumberInt(int min, int max) {
    /*
    Function that generates a random int between two numbers
    input: the range of the random number in int
    output: a random int between the two numbers
    */
    
    // set the random source
    srand(time(NULL)); 
    int randomInt = min + ( rand()%(max - min + 1) );
    return randomInt;
}

int randomIntFourDiffDigit() {
    /*
    Function that generates a random int of four differents digits 
    input: none
    output: a random int of four digits having all digits diferent
    */
    
    // set the random source 
    srand(time(NULL)); 
    int digits[4]; 

    for (int i = 0; i < 4; i++) {
        // generate a random digit bewteen 0 and 9
        int potentialDigit = randomNumberInt(0, 9);

        // check if the digit was already generated
        for (int j = 0; j < i; j++) {
            if (potentialDigit == digits[j]) { 
                // if the digits was already generated, generate another digit
                // and start the loop again
                potentialDigit = randomNumberInt(0, 9);
                j = -1; 
            }
        }

        // store the digit 
        digits[i] = potentialDigit; 
    }

    // concatenate the int
    int num = (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + digits[3];
    return num;
}

bool isNumberHave4DigitDifferent(int num) {
    /*
    Function that verifies if the four digits of a int are Diferent
    input: an integer number of four digits
    output: a boolean value that indicates if the digits of the int are diferent
    */
    
    // get the digits of the number
    int numDigits[4]; 
    for (int i = 0; i < 4; i++) {
        // obtains the last digit of the number
        numDigits[i] = num % 10; 
        // delete the last digit of the number
        num = floor(num / 10);
    }

    // Check if the digits are diferent
    // (no debería ser i<3?)
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            // if two digits are equal, the number is not valid
            if (numDigits[i] == numDigits[j]) { 
                return false;
            }
        }
    }

    return true;
}

bool isStringOfInt(string str){
    /*
    Function that verifies if a string is a string of is characters 
    input: a string 
    output: a boolean value that indicates if the string is a string of characters
    */

    for (char characters : str) {
        if (!isdigit(characters)) {
            return false;
            break;
        }
    }

    return true; 
}

bool validTurnInput(string turn_input){
    /*
    Function that verifies all the inputs turns from the user  
    (check if the input is [int, 4 digits, all digits diferent] )
    input: the string of the user input for the turn 
    output: a boolean value that indicates if the input is valid
    */

    // check if the input is a string of int
    int input_int = 0;
    if(isStringOfInt(turn_input)){
        input_int = stoi(turn_input);
    }
    else {
        return false;
    }

    // check if the input is a number of 4 digits and all digits are diferent
    if (input_int < 1000 or input_int> 9999){
        return false;
    }
    else if (!isNumberHave4DigitDifferent(input_int)){
        return false;
    }

    return true;
}

void clearConsole() {
    /*
    Function that clears the console
    input: none
    output: clear the console
    */

    cout << "\033[2J\033[1;1H";
}

int stopInputNumberState(string informative_text, int last_number_to_input) {
    /*
    Function that waits for the user to input a number in a range of numbers 
    (range is from 1 to lastNumberToInput)
    input: the informative text to show to the user, the last number
    output: the number inputed by the user
    */

    string input = "";
    int input_int = 0;
    bool invalid_input = true;
    // request input until the input is in the range of numbers
    cout << informative_text;
    while(invalid_input){
        cin >> input;

        if( isStringOfInt(input) ){
            input_int = stoi(input);

            if( input_int >= 1 and input_int <= last_number_to_input ){
                invalid_input = false;
            }
        }
    }

    cin.ignore();
    return input_int;
}

void centeredPrint(string text, char emptySpaces = ' ', int widthLine = 80){
    /*
    Function that prints a text centered in a line 
    input: the text to print, the character to fill the empty spaces, the width of the line 
    output: print the text centered in a line
    */ 
    
    // calculate the number of empty spaces 
    int emptySpacesNumber = widthLine - text.length();
    // calculate the number of empty spaces in each side of the text
    int emptySpacesLeft = floor(emptySpacesNumber / 2);
    int emptySpacesRight = emptySpacesNumber - emptySpacesLeft;

    // print the text
    for (int i = 1; i <= emptySpacesLeft; i++) {
        cout << emptySpaces;
    }
    cout << text;
    for (int i = 1; i <= emptySpacesRight; i++) {
        cout << emptySpaces;
    }
}

int mainMenu(){
    /*
    Function that prints the main menu of the game 
    input: none
    output: print the main menu of the game
    */

    string title_header[] = { 
        "---------------------",
        "- MUERTOS Y HERIDOS -",
        "---------------------",
        "",
        "",
    };

    string main_menu_options_template[3] = {
        "  1. Jugar           ",
        "  2. Instrucciones   ",
        "  3. Salir           ",
    };

    string main_menu_options[3] = {
        "  1. Jugar           ",
        "  2. Instrucciones   ",
        "  3. Salir           ",
    };

    char input_user = ' '; 
    int user_actual_option = 1;
    while(input_user != '\0' or input_user != '\n' or input_user != 'e'){
        // print the title
        for (string title : title_header) {
            centeredPrint(title);
            cout << endl;
        }

        // restart the options
        copy(begin(main_menu_options_template), 
             end(main_menu_options_template), 
             begin(main_menu_options)
             );

        // adjust the options to the actual options
        int index_line = user_actual_option - 1;
        int last_index_in_options = main_menu_options[index_line].length() - 1;
        main_menu_options[index_line][0] = '>';
        main_menu_options[index_line][last_index_in_options] = '<';

        // print the menu options 
        for (string options : main_menu_options) {
            centeredPrint(options);
            cout << endl;
        }
       
        // get the user input 
        cin >> input_user;

        // move the cursor based on the input, w is up, s is down
        if(input_user == 'w' or input_user == 'k'){
            if(user_actual_option > 1){
                user_actual_option -= 1;
            }
            else if(user_actual_option == 1){
                user_actual_option = 3;
            }
        }
        else if(input_user == 's' or input_user == 'j'){
            if(user_actual_option < 3){
                user_actual_option += 1;
            }
            else if(user_actual_option == 3){
                user_actual_option = 1;
            }
        }
        else if(input_user == '\0' or input_user == '\n' or input_user == 'e'){
            break;
        };

        clearConsole();
    }

    return user_actual_option;
}

void printInstructions(){
    string title_header[] = {
        "-------------------",
        "-MUERTOS Y HERIDOS-",
        "-------------------",
        "",
        "",
    };

    string instructions_text[] = {
        "Instrucciones:",
        "",
        "El juego consiste en adivinar un numero de 4 digitos",
        "que no se repitan los digitos.",
        "",
        "El juego te dara pistas de cuantos muertos y heridos",
        "tienes en cada turno.",
        "",
        "Un muerto es un digito que esta en la posicion correcta.",
        "Un herido es un digito que esta en la posicion incorrecta.",
        "",
        "Tienes 10 intentos para adivinar el numero.",
        "",
        "Buena suerte!",
        "",
        "",
        "Presione enter para volver al menu principal",
    };
}

int main(){
    // start the game
    bool game_state = true;
    while(game_state){
        clearConsole();
        int menu_user_option = mainMenu();
        clearConsole();
    
        // start the game
        if(menu_user_option == 1){
            
        }
        // show the instructions
        else if(menu_user_option == 2){
            
        }
        // exit the game
        else if(menu_user_option == 3){
            game_state = false;
        }
    }

    return 0;
}
