#include <iostream>
#include <string>
#include <unistd.h> // Para usar sleep
#include <algorithm> // Para usar transform (en minusculas)

// Prototipos de las funciones
void pantallaPrincipal();
bool nivel1();
bool nivel2();
bool nivel3();
bool nivel4();
bool nivel5();
void barraDeVida(int vidas);
void barra(int respondidas);
void textoReintente();
void jugar();
void hasGanado();

using namespace std;

int main() {
    pantallaPrincipal();
    return 0;
}

// Carga de pantalla principal del juego
void pantallaPrincipal() {
    int tiempo = 0;
    int carga;

    do {
        carga = (tiempo / 3.0) * 100;

        system("cls");
        cout << "------------------------------------" << endl;
        cout << "  Cargando por favor espere..... " << endl;
        cout << "------------" << carga << "%" << "--------------------" << endl;
        sleep(1);
        system("cls");
        cout << carga << endl;
        cout << "------------------------------------" << endl;
        cout << "  Cargando por favor espere......... " << endl;
        cout << "------------" << carga << "%" << "--------------------" << endl;
        sleep(0.5);
        system("cls");
        tiempo++;
    } while (tiempo < 4);

    int opc;
    do {
        cout << "------------------------------------" << endl;
        cout << "        Prision de los Enigmas       " << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cin >> opc;

        switch(opc) {
            case 1:
                system("cls");
                jugar();
                break;
            default:
                opc = 2;
                break;
        }
    } while (opc != 2);
}

// Funcion para el nivel 1
bool nivel1() {
    string preguntasNivel1[3] = {
        "Soy un numero par, divideme por 2 y el resultado es 18",
        "Soy un numero mayor que 10, si me restas 4, el resultado es 8",
        "Soy un numero impar, si me sumas 9 y luego lo divides entre 2, obtienes 17"
    };
    int respuestasNivel1[3] = {36, 12, 25};
    int vidas = 5, respondidas = 0;
    bool gano = false;
    int respuesta;

    cout << "Nivel 1. (Adivinanza matematica)" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3 && vidas > 0; ++i) {
        do {
            barraDeVida(vidas);
            barra(respondidas);
            cout << "----------Pregunta " << i+1 << "---------" << endl;

            cout << preguntasNivel1[i] << endl;
            cin >> respuesta;
            system("cls");
            if (respuesta != respuestasNivel1[i]) vidas--;
        } while (respuesta != respuestasNivel1[i] && vidas > 0);

        if (vidas > 0) respondidas++;
    }

    gano = vidas > 0;
    return gano;
}

// Funcion para el nivel 2
bool nivel2() {
    string preguntasNivel2[3] = {
        "Completa la secuencia: 2, 4, 6, 8, ?",
        "Completa la secuencia: 1, 3, 5, 7, ?",
        "Completa la secuencia: 5, 10, 15, 20, ?"
    };
    int respuestasNivel2[3] = {10, 9, 25};
    int vidas = 5, respondidas = 3;
    bool gano = false;
    int respuesta;

    cout << "Nivel 2. (Secuencia logica)" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3 && vidas > 0; ++i) {
        do {
            barraDeVida(vidas);
            barra(respondidas);
            cout << "----------Pregunta " << i+1 << "---------" << endl;
            cout << preguntasNivel2[i] << endl;
            cin >> respuesta;
            system("cls");
            if (respuesta != respuestasNivel2[i]) vidas--;
        } while (respuesta != respuestasNivel2[i] && vidas > 0);

        if (vidas > 0) respondidas++;
    }

    gano = vidas > 0;
    return gano;
}

// Funcion para el nivel 3
bool nivel3() {
    string preguntasNivel3[3] = {
        "Encuentra la palabra oculta: El agua siempre fluye con fuerza.",
        "La montaña es muy alta.",
        "La nieve cubre el sol."
    };
    string respuestasNivel3[3] = {"agua", "montania", "nieve"};
    int vidas = 5, respondidas = 6;
    bool gano = false;
    string respuesta;

    cout << "Nivel 3. (Palabra Oculta)" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3 && vidas > 0; ++i) {
        do {
            barraDeVida(vidas);
            barra(respondidas);
            cout << "----------Pregunta " << i+1 << "---------" << endl;
            cout << preguntasNivel3[i] << endl;
            cin >> respuesta;

            system("cls");
            if (respuesta != respuestasNivel3[i]) vidas--;
        } while (respuesta != respuestasNivel3[i] && vidas > 0);

        if (vidas > 0) respondidas++;
    }

    gano = vidas > 0;
    return gano;
}

// Funcion para el nivel 4
bool nivel4() {
    string preguntasNivel4[3] = {
        "Reordena las letras para obtener una palabra: FFULY",
        "Reordena las letras para obtener una palabra: OROZ",
        "Reordena las letras para obtener una palabra: MINA"
    };
    string respuestasNivel4[3] = {"luffy", "zoro", "nami"};
    int vidas = 5, respondidas = 9;
    bool gano = false;
    string respuesta;

    cout << "Nivel 4. (Rompecabezas de letras)" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3 && vidas > 0; ++i) {
        do {
            barraDeVida(vidas);
            barra(respondidas);
            cout << "----------Pregunta " << i+1 << "---------" << endl;
            cout << preguntasNivel4[i] << endl;
            cin >> respuesta;
            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::tolower);
            system("cls");
            if (respuesta != respuestasNivel4[i]) vidas--;
        } while (respuesta != respuestasNivel4[i] && vidas > 0);

        if (vidas > 0) respondidas++;
    }

    gano = vidas > 0;
    return gano;
}

// Funcion para el nivel 5
bool nivel5() {
    string preguntasNivel5[3] = {
        "· · ·   +    ----",
        "¿Cuál es el resultado de la siguiente operación?:",
        " ·     *    · · ·"
    };
    int respuestasNivel5[3] = {8, -20, 3};
    int vidas = 5, respondidas = 12;
    bool gano = false;
    int respuesta;

    cout << "Nivel 5. (Operaciones con numeros mayas)" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3 && vidas > 0; ++i) {
        do {
            barraDeVida(vidas);
            barra(respondidas);
            cout << "----------Pregunta " << i+1 << "---------" << endl;
            cout << preguntasNivel5[i] << endl;
            cin >> respuesta;
            system("cls");
            if (respuesta != respuestasNivel5[i]) vidas--;
        } while (respuesta != respuestasNivel5[i] && vidas > 0);

        if (vidas > 0) respondidas++;
    }

    gano = vidas > 0;
    if (gano){
        hasGanado();
    }
    return gano;
}

// Funcion para mostrar la barra de vida
void barraDeVida(int vidas) {
    cout << "Vidas: ";
    for (int i = 0; i < vidas; i++) {
        cout << "<3 ";
    }
    for (int i = vidas; i < 5; i++) {
        cout << "<> ";
    }
    cout << endl;
}

// Funcion para mostrar el progreso del jugador
void barra(int respondidas) {
    int avanze = (respondidas / 15.0) * 100;
    string progreso[3][5];

    cout << "Progreso del jugador: " << avanze << "%" << endl;
    cout << "------Mapa------" << endl;
    cout << " 1  2  3  4  5" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (respondidas >= (i * 3 + j + 1)) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
}

// Mensaje de reintentar
void textoReintente() {
    cout << "Juego Terminado, vuelve a intentarlo mas tarde!" << endl;
}

// Funcion principal de juego
void jugar() {
    bool gano = false;
    gano = nivel1();
    if (gano) gano = nivel2();
    if (gano) gano = nivel3();
    if (gano) gano = nivel4();
    if (gano) gano = nivel5();
    if (!gano) {
        textoReintente();
    }
}

// Mensaje de victoria
void hasGanado() {
    cout << "Felicitaciones has completado todos los niveles y ganado el juego!" << endl;
}

