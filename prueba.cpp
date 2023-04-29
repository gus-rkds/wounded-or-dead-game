#include <iostream>
#include <ctime>

using namespace std;


// Function that generates a random number of four digits having all digits diferent
int generate() {
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
    cout << generate();
}