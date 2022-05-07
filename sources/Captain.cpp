#include "Captain.hpp"

using namespace std;

namespace coup{

    Captain::Captain(Game& game, const string& name) :Player(game, name){}
    
    void Captain::steal(Player& victim){

        game.log(name, Event::steal);

        victim.getCoins() -=2;
        _coins +=2;

        last_victim = &victim;
    }

    void Captain::block (Player& perpetrator){
        
        game.log(perpetrator.getName(), Event::block);

        perpetrator.getCoins() -= 2;
        perpetrator.getVictim().getCoins() +=2;
    }
}