

#include "UISliderTest_Editor.h"


// UISliderTest_Editor

UISliderTest_Editor::UISliderTest_Editor()
: _displayValueLabel(nullptr)
{
    
}

UISliderTest_Editor::~UISliderTest_Editor()
{
    
}

bool UISliderTest_Editor::init()
{
    if (UIScene_Editor::init())
    {
        _layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosui/UIEditorTest/UISlider_Editor/ui_slider_editor_1.json"));
        _touchGroup->addChild(_layout);
        Size screenSize = CCDirector::getInstance()->getWinSize();
        Size rootSize = _layout->getSize();
        _touchGroup->setPosition(Vector2((screenSize.width - rootSize.width) / 2,
                                       (screenSize.height - rootSize.height) / 2));
        
        Layout* root = static_cast<Layout*>(_layout->getChildByName("root_Panel"));
        
        Text* back_label = static_cast<Text*>(Helper::seekWidgetByName(root, "back"));
        back_label->addTouchEventListener(CC_CALLBACK_2(UIScene_Editor::toGUIEditorTestScene, this));
        
        _sceneTitle = static_cast<Text*>(Helper::seekWidgetByName(root, "UItest"));
        
        
        Slider* slider = static_cast<Slider*>(Helper::seekWidgetByName(root, "Slider_738"));
        slider->addEventListener(CC_CALLBACK_2(UISliderTest_Editor::sliderEvent, this));
        
        Slider* scale9_slider = static_cast<Slider*>(Helper::seekWidgetByName(root, "Slider_740"));
        scale9_slider->addEventListener(CC_CALLBACK_2(UISliderTest_Editor::sliderEvent, this));
        
        
        _displayValueLabel = Text::create();
        _displayValueLabel->setFontName("fonts/Marker Felt.ttf");
        _displayValueLabel->setFontSize(30);
        _displayValueLabel->setString("No event");
        _displayValueLabel->setPosition(Vector2(_layout->getSize().width / 2,
                                              _layout->getSize().height - _displayValueLabel->getSize().height * 1.75f));
        _touchGroup->addChild(_displayValueLabel);
        
        return true;
    }
    
    return false;
}

void UISliderTest_Editor::sliderEvent(Ref *pSender, Slider::EventType type)
{
    switch (type)
    {
        case Slider::EventType::ON_PERCENTAGE_CHANGED:
        {
            Slider* slider = static_cast<Slider*>(pSender);
            _displayValueLabel->setString(CCString::createWithFormat("percent %d", slider->getPercent())->getCString());
        }
            break;
            
        default:
            break;
    }
}
