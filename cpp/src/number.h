#ifndef NUMBER_H
#define NUMBER_H

class Strategy{
    int key;
public:
    Strategy(int number): key(number){}  
    int countScore(int d1, int d2, int d3, int d4, int d5){
        int sum = 0;
        if (d1 == key) sum += key;
        if (d2 == key) sum += key;
        if (d3 == key) sum += key;
        if (d4 == key) sum += key;
        if (d5 == key) sum += key;
        return sum;
    }
};




#endif