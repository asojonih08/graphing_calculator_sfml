#include "sidebar.h"
#include "constants.h"

Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    prev_items_size = 0;
    current_item_size = 0;

    prev_sidebar_function_size = 0;

    string function;
    function_history.open("Function_History.txt", fstream::in); // reads in string of functions from txt file and saves to vector <string> items

    while(getline(function_history, function))
    {

        items.push_back(function);
        cout << endl << "function: " << function << endl;
        cout << "items size: " << items.size() << endl;
    }

    function_history.close();
    prev_items_size = items.size();
    history_count = items.size();

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(152,163,175)); //(192,192,192)); //silver // set sidebar rectangle values
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Arimo-VariableFont_wght.ttf")){ // load sidebar font
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl; // set sidebar text values
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color(4,31,48));

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

//    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

int Sidebar::get_history_count() // returns number of functions in history
{
    return history_count;
}

vector<sf::Text> Sidebar::get_sidebar_functions() // return Text objects asscociated with sidebar
{
    return sidebar_functions;
}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;
    const bool debug = false;

    window.draw(rect);
    float height = 10;

    for (vector<string>::iterator it = items.begin();
                                it != items.end(); it++){


        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
              if (debug)  cout <<"new function: " << it->c_str() << endl;

            current_item_size++;
            if (debug)cout <<"current size: " << current_item_size << endl;
            sb_text.setString(it->c_str());

           if (debug) cout <<"prev size: " << prev_items_size << endl;
            if(current_item_size > prev_items_size)
            {
                function_history.open("Function_History.txt", fstream::app); // only appends to file if the function amount in sidebar changes
                function_history << it->c_str() << endl;
                prev_items_size = current_item_size ;
                function_history.close();
            }


        }

        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING + 10;

        if (!blank)
        {

            if(current_item_size > prev_sidebar_function_size)
            {

                 if (debug)cout <<"\ncurrent size: " << current_item_size << endl;
                sidebar_functions.push_back(sb_text);
                if (debug)cout << "\nsidebar_function size: " << sidebar_functions.size() << endl; // appends to sidebar from file up until the number of
                                                                                                    //functions in history matches and then added after
                 if (debug)cout <<"prev sidebar size: " << prev_sidebar_function_size << endl;
                 prev_sidebar_function_size = current_item_size;
            }

            window.draw(sb_text);
        }
    }

        current_item_size = 0;
}

string& Sidebar::operator [](int index){

    return items[index];
}
