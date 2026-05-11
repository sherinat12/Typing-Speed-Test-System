#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Colors
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Functions
void line() {
    printf(BLUE "+--------------------------------------+\n" RESET);
}

void title(char text[]) {
    line();
    printf(BLUE "| %-36s |\n" RESET, text);
    line();
}

void pauseScreen() {
    printf(YELLOW "\nPress Enter to continue..." RESET);
    getchar();
}

// Main
int main() {

    char text[] =
        "C programming is simple and powerful";

    char input[100];

    time_t start, end;
    double timeTaken;

    system("cls || clear");

    title("TYPING SPEED TEST");

    printf(CYAN "\n Type the following sentence:\n\n" RESET);

    printf(YELLOW "\"%s\"\n" RESET, text);

    printf(CYAN "\n Start typing below:\n\n" RESET);

    time(&start);

    getchar();
    fgets(input, sizeof(input), stdin);

    time(&end);

    timeTaken = difftime(end, start);

    // Remove newline
    input[strcspn(input, "\n")] = 0;

    line();

    if (strcmp(text, input) == 0) {

        printf(GREEN "\n ✔ Correct Typing!\n" RESET);

    } else {

        printf(RED "\n ✘ Typing Mistake Found!\n" RESET);
    }

    printf(YELLOW "\n Time Taken: %.2f seconds\n" RESET, timeTaken);

    line();

    pauseScreen();

    return 0;
}