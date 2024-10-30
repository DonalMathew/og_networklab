/*
Nikhil Jojy
R7A_246
First and Follow
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char productions[10][10], first[10], follow[10], temp[10];


int contains(char result[], char ch) {
    for (int i = 0; i < strlen(result); i++) {
        if (result[i] == ch) {
            return 1; 
        }
    }
    return 0;
}


void findFirst(char ch, char result[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (productions[i][0] == ch) {
            if (!isupper(productions[i][2])) {
                if (!contains(result, productions[i][2])) {
                    strncat(result, &productions[i][2], 1);
                }
            } else {
                for (j = 0; j < n; j++) {
                    if (productions[j][0] == productions[i][2]) {
                        if (productions[j][2] == '#') {
                            if (!contains(result, '#')) {
                                strncat(result, "#", 1);
                            }
                        } else {
                            findFirst(productions[j][0], result);
                        }
                    }
                }
            }
        }
    }
}


void findFollow(char ch, char result[]) {
    int i, j, k;
    if (ch == productions[0][0]) {
        if (!contains(result, '$')) {
            strncat(result, "$", 1);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productions[i]); j++) {
            if (productions[i][j] == ch) {
                if (productions[i][j + 1] != '\0') {
                    if (!isupper(productions[i][j + 1])) {
                        if (!contains(result, productions[i][j + 1]) && productions[i][j + 1] != '#') {
                            strncat(result, &productions[i][j + 1], 1);
                        }
                    } else {
                        for (k = 0; k < n; k++) {
                            if (productions[k][0] == productions[i][j + 1]) {
                                if (productions[k][2] == '#') {
                                    findFollow(productions[i][0], result);
                                } else {
                                    findFirst(productions[k][0], temp);
                                    for (int l = 0; l < strlen(temp); l++) {
                                        if (temp[l] != '#' && !contains(result, temp[l])) {
                                            strncat(result, &temp[l], 1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (productions[i][0] != ch) {
                        findFollow(productions[i][0], result);
                    }
                }
            }
        }
    }
}

int main() {
    int i;
    char symbol;
    int choice = 1;

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    
    printf("Enter the productions (E.g., E=E+T):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }
    do{
        printf("Enter the symbol to find First and Follow: ");
        scanf(" %c", &symbol);

        
        memset(first, 0, sizeof(first));
        memset(follow, 0, sizeof(follow));
        memset(temp, 0, sizeof(temp));

        
        findFirst(symbol, first);
        findFollow(symbol, follow);

        
        printf("\nFirst(%c) = { ", symbol);
        for (i = 0; i < strlen(first); i++) {
            printf("%c, ", first[i]);
        }
        printf("}\n");

        printf("Follow(%c) = { ", symbol);
        for (i = 0; i < strlen(follow); i++) {
            printf("%c, ", follow[i]);
        }
        printf("}\n");
        printf("Do you want to continue?(Press 1 to continue): ");
        scanf("%d",&choice);
    }while(choice == 1);

    return 0;
}
