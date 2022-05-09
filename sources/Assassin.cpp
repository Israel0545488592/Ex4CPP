#include "Assassin.hpp"

using namespace std;

namespace coup{

    Assassin::Assassin(Game& game, const string& name) : Player(game, name){}

    void Assassin::coup(Player& victim){

        if (_coins < assassination_cost){ throw runtime_error("not enough capital");}

        if (! game.alive(victim.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        if (_coins >= coup_cost){

            game.log(name, "", Event::overthrow);

            game.depose(victim.getName());

            last_victim = &victim;

            _coins -= coup_cost;

        }else{

            game.log(name, name, Event::kill);

            game.depose(victim.getName());

            last_victim = &victim;

            _coins -= assassination_cost;
        }

        game.next();
    }
}