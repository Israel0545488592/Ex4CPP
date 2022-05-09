#include "Contessa.hpp"

using namespace std;

namespace coup{

    Contessa::Contessa(Game& game, const string& name) :Player(game, name){}

    void Contessa::block (Player& perpetrator){

        if (! game.alive(perpetrator.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        game.log(name, perpetrator.getName(), Event::save);

        game.revive(perpetrator.getVictim().getName());
    }
}