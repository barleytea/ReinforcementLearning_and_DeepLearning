/* generate 1000 biased hand */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SEED 65535
#define LASTNO 1000
#define ROCK 0
#define SCISSORS 1
#define PAPER 2

int hand(double rate[]);
double frand(void);

int main(int argc, char *argv[]) {
    int n;
    double rate[3];

    srand(SEED);

    if (argc < 4) {
        fprintf(stderr, "how to use: randgen (ROCK rate), (SCISSORS rate), (PAPER rate)\n");
        exit(1);
    }
    rate[ROCK] = atof(argv[1]);
    rate[SCISSORS] = atof(argv[2]);
    rate[PAPER] = atof(argv[3]);

    for (n = 0; n < LASTNO; ++n) {
        printf("%d\n", hand(rate));
    }
    return 0;
}

int hand(double rate[]) {
    double rock, scissors, paper;

    rock = rate[ROCK] * frand();
    scissors = rate[SCISSORS] * frand();
    paper = rate[PAPER] * frand();

    if(rock > scissors) {
        if (rock > paper) return ROCK;
        else return PAPER;
    } else {
        if (scissors > paper) return SCISSORS;
        else return PAPER;
    }
}

double frand(void) {
    return (double)rand()/RAND_MAX;
}
