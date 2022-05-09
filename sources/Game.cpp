#include "Game.hpp"

using namespace std;

//documantaion in Game.hpp

namespace coup{

    Game::Game(){

        current_player = 0;
    }

    void Game::inrolle(const string& name){ 
        
        participants.push_back(name);
        active.push_back(true);
    }

    void Game::log(const string& player, const string& comitter, const Event& event){

        events.push_back({comitter, event});   // register

        if (player != participants[current_player]){ throw runtime_error(player + " played not on her/is turn");}

        check();                                // ligallity


        // turn track
        current_player++;
        current_player %= participants.size();

        while (! active[current_player]){
            
            current_player++;
            current_player %= participants.size();
        }
    }

    vector <string> Game::players () const{ 
        
        vector <string> ans;

        for (unsigned long i = 0; i < participants.size(); i++){

            if (active[i]){
                ans.push_back(participants[i]);
            }
        }
        return ans;
     }

    const string& Game::turn() const{

        if (participants.size() == 0){ throw runtime_error("no participants");}

        return participants[current_player];
    }

    const string& Game::winner() const{

        bool game_over = true;
        unsigned long winner = 0;

        for (unsigned long i = 0; i < participants.size(); i++){

            if (active[i]){
                if (game_over){

                    winner = i;
                    game_over = false;

                }else{
                    
                    throw runtime_error("game is not over");
                }
            }
        }
        return participants[winner];
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
        Making sure no illigal move has been executed.

        for each event the code scans the history of the game
        ONE round back to see if it makes sense.

        the method only verefy validty. the actuall changes
        are done by the players cause they have the oversight
    */
    void Game::check() const{

        unsigned long last_ind = events.size() -1;

        pair <string, Event> last = events[last_ind];

        string suspect = last.first;

        //all possiable moves

        switch (last.second){

        case Event::block:

            for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::steal){
                    if (events[last_ind -i].first == suspect){
                        return;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");

        case Event::sanction:

            for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::aid){
                    if (events[last_ind -i].first == suspect){
                        return;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");

        case Event::save:
            
             for (unsigned long i = 1; i < participants.size() -1; i++){

                if (events[last_ind -i].second == Event::kill){
                    if (events[last_ind -i].first == suspect){
                        return;
                    }
                }
            } 
            throw runtime_error("someone tried to block an insant particpant");
        
        default:
            break;
        }
        
    }
}