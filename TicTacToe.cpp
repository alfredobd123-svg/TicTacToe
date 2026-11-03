// BURGUEÑO DELGADO JESUS ALFREDO
// Mini proyecto: Tic Tac Toe (Juego del Gato)

#include <iostream>

using namespace std;

char tablero[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void mostrarTablero() {
    cout << endl;
    cout << " --- TIC TAC TOE ---" << endl << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << endl;
        if (i < 2) {
            cout << " ---|---|---" << endl;
        }
    }
    cout << endl;
}

int main() {
    mostrarTablero();
    return 0;
}
