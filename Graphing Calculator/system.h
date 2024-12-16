#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph.h"

using namespace std;
class System
{
public:
    System(GraphInfo* info):_g(info){};
    void Step(int command, GraphInfo* _info);
    int Size();
    void Draw(sf::RenderWindow& widnow);
    void set_info(GraphInfo* info);
private:
//    vector<Particle> system;
    Graph _g;
    sf::CircleShape shape;
    sf::Vector2f vel;

};

#endif // SYSTEM_H
