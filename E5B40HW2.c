#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// 定義全局變數來存儲密碼和輸入密碼的次數
#define PASSWORD "2024"
int attempts = 0;

// 函數聲明
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

    // 歡迎畫面
    clearScreen();
    printf("歡迎使用我的程式！\n");
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
    fflush(stdin); // 清空輸入緩衝區
    system("PAUSE"); // 等待使用者按下任意鍵
    system("CLS"); // 清除畫面

    // 密碼驗證
    while (attempts < 3) {
        printf("請輸入四位數的密碼：");
        char input[5];
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            break;
        } else {
            attempts++;
            printf("密碼錯誤！請重新輸入。\n");
        }
    }

    // 如果輸入次數超過三次，結束程式
    if (attempts >= 3) {
        printf("輸入次數超過三次，程式結束。\n");
        system("PAUSE"); // 等待使用者按下任意鍵
        return 1;
    }

    // 進入主選單
    while (1) {
        drawMenu();
        choice = getValidCharInput();
        clearScreen();

        switch (choice) {
            case 'a':
            case 'A':
                printf("請輸入要使用的字元（a到z之間）：");
                triangleChar = getValidCharInput();
                drawRightTriangle(triangleChar);
                break;
            case 'b':
            case 'B':
                printf("請輸入要生成的乘法表的大小（1到9之間）：");
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
                    printf("程式結束。\n");
                    system("PAUSE"); // 等待使用者按下任意鍵
                    return 0;
                } else {
                    printf("錯誤的輸入，請重新輸入。\n");
                }
                break;
            default:
                printf("錯誤的輸入，請重新輸入。\n");
        }
    }

    return 0;
}

// 清除螢幕函數的實現
void clearScreen() {
    system("cls");
}

// 繪製主選單函數的實現
void drawMenu() {
    printf("--------------------------\n");
    printf("|  a. 畫出直角三角形    |\n");
    printf("|  b. 顯示乘法表        |\n");
    printf("|  c. 結束              |\n");
    printf("--------------------------\n");
}

// 繪製直角三角形函數的實現
void drawRightTriangle(char ch) {
    if (ch < 'a' || ch > 'z') {
        printf("輸入不在範圍內，請重新輸入。\n");
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
    printf("\n按任意鍵返回主選單...");
    getch(); // 按任意鍵繼續
}

// 繪製乘法表函數的實現
void drawMultiplicationTable(int n) {
    if (n < 1 || n > 9) {
        printf("輸入不在範圍內，請重新輸入。\n");
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
    printf("\n按任意鍵返回主選單...");
    getch(); // 按任意鍵繼續
}

// 獲取有效字符輸入函數的實現
char getValidCharInput() {
    char input;
    scanf(" %c", &input);
    return input;
}

// 獲取有效整數輸入函數的實現
int getValidIntInput() {
    int input;
    scanf("%d", &input);
    return input;
}
