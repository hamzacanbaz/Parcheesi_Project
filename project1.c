#include<stdio.h>
#include<time.h>

// Roll Function
int rollTheDice(){
	return (rand()%5 + 1);
}


int main(){	
	srand(GetTickCount()); // for rand function
	int numberOfPlayers;
	int i,j;
	int temp;
	int min;
	int wrongOperation = 1;
	int diceValues[2][4] = {1,2,3,4,0,0,0,0};
	int startArray[2][4];

	
	
	// Number of players control(2-4)
	while(wrongOperation!=0){
			printf("Number of players: ");
			scanf("%d",&numberOfPlayers);
			if(!(numberOfPlayers>=2 && numberOfPlayers<=4)){
				printf("number of players must be between 2 and 4\n");
				wrongOperation=1;
			}
			else
				wrongOperation=0;			
	}
	printf("%d\n",numberOfPlayers);
	
	
	// Colors of players
	if(numberOfPlayers==4)
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\nPlayer4 : Blue\n");
	else if(numberOfPlayers==3)
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\n");
	else
		printf("Player1 : Yellow\nPlayer2 : Red\n");
	
	
	// Decide who to start
	for(i=0;i<numberOfPlayers;i++){
		diceValues[1][i] = rollTheDice();
		printf("%d ",diceValues[1][i]);
	}
	
	for(i=0;i<numberOfPlayers;i++){
		for(j=i+1;j<numberOfPlayers;j++){
			if(diceValues[1][i]>diceValues[1][j]){
				temp = diceValues[1][i];
				diceValues[1][i]=diceValues[1][j];
				diceValues[1][j] = temp;
				temp = diceValues[0][i];
				diceValues[0][i]=diceValues[0][j];
				diceValues[0][j] = temp;
			}
		}
		
	}

	// turn to play
	for(i=numberOfPlayers-1;i>=0;i--){
		printf("\n%d.player  %d degerli",diceValues[0][i],diceValues[1][i]);
	}
	

	
	
	
	
	


	
	return 0;
	
}


