#include <stdio.h>

#include "../include/utils.h"

/**
 * @brief Displays the usage mode of the program on the standard output.
 *
 * This function prints a message on the standard output explaining how to use the program,
 * including the expected format of command-line arguments.
 */
void usage(void) {
    printf("___________________________________\n");
    printf("< Use: ./main target.com <wordlist> >\n");
    printf("-----------------------------------\n");
    printf("       \\    ^__^\n");
    printf("        \\   (..)\\_______\n");
    printf("            (__)\\       )\\/\\\n");
    printf("             U  ||----w |\n");
    printf("                ||     ||\n");
}

/**
 * @brief Counts the number of lines in a file.
 *
 * This function traverses the given file and counts how many lines it contains, based 
 * on the presence of the newline character (0x0A / `\n`).
 *
 * @param file Pointer to the file whose lines are to be counted.
 * @return The total number of lines in the file.
 */
int countFileLines(FILE *file) {
    int lines = 0;
    char word = { 0 };

    while (!feof(file)) {
        word = fgetc(file);

        if (word == 0x0A) {
            lines++;
        }
    }

    rewind(file);

    return ++lines;
}
