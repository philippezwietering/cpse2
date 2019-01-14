#include "game.hpp"

void Game::undoTurn(){
    turns.pop_back();
}

void Game::drawTextBoard(){
    bool cellEmpty = true;
    std::cout << "|-----------|" << std::endl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cellEmpty = true;
            std::cout << "|";
            for(auto obj : turns){
                if(i == obj->getX() && j == obj->getY()){
                    cellEmpty = false;
                    std::cout << (obj->getO() ? " o " : " x ");
                    break;
                }
            }
            if(cellEmpty){
                std::cout << "   ";
            }
        }
        std::cout << "|" << std::endl << "|-----------|" << std::endl;
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
            if(obj->getX() == 2-i && obj->getY() == i && obj->getO() == lastO){
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
    drawTextBoard();
    while(!detectWin()){
        if(turns.size() > 8){
            std::cout << "DRAW!" << std::endl;
            return;
        } else{
            handleTextInput();
            drawTextBoard();
        }
    }
    std::cout << (turns.back()->getO() ? "o" : "x") << " won!!! You're the cool kid now!" << std::endl;
}

void Game::runSFML(){
    sf::RenderWindow mainWindow(sf::VideoMode(380, 380), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
    mainWindow.setFramerateLimit(60);

    std::list<block> tiles;
    std::list<picture> cheeses;
    std::list<picture> butters;
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        block b = block(j, i, sf::Vector2f(20+i*120, 20+j*120), sf::Vector2f(100, 100), sf::Color::Blue);
        tiles.push_back(b);

        picture cheese = picture(j, i, sf::Vector2f(20+i*120, 20+j*120), "project/boter.png");
        cheeses.push_back(cheese);
      }
    }

    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        picture butter = picture(j, i, sf::Vector2f(20+i*120, 20+j*120), "project/kaas.png");
        butters.push_back(butter);
      }
    }

    while(mainWindow.isOpen()){

        sf::Event event;
        while(mainWindow.pollEvent(event)){
          switch(event.type){

            case sf::Event::Closed:
              mainWindow.close();
              break;

            case sf::Event::KeyPressed:
              if(event.key.code == sf::Keyboard::U && !turns.empty()){
                undoTurn();
              }
              break;

            case sf::Event::MouseButtonReleased:
              if(event.mouseButton.button == sf::Mouse::Left){
                //std::cout << "Click on " << event.mouseButton.x << ", " << event.mouseButton.y << '\n';

                for(auto b : tiles){
                  if(b.getBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                    //std::cout << "Found block " << b.xId << ", " << b.yId <<"\n";

                    if(turns.empty()){
                      turns.push_back(std::make_shared<Turn>(Turn(b.xId, b.yId, true)));
                    } else if(!(turns.back()->getX() == b.xId && turns.back()->getY() == b.yId)){
                      turns.push_back(std::make_shared<Turn>(Turn(b.xId, b.yId, !turns.back()->getO())));
                    }
                    else{
                      std::cout << "The tile " << *turns.back() << " is already taken!\n";
                    }
                  }
                }
                if(detectWin()){
                  std::cout << (turns.back()->getO() ? "o" : "x") << " won!!! You're the cool kid now!\n";
                  mainWindow.close();
                } else if(turns.size() > 8){
                  std::cout << "It's a draw!\n";
                  mainWindow.close();
                }
              }
              break;

            default:
              break;
          }
        }
        mainWindow.clear();

        for(auto b : tiles){
          b.draw(mainWindow);
        }

        for(auto t : turns){
          int it = t->getY()*3+t->getX();
          if(t->getO()){
            for(auto cheese : cheeses){
              if(it == cheese.xId*3+cheese.yId){
                cheese.draw(mainWindow);
                break;
              }
            }
          } else{
            for(auto butter : butters){
              if(it == butter.xId*3+butter.yId){
                butter.draw(mainWindow);
                break;
              }
            }
          }
        }

        mainWindow.display();
        sf::sleep(sf::milliseconds(50));
    }
}

void Game::handleTextInput(){
    std::string input;
    std::cout << "Put in x-coordinate or undo:\n";
    std::cin >> input;

    if(input == "undo" || input == "u"){
      if(turns.empty()){
        return;
      }
      undoTurn();
      return;
    }

    int x, y;
    x = std::stoi(input);
    std::cout << "Put in y-coordinate:\n";
    std::cin >> input;
    y = std::stoi(input);

    if(x < 0){x = 0;}   if(x > 2){x = 2;}
    if(y < 0){y = 0;}   if(y > 2){y = 2;}

    if(!turns.empty()){
        for(auto obj: turns){
            if(obj->getX() == x && obj->getY() == y){
                std::cout << "The space " << *obj  << " is already taken!" << '\n';
                handleTextInput();
                return;
            }
        }
    }

    bool lastO;
    if(turns.empty()){
        lastO = true;
    } else{
        lastO = !turns.back()->getO();
    }
    turns.push_back(std::make_shared<Turn>(Turn(x, y, lastO)));

}
