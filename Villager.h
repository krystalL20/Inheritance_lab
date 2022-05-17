#pragma once

#include "Player.h"

using namespace std;

/*--------------------------------------------------------------------------------------------------------------------------------
	 														This is the Villager Class
	 	This is the first class of the four classes. In this class you must to complete part of the given code, read instructions.													
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

class Villager : public Player
{

private:
    string job;

public:
    Villager(string name, int height, int weight, string job) : Player(name, height, weight)
    {
        this->job = job;
    }

    string getJob() { return job; }
    void setJob(string job) { this->job = job; }

    virtual string toString() {
        string result = "{Villager: ";
        result += "Name=" + this->getName() + " ";
        result += "Height=" + to_string(this->getHeight()) + " ";
        result += "Weight=" + to_string(this->getWeight()) + " ";
        result += "Job=" + this->getJob();
        result += "}";
        return result;
    }
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};
