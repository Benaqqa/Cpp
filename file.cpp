#include <graphics.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <conio.h>
const int N=50;
const int R=2;
using namespace std;


struct node{                                  //node definition
	int num;
	float x;
	float y;
	int theta;
	float speed;
	int c;
	//int mass;
	node *next;
};

node* create(float x,float y,int theta,float speed,int c,int num){       //memory allocation func
	node* neww = (node*)malloc(sizeof(node));
	if (neww != NULL){
		neww->x=x;
		neww->y=y;
		neww->theta= theta;
		neww->speed=speed;
		neww->c=c;
		neww->num = num;
		neww->next=NULL;
	}
	return neww;
	
}

void insert(node **rootptr,float x,float y,float speed,int theta,int c,int num){      //insertion defintion
	
	if (*rootptr == NULL){
		*rootptr = create(x,y,theta,speed,c,num);
		return;
	}
	return insert(&((*rootptr)->next),x,y,speed,theta,c,num);
}



int abs(int a){
	if(a>0){
		return a;
	}
	return -a;
}
int reflection(int theta, char t) {
    if (theta >= 90 && theta < 270) {  // Corrected range check
        if (theta <= 180) {
            return (t == 'x') ? (180 - theta) : (360 - theta);
        } else {
            return (t == 'x') ? (540 - theta) : (360 - theta);
        }
    } else {
        return (t == 'y') ? (360 - theta) : (180 - theta);
    }
}

int touch(double co[N][4],int i,int j){                     //verify if we have collision
    if(sqrt((pow((co[i][0]-co[j][0]),2))+(pow((co[i][1]-co[j][1]),2))<=2*R)){
        return 1;
    }
    return 0;

}                                                                           
                                                              
void collision(double co[N][4],int i){                //collision control
	for (int j=0;j<N;j++){
		if (j==i){
			continue;
		}
		if(touch(co,i,j)){        
			int x = co[i][3];                                   
			co[i][3] = co[j][3];
			co[j][3] = x;	                                                      
		                                                        
	    } 
	    
	}                                                        
}                                                               
                                                         
void mymove(node *root){                   //movement simulation
	
	setcolor(15);
	rectangle(100,100,500,500);
	float t = root->theta*M_PI/180;

	//collision(co,i);
	
	int colors[3] = {2,3,4};
	if (root->x+(root->speed)*cos(t)>499){
		root->x=499;
		root->theta = reflection(root->theta,'x');
		
		
	}else if (root->x+(root->speed)*cos(t)<101){
		root->x=101;
		root->theta = reflection(root->theta,'x');
		
		
	}else{
		
		root->x+=(root->speed)*cos(t);
	}
	
	
	if (root->y-(root->speed)*sin(t)>499){
		root->y=499;
		root->theta = reflection(root->theta,'y');
		
	}else if (root->y-(root->speed)*sin(t)<101){
		root->y=101;
		root->theta = reflection(root->theta,'y');
        	
	}else{
		root->y-=(root->speed)*sin(t);
	}
	
	setcolor(colors[root->c]);
	setfillstyle(SOLID_FILL,colors[root->c]);
	fillellipse(root->x,root->y,R,R);
	
	
}
main(){
	
	
	node* root = NULL;
	int colors[3] ={2,3,4};
	                                
	
	initwindow(800,800);
	
	
    
	for (int i=0;i<N;i++){                             //object creation and direction association
		setcolor(15);
		rectangle(100,100,500,500);
		
		float x=rand()%399 +101, y=rand()%399 +101;
		int theta = rand()%360;
		float speed = 6;           //(rand()%2)+2
		
		int c = rand()%3;
		setcolor(colors[c]);
		setfillstyle(SOLID_FILL,colors[c]);
		fillellipse((int)x,(int)y,R,R);
		insert(&root,x,y,speed,theta,c,i);
		
	}

	while(true){
		node * current = root;
		cleardevice();
		//system("cls");
		while(current){
			
			//printf("ball : %d speed: %f angle: %d\n",current->num,current->speed,current->theta);
			float x = current->x;
			float y=current->y;
			int theta = current->theta;
			
			
			mymove(current);
			current = current->next;
		}
		delay(1);
		
	}
	
	getch();
	
}
