#include<iostream>
using namespace std;

char board[3][3] = {
					{'1' , '2' , '3'},
					{'4' , '5' , '6'},
					{'7' , '8' , '9'}		
};

char sign;
int player;

void displayBoard(){
	cout<<"\n";
	cout<< " " <<board[0][0]<< " | " <<board[0][1] << " | " <<board[0][2]<<"\n";
	cout<<"---|---|---\n";
	cout<< " " <<board[1][0]<< " | " <<board[1][1] << " | " <<board[1][2]<<"\n";
	cout<<"---|---|---\n";
	cout<< " " <<board[2][0]<< " | " <<board[2][1] << " | " <<board[2][2]<<"\n"	;
}

bool PlaceMarker(int position){
	int row=(position -1)/3;
	int cols=(position-1)%3;
	
	if(board[row][cols]!='X' && board[row][cols]!='O'){
		board[row][cols]=sign;
		return true;
	}else{
		return false;
	}
}

bool winner(){
	for(int i=0; i<3; i++){
		if((board[i][0]==board[i][1] && board[i][1]==board[i][2]) ||
		   (board[0][i]==board[1][i] && board[1][i]==board[2][i])){
		   	return true;
		   }
	}
	if((board[0][0]==board[1][1] &&board[1][1]==board[2][2])||
	   (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
	   	return true;
	   }
	   
	return false;
}

bool boardfull(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]!='X' &&board[i][j]!='O'){
				return false;
			}
		}
	}
	return true;
}

void switchplayer(){
	if(sign=='X'){
		sign='0';
	}else{
		sign='X';
	}
	player = ( player==1 ) ? 2:1 ;
}
void playgame(){
	
	int position; 
	displayBoard();
	
	while(true){
	cout<<"Player"<<player<<"("<<sign<<") enter your position (1-9): ";
	cin>>position;
	
	if(position<1 || position>9 || !PlaceMarker(position)){
		cout<<"Invalid position \n";
		continue;
	}
	
	displayBoard();
	
	if(winner()){
		cout<<"Player"<<player<<"wins\n";
		break;
	}
	
        if (boardfull()) {
            cout << "It's a draw!\n";
            break;
        }
	switchplayer();
	}
}
int main(){
	
	cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> sign;
    
    while (sign != 'X' && sign != 'O') {
        cout << "Invalid choice! Please select X or O: ";
        cin >> sign;
    }
    
    player = 1;
    playgame();
    
	return 0;
}
