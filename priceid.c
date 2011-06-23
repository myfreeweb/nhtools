#include <stdio.h>

int main(int argc, char **argv) {
  if (argc <3) {
    printf("Usage: priceid [options] type price");
  } else {
    int i;
    for(i=1; i < argc; i++) {
      if (argv[i][0] == 45) { /* minus */
        printf("Flag: %s\n", argv[i]);
      } else {
        printf("Non-flag: %s\n", argv[i]);
      }
    }
  }
  return 0;
}
