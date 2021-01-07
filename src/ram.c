#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dltspcs(char *string);

const char *ram_total(){
    FILE *fp;
    fp = fopen("/proc/meminfo", "r");
    size_t n = 0;
    char *line = NULL;
    char *p;

    while (getline(&line, &n, fp) > 0) {
        if (strstr(line, "MemTotal")) {
            fclose(fp);
            // delete the MemTotal part of the string
            memcpy(line, line+9, 30);
            // delete the newline and the kB part of the string
            p = line; 
            p[strlen(p)-3] = 0;
            return line;
        }
    }
    free(line);
    return "err";
}

const char *ram_av(){
    FILE *fp;
    fp = fopen("/proc/meminfo", "r");
    size_t n = 0;
    char *line = NULL;
    char *p;

    while (getline(&line, &n, fp) > 0) {
        if (strstr(line, "MemAvailable")) {
            fclose(fp);
            // delete the MemAvailable part of the string
            memcpy(line, line+13, 30);
            // delete the newline and the kB part of the string
            p = line;
            p[strlen(p)-3] = 0;
            return line;
        }
    }
    free(line);
    return line; 
}

const char *ram_cached(){
    FILE *fp;
    fp = fopen("/proc/meminfo", "r");
    size_t n = 0;
    char *line = NULL;
    char *p;

    while (getline(&line, &n, fp) > 0) {
        if (strstr(line, "Cached")) {
            fclose(fp);
            // delete the Cached part of the string
            memcpy(line, line+6, 30);
            // delete the newline and the kB part of the string
            p = line;
            p[strlen(p)-3] = 0;
            return line;
        }
    }
    free(line);
    return line; 
}

const char *ram_buffer(){
    FILE *fp;
    fp = fopen("/proc/meminfo", "r");
    size_t n = 0;
    char *line = NULL;
    char *p;

    while (getline(&line, &n, fp) > 0) {
        if (strstr(line, "Buffers")) {
            fclose(fp);
            // delete the Buffers part of the string
            memcpy(line, line+7, 30);
            // delete the newline and the kB part of the string
            p = line;
            p[strlen(p)-3] = 0;
            return line;
        }
    }
    free(line);
    return line; 
}
