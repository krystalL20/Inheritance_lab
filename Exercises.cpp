**
 * F21 Inheritance Lab
 */

#include <iostream>
#include <vector>

#include "Player.h"
#include "Villager.h"
#include "Police.h"
#include "Mayor.h"
#include "Chief.h"

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------------------
	   												    EXERCISES												
-------------------------------------------------------------------------------------------------------------------------------*/

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


/*
 * EXERCISE A
 * 
 * Implement the Chief Class constructor by calling its super class constructor
 * and passing the appropriate parameters.
 * HINT: You use the Police class as a guide. And remember a Chief is a rank
*/

Chief::Chief(string name, int height, int weight, int yearsInService) : Police(name, height, weight, "Chief")  //Dummy super constructor
{
    this->yearsInService = yearsInService; 
}

/*
 * EXERCISE B
 * 
 * Override the getSalary method in the Chief class by calling the super
 * getSalary method and adding the bonus times yearInService.
 * If chief has more than 3 years and less than 5 years of service, his salary will be raised 25%
 * If chief has 5 years or more and less that 10 years of service, his salary will be raised 50%
 * If chief has 10 years or more of service, his salary will be raised 75%
 * Otherwise, the salary will not be raised.
 */

double Chief::getSalary()
{
     int years = getYearsInService();
    double salary = Police::getSalary();
    if(years>3 && years <5){
        salary += salary *0.25;
    }
    else if(years>=5 && years <10){
        salary += salary *0.50;
    }
    else if(years>=10){
        salary += salary *0.75;
    }



    return salary;
}

/*
 * EXERCISE C PART 1-a
 * 
 * Override object's method (canEnterEvent) considering
 * the parameter's type string
 * Villager's can only enter the "Party" event
 */

bool Villager::canEnterEvent(string event)
{
    if(event == "Party"){
        return true;
    }

    return false; //Dummy Return
}

/*
 * EXERCISE C PART 1-b
 * 
 * Override object's method canEnterEvent considering
 * the parameter event string
 * Police can only enter the "Party" and "PDMeeting" events
 */

bool Police::canEnterEvent(string event)
{
    if(event == "Party" || event == "PDMeeting"){
        return true;
    }

    return false; //Dummy Return
}

/*
 * EXERCISE C PART 1-c
 * 
 * Override object's method canEnterEvent considering
 * the parameter event string.
 * Mayor can enter the Party, PDMeeting and Presidential Reunion events.
 */

bool Mayor::canEnterEvent(string event)
{
    if(event == "Party" || event == "PDMeeting" || event == "Presidential Reunion"){
        return true;
    }
    

    return false; //Dummy Return
}

/*
 * EXERCISE C PART 2
 * 
 * Create and Override the canDisableAlarm method in the Chief class to
 * return true. Remember that only a Chief can disable alarms.
 */

bool Chief::canDisableAlarm()
{
    //--->>> Implement here! <<<---
    return true; // Dummy return
}

/*
 * EXERCISE D PART 1
 * 
 * Modify each class to greet as follows: (greet() method).
 * Villager: "Hello, I am [name] and I work at [work place]."
 */

string Villager::greet()
{
    //Implement here!

    return "Hello, I am " +getName()+ " and I work at " +getJob() + "."; //Dummy Return
}

/*
 * EXERCISE D PART 2
 * 
 * Modify the greet method to return the following string:
 * "I am Police [name] at your service."
 */

string Police::greet()
{
    //Implement here!

    return "I am Police " +getName()+ " at your service."; //Dummy Return
}

/*
 * EXERCISE D PART 3
 * 
 * Modify each class to greet as follows: (greet() method).
 * Chief: "I am Chief [name]."
 */

string Chief::greet()
{
    //Implement here!

    return ""; //Dummy Return
}

/*
 * EXERCISE D PART 4 
 * 
 * Modify the Mayor's greet method to return the string:
 * "Greetings, I am [name], the Mayor of this city."
 */

string Mayor::greet()
{
    //Implement here!

    return "I am Chief "+ getName() + "."; //Dummy Return
}

/* 
 * EXERCISE E PART 1
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Villager::equals(Player *p)
{
    
    Villager* v = dynamic_cast<Villager*>(p);
    if(v != NULL){
        return (v->getHeight() == this->getHeight() && v->getWeight() == this->getWeight() && v->getName() == this->getName() && v->getJob() == this->getJob());
    }
    return false; //Dummy Return
}

/* 
 * EXERCISE E PART 2
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Police::equals(Player *p)
{
     Police*police = dynamic_cast<Police*>(p);
    if(police !=nullptr){
        return police->getHeight() == this->getHeight() && police->getWeight() == this->getWeight() && police->getName() == this->getName() && police->getRank() == this->getRank();
    }
    //Implement here!

    return false; //Dummy Return
}

/* 
 * EXERCISE E PART 3
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Chief::equals(Player *p)
{
    //Implement here!
     Chief*chief = dynamic_cast<Chief*>(p);
    if(chief != nullptr){
        return chief->getHeight() == this->getHeight() && chief->getWeight() == this->getWeight() && chief->getName() == this->getName() && chief->getYearsInService() == this->getYearsInService();
    }
    
    return false; //Dummy Return
}

/* 
 * EXERCISE E PART 4
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Mayor::equals(Player *p)
{
    //Implement here!
    Mayor*mayor = dynamic_cast<Mayor*>(p);
    if(mayor != nullptr){
        return mayor->getHeight() == this->getHeight() && mayor->getWeight() == this->getWeight() && mayor->getName() == this->getName() && mayor->getTerm() == this->getTerm();
    }

    return false; //Dummy Return
}
