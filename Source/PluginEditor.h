/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"

//==============================================================================
/**
*/
class QuantumB1AudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Button::Listener
{
public:
    QuantumB1AudioProcessorEditor (QuantumB1AudioProcessor&);
    ~QuantumB1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void buttonClicked(Button* button) override;

private:
    CustomLookAndFeelV1 CustomLookAndFeelV1;
    
    ScopedPointer<Slider> probabilitySlider;
    ScopedPointer<Slider> bendSlider;
    ScopedPointer<Slider> dampSlider;
    ScopedPointer<Slider> tuneSlider;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Slider> driveSlider;
    
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> probabilitySliderAttachment;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> bendSliderAttachment;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> dampSliderAttachment;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> tuneSliderAttachment;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> driveSliderAttachment;
    
    std::unique_ptr<Label> probabilitySliderLabel;
    std::unique_ptr<Label> bendSliderLabel;
    std::unique_ptr<Label> dampSliderLabel;
    std::unique_ptr<Label> tuneSliderLabel;
    std::unique_ptr<Label> decaySliderLabel;
    std::unique_ptr<Label> driveSliderLabel;
    
    std::unique_ptr<Label> baseRadioLabel;
    std::unique_ptr<Label> addRadioLabel;
    std::unique_ptr<Label> baseMarksLabel;
    
    Label* addMarksLabel;
    OwnedArray<Label> addMarksLabelList;
    
    // BASE group
    TextButton* baseButton;
    OwnedArray<TextButton> baseButtonsList;
    ScopedPointer<Slider> baseButtonSlider;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment>baseButtonSliderAttachment;
    
    // ADD group
    TextButton* addButton;
    OwnedArray<TextButton> addButtonsList;
    ScopedPointer<Slider> addButtonSlider;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment>addButtonSliderAttachment;
    
    
    std::unique_ptr<Label> mainLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    QuantumB1AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QuantumB1AudioProcessorEditor)
};
