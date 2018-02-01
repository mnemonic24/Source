/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::jikiPosition(int x, int y)
{
	jikiX = x;
	jikiY = y;
}

void MainContentComponent::tamaPosition(int x, int y)
{
	tamaX = x;
	tamaY = y;
}


void MainContentComponent::targetPosition(int x, int y)
{
	targetX = x;
	targetY = y;
}


void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

//    g.setFont (Font (16.0f));
 //   g.setColour (Colours::white);
 //   g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);

	g.fillAll(Colours::black);

	image_bg = ImageCache::getFromMemory(BinaryData::GUI_base_png, BinaryData::GUI_base_pngSize);
	g.drawImageWithin(image_bg, //image_bg check
		0, 0, // left top xy
		image_bg.getWidth(), image_bg.getHeight() + 64, //wide height
		RectanglePlacement::yTop, //on center
		false);// dont draw on alpha channel
	image_bg = ImageCache::getFromMemory(BinaryData::jiki_png, BinaryData::jiki_pngSize);
	g.drawImageWithin(image_bg, jikiX, jikiY, image_bg.getWidth(), image_bg.getHeight() + 64, RectanglePlacement::yTop, false);
	image_bg = ImageCache::getFromMemory(BinaryData::tama_png, BinaryData::tama_pngSize);
	g.drawImageWithin(image_bg, tamaX, tamaY, image_bg.getWidth(), image_bg.getHeight() + 64, RectanglePlacement::yTop, false);
	image_bg = ImageCache::getFromMemory(BinaryData::target_png, BinaryData::target_pngSize);
	g.drawImageWithin(image_bg, targetX, targetY, image_bg.getWidth(), image_bg.getHeight() + 64, RectanglePlacement::yTop, false);

}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
