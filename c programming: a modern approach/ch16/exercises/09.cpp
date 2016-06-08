#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);

int main(void) {
    int red, green, blue;
    scanf("%d %d %d", &red, &green, &blue);
    getRed(make_color(red, green, blue));

    struct color color1, color2;
    scanf("%d %d %d", &color1.red, &color1.green, &color1.blue);
    scanf("%d %d %d", &color2.red, &color2.green, &color2.blue);
    equal_color(color1, color2);
}

struct color make_color(int red, int green, int blue) {
    struct color new;

    if (red < 0)
      new.red = 0;
    else if (red > 255)
      new.red = 255;
    else
      new.red = red;

    if (green < 0)
      new.green = 0;
    else if (green > 255)
      new.green = 255;
    else
      new.green = green;

    if (blue < 0)
      new.blue = 0;
    else if (blue > 255)
      new.blue = 255;
    else
      new.blue = blue;

    return new;
}

int getRed(struct color c) {
    return c.red;
}

bool equal_color(struct color color1, struct color color2) {
    if(color1.red != color2.red)
        return 0;
    if (color1.green != color2.green)
        return 0;
    if (color1.blue != color2.blue)
        return 0;
    else
        return 1;
}