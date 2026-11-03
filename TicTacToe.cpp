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
    char turno = 'X';
    int casilla;
    int jugadas = 0;

    while (jugadas < 9) {
        mostrarTablero();
        cout << "Turno del jugador " << turno << ". Elige una casilla (1-9): ";
        cin >> casilla;

        if (casilla < 1 || casilla > 9) {
            cout << "Numero invalido, intenta elegir del 1 al 9." << endl;
            continue;
        }

        int fila = (casilla - 1) / 3;
        int columna = (casilla - 1) % 3;

        if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O') {
            cout << "Esa casilla ya esta ocupada, elige otra." << endl;
            continue;
        }

        tablero[fila][columna] = turno;
        jugadas++;

        if (turno == 'X') {
            turno = 'O';
        } else {
            turno = 'X';
        }
    }

    mostrarTablero();
    return 0;
}
