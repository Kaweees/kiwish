#include "../include/kiwish.h"

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/input.h"
#include "../include/utils.h"

#define SYSCALL_ERROR -1

/**
 * @brief kiwish - A function that reads commands from a file and executes them
 * @param infile - a file descriptor to the file to read from
 * @param outfile - a pointer to the file to write to
 */
void kiwish(int infile, int outfile) {
  FILE* input_file = fdopen(infile, "r");
  if (input_file == NULL) {
    fclose(input_file);
    panic("Error opening infile as a file stream");
  }
  FILE* output_file = fdopen(infile, "wb");
  if (output_file == NULL) {
    fclose(output_file);
    panic("Error opening outfile as a file stream");
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
