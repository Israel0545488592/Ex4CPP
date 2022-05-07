#include "Ambassador.hpp"

using namespace std;

namespace coup{

    Ambassador::Ambassador(Game& game, const string& name) :Player(game, name){

        last_payer = nullptr;
        last_beneficiary = nullptr;
    }

    void Ambassador::transfer (Player& payer, Player& beneficiary){

        game.log(name, Event::transfer);

        payer.getCoins() -= 1;
        beneficiary.getCoins() += 1;

        last_payer = &payer;
        last_beneficiary = &beneficiary;
    }

    void Ambassador::prevent (Ambassador& mitigator){

        game.log(mitigator.getName(), Event::block);

        mitigator.last_payer -> getCoins() +=1;
        mitigator.last_beneficiary -> getCoins() -=1;

    }
}