#include "coordtranslation.h"

//CoordTranslation::CoordTranslation()
//{

//}

sf::Vector2f CoordTranslation::translate(sf::Vector2f graph_point)
{
//    const bool debug = false;

//    if(_info->_graph_type == 'p')
//    {
//        graph_point.x = graph_point.y * cos(graph_point.x);
//        graph_point.y = graph_point.y * sin(graph_point.x);
//    }


//    if (_info->_graph_type == 'p')
//    {
//        _info->_domain.x = -1;
//        _info->_domain.y = 1;
//        cout << "domain.x: " << _info->_domain.x << endl <<"domain.y: " << _info->_domain.y << endl;
//    }

    double domain = _info->_domain.y - _info->_domain.x;

    double coordinate_matrix [1] [3] =

    {{        graph_point.x,                                                       graph_point.y,                              1            }};

    double scaling_transl_matrix [3] [3] =

    {{ (static_cast<double>(WORK_PANEL)* 1.0) / domain,                                 0,                                      0            },

    {                      0,                                -((static_cast<double> (SCREEN_HEIGHT) * 1.0) / domain),           0            },

    {( 560 -(560*(2*(0.5+(_info->_domain.x/domain))))),                        400+ _info->_origin.y,                           1            }};

    double translated_matrix [3][1];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            translated_matrix[i][j] = coordinate_matrix[0][0] * scaling_transl_matrix[j][i] + coordinate_matrix[0][1] * scaling_transl_matrix[j+1][i]
                                     + coordinate_matrix [0][2] * scaling_transl_matrix[j+2][i];
        }
    }

    return sf::Vector2f(translated_matrix[0][0], translated_matrix[1][0]);

//    double xpos = 0;

//    if (debug) cout << "\ndomain: " << domain << endl;


//    xpos = graph_point.x * ((static_cast<double>(WORK_PANEL)* 1.0) / domain) + (560 -(560*(2*(0.5+(_info->_domain.x/domain)))));

//    double ypos = graph_point.y * -((static_cast<double> (SCREEN_HEIGHT) * 1.0) / domain) + (400+ _info->_origin.y);
//    return sf::Vector2f(xpos, ypos);
}
