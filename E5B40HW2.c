#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// �w�q�����ܼƨӦs�x�K�X�M��J�K�X������
#define PASSWORD "2024"
int attempts = 0;

// ����n��
void clearScreen();
void drawMenu();
void drawRightTriangle(char ch);
void drawMultiplicationTable(int n);
char getValidCharInput();
int getValidIntInput();

int main() {
    char choice;
    char triangleChar;
    int tableSize;

    // �w��e��
    clearScreen();
    printf("�w��ϥΧڪ��{���I\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*          Welcome to My Program        *\n");
    printf("*                                       *\n");
    printf("*     |-|    |-|      |-----------|     *\n");
    printf("*     | |    | |      |----| |----|     *\n");
    printf("*     | |    | |           | |          *\n");
    printf("*     | -----| |           | |          *\n");
    printf("*     | -----| |           | |          *\n");
    printf("*     | |    | |           | |          *\n");
    printf("*     | |    | |      |----| |----|     *\n");
    printf("*     |-|    |-|      |-----------|     *\n");
    printf("*                                       *\n");
    printf("*     *****************************     *\n");
    printf("*             *            *            *\n");
    printf("*           *   *        *   *          *\n");
    printf("*         *       *    *       *        *\n");
    printf("*                                       *\n");
    printf("*                                       *\n");
    printf("*                                       *\n");
    printf("*            *               *          *\n");
    printf("*             *             *           *\n");
    printf("*              *************            *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");

    printf("\nPress any key to continue...");
    fflush(stdin); // �M�ſ�J�w�İ�
    system("PAUSE"); // ���ݨϥΪ̫��U���N��
    system("CLS"); // �M���e��

    // �K�X����
    while (attempts < 3) {
        printf("�п�J�|��ƪ��K�X�G");
        char input[5];
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            break;
        } else {
            attempts++;
            printf("�K�X���~�I�Э��s��J�C\n");
        }
    }

    // �p�G��J���ƶW�L�T���A�����{��
    if (attempts >= 3) {
        printf("��J���ƶW�L�T���A�{�������C\n");
        system("PAUSE"); // ���ݨϥΪ̫��U���N��
        return 1;
    }

    // �i�J�D���
    while (1) {
        drawMenu();
        choice = getValidCharInput();
        clearScreen();

        switch (choice) {
            case 'a':
            case 'A':
                printf("�п�J�n�ϥΪ��r���]a��z�����^�G");
                triangleChar = getValidCharInput();
                drawRightTriangle(triangleChar);
                break;
            case 'b':
            case 'B':
                printf("�п�J�n�ͦ������k���j�p�]1��9�����^�G");
                tableSize = getValidIntInput();
                drawMultiplicationTable(tableSize);
                break;
            case 'c':
            case 'C':
                printf("Continue? (y/n): ");
                choice = getValidCharInput();
                if (choice == 'y' || choice == 'Y') {
                    clearScreen();
                    break;
                } else if (choice == 'n' || choice == 'N') {
                    printf("�{�������C\n");
                    system("PAUSE"); // ���ݨϥΪ̫��U���N��
                    return 0;
                } else {
                    printf("���~����J�A�Э��s��J�C\n");
                }
                break;
            default:
                printf("���~����J�A�Э��s��J�C\n");
        }
    }

    return 0;
}

// �M���ù���ƪ���{
void clearScreen() {
    system("cls");
}

// ø�s�D����ƪ���{
void drawMenu() {
    printf("--------------------------\n");
    printf("|  a. �e�X�����T����    |\n");
    printf("|  b. ��ܭ��k��        |\n");
    printf("|  c. ����              |\n");
    printf("--------------------------\n");
}

// ø�s�����T���Ψ�ƪ���{
void drawRightTriangle(char ch) {
    if (ch < 'a' || ch > 'z') {
        printf("��J���b�d�򤺡A�Э��s��J�C\n");
        return;
    }
    clearScreen();
    char i;
    char j;
    for (i = ch; i >= 'a'; i--) {
        for (j = ch; j >= i; j--) {
            printf("%c", j);
        }
        printf("\n");
    }
    printf("\n�����N���^�D���...");
    getch(); // �����N���~��
}

// ø�s���k���ƪ���{
void drawMultiplicationTable(int n) {
    if (n < 1 || n > 9) {
        printf("��J���b�d�򤺡A�Э��s��J�C\n");
        return;
    }
    clearScreen();
    int i;
    int j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%dx%d=%2d ",i,j,i * j);
        }
        printf("\n");
    }
    printf("\n�����N���^�D���...");
    getch(); // �����N���~��
}

// ������Ħr�ſ�J��ƪ���{
char getValidCharInput() {
    char input;
    scanf(" %c", &input);
    return input;
}

// ������ľ�ƿ�J��ƪ���{
int getValidIntInput() {
    int input;
    scanf("%d", &input);
    return input;
}
