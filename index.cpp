#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

bool isDiferent(int num) {
    int digitos[4];
    for (int i = 0; i < 4; i++) {
        digitos[i] = num % 10; // Se obtiene el último dígito del número
        num /= 10; // Se elimina el último dígito del número
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digitos[i] == digitos[j]) { // Si hay dígitos iguales, el número no es válido
                return false;
            }
        }
    }
    return true;
}

int generate() {
    int num;
    srand(time(NULL)); // Se inicializa el generador de números aleatorios con la hora actual
    do {
        num = rand() % 9000 + 1000; // Se genera un número aleatorio de 4 dígitos
    } while (!isDiferent(num)); // Se comprueba si los dígitos del número son diferentes
    return num;
}

main(){
    cout << generate(); 
}



