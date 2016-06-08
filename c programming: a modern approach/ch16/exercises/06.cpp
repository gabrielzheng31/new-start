#include <stdio.h>

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long long_seconds);

int main(void) {
    long long_seconds;
    struct time time2;

    scanf("%ld", &long_seconds);

    time2 = split_time(long_seconds);
    printf("%d:%d:%d\n", time2.hours, time2.minutes, time2.seconds);

    return 0;
}

struct time split_time(long long_seconds) {
    struct time time;

    time.hours = long_seconds / 3600;
    long_seconds -= 3600 * time.hours;
    time.minutes = long_seconds / 60;
    long_seconds -= 60 * time.minutes;
    time.seconds = long_seconds;

    return time;
}
