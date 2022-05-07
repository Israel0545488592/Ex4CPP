#include "Game.hpp"

using namespace std;

//documantaion in Game.hpp

namespace coup{

    void Game::inrolle(const string& name){ 
        
        participants.push_back(name);
        active.push_back(true);
    }

    void Game::log(const string& name , const Event& event){

        events.push_back({name, event});        // register

        check();                                // ligallity

        current_player++;                       // turn track
        current_player %= participants.size();
    }

    vector <string> Game::players () const{ return participants; }

    const string& Game::turn() const{

        if (participants.size() == 0){ throw runtime_error("no participants");}

        return participants[current_player];
    }

    const string& Game::winner() const{

        if (participants.size() > 1){ throw runtime_error("the game isnt over");}

        return participants[0];
    }

    void Game::depose(const string& victim){

        for (unsigned long i = 0; i < participants.size(); i++){
            
            if (participants[i] == victim){
                active[i] = false;
                return;
            }
        }
        throw runtime_error("a player tried to depose someone from another game");
    }

    void Game::revive(const string& victim){

        for (unsigned long i = 0; i < participants.size(); i++){
            
            if (participants[i] == victim){
                active[i] = true;
                return;
            }
        }
        throw runtime_error("a player tried to save someone from another game");
    }

    /*
        Making sure no illigal move has been executed, this method
        is a bit complicated since it implements all the rules.

        for each event the code scans the history of the game
        ONE round back to see if it makes sense.

        the method only verefy validty. the actuall changes
        are done by the players cause they have the  oversight
    */
    void Game::check() const{

        unsigned long last_ind = events.size() -1;

        pair <string, Event> last = events[last_ind];

        string suspect = last.first;

        if (suspect != participants[current_player]){ throw runtime_error(suspect + "played not on her/is turn");}

        //all possiable moves

        switch (last.second){

        case Event::block:

            for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::steal){
                    if (events[last_ind -i].first == suspect){
                        break;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");

        case Event::sanction:

            for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::aid){
                    if (events[last_ind -i].first == suspect){
                        break;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");

        case Event::save:
            
             for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::overthrow){
                    if (events[last_ind -i].first == suspect){
                        break;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");
        
        default:
            break;
        }
        
    }
}