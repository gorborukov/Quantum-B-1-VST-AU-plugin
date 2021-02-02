/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

static const Font& getMontserratExtraBoldFont()
{
    static Font MontserratExtraBold (Font (Typeface::createSystemTypefaceFor (BinaryData::MontserratExtraBold_ttf,
                                                                        BinaryData::MontserratExtraBold_ttfSize)));
    return MontserratExtraBold;
}

static const Font& getMontserratBlackFont()
{
    static Font MontserratBlack (Font (Typeface::createSystemTypefaceFor (BinaryData::MontserratBlack_ttf,
                                                                        BinaryData::MontserratBlack_ttfSize)));
    return MontserratBlack;
}



//==============================================================================
QuantumB1AudioProcessorEditor::QuantumB1AudioProcessorEditor (QuantumB1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // BASE group
    for (int i = 0; i < 3; ++i)
    {
        baseButtonsList.add(baseButton = new TextButton);
        addAndMakeVisible(baseButtonsList[i]);
        baseButtonsList[i]->setClickingTogglesState(true);
        baseButtonsList[i]->setRadioGroupId(34567);
        baseButtonsList[i]->setBounds(39 + i * 38, 144, 32, 32);
        baseButtonsList[i]->setButtonText((String) i);
        baseButtonsList[i]->setLookAndFeel(&CustomLookAndFeelV1);
        baseButtonsList[i]->addListener(this);
        if (i == 0)
            baseButtonsList[i]->setToggleState(true, false);
    }
    
    addAndMakeVisible(baseButtonSlider = new Slider("Base"));
    baseButtonSlider->setBounds(0, 0, 0, 0);
    
    baseButtonSlider.get()->onValueChange = [this] {
        baseButtonsList[(int)baseButtonSlider->getValue()]->setToggleState(true, false);
    };
    
    baseButtonSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "base", *baseButtonSlider);
    // END BASE group
    
    // ADD group
    for (int i = 0; i < 8; ++i)
    {
        addButtonsList.add(addButton = new TextButton);
        addAndMakeVisible(addButtonsList[i]);
        addButtonsList[i]->setClickingTogglesState(true);
        addButtonsList[i]->setRadioGroupId(45678);
        addButtonsList[i]->setBounds(39 + i * 38, 247, 32, 32);
        addButtonsList[i]->setButtonText((String) i);
        addButtonsList[i]->setLookAndFeel(&CustomLookAndFeelV1);
        addButtonsList[i]->addListener(this);
        if (i == 0)
            addButtonsList[i]->setToggleState(true, false);
    }
    
    addAndMakeVisible(addButtonSlider = new Slider("Add"));
    addButtonSlider->setBounds(0, 0, 0, 0);
    
    addButtonSlider.get()->onValueChange = [this] {
        addButtonsList[(int)addButtonSlider->getValue()]->setToggleState(true, false);
    };
    
    addButtonSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "add", *addButtonSlider);
    // END ADD group
    
    addAndMakeVisible(probabilitySlider = new Slider("Probability"));
    probabilitySlider->setLookAndFeel(&CustomLookAndFeelV1);
    probabilitySlider->setSliderStyle(Slider::LinearBar);
    probabilitySlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    probabilitySlider->setBounds(178, 144, 160, 32);
    
    addAndMakeVisible(bendSlider = new Slider("Bend"));
    bendSlider->setLookAndFeel(&CustomLookAndFeelV1);
    bendSlider->setSliderStyle(Slider::Rotary);
    bendSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    bendSlider->setBounds(90, 348, 70, 70);
    
    addAndMakeVisible(dampSlider = new Slider("Damp"));
    dampSlider->setLookAndFeel(&CustomLookAndFeelV1);
    dampSlider->setSliderStyle(Slider::Rotary);
    dampSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    dampSlider->setBounds(210, 348, 70, 70);
    
    addAndMakeVisible(tuneSlider = new Slider("Tune"));
    tuneSlider->setLookAndFeel(&CustomLookAndFeelV1);
    tuneSlider->setSliderStyle(Slider::Rotary);
    tuneSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    tuneSlider->setBounds(33, 466, 70, 70);
    
    addAndMakeVisible(decaySlider = new Slider("Decay"));
    decaySlider->setLookAndFeel(&CustomLookAndFeelV1);
    decaySlider->setSliderStyle(Slider::Rotary);
    decaySlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    decaySlider->setBounds(150, 466, 70, 70);
    
    addAndMakeVisible(driveSlider = new Slider("Drive"));
    driveSlider->setLookAndFeel(&CustomLookAndFeelV1);
    driveSlider->setSliderStyle(Slider::Rotary);
    driveSlider->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    driveSlider->setBounds(268, 466, 70, 70);
    
    // Sliders attachments
    
    probabilitySliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "probability", *probabilitySlider);
    bendSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "bend", *bendSlider);
    dampSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "damp", *dampSlider);
    tuneSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "tune", *tuneSlider);
    decaySliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "decay", *decaySlider);
    driveSliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveSlider);
    
    // Main label
    
    mainLabel.reset(new Label("Main Label", TRANS("QUANTUM B-1")));
    addAndMakeVisible(mainLabel.get());
    mainLabel->setJustificationType (Justification::left);
    mainLabel->setFont(getMontserratBlackFont().withHeight(42.00f));
    mainLabel->setColour (Label::textColourId, Colour (0xffffffff));
    mainLabel->setEditable (false, false, false);
    mainLabel->setBounds(34, 40, 250, 38);
    
    // Components labels
    
    baseRadioLabel.reset(new Label("Base Radio Label", TRANS("BASE")));
    addAndMakeVisible(baseRadioLabel.get());
    baseRadioLabel->setJustificationType (Justification::left);
    baseRadioLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    baseRadioLabel->setColour (Label::textColourId, Colour (0xffffffff));
    baseRadioLabel->setEditable (false, false, false);
    baseRadioLabel->setBounds(34, 116, 70, 20);
    
    addRadioLabel.reset(new Label("Add Radio Label", TRANS("ADD")));
    addAndMakeVisible(addRadioLabel.get());
    addRadioLabel->setJustificationType (Justification::left);
    addRadioLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    addRadioLabel->setColour (Label::textColourId, Colour (0xffffffff));
    addRadioLabel->setEditable (false, false, false);
    addRadioLabel->setBounds(34, 220, 70, 20);
    
    probabilitySliderLabel.reset(new Label("Probability Slider Label", TRANS("PROBABILITY")));
    addAndMakeVisible(probabilitySliderLabel.get());
    probabilitySliderLabel->setJustificationType (Justification::left);
    probabilitySliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    probabilitySliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    probabilitySliderLabel->setEditable (false, false, false);
    probabilitySliderLabel->setBounds(174, 116, 110, 20);
    
    
    bendSliderLabel.reset(new Label("Bend Label", TRANS("BEND")));
    addAndMakeVisible(bendSliderLabel.get());
    bendSliderLabel->setJustificationType (Justification::centred);
    bendSliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    bendSliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    bendSliderLabel->setEditable (false, false, false);
    bendSliderLabel->setBounds(90, 322, 70, 20);
    
    dampSliderLabel.reset(new Label("Damp Label", TRANS("DAMP")));
    addAndMakeVisible(dampSliderLabel.get());
    dampSliderLabel->setJustificationType (Justification::centred);
    dampSliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    dampSliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    dampSliderLabel->setEditable (false, false, false);
    dampSliderLabel->setBounds(210, 322, 70, 20);
    
    tuneSliderLabel.reset(new Label("Tune Label", TRANS("TUNE")));
    addAndMakeVisible(tuneSliderLabel.get());
    tuneSliderLabel->setJustificationType (Justification::centred);
    tuneSliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    tuneSliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    tuneSliderLabel->setEditable (false, false, false);
    tuneSliderLabel->setBounds(32, 440, 70, 20);
    
    decaySliderLabel.reset(new Label("Decay Label", TRANS("DECAY")));
    addAndMakeVisible(decaySliderLabel.get());
    decaySliderLabel->setJustificationType (Justification::centred);
    decaySliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    decaySliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    decaySliderLabel->setEditable (false, false, false);
    decaySliderLabel->setBounds(150, 440, 70, 20);
    
    driveSliderLabel.reset(new Label("Drive Label", TRANS("DRIVE")));
    addAndMakeVisible(driveSliderLabel.get());
    driveSliderLabel->setJustificationType (Justification::centred);
    driveSliderLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    driveSliderLabel->setColour (Label::textColourId, Colour (0xffffffff));
    driveSliderLabel->setEditable (false, false, false);
    driveSliderLabel->setBounds(266, 440, 70, 20);
    
    // Base Marks Labels
    baseMarksLabel.reset(new Label("Base Marks Label", TRANS("IV      II        I")));
    addAndMakeVisible(baseMarksLabel.get());
    baseMarksLabel->setJustificationType (Justification::centred);
    baseMarksLabel->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
    baseMarksLabel->setColour (Label::textColourId, Colour (0xffffffff));
    baseMarksLabel->setEditable (false, false, false);
    baseMarksLabel->setBounds(40.7, 185, 100, 20);
    
    // Add Marks Labels
    for (int i = 0; i < 8; ++i)
    {
        addMarksLabelList.add(addMarksLabel = new Label("", TRANS((String) (i+1))));
        addAndMakeVisible(addMarksLabelList[i]);
        addMarksLabelList[i]->setJustificationType(Justification::left);
        addMarksLabelList[i]->setFont(getMontserratExtraBoldFont().withHeight(17.00f));
        addMarksLabelList[i]->setColour (Label::textColourId, Colour (0xffffffff));
        addMarksLabelList[i]->setEditable (false, false, false);
        addMarksLabelList[i]->setBounds(46 + i * 38, 288, 296, 20);
    }

    setSize (370, 580);
}

QuantumB1AudioProcessorEditor::~QuantumB1AudioProcessorEditor()
{
}

//==============================================================================
void QuantumB1AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colour(0xff000000));
    g.setColour (juce::Colours::white);
}

void QuantumB1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void QuantumB1AudioProcessorEditor::buttonClicked(Button* button)
{
    //if (button->getRadioGroupId() == 34567) {
    //    Logger::writeToLog(button->getButtonText());
    //    baseButtonSlider->setValue(button->getButtonText().getFloatValue());
    //}
    switch (button->getRadioGroupId()) {
        case 34567:
            baseButtonSlider->setValue(button->getButtonText().getFloatValue());
            break;
        case 45678:
            addButtonSlider->setValue(button->getButtonText().getFloatValue());
            break;
        default:
            break;
    }
}
