#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 

// 定義學生結構
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

// 函數原型
void displayWelcomeScreen();
int checkPassword();
void displayMainMenu();
void enterGrades(Student students[], int *n);
void displayGrades(Student students[], int n);
void searchGrades(Student students[], int n);
void gradeRanking(Student students[], int n);
void clearScreen();
void pressAnyKey();

// 主程式入口
int main() {
    Student students[10]; // 儲存最多10位學生的資料
    int studentCount = 0; // 目前學生數量
    int attempts = 0;

    // 顯示歡迎畫面並要求輸入密碼
    displayWelcomeScreen();
    int password;

    while (attempts < 3) {
        printf("請輸入密碼：");
        scanf("%d", &password);
        if (password == 2024) {
            printf("歡迎進入系統！\n");
            break;
        } else {
            printf("密碼錯誤！\n");
            attempts++;
        }
    }
    
    if (attempts == 3)//如果嘗試三次，程式關閉 
    {
       printf("輸入錯誤三次，程式關閉");
       system("PAUSE"); // 等待使用者按下任意鍵           
      return 0;
     }

    // 顯示主選單
    while (1) {
        displayMainMenu();
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                enterGrades(students, &studentCount);
                break;
            case 'b':
                displayGrades(students, studentCount);
                break;
            case 'c':
                searchGrades(students, studentCount);
                break;
            case 'd':
                gradeRanking(students, studentCount);
                break;
            case 'e':
                 while (1) {
                    printf("確定離開？ (y/n)\n");
                    char exitChoice;
                    scanf(" %c", &exitChoice);
                    if (exitChoice == 'y' || exitChoice == 'Y') {
                        return 0;
                    } else if (exitChoice == 'n' || exitChoice == 'N') {
                        break; // 回到主選單
                    } else {
                        printf("無效的選項，請重新輸入。\n");
                    }
                }
                break;
                break;
            default:
                printf("無效的選項，請重新輸入。\n");
        }
    }

    return 0;
}

// 顯示歡迎畫面
void displayWelcomeScreen() {
    clearScreen();
      printf("Welcome to my program!\n");
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
    
    printf("Press any key to continue...");
    fflush(stdin); // 清空輸入緩衝區
    system("PAUSE"); // 等待使用者按下任意鍵
    system("CLS"); // 清除畫面
    
    printf("*****************************\n");
    printf("*   歡迎使用簡易成績系統    *\n");
    printf("*   請輸入4位數字的密碼     *\n");
    printf("*****************************\n\n\n\n\n");
}


// 顯示主選單
void displayMainMenu() {
    clearScreen();
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades          |\n");
    printf("|  b. Display student grades        |\n");
    printf("|  c. Search for student grades     |\n");
    printf("|  d. Grade ranking                 |\n");
    printf("|  e. Exit system                   |\n");
    printf("------------------------------------\n");

}

// 輸入學生成績
void enterGrades(Student students[], int *n) {
    clearScreen();
    printf("請輸入學生數量（5~10）：");
    scanf("%d", n);
    if (*n < 5 || *n > 10) {
        printf("輸入錯誤，請輸入5~10之間的數字。\n");
        pressAnyKey();
        return;
    }
    int i;
    for (i = 0; i < *n; i++) {
        printf("請輸入第%d位學生的姓名：", i + 1);
        scanf("%s", students[i].name);
        
        while (1) {
            printf("請輸入學號（6位整數）：");
            scanf("%d", &students[i].id);
            if (students[i].id >= 100000 && students[i].id <= 999999) {
                break;
            } else {
                printf("學號錯誤，請重新輸入。\n");
            }
        }

        while (1) {
            printf("請輸入數學成績（0~100）：");
            scanf("%d", &students[i].math);
            if (students[i].math >= 0 && students[i].math <= 100) {
                break;
            } else {
                printf("成績錯誤，請重新輸入。\n");
            }
        }

        while (1) {
            printf("請輸入物理成績（0~100）：");
            scanf("%d", &students[i].physics);
            if (students[i].physics >= 0 && students[i].physics <= 100) {
                break;
            } else {
                printf("成績錯誤，請重新輸入。\n");
            }
        }

        while (1) {
            printf("請輸入英文成績（0~100）：");
            scanf("%d", &students[i].english);
            if (students[i].english >= 0 && students[i].english <= 100) {
                break;
            } else {
                printf("成績錯誤，請重新輸入。\n");
            }
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

// 顯示所有學生成績
void displayGrades(Student students[], int n) {
    clearScreen();
    printf("所有學生的成績如下：\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("姓名：%s, 學號：%d, 數學：%d, 物理：%d, 英文：%d, 平均成績：%.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, students[i].average);
    }
    pressAnyKey();
}

// 搜尋學生成績
void searchGrades(Student students[], int n) {
    clearScreen();
    char searchName[50];
    printf("請輸入要搜尋的學生姓名：");
    scanf("%s", searchName);
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("姓名：%s, 學號：%d, 數學：%d, 物理：%d, 英文：%d, 平均成績：%.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
            pressAnyKey();
            return;
        }
    }
    printf("找不到該學生資料。\n");
    pressAnyKey();
}

// 成績排名
void gradeRanking(Student students[], int n) {
    clearScreen();
    Student temp;
    int i,j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    
    printf("按平均成績高低排序如下：\n");
    for (i = 0; i < n; i++) {
        printf("姓名：%s, 學號：%d, 平均成績：%.1f\n",
               students[i].name, students[i].id, students[i].average);
    }
    pressAnyKey();
}

// 清除螢幕
void clearScreen() {
    // system("cls"); // Windows
    system("clear"); // Unix/Linux/MacOS
}

// 等待使用者按任意鍵
void pressAnyKey() {
    printf("按任意鍵繼續...\n");
    getchar();
    getchar(); // 需要兩次getchar()，因為上一次輸入留有換行符
}
