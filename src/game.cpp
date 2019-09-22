#include "game.h"

float Game::deltaTime;

sf::RenderWindow* Game::window;
std::stack<State*> Game::states;

sf::Event Game::event;
sf::Clock Game::dtclock;

const int Game::WINDOWX;
const int Game::WINDOWY;

Game::Game(){
    Init();
}
Game::~Game(){
    delete window;
    FreeMemory(states);
}
void Game::Run()noexcept{
    while (window -> isOpen())
    {
        Render();
        UpdateAll();
    }
}
void Game::Init() noexcept{
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
    InitStates();
    
}
void Game::Render()noexcept{
    window -> clear();
    if(!states.empty()){
        states.top()->Render();
    }

    
    window -> display();
}

void Game::UpdateAll()noexcept{
    UpdateDeltaTime();
    while (window -> pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window -> close();
        else if(event.type == sf::Event::Resized){
            window ->setSize(sf::Vector2u(WINDOWX, WINDOWY));
            
        }  
    }

    if(!states.empty()){
        states.top()->UpdateState(deltaTime);
    }


    
}
void Game::UpdateDeltaTime()noexcept{
    deltaTime = dtclock.restart().asSeconds() / 1000.f;
}


void Game::FreeMemory(std::stack<State*>& statesStack){
    while(!statesStack.empty()){
        delete statesStack.top();
        std::cout << "Deleting state -freememory from game!" << std::endl;
        statesStack.pop();
    }
}


void Game::InitStates()noexcept{
    states.push(new GameState(window));
    states.top()->InitState();
}
