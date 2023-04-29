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

bool checkTurnInput(int number){
    // Function that verifies all the inputs turns from the user  
    // (check if the input is [int, 4 digits, all digits diferent] )
    // input: an integer
    // output: a boolean value that indicates if the number is valid, if not, print the error
    string userInput;
    bool validInput = false;

    if (number < 1000 or number > 9999){
        return false;
    } else if (number != int(number)){
        return false;
    } else if (!isNumberHave4DigitDifferent(number)){
        return false;
    }

    return true;
}


int main(){
    string user_input;
    int number;
    bool valid_input = false;
    
    while (!valid_input) {
        cout << "Por favor, ingrese un entero: ";
        cin >> user_input;
        
        // verify is the characters of the string are all digits
        bool all_digits = true;
        for (char c : user_input) {
            if (!isdigit(c)) {
                all_digits = false;
                break;
            }
        }
        
        // if the characters are all digits and the numbers is valid
        if (all_digits and checkTurnInput(stoi(user_input))) {
            // the user input is valid
            number = stoi(user_input);
            valid_input = true;
        } else {
            cout << "El valor ingresado no es un entero valido. Intentelo de nuevo." << endl;
        }
    }
    
    cout << "El entero ingresado es: " << number << endl;
    
    return 0;
}
