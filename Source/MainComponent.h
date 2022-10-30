#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    //MainComponent();
    MainComponent(juce::StringArray _args);
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    //project name
    juce::Label label1;
    juce::TextEditor line1;
    //asset name
    juce::TextEditor line2;
    juce::Label label2;
    //task name
    juce::TextEditor line3;
    juce::Label label3;
    //subtask name
    juce::TextEditor line4;
    juce::Label label4;
    //work version
    juce::TextEditor line5;
    juce::Label label5;

    //save button
    juce::TextButton m_saveButton;
    juce::TextButton m_quitButton;

    void SaveAsset();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
