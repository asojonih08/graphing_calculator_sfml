#ifndef PLOT_H
#define PLOT_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "shuntingyard.h"
#include "includes/Queue.h"
#include "variable.h"
#include "rpn.h"
#include "input.h"
#include "coordtranslation.h"

using namespace std;

class Plot
{
public:
    Plot(GraphInfo* info);

    void set_info(GraphInfo* info);

    void get_points(vector<sf::Vector2f> &_points);

private:
    Queue<Token*> _post_fix;
    GraphInfo* _info;
};

#endif // PLOT_H
