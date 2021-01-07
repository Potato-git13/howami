#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// external functions
extern int bat_perc();
extern const char *ram_total();
extern const char *ram_av();
extern const char *ram_cached();
extern const char *ram_buffer();

const char *bat_rating(int bat_percent);
const char *ram_rating(int ram_percent);
// when i gather all of the system info and all the ratings i will output the full total feeling message
int total_feeling_rate = 0;

int main(){
    int ram_av_out = atoi(ram_av());
    int ram_total_out = atoi(ram_total());
    int ram_cached_out = atoi(ram_cached());
    int ram_buffer_out = atoi(ram_buffer());
    // calcualte the used ram in the system
    int ram_used = (ram_total_out - ram_av_out - (ram_buffer_out + ram_cached_out))/1048576;
    // get the precentage
    int ram_used_perc = (ram_used * 100) / (ram_total_out/1048576);
    // main will print out all of the info and the feeling. (when it's done the percentages and all of that will not be displayed)
    printf("BAT: %d%%\n", bat_perc());
    printf("RAM perc: %d%%\n", ram_used_perc);
    printf("%s", bat_rating(bat_perc()));
    printf("%s", ram_rating(ram_used_perc));
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
        strcpy(bat_feeling, "I'm good with the battery\n");
        total_feeling_rate += 3;
    }
    else if (bat_percent<=99 && bat_percent>80){
        strcpy(bat_feeling, "I'm great with the battery!\n");
        total_feeling_rate += 4;
    }
    else if (bat_percent==100){
        strcpy(bat_feeling, "I'm fully energized!\n");
        total_feeling_rate += 5;
    }
    return bat_feeling;
}

const char *ram_rating(int ram_perc){
    static char ram_feeling[46];
    if(ram_perc==100){
        strcpy(ram_feeling, "AAAAAAAAAAAAAAAAAAAAHHH my RAM is gonna FRY!\n");
        total_feeling_rate += 1;
    }
    else if (ram_perc<=99 && ram_perc>80){
        strcpy(ram_feeling, "My RAM is melting\n");
        total_feeling_rate += 2;
    }
    else if (ram_perc<=80 && ram_perc>50){
        strcpy(ram_feeling, "My RAM is not being spared by the user\n");
        total_feeling_rate += 3;
    }
    else if (ram_perc<=50 && ram_perc>30){
        strcpy(ram_feeling, "The RAM is quite OK\n");
        total_feeling_rate += 4;
    }
    else if (ram_perc<=30 && ram_perc>=0){
        strcpy(ram_feeling, "The RAM very cool\n");
        total_feeling_rate += 5;
    }
    return ram_feeling;
}
