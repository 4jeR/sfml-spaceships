#include "application.h"


sf::RenderWindow* Application::window;
std::stack<State*> Application::states;
Player* Application::player;

sf::Event Application::event;
sf::Clock Application::dtclock;

const int Application::WINDOWX;
const int Application::WINDOWY;

Application::Application(){
    InitWindow();
    InitStates();
}
Application::~Application(){
    delete window;
    delete player;
    FreeStatesMemory();
}
void Application::Run()noexcept{
    while (window -> isOpen())
    {
        Render();
        UpdateAll();
    }
}


void Application::Render()noexcept{
    window -> clear();
    if(!states.empty()){
        states.top()->Render();
    }

    
    window -> display();
}

void Application::UpdateAll()noexcept{
    while (window -> pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window -> close();
        else if(event.type == sf::Event::Resized){
            window ->setSize(sf::Vector2u(WINDOWX, WINDOWY));
        }  
    }
    // switching through states logic will be moved in states' logic
    if(!states.empty()){
        states.top()->UpdateState(states, window);
    }
    
    else{
        std::cout << "states stack is empty -> closing window!" << std::endl;
        window -> close();
    }


    
}



void Application::FreeStatesMemory(){
    while(!states.empty()){
        delete states.top();
        std::cout << "Deleting state - freememory from application!" << std::endl;
        states.pop();
    }
}

void Application::InitWindow()noexcept{
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
}

void Application::InitStates()noexcept{
    states.push(new MenuState(window));
    states.top()->InitState(states, window);
    /**
     * NOTE:
     *      this should be probably organised in different sections 
     *      states.push(mainmenu)
     *      states.top()->InitState();
     *      
     *      then based on user input 
     *      states.push(state [gamestate / options? / about / quitstate]
     * 
    */
}
