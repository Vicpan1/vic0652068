#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char teamA[99], teamB[99];                                                   //�s��A�BB�ո�T
int peopleA, peopleB;                                                        //�s��A�BB�դH��
int pnumALL[20];                                                             //�s��Ҧ����a�s�� ,B�ճ��q[9]�}�l 
int plusALL[20];                                                             //�s��Ҧ����a���B�~�[��(����) ,B�ճ��q[9]�}�l
int x;                                                                       //�}�C�I�s��m�γ~ 
int i;
int scoreA=0, scoreB=0;                                                      //A�BB�ձo��
int moneyA=0, moneyB=0;                                                      //A�BB����o����
int state;                                                                   //�X�m

void plus1(void);	     void plus2(void);
void score1(void);       void score2(void);

int main(int argc, char *argv[],const char * str) {
	
	printf("A�աG");
    gets(teamA);									 			    		  //��JA�ժ��a��T,��J����T�s��r��team1 
    printf("\nB�աG");
    gets(teamB);								    	 					  //��JB�ժ��a��T,��J����T�s��r��team2
	peopleA=((strlen(teamA)+1)/5);         								      //�p��A�ժ��a�H��,�æs��peopleA 
	peopleB=((strlen(teamB)+1)/5);          								  //�p��B�ժ��a�H��,�æs��peopleB 
	
	for(x=0;x<=peopleA-1;x++){                                               
		pnumALL[x]=((teamA[x*5]-'0')*10)+(teamA[(x*5)+1]-'0');             	  //���a�s�� 
	}
	for(x=10;x<=peopleB+9;x++){                                               //���a�s�� 
		pnumALL[x]=((teamB[(x-10)*5]-'0')*10)+(teamB[((x-10)*5)+1]-'0');              
	}

	if(peopleA<=peopleB){                                                     //�[������ 
		plus1();
	}else if(peopleA>peopleB){
		plus2();
	}
	
	do{
		printf("\n�o�����a�s���G");
		scanf("%d",&state);
		i = 0;                                         						  //�P�_�O�_�������a ! 
		score1();
		score2();
		if(i==0){
			printf("\n�S�������a\n");
		}		
	}while(scoreA<50 && scoreB<50);
	if(scoreA>=50){
		printf("����A�����");
	}
	else if(scoreB>=50){
		printf("����B�����");
	}
	return 0;
}
//----------------------------------------------------------------------------�H�W���D�{��--------------------------------------------------------------------------------- 

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
					printf("\nA�ձo %d ���A�åB�o�� %d �T����\n\n",5,plusALL[x]);
					scoreA+=5;
					moneyA+=plusALL[x];
					printf("A����o�����G%d\t\t",moneyA);
					printf("B����o�����G%d\n\n",moneyB);
					printf("A�դ��ơG%d\t\t",scoreA);
					printf("B�դ��ơG%d\n\n",scoreB);
					break;
				default:
					printf("\nA�ձo %d ��\n\n",5+plusALL[x]);
					scoreA+=5+plusALL[x];
					printf("A����o�����G%d\t\t",moneyA);
					printf("B����o�����G%d\n\n",moneyB);
					printf("A�դ��ơG%d\t\t",scoreA);
					printf("B�դ��ơG%d\n\n",scoreB);
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
					printf("\nB�ձo %d ���A�åB�o�� %d �T����\n\n",5,plusALL[x]);
					scoreB+=5;
					moneyB+=plusALL[x];
					printf("A����o�����G%d\t\t",moneyA);
					printf("B����o�����G%d\n\n",moneyB);
					printf("A�դ��ơG%d\t\t",scoreA);
					printf("B�դ��ơG%d\n\n",scoreB);
					break;
				default:
					printf("\nB�ձo %d ��\n\n",5+plusALL[x]);
					scoreB+=5+plusALL[x];
					printf("A����o�����G%d\t\t",moneyA);
					printf("B����o�����G%d\n\n",moneyB);
					printf("A�դ��ơG%d\t\t",scoreA);
					printf("B�դ��ơG%d\n\n",scoreB);
			}
			break;
		}	
	}
}
