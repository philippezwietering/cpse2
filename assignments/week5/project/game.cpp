#include "game.hpp"

void Game::undoTurn(){
    turns.pop_back();
}

void Game::drawTextTurn(){
    bool cellEmpty = true;
    std::cout << "|-----|" << std::endl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cellEmpty = true;
            std::cout << "|";
            for(auto obj : turns){
                if(i == obj->getX() && j == obj->getY()){
                    cellEmpty = false;
                    std::cout << (obj->getO() ? "o" : "x");
                    break;
                }
            }
            if(cellEmpty){
                std::cout << " ";
            }
        }
        std::cout << "|" << std::endl << "|-----|" << std::endl;
    }
}

bool Game::detectWin(){
    if(turns.size() < 3){ return false; }
    bool lastO = turns.back()->getO();
    int numberInRow = 0;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(auto obj: turns){
                if(obj->getX() == i && obj->getY() == j && obj->getO() == lastO){
                    numberInRow++;
                }
            }
        }
        if(numberInRow == 3){
            return true;
        }
        numberInRow = 0;
    }

    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i){
            for(auto obj: turns){
                if(obj->getX() == i && obj->getY() == j && obj->getO() == lastO){
                    numberInRow++;
                }
            }
        }
        if(numberInRow == 3){
            return true;
        }
        numberInRow = 0;
    }

    for(int i = 0; i < 3; ++i){
        for(auto obj: turns){
            if(obj->getX() == i && obj->getY() == i && obj->getO() == lastO){
                numberInRow++;
            }
        }
    }
    if(numberInRow == 3){
        return true;
    }
    numberInRow = 0;

    for(int i = 0; i < 3; ++i){
        for(auto obj: turns){
            if(obj->getX() == 2-i && obj->getY() == 2-i && obj->getO() == lastO){
                numberInRow++;
            }
        }
    }
    if(numberInRow == 3){
        return true;
    }

    return false;   //If no win is possible
}

void Game::runText(){
    drawTextTurn();
    while(!detectWin()){
        if(turns.size() > 8){
            std::cout << "DRAW" << std::endl;
            return;
        } else{
            handleInput();
            drawTextTurn();
        }
    }
    std::cout << (turns.back()->getO() ? "o" : "x") << " won!!! You're the cool kid now!" << std::endl;
}

void Game::runSFML(){
    drawSFMLTurn();
    while(!detectWin()){
        if(turns.size() > 8){
            std::cout << "DRAW" << std::endl;
            return;
        } else{
            handleInput();
            drawSFMLTurn();
        }
    }
}

void Game::handleInput(){
    int x, y;
    std::cout << "Put in x-coördinate: ";
    std::cin >> x;
    std::cout << "Put in y-coördinate: ";
    std::cin >> y;

    if(x < 0){x = 0;}   if(x > 2){x = 2;}
    if(y < 0){y = 0;}   if(y > 2){y = 2;}
    //auto t = textInputFactory(input);

    if(!turns.empty() && turns.back()->getX() == x && turns.back()->getY() == y){
        std::cout << "That space is already taken!" << std::endl;
        handleInput();
        return;
    }

    bool lastO;
    if(turns.empty()){
        lastO = true;
    } else{
        lastO = !turns.back()->getO();
    }
    turns.push_back(std::make_shared<Turn>(Turn(x, y, lastO)));
}
