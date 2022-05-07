#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "doctest.h"

using namespace std;
using namespace coup;

static Game game;

static Duke duke{game, "balfor"};
static Assassin assassin{game, "ali"};
static Ambassador ambassador{game, "rabin"};
static Captain captain{game, "david"};
static Contessa contessa{game, "golda"};


TEST_CASE("Good input") {


    //basic round
    // CHECK_EQ(game.turn(), "balfor");
    // CHECK_NOTHROW(duke.income());
    // CHECK_EQ(game.turn(), "ali");
    // CHECK_NOTHROW(assassin.income());
    // CHECK_EQ(game.turn(), "rabin");
    // CHECK_NOTHROW(ambassador.income());
    // CHECK_EQ(game.turn(), "david");
    // CHECK_NOTHROW(captain.income());
    // CHECK_EQ(game.turn(), "golda");
    // CHECK_NOTHROW(contessa.income());
    // CHECK_EQ(game.turn(), "balfor");

    //basic round
    // CHECK_EQ(game.turn(), "balfor");
    // CHECK_NOTHROW(duke.foreign_aid());
    // CHECK_EQ(game.turn(), "ali");
    // CHECK_NOTHROW(assassin.foreign_aid());
    // CHECK_EQ(game.turn(), "rabin");
    // CHECK_NOTHROW(ambassador.foreign_aid());
    // CHECK_EQ(game.turn(), "david");
    // CHECK_NOTHROW(captain.foreign_aid());
    // CHECK_EQ(game.turn(), "golda");
    // CHECK_NOTHROW(contessa.foreign_aid());
    // CHECK_EQ(game.turn(), "balfor");


    //spacial abilities
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.transfer(assassin, ambassador));
    CHECK_NOTHROW(captain.steal(duke));
    CHECK_NOTHROW(contessa.block(captain));

    // //check balance
    // CHECK_EQ(duke.coins(), 6);
    // CHECK_EQ(assassin.coins(), 3);
    // CHECK_EQ(ambassador.coins(), 4);
    // CHECK_EQ(captain.coins(), 3);
    // CHECK_EQ(contessa.coins(), 3);

    for(int i = 0; i < 20; i++){
        CHECK_NOTHROW(game.players());
    }
    
}



TEST_CASE("Bad input") {

     CHECK_THROWS(assassin.income());   //not his turn

}