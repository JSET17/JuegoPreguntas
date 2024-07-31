#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opc;
int cantdataUser = 0;
char input[10];

struct dataUser {
    char user[30];
    char password[15];
};

struct dataUser dbUsers[100];

struct pregunta {
    char pregunta[50];
    char respuesta1[50];
    char respuesta2[50];
    char respuesta3[50];
    char respuesta4[50];
};

struct pregunta pregunta1, pregunta2, pregunta3, pregunta4, pregunta5;

void init();
void registration();
void access();
void game();

void ask1();
void ask2();
void ask3();
void ask4();
void ask5();

int main() {
    init();
    return 0;
}

void init() {
    while(opc != 3) {
        system("cls");
        printf("-----Questions Game-----\n\n");
        printf("1. Play.\n");
        printf("2. Registration.\n");
        printf("3. Exit.\n\n");

        printf("Choose an option: ");
        fgets(input, sizeof(input), stdin);
        opc = atoi(input);

        switch(opc) {
            case 1:
                access();
                break;
            case 2:
                registration();
                break;
            case 3:
                system("cls");
                printf("\nThanks for playing.\n\n");
                system("pause");
                break;
            default:
                system("cls");
                printf("\nInvalid option.\n\n");
                system("pause");
        }
    }
}

void registration() {
    system("cls");
    printf("-----registration-----\n\n");

    fflush(stdin);
    printf("User: ");
    fgets(dbUsers[cantdataUser].user, 30, stdin);
    dbUsers[cantdataUser].user[strcspn(dbUsers[cantdataUser].user, "\n")] = '\0';

    fflush(stdin);
    printf("Password: ");
    fgets(dbUsers[cantdataUser].password, 15, stdin);
    dbUsers[cantdataUser].password[strcspn(dbUsers[cantdataUser].password, "\n")] = '\0';

    cantdataUser++;

    system("cls");
    printf("\nSuccessful registration.\n\n");
    system("pause");
}

void access() {
    int validUser = 0;
    int validPasword = 0;
    char userAccess[30];
    char passwordAccess[15];

    if(cantdataUser > 0) {
        system("cls");
        printf("-----Access-----\n\n");

        fflush(stdin);
        printf("User: ");
        fgets(userAccess, 30, stdin);
        userAccess[strcspn(userAccess, "\n")] = '\0';

        fflush(stdin);
        printf("Password: ");
        fgets(passwordAccess, 15, stdin);
        passwordAccess[strcspn(passwordAccess, "\n")] = '\0';

        for(int i = 0; i < cantdataUser; i++) {
            if(strcmp(userAccess, dbUsers[i].user) == 0) {
                validUser = 1;
            } else {
                validUser = 0;
            }

            if(strcmp(passwordAccess, dbUsers[i].password) == 0) {
                validPasword = 1;
            } else {
                validPasword = 0;
            }

            if(validUser == 1 && validPasword == 1) {
                system("cls");
                printf("\nSuccessful login.\n\n");
                system("pause");

                game();
            } else {
                system("cls");
                printf("\nIncorrect credentials.\n\n");
                system("pause");
            }
        }
    } else {
        system("cls");
        printf("\nNo users created.\n\n");
        system("pause");
    }
}

void game() {

    char answer[10];

    ask1();
    printf("Elige una opcion: ");
    fgets(answer, 10, stdin);
    answer[strcspn(answer, "\n")] = '\0';

    if(strcmp(answer, "a") == 0) {
        printf("\n\nRespuesta incorrecta.\n\nNo ganaste ningun premio.\n\n");
        system("pause");
    }

    if(strcmp(answer, "b") == 0) {

        ask2();
        printf("Elige una opcion: ");
        fgets(answer, 10, stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if(strcmp(answer, "a") == 0) {
            printf("\n\nRespuesta incorrecta.\n\nGanaste $1.000 pesos.\n\n");
            system("pause");
        }

        if(strcmp(answer, "b") == 0) {
            printf("\n\nRespuesta incorrecta.\n\nGanaste $1.000 pesos.\n\n");
            system("pause");
        }

        if(strcmp(answer, "c") == 0) {

            ask3();
            printf("Elige una opcion: ");
            fgets(answer, 10, stdin);
            answer[strcspn(answer, "\n")] = '\0';

            if(strcmp(answer, "a") == 0) {
                printf("\n\nRespuesta incorrecta.\n\nGanaste $2.000 pesos.\n\n");
                system("pause");
            }

            if(strcmp(answer, "b") == 0) {
                printf("\n\nRespuesta incorrecta.\n\nGanaste $2.000 pesos.\n\n");
                system("pause");
            }

            if(strcmp(answer, "c") == 0) {

                ask4();
                printf("Elige una opcion: ");
                fgets(answer, 10, stdin);
                answer[strcspn(answer, "\n")] = '\0';

                if(strcmp(answer, "a") == 0) {
                    printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                    system("pause");
                }

                if(strcmp(answer, "b") == 0) {
                    printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                    system("pause");
                }

                if(strcmp(answer, "c") == 0) {
                    printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                    system("pause");
                }

                if(strcmp(answer, "d") == 0) {

                    ask5();
                    printf("Elige una opcion: ");
                    fgets(answer, 10, stdin);
                    answer[strcspn(answer, "\n")] = '\0';

                    if(strcmp(answer, "a") == 0) {
                        printf("\n\nRespuesta correcta.\n\nHas ganado el premio maximo.\n");
                        printf("Felicidades ganaste $20.000.\n\n");
                        system("pause");
                    }

                    if(strcmp(answer, "b") == 0) {
                        printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                        system("pause");
                    }

                    if(strcmp(answer, "c") == 0) {
                        printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                        system("pause");
                    }

                    if(strcmp(answer, "d") == 0) {
                        printf("\n\nRespuesta incorrecta.\n\nGanaste $5.000 pesos.\n\n");
                        system("pause");
                    }
                }
            }

            if(strcmp(answer, "d") == 0) {
                printf("\n\nRespuesta incorrecta.\n\nGanaste $2.000 pesos.\n\n");
                system("pause");
            }
        }

        if(strcmp(answer, "d") == 0) {
            printf("\n\nRespuesta incorrecta.\n\nGanaste $1.000 pesos.\n\n");
            system("pause");
        }
    }

    if(strcmp(answer, "c") == 0) {
        printf("\n\nRespuesta incorrecta.\n\nNo ganaste ningun premio.\n\n");
        system("pause");
    }

    if(strcmp(answer, "d") == 0) {
        printf("\n\nRespuesta incorrecta.\n\nNo ganaste ningun premio.\n\n");
        system("pause");
    }
}

void ask1(){
    strcpy(pregunta1.pregunta, "1. Que es POO.");
    strcpy(pregunta1.respuesta1, "A. Programacion orientada a eventos.");
    strcpy(pregunta1.respuesta2, "B. Programacion orientada a objetos.");
    strcpy(pregunta1.respuesta3, "C. Lenguaje de programacion.");
    strcpy(pregunta1.respuesta4, "D. Una base de datos.");

    system("cls");
    printf("Por $1.000 pesos.\n");
    printf("\n%s\n\n", pregunta1.pregunta);
    printf("%s", pregunta1.respuesta1);
    printf("\n%s", pregunta1.respuesta2);
    printf("\n%s", pregunta1.respuesta3);
    printf("\n%s\n\n", pregunta1.respuesta4);
}

void ask2(){
    strcpy(pregunta2.pregunta, "2. Cuanto es 7 por 6.");
    strcpy(pregunta2.respuesta1, "A. 48.");
    strcpy(pregunta2.respuesta2, "B. 59.");
    strcpy(pregunta2.respuesta3, "C. 42.");
    strcpy(pregunta2.respuesta4, "D. 46.");

    printf("\n\nRespuesta correcta.\n\n");
    system("pause");
    system("cls");
    printf("Por $2.000 pesos.\n");
    printf("\n%s\n\n", pregunta2.pregunta);
    printf("%s", pregunta2.respuesta1);
    printf("\n%s", pregunta2.respuesta2);
    printf("\n%s", pregunta2.respuesta3);
    printf("\n%s\n\n", pregunta2.respuesta4);
}

void ask3(){
    strcpy(pregunta3.pregunta, "3. Cual de estos no es un pais.");
    strcpy(pregunta3.respuesta1, "A. Lituania.");
    strcpy(pregunta3.respuesta2, "B. Armenia.");
    strcpy(pregunta3.respuesta3, "C. Birmingham.");
    strcpy(pregunta3.respuesta4, "D. Singapur.");

    printf("\n\nRespuesta correcta.\n\n");
    system("pause");
    system("cls");
    printf("Por $5.000 pesos.\n");
    printf("\n%s\n\n", pregunta3.pregunta);
    printf("%s", pregunta3.respuesta1);
    printf("\n%s", pregunta3.respuesta2);
    printf("\n%s", pregunta3.respuesta3);
    printf("\n%s\n\n", pregunta3.respuesta4);
}

void ask4(){
    strcpy(pregunta4.pregunta, "4. Simbolo quimico del oro.");
    strcpy(pregunta4.respuesta1, "A. B.");
    strcpy(pregunta4.respuesta2, "B. K.");
    strcpy(pregunta4.respuesta3, "C. Og.");
    strcpy(pregunta4.respuesta4, "D. Au.");

    printf("\n\nRespuesta correcta.\n\n");
    system("pause");
    system("cls");
    printf("Por $10.000 pesos.\n");
    printf("\n%s\n\n", pregunta4.pregunta);
    printf("%s", pregunta4.respuesta1);
    printf("\n%s", pregunta4.respuesta2);
    printf("\n%s", pregunta4.respuesta3);
    printf("\n%s\n\n", pregunta4.respuesta4);
}

void ask5(){
    strcpy(pregunta5.pregunta, "5. Quien fue Nikola Tesla.");
    strcpy(pregunta5.respuesta1, "A. Ingeniero electrico y mecanico.");
    strcpy(pregunta5.respuesta2, "B. Fisico.");
    strcpy(pregunta5.respuesta3, "C. Filosofo.");
    strcpy(pregunta5.respuesta4, "D. Matematico.");

    printf("\n\nRespuesta correcta.\n\n");
    system("pause");
    system("cls");
    printf("Por $20.000 pesos.\n");
    printf("\n%s\n\n", pregunta5.pregunta);
    printf("%s", pregunta5.respuesta1);
    printf("\n%s", pregunta5.respuesta2);
    printf("\n%s", pregunta5.respuesta3);
    printf("\n%s\n\n", pregunta5.respuesta4);
}
