#include <iostream>
using namespace std;

bool verify (int number){
    if (number < 1000 or number > 9999){
        return false;
    } else if (number != int(number)){
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
