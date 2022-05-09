#include "Assassin.hpp"

using namespace std;

namespace coup{

    Assassin::Assassin(Game& game, const string& name) : Player(game, name){}

    void Assassin::coup(Player& victim){

        if (_coins < 3){ throw runtime_error("not enough capital");}

        if (_coins > 7){

            game.log(name, "", Event::overthrow);

            game.depose(victim.getName());

            last_victim = &victim;

            _coins -= 7;

        }else{

            game.log(name, name, Event::kill);

            game.depose(victim.getName());

            last_victim = &victim;

            _coins -= 3;
        }
    }
}