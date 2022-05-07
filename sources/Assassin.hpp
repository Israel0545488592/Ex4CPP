#include "Player.hpp"

using namespace std;

namespace coup{

    class Assassin : public Player{

        public:

        void coup(Player&);

        Assassin (Game&, const string&);

        const string role() const{ return "Assassin";}
    };
}