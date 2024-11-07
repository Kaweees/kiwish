#pragma once

/* Begin typedef declarations */

typedef enum CommandType {
  EXECUTE_CMD,
  REDIRECT_CMD,
  PIPE_CMD,
  LIST_CMD,
  BACKGROUND_CMD,
} CommandType;

/* Begin function prototype declarations */
void kiwish(int infile, int outfile);
