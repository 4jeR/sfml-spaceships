#include "application.h"


sf::RenderWindow* Application::window;
std::array<State*, 5> Application::states;
long unsigned int Application::currentState = 0;

sf::Event Application::event;
sf::Clock Application::dtclock;

const int Application::WINDOWX;
const int Application::WINDOWY;

Application::Application()
{
    srand(std::rand()%RAND_MAX);
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
    InitStates();
}


Application::~Application(){
    delete window;
    FreeStatesMemory();
}


void Application::Run()noexcept{
    while (window -> isOpen()){
        UpdateAll();
        Render();
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
    states[currentState]->UpdateState(states, currentState);
}


void Application::FreeStatesMemory(){
    for(auto& state : states){
        delete state;
    }
}


void Application::InitStates()noexcept{
    states[0] = new MenuState(states, window);      
    states[1] = new GameState(states, window);      
    states[2] = new PauseState(states, window);     
    states[3] = new OptionsState(states, window);   
    states[4] = new EndState(states, window);
}
