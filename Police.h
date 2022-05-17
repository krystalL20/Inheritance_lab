#pragma once

#include "Player.h"

using namespace std;

/*--------------------------------------------------------------------------------------------------------------------------------
													   This is the Police Class
        This is the second class of the four classes. In this class you must to complete part of the given code, read instructions.													
----------------------------------------------------------------------------------------------------------------------------------*/

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

class Police : public Player
{

private:
    const double SALARY = 50000;
    string rank;

public:
    Police(string name, int height, int weight, string rank) : Player(name, height, weight)
    {
        this->rank = rank;
    }

    string getRank() { return rank; }
    void setRank(string rank) { this->rank = rank; }

    virtual double getSalary() { return SALARY; }

    virtual string toString() {
        string result = "{Police: ";
        result += "Name=" + this->getName() + " ";
        result += "Height=" + to_string(this->getHeight()) + " ";
        result += "Weight=" + to_string(this->getWeight()) + " ";
        result += "Rank=" + this->getRank() + " ";
        result += "}";
        return result;
    }
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};
