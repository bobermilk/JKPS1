#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "KeyPressingManager.hpp"
#include "ResourceIdentifiers.hpp"
#include "Settings.hpp"
#include "Statistics.hpp"

#include <memory>
#include <cassert>

class Button
{
    public:
        enum AnimationStyle
        {
            Light,
            Press,
            AnimationCounter,
        };


    public:
                                    Button(sf::RenderWindow& window);

        void                        update(std::vector<bool>& needToBeReleased);
        void                        handleInput(std::vector<bool>& clickedKeys, KeyPressingManager& container);
        void                        handleEvent(sf::Event event);
        void                        handleHighlight(int buttonIndex);
        void                        draw();

        void                        loadTextures(TextureHolder& textureHolder);
        void                        loadFonts(FontHolder& fontHolder);

        void                        setFonts();
        void                        setupTextures(); 

        void                        clear();


    private:
        void                        updateAnimation(const std::vector<bool>& needToBeReleased);
        void                        updateButtonText();

        void                        setTextures(std::vector<std::unique_ptr<sf::Sprite>>& vector, sf::Texture& texture);
        void                        setColor(std::vector<std::unique_ptr<sf::Sprite>>& vector, const sf::Color& color);
        void                        scaleTexture(std::vector<std::unique_ptr<sf::Sprite>>& vector, const sf::Vector2u& texture);
        void                        centerOrigin(std::vector<std::unique_ptr<sf::Sprite>>& vector);
        void                        setButtonPositions(std::vector<std::unique_ptr<sf::Sprite>>& vector);
        sf::Vector2f                getDefaultScale() const;
        sf::Vector2f                getScaleForText() const;
        sf::Vector2f                getScaleAmountPerFrame() const;
        float                       getDefaultTextHeight(unsigned chSz) const;
        float                       getTextMaxWidth() const;
        float                       getTextMaxHeight() const;
        sf::Vector2f                getCenterOriginText(unsigned idx) const;

        void                        setupKeyCounterTextVec();
        void                        setupTextPosition(int index);
        void                        decreaseTextCharacterSize(int index);
        std::string                 getButtonText(unsigned index) const;

        void                        resizeVectors();

        void                        lightUpKey(size_t index);
        void                        fadeKeyLight(size_t index);
        void                        raiseKey(size_t index);
        void                        lowerKey(size_t index);

        unsigned int                getKeyCountersWidth(size_t index) const;
        unsigned int                getKeyCountersHeight(size_t index) const;

    
    private:
        sf::RenderWindow&           mWindow;

        sf::Font*                   mKeyCountersFont;
        std::vector<long>           mKeyCounters;
        std::vector<std::unique_ptr<sf::Text>> mButtonsText;

        sf::Texture*                mButtonTexture;
        sf::Texture*                mAnimationTexture;

        std::vector<std::unique_ptr<sf::Sprite>> mButtonsSprite;
        std::vector<std::unique_ptr<sf::Sprite>> mAnimationSprite;

        AnimationStyle              mAnimationStyle;
        std::vector<float>          mButtonsYOffset;

        std::vector<float>          mCurDefaultTextHeight;
        std::vector<unsigned>       mKeyCounterDigits;
};