#pragma once

#include <iostream>

struct Turn{
private:
    int x;
    int y;
    bool o;
public:
    Turn(int x = 0, int y = 0, bool o = true): x(x), y(y), o(o){}
    int getX(){ return x; }
    int getY(){ return y; }
    bool getO(){ return o; }
    friend std::ostream &operator<<(std::ostream &os, const Turn t){
    	os << '(' << t.x << ", " << t.y << ", " << (t.o ? "O" : "X") << ')';
		  return os;
    }
};
