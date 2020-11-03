#include <stdio.h>
#include <stdlib.h>

typedef struct Item Item;
struct Item {
   char  symbol;
   int  count;
   Item *next;
} item;

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
  Item *items = malloc(sizeof(Item));
  Item *ptr = items;
  char prev = '\0';
  int first = 1;
  while ((ch = fgetc(fp)) != EOF) {
    /* first Item */
    if (first) {
      ptr->symbol = ch;
      ptr->count = 1;
      first = 0;
    }

    /* new Item */
    else if (ch != prev) {
      ptr->next = malloc(sizeof(Item));
      ptr = ptr->next;
      ptr->symbol = ch;
      ptr->count = 1;
    }

    /* inc Item */
    else if (ch == prev) {
      ptr->count += 1;
    }

    /* default */
    else {
      printf("not sure why I'm here\n");
    }

    prev = ch;
  }
  fclose(fp);

  /* write to file */
  fname = "out.txt"; 
  fp = fopen(fname, "w+");
  while (items) {
    fprintf(fp,"%d%c", items->count, items->symbol);
    items = items->next;
  }
}