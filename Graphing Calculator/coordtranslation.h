#ifndef COORDTRANSLATION_H
#define COORDTRANSLATION_H
#include "graphinfo.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include <cmath>

using namespace std;

class CoordTranslation
{
public:
    CoordTranslation(GraphInfo* info):_info(info){};
    sf::Vector2f translate(sf::Vector2f graph_point);

private:
    GraphInfo* _info;
};

#endif // COORDTRANSLATION_H
