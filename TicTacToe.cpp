// BURGUEÑO DELGADO JESUS ALFREDO
// Mini proyecto: Tic Tac Toe (Juego del Gato)

#include <iostream>

using namespace std;

// Matriz de 3x3 para guardar las posiciones del tablero
char tablero[3][3];

// Funcion para poner los numeros del 1 al 9 al iniciar una partida
void reiniciarTablero() {
    char numero = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = numero;
            numero++;
        }
    }
}

// Funcion para dibujar el tablero en pantalla
void mostrarTablero() {
    cout << endl;
    cout << " --- JUEGO TIC TAC TOE (GATO) ---" << endl << endl;
    cout << " Jugador 1 (X)  -  Jugador 2 (O)" << endl << endl;

    for (int i = 0; i < 3; i++) {
        cout << "        " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << endl;
        if (i < 2) {
            cout << "       ---|---|---" << endl;
        }
    }
    cout << endl;
}

// Funcion para revisar si alguien ya gano
bool hayGanador() {
    // Revisar las 3 filas y las 3 columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return true;
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return true;
        }
    }

    // Revisar las 2 diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return true;
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return true;
    }

    return false;
}

int main() {
    char jugarDeNuevo = 's';

    while (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        reiniciarTablero();
        char turno = 'X';
        int casilla;
        int jugadas = 0;
        bool partidaTerminada = false;

        while (jugadas < 9 && !partidaTerminada) {
            mostrarTablero();
            cout << "Turno del jugador " << turno << ". Elige una casilla (1-9): ";
            cin >> casilla;

            // Validar que el usuario escriba un numero valido
            if (cin.fail() || casilla < 1 || casilla > 9) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Jugada no valida. Por favor ingresa un numero del 1 al 9." << endl;
                continue;
            }

            // Calcular la fila y columna segun el numero del 1 al 9
            int fila = (casilla - 1) / 3;
            int columna = (casilla - 1) % 3;

            // Verificar que la casilla no este ocupada
            if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O') {
                cout << "Esa casilla ya esta ocupada. Intenta con otra." << endl;
                continue;
            }

            // Marcar la jugada en el tablero
            tablero[fila][columna] = turno;
            jugadas++;

            // Comprobar si gano o si hubo empate
            if (hayGanador()) {
                mostrarTablero();
                cout << "*** Felicidades! El jugador " << turno << " ha ganado la partida! ***" << endl;
                partidaTerminada = true;
            } else if (jugadas == 9) {
                mostrarTablero();
                cout << "*** La partida termino en empate! ***" << endl;
                partidaTerminada = true;
            } else {
                // Cambiar de turno
                if (turno == 'X') {
                    turno = 'O';
                } else {
                    turno = 'X';
                }
            }
        }

        cout << endl;
        cout << "Desean jugar otra partida? (s/n): ";
        cin >> jugarDeNuevo;
    }

    cout << endl;
    cout << "Gracias por jugar. Presiona Enter para salir...";
    cin.ignore();
    cin.get();

    return 0;
}
