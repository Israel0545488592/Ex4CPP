#include "Player.hpp"

using namespace std;

namespace coup{

    class Assassin : public Player{

        public:

        virtual void coup(Player&);

        Assassin (Game&, const string&);

        string role() const{ return "Assassin";}
    };
}