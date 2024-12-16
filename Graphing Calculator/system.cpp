#include "system.h"
#include "random.h"

#include <iostream>

#include <constants.h>


//------------------------------------------------------------------
//------------------------------------------------------------------
void System::set_info(GraphInfo* info)
{

}
void System::Step(int command, GraphInfo* _info){

    double domain = _info->_domain.y - _info->_domain.x;
    switch(command) // handles key presses that change the values in graph_info and reevaluates the function to draw new points on screen
    {
        case 4:
        _info->_domain.x -= (domain/2)/16;
        _info ->_domain.y -= (domain/2)/16;
        domain = _info->_domain.y - _info->_domain.x;
        _info ->_origin.x +=  domain/32 * WORK_PANEL/domain; break;

        case 6:
            _info->_domain.x += (domain/2)/16;
            _info ->_domain.y += (domain/2)/16;
            _info ->_origin.x -=  domain/32 * WORK_PANEL/domain; break;

        case 8:
            _info->_domain.x *= 1.1;
            _info->_domain.y *= 1.1; break;

        case 10:
            _info->_domain.x*=0.9;
            _info->_domain.y*=0.9; break;

        case 14:
        domain = _info->_domain.y - _info->_domain.x;
        _info ->_origin.y +=  domain/32 * SCREEN_HEIGHT/domain; break;

        case 16:
        domain = _info->_domain.y - _info->_domain.x;
        _info ->_origin.y -=  domain/32 * SCREEN_HEIGHT/domain; break;


    }


    if(command != 0)
        _g.update(_info); // send updated information when command value is set to something else



}


void System::Draw(sf::RenderWindow& window){ // draw the translated coordinates

    _g.draw(window);

}
