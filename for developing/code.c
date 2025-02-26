#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


const int weapon_set[5] = {
    100, 120, 150, 200, 250
};

const char weapon_name[5][100] = {
    "Basic Sword",
    "Shadowfang Blade",
    "Frostmaul Sword",
    "Venomstrike Dagger",
    "Stormpiercer Sword"
};


const char gunting[5][100] = {
    "Tijeras",
    "Ciseaux",
    "Schere",
    "Forbici",
    "Ножницы"
};

const char batu[5][100] = {
    "Piedra",
    "Pierre",
    "Stein",
    "Sasso",
    "Камень"
};

const char kertas[5][100] = {
    "y Papel",
    "et Papier",
    "und Papier",
    "e Carta",
    "и Бумага"
};

const char bossname[5][100] = {
    "Zylnor", /*FIRE STRUCK*/
    "Eryndra", /*BLIND*/
    "Thraxxus", /*BONE OT STEEL*/
    "Kaelith", /*ELECTRO CHARGE*/
    "Vrakthar" /*EMPEROR OF TIME*/
};

const char item_name[4][100] = {
    "Bread",
    "Steak",
    "Booster",
    "Strong booster"
};

const int item_price[4] = {
    100, 150, 100, 200
};


void gbk(int guess, int *count);
void math(int *num1, int *num2, int *count);

void dodge(int *num1, int *num2, int *count, int *hp, int *base_atk, int *bosshp, int *bossatk){
    int random;
    *count = 0;
    random = rand() % 2;
    if(random == 1){
        math(num1, num2, count);
    }else{
        gbk(*num1, count);
    }

    if(*count == 1){
        *bosshp -= (*base_atk * 0.5);
        printf("\nCHALLANNGE DRAW");
    }else if(*count == 2){
        *bosshp -= *base_atk;
        printf("\nCHALLANGE WIN");
    }else{
        *hp -= *bosshp; /*STC*/
        printf("\nCHALLENGE LOSE");
    }

}

void gbk(int guess, int *count){
    int tebak = rand() % 3;
    int lhint = rand() % 4;
    int komp;
    char hint[100] = "";
    switch(tebak){
        case 0: /*GUNTING*/
            komp = 1;
            strcpy(hint, gunting[lhint]);
            break;
        case 1: /*BATU*/
            komp = 2;
            strcpy(hint, batu[lhint]);
            break;
        case 2: /*KERTAS*/
            komp = 3;
            strcpy(hint, kertas[lhint]);
            break;
    }
    system("cls");
    printf("\nKOMPUTER TELAH MEMILIH!");
    printf("\nHint : %s", hint);sleep(2);

    system("cls");
    printf("\nMASUKKAN TEBAKAN ANDA!");
    printf("\n1. GUNTING\n2. BATU\n3. KERTAS");
    printf("\nPILIHAN ANDA: ");scanf("%d", &guess);
    if(komp == guess){
        printf("\n!!SERI!!");
        *count = 1;
    } else{
        if(komp == 1 && guess == 2 || komp == 2 && guess == 3 || komp == 3 && guess == 1){
            printf("\n!!SELAMAT ANDA MENANG!!");
            *count = 2;
        }else{
            printf("\n!!ANDA KALAH!!");
        }
    }
    switch(komp){
        case 1:
            printf("\nKOMPUTER MEMILIH GUNTING");
            break;
        case 2:
            printf("\nKOMPUTER MEMILIH BATU");
            break;
        case 3:
            printf("\nKOMPUTER MEMILIH KERTAS");
            break;
        default:
            printf("\n!!ERROR!!");
    }
    sleep(3);
};

void math(int *num1, int *num2, int *count){
    int answer, operation, quest;
    *num1 = rand() % 100;
    *num2 = rand() % 100;
    operation = rand() % 2;
    
    system("cls");
    printf("\nQUESTION:");
    switch(operation){
        case 0:
            printf("\n%d + %d", *num1, *num2);
            quest = *num1 + *num2;
            sleep(2);
            break;
        case 1:
            if(*num1 < *num2){
                *num1 += rand() % 10;
            }
            printf("\n%d - %d", *num1, *num2);
            quest = *num1 - *num2;
            sleep(2);
            break;
        default:
            printf("\n!!ERROR!!");
    }

    system("cls");
    printf("\nINSERT THE RESULT: ");scanf("%d", &answer);
    if(answer == quest){
        printf("\nCONGRATULATIONS");
        *count = 2;
        sleep(1);
    }else{
        printf("\nLOSER!!");
        sleep(1);
    }

}

void attack(int *hp, int *bosshp, int *base_atk, int *bossatk){
    system("cls");
    printf("\nATTACKING!!");
    *hp -= *bossatk; /*STC*/
    *bosshp -= *base_atk;
    sleep(2);
}

void weaponidle(int *a, char wname[100]){
    strcpy(wname, weapon_name[*a]);
}

void weaponchange(int *a, int *point){
    int j;
    int p;
    system("cls");
    printf("\nCHOOSE YOUR WEAPON: ");
    for(j = 0; j < *point + 1; j++){
        printf("\n%d. %s", j + 1, weapon_name[j]);
    }
    printf("\n\nCHOICE: ");scanf("%d", &p);
    *a = p -1;
    sleep(2);
}

void battleshop(int *coin, int *hp, int *c_effect1, int *c_effect2){
    int j, choice;
    while(choice != 0){
        system("cls");
        printf("\nBATTLESHOP!!");
        for(j = 0; j < 4; j++){
            printf("\n%d. %s : %d", j + 1, item_name[j], item_price[j]);
        }
        printf("\nCOIN : %d", *coin);
        printf("\nCHOICE (0 to exit): ");scanf("%d", &choice);
        switch(choice){
            case 0:
                break;
            case 1:
                if(*coin < item_price[choice - 1]){
                    printf("\nCOIN NOT ENOUGH");
                }else{
                    *hp += 100;
                }
                break;
            case 2:
                if(*coin < item_price[choice - 1]){
                    printf("\nCOIN NOT ENOUGH");
                }else{
                    *hp += 200;
                }
                break;
            case 3:
                if(*coin < item_price[choice - 1]){
                    printf("\nCOIN NOT ENOUGH");
                }else{
                    *c_effect1 += 3;
                }
                break;
            case 4:
                if(*coin < item_price[choice - 1]){
                    printf("\nCOIN NOT ENOUGH");
                }else{
                    *c_effect2 += 5;
                }
                break;
            default:
                printf("\nITEM NOT FOUND");
                break;
        }
        if(*coin >= item_price[choice - 1]){
            *coin -= item_price[choice - 1];
            if(choice != 0)printf("\nYou Purchased %s", item_name[choice - 1]);
        }
        sleep(2);
    }
}

void baseattackop(int *base_atk, int *a, int *e_count, int *c_effect1, int *c_effect2, int *item_effect){
    if(*c_effect1 > 0){
        *item_effect += 100;
    }

    if(*c_effect2 > 0){
        *item_effect += 100;
    }

    *base_atk = weapon_set[*a] + *item_effect;
}

void effectindicator(int *c_effect1, int *c_effect2){
    if(*c_effect1 > 0){
        printf("\n\nITEM EFFECT TURNS REMAIN : %d\n", *c_effect1);
    }
    if(*c_effect2 > 0){
        printf("\n\nITEM EFFECT TURNS REMAIN : %d\n", *c_effect2);
    }
}

void bodybattle(int num1, int num2, int count, int *hp, int *coin, int *coin_menu, int *s_count, int *point){


    int bosshp[5] = { 100, 1500, 2000, 2500, 3000};
    int bossatk[5] = { 100, 125, 150, 200, 220}; /*STC*/
    int i, choice;
    *point = *s_count;
    if(i > 4 && *point > 4){
        i = 0;
        *point = 0;
    }
    
    char wname[100] = "";
    int a = 0;
    int item_effect = 0;

    int e_count = 0, c_effect1 = 0, c_effect2 = 0;

    for(i = *point; i < 5; i++){
        while(choice != 5){
            
            int base_atk;
            if(c_effect1 < 0)c_effect1 = 0;
            if(c_effect2 < 0)c_effect2 = 0;

            baseattackop(&base_atk, &a, &e_count, &c_effect1, &c_effect2, &item_effect);
            weaponidle(&a, wname);

            system("cls");
            printf("\nBOSS LEVEL %d", i + 1);
            printf("\nBOSS NAME: %s", bossname[i]);
            printf("\nBOSS HP: %d", bosshp[i]);
            printf("\n");
            printf("\nYOUR HP: %d", *hp);
            printf("\nYOUR WEAPON: %s", wname);
            printf("\nCOIN : %d", *coin);

            effectindicator(&c_effect1, &c_effect2);

            printf("\nCHOOSE YOUR MOVE: ");
            printf("\n1. ATTACK\n2. DEFENDS (DODGE)\n3. CHANGE WEAPON\n4. SHOP\n5. EXIT");
            printf("\nINSERT YOUR CHOICE: ");scanf("%d", &choice);
            switch(choice){
                case 1:
                    attack(hp, &bosshp[i], &base_atk, &bossatk[i]);
                    (c_effect1)--;
                    break;
                case 2:
                    dodge(&num1, &num2, &count, hp, &base_atk, &bosshp[i], &bossatk[i]);
                    (c_effect2)--;
                    break;
                case 3:
                    weaponchange(&a, point);
                    break;
                case 4:
                    battleshop(coin, hp, &c_effect1, &c_effect2);
                    break;
            }
            
            if(bosshp[i] <= 0){
                *point += 1;
                *s_count = *point;
                *coin += rand() % 1000; 
                break;
            }
        }
    }
    system("cls");
    printf("\nBACK TO LOBBY");
    sleep(2);
}

void adventurebattle(int *hp, int *coin, int *coin_menu, int num1, int num2, int count, int *point){
    int krocohp[2] = {100, 150};
    char kroco_name[2][100] = {
        "Goblin",
        "Knight"
    };
    int kroco_atk[2] = {40, 50};

    int i, choice;
    char wname[100] = "";
    int a = 0;
    int item_effect = 0;

    int e_count = 0, c_effect1 = 0, c_effect2 = 0;

    while(choice != 5){

        i = rand() % 2;
        int base_atk;
        if(c_effect1 < 0)c_effect1 = 0;
        if(c_effect2 < 0)c_effect2 = 0;
        baseattackop(&base_atk, &a, &e_count, &c_effect1, &c_effect2, &item_effect);
        weaponidle(&a, wname);
        system("cls");
        printf("\nADVENTURE MODE!!");
        printf("\nEnemy: %s", kroco_name[i]);
        printf("\nEnemy Hp: %d", krocohp[i]);
        printf("\nYour Weapon: %s", wname);
        printf("\nYOUR HP: %d\tYOUR COIN: %d", *hp, *coin);
        effectindicator(&c_effect1, &c_effect2);
        printf("\nMake Your Move: ");
        printf("\n1. ATTACK\n2. DEFENDS (DODGE)\n3. CHANGE WEAPON\n4. SHOP\n5. EXIT");
        printf("\nYour CHOICE: ");scanf("%d", &choice);
        switch(choice){
            case 1:
                attack(hp, &krocohp[i], &base_atk, &kroco_atk[i]);
                (c_effect1)--;
                break;
            case 2:
                dodge(&num1, &num2, &count, hp, &base_atk, &krocohp[i], &kroco_atk[i]);
                (c_effect2)--;
                break;
            case 3:
                weaponchange(&a, point);
                break;
            case 4:
                battleshop(coin, hp, &c_effect1, &c_effect2);
                break;
        }
        if(krocohp[0] <= 0){
            *coin += rand() % 80;
            krocohp[0] = 100;
        } else if(krocohp[1] <= 0){
            *coin += rand() % 100;
            krocohp[1] = 150;
        }
    }
    printf("\nBACK TO LOBBY!");
    sleep(2);
}

void userload(char nama, int hp, int coin, int point){

}

void ingame(char nama[100], int *hp, int *coin, int *point){
    int num1, num2;
    if(*point >= 4){
        *point = 0;
    }
    int count, coin_menu = 0;



    int choice;
    srand(time(NULL));
    while(choice != 3){
        system("cls");
        printf("\n==TOWNHALL==");
        printf("\nNAME: %s", nama);
        printf("\nYour HP: %d", *hp);
        printf("\nYour Coin: %d", *coin);
        printf("\nWHAT WILL YOU DO?");
        printf("\n1. DUNGEON\n2. ADVENTURE\n3. EXIT");
        printf("\nYour Choice: ");scanf("%d", &choice);
        switch(choice){
            case 1:
                bodybattle(num1, num2, count, hp, coin, &coin_menu, &count, point);
                break;
            case 2:
                adventurebattle(hp, coin, &coin_menu, num1, num2, count, point);
                break;
            case 3:
                break;

        }
        sleep(2);
        
    }
}   

void savefile(char nama[100], int *hp, int *coin, int *point){
    FILE *file = fopen("save.txt", "r");
    FILE *temp = fopen("tempsave.txt", "w");
    char buffer[100], target[100];
    int found = 0;
    
    int temphp, tempcoin, temppoint;
    if(file == NULL || temp == NULL){
        printf("\nERROR");
        return;
    }

    printf("\nSAVING YOUR PROGRESS");
    printf("\nMasukkan Username anda: ");scanf("%s", target);
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        sscanf(buffer, "%[^,],%d,%d,%d", nama, &temphp, &tempcoin, &temppoint);
        if(strcmp(nama, target) == 0){
            found = 1;
            fprintf(temp, "%s,%d,%d,%d\n", nama, *hp, *coin, *point);
        }else{
            fprintf(temp, "%s,%d,%d,%d\n", nama, temphp, tempcoin, temppoint);
        }
    }

    fclose(temp);fclose(file);
    if(found == 1){
        printf("\nSAVED");
        remove("save.txt");
        rename("tempsave.txt", "save.txt");
    }else{
        printf("\nERROR 05");
        remove("tempsave.txt");
    }
}

void loaduser(){
    char nama[100];
    int hp, coin, point;

    char tempnama[100];
    int temphp, tempcoin, temppoint;
    
    char buffer[100], target[100];
    int found = 0;  

    FILE *file = fopen("save.txt", "r");
    if(file == NULL){
        printf("\nERROR");
        return;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        sscanf(buffer, "%[^,],%d,%d,%d", tempnama, &temphp, &tempcoin, &temppoint);
        printf("\nUsername: %s", tempnama);
        printf("\nHP: %d    Coin: %d", temphp, tempcoin);
        printf("\n");
    }

    rewind(file);

    printf("\nMasukkan username yang ingin anda load: ");scanf("%s", target);
    while(fgets(buffer, sizeof(buffer), file) != NULL){
        sscanf(buffer, "%[^,],%d,%d,%d", tempnama, &temphp, &tempcoin, &temppoint);
        if(strcmp(tempnama, target) == 0){
            strcpy(nama, tempnama);
            hp = temphp;
            coin = tempcoin;
            point = temppoint;
            found = 1;
            break;
        }
    }
    
    fclose(file);
    if(found == 1){
        printf("\nSelamat datang %s", nama);
        ingame(nama, &hp, &coin, &point);
        savefile(nama, &hp, &coin, &point);
    }else{
        printf("\nDATA TIDAK DITEMUKAN");
    }

}
void newuser(){
    char nama[100];
    int coin = 0;
    int hp = 1000;
    int point = 0;

    printf("\n== NEW USER ==");
    printf("\nName: ");scanf("%s", nama);


    FILE *file = fopen("save.txt", "a");
    if(file== NULL){
        printf("\nERROR");
        return;
    }

    fprintf(file, "%s,%d,%d,%d\n", nama, hp, coin, point);
    fclose(file);

    ingame(nama, &hp, &coin, &point);
    savefile(nama, &hp, &coin, &point);
};



int main(){
    int choice;

    printf("\nWELCOME TO SWITCH AND KILL");
    printf("\n1. NEW GAME\n2. LOAD GAME");
    printf("\nINSERT YOUR CHOICE: ");scanf("%d", &choice);
    switch(choice){
        case 1:
            newuser();
            break;
        case 2:
            loaduser();
            break;
        default:
            printf("\nERROR");
    }

}