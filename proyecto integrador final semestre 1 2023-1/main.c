#include <stdio.h> //predeterminada
#include <stdlib.h> //predeterminada
#include <conio.h> // leer caracteres sin mostrarlos en pantalla
#include <windows.h> //Manipulacion de pantalla
#include <string.h> //predeterminada
#define OPCIONES 4 //definir constantes
void horario(); //funcion para generar un horario al usuario
void pomodoroF(); //funcion para realizar la tecnica de podmoro
void promedio(); //funcion para encontrar las notas finales y el promedio ponderado semestral
/*
        Titulo:  Proyecto Integrador
        Semestre: 1
        Autores:                        Codigo:
        JUAN ESTEVAN SANTIAGO HOLGUIN   230231009
        SEBASTIAN MORALES FLOREZ        230231002
        SAMUEL ALEJANDRO RINCON SERNA   230231045
        DANIELA GUTIERREZ GALLEGO       230231001
        SANTIAGO GARCÍA GRANDA          230231008
*/

// Funcion para dibujar el menu
void dibujarMenu(int opcion)
{
    system("cls"); // Limpiar la pantalla

    printf("==== Menu ====\n");
    printf("%c Horario\n", opcion == 1 ? '>' : ' ');
    printf("%c Pomodoro\n", opcion == 2 ? '>' : ' ');
    printf("%c Promedio Ponderado\n", opcion == 3 ? '>' : ' ');
    printf("%c Salir\n", opcion == 4 ? '>' : ' ');
}

int main()
{
    int opcion = 1;
    int tecla;

    // Dibujar el menu inicial
    dibujarMenu(opcion);

    while (1)
    {
        tecla = getch(); // Leer una tecla

        // Manejar las teclas de flecha
        switch (tecla)
        {
            case 72: // Flecha arriba
                opcion--;
                if (opcion < 1)
                    opcion = OPCIONES;
                break;
            case 80: // Flecha abajo
                opcion++;
                if (opcion > OPCIONES)
                    opcion = 1;
                break;
            case 13: // Tecla Enter
                // Ejecutar la opcion seleccionada
                switch (opcion)
                {
                    case 1:
                        // Llamar a la funcion para manejar la opcion horario
                        horario();
                        break;
                    case 2:
                        // Llamar a la funcion para manejar la opcion pomodoro
                        pomodoroF();
                        break;
                    case 3:
                        // Llamar a la funcion para manejar la opcion 3
                        promedio();
                        break;
                    case 4:
                        // Salir del programa
                        printf("Saliendo del programa...\n");
                        return 0;
                }
                break;
        }

        // Volver a dibujar el menu con la opcion seleccionada resaltada
        dibujarMenu(opcion);
    }

    return 0;
}
