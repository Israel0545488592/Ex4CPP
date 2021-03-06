#include "Player.hpp"

using namespace std;

namespace coup{

    class Captain : public Player{

    public:

    Captain (Game&, const string&);

    void steal(Player&);            // steal 2 coins from someone

    void block (Player&);           // prevents theft

    string role() const{ return "Captain";}
    };
}