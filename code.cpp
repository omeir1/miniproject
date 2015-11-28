#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>



int panel[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,computer;


void main_menu();
void go(int n);
void begin_game();
void tie_checker();
void draw_board();
void player_1();
void put_X_O(char ch,int pos);
COORD coord={0,0};


void gotoxy(int x,int y){
	
	coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



main(){
	
	system("cls");
	main_menu();
	getch();

}

void main_menu(){
	
	int choice;
	system("cls");
	system("COLOR 1C"); 		//selecting color of background and text to be displayed
 	printf("\n-----START MENU-----");
 	printf("\n1 : Play with X");
 	printf("\n2 : Play with O");
	printf("\n3 : Exit");
 	printf("\nEnter your choice:>  ");
 	scanf("%d",&choice);
 	turn = 1;
 	
	switch (choice){
 		
  		case 1:
   			player = 1;
   			computer = 0;
   			player_1();
   			break;
  		case 2:
   			player = 0;
   			computer = 1;
   			begin_game();
   			break;
  		case 3:
   			exit(1);
  		default:
   			main_menu();
 }
}

int make2(){
	
 	if(panel[5] == 2)
  		return 5;
 	if(panel[2] == 2)
  		return 2;
 	if(panel[4] == 2)
  		return 4;
 	if(panel[6] == 2)
  		return 6;
 	if(panel[8] == 2)
  		return 8;
  		
return 0;
}

int make4(){
	
 	if(panel[1] == 2)
  		return 1;
 	if(panel[3] == 2)
  		return 3;
 	if(panel[7] == 2)
  		return 7;
 	if(panel[9] == 2)
  		return 9;
 
return 0;
}

int posswin(int p){
	

int i;
int check_val,pos;

	if(p == 1)
  		check_val = 18;
 	else
  		check_val = 50;

 i = 1;
while(i<=9) //row check
{
  	if(panel[i] * panel[i+1] * panel[i+2] == check_val){
  		if(panel[i] == 2)
    		return i;
   		if(panel[i+1] == 2)
    		return i+1;
   	if(panel[i+2] == 2)
    		return i+2;
  }
  
	i+=3;
 }

 	i = 1;
 	while(i<=3) //column check
	 {
  		if(panel[i] * panel[i+3] * panel[i+6] == check_val){
  			if(panel[i] == 2)
    			return i;
   			if(panel[i+3] == 2)
    			return i+3;
   			if(panel[i+6] == 2)
    			return i+6;
  }
  
  i++;
 }

 if(panel[1] * panel[5] * panel[9] == check_val){
 	if(panel[1] == 2)
   		return 1;
  	if(panel[5] == 2)
   		return 5;
  	if(panel[9] == 2)
   		return 9;
 }

 if(panel[3] * panel[5] * panel[7] == check_val)
 {
  	if(panel[3] == 2)
   		return 3;
  	if(panel[5] == 2)
   		return 5;
  	if(panel[7] == 2)
   		return 7;
 }
 
 return 0;
}

void go(int n){
	
if(turn % 2)
  	panel[n] = 3;
else
  	panel[n] = 5;
turn++;
}

void player_1(){
	
 	int pos;

 	tie_checker();
 	draw_board();
 	gotoxy(30,18);
 	printf("Your Turn :> ");
 	scanf("%d",&pos);

 if(panel[pos] != 2)
  	player_1();

 if(pos == posswin(player)){
 	
  	go(pos);
  	draw_board();
 	gotoxy(30,20);
 		system("cls");		//clearing screen to displa result 
 		system("COLOR 1A");				//selecting color of panel showing result
  		printf("\t\t\t\tPlayer Wins\n\t\t\t  -----GAME OVER-----");
  	getch();
  	exit(0);
 }

go(pos);
draw_board();
begin_game();
}

void begin_game(){
	
 
if(posswin(computer)){
	
  go(posswin(computer));
  flag = 1;
 }
else
if(posswin(player))
  	go(posswin(player));
else
if(make2())
  	go(make2());
else
  	go(make4());
 	draw_board();

if(flag){
	
  	gotoxy(30,20);
  	system("cls");			//clearing screen to displa result 
  	system("COLOR 4F");					//selecting color of panel showing result
  	printf("\t\t\t      Computer wins\n\t\t\t  -----GAME OVER-----");
  	getch();
 }
else
  	player_1();
}

void tie_checker()
{
 	if(turn > 9){
 		
  		gotoxy(30,20);
  		system("cls");			//clearing screen to displa result 
  		system("COLOR 7C");					//selecting color of panel showing result
  		printf("\t\t\t\tGame Draw\n\t\t\t  -----GAME OVER-----");
  		getch();
  	exit(0);
 }
}

void draw_board(){
 	int j;

 	for(j=9;j<17;j++){
  		gotoxy(35,j);
  		printf("|       |");
 }
 	gotoxy(28,11);
 	printf("-----------------------");
 	gotoxy(28,14);
 	printf("-----------------------");

 	for(j=1;j<10;j++){
  		if(panel[j] == 3)
   		put_X_O('X',j);
  	else
  		if(panel[j] == 5)
   			put_X_O('O',j);
 }
}

void put_X_O(char ch,int pos){
int m;
int x = 31, y = 10;

m = pos;

if(m > 3){
	
  	while(m > 3){
  		
   		y += 3;
   		m -= 3;
  }
 }
if(pos % 3 == 0)
  	x += 16;
else
 {
  	pos %= 3;
  	pos--;
  	while(pos)
  {
   		x+=8;
   		pos--;
  }
 }
gotoxy(x,y);
printf("%c",ch);
}
