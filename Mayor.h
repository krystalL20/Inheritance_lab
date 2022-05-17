#pragma once

#include "Player.h"

using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------
		                                              This is the Mayor Class
         This is the fourth class of the four classes. In this class you must to complete part of the given code, read instructions.													
------------------------------------------------------------------------------------------------------------------------------------*/

    /*                          Player
    *                       /     |     \
    *                      /      |      \
    *                     /       |       \
    *               Villager   Police     Mayor
    *                             |
    *                             |
    *                           Chief
    * 
    */

class Mayor : public Player
{

private:
    int term;

public:
    Mayor(string name, int height, int weight, int term) : Player(name, height, weight)
    {
        this->term = term;
    }

    int getTerm() { return term; }
    void setTerm(int term) { this->term = term; }

    virtual string toString() {
        string result = "{Mayor: ";
        result += "Name=" + this->getName() + " ";
        result += "Height=" + to_string(this->getHeight()) + " ";
        result += "Weight=" + to_string(this->getWeight()) + " ";
        result += "Term=" + to_string(this->getTerm()) + " ";
        result += "}";
        return result;
    }
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};
