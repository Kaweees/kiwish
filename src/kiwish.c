#include "kiwish.h"

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "input.h"

#define SYSCALL_ERROR -1

/**
 * @brief kiwish - A function that reads commands from a file and executes them
 * @param infile - a file descriptor to the file to read from
 * @param outfile - a pointer to the file to write to
 */
void kiwish(int infile, int outfile) {
  FILE* input_file = fdopen(infile, "r");
  if (input_file == NULL) {
    perror("Error opening infile as a file stream");
    fclose(input_file);
    exit(EXIT_FAILURE);
  }
  FILE* output_file = fdopen(infile, "wb");
  if (output_file == NULL) {
    perror("Error opening outfile as a file stream");
    fclose(output_file);
    exit(EXIT_FAILURE);
  }
  InputBufferType* input = createInputBuffer();

  while (true) {
    printPrompt();
    readInput(input, input_file);
    if (strcmp(input->buffer, "exit") == 0) {
      freeInputBuffer(input);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'.\n", input->buffer);
    }
  }
}
