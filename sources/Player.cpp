#include "Player.hpp"
#include <string>

using namespace std;

namespace coup{

    Player::Player(Game& game, const string& name) : game(game) , name(name){

        last_victim = nullptr;

        game.inrolle(name);
    }


    //getters
    const string& Player::getName(){ return name; }

    unsigned int& Player::getCoins(){ return _coins;}

    Player& Player::getVictim() { return *last_victim; }

    const unsigned int Player::coins() const{  return _coins; }


    void Player::income(){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}
        
        _coins++;
        game.log(name, Event::income);
    }

    void Player::foreign_aid(){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}
        
        _coins += 2;
        game.log(name, Event::aid);
    }

    void Player::coup(Player& victim){

        if (this -> _coins < 7){ throw runtime_error("not enough capital");}

        game.log(name, Event::overthrow);

        game.depose(victim.getName());

        last_victim = &victim;

        _coins -= 7;
    }
}