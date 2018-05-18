#include <iostream>
#include <cstring>
#include "game.hpp"

int main(int argc, char *argv[]){
    if(argc > 0){
    	if(!strcmp(argv[1], "sfml")){
    		Game().runSFML();
    	} else if(!strcmp(argv[1], "text")){
    		Game().runText();
    	}
    }
    return 0;
}
