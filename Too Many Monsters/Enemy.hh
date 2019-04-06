#ifndef ENEMY_HH_INCLUDED
#define ENEMY_HH_INCLUDED
#include "Main.h"

using namespace std;

class Character;

class Enemy{
protected:
    int ATK, DEF, HEA, DEX, ACC, DMGD, BLEED, STUN;
    double CHEA;
    string NAME;
public:
    void setName(string a);
    void setATK(int n);
    void setDEF(int n);
    void setHEA(int n);
    void setCHEA(int n);
    void setDEX(int n);
    void setACC(int n);
    void setSTUN(int n);

    void ChangeATK(int n);
    void ChangeBLEED(int n);
    void ChangeDMGD(int n);
    void ChangeDEF(int n);
    void ChangeACC(int n);
    void ChangeHEA(int n);
    void ChangeCHEA(double n);
    void ChangeDEX(int n);
    void ChangeSTUN(int n);

    string getName();
    int getHEA();
    int getCHEA();
    int getATK();
    int getACC();
    double getDEF();
    int getDEX();
    int getBLEED();
    int getSTUN();

    bool isAlive();
    bool IsBleed();
    bool IsStun();
    virtual bool isBoss();
    int DieRoll(int ds, int dn);
    int StatRoll(int ds, int dn);
    int Attack(Character& c);
    bool ChooseTurn(Character &c, Enemy &e, int a, HANDLE hConsole);
    virtual void Special(Character& c, Enemy& e, int a);

    Enemy();
    ~Enemy();

    friend ostream &operator<<(ostream &output, Enemy &i);
};

class Rat:public Enemy{
public:
    Rat(int i);
    void Special(Character& c, Enemy& e, int a);
};

class Slime:public Enemy{
public:
    Slime(int i);
    void Special(Character& c, Enemy& e, int a);
};

class Skeleton:public Enemy{
public:
    Skeleton(int i);
};

class Goblin:public Enemy{
public:
    Goblin(int i);
};

class Golem:public Enemy{
public:
    Golem(int i);
    void Special(Character& c, Enemy& e, int a);
};

class Kobold:public Enemy{
public:
    Kobold(int i);
    void Special(Character& c, Enemy& e, int a);
};

class Orc:public Enemy{
public:
    Orc(int i);
    void Special(Character& c, Enemy& e, int a);
};

class Boss:public Enemy{
public:
    bool isBoss();
    Boss(int i);
};

#endif // ENEMY_HH_INCLUDED
