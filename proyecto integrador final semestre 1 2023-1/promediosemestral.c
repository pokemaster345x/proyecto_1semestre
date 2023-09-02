#include <stdio.h>
#include <conio.h>
#include <windows.h>

void promedio(){
    void waitForEnter();
    float prome,notaf[5],corte[5][3];//arreglo para guardar el promedio, su nota final y de cada corte
    char mate[5][30]; //guardar el nombre de la materia
    int cont,i,creditos[5],credit;

    printf("\t\t----Calculo Promedio Ponderado y Notas Finales----\n\n");
    printf("\n En este apartado te proporcionaremos una herramienta para encontrar tu nota final de cada materia");
    printf("\n y promedio ponderado segun la formula dada en el articulo 80 del manual del estudiante de la UCEVA\n");

    waitForEnter();
    system ("cls");

    printf("A continuacion vamos a calcular tu nota final de cada materia vista en el semestre\n\n");

    for (int cont = 0; cont < 5; cont++) {
        printf("Ingrese el nombre de la materia:\n");
        scanf("%s", mate[cont]);
        for (int i = 0; i < 3; i++) {
        printf("Ingrese la nota del corte #%d de la materia %s:\n", i + 1, mate[cont]);
        scanf("%f", &corte[cont][i]);
        }
    }

            system("cls");

     for(cont = 0; cont < 5; cont++) {
        float notafinal = 0.3 * (corte[cont][0] + corte[cont][1]) + 0.4 * corte[cont][2];
        notaf[cont] = notafinal;
        printf("La nota final de la materia %s es: %.2f\n", mate[cont], notafinal);
    }

    waitForEnter(); //agrega lo de  presiona enter para continuar y quita el sleep
    system("cls");


    printf("Ahora calcularemos tu promedio ponderado\n\n");
    printf("la formula para obtener esto nos lo proporciona el articulo 80 del manual del estudiante, el cual dice que:  \"se multiplica\n");
    printf("la nota definitiva de cada asignatura por el numero de creditos academicos de la misma. Se suma los productos resultantes\n");
    printf("y se divide la suma anterior entre el total de creditos academicos de la asignacion academica matriculada por el estudiante\"\n\n");

    waitForEnter(); //agrega lo de  presiona enter para continuar y quita el sleep
    system("cls");

    for(i=0;i<5;i++){
        printf("\nIngrese el numero de creditos de la materia: %s\n",mate[i]);
        scanf("%d",&creditos[i]);
    }
    credit=0;
    prome=0;
    for(cont=0;cont<5;cont++){
        prome=prome+(notaf[cont]*creditos[cont]); //calcular la sumatoria de la multiplicacion de los cada materia
    }                                             //por su cantidad de creditos

    for(cont=0;cont<5;cont++){
     credit=credit+creditos[cont];
    }
    prome=prome/credit;
    printf("El promedio semestral es: %.2f",prome);
    waitForEnter();
    system("cls");
}
