#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
    DIR *d;
    struct stat buf;
    struct dirent *de;
    struct passwd *p;
    struct group *g;
    struct tm *t;
    int i, j;
    char P[] = "rwxrwxrwx", AP[10] = " ", time[26];
    d = opendir(".");
    readdir(d);
    readdir(d);
    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &buf);
        if (S_ISDIR(buf.st_mode)) printf("d");
        if (S_ISREG(buf.st_mode)) printf("-");
        if (S_ISCHR(buf.st_mode)) printf("c");
        if (S_ISBLK(buf.st_mode)) printf("b");
        if (S_ISLNK(buf.st_mode)) printf("l");
        if (S_ISFIFO(buf.st_mode)) printf("p");
        if (S_ISSOCK(buf.st_mode)) printf("s");
        for (i = 0, j = (1 << 8); i < 9; i++, j >>= 1) AP[i] = (buf.st_mode & j) ? P[i] : '-';
        printf("%s", AP);
        printf("%2ld", buf.st_nlink);
        p = getpwuid(buf.st_uid);
        printf(" %-15s", p->pw_name);
        g = getgrgid(buf.st_gid);
        printf(" %-10s", g->gr_name);
        printf(" %5ld", buf.st_size);
        t = localtime(&buf.st_mtime);
        strftime(time, sizeof(time), "%b %d %H:%M", t);
        printf(" %s", time);
        printf(" %s\n", de->d_name);
    }
}