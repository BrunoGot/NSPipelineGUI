#include "TreeViewComponent.h"
class TreeViewComponent 
{
public:
    TreeViewComponent()
    {
        tree.setRootItem(&root);
        tree.setRootItemVisible(false);

        addAndMakeVisible(tree);
    }

    void resized() override
    {
        tree.setBounds(getLocalBounds());
    }

private:
    //==============================================================================
    struct RootItem : public juce::TreeViewItem
    {
        RootItem()
        {
            struct Item : public TreeViewItem
            {
                Item(int index, int depth, int numSubItems)
                    : textToDisplay("Item " + juce::String(index)
                        + ". Depth: " + juce::String(depth)
                        + ". Num sub-items: " + juce::String(numSubItems))
                {
                    for (int i = 0; i < numSubItems; ++i)
                        addSubItem(new Item(i,
                            depth + 1,
                            juce::Random::getSystemRandom().nextInt(juce::jmax(0, 5 - depth))));
                }

                bool mightContainSubItems() override
                {
                    return getNumSubItems() > 0;
                }

                void paintItem(juce::Graphics& g, int width, int height) override
                {
                    if (isSelected())
                    {
                        g.setColour(juce::Colours::yellow.withAlpha(0.3f));
                        g.fillRect(0, 0, width, height);
                    }

                    g.setColour(juce::Colours::black);
                    g.drawRect(0, height - 1, width, 1);

                    g.setColour(juce::Colours::white);
                    g.drawText(textToDisplay, 0, 0, width, height, juce::Justification::centredLeft);
                }

                juce::String getAccessibilityName() override { return textToDisplay; }

                const juce::String textToDisplay;
            };

            for (int i = 0; i < 10; ++i)
                addSubItem(new Item(i, 0, juce::Random::getSystemRandom().nextInt(10)));
        }

        bool mightContainSubItems() override
        {
            return true;
        }
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TreeViewComponent)
};

namespace juce {
    class ContentComponent : public Component
    {
    public:
        ContentComponent(const String& title, const String& info, Component& contentToDisplay)
            : titleLabel({}, title),
            content(contentToDisplay)
        {
            addAndMakeVisible(titleLabel);
            addAndMakeVisible(infoIcon);

            setTitle(title);
            setDescription(info);
            setFocusContainerType(FocusContainerType::focusContainer);

            infoIcon.setTooltip(info);
            infoIcon.setHelpText(info);

            addAndMakeVisible(content);
        }

        void paint(Graphics& g) override
        {
            g.setColour(Colours::black);
            g.drawRoundedRectangle(getLocalBounds().reduced(2).toFloat(), 5.0f, 3.0f);
        }

        void resized() override
        {
            auto bounds = getLocalBounds().reduced(5);

            auto topArea = bounds.removeFromTop(30);
            infoIcon.setBounds(topArea.removeFromLeft(30).reduced(5));
            titleLabel.setBounds(topArea.reduced(5));

            content.setBounds(bounds);
        }

    private:
        //==============================================================================
        struct InfoIcon : public Component,
            public SettableTooltipClient
        {
            InfoIcon()
            {
                constexpr uint8 infoPathData[] =
                {
                  110,109,0,0,122,67,0,0,0,0,98,79,35,224,66,0,0,0,0,0,0,0,0,79,35,224,66,0,0,0,0,0,0,122,67,98,0,0,
                  0,0,44,247,193,67,79,35,224,66,0,0,250,67,0,0,122,67,0,0,250,67,98,44,247,193,67,0,0,250,67,0,0,
                  250,67,44,247,193,67,0,0,250,67,0,0,122,67,98,0,0,250,67,79,35,224,66,44,247,193,67,0,0,0,0,0,0,122,
                  67,0,0,0,0,99,109,114,79,101,67,79,35,224,66,108,71,88,135,67,79,35,224,66,108,71,88,135,67,132,229,
                  28,67,108,116,79,101,67,132,229,28,67,108,116,79,101,67,79,35,224,66,99,109,79,35,149,67,106,132,
                  190,67,108,98,185,123,67,106,132,190,67,98,150,123,106,67,106,132,190,67,176,220,97,67,168,17,187,
                  67,176,220,97,67,18,150,177,67,108,176,220,97,67,248,52,108,67,98,176,220,97,67,212,8,103,67,238,
                  105,94,67,18,150,99,67,204,61,89,67,18,150,99,67,108,98,185,73,67,18,150,99,67,108,98,185,73,67,88,
                  238,59,67,108,160,70,120,67,88,238,59,67,98,54,194,132,67,88,238,59,67,169,17,137,67,60,141,68,67,
                  169,17,137,67,8,203,85,67,108,169,17,137,67,26,97,166,67,98,169,17,137,67,43,247,168,67,10,203,138,
                  67,141,176,170,67,27,97,141,67,141,176,170,67,108,80,35,149,67,141,176,170,67,108,80,35,149,67,106,
                  132,190,67,99,101,0,0
                };

                infoPath.loadPathFromData(infoPathData, numElementsInArray(infoPathData));

                setTitle("Info");
            }

            void paint(Graphics& g) override
            {
                auto bounds = getLocalBounds().toFloat().reduced(2);

                g.setColour(Colours::white);
                g.fillPath(infoPath, RectanglePlacement(RectanglePlacement::centred)
                    .getTransformToFit(infoPath.getBounds(), bounds));
            }

            Path infoPath;
        };

        //==============================================================================
        Label titleLabel;
        InfoIcon infoIcon;
        Component& content;

        //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ContentComponent)
    };
}