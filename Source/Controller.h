#pragma once

#include <JuceHeader.h>
#include "MainComponent.h"
//#include "MainWindow.h"


//==============================================================================

class Controller
{
public:
    //==============================================================================
    Controller(const juce::String&);
    ~Controller();

    //==============================================================================
    MainComponent* get_gui();
private:
    //==============================================================================
    // Your private member variables go here...
    juce::StringArray m_arguments;

    //std::unique_ptr<NSPipelinePOCApplication::MainWindow> mainWindow;
    
    void getProjectConfiguration();
    
    void parseProjectConfiguration(const juce::String& cmd);

};