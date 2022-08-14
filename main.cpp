// CREATED BY CONNOR WHISMAN ON 08-13-22
// 
// SFML PROJECT
// ------------
// LEARNING HOW TO MANIPULATE BASIC 2D GRAPHICS USING SFML
// GOALS ARE TO GET BASIC FUNCTIONALITY BUILT AND THEN ORGANIZE INTO A BASE CLASS, FOR USE IN MAKING SIMPLE GAMES OR VIEWING ALGORITHMS

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>



// CONSTANTS
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
// RENDER WINDOW
sf::RenderWindow WINDOW(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "HISOKA GRAPHICS");



// CLASS TO DISPLAY 'STATIC' SCREEN
class fuzzyScreen
{  
public:
    // VECTOR TO HOLD SHAPES, LOOP TO CREATE PIXELS AND POSITION THEM
    std::vector<sf::RectangleShape> pixelVector;
    void fillVector()
    {
        for (int i = 0; i < SCREEN_WIDTH; i += 5)
        {
            for (int j = 0; j < SCREEN_HEIGHT; j += 5)
            {
                auto position = sf::Vector2f((float)i, (float)j);
                sf::RectangleShape rect(sf::Vector2f(5.0f, 5.0f));
                rect.setPosition(position);

                pixelVector.push_back(rect);
            }
        }
    }
    // LOOP THROUGH DEFINED SHAPES, CHANGE THEIR COLOR, DRAW THEM
    void drawColors()
    {
        for (sf::RectangleShape rect : pixelVector)
        {
            rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
            WINDOW.draw(rect);
        }
    }
};

// CLASS TO DRAW CLOCK
class clockGUI
{
public:
    void initClock()
    {
        sf::CircleShape clockBase(280.f);
        clockBase.setFillColor(sf::Color(255, 230, 255));
        clockBase.setOutlineThickness(10.f);
        clockBase.setOutlineColor(sf::Color(210, 0, 250, 230));
        clockBase.setPosition(sf::Vector2f(110.f, 20.f));

        sf::CircleShape clockCenter(20.f);
        clockCenter.setPosition(sf::Vector2f(375.f, 275.f));
        clockCenter.setFillColor(sf::Color(0, 0, 0));

        WINDOW.draw(clockBase);
        WINDOW.draw(clockCenter);
    }
};


int main()
{
    // DEFINE SHAPES TO BE DRAWN
    /*sf::RectangleShape rect(sf::Vector2f(100.0f, 65.0f));
    rect.setFillColor(sf::Color(120, 80, 250));
    auto position = sf::Vector2f(30.0f, 30.0f);
    rect.setPosition(position);*/
    // CIRCLE SHAPE
    //sf::CircleShape circle(50.0f);
    //circle.setFillColor(sf::Color(30, 60, 90));
    // 
    // DECLARE FUZZY SCREEN
    //fuzzyScreen fuzz;
    //fuzz.fillVector();
    // 
    // DECLARE NEW CLOCK
    clockGUI analogClock;

    // DEFINE / START CLOCK TO CALCULATE FPS
    sf::Clock clock;

    // WINDOW LOOP
    while (WINDOW.isOpen())
    {
        // CLOCK VARIABLES
        float current_time = clock.restart().asSeconds();
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
        WINDOW.clear(sf::Color::Black);
       
        // DRAW FUZZY SCREEN
        //fuzz.drawColors();

        // DRAW ANALOG CLOCK
        analogClock.initClock();

        // DISPLAY DRAWINGS
        WINDOW.display();
    }
	return 0;
}