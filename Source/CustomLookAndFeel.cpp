#include "CustomLookAndFeel.h"

CustomLookAndFeelV1::CustomLookAndFeelV1()
{

}

//==============================================================================
void CustomLookAndFeelV1::drawRotarySlider(Graphics& g,
    int x, int y, int width, int height, float sliderPos,
    float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
    // Ring
    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (2);
    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    g.setColour (juce::Colours::white);
    g.drawEllipse (rx, ry, rw, rw, 3.5f);
    
    // Pointer
    juce::Path p;
    auto pointerLength = radius * 0.55f;
    auto pointerThickness = 6.0f;
    p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
    p.applyTransform (juce::AffineTransform::rotation (toAngle).translated (centreX, centreY));

    g.setColour (juce::Colours::white);
    g.fillPath (p);
}

void CustomLookAndFeelV1::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                       float sliderPos, float minSliderPos, float maxSliderPos,
                       const Slider::SliderStyle style, Slider& slider)
{
    g.fillAll (juce::Colours::black);


    const float fx = (float) x, fy = (float) y, fh = (float) height;

    Path p;

    p.addRectangle (fx , fy, sliderPos - fx, fh);

    
    Colour baseColour (juce::Colours::white);

    g.setColour (baseColour);
    g.fillPath (p);

    g.drawRect (slider.getLocalBounds().toFloat(), 3.8);


}

void CustomLookAndFeelV1::drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    auto buttonArea = button.getLocalBounds();
    
    float fx = (float) buttonArea.getX(), fy = (float) buttonArea.getY(), fw = (float) buttonArea.getWidth(), fh = (float) buttonArea.getHeight();
    
    if (button.getToggleState()) {
        g.setColour(juce::Colours::white);
        g.fillRect (fx + 8, fy + 8, fw/2, fh/2);
    } else {
        g.setColour (juce::Colours::black);
        g.fillRect (buttonArea);
    }
    
    g.setColour(juce::Colours::white);
    g.drawRect(button.getLocalBounds().toFloat(), 3.f);
}

void CustomLookAndFeelV1::drawButtonText(Graphics& g, TextButton &, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    g.setColour(juce::Colours::black);
}

