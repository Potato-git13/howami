#include <stdio.h>
#include <stdlib.h>

int bat_perc(){
    int perc;
    char char_perc[4];
    FILE *fp;
    // you can edit what battery it looks at if it doesn't work
    fp = fopen("/sys/class/power_supply/BAT0/capacity",  "r");
    fgets(char_perc, 4, fp);
    // turning the original string version of the bat percentage
    perc=atoi(char_perc);
    // return the int percentage
    return perc;
}
