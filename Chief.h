#pragma once

#include "Police.h"

using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------------
	   													This is the Chief Class
		This is the third class of the four classes. In this class you must to complete part of the given code, read instructions.													
-----------------------------------------------------------------------------------------------------------------------------------*/

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

class Chief : public Police
{

private:
    int yearsInService;

public:
    Chief(string name, int height, int weight, int yearsInService);

    int getYearsInService() { return yearsInService; }
    void setYearInService(int yearsInService) { this->yearsInService = yearsInService; }

    virtual double getSalary();

    virtual string toString() {
        string result = "{Chief: ";
        result += "Name=" + this->getName() + ", ";
        result += "Height=" + to_string(this->getHeight()) + ", ";
        result += "Weight=" + to_string(this->getWeight()) + ", ";
        result += "Rank=" + this->getRank() + ", ";
        result += "Years=" + to_string(this->getYearsInService());
        result += "}";
        return result;
    }
    virtual bool canDisableAlarm();
    virtual string greet();
    virtual bool equals(Player *p);
};
