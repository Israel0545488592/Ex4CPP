#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::Duke(Game& game, const string& name) : Player(game, name){}

    void Duke::block (Player& victim){

        if (! game.alive(victim.getName())){ throw runtime_error("someone tried to pull a move on an inactive or out of game player");}

        game.log(name, victim.getName(), Event::sanction);

        if (victim.getCoins() < 2){
            victim.getCoins() = 0;
        }else{
            victim.getCoins() -= 2;
        }
    }

    void Duke::tax (){ 

        if (_coins >= max_revanue){ throw runtime_error("once acumilated 10 coins, a player must arange a coup");}

        game.log(name, "", Event::tax);
        
        _coins += 3;

        game.next();
    }
}