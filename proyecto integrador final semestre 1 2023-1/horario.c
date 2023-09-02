#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void llenar(char materias[5][35], int horas[5][7]); //funcion para llenar materias y horas
void guardar(char materias[5][35], int horas[5][7]); //funcion para guardar los datos en un archivo txt
void leer (char materias[5][35], int horas[5][7]); //funcion para leer el txt
void ingresar_horas(int horas[5][7], int dia, int i); //funcion para ingresar horas
void pomodoroH(char materias[5][35], int horas[5][7]); //funcion pomodoro
void tabla(char materias[5][35], int horas[5][7]);
void waitForEnter(); //funcion presione enter para continuar
void iraxy(int x, int y);

void horario()
{
    char materias[5][35], letra;
    int horas[5][7], i;

    printf("\t\t\t----Horario academico---- \n\n");
    printf("En este apartado, debes ingresar las materias que tienes disponibles\n");
    printf("y asignarle a cada dia el tiempo que tengas destinado a dicha materia.\n\n");
    //preguntamos si desea caragar un horario ya definido
    printf("Tienes un horario ya definido? s/n: ");
    scanf("%c",&letra);
    if(letra == 's' || letra == 'S'){
        leer(materias, horas); //llamamos a la funcion que nos leerá los datos del txt
    }
    else{
        waitForEnter();
        system("cls");
        printf("Cargando.");
        Sleep(200);
        llenar(materias, horas);
        guardar(materias,horas);
        system("cls");
        printf("Cargando..");
        system("cls");
    }
    printf("Generando tabla...");
    system("cls");
    tabla(materias, horas);
    system("pause");
    pomodoroH(materias, horas);
    return 0;
}

void llenar(char materias[5][35], int horas[5][7])
{
    int i, dia;
    for (i = 0; i < 5; i++)
    {
        system("cls");
        printf("Ingresa la materia: ");
        fgets(materias[i], 35, stdin);
        for (dia = 0; dia < 7; dia++)
        {
            ingresar_horas(horas, dia, i);
        }
    }
}

void ingresar_horas(int horas[5][7], int dia, int i)
{
    char nombre_dia[15];
    switch (dia)
    {
    case 0:
        strcpy(nombre_dia, "lunes");
        break;

    case 1:
        strcpy(nombre_dia, "martes");
        break;

    case 2:
        strcpy(nombre_dia, "miercoles");
        break;

    case 3:
        strcpy(nombre_dia, "jueves");
        break;

    case 4:
        strcpy(nombre_dia, "viernes");
        break;

    case 5:
        strcpy(nombre_dia, "sabado");
        break;

    case 6:
        strcpy(nombre_dia, "domingo");
        break;
    }
    printf("Horas para el dia %s: ", nombre_dia);
    scanf("%d", &horas[i][dia]);
    fflush(stdin);
}

//funcion para guardar las matrices en un archivo txt
void guardar(char materias[5][35], int horas[5][7]){
    int i, j;
    FILE *archivo = fopen("horario.txt", "w");
    for(i=0; i<5; i++){
        fprintf(archivo,"%s", materias[i]);
        for(j=0; j<7; j++){
            fprintf(archivo, "%d\n",horas[i][j]);
        }
    }
    fclose(archivo);

}
//funcion para leer los datos del txt
void leer (char materias[5][35], int horas[5][7])
{
    int i, j;
    char linea[35];
    FILE *archivo = fopen("horario.txt", "r");
    if (archivo == NULL){
        printf("Error al abrir el archivo txt");
        return;
    }
    for(i=0; i<5; i++){
        fgets(linea,35,archivo); //leo las lines de mi documento y obtengo de ahi su informacion
        sscanf(linea, "%[^\n]", materias[i]);

        for(j=0; j<7; j++){
            fgets(linea,35,archivo);
            sscanf(linea, "%d", &horas[i][j]);
        }
    }
    fclose(archivo);

}
void tabla(char materias[5][35], int horas[5][7])
{
    int a, b, c, d, x, y;
    x = 1;
    y = 1;
    for (a = 1; a <= 6; a++)
    {
        iraxy(x, y);
        printf("%c", 179);
        iraxy(x + 30, y);
        printf("%c", 179);
        y += 2;
        Sleep(10);
    }

    for (b = 0; b <= 12; b += 2)
    {
        for (c = 2; c <= 30; c++)
        {
            iraxy(c, b);
            printf("%c", 196);
        }
    }

    x = 41;
    y = 1;
    for (a = 1; a <= 6; a++)
    {
        iraxy(x, y);
        printf("%c", 179);
        iraxy(x + 11, y);
        printf("%c", 179);
        iraxy(x + 22, y);
        printf("%c", 179);
        iraxy(x + 33, y);
        printf("%c", 179);
        iraxy(x + 44, y);
        printf("%c", 179);
        iraxy(x + 55, y);
        printf("%c", 179);
        iraxy(x + 66, y);
        printf("%c", 179);
        y += 2;
    }

    for (b = 0; b <= 12; b += 2)
    {
        for (c = 2; c <= 106; c++)
        {
            iraxy(c, b);
            printf("%c", 196);
        }
    }

    x = 107;
    y = 2;
    for (a = 1; a <= 5; a++)
    {
        iraxy(x, y);
        printf("%c", 180);
        y += 2;
    }

    x = 1;
    y = 2;
    for (a = 1; a <= 5; a++)
    {
        iraxy(x, y);
        printf("%c", 195);
        iraxy(x + 30, y);
        printf("%c", 180);
        y += 2;
    }

    x = 1;
    y = 0;
    iraxy(x, y);
    printf("%c", 218);

    iraxy(x + 30, y);
    printf("%c", 191);

    iraxy(x, y + 12);
    printf("%c", 192);

    iraxy(x + 30, y + 12);
    printf("%c", 217);

    x = 107;
    y = 0;
    iraxy(x, y);
    printf("%c", 191);

    x = 107;
    y = 12;
    iraxy(x, y);
    printf("%c", 217);

    iraxy(13, 1);
    printf("Dia");
    iraxy(35, 1);
    printf("Lunes");
    iraxy(44, 1);
    printf("Martes");
    iraxy(53, 1);
    printf("Miercoles");
    iraxy(65, 1);
    printf("Jueves");
    iraxy(76, 1);
    printf("Viernes");
    iraxy(87, 1);
    printf("Sabado");
    iraxy(98, 1);
    printf("Domingo");

    a = 0;
    for (b = 3; b <= 12; b += 2)
    {
        iraxy(3, b);
        printf("%s", materias[a]);
        a++;
    }

    b = 0;
    for (y = 3; y <= 12; y += 2)
    {
        a = 0;
        for (x = 35; x <= 107; x += 11)
        {
            iraxy(x, y);
            printf("%d", horas[b][a]);
            a++;
        }
        b++;
    }

    iraxy(18,18);
}
void iraxy(int x, int y)
{
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor;
    cursor.X = x;
    cursor.Y = y;
    SetConsoleCursorPosition(consola, cursor);
}

void pomodoroH(char materias[5][35], int horas[5][7]){
    printf("\n\n\t\t---Temporizador pomodoro.---\n\n");
    printf("A continuacion, te organizamos el tiempo en el siguiente pomodoro:\n");
    printf("25 minutos de concentracion y 5 minutos de descanso.\n");

    int r,dia, m,tiempo;
    printf("\n\n Seleccione el dia actual:\n");
    printf("1. Lunes\n");
    printf("2. Martes\n");
    printf("3. Miercoles\n");
    printf("4. Jueves\n");
    printf("5. Viernes\n");
    printf("6. Sabado\n");
    printf("7. Domingo\n\n");
    printf("Ingrese el numero correspondiente al dia: ");
    scanf("%d", &r);

    //guardar el dia
    switch(r){
        case 1: dia=0;
                break;
        case 2: dia=1;
                break;
        case 3: dia=2;
                break;
        case 4: dia=3;
                break;
        case 5: dia=4;
                break;
        default: printf("opcion invalida\n");
    }

    system("cls");

    printf("Seleccione la materia inicial:\n");
    for (int i = 0; i <= 4; i++) {
        printf("%d. %s\n", i + 1, materias[i]);
    }
    printf("Ingrese el numero correspondiente a la materia: ");
    scanf("%d",&m);

    system("cls");

    switch(m){
        case 1:
            tiempo=horas[0][m-1]*60;
            break;
        case 2:
            tiempo=horas[1][m-1]*60;
            break;
        case 3:
            tiempo=horas[2][m-1]*60;
            break;
        case 4:
            tiempo=horas[3][m-1]*60;
            break;
        case 5:
            tiempo=horas[4][m-1]*60;
            break;
    }

    int trabajo = 24; // Duracion del trabajo en minutos menos uno para que no inicie el podomoroo en 25:59
    int descanso = 4; // Duracion del descanso en minutos igual que lo anterior
    int repeticiones = tiempo / (trabajo+1 + descanso+1); // Formula para calcular el numero de repeticiones que se realizaron

    printf("Numero de repeticiones: %d\n", repeticiones);
    waitForEnter();

    for (int i = 0; i < repeticiones; i++) {
        int min = trabajo;
        int seg = 59; // Iniciar desde 59 segundos

        // Trabajo

        for (min = trabajo; min >= 0; min--) {
            for (seg = 59; seg >= 0; seg--) {

                system("cls"); // Borra la pantalla en Windows
                printf("Tiempo de trabajo \n %02d:%02d\n", min, seg);

                // Verificar si se ha presionado Enter para pausar el podometro
                if (kbhit()) {
                    getchar(); // Consumir el caracter presionado (Enter)

                    system("cls"); // Borra la pantalla en Windows
                    printf("Podomoro pausado. Opciones:\n");
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

                        printf("Podomoro finalizado.\n");
                        return; // Salir del podomoro
                    }
                }

                sleep(1);
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

                // Verificar si se ha presionado Enter para pausar el podomoro
                if (kbhit()) {
                    getchar(); // Consumir el car cter presionado (Enter)
                    system("cls"); // Borra la pantalla en Windows

                    printf("Podomoro pausado. Opciones:\n");
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

                        printf("Podomoro finalizado.\n");
                        return; // Salir del pod metro
                    }
                }

                sleep(1);
            }

            if (min == 0) {

                system("cls"); // Borra la pantalla en Windows

            }
        }
    }
}

void waitForEnter() {
    printf("\nPresione Enter para continuar...");
    fflush(stdin);
    getchar();
}
