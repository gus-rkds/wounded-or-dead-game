#include <iostream>
#include <ctime>

using namespace std;

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
    if (number < 1000 or number > 9999){
        cout << "The number must have four digits";
        return false;
    } else if (number != int(number)){
        cout << "The number must be an integer";
        return false;
    } else if (!isDiferent(number)){
        cout << "The number must have all digits diferent";
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
        
        // Verificar si todos los caracteres son dígitos
        bool all_digits = true;
        for (char c : user_input) {
            if (!isdigit(c)) {
                all_digits = false;
                break;
            }
        }
        
        if (all_digits) {
            // El usuario ha ingresado un entero válido
            number = stoi(user_input);
            valid_input = true;
        } else {
            cout << "El valor ingresado no es un entero valido, Intentelo de nuevo" << endl;
        }
    }
    
    cout << "El entero ingresado es: " << number << endl;



    cout << generate() << endl;
}