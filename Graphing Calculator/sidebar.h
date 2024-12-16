#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;


class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);

    int get_history_count();
    vector <sf::Text> get_sidebar_functions();

private:
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    fstream function_history;

    float _left;
    float _width;

    int prev_items_size;
    int current_item_size;
    vector<sf::Text> sidebar_functions;
    int prev_sidebar_function_size;

    int history_count;

};

#endif // SIDEBAR_H
