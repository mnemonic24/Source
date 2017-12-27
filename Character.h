/*
  ==============================================================================

    Character.h
    Created: 8 Dec 2017 11:41:24pm
    Author:  next2

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#pragma once

enum CharacterType { TYPE_NONE, TYPE_SHOT, TYPE_PLAYER, TYPE_ENEMY, TYPE_CLOUD, TYPE_NUM };

class Character;
typedef std::shared_ptr<Character> CharacterRef;

class Character {
	static int loaded_images[256];
	bool remove_flag;
protected:
	int image;
	Image image_bg;
	int x, y;
	int width, height;
	int hit_x, hit_y;
	int hit_width, hit_height;
	void remove() { remove_flag  = true; }
public:
	Character();
	void setImage(char*, int);
	void setPosition(int, int);
	void setHitArea(int, int, int, int);

	bool isRemove() { return remove_flag; }
	virtual CharacterType getType() = 0;
	virtual CharacterType hitType() { return TYPE_NONE; }
	virtual void move() = 0;
	virtual void draw();
	bool hitTest(CharacterRef&);
	virtual void hit() {};
};