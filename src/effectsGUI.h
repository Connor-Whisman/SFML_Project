#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class StaticEffect
{
public:
    //INITIALIZE
    StaticEffect() {
        for (int i = 0; i < 150; i += 5)
        {
            for (int j = 0; j < 150; j += 5)
            {
                auto position = sf::Vector2f((float)i, (float)j);
                sf::RectangleShape rect(sf::Vector2f(5.0f, 5.0f));
                rect.setPosition(position);

                pixelVector.push_back(rect);
            }
        }
    }

    // LOOP THROUGH DEFINED SHAPES, CHANGE THEIR COLOR, DRAW THEM
    void drawColors(sf::RenderWindow& WINDOW)
    {
        for (sf::RectangleShape rect : pixelVector)
        {
            rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            WINDOW.draw(rect);
        }
    }

private:
    std::vector<sf::RectangleShape> pixelVector;
};