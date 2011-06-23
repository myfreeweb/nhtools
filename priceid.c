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
      resprice = price / 1.33;
    } else {
      resprice = price / 1.0;
    }
    if (charisma < 6) {
      resprice = resprice / 2.0;
    } else if (charisma < 8) {
      resprice = resprice / 1.5;
    } else if (charisma < 11) {
      resprice = resprice / 1.33;
    } else if (charisma > 15) {
      resprice = resprice / 0.75;
    } else if (charisma == 18) {
      resprice = resprice / 0.67;
    } else if (charisma > 18) {
      resprice = resprice / 0.5;
    }
  }
  baseprice = (int) resprice;
  printf("Base price: %i\n", baseprice);
  if (selling == true) {
    puts("When you're selling, there's a 25% chance of a lower price, so drop the item a few times and use the higher price there.\n");
  }
  if (strcmp(tp, "scroll") == 0) {
    switch (baseprice) {
      case 20:
        return "That's definitely a scroll of identify!";
      case 50:
        /* I suck at rap, eh? */
        return "A scroll of light that shines bright,\nuntil you drop it down tonight,\nyo!";
      case 60:
        return "That's a scroll of enchant weapon. Or blank paper, less likely (2.8\% vs 8\% relative probability). Not dangerous anyway.";
      case 80:
        return "Wow, a useful one. Scroll of enchant armor (6.3\% relative probability) or remove curse (6.5\%).";
      case 100:
        return "Looks like I know what's that... One of those:\nconfuse monster (5.3\% relative probability),\ndestroy armor (4.5\%),\nfire (3\%),\nfood detection (2.5\%),\ngold detection (3.3\%),\nmagic mapping (4.5\%),\nscare monster (3.5\%),\nteleportation(5.5\%).";
      case 200:
        /* The Offspring reference, you got it? */
        return "Don't pick it up, you! (unless you know what you're doing) That could be:\namnesia (3.5\% relative probability),\ncreate monster (4.5\%),\nearth (1.8\%),\ntaming (1.5\%).";
      case 300:
        /* relative probabilities of these are equal */
        return "A scroll of charging, genocide, punishment or stinking cloud.";
      default:
        return "Some weird scroll...";
    }
  } else if (strcmp(tp, "potion") == 0) {
    switch (baseprice) {
      case 50:
        /* relative probabilities of these are equal */
        return "Booze, fruit juice, see invisible... good, eh? Stop, that can also be a potion of sickness! A cursed one removes up to 15 HP, uncursed - up to ten, blessed - just one. Non-blessed ones also randomly reduce one of your stats. Not so deadly, but beware. You can turn it into fruit juice by #dipping a unicorn horn into it or zapping it with a wand of cancellation (but don't waste it, really!) Dipping a missile weapon also helps by forming a coating on the potion.";
      case 100:
        return "Oh, one of these:\nconfusion (4.2\% relative probability),\nextra healing (4.7\%),\nhallucination (4\%),\nhealing (5.7\%),\nholy or unholy water (1.15\%),\nrestore ability (4\%),\nsleeping(4.2\%).";
      case 150:
        return "Definitely one of these fine potions:\nblindness (4\% relative probability),\ngain energy (4.2\%),\ninvisibility(4\%),\nmonster detection (4\%),\nobject detection (4.2\%).";
      case 200:
        return "I know that! One of those:\nenlightenment (2\% relative probability),\nfull healing (1\%),\nlevitation (4.2\%),\npolymorph (1\%),\nspeed (4.2\%).";
      case 250:
        return "That's acid (1\% relative probability) or oil (3\%).";
      case 300:
        return "There you have a potion of gain ability (4.2\% relative probability), gain level (2\%) or paralysis (4.2\%).";
      default:
        if (baseprice < 15) {
          return "I guess that's water.";
        } else {
          return "An odd potion.";
        }
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
