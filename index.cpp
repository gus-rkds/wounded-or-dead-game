#include <iostream>
#include <ctime>
using namespace std;

void clearConsole() {
    // Function that clears the console
    // input: none
    // output: clear the console
    cout << "\033[2J\033[1;1H";
}

void inputContinueStop() {
    // Function that waits for the user to press enter to continue
    // If use other key, the program stops
    // input: none
    // output: create a pause in the program for continue or stop
    string input;
    cout << "Presione enter para continuar o cualquier otra tecla para salir: ";
    cin >> input;
    if (input != "") {
        exit(0);
    }
    cin.ignore();
}

int floor(float num) {
    // Function that returns the floor of a number
    // input: a float number
    // output: the floor of the number
    int floor = int(num);

    // (if the number is negative, the floor is the number minus one)
    if (num < 0) {
        floor--;
    }
    return floor;
}

int randomNumberInt(int min, int max) {
    // Function that generates a random int between two numbers
    // input: the range of the random number in int
    // output: a random int between the two numbers
    
    // set the random source
    srand(time(NULL)); 
    int randomInt = min + ( rand()%(max - min + 1) );
    return randomInt;
}

int randomIntFourDiffDigit() {
    // Function that generates a random int of four differents digits 
    // input: none
    // output: a random int of four digits having all digits diferent
    
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
    // Function that verifies if the four digits of a int are Diferent
    // input: an integer number of four digits
    // output: a boolean value that indicates if the digits of the int are diferent
    
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
    // Function that verifies if a string is a string of is characters 
    // input: a string 
    // output: a boolean value that indicates if the string is a string of characters

    for (char characters : str) {
        if (!isdigit(characters)) {
            return false;
            break;
        }
    }

    return true; 
}

bool validTurnInput(string turn_input){
    // Function that verifies all the inputs turns from the user  
    // (check if the input is [int, 4 digits, all digits diferent] )
    // input: the string of the user input for the turn 
    // output: a boolean value that indicates if the input is valid

    int input_int = 0;
    // check and get the input in int
    if(isStringOfInt(turn_input)){
        input_int = stoi(turn_input);
    }
    else {
        return false;
    }

    // check if the int have exactly 4 digits and all digits are diferent
    if (input_int < 1000 or input_int> 9999){
        return false;
    }
    else if (!isNumberHave4DigitDifferent(input_int)){
        return false;
    }

    return true;
}

int main(){
    string user_input = "";
    int number_input = 0;
    
    bool invalid_input_turn = true;
    while (invalid_input_turn) {
        cout << "Por favor, ingrese un entero: ";
        cin >> user_input;
        
        // if the characters are all digits and the numbers is valid
        if (validTurnInput(user_input) ){
            number_input = stoi(user_input);
            invalid_input_turn = false;
        } else {
            cout << "El valor ingresado no es un entero valido. Intentelo de nuevo." << endl;
        }
    }
    
    cout << "El entero ingresado es: " << number_input << endl;
    
    return 0;
}
