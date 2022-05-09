#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game& game, const string& name) : Player(game, name){}

    void Ambassador::transfer (Player& payer, Player& beneficiary){

        if (_coins >= max_revanue){ throw runtime_error("once acumilated 10 coins, a player must arange a coup");}

        if (! game.alive(beneficiary.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        if (! game.alive(payer.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        if (payer.getCoins() == 0){ throw runtime_error("not enough money for transfer");}

        payer.getCoins()--;
        beneficiary.getCoins()++; 

        game.log(name, "", Event::transfer);

        game.next();
    }

    void Ambassador::block (Player& perpetrator){

        if (! game.alive(perpetrator.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}
        
        game.log(name, perpetrator.getName(), Event::block);

        if (perpetrator.getCoins() >= 2){

            perpetrator.getCoins() -= 2;
            perpetrator.getVictim().getCoins() +=2;
        }else{

            perpetrator.getVictim().getCoins() += perpetrator.getCoins();
            perpetrator.getCoins() = 0;
        }
    }
}