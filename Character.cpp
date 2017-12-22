/*
  ==============================================================================

    Character.cpp
    Created: 8 Dec 2017 11:38:35pm
    Author:  next2

  ==============================================================================
*/

#include "Character.h"

Character::Character() {
	remove_flag  = false;
}

void Character::setImage(char* file_name) {
    /*
	if (loaded_images[getType()] == 0) {
        LoadGraph		loaded_images[getType()] = LoadGraph(file_name);
	}
	image = loaded_images[getType()];
        LoadGraph	GetGraphSize(image, &width, &height);
 	hit_width  = width;
	hit_height = height;
	hit_x = hit_y = 0;
     */
}

void Character::setPosition(int px, int py) {
	x = px; y = py;
}

void Character::setHitArea(int hx, int hy, int hw, int hh) {
	hit_x = hx; hit_y = hy;
	hit_width = hw; hit_height = hh;
}

void Character::draw() {
// DrawGraph	DrawGraph(x, y, image,TRUE);
}

bool Character::hitTest(CharacterRef& dst) {
	int x1 = x + hit_x;
	int y1 = y + hit_y;
	int w1 = hit_width;
	int h1 = hit_height;
	int x2 = dst->x + dst->hit_x;
	int y2 = dst->y + dst->hit_y;
	int w2 = dst->hit_width;
	int h2 = dst->hit_height;
	if (x1 + w1> x2 && x1 < x2  + w2 && y1 + h1 > y2 && y1 < y2 + h2) return true;
	return false;
}

// 弾クラス メンバ関数

Shot::Shot() {
	setImage("shot.png");
}

void Shot::move() {
	x  += 12;
	if (x > Game::WIDTH) remove();
}

void Shot::hit() {
	remove();
}

// プレイヤークラス メンバ関数

Player::Player() {
	setImage("player.png");
	setPosition(30, 200);
	setHitArea(14, 12, 36, 16);
	shot_flag  = false;
	dead_time  = 0;
}

void Player::move() {
	if (dead_time > 0) {
		dead_time--;
		return;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) x  -= 6;
	if (CheckHitKey(KEY_INPUT_RIGHT)) x  += 6;
	if (CheckHitKey(KEY_INPUT_UP)) y  -= 6;
	if (CheckHitKey(KEY_INPUT_DOWN)) y  += 6;
	if (x < -hit_x) x  = -hit_x;
	if (x > Game::WIDTH  - hit_x  - hit_width) x  = Game::WIDTH  - hit_x - hit_width;
	if (y < -hit_y) y  = -hit_y;
	if (y > Game::HEIGHT  - hit_y  - hit_height) y  = Game::HEIGHT  - hit_y  - hit_height;
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (!shot_flag) {
			CharacterRef shot(new Shot());
			shot->setPosition(x  + width  - 16, y  + 16);
			Game::me->addList(shot);
			shot_flag  = true;
		}
	} else {
		shot_flag  = false;
	}
}

void Player::draw() {
	if (dead_time  % 5 == 0) Character::draw();
}

void Player::hit() {
	dead_time  = 50;
}

// 敵クラス メンバ関数

Enemy::Enemy() {
	setImage("enemy.png");
	setPosition(Game::WIDTH, GetRand(Game::HEIGHT  - height)); // GetRand?
}

void Enemy::move() {
	x  -= 4;
	if (x < -width) remove();
}

void Enemy::hit() {
	Game::me->addScore(100);
	remove();
}
