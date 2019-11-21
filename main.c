#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*player selcet*/
int ci=0; //card index
int p; //number of players
//
void player(){
	printf("input the number of players(MAX: 5) : ");
	scanf("%d", &p);
	
	while(p<=0||p>5){
		printf("invalid input players (%d)\n", p);
		printf("input the number of players(MAX: 5) : ");
	    scanf("%d", &p);
	}
	printf("--> card is mixed and put into the tray\n\n");
}

/*betting step*/
int A[6][3];// A[][0]=total money, A[][1]=betting money, A[][2]=sum of card numbers
int i;

int yb; //your betting money
//
void betting(){
	for(i=0; i<6; i++){
		A[i][0]=50;
	}
	printf("----- BETTING STEP -----\n");
	printf(" -> your betting (total:$%d) : ", A[0][0]);
	scanf("%d", &yb);
	while(yb<=0||yb>A[0][0]){
		printf(" -> invalid input for betting $%d\n", yb);
		printf(" -> your betting (total:$%d) : ", A[0][0]);
		scanf("%d", &yb);
	}
	yb=A[0][1];
	srand(time(NULL));
	for(i=1; i<p; i++){
		
		A[i][1]= rand()%5+1;
		printf(" -> player%d bets $%d (out of $%d)\n", i, A[i][1], A[i][0]);
	}
	printf("-----------------------------------\n\n");	
}
int c[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//card offering
int k_1, k_2, p_1, p_2, p_3 ,s_1,  s_2, s_3;
void card(){
	srand(time(NULL));
	printf("----- CARD OFFERING ------------\n");
	//server
	s_2=c[5+rand()%5];
	printf("--- server    : X %d\n", s_2);
	A[6][2]=s_2;
	//you
    k_1=c[3+rand()%7], k_2=c[0+rand()%10];
	printf("  -> you      : %d %d\n", k_1, k_2);
	A[0][2]=k_1+k_2;
	ci+=4;
	//players
	for(i=1; i<p; i++){
    p_1=c[0+rand()%10], p_2=c[5+rand()%5];
	    printf("  -> player%d  : %d %d\n", i, p_1, p_2);
	    A[i][2]=p_1+p_2;
	    ci+=2;
	}
}

//game start

int g; //go or stay
int k_3, k_4, k_5, k_6, k_7, k_8, k_9, k_10; //k_() :()¹ø Ä«µå 
void game_start(){
	printf("\n--------------- GAME START --------------------\n");
	//my turn
	printf(">>> my turn! -------------\n");

	printf("  -> card : %d %d", k_1, k_2);
	printf("   ::: Action? (0 - go, others - stay) :");
	scanf("%d", &g);
	switch(g){
		case 0:
			k_3=c[4+rand()%6];
			printf("  -> card : %d %d %d", k_1, k_2, k_3);
			A[0][2]+=k_3;
			ci++; 
			if(A[0][2]>21){
				A[0][0]-=A[0][1];
				printf("   ::: DEAD (sum:%d) --> -$%d ($%d)\n", A[0][2], A[0][1], A[0][0]); 
			}
			else if(A[0][2]=21){
				A[0][0]+=A[0][1];
				printf("   ::: Black Jack! Congratulation --> +$%d ($%d)\n", A[0][1], A[0][0]);
			}
			else{
				printf("   ::: Action? (0 - go, others - stay) :");
				scanf("%d", &g);
				switch(g){
					case 0:
				        k_4=c[0+rand()%10];
				        printf("  -> card : %d %d %d %d", k_1, k_2, k_3, k_4);
				        A[0][2]+=k_4;
				        ci++;
                        if(A[0][2]>21){
		            		A[0][0]-=A[0][1];
			            	printf("   ::: DEAD (sum:%d) --> -$%d ($%d)\n", A[0][2], A[0][1], A[0][0]); 
		               	}
			            else if(A[0][2]=21){
		                 		A[0][0]+=A[0][1];
			                 	printf("   ::: Black Jack! Congratulation --> +$%d ($%d)\n", A[0][1], A[0][0]);
		               	}
		               	else{
		               		printf("   ::: Action? (0 - go, others - stay) :");
		               		scanf("%d", &g);
							   switch(g){
							   	    case 0:
							   	    	k_5=c[3+rand()%7];
							   	    	ci++;
							   	    	printf("  -> card : %d %d %d %d %d", k_1, k_2, k_3, k_4, k_5);
							   	    	A[0][2]+=k_5;
							   	    	if(A[0][2]>21){
							   	    		A[0][0]-=A[0][1];
							   	    		printf("   ::: DEAD (sum:%d) --> -$%d ($%d)\n", A[0][2], A[0][1], A[0][0]);
							   	    	}
							   	    		else if(A[0][2]=21){
							   	    			A[0][0]-=A[0][1];
							   	    			printf("   ::: DEAD (sum:%d) --> -$%d ($%d)\n", A[0][2], A[0][1], A[0][0]);
											   }
											   else if(A[0][2]=21){
											   	       A[0][0]+=A[0][1];
											   	       printf("   ::: Black Jack! Congratulation --> +$%d ($%d)\n", A[0][1], A[0][0]);
											   }
										   }
							   } 
						   }}	
			}
				
		
			
    //players turn
    for(i=1; i<p; i++){
	
    printf(">>>player %d turn! ----------\n", i);
    printf("  -> card : %d %d\n",p_1, p_2);
    if(A[i][2]<15){
    	p_3=c[0+rand()%10];
    	printf("  -> card : %d %d %d", p_1, p_2, p_3);
    	A[i][2]+=p_3;
    	ci++;
    	if(A[i][2]=21){
    		A[i][0]+=A[i][1];
    		printf("   ::: Black Jack! congratulation --> +$%d ($%d)\n\n", A[i][1], A[i][0]);
		}
		else if(A[i][2]>21){
			A[i][0]-=A[i][1];
			printf("   ::: DEAD (sum:%d) --> -$%d ($%s)\n\n", A[i][2], A[i][1], A[i][0]);
		}
	}}
	//serve turn
	printf(">>> sever turn! ------------------------------\n");
	s_1=c[0+rand()%10];
	printf("  -> card : %d %d",s_1, s_2 );
	A[6][2]+=s_2;
	ci++;
	if(A[6][2]<15){
		printf("   ::: GO!\n");
		s_3=c[0+rand()%10];
		printf("  -> card : %d %d %d", s_1, s_2, s_3);
		A[6][2]+=s_3;
		if(A[6][2]=21){
			printf("\nsever result is .... Black Jack\n");
		}
		else if(A[6][2]>21){
			printf("\nsever is DEAD (sum:%d)\n", A[6][2]);
		}
	}
    if(A[0][2]>A[6][2]){
    	A[0][0]+=A[0][1];
    	printf("  -> your result : win (sum:%d) --> $%d\n", A[0][2], A[0][0]);
	}
	else if(A[0][2]=A[6][2]){
		printf("  -> your result : same the result (sum:%d) --> $%d\n", A[0][2], A[0][0]);
	}else{
		A[0][0]-=A[0][1];
		printf("  -> your result : lose! (sum:%d) --> $%d\n", A[0][2], A[0][0]);
	}
}
	
	
	
    


void main(){
int r=1;  //round number 
	player();
	while(ci<=52){
		printf("--------------------------------------\n");
		printf("------- ROUND %d (cardindex:%d)----------------------------\n", r, ci);
		printf("--------------------------------------\n\n");
	    betting();
	    card();
	    game_start();
	    r++;
    }
    printf("\ncard is ran out of the tray!! finishing the game...\n ");
	return 0;
}
