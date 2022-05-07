#include "Assassin.hpp"

using namespace std;

namespace coup{

    Assassin::Assassin(Game& game, const string& name) :Player(game, name){}

    void Assassin::coup(Player& victim){

        if (this -> _coins < 3){ throw runtime_error("not enough capital");}

        game.log(name, Event::overthrow);

        last_victim = &victim;

        _coins -= 3;
    }
}