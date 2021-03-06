#include<iostream>
#include <cstdlib>
#include<conio.h>
using namespace std;
bool gameOver;

const int width = 25;
const int height = 20;
int x, y;
int fruitx, fruity, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
 

// set up the head and fruits

void setup()
{
	gameOver = false;
	dir = STOP;
	x= width / 2;
	y = height / 2;
	fruitx = rand() % width ;
	fruity = rand() % height;
	score = 0;
	
}


// Draw the boundary  

void draw()
{
	system("cls");
	for (int i=0; i < width+1;  i++)
	     cout<< "#";
	cout<<endl;
	
	
	for (int i=0; i < height; i++)
	{
		for(int j= 0; j < width ; j++)
		{
			
			if (j== 0 )
			    cout << "#";
			if(i == y && j == x)
			    cout << "O";
			else if (i == fruity && j == fruitx)
			     cout << "F";
		    else
			    cout << " ";
			    
			if ( j == width -1 )
			     cout << "#";			
		}
		
		cout << endl;
		
	}
	
	for (int i=0; i < width+1;  i++)
	     cout<< "#";
	cout<<endl;
	cout << " Score:" << score << endl;
	
}

// set up the dirrection in keyboard
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
				dir = LEFT;
				break;
				
			case 'd':
				dir = RIGHT;
				break;
			
			case 'w':
				dir = UP;
				break;
				
			case 's':
				dir = DOWN;
				break;
				
			case 'x':
				gameOver = true;
				break;
		}
	}
	
}


// finally set the logic function according to the Axis
void logic()
{
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
	    case UP:
			y--;
			break;
			
		case DOWN:
			y++;
			break;
			
		default:
			break;
	}
	
	if (x> width || x < 0 || y > height || y < 0)
	    gameOver = true;
	
	if ( x == fruitx && y == fruity)
	{
		score += 10;
		fruitx = rand() % width ;
	    fruity = rand() % height;
		
	}
	
}


// main body 

int main()
{
	setup();
	while(!gameOver)
	{
		draw();
		input();
		logic();
	
	}
	
	
	return 0;
}
