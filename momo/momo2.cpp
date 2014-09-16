#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
int xx[85]={0};
int yy[21]={0};
class Ball{
	
public:
	class Ball * nextPtr;
	int x,y,z;   
	unsigned char s;// 右上 z=1   右下z=2  左下z=3   左上z=4
public:
	
	Ball(){
		nextPtr=nullptr;
		do{
		x= (rand()%78)+1;
		y= (rand()%19)+1;
		z= (rand()%4)+1;
		}while(x!=40&&y!=10);
		xx[x]+=1;
		yy[y]+=1;
		}
	void setNext(class Ball *p){
	nextPtr=p;
	}
	class Ball* getNext(){
		return nextPtr;
	}
	void pon(){//---------------pon
	if(y>19&&x>78){
		z=4;
		return;
	}
	if(y<1&&x>77){
		z=3;
		return ;
	}
	if(y>19&&x<1){
		z=1;
		return ;
	}
	if(y<1&&x<1){
		z=2;
		return;
	}
	if(x<1){
		if(z==4){
			
			z=1;
		}
		if(z==3){
			z=2;
		}
		return;
	}
	if(x>78){
		if(z==2){
			z=3;
		}
		if(z==1){
			z=4;
		}
		return;
	}
	if(y<1){
		if(z==1){
			z=2;
		}
		if(z==4){
			z=3;
		}
		return;
	}
	if(y>19){
		if(z==2){
			z=1;
		}
		if(z==3){
			z=4;
		}
		return;
	}
	}//--------pon

	
	void display(){
		gotoxy(x,y);
		cout<<s;
	}
	void mov(){	  //--------------------mov
		if(z==1){
			s=' ';
			display();
			xx[x]-=1;
			yy[y]-=1;
			x+=1;
			y-=1;
			xx[x]+=1;
			yy[y]+=1;
			s='O';
			display();
			
		}
		else if(z==2){
			s=' ';
			display();
			xx[x]-=1;
			yy[y]-=1;
			x+=1;
			y+=1;
			xx[x]+=1;
			yy[y]+=1;
			s='O';
			display();
			
		}
		else if(z==3){
			s=' ';
			display();
			xx[x]-=1;
			yy[y]-=1;
			x-=1;
			y+=1;
			s='O';
			display();
			xx[x]+=1;
			yy[y]+=1;
		}
		else {
			s=' ';
			display();
			xx[x]-=1;
			yy[y]-=1;
			x-=1;
			y-=1;
			s='O';
			display();
			xx[x]+=1;
			yy[y]+=1;
		}
	if(y>20||x>78||y<1||x<1){
				pon();
				return;
			}
		
		
	}
};
class Man{
public:
	int x,y;
	Man(){
		x=40;
		y=10;
	}
	void setxy(int xxx,int yyy){
		x=xxx;
		y=yyy;
	}
	void xdes(){
		if(x>1)
			x-=2;
	}
	void xins(){
		if(x<79)
			x+=2;
	}
	void ydes(){
		if(y>1)
			y-=2;
	}
	void yins(){
		if(y<19)
			y+=2;
	}
	void display(char s){
		gotoxy(x,y);
		cout<<s;
	}
};
typedef class Ball ball; 
typedef class Man man;
int main(){
	srand(time(NULL));
	ball *x;
	ball *cur;
	man playera ,playerb;
	int mod=1,k=0;
	char s;
	x=new ball();
	int i;
	while(1){
	cout<<"one player , or two player ?: ";
	cin>>mod;
	if(mod==1||mod==2)
		break;
	}
	system("CLS");
	gotoxy(30,8);
	cout<<"Ready";
	for(int j=3;j>0;j--){
		gotoxy(37,8);
	cout<<j;
	Sleep(1000);
	}
	for(int j=0;j<10;j++){
		gotoxy(30+j,8);
		cout<<" ";
	}
	system("CLS");
	for(k=0;;){
		k+=1;

	Sleep(50);
	playera.display(' ');
	if(mod==2)
	playerb.display(' ');
	if(mod==2){
	playera.setxy(30,10);
	playerb.setxy(60,10);
	}
	if(k==50){
		k=0;
		cur=x;
		for(i=0;cur->getNext()!=nullptr;i++,cur=cur->getNext());
		cur->setNext(new ball());
	}
	if(kbhit()){
		s=getch();
	if(s=='+'){
		cur=x;
		for(i=0;cur->getNext()!=nullptr;i++,cur=cur->getNext());
		cur->setNext(new ball());
	}
	if(mod==1){
	if(s=='w'){
		playera.ydes();
	}
	if(s=='s'){
		playera.yins();
	}
	if(s=='a'){
		playera.xdes();
	}
	if(s=='d'){
		playera.xins();
	}
	}
	if(mod==2){
		if(s=='w'){
		playera.ydes();
	}
	if(s=='s'){
		playera.yins();
	}
	if(s=='a'){
		playera.xdes();
	}
	if(s=='d'){
		playera.xins();
	}
		if(s=='8'){
		playerb.ydes();
	}
	if(s=='5'){
		playerb.yins();
	}
	if(s=='4'){
		playerb.xdes();
	}
	if(s=='6'){
		playerb.xins();
	}
	}
	}
	playera.display('a');
	if(mod==2)
	playerb.display('b');
	for(i=0,cur=x;cur!=nullptr;i++,cur=cur->getNext()){
		if(cur->x==playerb.x&&cur->y==playerb.y&&mod==2){
	gotoxy(0,0);
	cout<<" b gameover!!!!!!!!!!!!!!!!!!!!!!!!!!";
	while(1){
		if(kbhit()){
			s=getch();
		if(s=='n'||s=='N')
			return 0;
		}
		//if(s=='y'||s=='Y')
			//break;
	}

	
		}
		if(cur->x==playera.x&&cur->y==playera.y){
	gotoxy(0,0);
	cout<<" a gameover!!!!!!!!!!!!!!!!!!!!!!!!!!";
	while(1){
		if(kbhit()){
			s=getch();
		if(s=='n'||s=='N')
			return 0;
		}
		//if(s=='y'||s=='Y')
			//break;
	}

	
		}}
	for(i=0,cur=x;cur!=nullptr;i++,cur=cur->getNext()){//ball move;
	cur->mov();
	
	
	gotoxy(10,21);
	cout<<"x: "<<cur->x;
	gotoxy(10,22);
	cout<<"y: "<<cur->y;
	gotoxy(10,23);
	cout<<"z: "<<cur->z;
	} //ball move
	
	
	}




	return 0;
}