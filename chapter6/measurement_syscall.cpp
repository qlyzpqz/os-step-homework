#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main() {
    int count = 10000;
    struct timeval begin_time, end_time;
    char buf[10];

    gettimeofday(&begin_time, NULL);

    for (int i = 0; i < count; i++) {
        read(0, buf, 0);
    }

    gettimeofday(&end_time, NULL);

    time_t total_time = (end_time.tv_sec - begin_time.tv_sec)*1000 + (end_time.tv_usec - begin_time.tv_usec);

    printf("iterator count=%d\n, total time spend=%d\n, %.3lf\n", count, total_time, (double)total_time / count);
}
