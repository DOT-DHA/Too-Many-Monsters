#include "main.h"

void Start_Game();
void Starting_Quest(Character &c);
void Combat(Character &c, Enemy &e, int a);
void PotionDrops(Character &c, int n);
void Bleed(Character& c);
void Bleed(Enemy& e);
int DieRoll(int ds, int dn);
bool DeadEnemy(Character& c, Enemy& e, int a);
bool DeadCharacter(Character& c, int a);

HANDLE hConsole;


int main(){

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(nullptr));

    Start_Game();

    system("CLS");

    return 0;
}

void Starting_Quest(Character& c){
    int Area = 1;

    while(true){
        if(c.getBKILLS()>=9){
        SetConsoleTextAttribute(hConsole, 15);
            cout << "you win" << endl << endl;
            exit(69);
        }
        char Input;
        cout << c;
        SetConsoleTextAttribute(hConsole, 14);
        cout << setw(12) << "Level:" << c.getLVL()
        << endl << setw(12) << "EXP:" <<  c.getXP() << "/" << c.getXPC()
        << endl << setw(12) << "GOLD:" << c.getGold() << " G" << endl;
        SetConsoleTextAttribute(hConsole, 11);

        cout << endl << "What would you like to do? " << endl
        << "1: Explore Area " << Area << endl;
        if(c.getBKILLS() >= Area)
            cout << "2: Next Area" << endl;
        else if(c.getKILLS() >= Area * 5){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "2: Fight Boss" << endl;
        }
        else if(c.getKILLS() < Area * 5){
            SetConsoleTextAttribute(hConsole, 8);
            cout << "2: (" << c.getKILLS() % 5 << "/" << 5 << " Monsters Killed)" << endl;
        }
        SetConsoleTextAttribute(hConsole, 11);
        if(Area > 1)
            cout << "3: Previous Area" << endl;
        SetConsoleTextAttribute(hConsole, 14);
        cout << "S: Visit Shop" << endl;
        SetConsoleTextAttribute(hConsole, 11);
        Input = getch();


        if(Input == '1'){
            system("CLS");
                int r = rand() % (7)+1;
                int T = rand() % (100)+1;

            if(T > 90){
                system("CLS");
                SetConsoleTextAttribute(hConsole, 10);
                cout << "You Find A Crate And Break It Open" << endl << endl << endl;
                PotionDrops(c, Area+6);
                SetConsoleTextAttribute(hConsole, 11);
                system("PAUSE|Echo Continue...");
                c.Heal(INT_MAX);
            }
            else if(r == 1){
                system("CLS");
                Rat ENEMY(Area);
                Combat(c, ENEMY, Area);
            }
            else if(r == 2){
                system("CLS");
                Slime ENEMY(Area);
                Combat(c, ENEMY, Area);
            }
            else if(r == 3){
                system("CLS");
                Skeleton ENEMY(Area);
                Combat(c, ENEMY, Area);
            }
            else if(r == 4){
                system("CLS");
                Goblin ENEMY(Area);
                Combat(c, ENEMY, Area);
            }
            else if(r == 5){
                system("CLS");
                Golem ENEMY(Area);
                Combat(c, ENEMY, Area);
            }
            else if(r == 6){
                system("CLS");
                Kobold ENEMY(Area);
                Combat(c, ENEMY, Area);
            }

            else if(r == 7){
                system("CLS");
                Orc ENEMY(Area);
                Combat(c, ENEMY, Area);
            }

        }
        else if(Input == '2' && c.getKILLS() >= Area * 5){
                system("CLS");
                if (c.getBKILLS() < Area){
                    Boss ENEMY(Area);
                    Combat(c,ENEMY, Area);
                }
                else
                    Area += 1;
        }
        else if(Input == '3' && Area > 1){
                Area -= 1;
        }
        else if(Input == 'j' || Input == 'J'){
                system("CLS");
                SetConsoleTextAttribute(hConsole, 6);
                cout << "For Some Reason " << c.getNAME() << " Is Carrying " << c.getJUNK() << " Pieces Of Junk" << endl << endl;
                SetConsoleTextAttribute(hConsole, 11);
                system("PAUSE|Echo Continue...");
        }
        else if(Input == 's' || Input == 'S'){
                system("CLS");
                cout << "Welcome To My Shop!" << endl
                << "1: Health Potion (25% Heal) " << (c.getBKILLS()+1)*20 << " G" << endl
                << "2: Bandages (Removes Bleed) " << (c.getBKILLS()+1)*10 << " G" << endl
                << "3: Health Potion x 10 (25% Heal) " << (c.getBKILLS()+1)*200 << " G" << endl
                << "4: Bandages x 10 (Removes Bleed) " << (c.getBKILLS()+1)*100 << " G" << endl;
                char i = getch();

                if(i == '1'){
                    if(c.getGold() >= (c.getBKILLS()+1)*20){
                        c.ChangeHPot(1);
                        c.ChangeGold(-(c.getBKILLS()+1)*20);
                        system("CLS");
                        cout << "A Health Potion Has been Bought" << endl << endl;
                    }
                    else{
                        system("CLS");
                        cout << "Not Enough Gold" << endl << endl;
                    }
                }

                if(i == '2'){
                    if(c.getGold() >= (c.getBKILLS()+1)*10){
                        c.ChangeBand(1);
                        c.ChangeGold(-(c.getBKILLS()+1)*10);
                        system("CLS");
                        cout << "Some Bandages Have been Bought" << endl << endl;
                    }
                    else{
                        system("CLS");
                        cout << "Not Enough Gold" << endl << endl;
                    }
                }

                else if(i == '3'){
                    if(c.getGold() >= (c.getBKILLS()+1)*200){
                        c.ChangeHPot(10);
                        c.ChangeGold(-(c.getBKILLS()+1)*200);
                        system("CLS");
                        cout << "10 Health Potions Have been Bought" << endl << endl;
                    }
                    else{
                        system("CLS");
                        cout << "Not Enough Gold" << endl << endl;
                    }
                }

                else if(i == '4'){
                    if(c.getGold() >= (c.getBKILLS()+1)*100){
                        c.ChangeBand(10);
                        c.ChangeGold(-(c.getBKILLS()+1)*100);
                        system("CLS");
                        cout << "10 Bandages Have been Bought" << endl << endl;
                    }
                    else{
                        system("CLS");
                        cout << "Not Enough Gold" << endl << endl;
                    }
                }
                system("PAUSE|Echo Continue...");
        }
    system("CLS");
    }
}

void Combat(Character& c, Enemy &e, int a){
        for(int j = 0; !j;){
            if(c.getCD()>0)
                c.ChangeCD(-1);
            if(c.getBuff()>0)
                c.ChangeBuff(-1);


            bool n = c.ChooseTurn(c, e, a, hConsole);
            if(n == false)
                break;

            if(DeadEnemy(c,e,a)){
                ++j;
                break;
            }

            system("PAUSE|Echo Continue...");
            system("CLS");

            if(c.IsBleed()){
                Bleed(c);
                cout << c << endl << e << endl;
                system("PAUSE|Echo Continue...");
                system("CLS");
            }

            e.ChooseTurn(c, e, a, hConsole);

            if(DeadCharacter(c, a)){
                ++j;
                break;
            }

            cout << c << endl << e << endl;
            system("PAUSE|Echo Continue...");
            system("CLS");

             if(e.IsBleed()){
                Bleed(e);
                cout << c << endl << e << endl;
                system("PAUSE|Echo Continue...");
                system("CLS");
            }

            if(DeadEnemy(c,e,a)){
                ++j;
                break;
            }

            if(c.getBuff() == 0 && c.isVanguard() && c.getB()){
                c.ChangeDEF(-10);
                c.ChangeB(false);
            }
        }
        while(c.getCD())
            c.ChangeCD(-1);

    system("PAUSE|Echo Continue...");
    system("CLS");
}

bool DeadCharacter(Character& c, int a){
    if(!c.isAlive()){
        cout << c.getNAME() << " Died And Lost " << a*20 << " XP." << endl << endl;
        c.ChangeXP(-a*20);
        c.Heal(INT_MAX);
        return true;
    }
return false;
}

bool DeadEnemy(Character& c, Enemy& e, int a){
    if(!e.isAlive()){
        system("CLS");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "The " << e.getName() << " Is DEAD." << endl << endl;
        SetConsoleTextAttribute(hConsole, 11);
        if(e.isBoss()){
            c.ChangeBKILLS(1);
            SetConsoleTextAttribute(hConsole, 14);
            cout << c.getNAME() << " Has Earned " << c.ChangeXP((a+2)*5) << " XP" << endl << endl;
            SetConsoleTextAttribute(hConsole, 11);
            c.Lvlup(c);
            cout << c.getNAME() << " Has Found " << c.ChangeGold(DieRoll(10,(a+2)*3)) << " Gold" << endl << endl;
        }

        else{
            SetConsoleTextAttribute(hConsole, 14);
            cout << c.getNAME() << " Has Earned " << c.ChangeXP(a*5) << " XP" << endl << endl;
            SetConsoleTextAttribute(hConsole, 11);
            c.Lvlup(c);
            cout << c.getNAME() << " Has Found " << c.ChangeGold(DieRoll(10,(a+2)*3)) << " Gold" << endl << endl;
        }

        if(c.getKILLS() < a*5)
            c.ChangeKILLS(1);

        cout << c.getNAME() << " Takes Some Time To Heal." << endl << endl;
        c.Heal(INT_MAX);
        return true;
        }
return false;
}

void Bleed(Character& c){
    cout << c.getNAME() << " Bleeds out for " << c.getBLEED() << " Damage" << endl << endl;
    c.ChangeCHEA(-c.getBLEED());
    c.ChangeBLEED(-1);
}

void Bleed(Enemy& e){
    cout << e.getName() << " Bleeds out for " << e.getBLEED() << " Damage" << endl << endl;
    e.ChangeCHEA(-e.getBLEED());
    e.ChangeBLEED(-1);
}

void PotionDrops(Character& c, int n){
    for(;n>0;--n){
         int r = rand() % 30;

        if(r >= 0 && r <= 2){
            cout << c.getNAME() << left << setw(33) << " Found A Lesser Health Potion." << " +10 Max HP" << endl << endl;
            c.ChangeHEA(10);
        }
        else if(r >= 3 && r <= 5){
            cout << c.getNAME() << left << setw(33) << " Found A Lesser Strength Potion." << " +1 ATK" << endl << endl;
            c.ChangeATK(1);
        }
        else if(r >= 6 && r <= 8){
            cout << c.getNAME() << left << setw(33) << " Found A Lesser Defense Potion." << " +1 Def" << endl << endl;
            c.ChangeDEF(1);
        }

        else if(r >= 9 && r <= 10){
            cout << c.getNAME() << left << setw(33) << " Found A Health Potion." << " +20 Max HP" << endl << endl;
            c.ChangeHEA(20);
        }
        else if(r >= 11 && r <= 12){
            cout << c.getNAME() << left << setw(33) << " Found A Strength Potion." << " +2 ATK" << endl << endl;
            c.ChangeATK(2);
        }
        else if(r >= 13 && r <= 14){
            cout << c.getNAME() << left << setw(33) << " Found A Defense Potion." << " +2 Def" << endl << endl;
            c.ChangeDEF(2);
        }

        else if(r == 15){
            cout << c.getNAME() << left << setw(33) << " Found A Greater Health Potion." << " +50 Max HP!" << endl << endl;
            c.ChangeHEA(50);
        }
        else if(r == 16){
            cout << c.getNAME() << left << setw(33) << " Found A Greater Strength Potion." << " +5 ATK!" << endl << endl;
            c.ChangeATK(5);
        }
        else if(r == 17){
            cout << c.getNAME() << left << setw(33) << " Found A Greater Defense Potion." << " +5 Def!" << endl << endl;
            c.ChangeDEF(5);
        }
        else if (r >= 18 && r <= 29){
            cout << c.getNAME() << " Found Some Junk" << endl <<endl;
            c.ChangeJUNK(1);
        }
        else if (r == 30){
            cout << c.getNAME() << " Found Loads Of Junk" << endl <<endl;
            c.ChangeJUNK(5);
        }
    }
}

void Start_Game(){
    char i;
    while(!kbhit()){
        system("CLS");
        SetConsoleTextAttribute(hConsole, 11);
        cout << "What Are You?" << endl <<
        "1: Highwayman" << endl <<
        "2: Gladiator" << endl <<
        "3: Vanguard" << endl <<
        "4: Garbage" << endl <<
        "R: Random" << endl;
        i = getch();

        if(i == 'R' || i == 'r'){
                int r = (rand() % 4)+1;
                if(r == 1)
                    i = '1';
                if(r == 2)
                    i = '2';
                if(r == 3)
                    i = '3';
                if(r == 4)
                    i = '4';
        }
        if(i == '1'){
            Highwayman PLAYER;
            system("CLS");

            string Input;
            cout << "What Is Your Name Traveler?" << endl;
            getline(cin,Input);
            PLAYER.setName(Input);
            system("CLS");

            Starting_Quest(PLAYER);
        }
        else if(i == '2'){
            Gladiator PLAYER;
            system("CLS");

            string Input;
            cout << "What Is Your Name Traveler?" << endl;
            getline(cin,Input);
            PLAYER.setName(Input);
            system("CLS");

            Starting_Quest(PLAYER);
        }
        else if(i == '3'){
            Vanguard PLAYER;
            system("CLS");

            string Input;
            cout << "What Is Your Name Traveler?" << endl;
            getline(cin,Input);
            PLAYER.setName(Input);

            system("CLS");
            Starting_Quest(PLAYER);
        }
        else if(i == '4'){
            Shit PLAYER;
            system("CLS");

            string Input;
            cout << "What Is Your Name Traveler?" << endl;
            getline(cin,Input);
            PLAYER.setName(Input);

            system("CLS");
            Starting_Quest(PLAYER);
        }
        else if(i == '?'){
            Highwayman PLAYER(1);
            PLAYER.setName("Your Mom!");
            system("CLS");
            Starting_Quest(PLAYER);
        }
    }
}

int DieRoll(int ds, int dn){
    int Total = 0;
    for(; dn > 0; --dn){
        Total += (rand() % ds) + 1;
    }
    return Total;
}
