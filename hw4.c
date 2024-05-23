#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 

// �w�q�ǥ͵��c
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

// ��ƭ쫬
void displayWelcomeScreen();
int checkPassword();
void displayMainMenu();
void enterGrades(Student students[], int *n);
void displayGrades(Student students[], int n);
void searchGrades(Student students[], int n);
void gradeRanking(Student students[], int n);
void clearScreen();
void pressAnyKey();

// �D�{���J�f
int main() {
    Student students[10]; // �x�s�̦h10��ǥͪ����
    int studentCount = 0; // �ثe�ǥͼƶq
    int attempts = 0;

    // ����w��e���ín�D��J�K�X
    displayWelcomeScreen();
    int password;

    while (attempts < 3) {
        printf("�п�J�K�X�G");
        scanf("%d", &password);
        if (password == 2024) {
            printf("�w��i�J�t�ΡI\n");
            break;
        } else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }
    
    if (attempts == 3)//�p�G���դT���A�{������ 
    {
       printf("��J���~�T���A�{������");
       system("PAUSE"); // ���ݨϥΪ̫��U���N��           
      return 0;
     }

    // ��ܥD���
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
                    printf("�T�w���}�H (y/n)\n");
                    char exitChoice;
                    scanf(" %c", &exitChoice);
                    if (exitChoice == 'y' || exitChoice == 'Y') {
                        return 0;
                    } else if (exitChoice == 'n' || exitChoice == 'N') {
                        break; // �^��D���
                    } else {
                        printf("�L�Ī��ﶵ�A�Э��s��J�C\n");
                    }
                }
                break;
                break;
            default:
                printf("�L�Ī��ﶵ�A�Э��s��J�C\n");
        }
    }

    return 0;
}

// ����w��e��
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
    fflush(stdin); // �M�ſ�J�w�İ�
    system("PAUSE"); // ���ݨϥΪ̫��U���N��
    system("CLS"); // �M���e��
    
    printf("*****************************\n");
    printf("*   �w��ϥ�²�����Z�t��    *\n");
    printf("*   �п�J4��Ʀr���K�X     *\n");
    printf("*****************************\n\n\n\n\n");
}


// ��ܥD���
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

// ��J�ǥͦ��Z
void enterGrades(Student students[], int *n) {
    clearScreen();
    printf("�п�J�ǥͼƶq�]5~10�^�G");
    scanf("%d", n);
    if (*n < 5 || *n > 10) {
        printf("��J���~�A�п�J5~10�������Ʀr�C\n");
        pressAnyKey();
        return;
    }
    int i;
    for (i = 0; i < *n; i++) {
        printf("�п�J��%d��ǥͪ��m�W�G", i + 1);
        scanf("%s", students[i].name);
        
        while (1) {
            printf("�п�J�Ǹ��]6���ơ^�G");
            scanf("%d", &students[i].id);
            if (students[i].id >= 100000 && students[i].id <= 999999) {
                break;
            } else {
                printf("�Ǹ����~�A�Э��s��J�C\n");
            }
        }

        while (1) {
            printf("�п�J�ƾǦ��Z�]0~100�^�G");
            scanf("%d", &students[i].math);
            if (students[i].math >= 0 && students[i].math <= 100) {
                break;
            } else {
                printf("���Z���~�A�Э��s��J�C\n");
            }
        }

        while (1) {
            printf("�п�J���z���Z�]0~100�^�G");
            scanf("%d", &students[i].physics);
            if (students[i].physics >= 0 && students[i].physics <= 100) {
                break;
            } else {
                printf("���Z���~�A�Э��s��J�C\n");
            }
        }

        while (1) {
            printf("�п�J�^�妨�Z�]0~100�^�G");
            scanf("%d", &students[i].english);
            if (students[i].english >= 0 && students[i].english <= 100) {
                break;
            } else {
                printf("���Z���~�A�Э��s��J�C\n");
            }
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

// ��ܩҦ��ǥͦ��Z
void displayGrades(Student students[], int n) {
    clearScreen();
    printf("�Ҧ��ǥͪ����Z�p�U�G\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("�m�W�G%s, �Ǹ��G%d, �ƾǡG%d, ���z�G%d, �^��G%d, �������Z�G%.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, students[i].average);
    }
    pressAnyKey();
}

// �j�M�ǥͦ��Z
void searchGrades(Student students[], int n) {
    clearScreen();
    char searchName[50];
    printf("�п�J�n�j�M���ǥͩm�W�G");
    scanf("%s", searchName);
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("�m�W�G%s, �Ǹ��G%d, �ƾǡG%d, ���z�G%d, �^��G%d, �������Z�G%.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
            pressAnyKey();
            return;
        }
    }
    printf("�䤣��Ӿǥ͸�ơC\n");
    pressAnyKey();
}

// ���Z�ƦW
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
    
    printf("���������Z���C�ƧǦp�U�G\n");
    for (i = 0; i < n; i++) {
        printf("�m�W�G%s, �Ǹ��G%d, �������Z�G%.1f\n",
               students[i].name, students[i].id, students[i].average);
    }
    pressAnyKey();
}

// �M���ù�
void clearScreen() {
    // system("cls"); // Windows
    system("clear"); // Unix/Linux/MacOS
}

// ���ݨϥΪ̫����N��
void pressAnyKey() {
    printf("�����N���~��...\n");
    getchar();
    getchar(); // �ݭn�⦸getchar()�A�]���W�@����J�d�������
}
