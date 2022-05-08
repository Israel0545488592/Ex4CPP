#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::Duke(Game& game, const string& name) : Player(game, name){}

    void Duke::block (Player& victim){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}

        game.log(victim.getName(), Event::sanction);

        if (victim.getCoins() < 2){
            victim.getCoins() = 0;
        }else{
            victim.getCoins() -= 2;
        }
    }

    void Duke::tax (){ 

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}

        game.log(name, Event::tax);
        
        _coins += 3;
    }
}