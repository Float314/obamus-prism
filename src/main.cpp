#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "popup_fixed.cpp"

using namespace geode::prelude;

// im banned from GD Creators discord server ngl 
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto leftMenu = static_cast<CCMenu*>(this->getChildByID("left-button-menu"));

        
        if (leftMenu) {
            auto profileButtonSpr = CCSprite::create("obama_button.png"_spr);

            if (!profileButtonSpr) return; 

            auto btn = CCMenuItemSpriteExtra::create(
                profileButtonSpr,
                this,
                menu_selector(MyPauseLayer::onMyButton)
            );

            btn->setID("obamus-button");
            // btn->setScale(0.5f); 
            leftMenu->addChild(btn);
            leftMenu->updateLayout();
        }
    }

    void onMyButton(CCObject* sender) {
        auto OPopup = MyPopup::create();
        if (OPopup) {
            OPopup->show();
        };
    }
};

/*
Theres a new geode function called "geode::addBackButton" that could easily compact those lines of
code of making the back button into one. 
So the entire section on adding the back button is kinda pointless with this function lol

also another thing is that geode::createLayerBG() exists as well so recreating the background 
by hand isn’t necessary as well lol
*/