#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "kiwish.h"

#define USAGE_STRING  "Usage: %s [ infile ]\n" /* Program usage string */
#define MIN_ARGS      1
#define MAX_ARGS      2
#define SYSCALL_ERROR -1

/**
 * Prints the proper usage of the program and exits unsuccessfully.
 */
void usage(char* prog_name) {
  fprintf(stderr, USAGE_STRING, prog_name);
  exit(EXIT_FAILURE);
}

/**
 * @brief Program entry point
 *
 * @param argc - the number of command line arguments
 * @param argv - an array of command line arguments
 * @return int - the exit status
 */
int main(int argc, char* argv[]) {
  if (argc == MIN_ARGS) {
    kiwish(STDIN_FILENO, STDOUT_FILENO);
  } else if (argc == MAX_ARGS) {
    int infile = open(*(argv + 1), O_RDONLY, S_IRWXU);
    if (infile == SYSCALL_ERROR) {
      perror("Error opening file");
      exit(EXIT_FAILURE);
    }
    kiwish(infile, STDOUT_FILENO);
    close(infile);
  } else {
    usage(*argv);
  }
  return EXIT_SUCCESS;
}
