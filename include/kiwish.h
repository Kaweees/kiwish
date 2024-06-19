#ifndef KIWISH_H
#define KIWISH_H

#define UNIMPLEMENTED                                                         \
  do {                                                                        \
    fprintf(stderr, "%s:%d: %s is not implemented yet\n", __FILE__, __LINE__, \
        __func__);                                                            \
    abort();                                                                  \
  } while (0)

#define UNREACHABLE                                                          \
  do {                                                                       \
    fprintf(                                                                 \
        stderr, "%s:%d: %s is unreachable\n", __FILE__, __LINE__, __func__); \
    abort();                                                                 \
  } while (0)

#define UNUSED(x) ((void)(x))

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

#endif /* KIWISH_H */
