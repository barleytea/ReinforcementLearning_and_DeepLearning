/*    Rock-paper-scissors    */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SEED 65535
#define ROCK 0
#define SCISSORS 1
#define PAPER 2
#define WIN 1
#define LOSE -1
#define DRAW 0
#define ALPHA 0.01 /* learning rate */

int hand (double rate[]);
double frand(void);

int main() {
    int n = 0;
    int myHand, oHand;
    double rate[3] = {1, 1, 1};
    int gain;
    int payoffMatrix[3][3] = {{DRAW, WIN, LOSE},
                              {LOSE, DRAW, WIN},
                              {WIN, LOSE, DRAW}};

    while (scanf("%d", &oHand) != EOF) {
        if ((oHand < ROCK) || (oHand > PAPER)) continue;
        myHand = hand(rate);
        gain = payoffMatrix[myHand][oHand];
        printf("%d %d %d   ", myHand, oHand, gain);
        rate[myHand] += gain * ALPHA * rate[myHand];
        printf("%lf  %lf  %lf\n", rate[ROCK], rate[SCISSORS], rate[PAPER]);
    }

    return 0;
}

int hand(double rate[]) {
    double rock, scissors, paper;
    rock = rate[ROCK] * frand();
    scissors = rate[SCISSORS] * frand();
    paper = rate[PAPER] * frand();
    printf("%lf  %lf  %lf\n", rock, scissors, paper);
    if (rock > scissors) {
        if (rock > paper) return ROCK;
        else return PAPER;
    } else {
        if (scissors > paper) return SCISSORS;
        else return PAPER;
    }
}

double frand(void) {
    return (double)rand() / RAND_MAX;
}

