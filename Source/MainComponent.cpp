#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(juce::StringArray _args)
{
    label1.setText("Project : ", juce::dontSendNotification);
    label2.setText("Asset : ", juce::dontSendNotification);
    label3.setText("Task : ", juce::dontSendNotification);
    label4.setText("Subtask : ", juce::dontSendNotification);
    label5.setText("Work: ", juce::dontSendNotification);
    if (_args.size()==5) {
        line1.setText(_args[0]);
        line2.setText(_args[1]);
        line3.setText(_args[2]);
        line4.setText(_args[3]);
        line5.setText(_args[4]);
    }
    std::cout << "Save Asset";
    setSize (600, 400);
    //juce::TextEditor* line1 = new juce::TextEditor("test");

    m_saveButton.setButtonText("Save Asset");
    m_quitButton.setButtonText("Cancel");

    m_saveButton.onClick = [this] {SaveAsset(); };
    m_quitButton.onClick = [] {juce::JUCEApplicationBase::quit(); };

    addAndMakeVisible(label1);
    addAndMakeVisible(line1);
    addAndMakeVisible(label2);
    addAndMakeVisible(line2);
    addAndMakeVisible(label3);
    addAndMakeVisible(line3);
    addAndMakeVisible(label4);
    addAndMakeVisible(line4);
    addAndMakeVisible(label5);
    addAndMakeVisible(line5);
    addAndMakeVisible(m_saveButton);
    addAndMakeVisible(m_quitButton);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    /*g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    */
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    juce::Grid grid;
    grid.templateRows = { juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(0)) };
    grid.templateColumns = { juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(4)) };
    grid.items = { juce::GridItem(label1),juce::GridItem(line1).withMargin({ 2 }),
                           juce::GridItem(label2),juce::GridItem(line2).withMargin({ 2 }),
                    juce::GridItem(label3),juce::GridItem(line3).withMargin({ 2 }),
                    juce::GridItem(label4),juce::GridItem(line4).withMargin({ 2 }),
                    juce::GridItem(label5),juce::GridItem(line5).withMargin({ 2 }),
                    juce::GridItem(m_saveButton).withMargin({ 2 }),juce::GridItem(m_quitButton).withMargin({ 2 }) };
    grid.performLayout(getLocalBounds());
    juce::Grid buttonsGrid;
    /*
    buttonsGrid.templateRows = { juce::Grid::TrackInfo(juce::Grid::Fr(1))};
    buttonsGrid.templateColumns = { juce::Grid::TrackInfo(juce::Grid::Fr(1)), juce::Grid::TrackInfo(juce::Grid::Fr(4)) };
    buttonsGrid.items = { juce::GridItem(m_saveButton) };
    buttonsGrid.performLayout(getLocalBounds());*/
    std::cout << "Save Asset";
    
}

void MainComponent::SaveAsset() {
    juce::String assetType = line1.getText();
    juce::String asset = line2.getText();
    juce::String task = line3.getText();
    juce::String subtask = line4.getText();
    juce::String work = line5.getText();
    DBG("Test");
    juce::String path = "AssetType : "+assetType + ", AssetName : " + asset + ", Task : " + task + ", Subtask : " + subtask + ", Version : " + work;
    DBG("line1 = " + path);
    printf("\n out path = %s \n", path);
    juce::JUCEApplicationBase::quit();
}
