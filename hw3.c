#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // For Windows; if using Linux, replace with appropriate library for getch()

#define ROWS 9
#define COLS 9
#define PASSWORD 2024
#define MAX_ATTEMPTS 3

void clearScreen();
void displayWelcomeScreen();
void displayMainMenu();
void displaySeats(char seats[ROWS][COLS]);
void initializeSeats(char seats[ROWS][COLS]);
int validatePassword();
void arrangeSeats(char seats[ROWS][COLS], int numSeats);
void bookSeats(char seats[ROWS][COLS], int count);
void chooseSeats(char seats[ROWS][COLS]);

void clearScreen() {
    system("cls");  // For Windows; if using Linux, replace with system("clear");
}

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
}

void displayMainMenu() {
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats                |\n");
    printf("|  b. Arrange for you                |\n");
    printf("|  c. Choose by yourself             |\n");
    printf("|  d. Exit                           |\n");
    printf("-------------------------------------\n");
}

void displaySeats(char seats[ROWS][COLS]) {
    printf("  123456789\n");
    int i;
    int j;
    for (i = ROWS; i > 0; i--) {
        printf("%d ", i);
        for (j = 0; j < COLS; j++) {
            printf("%c", seats[i-1][j]);
        }
        printf("\n");
    }
}

void initializeSeats(char seats[ROWS][COLS]) {
    srand(time(0));
    int i;
    int j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = '-';
        }
    }
    int h;
    for (h = 0; h < 10; h++) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (seats[row][col] == '*');
        seats[row][col] = '*';
    }
}

int validatePassword() {
    int attempt = 0;
    int input;
    while (attempt < MAX_ATTEMPTS) {
        displayWelcomeScreen();
        scanf("%d", &input);
        if (input == PASSWORD) {
            return 1;
        } else {
            printf("Incorrect password. Please try again.\n");
        }
        attempt++;
    }
    return 0;
}

void arrangeSeats(char seats[ROWS][COLS], int numSeats) {
    int found = 0;
    int i;
    int j;
    int k;
    for (i = 0; i < ROWS && !found; i++) {
        for (j = 0; j <= COLS - numSeats && !found; j++) {
            int canBook = 1;
            for (k = 0; k < numSeats; k++) {
                if (seats[i][j + k] != '-') {
                    canBook = 0;
                    break;
                }
            }
            if (canBook) {
                for (k = 0; k < numSeats; k++) {
                    seats[i][j + k] = '@';
                }
                found = 1;
            }
        }
    }
    if (!found && numSeats == 4) {
        for (i = 0; i < ROWS - 1 && !found; i++) {
            for (j = 0; j < COLS; j++) {
                if (seats[i][j] == '-' && seats[i + 1][j] == '-' && seats[i][j + 1] == '-' && seats[i + 1][j + 1] == '-') {
                    seats[i][j] = seats[i + 1][j] = seats[i][j + 1] = seats[i + 1][j + 1] = '@';
                    found = 1;
                    break;
                }
            }
        }
    }
}

void bookSeats(char seats[ROWS][COLS], int count) {
    arrangeSeats(seats, count);
    displaySeats(seats);
    printf("Are you satisfied with the arrangement? (y/n)\n");
    char response = getch();
    if (response == 'y') {
        int i,j;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (seats[i][j] == '@') {
                    seats[i][j] = '*';
                }
            }
        }
    }
}

void chooseSeats(char seats[ROWS][COLS]) {
    int row, col;
    char input[5];
    int valid = 0;
    while (!valid) {
        printf("Enter your seat selection (e.g., 1-2): ");
        scanf("%s", input);
        if (sscanf(input, "%d-%d", &row, &col) == 2 && row > 0 && row <= ROWS && col > 0 && col <= COLS && seats[row - 1][col - 1] == '-') {
            seats[row - 1][col - 1] = '@';
            valid = 1;
        } else {
            printf("Invalid input or seat already taken. Please try again.\n");
        }
    }
    displaySeats(seats);
    printf("Press any key to confirm your selection.\n");
    getch();
    int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') {
                seats[i][j] = '*';
            }
        }
    }
}

int main() {
    char seats[ROWS][COLS];
    
    displayWelcomeScreen(); //welcome
    
    int attempts=0;
    while (attempts < 3) {
        printf("Please enter a four-digit password.：");
        char input[5];
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            break;
        } else {
            attempts++;
            printf("Incorrect password, please try again.\n");
        }
    }

    // if Exceeding three attempts, the program will terminate.
    if (attempts >= 3) {
        printf("Exceeding three attempts, the program will terminate.\n");
        system("PAUSE"); // Waiting for the user to press any key.
        return 1;
    }

    clearScreen();
    initializeSeats(seats);
    char choice;
    do {
        displayMainMenu();
        choice = getch();  // Get single character input
        clearScreen();

        switch (choice) {
            case 'a':
                displaySeats(seats);
                printf("Press any key to return to the main menu.\n");
                getch();
                clearScreen();
                break;
           case 'b': {
    int numSeats;
    printf("How many seats do you need? (1-4): ");
    scanf("%d", &numSeats);
    if (numSeats >= 1 && numSeats <= 4) {
        if (numSeats < 4) {
            // Arrange for 1-3 seats
            arrangeSeats(seats, numSeats);
        } else {
            // Arrange for 4 seats
            printf("1. Consecutive seats in the same row\n");
            printf("2. Two seats in each of two consecutive rows\n");
            printf("Choose an option (1 or 2): ");
            int option;
            scanf("%d", &option);
            if (option == 1) {
                arrangeSeats(seats, 4); // Consecutive seats in the same row
            } else if (option == 2) {
                // Two seats in each of two consecutive rows
                arrangeSeats(seats, 2);
                arrangeSeats(seats, 2);
            } else {
                printf("Invalid option. Returning to main menu.\n");
            }
        }
    } else {
        printf("Invalid number of seats. Returning to main menu.\n");
    }
    clearScreen();
    break;
}
            case 'c':
                chooseSeats(seats);
                clearScreen();
                break;
           case 'd':
             printf("Continue? (y/n)\n");
             char confirm = getch();
             if (confirm == 'n') {
               printf("Exiting...\n");
               return 0;
             } else if (confirm == 'y') {
                  clearScreen();
                    break;
              } else {
                  printf("Invalid input. Please try again.\n");
                  clearScreen();
                     break;
                      }
            default:
                printf("Invalid choice. Please try again.\n");
                clearScreen();
                break;
        }
    } while (choice != 'd');

    return 0;
}
