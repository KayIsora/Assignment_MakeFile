#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define FILE_NAME "bigfile.txt"
#define BUF_SIZE 1024

// get time with nanosecond precision
double get_time() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

void test_read() {
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) { perror("open"); exit(1); }

    char buf[BUF_SIZE];
    ssize_t n;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        // only read, do not print
    }

    close(fd);
}

void test_fgets() {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) { perror("fopen"); exit(1); }

    char buf[BUF_SIZE];
    while (fgets(buf, sizeof(buf), f)) {
        // only read, do not print
    }

    fclose(f);
}

int main() {
    double start, end;

    printf("Benchmark read()...\n");
    start = get_time();
    test_read();
    end = get_time();
    printf("Time read():  %f seconds\n", end - start);

    printf("Benchmark fgets()...\n");
    start = get_time();
    test_fgets();
    end = get_time();
    printf("Time fgets(): %f seconds\n", end - start);

    return 0;
}
