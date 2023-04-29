#include <iostream>
#include <ctime>
using namespace std;

void clear_console() {
    // Function that clears the console
    // input: none
    // output: clear the console
    cout << "\033[2J\033[1;1H";
}

void input_continue_stop() {
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

bool isDiferent(int num) {
    // Function that verifies if the four digits of a number are Diferent
    // input: an integer number of four digits
    // output: a boolean value that indicates if the digits of the number are Diferent
    int digits[4]; // create an array to store the digits of the number
    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10; // obtains the last digit of the number
        num /= 10; // delete the last digit of the number
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] == digits[j]) { // if two digits are equal, the number is not valid
                return false;
            }
        }
    }
    return true;
}

bool verify (int number){
    // Function that verifies all the inputs from the user  
    // input: an integer
    // output: a boolean value that indicates if the number is valid, if not, print the error
    string userInput;
    bool validInput = false;
    if (number < 1000 or number > 9999){
        return false;
    } else if (number != int(number)){
        return false;
    } else if (!isDiferent(number)){
        return false;
    }
    return true;
}

int generate() {
    // Function that generates a random number of four digits having all digits diferent
    int digits[4]; // create an array to store the digits of the number
    srand(time(NULL)); // inicialize the random source time

    for (int i = 0; i < 4; i++) {
        int dig = rand() % 10; // generate a random digit bewteen 0 and 9
        for (int j = 0; j < i; j++) {
            if (dig == digits[j]) { // if the digits was already generated, generate another digit
                dig = rand() % 10;
                j = -1; // restart the loop
            }
        }
        digits[i] = dig; // store the digit in the array
    }

    int num = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3]; // concatenate the number
    return num;
}

main() {
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
        if (all_digits and verify(stoi(user_input))) {
            // the user input is valid
            number = stoi(user_input);
            valid_input = true;
        } else {
            cout << "El valor ingresado no es un entero valido. Intentelo de nuevo." << endl;
        }
    }
    
    cout << "El entero ingresado es: " << number << endl;
    
}
