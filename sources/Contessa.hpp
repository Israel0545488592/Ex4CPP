#include "Player.hpp"

using namespace std;

namespace coup{

    class Contessa : public Player{

    public:

    Contessa (Game&, const string&);

    void block (Player&);   // prevent theft

    const string role() const{ return "Contessa";}
    };
}