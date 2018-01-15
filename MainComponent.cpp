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

void MainContentComponent::ImageData(char* Name, int Size)
{
	FileName = Name;
	FileSize = Size;
}

void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

//    g.setFont (Font (16.0f));
 //   g.setColour (Colours::white);
 //   g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);

	g.fillAll(Colours::black);

	image_bg = ImageCache::getFromMemory(FileName, FileSize);
	g.drawImageWithin(image_bg, 0, 0, image_bg.getWidth(), image_bg.getHeight() + 64, RectanglePlacement::yTop, false);

}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
