#include "Captain.hpp"

using namespace std;

namespace coup{

    Captain::Captain(Game& game, const string& name) :Player(game, name){}
    
    void Captain::steal(Player& victim){

        if (_coins >= max_revanue){ throw runtime_error("once acumilated 10 coins, a player must arange a coup");}

        if (! game.alive(victim.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        game.log(name, name, Event::steal);

        if (victim.getCoins() < 2){
            _coins += victim.getCoins();
            victim.getCoins() = 0;
        }else{
            victim.getCoins() -= 2;
            _coins += 2;
        }

        last_victim = &victim;

        game.next();
    }

    void Captain::block (Player& perpetrator){

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