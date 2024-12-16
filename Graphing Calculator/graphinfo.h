#ifndef GRAPHINFO_H
#define GRAPHINFO_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

struct GraphInfo
{
public:
    GraphInfo(string equation, char graph_type, sf::Vector2f window_dimensions, sf::Vector2f origin,
              sf::Vector2f domain, int num_of_points):_equation(equation), _graph_type(graph_type), _window_dimensions(window_dimensions),
              _origin(origin), _domain(domain), _num_of_points(num_of_points){};

    string _equation;
    char _graph_type; // 'c' cartesian

    sf::Vector2f _window_dimensions;
    sf::Vector2f _origin; //origin
    sf::Vector2f _domain; // domain

    int _num_of_points;

};

#endif // GRAPHINFO_H
