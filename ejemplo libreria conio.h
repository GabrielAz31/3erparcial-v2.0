#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h> 

using namespace std;


enum ConsoleColor {
    Negro = 0,
    Azul = 1,
    Verde = 2,
    Cian = 3,
    Rojo = 4,
    Magenta = 5,
    Marron = 6,
    GrisClaro = 7,
    GrisOscuro = 8,
    AzulClaro = 9,
    VerdeClaro = 10,
    CianClaro = 11,
    RojoClaro = 12,
    MagentaClaro = 13,
    Amarillo = 14,
    Blanco = 15
};
void setColor(ConsoleColor texto, ConsoleColor fondo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((fondo << 4) | texto));
}

#ifndef M_PI
#define M_PI 3.1416
#endif

int main() {
    while (true) {
        int opcion = 1;
        double area;
        bool seleccionado = false;

        while (!seleccionado) {
            system("cls");

            
            setColor(Blanco, Negro);

            cout << "Seleccione una figura para calcular el área:" << endl;
            cout << (opcion == 1 ? "> " : "  ") << "1. Círculo" << endl;
            cout << (opcion == 2 ? "> " : "  ") << "2. Rectángulo" << endl;
            cout << (opcion == 3 ? "> " : "  ") << "3. Triángulo" << endl;
            cout << (opcion == 4 ? "> " : "  ") << "4. Cuadrado" << endl;
            cout << (opcion == 5 ? "> " : "  ") << "5. Salir" << endl;

            int tecla = _getch();

            if (tecla == 224) { 
                tecla = _getch();
                if (tecla == 72) { 
                    if (opcion > 1) {
                        opcion--;
                    }
                }
                else if (tecla == 80) {
                    if (opcion < 5) {
                        opcion++;
                    }
                }
            }
            else if (tecla == 13) { 
                seleccionado = true;
            }
        }

        system("cls");

        switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            area = M_PI * radio * radio;
            setColor(VerdeClaro, Negro); 
            cout << "El área del círculo es: " << area << endl;
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base del rectángulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectángulo: ";
            cin >> altura;
            area = base * altura;
            setColor(VerdeClaro, Negro); 
            cout << "El área del rectángulo es: " << area << endl;
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese la base del triángulo: ";
            cin >> base;
            cout << "Ingrese la altura del triángulo: ";
            cin >> altura;
            area = (base * altura) / 2;
            setColor(VerdeClaro, Negro); 
            cout << "El área del triángulo es: " << area << endl;
            break;
        }
        case 4: {
            double lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            area = lado * lado;
            setColor(VerdeClaro, Negro); 
            cout << "El área del cuadrado es: " << area << endl;
            break;
        }
        case 5:
            setColor(Blanco, Negro); 
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            setColor(RojoClaro, Negro); 
            cout << "Opción inválida. Por favor, seleccione una opción entre 1 y 5." << endl;
            break;
        }

        setColor(Amarillo, Negro); 
        cout << "Presione cualquier tecla para volver al menú..." << endl;
        _getch();
    }

    return 0;
}
