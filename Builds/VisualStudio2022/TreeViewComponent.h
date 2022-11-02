#pragma once
#include <JuceHeader.h>
class TreeViewComponent : public juce::Component
{
public:
    TreeViewComponent();
    void resized() override;
private:
    //==============================================================================
    struct Item : public juce::TreeViewItem
    {
        bool mightContainSubItems() override;
        void paintItem(juce::Graphics& g, int width, int height) override;
        juce::String getAccessibilityName() override;

        const juce::String textToDisplay;
    };

    struct RootItem : public juce::TreeViewItem
    {
        bool mightContainSubItems() override;
    };

    juce::TreeView tree;
    RootItem root;
};

