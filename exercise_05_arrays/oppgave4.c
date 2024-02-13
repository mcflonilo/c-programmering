//
// Created by lar on 2/9/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
struct bot{
    int active;
    int** array;
};
struct bot bots[8];

void makeBot(struct bot bot, int botNum){
    srand(((unsigned)time(0)));
    if(botNum<3){bot.active=1;}
    else{bot.active= rand()%2;}

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            bot.array[i][j] = rand()%2;
        }
    }
}
int playTurn(int** bot, int level){
    int answer = 0;
    fd_set input;
    char test[] = {0};
    int returnvalue;
    struct timeval timeout;
    int time = 10-level;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(bot[i][j]==1){answer++;}
            printf("%d",bot[i][j]);
        }
        printf("\n");
    }

    FD_ZERO(&input);
    FD_SET(STDIN_FILENO,&input);

    timeout.tv_sec = time;
    timeout.tv_usec = 0;
    returnvalue = select(1,&input,NULL,NULL,&timeout);
    if(returnvalue==-1){
        printf("noe gikk galt");
        return -1;
    }
    if(returnvalue){
        read(0,test, 19);
        printf("%s", test);
        return (answer==atoi(&test[0]));
    }
    else{
        return 0;
    }
}


int main(){
    int health = 100;
    int level = 1;
    int i;

    for (int j = 0; j < 8; ++j) {
        bots[j].array = (int**)calloc(3, sizeof (int*));
        for(i=0;i<3;i++){
            bots[j].array[i]= (int*) calloc(3,sizeof(int));
        }
    }


    while(health>0||level!=10){
        for (int j = 0; j < 8; ++j) {
            makeBot(bots[j],j);
        }

        switch (playTurn(enemy.array,level)) {
            case 0:
                health -=10;
                printf("du gikk tom for tid. Du tar 10 skade. livet ditt er nå %d\n",health);
                break;
            case 1:
                printf("riktig du går videre til nivå %d\n",++level);
                break;
            case 2:
                health-=5;
                printf("feil du tar 5 skade, livet ditt er nå på %d\n", health);
                break;
            default:
                printf("what the hell");
        }
    }

    for (int j = 0; j < 3; ++j) {
        free(enemy.array[j]);
    }
    free(enemy.array);
    return 0;
}