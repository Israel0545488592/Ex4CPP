#include "Player.hpp"

using namespace std;

namespace coup{

    class Ambassador : public Player{

        private:

        Player* last_payer;
        Player* last_beneficiary;

        public:

        Ambassador (Game&, const string&);

        void transfer (Player&, Player&);       // transfer 1 coin between 2 players

        void prevent (Ambassador&);             // prevent theft

        const string role() const{ return "Ambassador";}
    };
}