#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace coup{

    /* 
      axulery class to map all the possiable events that
      can take place in the game.
    */

    enum class Event{ income, tax, aid, sanction, steal, save, block, overthrow, kill, transfer};

    /*  main class to reprsant the poppular board game coup  */

    class Game{

    private:
        
    vector <string> participants;

    vector <bool> active;       // which players are still in the game

    unsigned long current_player;

    vector <pair<string, Event>> events;

    void check() const;

    public:

    Game();

    //commiting changes/moves
    void inrolle(const string&);                                  // add player
    void log(const string&, const string&, const Event&);          // inroll a move
    void depose(const string&);                                   // remove player
    void revive(const string&);                                   // save a deposed player

    //state of the game
    vector <string> players() const;                              // what players are currently active  
    const string& turn() const;                                   // who's turn is this
    const string& winner() const;                                 // who won
        
    };
}