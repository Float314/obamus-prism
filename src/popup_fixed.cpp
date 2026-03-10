#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/fmod/fmod.h>

using namespace geode::prelude;

// this is the updated code

class MyPopup : public geode::Popup {
protected:
    CCSprite* obamaSpr;
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
    // 135169432
    bool init() override {
        if (!Popup::init(380.f, 250.f)) return false;
        
        obamaSpr = CCSprite::create("obama.png"_spr);
        /* if (obamaSpr) {
            m_mainLayer->addChildAtPosition(obamaSpr, geode::Anchor::Center);
        } */ 

        auto obamaBtn = CCMenuItemSpriteExtra::create(
            obamaSpr,
            this,
            menu_selector(MyPopup::onObamaBtn)
        );
        // m_mainLayer->addChild(obamaBtn);
        m_buttonMenu->addChild(obamaBtn);
        obamaBtn->setPosition({190.f, 125.f});


        auto label = CCLabelBMFont::create("Barrack Obama :)", "bigFont.fnt");
        if (label) {
            label->setPosition({190.f, 200.f});
            m_mainLayer->addChild(label);
        } else return false;

        return true;
    }

    void onObamaBtn(CCObject* sender) { 
        obamaSpr->runAction(CCRotateBy::create(1.f, 360.f));

        auto system = FMODAudioEngine::get()->m_system;
        FMOD::Sound* sound;
        FMOD::Channel* channel;

        system->createSound(
            (string::pathToString(Mod::get()->getResourcesDir()/"ohd.ogg")).c_str(),
            FMOD_DEFAULT, nullptr, &sound
        );
        system->playSound(sound, nullptr, false, &channel);
        channel->setVolume(FMODAudioEngine::get()->m_sfxVolume);

    }
};