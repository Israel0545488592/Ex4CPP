#include "Contessa.hpp"

using namespace std;

namespace coup{

    Contessa::Contessa(Game& game, const string& name) :Player(game, name){}

    void Contessa::block (Player& perpetrator){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}

        game.log(perpetrator.getName(), Event::save);

        game.revive(perpetrator.getVictim().getName());
    }
}