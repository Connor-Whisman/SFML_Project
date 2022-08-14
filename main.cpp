// CREATED BY CONNOR WHISMAN ON 08-13-22
// 
// SFML PROJECT
// ------------
// LEARNING HOW TO MANIPULATE BASIC 2D GRAPHICS USING SFML
// GOALS ARE TO GET BASIC FUNCTIONALITY BUILT AND THEN ORGANIZE INTO A BASE CLASS, FOR USE IN MAKING SIMPLE GAMES OR VIEWING ALGORITHMS

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // CREATE WINDOW
	sf::RenderWindow window(sf::VideoMode(800, 600), "TEST_TITLE");

    // DEFINE SHAPES TO BE DRAWN
    sf::RectangleShape rect(sf::Vector2f(100.0f, 65.0f));
    rect.setFillColor(sf::Color(120, 80, 250));
    auto position = sf::Vector2f(30.0f, 30.0f);
    rect.setPosition(position);
    

    while (window.isOpen())
    {
        // CHECK FOR EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            // USER CLOSES WINDOW
            case sf::Event::Closed:
                window.close();
                break;

            // CHECK FOR KEY PRESSES                // VERY SLOW. ANY ALTERNATIVES EXIST?
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    // MOVE UP
                case sf::Keyboard::W:
                    std::cout << 'W';
                    position                        +=       sf::Vector2f( 0.0f, -5.0f );
                    rect.setPosition(position);
                    break;
                    // MOVE DOWN
                case sf::Keyboard::S:
                    std::cout << 'S';
                    position                        +=       sf::Vector2f( 0.0f,  5.0f );
                    rect.setPosition(position);
                    break;
                    // MOVE LEFT / ROTATE CCW
                case sf::Keyboard::A:
                    std::cout << 'A';
                    position                        +=       sf::Vector2f(-5.0f,  0.0f );
                    rect.setPosition(position);
                    break;
                    // MOVE RIGHT / ROTATE CW
                case sf::Keyboard::D:
                    std::cout << 'D';
                    position                        +=       sf::Vector2f( 5.0f,  0.0f );
                    rect.setPosition(position);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }


        // CLEAR SCREEN
        window.clear(sf::Color::Black);
       
        // DRAW DEFINED SHAPES
        window.draw(rect);

        // DISPLAY DRAWINGS
        window.display();


    }
	return 0;
}