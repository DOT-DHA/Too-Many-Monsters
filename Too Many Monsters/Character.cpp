#include "Main.h"


Character::Character(){
    XP = 0;
    XPC = 100;
    LVL = 0;
    ATK = -1;
    DEF = -1;
    DEX = -1;
    HEA = -1;
    DMGD = -1;
    ACC = -1;
    KILLS = 0;
    BKILLS = 0;
    BLEED = 0;
    junk = 0;
    Fizzle = 70;
    CD = 0;
    Buff = 0;
    B = 0;
    Gold = 10;
    HPot = 5;
    Band = 5;
    STUN = 0;
    CHEA = HEA;
}

Highwayman::Highwayman(){
    ATK = 8;
    DEF = 4;
    DEX = 7;
    DMGD = 6;
    ACC = 20;
    HEA = 40;
    junk = 3;
    CHEA = HEA;
}

Highwayman::Highwayman(int n){
    ATK = 10000;
    DEF = 100;
    DEX = 100;
    DMGD = 100;
    ACC = 100;
    HEA = 10000;
    junk = 69;
    LVL = 1337;
    KILLS = 45;
    BKILLS = 0;
    CHEA = HEA;
}

Gladiator::Gladiator(){
    ATK = 6;
    DEF = 6;
    DEX = 4;
    DMGD = 6;
    ACC = 14;
    HEA = 50;
    junk = 0;
    CHEA = HEA;
}

Vanguard::Vanguard(){
    ATK = 2;
    DEF = 8;
    DEX = 1;
    DMGD = 6;
    ACC = 7;
    HEA = 60;
    junk = 0;
    CHEA = HEA;
}

Shit::Shit(){
    ATK = 1;
    DEF = 1;
    DEX = 25;
    DMGD = 6;
    ACC = 1;
    HEA = 30;
    junk = 15;
    CHEA = HEA;
}

Character::~Character(){
}

void Character::setName(string n){
    NAME = n;
}

void Character::setBleed(int n){
    BLEED = n;
}

void Character::ChangeATK(int n){
    ATK += n;
}

void Character::ChangeACC(int n){
    ACC += n;
    if(ACC > 90)
        ACC = 90;
}

void Character::ChangeJUNK(int n){
    junk += n;
}

void Character::ChangeHPot(int n){
    HPot += n;
}

void Character::ChangeBand(int n){
    Band += n;
}

void Character::ChangeKILLS(int n){
    KILLS += n;
}

void Character::ChangeBKILLS(int n){
    BKILLS += n;
}

int Character::ChangeGold(int n){
    Gold += n;
    return n;
}

void Character::ChangeDEF(int n){
    DEF += n;
    if(DEF > 100){
        DEF = 100;
        cout << "Defense At Maximum" << endl << endl;
    }
}

void Character::ChangeB(bool n){
    B = n;
}

void Character::ChangeHEA(int n){
    HEA += n;
    if(HEA <= 30){
        HEA = 30;
        cout << "Health At Minimum" << endl;
    }
}

void Character::ChangeBuff(int n){
    Buff += n;
}

void Character::ChangeSTUN(int n){
    STUN += n;
}

int Character::getBuff(){
    return Buff;
}

void Character::ChangeCHEA(double n){
    CHEA += n;
    if(CHEA > HEA)
        CHEA = HEA;
}

void Character::ChangeCD(int n){
    CD += n;
}

void Character::ChangeFizzle(int n){
    Fizzle += n;
    if(Fizzle > 100)
        Fizzle = 100;
}

int Character::ChangeXP(int n){
    int Total = 0;
    if(n > 0){
        for(;n/5 > 1;n--)
            Total += n*20;
        Total += DieRoll(12,n);
        XP += Total;
        return Total;
    }
    else{
        XP += n;
        if(XP < 0)
            XP = 0;
    }
}

void Character::ChangeXPC(int n){
    XPC += n;
}

void Character::ChangeBLEED(int n){
    BLEED += n;
}

void Character::ChangeDEX(int n){
    DEX += n;
    if(DEX > 90)
        DEX = 90;
}

void Character::ChangeDMGD(int n){
    DMGD = n;
}

void Character::ChangeALL(Character &c){
    c.ChangeATK(DieRoll(8,1));
    c.ChangeDEX(DieRoll(4,1));
    c.ChangeACC(DieRoll(4,1));
    c.ChangeHEA(DieRoll(6,1));
    c.ChangeDEF(DieRoll(6,2));
}

int Character::getDMGD(){
    return DMGD;
}

int Character::getFizzle(){
    return Fizzle;
}

int Character::getBLEED(){
    return BLEED;
}

int Character::getJUNK(){
    return junk;
}

int Character::getKILLS(){
    return KILLS;
}

int Character::getBKILLS(){
    return BKILLS;
}

int Character::getDEX(){
    return DEX;
}

int Character::getBand(){
    return Band;
}

int Character::getHPot(){
    return HPot;
}

int Character::getGold(){
    return Gold;
}

int Character::getB(){
    return B;
}

int Character::getACC(){
    return ACC;
}

int Character::getSTUN(){
    return STUN;
}

bool Character::isAlive(){
    bool Status;
    if(CHEA > 0)
        Status = true;
    else
        Status = false;
return Status;
}

bool Character::IsStun(){
    bool Status;
    if(STUN > 0)
        Status = true;
    else
        Status = false;
return Status;
}

bool Character::isVanguard(){
    return false;
}

bool Character::IsBleed(){
    bool Status;
    if(BLEED > 0)
        Status = true;
    else
        Status = false;
return Status;
}

int Character::Attack(Enemy &e, int i = 2){
    int Total = DieRoll(DMGD, i);
    Total += Total * log((pow(ATK*.01,2)*6.42)+1);
    Total -= Total * e.getDEF();
    e.ChangeCHEA(-Total);
    return Total;
}

bool Character::ChooseTurn(Character &c, Enemy &e, int a, HANDLE hConsole){
    if(c.IsStun()){
        cout << c.getNAME() << " Is Stunned And Does Nothing" << endl << endl << c << endl << e << endl;
        ChangeSTUN(-1);
        return true;
    }
    bool n = false;
    char i;
        while(!n){
            system("CLS");
            cout << c << endl << e << endl;
            cout << "What Would You Like To Do?" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cout << "1: Try To Run Away" << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "2: Attack " << e.getName() << endl;
            if(c.getCD() == 0){
                SetConsoleTextAttribute(hConsole, 10);
                cout << "3: Skills " << endl;
            }
            else{
                SetConsoleTextAttribute(hConsole, 8);
                cout << "3: Skills (" << c.getCD() << ") Turns on Cool Down" << endl;
            }
            SetConsoleTextAttribute(hConsole, 3);
            cout << "4: Items " << endl;

            SetConsoleTextAttribute(hConsole, 11);
            i = getch();
            system("CLS");

            if(i == '1'){
                int r = (rand() & 100)+1;
                if(r < c.getDEX()+10){
                    Heal(INT_MAX);
                cout << c.getNAME() << " Successfully Ran Away" << endl << endl << c << endl;;
                    return false;
                }
                else{
                    cout << c.getNAME() << " Failed To Run Away" << endl << endl << c << endl << e << endl;
                    n = true;
                }
            }

            else if(i == '2'){

                int r = (rand() & 100)+1, r2 = (rand() & 100)+1;

                SetConsoleTextAttribute(hConsole, 10);

                if(r < e.getDEX() && r2 > c.getACC())
                    cout << c.getNAME() << " Missed The " << e.getName() << endl << endl;
                else
                    cout << c.getNAME() << " Stabbed The " << e.getName() << " For " << c.Attack(e) << " Damage" << endl << endl;

                cout << c << endl << e << endl;
                n = true;
            }
            else if(i == '3' && c.getCD() == 0){
                n = c.ChooseSkill(c,e,a);
                cout << c << endl << e << endl;
            }

            else if(i == '4'){
                cout << "Which Item would you like to use?" << endl
                << "1: Back" << endl;
                if(c.getCHEA() == c.getHEA())
                    cout << "2: Not Damaged" << endl;
                else if(c.getHPot() > 0)
                    cout << "2: Health Potion" << endl;
                else
                    cout << "2: No Health Potions" << endl;
                if (c.getBLEED() == 0)
                    cout << "3: Not Bleeding" << endl;
                else if(c.getBand() > 0)
                    cout << "3: Bandages" << endl;
                else
                    cout << "3: No Bandages" << endl;
                char i = getch();
                system("CLS");

                if(i == '2' && c.getHPot() > 0 && (c.getCHEA()<c.getHEA())){
                        int H = c.getHEA()/4;
                        c.ChangeCHEA(H);
                        cout << "Healed for " << H << " HP" << endl << c << endl << e << endl << endl;
                        c.ChangeHPot(-1);
                        n = true;
                }

                if(i == '3' && c.getBand() > 0 && c.IsBleed()){
                        c.setBleed(0);
                        cout << "Removed Bleed" << endl << c << endl << e << endl << endl;
                        c.ChangeBand(-1);
                        n = true;
                }
            }
            SetConsoleTextAttribute(hConsole, 11);

}
return true;
}

bool Character::ChooseSkill(Character &c, Enemy &e, int a){
    return true;
}

bool Highwayman::ChooseSkill(Character &c, Enemy &e, int a){
    char Input;
    int i = 0;
    while(!i){
        cout << "1: Back" << endl;
        if(c.getLVL() >= 1)
            cout << "2: Deep Cut Bleed For 5 (Cool Down 2)" << endl;
        else
            cout << "2: Unlocks At Level 1" << endl;
        if(c.getLVL() >= 2)
            cout << "3: Pistol Shot (Cool Down 5)" << endl;
        else
            cout << "3: Unlocks At Level 2" << endl;
        Input = getch();
        system("CLS");
        if(Input =='1')
            return false;
        if(Input=='2' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                cout << c.getNAME() << "'s Deep Cut Applied 5 Bleed" << endl << endl;
                e.ChangeBLEED(5);
                c.ChangeCD(3);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }
        if(Input=='3' && c.getLVL() >= 2){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                ChangeDMGD(12);
                cout << c.getNAME() << "'s Pistol Shot " << e.getName() << " For " << Attack(e) << endl << endl;
                ChangeDMGD(8);
                c.ChangeCD(5);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }
    }
    return false;
}

bool Gladiator::ChooseSkill(Character &c, Enemy &e, int a){
    char Input;
    int i = 0;
    while(!i){
        cout << "1: Back" << endl;
        if(c.getLVL() >= 1)
            cout << "2: Power Attack +50% Attack (Cool Down 2)" << endl;
        else
            cout << "2: Unlocks At First Level" << endl;
        if(c.getLVL() >= 2)
            cout << "3: Double Strike (Cool Down 4)" << endl;
        else
            cout << "3: Unlocks At Second Level" << endl;
        Input = getch();
        system("CLS");
        if(Input == '1')
            return false;
        if(Input=='2' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                int n = ATK/2;
                c.ChangeATK(n);
                cout << c.getNAME() << " Struck " << e.getName() << " With Power For " << Attack(e) << " Damage" << endl << endl;
                c.ChangeATK(-n);
                c.ChangeCD(3);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }

        if(Input=='3' && c.getLVL() >= 2){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                cout << c.getNAME() << " Struck " << e.getName() << " Twice For " << Attack(e) + Attack(e) << " Damage" << endl << endl;
                c.ChangeCD(4);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }
    }
    return false;
}

bool Vanguard::ChooseSkill(Character &c, Enemy &e, int a){
    char Input;
    int i = 0;
    while(!i){
        cout << "1: Back" << endl;
        if(c.getLVL() >= 1)
            cout << "2: Guard Up +10 DEF (Cool Down 2)" << endl;
        else
            cout << "2: Unlocks At First Level" << endl;
        if(c.getLVL() >= 2)
            cout << "3: Shield Bash Stun For 5 Turns (Cool Down 3)" << endl;
        else
            cout << "3: Unlocks At Second Level" << endl;
        Input = getch();
        system("CLS");
        if(Input == '1')
            return false;
        if(Input=='2' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                cout << "Increased Defense By 10" << endl << endl;
                c.ChangeBuff(2);
                c.ChangeDEF(10);
                c.ChangeCD(3);
                c.ChangeB(true);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }

        if(Input=='3' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                cout << e.getName() << " Has Been Bashed And Stunned" << endl << endl;
                e.ChangeSTUN(3);
                c.ChangeCD(5);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }
    }
    return false;
}

bool Shit::ChooseSkill(Character &c, Enemy &e, int a){
    char Input;
    int i = 0;
    while(!i){
        cout << "1: Back" << endl;
        if(c.getLVL() >= 1)
            cout << "2: Collect 1-12 Junk (Cool Down 1)" << endl;
        else
            cout << "2: Unlocks At Second Level" << endl;

        if(c.getLVL() >= 2)
            cout << "3: Throw Junk (Cool Down 2)" << endl;
        else
            cout << "3: Unlocks At First Level" << endl;
        Input = getch();
        system("CLS");
        if(Input =='1')
            return false;

        if(Input=='2' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                int n = (rand()% 12)+1;
                cout << c.getNAME() << " Found " << n << " Junk" << endl << endl;
                c.ChangeJUNK(n);
                c.ChangeCD(2);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }

        if(Input=='3' && c.getLVL() >= 1){
            int r = (rand() % 100)+1;
            if(r < c.getFizzle()){
                int n = (rand()%c.getJUNK())+1;
                cout << c.getNAME() <<" Threw Junk For " << n << " Damage" << endl << endl;
                e.ChangeCHEA(-n);
                c.ChangeCD(3);
                return true;
            }
            else{
                cout << "Skill Failed" << endl << endl;
                c.ChangeCD(2);
                return true;
            }
        }
    }
    return false;
}

bool Vanguard::isVanguard(){
    return true;
}

void Character::Heal(double n){
    CHEA += n;
    if(CHEA > HEA)
        CHEA = HEA;
    STUN = 0;
    BLEED = 0;
}

void Character::Lvlup(Character &c){
    while(XP >= XPC){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
        cout << NAME << " Has Leveled Up!" << endl << endl;
        LVL +=  1;
        XPC += LVL * 100;
        c.ChangeALL(c);
        c.ChangeFizzle(3);
        SetConsoleTextAttribute(hConsole, 11);
    }
}

int Character::getCHEA(){
    return CHEA;
}

int Character::getXP(){
    return XP;
}

int Character::getCD(){
    return CD;
}

int Character::getXPC(){
    return XPC;
}

int Character::getLVL(){
    return LVL;
}

string Character::getNAME(){
    return NAME;
}

int Character::getHEA(){
    return HEA;
}

int Character::getATK(){
    return ATK;
}


double Character::getDEF(){
    return (1 + pow((((DEF * .01)/4)-1),5));
}

int Character::DieRoll(int ds,int dn){
    int Total = 0;
    for(; dn > 0; --dn)
        Total += rand() % (ds) + 1;
    return Total;
}

ostream &operator<<(ostream &output, Character &i){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);

    output << left << setw(12) << "Name: " << i.NAME;
    SetConsoleTextAttribute(hConsole, 12);
    int BLD = i.getBLEED();
    if(BLD){
        cout << " ";
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

    SetConsoleTextAttribute(hConsole, 2);
    cout << endl << setw(12) << "Health:" <<  i.CHEA << "/" << i.HEA
    << endl << setw(12) << "Attack:" << i.ATK
    << endl << setw(12) << "Defense:" << i.DEF
    << endl << setw(12) << "Dodge:" << i.DEX  << "%"
    << endl << setw(12) << "Accuracy:" << i.ACC << "%"
    << endl << setw(12) << "HPot/Band: " << i.HPot << "/" << i.Band << endl;
    SetConsoleTextAttribute(hConsole, 11);
    return output;
}
