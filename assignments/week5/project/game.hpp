#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "turn.hpp"

class Game{
private:
    std::vector<std::shared_ptr<Turn>> turns;
    void drawSFMLTurn();
    void drawTextTurn();
    void undoTurn();
    bool detectWin();
    void handleInput();

public:
    Game(){
        turns.reserve(9);
    }
    void runSFML();
    void runText();
    
};
