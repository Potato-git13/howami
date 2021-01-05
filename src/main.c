#include <stdio.h>
#include <string.h>

// external function for battery percentage
extern int bat_perc();
const char *bat_rating(int bat_percent);
// when i gather all of the system info and all the ratings i will output the full total feeling message
int total_feeling_rate = 0;

int main(){
    printf("BAT: %d\n", bat_perc());
    printf("%s", bat_rating(bat_perc()));
    return 0;
}

const char *bat_rating(int bat_percent){
    static char bat_feeling[40];

    if (bat_percent<=40){
        strcpy(bat_feeling, "I feel sleepy..\n");
        total_feeling_rate += 1;
    }
    else if (bat_percent<=50 && bat_percent>40){
        strcpy(bat_feeling, "I'm half fully energized\n");
        total_feeling_rate += 2;
    }
    else if (bat_percent<=80 && bat_percent>50){
        strcpy(bat_feeling, "I'm good\n");
        total_feeling_rate += 3;
    }
    else if (bat_percent<=99 && bat_percent>80){
        strcpy(bat_feeling, "I'm great!\n");
        total_feeling_rate += 4;
    }
    else if (bat_percent==100){
        strcpy(bat_feeling, "I'm fully energized!\n");
        total_feeling_rate += 5;
    }
    return bat_feeling;
}
