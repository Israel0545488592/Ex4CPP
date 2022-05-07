#include "Contessa.hpp"

using namespace std;

namespace coup{

    Contessa::Contessa(Game& game, const string& name) :Player(game, name){}

    void Contessa::block (Player& perpetrator){

        game.log(perpetrator.getName(), Event::save);

        game.revive(perpetrator.getVictim().getName());
    }
}