#include "application.h"


sf::RenderWindow* Application::window;
std::array<State*, 3> Application::states;
long unsigned int Application::currentState = 0;

sf::Event Application::event;
sf::Clock Application::dtclock;

const int Application::WINDOWX;
const int Application::WINDOWY;

Application::Application()
{
    // init window
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");

    // init states
    states[0] = new MenuState(states, window);
    states[1] = new GameState(states, window);
    states[2] = new PauseState(states, window);
    currentState = 0;
}
Application::~Application(){
    delete window;
    
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
        states[currentState]->Render();
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
    
    states[currentState]->UpdateState(states, currentState, window);
    
}



void Application::FreeStatesMemory(){
    for(auto& state : states){
        delete state;
    }
}

void Application::InitStates()noexcept{
    
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
