#ifndef CHARACTER_HH_INCLUDED
#define CHARACTER_HH_INCLUDED
#include "Main.h"

class Enemy;

class Character{
protected:
    int B, CD, XP, XPC, LVL, ATK, DEF, HEA, DEX, DMGD;
    int ACC, KILLS, BKILLS, junk, BLEED, Fizzle, Buff;
    int HPot, Gold, STUN, Band;
    double CHEA;
    string NAME;
public:
    void setName(string a);
    void setBleed(int n);
    void ChangeATK(int n);
    void ChangeBLEED(int n);
    int ChangeXP(int n);
    void ChangeCD(int n);
    void ChangeBand(int n);
    void ChangeB(bool n);
    void ChangeXPC(int n);
    void ChangeJUNK(int n);
    void ChangeKILLS(int n);
    int ChangeGold(int n);
    void ChangeBKILLS(int n);
    void ChangeBuff(int n);
    void ChangeFizzle(int n);
    void ChangeACC(int n);
    void ChangeDEF(int n);
    void ChangeHEA(int n);
    void ChangeCHEA(double n);
    void ChangeDEX(int n);
    void ChangeDMGD(int n);
    void ChangeHPot(int n);
    void ChangeALL(Character &c);
    void ChangeSTUN(int n);

    int Attack(Enemy &e,int i);
    void Heal(double n);
    void Lvlup(Character &c);
    bool isAlive();
    bool IsBleed();
    bool IsStun();
    bool ChooseTurn(Character &c, Enemy &e, int a, HANDLE hConsole);
    virtual bool ChooseSkill(Character &c, Enemy &e, int a);
    virtual bool isVanguard();

    string getNAME();
    int getCHEA();
    int getBLEED();
    int getXP();
    int getHPot();
    int getGold();
    int getB();
    int getCD();
    int getBand();
    int getXPC();
    int getBuff();
    int getLVL();
    int getKILLS();
    int getBKILLS();
    int getFizzle();
    int getJUNK();
    int getACC();
    double getDEF();
    int getATK();
    int getHEA();
    int getDEX();
    int getDMGD();
    int getSTUN();

    int DieRoll(int ds, int dn);

    Character();
    ~Character();

    friend ostream &operator<<(ostream &output, Character &i);
};

class Gladiator:public Character{
public:

    bool ChooseSkill(Character &c, Enemy &e, int a);
    Gladiator();
};

class Highwayman:public Character{
public:
    bool ChooseSkill(Character &c, Enemy &e, int a);
    Highwayman();
    Highwayman(int);
};

class Vanguard:public Character{
public:
    bool isVanguard();
    bool ChooseSkill(Character &c, Enemy &e, int a);
    Vanguard();
};

class Shit:public Character{
public:
    bool ChooseSkill(Character &c, Enemy &e, int a);
    Shit();
};


#endif // CHARACTER_HH_INCLUDED
