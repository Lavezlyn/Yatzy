#include "yatzy1.hpp"
#include <string.h>
#include <array>
#include "./number.h"

std::array<int, 6> countDice(int d1, int d2, int d3, int d4, int d5){
    std::array<int, 6> counts = {0,0,0,0,0,0};
    counts[d1-1]++;
    counts[d2-1]++;
    counts[d3-1]++;
    counts[d4-1]++;
    counts[d5-1]++;
    return counts;
}

int Yatzy1::Chance(int d1, int d2, int d3, int d4, int d5)
{
    return d1 + d2 + d3 + d4 + d5;
}


int Yatzy1::yatzy(int dice[])
{
    if (dice[0] == dice[1] && dice[0] == dice[2] && dice[0] == dice[3] && dice[0] == dice[4])
        return 50;
    return 0;
}

int Yatzy1::Ones(int d1, int d2, int d3, int d4, int d5) {
    return Strategy(1).countScore(d1, d2, d3, d4, d5);
}

int Yatzy1::Twos(int d1, int d2, int d3, int d4, int d5) {
    return Strategy(2).countScore(d1, d2, d3, d4, d5);
}


int Yatzy1::Threes(int d1, int d2, int d3, int d4, int d5) {
    return Strategy(3).countScore(d1, d2, d3, d4, d5);
}

Yatzy1::Yatzy1()
{
}

Yatzy1::Yatzy1(int d1, int d2, int d3, int d4, int d5)
{
    dice = new int[5];
    dice[0] = d1;
    dice[1] = d2;
    dice[2] = d3;
    dice[3] = d4;
    dice[4] = d5;
}

int Yatzy1::Fours()
{
    return Strategy(4).countScore(dice[0], dice[1], dice[2], dice[3], dice[4]);
}


int Yatzy1::Fives()
{
    return Strategy(5).countScore(dice[0], dice[1], dice[2], dice[3], dice[4]);
}

int Yatzy1::sixes()
{
   return Strategy(6).countScore(dice[0], dice[1], dice[2], dice[3], dice[4]);
}

int Yatzy1::ScorePair(int d1, int d2, int d3, int d4, int d5)
{
    auto counts = countDice(d1, d2, d3, d4, d5);    
    for (int i = 0; i < 6; i += 1)
        if (counts[5-i] >= 2)
            return (6-i)*2;
}

int Yatzy1::TwoPair(int d1, int d2, int d3, int d4, int d5)
{
    auto counts = countDice(d1, d2, d3, d4, d5);    
    int n = 0;
    int score = 0;
    for (int i = 0; i < 6; i += 1)
        if (counts[5-i] >= 2) {
            n++;
            score += (6-i)*2;
        }
    return n == 2 ? score : 0;

}

int Yatzy1::FourOfAKind(int d1, int d2, int d3, int d4, int d5) {
    auto counts = countDice(d1, d2, d3, d4, d5);
    for (int i = 0; i < 6; i++)
        if (counts[i] >= 4)
            return (i+1) * 4;
    return 0;
}

int Yatzy1::ThreeOfAKind(int d1, int d2, int d3, int d4, int d5)
{
    auto counts = countDice(d1, d2, d3, d4, d5);
    for (int i = 0; i < 6; i++)
        if (counts[i] >= 3)
            return (i+1) * 3;
    return 0;
}


int Yatzy1::SmallStraight(int d1, int d2, int d3, int d4, int d5)
{
    if(countDice(d1, d2, d3, d4, d5) == std::array<int, 6>{1,1,1,1,1,0})
        return 15;
    return 0;
}

int Yatzy1::LargeStraight(int d1, int d2, int d3, int d4, int d5)
{
    if(countDice(d1, d2, d3, d4, d5) == std::array<int, 6>{0,1,1,1,1,1})
        return 20;
    return 0;
}


int Yatzy1::FullHouse(int d1, int d2, int d3, int d4, int d5)
{
    auto counts = countDice(d1, d2, d3, d4, d5);
    bool hasThree = false;
    bool hasTwo = false;
    for (int i = 0; i < 6; i++) {
        if (counts[i] == 3)
            hasThree = true;
        if (counts[i] == 2)
            hasTwo = true;
    }
    return hasThree && hasTwo ? d1 + d2 + d3 + d4 + d5 : 0;
}
