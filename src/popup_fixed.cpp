#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

// this is the updated code

class MyPopup : public geode::Popup {
public:
    static MyPopup* create() {
        auto ret = new MyPopup();
        if (ret->init()) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool init() override {
        if (!Popup::init(380.f, 250.f)) return false;
        
        auto obamaSpr = CCSprite::create("obama.png"_spr);
        if (obamaSpr) {
            m_mainLayer->addChildAtPosition(obamaSpr, geode::Anchor::Center);
        }

        auto label = CCLabelBMFont::create("Obama", "bigFont.fnt");
        if (label) {
            label->setPosition({190.f, 200.f});
            m_mainLayer->addChild(label);
        } else return false;

        return true;
    }
};