#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define width 60
#define height 30

int snakeX, snakeY, foodX, foodY, direction = 0, gameover, score,tail1X,tail1Y,tail2X,tail2Y;

int tailX[100], tailY[100];
int tailLength = 0;

void setup(){
    snakeY = (height / 2), snakeX = (width / 2);
    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;
    gameover = 1;
    score = 0;

}

void walls(){
    system("cls");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1){
                printf("*");
            }
        else{
            if (i == snakeY && j == snakeX){
                printf("$");
            }
            else if (i == foodY && j == foodX){
                printf("@");
            }
            else{
                int flag=0;
                for(int k=0;k<tailLength;k++){
                    if(tailY[k]==i && tailX[k]==j){
                    printf("O");
                    flag=1;
                    break;
                    }   
            }
                if(flag==0){
                printf(" ");}
        }}
        
    }
    printf("\n");
}}

void scoreandout(){
    if (snakeX == 0 || snakeX == (width-1) || snakeY == 0 || snakeY == (height-1)){
        gameover = 0;
    }
    for (int i = 0; i < tailLength; i++){
    if (snakeX == tailX[i] && snakeY == tailY[i]){
        gameover = 0;
    }
}
    if (snakeX == foodX && snakeY == foodY){
        score += 5;
        tailLength++;
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
    }

}

void control(){
    if (kbhit()){
        switch (getch()){
        case 'w':{
            if (direction != 2){
            direction = 1;}
            break;}
        case 's':{
            if (direction != 1){
                direction = 2;}
            break;}
        case 'a':{
            if (direction != 4){
            direction = 3;}
            break;}
        case 'd':{
            if (direction != 3){
            direction = 4;}
            break;}
        }
    }
}

void movement(){
    tail1X=snakeX;
    tail1Y=snakeY;

    for (int i = tailLength - 1; i > 0; i--){
        tailX[i]=tailX[i-1];
        tailY[i]=tailY[i-1];
        }
    if(tailLength>0){
        tailX[0]=tail1X;
        tailY[0]=tail1Y;
    }
    switch (direction){
    case 1:{
            snakeY--;
            break;}
    case 2:{
            snakeY++;
            break;}
    case 3:{
            snakeX--;
            break;}
    case 4:{
            snakeX++;
            break;}
    }


}

int main(){
    setup();
    while (gameover){
        walls();
        printf("\tSCORE = %d", score); 
        control();
        movement();
        scoreandout();
    }
    printf("\n\tGame Over!");
    return 0;
}
