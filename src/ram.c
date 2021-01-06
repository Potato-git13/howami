#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *ram_total(){
    FILE *fp;

    fp = fopen("/proc/meminfo", "r");
    
    size_t n = 0;
    char *line = NULL;
    while (getline(&line, &n, fp) > 0) {
        if (strstr(line, "MemTotal")) {
            return line;
        }
    }
    free(line);
    return "not found";
}
