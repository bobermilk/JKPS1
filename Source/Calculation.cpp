#include "../Headers/Calculation.hpp"

Calculation::Calculation()
: mFrameTick(0)
, mClickedKeysInCurrentFrame(0)
, mKeysPerTick()
, mKeyPerSecond(0)
, mNumberOfKPSToSave(9)
, mPreviousKeyPerSeconds()
{
    mPreviousKeyPerSeconds.resize(mNumberOfKPSToSave);
    for (auto& element : mPreviousKeyPerSeconds)
        element = 0;
}

void Calculation::handleInput(KeyPressingManager& container, std::vector<sf::Keyboard::Key>& keys)
{
    mClickedKeysInCurrentFrame = 0;

    for (const auto& element : container.mClickedKeys)
        mClickedKeysInCurrentFrame += element;
}

void Calculation::update()
{
    if (mFrameTick == mKeysPerTick.size())
        mFrameTick = 0;

    if (mKeysPerTick[mFrameTick] > 0)
        mKeyPerSecond -= mKeysPerTick[mFrameTick];

    mKeysPerTick[mFrameTick] = mClickedKeysInCurrentFrame;
    mKeyPerSecond += mClickedKeysInCurrentFrame;

    mPreviousKeyPerSeconds[mFrameTick % mNumberOfKPSToSave] = mKeyPerSecond;

    ++mFrameTick;
}

std::size_t Calculation::getKeyPerSecond()
{
    return mKeyPerSecond;
}

std::size_t Calculation::getBeatsPerMinute()
{
    size_t result = 0;
    for (auto& element : mPreviousKeyPerSeconds)
        result += element;
    
    return result * 60 / mNumberOfKPSToSave / 4;
}