#include "Player.hpp"

using namespace std;

namespace coup{

    class Duke : public Player{

        public:

        Duke (Game&, const string&);

        void block(Player&);

        void sunction (Player&);

        void tax ();

        const string role() const{ return "Duke";}
    };
}