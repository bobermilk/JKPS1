#include "../Headers/LogButton.hpp"
#include "../Headers/Settings.hpp"

#include <cassert>


unsigned LogButton::mBufferPointer(0);
unsigned LogButton::mPrevKpsBufferPointer(0);
float LogButton::statKeysPerSecond(0);
float LogButton::statMaxKeysPerSecond(0);
unsigned LogButton::statTotal(0);
float LogButton::statBeatsPerMinute(0);

LogButton::LogButton(LogKey &key)
: mKey(key)
, mKeysPerSecond(0)
, mTotal(0)
{
    for (auto &elem : mBuffer)
        elem = 0;
    for (auto &elem : mPrevKpsBuffer)
        elem = 0;
}

void LogButton::processRealtimeInput()
{
    unsigned &bufferElem = mBuffer[mBufferPointer];
    const bool keyPressed = mKey.isPressed();

    if (bufferElem > 0)
    {
        mKeysPerSecond -= bufferElem;
        --bufferElem;
        --statKeysPerSecond;
        assert(bufferElem == 0);
    }
    if (!mNeedToRelease && keyPressed)
    {
        ++bufferElem;
        ++mKeysPerSecond;
        ++statKeysPerSecond;
        if (statKeysPerSecond > statMaxKeysPerSecond)
            statMaxKeysPerSecond = statKeysPerSecond;

        const unsigned amtToAdd = 1 * Settings::ButtonPressMultiplier;
        mTotal += amtToAdd;
        statTotal += amtToAdd;
    }

    mPrevKpsBuffer[mPrevKpsBufferPointer] = mKeysPerSecond;
    statBeatsPerMinute += getLocalBeatsPerMinute();
    mNeedToRelease = keyPressed;
}

bool LogButton::isButtonPressed() const
{
    return mKey.isPressed();
}

void LogButton::movePointer()
{
    if (++mBufferPointer == 60)
        mBufferPointer = 0;
    if (++mPrevKpsBufferPointer == 9)
        mPrevKpsBufferPointer = 0;
    
    statBeatsPerMinute = 0;
}

void LogButton::reset()
{
    mKeysPerSecond = mTotal = statKeysPerSecond = statTotal = statBeatsPerMinute = 0;
    for (auto &elem : mBuffer)
        elem = 0;
    for (auto &elem : mPrevKpsBuffer)
        elem = 0;
}

float LogButton::getKeysPerSecond()
{
    return statKeysPerSecond;
}

float LogButton::getMaxKeysPerSecond()
{
    return statMaxKeysPerSecond;
}

unsigned LogButton::getTotal()
{
    return statTotal;
}

float LogButton::getBeatsPerMinute()
{
    return statBeatsPerMinute;
}

float LogButton::getLocalBeatsPerMinute() const
{
    float prevKpsSum = 0;
    for (const auto &elem : mPrevKpsBuffer)
        prevKpsSum += elem;

    // 9  = buffer size 
    // 15 = 60 (sec) / 4 (1/4 time signature for streams)
    return prevKpsSum / 9 * 15;
}
