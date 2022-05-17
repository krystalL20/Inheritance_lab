#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Player.h"
#include "Villager.h"
#include "Police.h"
#include "Mayor.h"
#include "Chief.h"

using namespace std;

TEST_CASE("Lab 6 Test"){

    string expected, output;
    bool accepted, result;
   
    SUBCASE("Ex A"){
        Chief *c1 = new Chief("Gabriel", 60, 150, 3);
        Chief *c2 = new Chief("Fabiola", 60, 110, 2);

        expected = "{Chief: Name=Gabriel, Height=60, Weight=150, Rank=Chief, Years=3}";
        output = c1->toString();
        CHECK(expected == output);

        expected = "{Chief: Name=Fabiola, Height=60, Weight=110, Rank=Chief, Years=2}";
        output = c2->toString();
        CHECK(expected == output);
        
    }
    SUBCASE("Ex B"){

        Chief *c1 = new Chief("Bienve", 60, 100, 0);
        Chief *c2 = new Chief("Dionel", 65, 150, 1);

        expected = "50000";
        output = to_string(c1->getSalary());
        CHECK(expected == output);

        expected = "50000";
        output = to_string(c2->getSalary());
        CHECK(expected == output);
    }
    SUBCASE("Ex C 1"){
        Villager *v = new Villager("Fabiola", 72, 100, "BlackSmithShop");
        Police *p = new Police("Everson", 60, 136, "ClerkPlace");
        Mayor *m = new Mayor("Bienve", 70, 139, 10);

        SUBCASE("Ex C 1a"){
            accepted = true;
            result = v->canEnterEvent("Party");
            CHECK(accepted == result);

            accepted = false;
            result = v->canEnterEvent("PDMeeting"); 
            CHECK(accepted == result);

            accepted = false;
            result = v->canEnterEvent("Presidential Reunion");
            CHECK(accepted == result);

        }
        SUBCASE("Ex C 1b"){
            accepted = true;
            result = p->canEnterEvent("Party");
            CHECK(accepted == result);

            accepted = true;
            result = p->canEnterEvent("PDMeeting"); 
            CHECK(accepted == result);

            accepted = false;
            result = p->canEnterEvent("Presidential Reunion");
            CHECK(accepted == result);

        }
        SUBCASE("Ex C 1c"){
            accepted = true;
            result = m->canEnterEvent("Party");
            CHECK(accepted == result);

            accepted = true;
            result = m->canEnterEvent("PDMeeting"); 
            CHECK(accepted == result);

            accepted = true;
            result = m->canEnterEvent("Presidential Reunion");
            CHECK(accepted == result);

        }

    }
    SUBCASE("Ex C 2"){
        Villager *v = new Villager("Jose", 60, 100, "PizzaPlace");
        Police p1 = Police("Kevin", 64, 130, "Clerk");
        Police p2 = Chief("Puig", 67, 145, 5);
        Police *c = new Chief("Alejandra", 67, 119, 5);
        Mayor *m = new Mayor("Bienve", 68, 90, 15);

        accepted = false;
        result = v->canDisableAlarm();
        CHECK(accepted == result);

        accepted = false;
        result = p1.canDisableAlarm();
        CHECK(accepted == result);

        accepted = false;
        result = p2.canDisableAlarm();
        CHECK(accepted == result);

        accepted = true;
        result = c->canDisableAlarm();
        CHECK(accepted == result);

        accepted = false;
        result = m->canDisableAlarm();
        CHECK(accepted == result);
        
    }
    SUBCASE("Ex D"){
        Villager *v = new Villager("Alberto", 72, 99, "BlackSmithShop");
        Police *p = new Police("Everson", 77, 112, "ClerkPlace");
        Chief *c = new Chief("Dionel", 61, 147, 5);
        Mayor *m = new Mayor("Bienve", 70, 186, 10);

        SUBCASE("Ex D 1") {
            expected = "Hello, I am Alberto and I work at BlackSmithShop.";
            output = v->greet();
            CHECK(expected == output);
        }
        SUBCASE("Ex D 2") {
            expected = "I am Police Everson at your service.";
            output = p->greet();
            CHECK(expected == output);
        }
        SUBCASE("Ex D 3") {
            expected = "I am Chief Dionel.";
            output = c->greet();
            CHECK(expected == output);
        }
        SUBCASE("Ex D 4") {
            expected = "Greetings, I am Bienve, the Mayor of this city.";
            output = m->greet();
            CHECK(expected == output);
        }

    }
    SUBCASE("Ex E") {
        Villager *v = new Villager("Alberto", 72, 99, "BlackSmithShop");
        Police *p = new Police("Kevin", 77, 112, "ClerkPlace");
        Chief *c = new Chief("Jose", 61, 147, 5);
        Mayor *m = new Mayor("Enrique", 70, 186, 10);

        SUBCASE("Ex E 1"){
            accepted = false;
            result = v->equals(m);
            CHECK(accepted == result);

            accepted = true;
            result = v->equals(v);
            CHECK(accepted == result);
        }
        SUBCASE("Ex E 2"){
            accepted = false;
            result = p->equals(c);
            CHECK(accepted == result);

            accepted = true;
            result = p->equals(p);
            CHECK(accepted == result);
        }
        SUBCASE("Ex E 3"){
            accepted = false;
            result = c->equals(p);
            CHECK(accepted == result);

            accepted = true;
            result = c->equals(c);
            CHECK(accepted == result);
        }
        SUBCASE("Ex E 4"){
            accepted = false;
            result = m->equals(v);
            CHECK(accepted == result);

            accepted = true;
            result = m->equals(m);
            CHECK(accepted == result);
        }

    }
    SUBCASE("BONUS"){

        const int villagerIndex = 0, policeIndex = 1, mayorIndex = 2;

        Villager *v = new Villager("Dionel", 72, 99, "BlackSmithShop");
        Police *p = new Police("Gabriel", 77, 112, "ClerkPlace");
        Chief *c = new Chief("Everson", 61, 147, 5);
        Mayor *m = new Mayor("Fabiola", 70, 186, 10);

        vector<Player*> list = {c, m, p, v};

        vector<string> playersCount = Player::countTypesOfPlayersIn(list);

        expected = "1";
        output = playersCount.at(villagerIndex);
        CHECK(expected == output);

        expected = "2";
        output = playersCount.at(policeIndex);
        CHECK(expected == output);

        expected = "1";
        output = playersCount.at(mayorIndex);
        CHECK(expected == output);

        // !
        list.pop_back();
        list.push_back(c);
        list.push_back(new Mayor("Enrique", 70, 186, 10));

        playersCount = Player::countTypesOfPlayersIn(list);
        // !

        expected = "0";
        output = playersCount.at(villagerIndex);
        CHECK(expected == output);

        expected = "3";
        output = playersCount.at(policeIndex);
        CHECK(expected == output);

        expected = "2";
        output = playersCount.at(mayorIndex);
        CHECK(expected == output);
        
    }
}
