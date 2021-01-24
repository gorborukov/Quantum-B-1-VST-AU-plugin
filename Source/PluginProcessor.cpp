/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
QuantumB1AudioProcessor::QuantumB1AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    context = hv_B1_new(44100.0);
    
    state = new AudioProcessorValueTreeState(*this, nullptr);
    
    state->createAndAddParameter("base", "Base", "Base", NormalisableRange<float>(0.f, 2.f, 1.f), 0.f, nullptr, nullptr);
    state->createAndAddParameter("add", "Add", "Add", NormalisableRange<float>(0.f, 7.f, 1.f), 0.f, nullptr, nullptr);
    
    state->createAndAddParameter("probability", "Probability", "Probability", NormalisableRange<float>(0.f, 100.f, 1.f), 50.f, nullptr, nullptr);
    state->createAndAddParameter("bend", "Bend", "Bend", NormalisableRange<float>(10.f, 999.f, 10.f), 41.f, nullptr, nullptr);
    state->createAndAddParameter("damp", "Damp", "Damp", NormalisableRange<float>(1.f, 500.f, 5.f), 114.f, nullptr, nullptr);
    state->createAndAddParameter("tune", "Tune", "Tune", NormalisableRange<float>(10.f, 999.f, 10.f), 189.f, nullptr, nullptr);
    state->createAndAddParameter("decay", "Decay", "Decay", NormalisableRange<float>(0.f, 1.f, 0.01f), 0.47f, nullptr, nullptr);
    state->createAndAddParameter("drive", "Drive", "Drive", NormalisableRange<float>(0.f, 1000.f, 10.f), 0.f, nullptr, nullptr);
    
    state->state = ValueTree("base");
    state->state = ValueTree("add");
    
    state->state = ValueTree("probability");
    state->state = ValueTree("bend");
    state->state = ValueTree("damp");
    state->state = ValueTree("tune");
    state->state = ValueTree("decay");
    state->state = ValueTree("drive");
}

QuantumB1AudioProcessor::~QuantumB1AudioProcessor()
{
    hv_delete(context);
}

//==============================================================================
const juce::String QuantumB1AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool QuantumB1AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool QuantumB1AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool QuantumB1AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double QuantumB1AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int QuantumB1AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int QuantumB1AudioProcessor::getCurrentProgram()
{
    return 0;
}

void QuantumB1AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String QuantumB1AudioProcessor::getProgramName (int index)
{
    return {};
}

void QuantumB1AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}
/*void sendHook(HeavyContextInterface *c, const char *sendName, unsigned int sendHash, const HvMessage *m) {
    switch (sendHash) {
        case 0xD1D4AC2: {
            auto pitch = hv_msg_getFloat(m, 0);
            std::cout << pitch;
            break;
        }
        default: break;
    }

}*/
//==============================================================================
void QuantumB1AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    if (hv_getSampleRate(context) != sampleRate)
    {
        if (context != nullptr) hv_delete(context);
        context = hv_B1_new(sampleRate);
        
    }
    // hv_setSendHook(context, sendHook);
    status = false;
    
}

void QuantumB1AudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool QuantumB1AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif



//void printHook(HeavyContextInterface *c, const char *printName, const char *str, const HvMessage *m) {
//    std::cout << 36;
//}

void QuantumB1AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{

    /*const HvMessage *m;
    context->getSendHook()(context, "__hv_noteout", 0xD1D4AC2, m);*/
    
    if (!JUCEApplication::isStandaloneApp()) {
        playHead = this->getPlayHead();
        playHead->getCurrentPosition(currentPositionInfo);
        
        float bpm = currentPositionInfo.bpm;
        hv_sendFloatToReceiver(context, 0x1191161E, bpm);
        
        if (!status) {
            if (currentPositionInfo.isPlaying) {
                status = true;
                hv_sendFloatToReceiver(context, 0xA4C9EA90, 1.0);
            } else {
                status = false;
                hv_sendFloatToReceiver(context, 0xA4C9EA90, 0.0);
            }
        } else {
            if (!currentPositionInfo.isPlaying) {
                status = false;
                hv_sendFloatToReceiver(context, 0xA4C9EA90, 0.0);
            }
        }
    }
    
    float base = *state->getRawParameterValue("base");
    float add = *state->getRawParameterValue("add");

    float probability = *state->getRawParameterValue("probability");
    float bend = *state->getRawParameterValue("bend");
    float damp = *state->getRawParameterValue("damp");
    float tune = *state->getRawParameterValue("tune");
    float decay = *state->getRawParameterValue("decay");
    float drive = *state->getRawParameterValue("drive");
    
    hv_sendFloatToReceiver(context, 0x82D58441, base*2);
    hv_sendFloatToReceiver(context, 0x6C1D372F, add);
    
    hv_sendFloatToReceiver(context, 0xADF6E53, probability);
    hv_sendFloatToReceiver(context, 0x7BBCF18C, bend);
    hv_sendFloatToReceiver(context, 0x1FB33D63, damp);
    hv_sendFloatToReceiver(context, 0x59559FD8, tune);
    hv_sendFloatToReceiver(context, 0x11A5B2CB, decay);
    hv_sendFloatToReceiver(context, 0xD5693069, drive);
    
    int time;
    MidiBuffer processedMidi;
    MidiMessage msg;
    
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent(msg, time);) {
        if (msg.isNoteOn()) {
            msg = MidiMessage::noteOn(msg.getChannel(), msg.getNoteNumber()+1, msg.getVelocity());
            hv_sendFloatToReceiver(context, 0xB2EA2CD, 1.0f);
        }
        processedMidi.addEvent(msg, time);
        if (msg.isNoteOff()) {
            msg = MidiMessage::noteOn(msg.getChannel(), msg.getNoteNumber()+1, msg.getVelocity());
        }
        processedMidi.addEvent(msg, time);
        /*if (context->getSendHook() != nullptr) {
            msg = MidiMessage::noteOn(msg.getChannel(), 36, msg.getVelocity());
        }
        processedMidi.addEvent(msg, time);*/
    }
    
    midiMessages.swapWith(processedMidi);
    
    jassert(hv_getSampleRate(context) == getSampleRate());
    float **inBuffers = buffer.getArrayOfWritePointers();
    float **outBuffers = buffer.getArrayOfWritePointers();
    hv_process(context, inBuffers, outBuffers, buffer.getNumSamples());
}

AudioProcessorValueTreeState& QuantumB1AudioProcessor::getState() {
    return *state;
}

//==============================================================================
bool QuantumB1AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* QuantumB1AudioProcessor::createEditor()
{
    return new QuantumB1AudioProcessorEditor (*this);
}

//==============================================================================
void QuantumB1AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    state->state.writeToStream(stream);
}

void QuantumB1AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    ValueTree tree = ValueTree::readFromData(data, sizeInBytes);
    if (tree.isValid())
    {
        state->state = tree;
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new QuantumB1AudioProcessor();
}
