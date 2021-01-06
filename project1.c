#include<stdio.h>
#include<time.h>

// Roll Function
int rollTheDice(){
	return (rand()%6 + 1);
}


// Display Game Board
void displayBoard(int rows, int cols, int board[rows][cols]){
	printf("\n");
	printf("\n");
	printf("|------|------|------|------|------|------|------|------|------|");
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
		printf("|------|------|------|------|------|------|------|------|------|");
		
		
	}
	printf("\n");
	printf("\n");
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
	int yellowfinish[4]={0};
	int redfinish[4]={0};
	int greenfinish[4]={0};
	int bluefinish[4]={0};
	
	int playToFirstCell;
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
	
	int isAlive[4]={4,4,4,4};   // in spawn
	
	// rota
	
	
	
	update(9,9, board,32,rota);

	
	int yellow[2][2] = {11,12,13,14}; // spawn matrix
	int red[2][2] = {21,22,23,24};
	int blue[2][2] = {31,32,33,34};
	int green[2][2] = {41,42,43,44};
	
	
	int yellowStart[4]={0};          // starting point of each pieces
	int redStart[4]={8,8,8,8};
	int greenStart[4]={24,24,24,24};
	int blueStart[4]={16,16,16,16};
	
	// tüm piyonlar final destinationa geldiginde 4 olacak
	int yellowFinished[4]={0};    
	int redFinished[4]={0};
	int greenFinished[4]={0};
	int blueFinished[4]={0};
	
	int inBoard[4]={0};          // still playing on the map
	int isFinished[4]={0};		// number of finished pieces
	

	
	
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
	// kýsaltýlabilir yellow ve redi alta alýp hepsinden çýkarýp
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
	printf("\nWARNING: If you make an illegal move, you will lose your right");
	
	int sixController;
	displayBoard(9,9,board);
	int numberOfPlayersCopy = numberOfPlayers;
	
	
	// while dongusu koyulmalý
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
		if(choice!=1){
			printf("You lost your right.\nPlease wait this round.\n");
		}
		if(choice==1){
		
			int temp = rollTheDice();
			printf("dice value: %d\n",temp);
			sixController=1;
			if(temp==6){
				sixController=1;
				// pawnda piyon kalmadýysa tek seçenek göster
				// 4-isAlive[currentPlayer-1]!=0 &&
				if( inBoard[currentPlayer-1]==0){
					printf("press 1 for a new piece: ");
					scanf("%d",&choice);
				}
				else{
					
					printf("press 1 for a new piece\npress 2 to move a piece: ");
					scanf("%d",&choice);
					
				}
				if(choice!=1 && choice!=2){
					printf("You lost your right\n");
				}	
				
				playToFirstCell=0;
				// oyuna piyon sokarken o hücrede zaten bir piyon varsa sadece hareket imkaný ver
				if(currentPlayer==1 && choice==1){
						if(rota[0]/10==1){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
						else if(rota[0]/10!=1 && rota[0]!=0){
							choice=1;
							//sarý oyuna girerken birini yerse
							if(rota[0]/10==2){
								if(rota[0]==21)
									red[0][0]=21;
								else if(rota[0]==22)
									red[0][1]=22;
								else if(rota[0]==23)
									red[1][0]=23;
								else if(rota[0]==23)
									red[1][1]=23;
								inBoard[1]--;	
								isAlive[1]++;
								redStart[rota[0]-21]=8;
								redToBoard(9,9,board,2,2,red);
							}
							else if(rota[0]/10==4){
								if(rota[0]==41)
									green[0][0]=41;
								else if(rota[0]==42)
									green[0][1]=42;
								else if(rota[0]==43)
									green[1][0]=43;
								else if(rota[0]==44)
									green[1][1]=44;
								inBoard[2]--;	
								isAlive[2]++;
								greenStart[rota[0]-41]=24;
								
							}
							else if(rota[0]/10==3){
								if(rota[0]==31)
									blue[0][0]=31;
								else if(rota[0]==32)
									blue[0][1]=32;
								else if(rota[0]==33)
									blue[1][0]=33;
								else if(rota[0]==34)
									blue[1][1]=34;
								inBoard[3]--;	
								isAlive[3]++;
								blueStart[rota[0]-31]=16;
							}
							
							
							
						}
				}
				if(currentPlayer==2 && choice==1){
						if(rota[8]/10==2){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
				}
				if(currentPlayer==4 && choice==1){
						if(rota[16]/10==3){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
				}
				if(currentPlayer==3 && choice==1){
						if(rota[24]/10==4){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
					}
//				
				if(choice==1){
					
					
					
					// yellow arrayinin ilk elemaný diyelim
					printf("Y2 entered the game\n");
					// hangi piyonun oyuna gireceði
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
						inBoard[currentPlayer-1]--;	
					}
					inBoard[currentPlayer-1]++;	
					isAlive[currentPlayer-1]--;
					
					
					
					// Update safePlaces
					if(numberOfPlayersCopy==2){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
					}
					if(numberOfPlayersCopy==3){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
					}
					else if(numberOfPlayersCopy==4){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
						blueToBoard(9,9,board,2,2,blue);
					}
					
					// Update board
					update(9,9, board,32,rota);
					sixController=0;
					
				}
				
				// dice = 6 but you want to move your piece that is alive
				else if(choice==2){
					sixController=1; // dice = 6 ?
					
				}
			}
			// dice == 6 but you want to move your piece that is alive OR dice != 6
			 if(sixController==1){
				
				// movement
				// 4-isAlive[currentPlayer-1]
//				if(playToFirstCell==1){
//					printf("You eat that");
//					if(rota[0]==21){
//						red[0][0]=21;
//						redStart[0]=8;
//						inBoard[1]--;
//								isAlive[1]++;
//					}
//				}
				if(inBoard[currentPlayer-1]>0 ){
					printf("which piece should movee: ");
					scanf("%d",&choosePiece);
					
					
					//yellow
					for(i=11;i<15;i++){
						if(i==choosePiece && currentPlayer==1 ){
							// eger hücredeki piyon sarýysa gideme farklý renkse ye ve onu eve gönder
							if(rota[yellowStart[choosePiece-11]+temp]/10==1){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							//
							else{
								
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==2){
									printf("kirmizi");
								
								//sarý kýrmýzýyý yerse
								if(rota[yellowStart[choosePiece-11]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								
								inBoard[1]--;
								isAlive[1]++;
								}
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==4){
								
								// sarý yeþili yerse
								if(rota[yellowStart[choosePiece-11]+temp]==41){
									green[0][0]=41;
									greenStart[0]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==3){
									
								
								// sarý maviyi yerse
								if(rota[yellowStart[choosePiece-11]+temp]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								
								rota[yellowStart[choosePiece-11]+temp]=rota[yellowStart[choosePiece-11]];
								rota[yellowStart[choosePiece-11]]=0;
								yellowStart[choosePiece-11]+=temp;
								
								if(yellowStart[choosePiece-11]>31  ){
									printf("piyon basariyla sona geldi");
									inBoard[currentPlayer-1]--;
									isFinished[currentPlayer-1]++;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("Sampiyon Yellow");
									}
										
									yellowStart[choosePiece-11]=0;
								}
							}
							//
							
						}
					}
					if(choosePiece<15 && choosePiece>=11 && currentPlayer!=1)
						printf("you can only play your own pawns");
					
					//red
					for(i=21;i<25;i++){
						if(i==choosePiece && currentPlayer==2){
							if(rota[(redStart[choosePiece-21]+temp)%32]/10==2){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==1){
									
								
								if(rota[(redStart[choosePiece-21]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// sarý yeþili yerse
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==4){
									
								
								if(rota[(redStart[choosePiece-21]+temp)%32]==41){
									green[0][0]=41;
									greenStart[0]=24;
																	
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								// sarý maviyi yerse
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==3){
									
								if(rota[(redStart[choosePiece-21]+temp)%32]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								
								
								rota[(redStart[choosePiece-21]+temp)%32]=rota[redStart[choosePiece-21]];
								rota[redStart[choosePiece-21]]=0;
								redStart[choosePiece-21]+=temp;
								if(redStart[choosePiece-21]>31){
									redfinish[choosePiece-21]=1;
								}
								redStart[choosePiece-21]=redStart[choosePiece-21]%32;
								if(redStart[choosePiece-21]>7 && redfinish[choosePiece-21]==1){
									printf("piyon basariyla sona geldi");
									isFinished[currentPlayer-1]++;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("Sampiyon Red");
									}
										
									inBoard[currentPlayer-1]--;
									rota[redStart[choosePiece-21]]=0;
								}
							}
							
						}
					}
					if(choosePiece<25 && choosePiece>=21 && currentPlayer!=2)
						printf("you can only play your own pawns");
					//green
					for(i=41;i<45;i++){
						if(i==choosePiece && currentPlayer==3){
							if(rota[(redStart[choosePiece-41]+temp)%32]/10==4){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==1){
									
								
								if(rota[(greenStart[choosePiece-41]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// sarý yeþili yerse
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==2){
								
								if(rota[greenStart[choosePiece-41]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								inBoard[1]--;
								isAlive[1]++;
								}
								
								// sarý maviyi yerse
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==3){
									
								
								if(rota[(greenStart[choosePiece-41]+temp)%32]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								
								rota[(greenStart[choosePiece-41]+temp)%32]=rota[greenStart[choosePiece-41]];
								rota[greenStart[choosePiece-41]]=0;
								greenStart[choosePiece-41]+=temp;
								if(greenStart[choosePiece-41]>32){
									greenfinish[choosePiece-41]=1;
								}
								greenStart[choosePiece-41]=greenStart[choosePiece-41]%32;
								if(greenStart[choosePiece-41]>23 && greenfinish[choosePiece-41]==1){
									printf("piyon basariyla sona geldi");
									isFinished[currentPlayer-1]+=1;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("Sampiyon Green");
									}
										
									inBoard[currentPlayer-1]--;
									rota[greenStart[choosePiece-41]]=0;
								}
							}
							
						}
						
					}
					if(choosePiece<45 && choosePiece>=41 && currentPlayer!=3)
						printf("you can only play your own pawns");
					
					//blue
					for(i=31;i<35;i++){
						if(i==choosePiece && currentPlayer==4){
							if(rota[(redStart[choosePiece-21]+temp)%32]/10==3){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==1){
									
								if(rota[(blueStart[choosePiece-31]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// sarý yeþili yerse
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==2){
									
								if(rota[blueStart[choosePiece-31]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								inBoard[1]--;
								isAlive[1]++;
								}
								
								// mavi yeþil yerse
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==4){
								
								if(rota[(blueStart[choosePiece-31]+temp)%32]==41){
									green[0][0]=41;
									greenStart[0]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								
								rota[(blueStart[choosePiece-31]+temp)%32]=rota[blueStart[choosePiece-31]];
								rota[blueStart[choosePiece-31]]=0;
								blueStart[choosePiece-31]+=temp;
								if(blueStart[choosePiece-31]>32){
									bluefinish[choosePiece-31]=1;
								}
								blueStart[choosePiece-31]=blueStart[choosePiece-31]%32;
								if(blueStart[choosePiece-31]>15 && bluefinish[choosePiece-31]==1){
									printf("piyon basariyla sona geldi");
									isFinished[currentPlayer-1]+=1;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("Sampiyon Blue");
									}
										
									inBoard[currentPlayer-1]--;
									rota[blueStart[choosePiece-31]]=0;
								}
							}
							
						}
					}
					if(choosePiece<35 && choosePiece>=31 && currentPlayer!=4)
						printf("you can only play your own pawns");
				}
			
	
				else{
					printf("Please, wait this round. \n");
					
				}
				
				//UPDATE
					if(numberOfPlayersCopy==2){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
					}
					if(numberOfPlayersCopy==3){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
					}
					else if(numberOfPlayersCopy==4){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
						blueToBoard(9,9,board,2,2,blue);
					}
					
					update(9,9,board,32,rota);
			
			}
	
		}
		// bu kýsmý 3 piyonun 4 bölmeye geleceði þekilde ayarlamak lazým ve her piyon için
//		board[4][1]=yellowFinished[0];
//		board[4][2]=yellowFinished[1];
//		board[4][3]=yellowFinished[2];
//		
//		board[1][4]=redFinished[0];
		
		printf("current player: %d",currentPlayer);
		displayBoard(9,9,board);
		
		numberOfPlayers--;
		
		if(numberOfPlayers==0)
			numberOfPlayers=numberOfPlayersCopy;
	}

	return 0;
	
}



