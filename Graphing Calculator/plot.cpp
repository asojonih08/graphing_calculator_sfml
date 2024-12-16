#include "plot.h"

Plot::Plot(GraphInfo* info)
{
    set_info(info);
}

void Plot::set_info(GraphInfo* info)
{
    _info = info;

    int n = (_info -> _equation).length();

    char input[n + 1];

    strcpy(input, (_info -> _equation).c_str());

    Input in;
    Queue<Token*> infix = in.tokenize(input);
    ShuntingYard sy;

    _post_fix = sy.post_fix(infix);
}

void Plot::get_points(vector<sf::Vector2f> &_points)
{
    const bool debug = false;

    double domain = _info->_domain.y - _info->_domain.x;
    double increments = domain /_info->_num_of_points;

    RPN rpn(_post_fix);
    sf::Vector2f screen_coord;
    CoordTranslation coord(_info);


    double y = 0;

    for(double x = _info ->_domain.x; x <= _info ->_domain.y; x+=increments) // evaluate increment pts and send to translate to insert in vector Vector2f
    {
        if (debug) cout << endl << "x = " << x;
        y = rpn.evaluate(x);
        if (debug) cout <<"\ny = " << y;
        screen_coord = coord.translate(sf::Vector2f(x,y));

//        if (_info->_graph_type == 'p')
//        {
//            _info->_domain.x = 0;
//            _info->_domain.y = 2*M_PI;
//            cout << "domain.x: " << _info->_domain.x << endl <<"domain.y: " << _info->_domain.y << endl;
//        }

        if (debug) cout << "\nx: " << screen_coord.x;
        if (debug) cout << "\ny: " << screen_coord.y;

        _points.push_back(screen_coord);
    }

    if (debug) cout << "\nexit coord evaluate loop\n";

}
