#pragma once

class Turn{
private:
    int x;
    int y;
    bool o;
public:
    Turn(int x = 0, int y = 0, bool o = true): x(x), y(y), o(o){}
    int getX(){ return x; }
    int getY(){ return y; }
    bool getO(){ return o; }
};
