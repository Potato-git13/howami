#include <sys/statvfs.h>
#include <stdio.h>

int disk_perc(const char *path){
    struct statvfs filesystem;
    if (statvfs(path, &filesystem) < 0) {
        printf("statvfs '%s':", path);
        return 0;
    }

    return ((int)(100*(1.0f-((float)filesystem.f_bavail/(float)filesystem.f_blocks))));
}
