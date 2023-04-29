#include <iostream>
using namespace std;

bool isDiferent(int num) {
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

// Function that verifies all the inputs from the user
// input: an integer
// output: a boolean value that indicates if the number is valid, if not, print the error
bool verify (int number){
    if (number < 1000 or number > 9999){
        cout << "The number must be between 1000 and 9999";
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

main(){
    int number = 1234;
    if (verify(number)){
        cout << "valid number " << number;
    } else {
        cout << "is not valid " << number;
    }
}
