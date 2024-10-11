#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i = 0, j = 0, no = 0, tmpch = 90;
char str[100], left[15], right[15];

struct exp {
    int pos;
    char op;
} k[15];

void findopr();
void explore();
void fleft();
void fright();

void gen(char op, char arg1, char arg2, char result) {
    printf("(%c, %c, %c, %c)\n", op, arg1, arg2, result);
}

void expr();

void term();

void factor();

void term_prime();

void factor_prime();

void error() {
    printf("Error in parsing expression.\n");
    exit(1);
}

void match(char expectedToken) {
    if (str[i] == expectedToken) {
        i++;
    } else {
        error();
    }
}

void fleft() {
    if (str[i] == '(') {
        i++;
        expr();
        match(')');
    } else if (isalpha(str[i])) {
        left[j++] = str[i++];
    } else {
        error();
    }
}

void fright() {
    if (str[i] == '(') {
        i++;
        expr();
        match(')');
    } else if (isalpha(str[i])) {
        right[j++] = str[i++];
    } else {
        error();
    }
}

void factor() {
    if (isdigit(str[i])) {
        gen('=', str[i], '_', 't');
        left[j++] = 't';
        i++;
    } else if (isalpha(str[i])) {
        left[j++] = str[i++];
    } else if (str[i] == '(') {
        fleft();
    } else {
        error();
    }
}

void term_prime() {
    while (str[i] == '*' || str[i] == '/') {
        char op = str[i];
        i++;
        factor();
        gen(op, left[j - 2], left[j - 1], 't');
        left[j - 2] = 't';
        j--;
    }
}

void term() {
    factor();
    term_prime();
}

void expr() {
    term();
    while (str[i] == '+' || str[i] == '-') {
        char op = str[i];
        i++;
        term();
        gen(op, left[j - 2], left[j - 1], 't');
        left[j - 2] = 't';
        j--;
    }
}

void explore() {
    int l, r;
    for (r = 0; r <= no; r++) {
        if (k[r].pos == 0) {
            k[r].pos = i;
            break;
        }
    }
    for (l = k[r].pos - 1; l >= 0; l--) {
        if (k[l].pos == 0) {
            k[l].pos = i;
            break;
        }
    }
    fleft();
    for (l = k[l].pos + 1; l < k[r].pos; l++) {
        if (str[l] == '*' || str[l] == '/') {
            char op = str[l];
            l++;
            fright();
            gen(op, left[j - 2], left[j - 1], 't');
            left[j - 2] = 't';
            j--;
        }
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", str);

    explore();

    return 0;
}
