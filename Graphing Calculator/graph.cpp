#include "graph.h"


void Graph::set_info(GraphInfo* info) // did not use
{
//    _info = info;
//    _plotter.set_info(info);
}

void Graph::update(GraphInfo* _info) // grabs translated pints after evaluated
{
    const bool debug = false;

//    set_info(_info);

    _points.clear();

    if (debug) cout << "\npre get_points()\n";

    _plotter.get_points(_points);

    if (debug) cout << "\nexit get_points()\n";

}

void Graph::draw(sf::RenderWindow &window) // draws circle objects in translated points and set position of axis based on origin shift
{
    const bool debug = false;
    int domain = _info->_num_of_points - 1;
    vector <sf::CircleShape> point;
    if (debug) cout << "\ndraw: \n";

    point.clear();
    for(int i = 0; i <= domain; i++)
    {
        point.push_back(sf::CircleShape(1.3));
        point.at(i).setFillColor(sf::Color(228,96,62));
        point.at(i).setPosition(_points.at(i));
        sf::Vector2f position = point.at(i).getPosition();
        if (debug)cout << "\nCircle Position ----- x: " << position.x << " y: " << position.y << endl;
    }


    for(int i = 0; i <= domain; i++)
    {
        window.draw(point.at(i));
    }


    sf::Vertex line[4];
    line[0].position = sf::Vector2f(0, 400 + _info->_origin.y);
    line[0].color  = sf::Color(167,170,177);
    line[1].position = sf::Vector2f(1120, 400 + _info->_origin.y);
    line[1].color = sf::Color(167,170,177);
    line[2].position = sf::Vector2f(560 + _info->_origin.x, 0);
    line[2].color  = sf::Color(167,170,177);
    line[3].position = sf::Vector2f(560 +_info->_origin.x, 800);
    line[3].color = sf::Color(167,170,177);


    window.draw(line, 4, sf::Lines);
}
