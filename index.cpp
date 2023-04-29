#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;


// Function that verifies if the four digits of a number are Diferent
// input: an integer number of four digits
// output: a boolean value that indicates if the digits of the number are Diferent
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

// Function that generates a random number of four digits having all digits diferent
// output: generate a random number of four digits having all digits diferent
int generate() {
    int num;
    srand(time(NULL)); // inicialize the random source time
    do {
        num = rand() % 9000 + 1000; // generate a random number between 1000 and 9999
    } while (!isDiferent(num)); // verifies if the number is valid
    return num;
}

main(){
    cout << generate(); 
}



