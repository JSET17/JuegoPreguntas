#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opc;
int cantData = 0;
char input[10];

struct data {
    char user[30];
    char password[15];
};

struct data db[100];

void init();
void registration();
void access();
void game();

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
    fgets(db[cantData].user, 30, stdin);
    db[cantData].user[strcspn(db[cantData].user, "\n")] = '\0';

    fflush(stdin);
    printf("Password: ");
    fgets(db[cantData].password, 15, stdin);
    db[cantData].password[strcspn(db[cantData].password, "\n")] = '\0';

    cantData++;

    system("cls");
    printf("\nSuccessful registration.\n\n");
    system("pause");
}

void access() {
    int validUser = 0;
    int validPasword = 0;
    char userAccess[30];
    char passwordAccess[15];

    if(cantData > 0) {
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

        for(int i = 0; i < cantData; i++) {
            if(strcmp(userAccess, db[i].user) == 0) {
                validUser = 1;
            } else {
                validUser = 0;
            }

            if(strcmp(passwordAccess, db[i].password) == 0) {
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
    system("cls");
    printf("\nDeveloping.\n\n");
    system("pause");
}
