#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include <cstring>

class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
private:
    sf::RenderWindow window;
    System system;                      //container for all the animated objects
    Sidebar sidebar;                    //rectangular message sidebar

    GraphInfo* _info;
    sf::RectangleShape textBox;
    string input;
    sf::CircleShape mousePoint;         //The little red dot
    int command;                        //command to send to system
    int index;
    bool history_flag;
    bool history_count;
    sf::Font font;                      //font to draw on main screen
    sf::Text equation;
    sf::Text hover_text;
    bool text_box_flag;

    //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
