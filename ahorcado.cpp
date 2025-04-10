#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Muestra el estado actual de la palabra con letras adivinadas
void mostrarProgreso(const string& progreso) {
    for (int i = 0; i < progreso.length(); ++i) {
        cout << progreso[i] << " ";
    }
    cout << endl;
}

// Muestra la parte del cuerpo que se pierde según los errores
void mostrarParteDelCuerpo(int errores) {
    switch (errores) {
        case 1: cout << "Pierde pierna derecha" << endl; break;
        case 2: cout << "Pierde pierna izquierda" << endl; break;
        case 3: cout << "Pierde brazo derecho" << endl; break;
        case 4: cout << "Pierde brazo izquierdo" << endl; break;
        case 5: cout << "Pierde tronco" << endl; break;
        case 6: cout << "Pierde cabeza" << endl; break;
    }
}

// Verifica si una letra ya fue adivinada
bool letraYaAdivinada(char letra, const string& progreso) {
    for (int i = 0; i < progreso.length(); ++i) {
        if (progreso[i] == letra) {
            return true;
        }
    }
    return false;
}

// Intenta actualizar el progreso con la letra ingresada
bool actualizarProgreso(char letra, const string& palabra, string& progreso) {
    bool acierto = false;
    for (int i = 0; i < palabra.length(); ++i) {
        if (palabra[i] == letra && progreso[i] == '_') {
            progreso[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}

// Verifica si la palabra ha sido completamente adivinada
bool palabraCompleta(const string& progreso) {
    for (int i = 0; i < progreso.length(); ++i) {
        if (progreso[i] == '_') {
            return false;
        }
    }
    return true;
}

int main() {
    string palabra, progreso;
    char letra;
    int errores = 0;
    const int maxErrores = 6;

    cout << "Bienvenido al juego del Ahorcado\n";
    cout << "Ingrese la palabra: ";
    getline(cin, palabra);

    // Limpiar la pantalla (opcional)
    cout << string(50, '\n');

    // Inicializar progreso con guiones bajos
    for (int i = 0; i < palabra.length(); ++i) {
        if (palabra[i] != ' ')
            progreso += "_";
        else
            progreso += " "; // Permitir espacios en la palabra
    }

    cout << "Comienza el juego!" << endl;

    while (errores < maxErrores && !palabraCompleta(progreso)) {
        mostrarProgreso(progreso);

        cout << "Ingrese letra: ";
        cin >> letra;

        // Normalizar a minúscula 
        if (letra >= 'A' && letra <= 'Z') {
            letra = letra + ('a' - 'A');
        }

        if (letraYaAdivinada(letra, progreso)) {
            cout << "Ya has adivinado esa letra. Intenta otra." << endl;
            continue;
        }

        if (!actualizarProgreso(letra, palabra, progreso)) {
            errores++;
            mostrarParteDelCuerpo(errores);
        }
    }

    if (palabraCompleta(progreso)) {
        cout << "\n¡Felicidades! Adivinaste la palabra: " << palabra << endl;
    } else {
        cout << "\nHas perdido el juego." << endl;
        cout << "La palabra era: " << palabra << endl;
    }

    return 0;
}
