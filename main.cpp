#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // Para usar sleep
#include <algorithm> // Para usar transform (en minusculas)
#include <fstream> // Para utilizar archivos


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
void historial();


using namespace std;

int main() {
    pantallaPrincipal();
    return 0;
}

// Carga de pantalla principal del juego
void pantallaPrincipal() {
    int tiempo = 0;
    int carga;

    //animacion de carga
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
        cout << "2. Historial" << endl;
        cout << "3. Salir" << endl;
        cin >> opc;

        switch(opc) {
            case 1:
                system("cls");
                jugar();
                break;
            case 2:
                historial();
                break;
            default:
                opc = 3;
                break;
        }
    } while (opc != 3);
}

// Funcion para el nivel 1
bool nivel1() {

    string preguntasNivel1[3] = { "Soy un numero par, divideme por 2 y el resultado es 18", "Soy un numero mayor que 10, si me restas 4, el resultado es 8",
                                  "Soy un numero impar, si me sumas 9 y luego lo divides entre 2, obtienes 17" };

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

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            progreso[j][i] = " - ";
        }

    }
    progreso[2][4] = " -> Salida ";

    if (respondidas > 0 && respondidas <= 3){
        for (int i = 0; i < 3; i++)
        {
            progreso[respondidas-1][0]=" Tu";
        }

    }
    if (respondidas > 3 && respondidas <= 6){
        int respondidas1 = respondidas -3;
        for (int i = 0; i < respondidas1; i++)
        {
            progreso[respondidas1-1][1]=" Tu";
        }

    }
    if (respondidas > 6 && respondidas <= 9){
        int respondidas2 = respondidas -6;
        for (int i = 0; i < respondidas2; i++)
        {
            progreso[respondidas2-1][2]=" Tu";
        }

    }
    if (respondidas > 9 && respondidas <= 12){
        int respondidas3 = respondidas -9;
        for (int i = 0; i < respondidas3; i++)
        {
            progreso[respondidas3-1][3]=" Tu";
        }

    }
    if (respondidas > 12){
        int respondidas4 = respondidas -12;
        for (int i = 0; i < respondidas4; i++)
        {
            progreso[respondidas4-1][4]=" Tu";
        }

    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<progreso[i][j];
        }
        cout<<""<<endl;
    }



}

// Funcion para mostrar el mensaje de reintentar
void textoReintente() {
    int tiempo = 1;



    do
    {
        cout << "----------////////_/----------" << endl;
        cout << "--------------GAME OVER---------------" << endl;
        cout << "----------INTENTE OTRA VEZ------------" << endl;
        cout << "----------////////_/----------" << endl;
        cout << "Cargando...." << endl;
        sleep(1);
        system("cls");
        cout << "----------/////////_/----------"<< endl;
        cout << "--------------GAME OVER---------------" << endl;
        cout << "----------INTENTE OTRA VEZ------------" << endl;
        cout << "----------/////////_/----------" << endl;
        cout << "Cargando......" << endl;
        sleep(1);
        system("cls");
        tiempo += 1;
    } while (tiempo == 5);
}

//Funcion para comprobar si gano
void hasGanado() {
    int tiempo = 1;

    do
    {
        cout << "----------////////_/----------" << endl;
        cout << "--------------Has ganado---------------" << endl;
        cout << "----------Felicidades!!!!!------------" << endl;
        cout << "----------////////_/----------" << endl;
        cout << "Cargando...." << endl;
        sleep(1);
        system("cls");
        cout << "----------/////////_/----------"<< endl;
        cout << "--------------Has ganado---------------" << endl;
        cout << "----------Felicidades!!!!------------" << endl;
        cout << "----------/////////_/----------" << endl;
        cout << "Cargando......" << endl;
        sleep(1);
        system("cls");
        tiempo += 1;
    } while (tiempo == 5);



}

//Funcion para guardar en el archivo
void guardarJugador(string nombre, int nivel) {
    fstream historial;
    historial.open("baseJugadores.txt", ios::app);

    historial << nombre << " - " << nivel << endl;
    historial.close();
}

// Funcion que gestiona los niveles del juego
void jugar() {
    int nivel = 1;
    bool gano = false;
    string nombre;

    cout << "Ingresa tu nombre" << endl;
    cin >> nombre;
    system("cls");

    do {
        switch (nivel) {
            case 1:
                gano = nivel1();
                break;
            case 2:
                gano = nivel2();
                break;
            case 3:
                gano = nivel3();
                break;
            case 4:
                gano = nivel4();
                break;
            case 5:
                gano = nivel5();
                break;
        }
        if (gano) {
            nivel++;
        } else {
            textoReintente();
            string respuesta;
            cout << "Quieres reintentar? si/no" << endl;
            cin >> respuesta;
            if (respuesta == "si") {
                system("cls");
            } else {

                guardarJugador(nombre, nivel);
                nivel = 6;
            }
        }
    } while (nivel <= 5);
}

void historial() {
    fstream historial;
    historial.open("baseJugadores.txt", ios::in);

    //Si no hay un registro previo
    if(historial.fail()) {
        cout << "No hay ningun historial" << endl;
        historial.close();

        //Por si hay un archivo existente
    }else {
        string texto;
        while(!historial.eof()) {
            getline(historial, texto);
            cout << texto << endl;
        }

        historial.close(); // Cerrar el archivo manualmente
    }

}