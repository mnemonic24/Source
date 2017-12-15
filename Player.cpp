/*
  ==============================================================================

    Player.cpp
    Created: 21 Nov 2017 6:48:41pm
    Author:  next2

  ==============================================================================
*/

#include "Player.h"

Player::Player() {
	position = 30 + 60 * 5;
	shootFlag = 0;
}

Player::~Player() {
}

void Player::move(Graphics& g) {
	g.setColour(Colours::red);	
	g.drawEllipse(position, 200.0, 30.0, 30.0, 15.0);
	g.setColour(Colours::white);
}

void Player::shoot() {
}

