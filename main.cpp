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


// ------  CONSTANTS  ------
// WINDOW
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;
const unsigned int FPS_LIMIT = 60;
float xMidPoint = (float)SCREEN_WIDTH / 2.f;
float yMidPoint = (float)SCREEN_HEIGHT / 2.f;
sf::RenderWindow WINDOW(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "HISOKA GRAPHICS");


// CLASS TO DISPLAY 'STATIC' SCREEN
//    <CURRENTLY NOT IN USE>
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


// ANALOG CLOCK INIT
float baseRadius = 280.0f;
float baseDiam = baseRadius * 2;
float centerRadius = 12.0f;
float centerDiam = centerRadius * 2;
sf::CircleShape clockBase(baseRadius);
sf::CircleShape clockCenter(centerRadius);
sf::RectangleShape hourHand(sf::Vector2f(160.f, 4.f));
sf::RectangleShape minuteHand(sf::Vector2f(240.f, 3.f));
sf::RectangleShape secondHand(sf::Vector2f(260.f, 2.f));


// ----------  ANALOG CLOCK FUNCTIONS  ----------
void drawClock()
{
    clockBase.setFillColor(sf::Color(30, 140, 160));
    clockBase.setOutlineThickness(10.f);
    clockBase.setOutlineColor(sf::Color(30, 80, 140));
    clockBase.setPosition(sf::Vector2f((SCREEN_WIDTH - baseDiam) / 2.f, (SCREEN_HEIGHT - baseDiam) / 2.f));

    hourHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
    hourHand.setRotation(270.f);

    minuteHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
    minuteHand.setRotation(270.f);

    secondHand.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
    secondHand.setRotation(270.f);

    clockCenter.setFillColor(sf::Color(0, 0, 0));
    clockCenter.setPosition(sf::Vector2f((SCREEN_WIDTH - centerDiam) / 2.f, (SCREEN_HEIGHT - centerDiam) / 2.f));
}
// CURRENT TIME FOR ANALOG CLOCK
int * getCurrentTime()
{
    // CURRENT SYSTEM DATE/TIME
    time_t now = time(0);

    // IGNORE WARNING
    // CONVERT TO STR
#pragma warning(suppress : 4996)
    char* dt = ctime(&now);
    std::string str(dt);

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
// CALLED EVERY FRAME
void updateClock()
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
    
    WINDOW.draw(clockBase);
    WINDOW.draw(hourHand);
    WINDOW.draw(minuteHand);
    WINDOW.draw(secondHand);
    WINDOW.draw(clockCenter);





    // CURRENTLY WORKING ON TICKS
    // HARD CODED DRAWING TOP TICK - NEEDS TO CHANGE TO BE DYNAMIC; LOOP THROUGH 12 TICKS AND PLACE BASED ON ANGLE 
    sf::RectangleShape line(sf::Vector2f(40.f, 4.f));
    line.setPosition(sf::Vector2f(xMidPoint, yMidPoint - (yMidPoint - 20)));
    line.rotate(90.f);
    WINDOW.draw(line);

    //for (int i = 0; i < 360; i+=30)
    //{
    //    sf::RectangleShape tick(sf::Vector2f(40.f, 4.f));
    //    tick.setPosition(sf::Vector2f(xMidPoint, yMidPoint));
    //    tick.setRotation(i);
    //    //tick.scale(2.f, 2.f);
    //    WINDOW.draw(tick);
    //}
}





int main()
{
    // TAKE A GUESS (-_-)
    WINDOW.setFramerateLimit(FPS_LIMIT);

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

    // ANALOG CLOCK
    drawClock();

    // DEFINE / START CLOCK TO CALCULATE FPS
    // CREATE ARRAY FOR PAST 1000 FPS CALCULATIONS AND GET THE AVERAGE
    sf::Clock fpsClock;



    // ----------  WINDOW LOOP  -----------
    while (WINDOW.isOpen())
    {
        // FPS CLOCK VARIABLES
        float current_time = fpsClock.restart().asSeconds();
        float fps = 1.0f / (current_time);
        // PRINT FPS
        //std::cout << fps << std::endl;

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
       
        // DRAW FUZZY SCREEN
        //fuzz.drawColors();

        // GET TIME AND DRAW ANALOG CLOCK UPDATES ACCORDINGLY
        updateClock();

        // DISPLAY DRAWINGS
        WINDOW.display();




    }
	return 0;
}