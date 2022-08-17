#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class ClockGUI
{
public:
    ClockGUI() {
        
    }
    // INITIALIZE
    ClockGUI(float baseRadius, sf::RenderWindow& window) {
        // WINDOW DATA
        sf::Vector2u windowSize = window.getSize();
        unsigned int windowX = windowSize.x;
        unsigned int windowY = windowSize.y;
        float xMidPoint = windowX * 0.5f;
        float yMidPoint = windowY * 0.5f;
        // CLOCK SIZE VARIABLES
        float baseDiam = baseRadius * 2;
        float centerRadius = baseRadius * 0.04f;
        float centerDiam = centerRadius * 2;
        // INIT ALL OBJECTS TO BE DRAWN
        clockBase.setRadius(baseRadius);
        clockCenter.setRadius(centerRadius);
        hourHand.setSize(sf::Vector2f(baseRadius * 0.575f, baseRadius * 0.0125f));
        minuteHand.setSize(sf::Vector2f(baseRadius * 0.85f, baseRadius * 0.01f));
        secondHand.setSize(sf::Vector2f(baseRadius * 0.93f, baseRadius * 0.009));
        clockBase.setFillColor(sf::Color(30, 140, 160));
        clockBase.setOutlineThickness(baseRadius * 0.03f);
        clockBase.setOutlineColor(sf::Color(30, 80, 140));
        clockBase.setPosition(sf::Vector2f((windowX - baseDiam) / 2.f, (windowY - baseDiam) / 2.f));
        hourHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
        hourHand.setRotation(270.f);
        minuteHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
        minuteHand.setRotation(270.f);
        secondHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
        secondHand.setRotation(270.f);
        clockCenter.setFillColor(sf::Color(0, 0, 0));
        clockCenter.setPosition(sf::Vector2f((windowX - centerDiam) / 2.f, (windowY - centerDiam) / 2.f));
        // INIT TICKS AROUND CLOCK INTO VECTOR
        for (int i = 0; i < 360; i += 30)
        {
            double angleToRad = i / 57.29577951;
            sf::RectangleShape tick(sf::Vector2f(30.f, 3.f));
            tick.setFillColor(sf::Color(160, 160, 160));
            tick.setPosition(sf::Vector2f(xMidPoint + sin(angleToRad) * baseRadius, yMidPoint - cos(angleToRad) * baseRadius));
            tick.setRotation(i + 90);
            ticksVector.push_back(tick);
        }
    }

    void updateTime()
    {
        int* time = getCurrentTime();
        int hour = time[0];
        int min = time[1];
        int sec = time[2];
    
        float hourHandPos = ((360.f / 12.f) * hour) - 90.f;
        float minHandPos = ((360.f / 60.f) * min) - 90.f;
        float secHandPos = ((360.f / 60.f) * sec) - 90.f;
    
        hourHand.setRotation(hourHandPos);
        minuteHand.setRotation(minHandPos);
        secondHand.setRotation(secHandPos);
    }

    void drawClock(sf::RenderWindow& window)
    {
        // DRAW BASE AND TICKS
        window.draw(clockBase);
        for (sf::RectangleShape tick : ticksVector)
        {
            window.draw(tick);
        }
        // DRAW HANDS AND THEN CENTER OVER THEM
        window.draw(hourHand);
        window.draw(minuteHand);
        window.draw(secondHand);
        window.draw(clockCenter);
    }

private:
    sf::CircleShape clockBase;
    sf::CircleShape clockCenter;
    std::vector<sf::RectangleShape> ticksVector;
    sf::RectangleShape hourHand;
    sf::RectangleShape minuteHand;
    sf::RectangleShape secondHand;

    int* getCurrentTime()
    {
        // CURRENT SYSTEM DATE/TIME
        time_t now = time(0);

        // IGNORE WARNING
        // CONVERT TO STR
    #pragma warning(suppress : 4996)
        char* dt = ctime(&now);
        std::string str(dt);
        //std::cout << str;

        std::string hourStr;
        hourStr += ((int)str.at(11));
        hourStr += ((int)str.at(12));
        int hour = stoi(hourStr);

        std::string minStr;
        minStr += ((int)str.at(14));
        minStr += ((int)str.at(15));
        int min = stoi(minStr);

        std::string secStr;
        secStr += ((int)str.at(17));
        secStr += ((int)str.at(18));
        int sec = stoi(secStr);

        int timeValues[3] = { hour, min, sec };
        return timeValues;
    }
};