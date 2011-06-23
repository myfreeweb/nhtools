#include <stdio.h>
#include <string.h>
#define true  1
#define false 0

char *id(char *tp, int price, int charisma, int sucker, int selling) {
  float resprice;
  int baseprice;
  if (selling == true) {
    if (sucker == true) {
      resprice = price / 100.0 * 3.0;
    } else {
      resprice = price * 0.5;
    }
  } else {
    if (sucker == true) {
      resprice = price * 1.33;
    } else {
      resprice = price * 1.0;
    }
    if (charisma < 6) {
      resprice = resprice * 2.0;
    } else if (charisma < 8) {
      resprice = resprice * 1.5;
    } else if (charisma < 11) {
      resprice = resprice * 1.33;
    } else if (charisma > 15) {
      resprice = resprice * 0.75;
    } else if (charisma == 18) {
      resprice = resprice * 0.67;
    } else if (charisma > 18) {
      resprice = resprice * 0.5;
    }
  }
  baseprice = (int) resprice;
  if (strcmp(tp, "scroll") == 0) {
    switch (baseprice) {
      case 20:
        return "That's definitely a scroll of identify!";
      case 50:
        return "Scroll of light, yo!";
      case 60:
        return "That's a scroll of enchant weapon. Or blank paper. Not dangerous anyway.";
      case 80:
        return "Wow, a useful one. Scroll of enchant armor or remove curse.";
      case 1488:
        return "Sieg Heil! That's a scroll of Nazi.";
      default:
        return "Some weird scroll...";
    }
  } else {
    return "I don't know anything about that kind of things. Sorry.";
  }
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
