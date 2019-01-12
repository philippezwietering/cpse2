#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "turn.hpp"
#include "block.hpp"
#include "picture.hpp"

class Game{
private:
    std::vector<std::shared_ptr<Turn>> turns;
    void drawTextBoard();
    void undoTurn();
    bool detectWin();
    void handleTextInput();

public:
    Game(){
        turns.reserve(9);
    }
    void runSFML();
    void runText();

};
