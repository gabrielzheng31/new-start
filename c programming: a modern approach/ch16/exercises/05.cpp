#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int day_of_year(struct date);
int compare_dates(struct date, struct date);

int main(void) {
    struct date d, d1, d2;
    scanf("%d %d %d", &d.month, &d.day, &d.year);
    scanf("%d %d %d", &d1.month, &d1.day, &d1.year);
    scanf("%d %d %d", &d2.month, &d2.day, &d2.year);
    printf("%d\n", day_of_year(d));
    printf("%d\n", compare_dates(d1, d2));

    return 0;
}

int day_of_year(struct date d) {
    int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int count = 0;
    for (int i = 1; i < d.month; i++)
        count += days[i-1];

    count += d.day;

    if (((d.year%100!=0 && d.year%4==0)||d.year%400==0)&&d.month>2)
        count++;

    return count;
}

int compare_dates(struct date d1, struct date d2) {
    if (d1.year > d2.year)
        return 1;
    else if (d1.year < d2.year)
        return -1;
    else {
        if (day_of_year(d1) > day_of_year(d2))
            return 1;
        else if (day_of_year(d1) < day_of_year(d2))
            return -1;
        else
            return 0;
    }
}
