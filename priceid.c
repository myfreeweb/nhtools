#include <stdio.h>
#include <string.h>
#define true  1
#define false 0

char *id(char *tp, int price, int charisma, int sucker, int selling) {
  float resprice;
  int baseprice;
  if (selling == true) {
    if (sucker == true) {
      resprice = price * 3;
    } else {
      resprice = price * 2;
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
        return "Booze, fruit juice, see invisible... good, eh? Stop, that can also be a potion of sickness! A cursed one removes up to 15 HP, uncursed - up to ten, blessed - just one. Non-blessed ones also randomly reduce one of your stats. Not so deadly, but beware. You can turn it into fruit juice by #dipping a unicorn horn into it or zapping it with a wand of cancellation (but don't waste it, really!) Dipping a missile weapon also helps: it will be poisoned after dipping. So, dip a dart. Or whatever. But not a dagger. Hey, I should stop talking. You're not listening anyway.";
      case 100:
        return "Oh, one of these:\nconfusion (4.2\% relative probability),\nextra healing (4.7\%),\nhallucination (4\%),\nhealing (5.7\%),\nholy or unholy water (1.15\%),\nrestore ability (4\%),\nsleeping (4.2\%).";
      case 150:
        return "Definitely one of these fine potions:\nblindness (4\% relative probability),\ngain energy (4.2\%),\ninvisibility (4\%),\nmonster detection (4\%),\nobject detection (4.2\%).";
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
  } else if (strcmp(tp, "wand") == 0) {
    switch (baseprice) {
      case 100:
        return "A wand of light (9.5\% relative probability) or a wand of nothing (2.5\%).";
      case 150:
        return "Yeah, that's one of these useful wands:\ndigging (5.5\% relative probability),\nenlightenment (1.5\%),\nlocking (2.5\%),\nmagic missile (5\%),\nmake invisible (4.5\%),\nopening (2.5\%),\nprobing (3\%),\nsecret door detection (5\%),\nslow monster (5\%),\nspeed monster (5\%),\nstriking (7.5\%),\nundead turning (5\%).";
      case 175:
        return "This is a wand of cold, fire, lightning or (more probably, 5\% vs 4\%) sleep.";
      case 200:
        /* relative probabilities of these are equal */
        return "Wand of cancellation, create monster, polymorph or teleportation.";
      case 500:
        /* relative probabilities of these are equal */
        return "Wow. A wand or death or a wand of wishing. Try to zap it at the shopkeeper, if it's wishing - wish for a wand of death.";
      default:
        return "A strange wand.";
    }
  } else if (strcmp(tp, "ring") == 0) {
    switch (baseprice) {
      case 5:
        return "Just a useless meat ring.";
      case 100:
        return "That's a ring of:\nadornment,\nhunger (90\% generated cursed, beware!),\nprotection,\nprotection from shape changers,\nstealth,\nsustain ability,\nwarning.";
      case 150:
        return "One of these rings:\naggravate monster (90\% generated cursed, you don't want this!),\ncold resistance,\ngain constitution,\ngain strength,\nincrease accuracy,\nincrease damage,\ninvisibility (cursed if from a Nazgul),\npoison resistance,\nsee invisible,\nshock resistance.";
      case 200:
        return "There you have it:\nfire resistance,\nfree action,\nlevitation,\nregeneration,\nsearching,\nslow digestion,\nteleportation (90\% generated cursed).";
      case 300:
        return "Ring of conflict, polymorph (90\% generated cursed), polymorph control or teleport control.";
      default:
        return "I don't know anything about that ring. Sorry.";
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
  if (argc <3) { /* C is love... until you have to write malloc()s and stuff */
    printf("priceid - part of the free nhtools package by myfreeweb: https://github.com/myfreeweb/nhtools\nbased on info from http://nethackwiki.com\n\nUsage: priceid [options] type price\n\nOptions:\n-sucker - if you're a tourist with Xp level =< 14 or wearing a shirt w/o any armor/cloak over it. Or a duncecap.\n-selling - if you're selling an item\n-c[your charisma] - it affects the price when *buying*\n\nSupported types: scroll, potion, wand, ring.");
  } else {
    int i, charisma = 11, /* 11-15 is for list price */
    sucker = false, selling = false;
    for (i=1; i < argc; i++) {
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
    printf("%s\n", id(argv[argc-2], atoi(argv[argc-1]), charisma, sucker, selling));
  }
  return 0;
}
