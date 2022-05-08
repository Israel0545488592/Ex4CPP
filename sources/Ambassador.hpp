#include "Player.hpp"

using namespace std;

namespace coup{

    class Ambassador : public Player{

        public:

        Ambassador (Game&, const string&);

        void transfer (Player&, Player&);       // transfer 1 coin between 2 players

        void block (Player&);                   // prevent theft

        string role() const{ return "Ambassador";}
    };
}