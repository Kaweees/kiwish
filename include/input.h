#pragma once

#include <stdio.h>


#define PROMPT "kiwish> "

/* Begin typedef declarations */

typedef struct InputBufferType {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBufferType;

/* Begin function prototype declarations */
InputBufferType* createInputBuffer();
void freeInputBuffer(InputBufferType* input);
void readInput(InputBufferType* input, FILE* file);
void printPrompt();
