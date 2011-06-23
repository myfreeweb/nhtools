#include <stdio.h>
#include <string.h>
#define true  1
#define false 0

char* id(char *tp, int price, int charisma, int sucker, int selling) {
  /* TODO */
}

char *lslice(char *str, int beg) {
  char *res = str + beg;
  *res = 0; res++;
  return res;
}

int main(int argc, char **argv) {
  if (argc <3) {
    printf("Usage: priceid [options] type price");
  } else {
    int i, charisma = 11, /* 11-15 is for list price */
    sucker = false, selling = false;
    for(i=1; i < argc; i++) {
      if (argv[i][0] == 45) { /* minus */
        if (strcmp(argv[i], "-sucker") == 0) {
          sucker = true;
        } else if (strcmp(argv[i], "-selling") == 0) {
          selling = true;
        } else {
          charisma = atoi(lslice(argv[i], 1));
        }
      }
    }
    printf("%s", id(argv[argc-2], atoi(argv[argc-1]), charisma, sucker, selling));
  }
  return 0;
}
