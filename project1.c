#include<stdio.h>
#include<time.h>

// Roll Function
int rollTheDice(){
	return (rand()%6 + 1);
}


// Display Game Board
void displayBoard(int rows, int cols, int board[rows][cols]){
	
	int i,j;
	for(i=0;i<9;i++){
		printf("\n");
		for(j=0;j<9;j++){
			if (board[i][j]<10){
				if(board[i][j]==-1){
					printf("|      ",board[i][j]);
				}
				else{
					printf("|   %d  ",board[i][j]);
				}
			}
				
			else{
					printf("|  %d  ",board[i][j]);
			}
				
			if(j==8)
				printf("|\n");
		}
		printf("|------|------|------|------|------|------|------|------|------|-----");
		
		
	}
}



void update(int row,int col,int board[row][col],int len,int rota[len]){
	
	board[3][0]= rota[0];	board[3][1]= rota[1];
	board[3][2]= rota[2];	board[3][3]= rota[3];
	board[2][3]= rota[4];	board[1][3]= rota[5];
	board[0][3]= rota[6];	board[0][4]= rota[7];
	board[0][5]= rota[8];	board[1][5]= rota[9];
	board[2][5]= rota[10];	board[3][5]= rota[11];
	board[3][6]= rota[12];	board[3][7]= rota[13];
	board[3][8]= rota[14];	board[4][8]= rota[15];
	board[5][8]= rota[16];	board[5][7]= rota[17];
	board[5][6]= rota[18];	board[5][5]= rota[19];
	board[6][5]= rota[20];	board[7][5]= rota[21];
	board[8][5]= rota[22];	board[8][4]= rota[23];
	board[8][3]= rota[24];	board[7][3]= rota[25];
	board[6][3]= rota[26];	board[5][3]= rota[27];
	board[5][2]= rota[28];	board[5][1]= rota[29];
	board[5][0]= rota[30];	board[4][0]= rota[31];
	
}

void yellowToBoard(int row,int col,int board[row][col],int i,int j, int yellow[i][j]){
		board[0][0]=yellow[0][0];
		board[0][1]=yellow[0][1];
		board[1][0]=yellow[1][0];
		board[1][1]=yellow[1][1];
}
void redToBoard(int row,int col,int board[row][col],int i,int j, int red[i][j]){
		board[0][7]=red[0][0];
		board[0][8]=red[0][1];
		board[1][7]=red[1][0];
		board[1][8]=red[1][1];
}
void greenToBoard(int row,int col,int board[row][col],int i,int j, int green[i][j]){
		board[7][0]=green[0][0];
		board[7][1]=green[0][1];
		board[8][0]=green[1][0];
		board[8][1]=green[1][1];
}
void blueToBoard(int row,int col,int board[row][col],int i,int j, int blue[i][j]){
		board[7][7]=blue[0][0];
		board[7][8]=blue[0][1];
		board[8][7]=blue[1][0];
		board[8][8]=blue[1][1];
}




int main(){	
	srand(GetTickCount()); // for rand function
	
	// controller of finishing
	int redfinish[4]={0};
	int greenfinish[4]={0};
	int bluefinish[4]={0};
	
	int numberOfPlayers;
	int diceValue;
	int i,j;
	int temp;
	int min;
	int choice;
	int whichPiece;
	int wrongOperation = 1;
	int diceValues[2][4] = {1,2,3,4,0,0,0,0};
	int board[9][9]={0};
	board[2][0]=-1;board[2][1]=-1;board[2][2]=-1;board[1][2]=-1;board[0][2]=-1;board[2][6]=-1;board[2][7]=-1;board[2][8]=-1;
	board[0][6]=-1;board[1][6]=-1;board[6][0]=-1;board[6][1]=-1;board[6][2]=-1;board[7][2]=-1;board[8][2]=-1;board[6][6]=-1;
	board[6][7]=-1;board[6][8]=-1;board[7][6]=-1;board[8][6]=-1;board[4][4]=-1;
	
	int rota[32]={0};
	int choosePiece;
	
	int isAnyWinner = 0;
	
	int isAlive[4]={4,4,4,4};   // safe place
	
	// rota
	
	
	
	update(9,9, board,32,rota);

	
	int yellow[2][2] = {11,12,13,14};
	int red[2][2] = {21,22,23,24};
	int blue[2][2] = {31,32,33,34};
	int green[2][2] = {41,42,43,44};
	
	
	int yellowStart[4]={0};
	int redStart[4]={8,8,8,8};
	int greenStart[4]={24,24,24,24};
	int blueStart[4]={16,16,16,16};
	
	// t�m piyonlar final destinationa geldiginde 4 olacak
	int yellowFinished[4]={0};
	int redFinished[4]={0};
	int greenFinished[4]={0};
	int blueFinished[4]={0};

	
	
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
	if(numberOfPlayers==4){
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\nPlayer4 : Blue\n");
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
		greenToBoard(9,9,board,2,2,green);
		blueToBoard(9,9,board,2,2,blue);	
	}
		
	else if(numberOfPlayers==3){
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\n");
		
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
		greenToBoard(9,9,board,2,2,green);
	}
		
	else{
		printf("Player1 : Yellow\nPlayer2 : Red\n");
		
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
	}
		
	
	
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
		printf("\n%d.player  %d value",diceValues[0][i],diceValues[1][i]);
	}
	
	
	
	displayBoard(9,9,board);
	int numberOfPlayersCopy = numberOfPlayers;
	// while dongusu koyulmal�
	while(isAnyWinner==0){
		int currentPlayer=diceValues[0][numberOfPlayers-1];
		
		if(currentPlayer==1){
			printf("\nYellows turn\n",currentPlayer);
		}
		else if(currentPlayer==2){
			printf("\nReds turn\n",currentPlayer);
		}
		else if(currentPlayer==3){
			printf("\nGreens turn\n",currentPlayer);
		}
		else if(currentPlayer==4){
			printf("\nBlues turn\n",currentPlayer);
		}
		
		
		printf("press 1 to dice: \n");
		printf("Answer: ");
		
		scanf("%d",&choice);
		if(choice==1){
		
			int temp = rollTheDice();
			printf("dice value: %d\n",temp);
		
			if(temp==6){
				// pawnda piyon kalmad�ysa tek se�enek g�ster
				if(isAlive[currentPlayer-1]!=4){
					printf("press 1 for a new piece\npress 2 to move a piece: ");
					scanf("%d",&choice);
				}
				else{
					printf("press 1 for a new piece: ");
					scanf("%d",&choice);
					
				}	
				
			
				if(choice==1){
					
					// yellow arrayinin ilk eleman� diyelim
					printf("Y2 entered the game\n");
					
					if(isAlive[currentPlayer-1]==4){
						if(currentPlayer==1){
							rota[0]=yellow[0][0];
							yellow[0][0]=0;
						}
						else if(currentPlayer==2){
							rota[8]=red[0][0];
							red[0][0]=0;
						}
						else if(currentPlayer==3){
							rota[24]=green[0][0];
							green[0][0]=0;
						}
						else if(currentPlayer==4){
							rota[16]=blue[0][0];
							blue[0][0]=0;
						}
						
					}
					else if(isAlive[currentPlayer-1]==3){
						if(currentPlayer==1){
							rota[0]=yellow[0][1];
							yellow[0][1]=0;
						}
						else if(currentPlayer==2){
							rota[8]=red[0][1];
							red[0][1]=0;
						}
						else if(currentPlayer==3){
							rota[24]=green[0][1];
							green[0][1]=0;
						}
						else if(currentPlayer==4){
							rota[16]=blue[0][1];
							blue[0][1]=0;
						}
					}


					else if(isAlive[currentPlayer-1]==2){
						
						if(currentPlayer==1){
							rota[0]=yellow[1][0];
							yellow[1][0]=0;
						}
						
						else if(currentPlayer==2){
							rota[8]=red[1][0];
							red[1][0]=0;
						}
						
						else if(currentPlayer==3){
							rota[24]=green[1][0];
							green[1][0]=0;
						}
						
						else if(currentPlayer==4){
							rota[16]=blue[1][0];
							blue[1][0]=0;
						}
						
					}
						
					else if(isAlive[currentPlayer-1]==1){
						if(currentPlayer==1){
							rota[0]=yellow[1][1];
							yellow[1][1]=0;
						}
						else if(currentPlayer==2){
							rota[8]=red[1][1];
							red[1][1]=0;
						}
						else if(currentPlayer==3){
							rota[24]=green[1][1];
							green[1][1]=0;
						}
						else if(currentPlayer==4){
							rota[16]=blue[1][1];
							blue[1][1]=0;
						}
					}
					else{
						printf("All pieces have been played");
						isAlive[currentPlayer-1]++;
					}
						
					isAlive[currentPlayer-1]--;
					
					
					
					// Update safePlaces
					
					
					if(currentPlayer==1){
						yellowToBoard(9,9,board,2,2,yellow);
					}
					else if(currentPlayer==2){
						redToBoard(9,9,board,2,2,red);
						
					}
					else if(currentPlayer==3){
						greenToBoard(9,9,board,2,2,green);
						
					}
					else if(currentPlayer==4){
						blueToBoard(9,9,board,2,2,blue);
					}
					
					
					
					// Update board
					update(9,9, board,32,rota);
					
				}
			
				if(choice==2){
					printf("which piece should move: ");
					scanf("%d",&whichPiece);
				}
			}
			else{
				
			
				
				// movement
				 if(4-isAlive[currentPlayer-1]>0 ){
					printf("which piece should movee: ");
					scanf("%d",&choosePiece);
					
					//yellow
					for(i=11;i<15;i++){
						if(i==choosePiece){
							rota[yellowStart[i-11]+temp]=rota[yellowStart[i-11]];
							rota[yellowStart[i-11]]=0;
							yellowStart[i-11]+=temp;
							if(yellowStart[i-11]>31){
								printf("piyon basariyla sona geldi");
								isAlive[currentPlayer-1]++;	
							}
						}
					}
					
					//red
					for(i=21;i<25;i++){
						if(i==choosePiece){
							rota[(redStart[i-21]+temp)%32]=rota[redStart[i-21]];
							rota[redStart[i-21]]=0;
							redStart[i-21]+=temp;
							if(redStart[i-21]>32){
								redfinish[i-21]=1;
							}
							redStart[i-21]=redStart[i-21]%32;
							if(redStart[i-21]>7 && redfinish[i-21]==1){
								printf("piyon basariyla sona geldi");
								isAlive[currentPlayer-1]++;
								rota[redStart[i-21]]=0;
							}
						}
					}
					
					//green
					for(i=41;i<45;i++){
						if(i==choosePiece){
							rota[(greenStart[i-41]+temp)%32]=rota[greenStart[i-41]];
							rota[greenStart[i-41]]=0;
							greenStart[i-41]+=temp;
							if(greenStart[i-41]>32){
								greenfinish[i-41]=1;
							}
							greenStart[i-41]=greenStart[i-41]%32;
							if(greenStart[i-41]>23 && greenfinish[i-41]==1){
								printf("piyon basariyla sona geldi");
								isAlive[currentPlayer-1]++;
								rota[greenStart[i-41]]=0;
							}
						}
					}
					
					//blue
					for(i=31;i<35;i++){
						if(i==choosePiece){
							rota[(blueStart[i-31]+temp)%32]=rota[blueStart[i-31]];
							rota[blueStart[i-31]]=0;
							blueStart[i-31]+=temp;
							if(blueStart[i-31]>32){
								bluefinish[i-31]=1;
							}
							blueStart[i-31]=blueStart[i-31]%32;
							if(blueStart[i-31]>15 && bluefinish[i-31]==1){
								printf("piyon basariyla sona geldi");
								isAlive[currentPlayer-1]++;
								rota[blueStart[i-31]]=0;
							}
						}
					}
					
					
				
	
				}
			
	
				else{
					printf("Please, wait this round. \n");
					
				}
				
				//UPDATE
				if(currentPlayer==1){
					yellowToBoard(9,9,board,2,2,yellow);
				}
				else if(currentPlayer==2){
					redToBoard(9,9,board,2,2,red);
					
				}
				else if(currentPlayer==3){
					greenToBoard(9,9,board,2,2,green);
					
				}
				else if(currentPlayer==4){
					blueToBoard(9,9,board,2,2,blue);
				}
				update(9,9,board,32,rota);
			
			}
	
		}
		printf("current player: %d",currentPlayer);
		displayBoard(9,9,board);
		
		numberOfPlayers--;
		
		if(numberOfPlayers==0)
			numberOfPlayers=numberOfPlayersCopy;
	}

	return 0;
	
}



