#pragma once

#include <vector>
#include <string>

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------------------
	  													This is the abstract class Player
------------------------------------------------------------------------------------------------------------------------------*/

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

class Player
{
private:
    string name;
    int height;
    int weight;

public:
    Player(string name, int height, int weight)
    {
        this->name = name;
        this->height = height;
        this->weight = weight;
    }
    string getName() { return name; }
    int getHeight() { return height; }
    int getWeight() { return weight; }

    void setName(string name) { this->name = name; }
    void setHeight(int height) { this->height = height; }
    void setWeight(int weight) { this->weight = weight; }

    virtual string toString() = 0;
    virtual bool canDisableAlarm() { return false; }
    virtual bool equals(Player *) = 0;
    virtual string greet() = 0;
    virtual bool canEnterEvent(string event) { return false; }

    static vector<string> countTypesOfPlayersIn(vector<Player*> &list);
};
