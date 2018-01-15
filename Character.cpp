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
/*

void Character::setImage(char* FileName, int FileSize) { //2引数に変更
	//if (loaded_images[getType()] == 0) { 変更前の記述
// LoadGraph		loaded_images[getType()] = LoadGraph(file_name);
//	}

	image_bg = ImageCache::getFromMemory(FileName, FileSize);

//	image = loaded_images[getType()];　変更前の記述
// LoadGraph	GetGraphSize(image, &width, &height);

 	hit_width  = width;
	hit_height = height;
	hit_x = hit_y = 0;
}

*/

/*
void Character::paint(Graphics& g)
{
	g.clear();


	g.drawImageWithin(image_bg, 0, 0, image_bg.getWidth(), image_bg.getHeight() + 64, RectanglePlacement::yTop, false);
}
*/

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