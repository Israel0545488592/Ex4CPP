#include "Captain.hpp"

using namespace std;

namespace coup{

    Captain::Captain(Game& game, const string& name) :Player(game, name){}
    
    void Captain::steal(Player& victim){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}

        game.log(name, name, Event::steal);

        if (victim.getCoins() < 2){
            victim.getCoins() = 0;
        }else{
            victim.getCoins() -= 2;
        }
        _coins +=2;

        last_victim = &victim;
    }

    void Captain::block (Player& perpetrator){

        if (_coins >= 10){ throw runtime_error("one acumilated 10 coins, a player must arange a coup");}
        
        game.log(name, perpetrator.getName(), Event::block);

        if(perpetrator.getCoins() < 2){
            perpetrator.getCoins() = 0;
        }else{
            perpetrator.getCoins() -= 2;
        }
        perpetrator.getVictim().getCoins() +=2;
    }
}