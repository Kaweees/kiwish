#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/kiwish.h"
#include "../include/utils.h"

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
      panic("Error opening file");
    }
    kiwish(infile, STDOUT_FILENO);
    close(infile);
  } else {
    usage(*argv);
  }
  return EXIT_SUCCESS;
}
