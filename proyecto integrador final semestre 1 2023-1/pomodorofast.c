#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void pomodoro1(int tiempo, int r, int sesion);
int repeticiones1(int tiempo, int sesion);
int repeticiones2(int tiempo, int sesion);

void pomodoroF() {
    int tiempo, r, sesion;
    printf("\t\tTemporizador pomodoro.\n\n");
    printf("En este apartado, puedes iniciar una sesion de pomodoro rapidamente.\n");
    printf("Para ello, ingresa el tiempo disponible que tengas en minutos: ");
    scanf("%d", &tiempo);
    system("cls"); // Limpiar pantalla

    // Llamamos a la funcion que nos dira las dos formas de pomodoro que podemos hacer segun el tiempo:
    printf("Que sesion deseas?:\n\n\n");

    printf("\t1. Pomodoro 25 minutos de concentracion 5 de descanso:\n\n");
    printf("\tUno de los mas utilizados. 25 minutos es un tiempo de concentracion nada despreciable\n");
    printf("\ty en 5 minutos el cerebro descansa mas que de sobra.\n\n\n");

    printf("\t2. Pomodoro 50 minutos de concentracion 10 de descanso:\n\n");
    printf("\tSe trata de uno de los Pomodoros mas completos. En 50 minutos da tiempo a estudiar y \n");
    printf("\trepasar varios epigrafes y 10 minutos son mas que suficientes para resetear y volver con fuerzas. \n\n\n\n");

    printf("Escoge aqui: ");
    scanf("%d", &sesion);

    if (sesion == 1) {
        r = repeticiones1(tiempo, sesion);
    } else {
        r = repeticiones2(tiempo, sesion);
    }

    system("cls");
    printf("Presione  enter para generar reloj.");
    getchar();
    getchar();

    // Llamamos a la funcion de pomodoro
    pomodoro1(tiempo, r, sesion);
}

int repeticiones1(int tiempo, int sesion) {
    int trabajo, descanso, r, sobrante;
    // Para 25 / 5
    trabajo = 24; // Duracion del trabajo en minutos menos uno para que no inicie el pomodoro en 25:59
    descanso = 4; // Duracion del descanso en minutos igual que lo anterior
    r = tiempo / (trabajo + 1 + descanso + 1); // Formula para calcular el numero de repeticiones que se realizaron
    sobrante = tiempo - (r * 30);
    printf("\nNumero de repeticiones: %d. Te sobran %d minutos.\n", r, sobrante);
    Sleep(2000); // Pausa de 2 segundos
    return r;
}

int repeticiones2(int tiempo, int sesion) {
    int trabajo, descanso, r, sobrante;
    trabajo = 49; // Duracion del trabajo en minutos menos uno para que no inicie el pomodoro en 50:59
    descanso = 9; // Duracio del descanso en minutos igual que lo anterior
    r = tiempo / (trabajo + 1 + descanso + 1); // Formula para calcular el numero de repeticiones que se realizaron
    sobrante = tiempo - (r * 60);
    printf("\nNumero de repeticiones: %d. Te sobran %d minutos que los puedes volver a ingresar cuando hayas acabado la sesion.\n", r, sobrante);
    Sleep(2000); // Pausa de 2 segundos
    return r;
}

void pomodoro1(int tiempo, int r, int sesion) {
    int trabajo, descanso;
    if (sesion == 1) {
        trabajo = 24;
        descanso = 4;
    } else {
        trabajo = 49;
        descanso = 9;
    }

    for (int i = 0; i < r; i++) {
        int min = trabajo;
        int seg = 59; // Iniciar desde 59 segundos

        // Trabajo
        for (min = trabajo; min >= 0; min--) {
            for (seg = 59; seg >= 0; seg--) {
                system("cls"); // Borra la pantalla en Windows
                printf("Tiempo de trabajo \n %02d:%02d\n", min, seg);

                // Verificar si se ha presionado Enter para pausar el pomodoro
                if (kbhit()) {
                    getchar(); // Consumir el caracter presionado (Enter)
                    system("cls"); // Borra la pantalla en Windows
                    printf("Pomodoro pausado. Opciones:\n");
                    printf("1. Continuar\n");
                    printf("2. Reiniciar\n");
                    printf("3. Salir\n");

                    int opcion;
                    scanf("%d", &opcion);

                    if (opcion == 1) {
                        system("cls"); // Borra la pantalla en Windows
                    } else if (opcion == 2) {
                        system("cls"); // Borra la pantalla en Windows
                        min = trabajo + 1; // Reiniciar el contador del trabajo
                        break;
                    } else if (opcion == 3) {
                        system("cls"); // Borra la pantalla en Windows
                        printf("Pomodoro finalizado.\n");
                        return; // Salir del pomodoro
                    }
                }

                Sleep(1000); // Pausa de 1 segundo
            }

            if (min == 0) {
                system("cls"); // Borra la pantalla en Windows
            }
        }

        // Descanso
        min = descanso;
        seg = 59; // Iniciar desde 59 segundos

        for (min = descanso; min >= 0; min--) {
            for (seg = 59; seg >= 0; seg--) {
                system("cls"); // Borra la pantalla en Windows
                printf("Tiempo de descanso:\n %02d:%02d\n", min, seg);

                // Verificar si se ha presionado Enter para pausar el pomodoro
                if (kbhit()) {
                    getchar(); // Consumir el caracter presionado (Enter)
                    system("cls"); // Borra la pantalla en Windows
                    printf("Pomodoro pausado. Opciones:\n");
                    printf("1. Continuar\n");
                    printf("2. Reiniciar\n");
                    printf("3. Salir\n");

                    int opcion;
                    scanf("%d", &opcion);

                    if (opcion == 1) {
                        system("cls"); // Borra la pantalla en Windows
                    } else if (opcion == 2) {
                        system("cls"); // Borra la pantalla en Windows
                        min = descanso + 1; // Reiniciar el contador del descanso
                        break;
                    } else if (opcion == 3) {
                        system("cls"); // Borra la pantalla en Windows
                        printf("Pomodoro finalizado.\n");
                        return; // Salir del pomodoro
                    }
                }

                Sleep(1000); // Pausa de 1 segundo
            }

            if (min == 0) {
                system("cls"); // Borra la pantalla en Windows
            }
        }
    }
}
