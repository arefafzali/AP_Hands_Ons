
#include "rsdl.hpp"
#include <iostream>
//#include <cstdlib>

using namespace std;

int main(){
	Window w(1212,818,"game");
	Event event;
	int x=(rand()%1212)+1,y=(rand()%818)+1;
	while(event.type()!=QUIT){
		w.draw_bg("Football-Ground.png",0,0);
		w.draw_png("Ball.png",x,y,52,58);
		w.update_screen();
		event=w.pollForEvent();
		if(event.type()==KEY_PRESS)
			switch(event.pressedKey()){
				case 'w':
					if(y<766&&y>0)
						y=y-10;
					else
						y=y+10;
					break;
				case 'a':
					if(x<1154&&x>0)
						x=x-10;
					else
						x=x+10;
					break;
				case 's':
					if(y<766&&y>0)
						y=y+10;
					else
						y=y-10;
					break;
				case 'd':
					if(x<1154&&x>0)
						x=x+10;
					else
						x=x-10;
					break;
			}
		if(event.type()==KEY_PRESS)
			switch(event.pressedKey()){
				case 'i':
					while(y<766&&y>0){
						y=y-10;
						w.clear();
						w.draw_bg("Football-Ground.png",0,0);
						w.draw_png("Ball.png",x,y,52,58);
						w.update_screen();
					}
					y=y+10;
					break;
				case 'j':
					while(x<1154&&x>0){
						x=x-10;
						w.clear();
						w.draw_bg("Football-Ground.png",0,0);
						w.draw_png("Ball.png",x,y,52,58);
						w.update_screen();
					}
					x=x+10;
					break;
				case 'k':
					while(y<766&&y>0){
						y=y+10;
						w.clear();
						w.draw_bg("Football-Ground.png",0,0);
						w.draw_png("Ball.png",x,y,52,58);
						w.update_screen();
					}
					y=y-10;
					break;
				case 'l':
					while(x<1154&&x>0){
						x=x+10;
						w.clear();
						w.draw_bg("Football-Ground.png",0,0);
						w.draw_png("Ball.png",x,y,52,58);
						w.update_screen();
					}
					x=x-9;
					break;
			}
		w.clear();
		w.draw_bg("Football-Ground.png",0,0);
		w.draw_png("Ball.png",x,y,52,58);
		w.update_screen();
		//1150 10 441 321
		if((x>=1149&&(y<=442&&y>=320))||(x<=10&&(y<=442&&y>=320))){
			w.draw_png("Goal.png",0,0,1212,818);
			w.update_screen();
			Delay(2000);
			w.clear();
			w.draw_bg("Football-Ground.png",0,0);
			x=(rand()%1212)+1,y=(rand()%818)+1;
			w.draw_png("Ball.png",x,y,52,58);
			w.update_screen();
		}	
	}
	return 0;
}