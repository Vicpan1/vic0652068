#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char teamA[99], teamB[99];                                                   //存放A、B組資訊
int peopleA, peopleB;                                                        //存放A、B組人數
int pnumALL[20];                                                             //存放所有玩家編號 ,B組都從[9]開始 
int plusALL[20];                                                             //存放所有玩家的額外加分(金幣) ,B組都從[9]開始
int x;                                                                       //陣列呼叫位置用途 
int i;
int scoreA=0, scoreB=0;                                                      //A、B組得分
int moneyA=0, moneyB=0;                                                      //A、B組獲得金幣
int state;                                                                   //旗幟

void plus1(void);	     void plus2(void);
void score1(void);       void score2(void);

int main(int argc, char *argv[],const char * str) {
	
	printf("A組：");
    gets(teamA);									 			    		  //輸入A組玩家資訊,輸入的資訊存到字串team1 
    printf("\nB組：");
    gets(teamB);								    	 					  //輸入B組玩家資訊,輸入的資訊存到字串team2
	peopleA=((strlen(teamA)+1)/5);         								      //計算A組玩家人數,並存到peopleA 
	peopleB=((strlen(teamB)+1)/5);          								  //計算B組玩家人數,並存到peopleB 
	
	for(x=0;x<=peopleA-1;x++){                                               
		pnumALL[x]=((teamA[x*5]-'0')*10)+(teamA[(x*5)+1]-'0');             	  //玩家編號 
	}
	for(x=10;x<=peopleB+9;x++){                                               //玩家編號 
		pnumALL[x]=((teamB[(x-10)*5]-'0')*10)+(teamB[((x-10)*5)+1]-'0');              
	}

	if(peopleA<=peopleB){                                                     //加分分數 
		plus1();
	}else if(peopleA>peopleB){
		plus2();
	}
	
	do{
		printf("\n得分玩家編號：");
		scanf("%d",&state);
		i = 0;                                         						  //判斷是否有此玩家 ! 
		score1();
		score2();
		if(i==0){
			printf("\n沒有此玩家\n");
		}		
	}while(scoreA<50 && scoreB<50);
	if(scoreA>=50){
		printf("恭喜A組獲勝");
	}
	else if(scoreB>=50){
		printf("恭喜B組獲勝");
	}
	return 0;
}
//----------------------------------------------------------------------------以上為主程式--------------------------------------------------------------------------------- 

void plus1(void){
	for(x=2;x<=((peopleA*5)-3);x+=5){
		switch(teamA[x]){
			case'a':
				plusALL[(x-2)/5]=(peopleB-peopleA)*(teamA[x+1]-'0');
				break;
			case'b':
				plusALL[(x-2)/5]=teamA[x+1]-'0';
				break;
				case'c':
				plusALL[(x-2)/5]=40+(10*(teamA[x+1]-'0'));
		} 
	}
	for(x=2;x<=((peopleB*5)-3);x+=5){
		switch(teamB[x]){
			case'a':
				plusALL[((x-2)/5)+10]=0;
				break;
			case'b':
				plusALL[((x-2)/5)+10]=teamB[x+1]-'0';
				break;
			case'c':
				plusALL[((x-2)/5)+10]=40+(10*(teamB[x+1]-'0'));
		}
	}
}

void plus2(void){
	for(x=2;x<=((peopleA*5)-3);x+=5){
		switch(teamA[x]){
			case'a':
				plusALL[(x-2)/5]=0;
				break;
			case'b':
				plusALL[(x-2)/5]=teamA[x+1]-'0';
				break;
			case'c':
				plusALL[(x-2)/5]=40+(10*(teamA[x+1]-'0'));
		}
	}
	for(x=2;x<=((peopleB*5)-3);x+=5){
		switch(teamB[x]){
			case'a':
				plusALL[((x-2)/5)+10]=(peopleA-peopleB)*(teamB[x+1]-'0');
				break;
			case'b':
				plusALL[((x-2)/5)+10]=teamB[x+1]-'0';
				break;
			case'c':
				plusALL[((x-2)/5)+10]=40+(10*(teamB[x+1]-'0'));
		}
	}
}

void score1(void){
	for(x=0;x<9;x++){
		if(state==pnumALL[x]){
			i = 1;
			switch(teamA[(x*5)+2]){
				case'c':
					printf("\nA組得 %d 分，並且得到 %d 枚金幣\n\n",5,plusALL[x]);
					scoreA+=5;
					moneyA+=plusALL[x];
					printf("A組獲得金幣：%d\t\t",moneyA);
					printf("B組獲得金幣：%d\n\n",moneyB);
					printf("A組分數：%d\t\t",scoreA);
					printf("B組分數：%d\n\n",scoreB);
					break;
				default:
					printf("\nA組得 %d 分\n\n",5+plusALL[x]);
					scoreA+=5+plusALL[x];
					printf("A組獲得金幣：%d\t\t",moneyA);
					printf("B組獲得金幣：%d\n\n",moneyB);
					printf("A組分數：%d\t\t",scoreA);
					printf("B組分數：%d\n\n",scoreB);
			}
			break;
		}
	} 
}

void score2(void){
	for(x=10;x<19;x++){
		if(state==pnumALL[x]){
			i = 1;
			switch(teamB[((x-10)*5)+2]){
				case'c':
					printf("\nB組得 %d 分，並且得到 %d 枚金幣\n\n",5,plusALL[x]);
					scoreB+=5;
					moneyB+=plusALL[x];
					printf("A組獲得金幣：%d\t\t",moneyA);
					printf("B組獲得金幣：%d\n\n",moneyB);
					printf("A組分數：%d\t\t",scoreA);
					printf("B組分數：%d\n\n",scoreB);
					break;
				default:
					printf("\nB組得 %d 分\n\n",5+plusALL[x]);
					scoreB+=5+plusALL[x];
					printf("A組獲得金幣：%d\t\t",moneyA);
					printf("B組獲得金幣：%d\n\n",moneyB);
					printf("A組分數：%d\t\t",scoreA);
					printf("B組分數：%d\n\n",scoreB);
			}
			break;
		}	
	}
}
