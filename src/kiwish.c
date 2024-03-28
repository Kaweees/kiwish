#include "kiwish.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SYSCALL_ERROR -1
#define PROMPT        "kiwish> "

/**
 * @brief kiwish - A function that reads commands from a file and executes them
 * @param infile - a file descriptor to the file to read from
 * @param outfile - a pointer to the file to write to
 */
void kiwish(int infile, int outfile) {
  FILE* file = fdopen(infile, "r");
  if (file == NULL) {
    perror("Error opening infile as a file stream");
    close(infile);
    exit(EXIT_FAILURE);
  }
  char* line = NULL;
  size_t line_size = 0;
  ssize_t num_read;
  while ((num_read = getline(&line, &line_size, file)) != -1) {
    if (write(outfile, line, num_read) == SYSCALL_ERROR) {
      perror("write");
      fclose(file);
      close(infile);
      exit(EXIT_FAILURE);
    }
    free(line);
    line = NULL;
  }
  free(line);
  line = NULL;
}
