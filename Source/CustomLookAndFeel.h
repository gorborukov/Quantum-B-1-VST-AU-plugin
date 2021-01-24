#pragma once

#include <JuceHeader.h>

class CustomLookAndFeelV1 : public LookAndFeel_V4
{
public:
    CustomLookAndFeelV1();
    
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;
    void drawLinearSlider(Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider &) override;
    void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    void drawButtonText(Graphics& g, TextButton &, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
private:
    Image img1;
};
