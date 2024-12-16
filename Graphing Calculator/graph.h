#ifndef GRAPH_H
#define GRAPH_H
#include "graphinfo.h"
#include "plot.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Graph
{
public:
    Graph(GraphInfo* info):_info(info), _plotter(info){};

    void set_info(GraphInfo* info);
    void update(GraphInfo* _info);
    void step(int command, GraphInfo* _info);
    void draw(sf::RenderWindow &window);

private:
    GraphInfo* _info;
    Plot _plotter;
    vector <sf::Vector2f> _points;
};

#endif // GRAPH_H
