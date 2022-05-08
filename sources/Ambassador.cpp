#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game& game, const string& name) : Player(game, name){}

    void Ambassador::transfer (Player& payer, Player& beneficiary){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}

        game.log(name, Event::transfer);

        payer.getCoins() -= 1;
        beneficiary.getCoins() += 1;
    }

    void Ambassador::block (Player& perpetrator){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}
        
        game.log(perpetrator.getName(), Event::block);

        perpetrator.getCoins() -= 2;
        perpetrator.getVictim().getCoins() +=2;

    }
}