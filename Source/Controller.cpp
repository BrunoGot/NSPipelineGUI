/*
  ==============================================================================

    Controller.cpp
    Created: 13 Mar 2022 6:17:51pm
    Author:  Natspir

  ==============================================================================
*/


#include "Controller.h"
#include <iostream>
#include <fstream>

Controller::Controller(const juce::String& commandLine)
{
    printf("in Controller\n");
    printf("\n%s",commandLine);
    parseProjectConfiguration(commandLine);
}

Controller::~Controller()
{
}

MainComponent* Controller::get_gui()
{
    return new MainComponent(m_arguments);
}

void Controller::parseProjectConfiguration(const juce::String& cmd)
{
    m_arguments.addTokens(cmd, " ");

    for (int i = 0; i < m_arguments.size(); i++)
    {
        printf("arg = %s\n", m_arguments[i]); // holds next token

    }
}

void Controller::getProjectConfiguration()
{

}

