// CREATED BY CONNOR WHISMAN ON 08-13-22
// 
// SFML PROJECT
// ------------
// LEARNING HOW TO MANIPULATE BASIC 2D GRAPHICS USING SFML
// GOALS ARE TO GET BASIC FUNCTIONALITY BUILT AND THEN ORGANIZE INTO A BASE CLASS, FOR USE IN MAKING SIMPLE GAMES OR VIEWING ALGORITHMS

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <ctime>
#include <string>
#include <math.h>

#include <analogClockGUI.h>
#include <effectsGUI.h>


// ------  CONSTANTS  ------
// WINDOW
const unsigned int SCREEN_WIDTH = 1200;
const unsigned int SCREEN_HEIGHT = 800;
sf::RenderWindow WINDOW(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "HISOKA GRAPHICS");



int main()
{
    // TAKE A GUESS (-_-)
    //WINDOW.setFramerateLimit(FPS_LIMIT);

    // DEFINE / START CLOCK TO CALCULATE FPS
    // CREATE ARRAY FOR PAST 1000 FPS CALCULATIONS AND GET THE AVERAGE
    sf::Clock fpsClock;



    // DEFINE SHAPES TO BE DRAWN
    ClockGUI nClock(140, WINDOW);
    //StaticEffect fuzz;



    // ----------  WINDOW LOOP  -----------
    while (WINDOW.isOpen())
    {
        // FPS CLOCK VARIABLES
        float current_time = fpsClock.restart().asSeconds();
        float fps = 1.0f / (current_time);
        // PRINT FPS
        std::cout << fps << std::endl;
        // CHECK FOR EVENTS
        sf::Event event;
        while (WINDOW.pollEvent(event))
        {
            switch (event.type)
            {
            // USER CLOSES WINDOW
            case sf::Event::Closed:
                WINDOW.close();
                break;
            // CHECK FOR KEY PRESSES                // VERY SLOW. ANY ALTERNATIVES EXIST?
            //case sf::Event::KeyPressed:
            //    switch (event.key.code)
            //    {
            //        // MOVE UP
            //    case sf::Keyboard::W:
            //        //std::cout << 'W';
            //        position                        +=       sf::Vector2f( 0.0f, -5.0f );
            //        rect.setPosition(position);
            //        break;
            //        // MOVE DOWN
            //    case sf::Keyboard::S:
            //        //std::cout << 'S';
            //        position                        +=       sf::Vector2f( 0.0f,  5.0f );
            //        rect.setPosition(position);
            //        break;
            //        // MOVE LEFT / ROTATE CCW
            //    case sf::Keyboard::A:
            //        //std::cout << 'A';
            //        position                        +=       sf::Vector2f(-5.0f,  0.0f );
            //        rect.setPosition(position);
            //        break;
            //        // MOVE RIGHT / ROTATE CW
            //    case sf::Keyboard::D:
            //        //std::cout << 'D';
            //        position                        +=       sf::Vector2f( 5.0f,  0.0f );
            //        rect.setPosition(position);
            //        break;
            //    default:
            //        break;
            //    }
            //    break;
            default:
                break;
            }
        }




        // CLEAR SCREEN
        WINDOW.clear(sf::Color(180, 180, 180));

        // UPDATE AND DRAW
        nClock.updateTime();
        nClock.drawClock(WINDOW);
        //fuzz.drawColors(WINDOW);

        // DISPLAY DRAWINGS
        WINDOW.display();

    }
	return 0;
}