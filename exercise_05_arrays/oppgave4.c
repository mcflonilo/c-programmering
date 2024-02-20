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


int makeBot(struct bot **bot, int botNum) {
    int activeBots = 0;
    srand((unsigned)time(0));
    for (int i = 0; i < botNum; ++i) {
        if (botNum < 3) {
            bot[i]->active = 1;
        } else {
            bot[i]->active = rand() % 2;
        }
        if(bot[i]->active){activeBots++;}

        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < 3; ++j) {
                bot[i]->array[k][j] = rand() % 2;
            }
        }
    }
    return activeBots;
}
int playTurn( int level, struct bot **bot, int activeBots){
    int answer = 0;
    fd_set input;
    char test[] = {0};
    int returnValue;
    struct timeval timeout;
    int time = 10-level;

    printf("active bots %d", activeBots);

    for (int i = 0; i < 3; ++i) {
        printf("\n");
        for (int j = 0; j < activeBots; ++j) {
            for (int k = 0; k < 3; ++k) {

                if(bot[j]->array[i][k]==1){answer++;}
                printf("%d",bot[j]->array[i][k]);
            }
            printf(" ");
        }
    }
    printf("\n");


    FD_ZERO(&input);
    FD_SET(STDIN_FILENO,&input);

    timeout.tv_sec = time;
    timeout.tv_usec = 0;
    returnValue = select(1, &input, NULL, NULL, &timeout);
    if(returnValue == -1){
        printf("noe gikk galt");
        return -1;
    }
    printf("answer == %d\n", answer);
    if(returnValue){
        read(0,test, 19);
        return (answer==atoi(&test[0]));
    }
    else{
        return 0;
    }
}


int main(){
    int numberOfBots = 8;
    int activeBots;
    int health = 100;
    int level = 1;
    int i;

    struct bot **bots = malloc(numberOfBots * sizeof(struct bot *));
    for (int j = 0; j < numberOfBots; ++j) {
        bots[j] = malloc(sizeof(struct bot));
        bots[j]->array = (int**)calloc(3, sizeof (int*));
        for(i=0;i<3;i++){
            bots[j]->array[i]= (int*) calloc(3,sizeof(int));
        }
    }

    while(health>0&&level<10){
        activeBots = makeBot(bots,numberOfBots);

        switch (playTurn(level, bots,activeBots)) {
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

    for (i = 0; i < numberOfBots; ++i) {
        for (int j = 0; j < 3; ++j) {
            free(bots[i]->array[j]);
        }
        free(bots[i]->array);
    }
    return 0;
}