#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

struct fraction gcd(struct fraction);
struct fraction additon(struct fraction, struct fraction);
struct fraction subtraction(struct fraction, struct fraction);
struct fraction multiplication(struct fraction, struct fraction);
struct fraction division(struct fraction, struct fraction);

int main(void) {
    struct fraction f, f1, f2;
    struct fraction ff;
    scanf("%d %d", &f.numerator, &f.denominator);
    scanf("%d %d", &f1.numerator, &f1.denominator);
    scanf("%d %d", &f2.numerator, &f2.denominator);

    ff = gcd(f);
    printf("%d/%d\n", ff.numerator, ff.denominator);

    ff = additon(f1, f2);
    printf("%d/%d\n", ff.numerator, ff.denominator);

    ff = subtraction(f1, f2);
    printf("%d/%d\n", ff.numerator, ff.denominator);

    ff = multiplication(f1, f2);
    printf("%d/%d\n", ff.numerator, ff.denominator);

    ff = division(f1, f2);
    printf("%d/%d\n", ff.numerator, ff.denominator);
}

struct fraction gcd(struct fraction f) {
    struct fraction ff;
    ff = f;

    while (f.denominator != 0) {
        int temporary = f.denominator;
        f.denominator = f.numerator % f.numerator;
        f.numerator = temporary;
    }
    ff.denominator /= f.numerator;
    ff.numerator /= f.numerator;
    return ff;
}

struct fraction additon(struct fraction f1, struct fraction f2) {
    struct fraction f3;
    f3.denominator = f1.denominator * f2.denominator;
    f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f3 = gcd(f3);
    return f3;
}

struct fraction subtraction(struct fraction f1, struct fraction f2) {
    struct fraction f3;
    f3.denominator = f1.denominator * f2.denominator;
    f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f3 = gcd(f3);
    return f3;
}

struct fraction multiplication(struct fraction f1, struct fraction f2) {
    struct fraction f3;
    f3.denominator = f1.denominator * f2.denominator;
    f3.numerator = f1.numerator * f2.numerator;
    f3 = gcd(f3);
    return f3;
}

struct fraction division(struct fraction f1, struct fraction f2) {
    struct fraction f3;
    f3.denominator = f1.denominator * f2.numerator;
    f3.numerator = f1.numerator * f2.denominator;
    f3 = gcd(f3);
    return f3;
}
