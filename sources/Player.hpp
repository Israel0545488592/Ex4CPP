#pragma once
#include "Game.hpp"

using namespace std;

namespace coup{

    /* A base class for the different roles a participant can play on the game*/

    class Player{

        protected:

            int id;

            unsigned int _coins;

            string name;

            Game game;

            Player* last_victim;

        public:

            Player (Game&, const string&);

            // game methods
            void income();
            virtual void coup(Player&);
            void foreign_aid();

            //getters
            const string& getName();
            unsigned int& getCoins();
            Player& getVictim();
            const unsigned int coins() const;          // how many coins I have
            virtual string role() const = 0;           // what is my role
    };
}