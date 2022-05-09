#include "Player.hpp"
#include <string>

using namespace std;

namespace coup{

    Player::Player(Game& game, const string& name) : game(game) , name(name){

        _coins = 0;

        last_victim = nullptr;

        game.inrolle(name);
    }


    //getters
    const string& Player::getName(){ return name; }

    unsigned int& Player::getCoins(){ return _coins;}

    Player& Player::getVictim() { return *last_victim; }

    unsigned int Player::coins() const{  return _coins; }


    void Player::income(){

        if (_coins >= max_revanue){ throw runtime_error("once acumilated 10 coins, a player must arange a coup");}

        game.log(name, "", Event::income);
        
        _coins++;

        game.next();
    }

    void Player::foreign_aid(){

        if (_coins >= max_revanue){ throw runtime_error("once acumilated 10 coins, a player must arange a coup");}

        game.log(name, name, Event::aid);
        
        _coins += 2;

        game.next();
    }

    void Player::coup(Player& victim){

        if (this -> _coins < coup_cost){ throw runtime_error("not enough capital");}

        if (! game.alive(victim.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        game.log(name, "", Event::overthrow);

        game.depose(victim.getName());

        last_victim = &victim;

        _coins -= coup_cost;

        game.next();
    }
}