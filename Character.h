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
	int x, y;
	int width, height;
	int hit_x, hit_y;
	int hit_width, hit_height;
	void remove() { remove_flag  = true; }
public:
	Character();
	void setImage(char*);
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

int Character::loaded_images[] = {};

// 弾クラス
class Shot : public Character {
public:
	Shot();
	CharacterType getType() { return TYPE_SHOT; }
	CharacterType hitType() { return TYPE_ENEMY; }
	void move();
	void hit();
};

			 // プレイヤークラス
		 class Player : public Character {
			 bool shot_flag;
						int dead_time;
public:
	Player();
	CharacterType getType() { return TYPE_PLAYER; }
	void move();
	void draw();
	void hit();
		 };

						// 敵クラス
					class Enemy : public Character {
public:
	Enemy();
	CharacterType getType() { return TYPE_ENEMY; }
	CharacterType hitType() { return TYPE_PLAYER; }
	void move();
	void hit();
					};