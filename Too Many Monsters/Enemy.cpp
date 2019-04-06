#include "Main.h"
void Enemy::Special(Character& c, Enemy& e, int a){
    int r1 = rand() % (100), r2 = rand() % (100);
    if(r1 < c.getDEX() && r2 > e.getACC())
        cout << "The " << e.getName() << " Missed " << c.getNAME() << endl << endl;
    else
        cout << "The " << e.getName() << " Hit " << c.getNAME() << " For " << e.Attack(c) << " Damage" << endl << endl;
}

Enemy::Enemy(){
    NAME = "DONT";
    ATK = -1;
    DEF = -1;
    DEX = -1;
    ACC = -1;
    HEA = -1;
    BLEED = 0;
    STUN = 0;
    CHEA = HEA;
}

Rat::Rat(int i){
    NAME = "Rat";
    ATK = this->StatRoll(3, i*2);
    DEF = this->StatRoll(3, i*2);
    DEX = this->StatRoll(4, i*2);
    ACC = this->StatRoll(3, i*2);
    HEA = this->StatRoll(2, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

void Rat::Special(Character& c, Enemy& e, int a){
    cout << e.getName() << " Bit " << c.getNAME() << " For " << (a+1)/2 << " Bleed." << endl << endl;
    c.ChangeBLEED((a+1)/2);
}

Slime::Slime(int i){
    NAME = "Slime";
    ATK = this->StatRoll(3, i*2);
    DEF = this->StatRoll(3, i*2);
    DEX = this->StatRoll(2, i*2);
    ACC = this->StatRoll(3, i*2);
    HEA = this->StatRoll(4, i*2)*10;
    CHEA = HEA;
    DMGD = 4;
}

void Slime::Special(Character& c, Enemy& e, int a){
    cout << e.getName() << " Regained " << a*5 << " Health." << endl << endl;
    e.ChangeCHEA(a*5);
    if(e.getCHEA() > e.getHEA())
        e.setCHEA(e.getHEA());
}

Skeleton::Skeleton(int i){
    NAME = "Skeleton";
    ATK = this->StatRoll(4, i*2);
    DEF = this->StatRoll(2, i*2);
    DEX = this->StatRoll(3, i*2);
    ACC = this->StatRoll(3, i*2);
    HEA = this->StatRoll(3, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

Goblin::Goblin(int i){
    NAME = "Goblin";
    ATK = this->StatRoll(3, i*2);
    DEF = this->StatRoll(3, i*2);
    DEX = this->StatRoll(3, i*2);
    ACC = this->StatRoll(3, i*2);
    HEA = this->StatRoll(3, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

Golem::Golem(int i){
    NAME = "Golem";
    ATK = this->StatRoll(2, i*2);
    DEF = this->StatRoll(5, i*2);
    DEX = this->StatRoll(3, i*2);
    ACC = this->StatRoll(2, i*2);
    HEA = this->StatRoll(3, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

void Golem::Special(Character& c, Enemy& e, int a){
    cout << e.getName() << " Bashed " << c.getNAME() << " And Has Been Stunned For " << (a+1)/2 << " Turns." << endl << endl;
    c.ChangeSTUN((a+1)/2);
}

Kobold::Kobold(int i){
    NAME = "Kobold";
    ATK = this->StatRoll(2, i*2);
    DEF = this->StatRoll(2, i*2);
    DEX = this->StatRoll(5, i*2);
    ACC = this->StatRoll(4, i*2);
    HEA = this->StatRoll(2, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

void Kobold::Special(Character& c, Enemy& e, int a){
    cout << e.getName() << " Started Moving Faster." << endl << endl;
    e.ChangeDEX((a+1)/2);
}

Orc::Orc(int i){
    NAME = "Orc";
    ATK = this->StatRoll(5, i*2);
    DEF = this->StatRoll(2, i*2);
    DEX = this->StatRoll(2, i*2);
    ACC = this->StatRoll(2, i*2);
    HEA = this->StatRoll(4, i*2)*10;
    CHEA = HEA;
    DMGD = 6;
}

void Orc::Special(Character& c, Enemy& e, int a){
    cout << e.getName() << " Started Flexing." << endl << endl;
    e.ChangeATK((a+1)/2);
}

Boss::Boss(int i){
    if(i == 1){
        NAME = "Big Rat";
        ATK = 13;
        DEF = 12;
        DEX = 20;
        ACC = 50;
        HEA = 100;
        CHEA = HEA;
        DMGD = 8;
    }
    else if(i == 2){
        NAME = "Bigger Rat";
        ATK = 23;
        DEF = 18;
        DEX = 35;
        ACC = 60;
        HEA = 150;
        CHEA = HEA;
        DMGD = 12;
    }
    else if(i == 3){
        NAME = "Biggest Rat";
        ATK = 35;
        DEF = 30;
        DEX = 50;
        ACC = 60;
        HEA = 150;
        CHEA = HEA;
        DMGD = 12;
    }
    else if(i == 4){
        NAME = "Slimy Slime";
        ATK = 41;
        DEF = 41;
        DEX = 10;
        ACC = 40;
        HEA = 400;
        CHEA = HEA;
        DMGD = 8;
    }
    else if(i == 5){
        NAME = "THE WALL";
        ATK = 1;
        DEF = 147;
        DEX = 0;
        ACC = 100;
        HEA = 5;
        CHEA = HEA;
        DMGD = 10;
    }
    else if(i == 6){
        NAME = "Momma Slime";
        ATK = 52;
        DEF = 53;
        DEX = 1;
        ACC = 90;
        HEA = 1000;
        CHEA = HEA;
        DMGD = 10;
    }
    else if(i == 7){
        NAME = "Skeletor";
        ATK = 80;
        DEF = 0;
        DEX = 80;
        ACC = 70;
        HEA = 20;
        CHEA = HEA;
        DMGD = 20;
    }
    else if(i == 8){
        NAME = "Mr. Bones";
        ATK = 100;
        DEF = 0;
        DEX = 90;
        ACC = 80;
        HEA = 40;
        CHEA = HEA;
        DMGD = 30;
    }
    else if(i == 9){
        NAME = "Just a Goblin";
        ATK = 60;
        DEF = 32;
        DEX = 95;
        ACC = 90;
        HEA = 40;
        CHEA = HEA;
        DMGD = 100;
    }
}


Enemy::~Enemy(){
}

bool Boss::isBoss(){
    return true;
}

bool Enemy::isBoss(){
    return false;
}

void Enemy::setName(string n){
    NAME = n;
}

void Enemy::setATK(int n){
    ATK = n;
}

void Enemy::setSTUN(int n){
    STUN = n;
}

void Enemy::setDEF(int n){
    DEF = n;
}

void Enemy::setHEA(int n){
    HEA = n;
}

void Enemy::setCHEA(int n){
    CHEA = n;
}

void Enemy::setDEX(int n){
    DEX = n;
}

string Enemy::getName(){
    return NAME;
}

void Enemy::ChangeATK(int n){
    ATK += n;
}

void Enemy::ChangeSTUN(int n){
    STUN += n;
}

void Enemy::ChangeDEF(int n){
    DEF += n;
}

void Enemy::ChangeHEA(int n){
    HEA += n;
}

void Enemy::ChangeCHEA(double n){
    CHEA += n;
}

void Enemy::ChangeDEX(int n){
    DEX += n;
}

void Enemy::ChangeACC(int n){
    ACC += n;
}

void Enemy::ChangeBLEED(int n){
    BLEED += n;
}

void Enemy::ChangeDMGD(int n){
    DMGD = n;
}

bool Enemy::isAlive(){
    bool Status;
    if(CHEA > 0)
        Status = true;
    else
        Status = false;
return Status;
}

bool Enemy::IsBleed(){
    bool Status;
    if(BLEED > 0)
        Status = true;
    else
        Status = false;
return Status;
}

bool Enemy::IsStun(){
    bool Status;
    if(STUN > 0)
        Status = true;
    else
        Status = false;
return Status;
}

int Enemy::Attack(Character& c){
    int Total = DieRoll(DMGD, 2);
    Total += Total * log((pow(ATK*.01,2)*6.42)+1);
    Total -= Total * c.getDEF();
    c.ChangeCHEA(-Total);
    return Total;
}

bool Enemy::ChooseTurn(Character &c, Enemy &e, int a, HANDLE hConsole){
    if(e.IsStun()){
        cout << e.getName() << " Is Stunned And Does Nothing" << endl << endl;
        ChangeSTUN(-1);
        return true;
    }
    int r = rand() % 100 + 1;
    if(r > 20){
        int r1 = rand() % (100), r2 = rand() % (100);

        SetConsoleTextAttribute(hConsole, 12);
        if(r1 < c.getDEX() && r2 > e.getACC())
            cout << "The " << e.getName() << " Missed " << c.getNAME() << endl << endl;
        else
            cout << "The " << e.getName() << " Hit " << c.getNAME() << " For " << e.Attack(c) << " Damage" << endl << endl;
        }
    else{
    SetConsoleTextAttribute(hConsole, 12);
         e.Special(c, e, a);
    }

    SetConsoleTextAttribute(hConsole, 11);

return true;
}

int Enemy::getHEA(){
    return HEA;
}

int Enemy::getCHEA(){
    return CHEA;
}

int Enemy::getDEX(){
    return DEX;
}

int Enemy::getATK(){
    return ATK;
}

int Enemy::getACC(){
    return ACC;
}

double Enemy::getDEF(){
    return (1 + pow((((DEF * .01)/4)-1),5));
}

int Enemy::getBLEED(){
    return BLEED;
}

int Enemy::getSTUN(){
    return STUN;
}

int Enemy::DieRoll(int ds,int dn){
    int Total = 0;
    for(; dn > 0; --dn)
        Total += rand() % ((ds+1)-1) + 1;
    return Total;
}

int Enemy::StatRoll(int ds,int dn){
    int Total = 0;

    for(;dn > 1; --dn)
        Total += ds;

    Total += rand() % ds + 1;

    return Total;
}

ostream &operator<<(ostream &output, Enemy &i){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);

    output << left << setw(12) << "Name: " << i.NAME << " ";
    SetConsoleTextAttribute(hConsole, 12);
    int BLD = i.getBLEED();
    while(BLD > 0){
        if(BLD >= 10){
            cout << "X";
            BLD -= 10;
        }
        else if(BLD == 9){
            cout << "IX";
            BLD -= 9;
        }
        else if(BLD >= 5){
            cout << "V";
            BLD -= 5;
        }
        else if(BLD == 4){
            cout << "IV";
            BLD -= 4;
        }
        else if(BLD < 4){
            cout << "I";
            BLD--;
        }
    }

    SetConsoleTextAttribute(hConsole, 14);
    int STN = i.getSTUN();
    if(STN){
        cout << " ";
        while(STN > 0){
            if(STN >= 10){
                cout << "X";
                STN -= 10;
            }
            else if(STN == 9){
                cout << "IX";
                STN -= 9;
            }
            else if(STN >= 5){
                cout << "V";
                STN -= 5;
            }
            else if(STN == 4){
                cout << "IV";
                STN -= 4;
            }
            else if(STN < 4){
                cout << "I";
                STN--;
            }
        }
    }

    SetConsoleTextAttribute(hConsole, 12);

    cout << endl << setw(12) << "Health: " <<  i.CHEA << "/" << i.HEA
    << endl << setw(12) << "Attack: " << i.ATK
    << endl << setw(12) << "Defense: " << i.DEF
    << endl << setw(12) << "Accuracy: " << i.ACC << "%"
    << endl << setw(12) << "Dodge: " << i.DEX  << "%" << endl;

    SetConsoleTextAttribute(hConsole, 11);
    return output;
}
