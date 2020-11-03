#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char ch;
  char *fname;
  FILE *fp;

  /* validate cmd in */
  if (argc != 2) {
    printf("usage:\n    ./run.sh <some_file_path>\n");
    return 1;
  }
  
  /* does file exist */
  fname = argv[1]; 
  fp = fopen(fname, "r");
  if (!fp) {
    printf("%s does not exist\n", fname);
    return 1;
  }

  /* loop through the file */
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }
  printf("Hello world %s\n", fname);
}