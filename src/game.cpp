#include "game.h"

float Game::deltaTime;

sf::RenderWindow* Game::window;
std::stack<State*> Game::states;
Player* Game::player;
ObjectCleaner Game::cleaner;

sf::Event Game::event;
sf::Clock Game::dtclock;

const int Game::WINDOWX;
const int Game::WINDOWY;

Game::Game(){
    InitWindow();
    InitStates();
}
Game::~Game(){
    delete window;
    FreeStatesMemory();
}
void Game::Run()noexcept{
    while (window -> isOpen())
    {
        Render();
        UpdateAll();
    }
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
        states.top()->UpdateState();
        if(states.top()->CheckForQuit()){
            delete states.top();
            states.pop();
        }
    }
    else{
        std::cout << "states stack is empty -> closing window!";
        window -> close();
    }


    
}
void Game::UpdateDeltaTime()noexcept{
    deltaTime = dtclock.restart().asSeconds() / 1000.f;
}


void Game::FreeStatesMemory(){
    while(!states.empty()){
        delete states.top();
        std::cout << "Deleting state -freememory from game!" << std::endl;
        states.pop();
    }
}

void Game::InitWindow()noexcept{
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
}

void Game::InitStates()noexcept{
    // states.push(new MenuState)
    states.push(new GameState(window));
    states.top()->InitState();
    /**
     * NOTE:
     *      this should be probably organised in different sections 
     *      states.push(mainmenu)
     *      states.top()-InitState();
     *      
     *      then based on user input 
     *      states.push(state [gamestate / options? / about / quitstate]
     * 
    */
}
