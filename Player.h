/*
  ==============================================================================

    Player.h
    Created: 21 Nov 2017 6:48:57pm
    Author:  

  ==============================================================================
*/

#pragma once


#include "../JuceLibraryCode/JuceHeader.h"

class Player {
public:
	Player();
	~Player();

	void move(Graphics&);
	void shoot();

private:
	int position;
	bool shootFlag;
};