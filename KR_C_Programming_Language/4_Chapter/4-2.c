#include <stdio.h>
#include <ctype.h>

double atof(char *msg) {
    double val, power;
    int i, j, expo, sign, dec = 1;
    for (i = 0; isspace(msg[i]); i++)
        ;
    sign = (msg[i] == '-') ? -1 : 1;
    if (msg[i] == '+' || msg[i] == '-')
        i++;
    for (val = 0.0; isdigit(msg[i]); i++) {
        val =  val * 10 + (msg[i] - '0');
    }
    if (msg[i] == '.')
        i++;
    for (power = 1.0; isdigit(msg[i]); i++) {
        val = 10.0 * val + (msg[i] - '0');
        power *= 10.0;
    }
    if (msg[i] == 'e') {
            ++i;
        if (msg[i] == '-') {
            dec = -1;
            ++i;
        }
        expo = msg[i] - '0';
        for (j = 0; j < expo; j++) {
            if (dec == -1)
                power *= 10.0;
            else
                power /= 10.0;
        }
    }
    return sign * val / power;
}

int main() {
    double n, atof(char *msg);
    char *input = "123.45e-6";
    n = atof(input);
    printf("%s has been converted into %.6f\n", input, n);

    return 0;
}
