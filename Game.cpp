/*
  ==============================================================================

    Game.cpp
    Created: 27 Nov 2017 3:34:57pm
    Author:  next2

  ==============================================================================
*/

#include "Game.h"
#include "Character.h"

Game::Game() {
}

Game::~Game() {
}

void Game::Play(){
	CharacterRef player(new Player()); //Player生成
    while (true) {
        
        //Player move()
        //Enemy move()
        //Ballet move()
        
        /*
        if(){
            CreateEnemy();
        }
        */
        
        
    }
}

void Game::CreateEnemy(/*座標*/){
	CharacterRef enemy(new Enemy());  //Enemy生成
}
