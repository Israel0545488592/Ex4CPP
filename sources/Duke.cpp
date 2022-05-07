#include "Duke.hpp"

using namespace std;

namespace coup{

    Duke::Duke(Game& game, const string& name) : Player(game, name){}

    void Duke::sunction (Player& victim){

        game.log(victim.getName(), Event::sanction);

        victim.getCoins() -= 2;
    }

    void Duke::tax (){ 

        game.log(name, Event::tax);
        
        _coins += 3;
    }
}