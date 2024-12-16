#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate():system(System(new GraphInfo("0", 'c', sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 0))), sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
//    system = System();
    window.setFramerateLimit(120);

    mouseIn = true;

    index = sidebar.get_history_count(); // get the amount of functions in history
    input = "";
    _info = new GraphInfo("x * sin ( 1 / x )", 'c', sf::Vector2f(1400, 800), sf::Vector2f(0, 0), sf::Vector2f(-M_PI/8, M_PI/8), 30000); //GraphInfo instantiation
    text_box_flag = false; // default value to not allow textentered event to be triggered by key presses
    system = System(_info); // send in instantiated _info by copying a new System Class

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(1.0);
    mousePoint.setFillColor(sf::Color::Blue);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("Arimo-VariableFont_wght.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)

    window.draw(textBox); //draw input textbox on screen
    window.draw(equation); //draw equation sf::Text captured by textEntered event
    window.draw(hover_text); // draw updated text when hover over functions on sidebar


    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){


    //cause changes to the data for the next frame
    system.Step(command, _info);
    
    
    
    
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
//        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);




    }
}
void animate::render(){
       window.clear(sf::Color(34,38,49)); // change background color of window
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;

   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           case sf::Event::MouseWheelMoved:


                   if(event.mouseWheel.delta < 0)      // ZOOM OUT when mousewheel moves down; command =8
                   {
//                        sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                        command = 8;


                   }
                   else if(event.mouseWheel.delta == 0) {}      // does nothing if not moving

                   else                                         // ZOOM IN when mousewheel moves up; command = 10
                   {
//                     sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                       command = 10;

                   }

                    break;

           // key pressed

           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Left:    // PANS LEFT when left arrow key pressed
//                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                   command = 4;
                   break;
               case sf::Keyboard::Right:    // PANS RIGHT when right arrow key pressed
//                   sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   command = 6;
                   break;
               case sf::Keyboard::Up:     // PANS UP when up arrow key pressed
//                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                  command = 14;
                  break;
              case sf::Keyboard::Down:      // PANS DOWN when down arrow key pressed
//                   sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                  command = 16;
                  break;

               case sf::Keyboard::Escape:  //ends program when ESC is pressed
//                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;

               case sf::Keyboard::Return:     //sets graph info to string inout by user, resets orion to 0 and domain to (-pi,pi), command = 18 sent to System step
//               sidebar[SB_KEY_PRESSED] = "Enter Function";
                   cout << "index: " << index << endl;
               sidebar[index] = input;   // send input string to sidebar items string vector to draw to screen in sidebar
               index++;
               _info->_equation = input;  // set graph input equation to input string
               _info->_origin.x = 0;
               _info->_origin.y = 0;
               _info->_domain = sf::Vector2f(-M_PI, M_PI);
               system = System(_info);
               command = 18;
               input.clear();   // clears input string after Enter is pressed
               textBox.setFillColor(sf::Color::Transparent); //sets textbox rectangle to transparent when function is Enter
               textBox.setOutlineColor(sf::Color::Transparent);




            break;

               case sf::Keyboard::Space:    //Makes textbox Rectangleshape visible and Text objec; sets text_box_flag to true to allow textentered events
//               sidebar[SB_KEY_PRESSED] = "SPACE";
               text_box_flag = true;
               textBox.setSize(sf::Vector2f(500, 55));
               textBox.setFillColor(sf::Color(34,38,49));
               textBox.setOutlineColor(sf::Color(27,161,242));
               textBox.setOutlineThickness(1.5);
               textBox.setPosition(sf::Vector2f(308, 650));




            break;

               case sf::Keyboard::Backspace:    // removes last character from input string
//               sidebar[SB_KEY_PRESSED] = "BACKSPACE";
               if(!input.empty()) input.pop_back();
               cout << "trigger '\\b' " << endl;
               cout << endl << static_cast<int>(event.text.unicode);





            break;

           }

               case sf::Event::TextEntered:  // captures input function typed through keyboard


    //               sidebar[SB_KEY_PRESSED] = (event.text.unicode);

               if(!text_box_flag)break;

                   if (event.text.unicode == 57)
                   {
                       input += " ";

                       cout << "trigger ' ' " << endl;

                   }

                   else if((event.text.unicode > 39 && event.text.unicode < 48) ||  event.text.unicode == 94) // && event.text.unicode != 49 to use comma exclude from alnum
                   {

                        char punct = static_cast<char>(event.text.unicode);
                         input += punct;
                        cout << endl << static_cast<int>(event.text.unicode);
                        cout << endl << input << endl;
                        cout << "trigger ispunct " << endl;


                   }

                   else if(isalnum(event.text.unicode) && event.text.unicode != 57 && event.text.unicode != 56 && event.text.unicode != 55
                           && event.text.unicode != 52  && event.text.unicode != 71 && event.text.unicode != 72
                           && event.text.unicode != 73 && event.text.unicode != 74)
                   {
                        input += (static_cast<char>(event.text.unicode));
                        cout << endl << static_cast<int>(event.text.unicode);
                        cout << endl << input << endl;
                        cout << "trigger isalnum " << endl;


                   }

                   else{}


                   equation.setString(input);   // send input string to Text object
                   equation.setFont(font);
                   equation.setCharacterSize(24);
                   equation.setColor(sf::Color(217,218,228));
                   equation.setPosition(sf::Vector2f(320, 662));

                   if(input.empty()) text_box_flag = false; // sets textbox flag to false when the input is empty after sending it to Text object
                   break;



           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved: // tracks position of cursor as it is moving on the screen
           {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;


               vector<sf::Text> sidebar_funcs = sidebar.get_sidebar_functions();

              for (vector<sf::Text>::iterator it = sidebar_funcs.begin(); it != sidebar_funcs.end(); it++)  // checks if cursor is above the Text Objects
                                                                                                            //on sidebar and changes t color of Text to orange
              {
                  if (it->getGlobalBounds().contains(mouseX, mouseY))
                  {
                      it->setFillColor(sf::Color(255, 69, 0));
                      hover_text = *it;
                      break;
                  }
                }

                //Do something with it if you need to...
               break;
           }
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
//                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
//                               mouse_pos_string(window);

                   }
                   else{
//                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
//                               mouse_pos_string(window);
                        sf::Vector2<int> localMousePos = sf::Mouse::getPosition(window);
                       vector<sf::Text> sidebar_funcs = sidebar.get_sidebar_functions();

                      for (vector<sf::Text>::iterator it = sidebar_funcs.begin(); it != sidebar_funcs.end(); it++) // checks if a left click realease is on equation in Sidebar
                                                                                                                    // if it is, grabs equation string and set _info equation to that equation
                      {
                          if (it->getGlobalBounds().contains(localMousePos.x, localMousePos.y))
                          {
                              cout << endl << "clicked in bounds" << endl << " function clicked : " << it->getString().toAnsiString() << endl;
                                  _info->_equation = it->getString().toAnsiString();
                                  _info->_origin.x = 0;
                                  _info->_origin.y = 0;
                                  _info->_domain = sf::Vector2f(-M_PI, M_PI);
                                  command = 12;
                                  system = System(_info);
                          }
                      }

                   }
                   break;

               default:
                   break;
           }
       }
}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
