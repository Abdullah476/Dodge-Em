//============================================================================
// Name        : game.cpp
// Author      : Abdullah
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include <fstream>	 //it contains implementation of ofstream and ifstream
#include<string>
#include<cmath> 	// for basic math functions such as cos, sin, sqrt
#include<ctime>
#include<cstdlib>
using namespace std;
	
	//Rndom Car Position
	int c1;		//Player Car
	int c2;		//1st Opponent
	int c3;		//2nd Opponent
	
	//Player Car
	float px = 675; 
	float py = 1230;
	float pwidth = 15; 
	float pheight = 10;
	float* pcolor = colors[SANDY_BROWN]; 
	float pradius = 5.0;
	
	//(1st) Opponent Car
	float x = 125; 
	float y = 675;
	float width = 15; 
	float height = 10;
	float* color = colors[SKY_BLUE]; 
	float radius = 5.0;
	
	//(2nd) Opponent Car
	float tx = 675; 
	float ty = 120;
	float twidth = 15; 
	float theight = 10;
	float* tcolor = colors[GRAY]; 
	float tradius = 5.0;
	
	
	//For lives
	int lives = 3;
	
	//For Food
	int fcolor[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};		//Top right
	int f1color[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};	//Bottom right
	int f2color[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};	//Bottom Left
	int f3color[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};	//Top Left
	
	
	//For Cars Motion
	float s1;					//User Car
	float s2;					//Opponent Car
	float s3;					//2nd Opponent Car
	
	
	//Defining Speed for Levels
	float speed1 = 5.0;
	bool overSpeed = false;
	
	//Food Re Drawing
	bool reDraw = false;	
	
	//For Gameover
	bool gameEnd = false;
	
	//For Gamewin
	bool win = false;				
	
	//For Scores
	int score = 0;					//For Score Display
	int *high_Scores = new int[10]; 			//scores array
	string show_highscore;
	int newHighScore;
	
	//Random Car Motion
	int r1;				//For 1st Opponent
	int r2;
	
	int r11;			//For 2nd Opponent
	int r22;
	
	//For Level
	int level = 4;					//For Displaying The Level
	int levelCheck = 80;			//For Level Checkking Purpose
	
	//For Re-setting the Game
	bool reset = false; 
	
	//Opponent Car Movement
	bool movement = false;
	bool movement1 =  false;
	
	//For Boost
	bool cBoost = false;	
	
	//For Menu
	bool pmenu = false;				//For Displaying Pause Menu
	bool menu = true;				//For Displaying Menu
	bool start = false;				//For Start In Menu
	bool highScore = false;			//For Highscore In Menu
	bool help = false;				//For Help In Menu
	bool pcheck = false;			//Used for Checking That Game Is Paused or Not
	bool resume = false;			//Used to Check Whether The User Resume In The Menu or Not
	bool toMenu = false;			//Used For Back In Menu
	bool startCheck = false;		//Used To Check Whether Game Started or Not
	bool re = false;				//Used  After Gameover or End
	
	//Writing To file 
	bool write1 = false;			//If true than write to file
	
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;

/***************************************************************************************************************************/

void DisplayGameOver()
{
	if (gameEnd)
	{
			s1 = 0;
			s2 = 0;
			s3 = 0;
			// G
			DrawLine(310,1240,360,1240,10,colors[RED]);
			DrawLine(310,1240,310,1150,10,colors[RED]);
			DrawLine(310,1150,360,1150,10,colors[RED]);
			DrawLine(360,1150,360,1190,10,colors[RED]);
			DrawLine(360,1190,335,1190,10,colors[RED]);
			
			//A
			DrawLine(390,1240,390,1150,10,colors[RED]);
			DrawLine(390,1240,440,1240,10,colors[RED]);
			DrawLine(440,1240,440,1150,10,colors[RED]);
			DrawLine(390,1195,440,1195,10,colors[RED]);
			
			//M
			DrawLine(470,1240,470,1150,10,colors[RED]);
			DrawLine(470,1240,490,1240,10,colors[RED]);
			DrawLine(490,1240,490,1200,10,colors[RED]);
			DrawLine(490,1200,510,1200,10,colors[RED]);
			DrawLine(510,1240,510,1200,10,colors[RED]);
			DrawLine(510,1240,530,1240,10,colors[RED]);
			DrawLine(530,1240,530,1150,10,colors[RED]);
			
			//E
			DrawLine(560,1240,560,1150,10,colors[RED]);
			DrawLine(560,1240,610,1240,10,colors[RED]);
			DrawLine(560,1150,610,1150,10,colors[RED]);
			DrawLine(560,1195,610,1195,10,colors[RED]);
			
			
			//O
			DrawLine(660,1240,660,1150,10,colors[RED]);
			DrawLine(660,1240,710,1240,10,colors[RED]);
			DrawLine(660,1150,710,1150,10,colors[RED]);
			DrawLine(710,1240,710,1150,10,colors[RED]);
			
			//V
			DrawLine(740,1240,760,1150,10,colors[RED]);
			DrawLine(760,1150,780,1240,10,colors[RED]);
			
			//E
			DrawLine(810,1240,810,1150,10,colors[RED]);
			DrawLine(810,1240,860,1240,10,colors[RED]);
			DrawLine(810,1150,860,1150,10,colors[RED]);
			DrawLine(810,1195,860,1195,10,colors[RED]);
			
			//R
			DrawLine(890,1240,890,1150,10,colors[RED]);
			DrawLine(890,1240,925,1240,10,colors[RED]);
			DrawLine(925,1240,925,1200,10,colors[RED]);
			DrawLine(890,1200,925,1200,10,colors[RED]);
			DrawLine(890,1200,925,1150,10,colors[RED]);
			
	}
}

/***************************************************************************************************************************/

void DisplayWin()
{
	if (win)
	{
		s1 = 0;
		s2 = 0;
		s3 = 0;
		//Y
		DrawLine(310,1240,330,1200,10,colors[RED]);
		DrawLine(330,1200,350,1240,10,colors[RED]);
		DrawLine(330,1200,330,1150,10,colors[RED]);
		
		//O
		DrawLine(380,1240,380,1150,10,colors[RED]);
		DrawLine(380,1240,420,1240,10,colors[RED]);
		DrawLine(380,1150,420,1150,10,colors[RED]);
		DrawLine(420,1240,420,1150,10,colors[RED]);
		
		//U
		DrawLine(450,1240,450,1150,10,colors[RED]);
		DrawLine(450,1150,490,1150,10,colors[RED]);
		DrawLine(490,1240,490,1150,10,colors[RED]);
		
		//W
		DrawLine(540,1240,540,1150,10,colors[RED]);
		DrawLine(540,1150,590,1150,10,colors[RED]);
		DrawLine(590,1240,590,1150,10,colors[RED]);
		DrawLine(565,1190,565,1150,10,colors[RED]);
		
		//O
		DrawLine(620,1240,620,1150,10,colors[RED]);
		DrawLine(620,1240,660,1240,10,colors[RED]);
		DrawLine(620,1150,660,1150,10,colors[RED]);
		DrawLine(660,1240,660,1150,10,colors[RED]);
		
		//N
		DrawLine(690,1240,690,1150,10,colors[RED]);
		DrawLine(690,1240,740,1150,10,colors[RED]);
		DrawLine(740,1240,740,1150,10,colors[RED]);
				
	}
}

/***************************************************************************************************************************/

void DisplayCars()
{
	if ((menu == false && pmenu == false) && (start == true || resume == true))
	{
	
		s1 = speed1;
		if (level == 1)
			s2 = speed1;
		else if (level == 2)
			s2 = speed1;
		else if (level == 3)
			overSpeed = true; 
		else if (level == 4)
		{	
			overSpeed = false;
			s2 = speed1;
		}
		// Drawing player car
		DrawRoundRect(px,py,pwidth,pheight,pcolor,pradius); // bottom left tyre
		DrawRoundRect(px+pwidth*3,py,pwidth,pheight,pcolor,pradius); // bottom right tyre
		DrawRoundRect(px+pwidth*3,py+pheight*4,pwidth,pheight,pcolor,pradius); // top right tyre
		DrawRoundRect(px,py+pheight*4,pwidth,pheight,pcolor,pradius); // top left tyre
		DrawRoundRect(px, py+pheight*2, pwidth, pheight, pcolor, pradius/2); // body left rect
		DrawRoundRect(px+pwidth, py+pheight, pwidth*2, pheight*3, pcolor, pradius/2); // body center rect
		DrawRoundRect(px+pwidth*3, py+pheight*2, pwidth, pheight, pcolor, pradius/2); // body right rect

		// Drawing (1st) Opponent car
		DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
		DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
		DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
		DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
		DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
		DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
		DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
	
		if (level == 4)
		{
			s3 = speed1;
			// Drawing (2nd) Opponent car
			DrawRoundRect(tx,ty,twidth,theight,tcolor,tradius); // bottom left tyre
			DrawRoundRect(tx+twidth*3,ty,twidth,theight,tcolor,tradius); // bottom right tyre
			DrawRoundRect(tx+twidth*3,ty+theight*4,twidth,theight,tcolor,tradius); // top right tyre
			DrawRoundRect(tx,ty+theight*4,twidth,theight,tcolor,tradius); // top left tyre
			DrawRoundRect(tx, ty+theight*2, twidth, theight, tcolor, tradius/2); // body left rect
			DrawRoundRect(tx+twidth, ty+theight, twidth*2, theight*3, tcolor, tradius/2); // body center rect
			DrawRoundRect(tx+twidth*3, ty+theight*2, twidth, theight, tcolor, tradius/2); // body right rect
		}
	
	}
}

/***************************************************************************************************************************/

void DrawArena()
{
	if ((menu == false && pmenu == false) && (start == true || resume == true))
	{
	// Drawing Arena (1)
	int gap_turn = 120;
	int sx = 100;
	int sy = 90;
	int swidth = 1200/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[TEAL];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+1210, swidth, sheight, scolor); // top right
	DrawRectangle(sx, sy+1210, swidth, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down


	// Drawing Arena (2)
	int tx = 200;
	int ty = 190;
	int twidth = 1000/2 - gap_turn/2; // half width
	DrawRectangle(tx+40, ty, twidth-40, sheight, scolor); // bottom left
	DrawRectangle(tx + twidth + gap_turn, ty, twidth-40, sheight, scolor); // bottom right
	DrawRectangle(tx+twidth*2+gap_turn-40, ty+sheight, sheight*2, twidth, scolor); // right down
	DrawRectangle(tx+twidth*2+gap_turn-40, ty+sheight+twidth+gap_turn, sheight*2, twidth, scolor); // right up
	DrawRectangle(tx+ twidth + gap_turn, ty+1010, twidth-40, sheight, scolor); // top right
	DrawRectangle(tx+40, ty+1010, twidth-40, sheight, scolor); // top left
	DrawRectangle(tx-sheight*2+40, ty+sheight+twidth+gap_turn, sheight*2, twidth, scolor); // left up
	DrawRectangle(tx-sheight*2+40, ty+sheight, sheight*2, twidth, scolor); // left down

	
	// Drawing Arena (3)
	int ux = 300;
	int uy = 290;
	int uwidth = 800/2 - gap_turn/2; // half width
	DrawRectangle(ux+80, uy, uwidth-80, sheight, scolor); // bottom left
	DrawRectangle(ux + uwidth + gap_turn, uy, uwidth-80, sheight, scolor); // bottom right
	DrawRectangle(ux+uwidth*2+gap_turn-80, uy+sheight, sheight*2, uwidth, scolor); // right down
	DrawRectangle(ux+uwidth*2+gap_turn-80, uy+sheight+uwidth+gap_turn, sheight*2, uwidth, scolor); // right up
	DrawRectangle(ux+ uwidth + gap_turn, uy+810, uwidth-80, sheight, scolor); // top right
	DrawRectangle(ux+80, uy+810, uwidth-80, sheight, scolor); // top left
	DrawRectangle(ux-sheight*2+80, uy+sheight+uwidth+gap_turn, sheight*2, uwidth, scolor); // left up
	DrawRectangle(ux-sheight*2+80, uy+sheight, sheight*2, uwidth, scolor); // left down
	
	
	// Drawing Arena (4)
	int vx = 400;
	int vy = 390;
	int vwidth = 600/2 - gap_turn/2; // half width
	DrawRectangle(vx+120, vy, vwidth-120, sheight, scolor); // bottom left
	DrawRectangle(vx + vwidth + gap_turn, vy, vwidth-120, sheight, scolor); // bottom right
	DrawRectangle(vx+vwidth*2+gap_turn-120, vy+sheight, sheight*2, vwidth, scolor); // right down
	DrawRectangle(vx+vwidth*2+gap_turn-120, vy+sheight+vwidth+gap_turn, sheight*2, vwidth, scolor); // right up
	DrawRectangle(vx+ vwidth + gap_turn, vy+610, vwidth-120, sheight, scolor); // top right
	DrawRectangle(vx+120, vy+610, vwidth-120, sheight, scolor); // top left
	DrawRectangle(vx-sheight*2+120, vy+sheight+vwidth+gap_turn, sheight*2, vwidth, scolor); // left up
	DrawRectangle(vx-sheight*2+120, vy+sheight, sheight*2, vwidth, scolor); // left down
	
	
	// Drawing Arena (5)
	gap_turn = 0;
	int wx = 500;
	int wy = 490;
	int wwidth = 400/2 - gap_turn/2; // half width
	DrawRectangle(wx+160, wy+170, wwidth-160, sheight, scolor); // bottom left
	DrawRectangle(wx + wwidth + gap_turn, wy+170, wwidth-160, sheight, scolor); // bottom right
	DrawRectangle(wx+wwidth*2+gap_turn-160, wy+sheight+170, sheight*2, wwidth-130, scolor); // right down
	DrawRectangle(wx+wwidth*2+gap_turn-160, wy+sheight+wwidth+gap_turn+10, sheight*2, wwidth-140, scolor); // right up
	DrawRectangle(wx+ wwidth + gap_turn, wy+280, wwidth-160, sheight, scolor); // top right
	DrawRectangle(wx+160, wy+280, wwidth-160, sheight, scolor); // top left
	DrawRectangle(wx-sheight*2+160, wy+sheight+wwidth+gap_turn+10, sheight*2, wwidth-140, scolor); // left up
	DrawRectangle(wx-sheight*2+160, wy+sheight+170, sheight*2, wwidth-130, scolor); // left down
	}
}

/***************************************************************************************************************************/

void DrawFood()
{
	if ((menu == false && pmenu == false) && (start == true || resume == true))
	{
		if (reDraw)				//Re Drawing The Food
	{
		for(int k = 0 ; k < 20 ; k++)
			fcolor[k] = 1;
		for(int k = 0 ; k < 20 ; k++)
			f1color[k] = 1;
		for(int k = 0 ; k < 20 ; k++)
			f2color[k] = 1;
		for(int k = 0 ; k < 20 ; k++)
			f3color[k] = 1;
			
		reDraw = false;
	}
	
	{	//Drawing food
			int k = 0; 
			for (int i = 1230 ; i >= 830 ; i-= 100 )	//Top right
			{
				for (int j = 790 ; j <= 1210 ; j+= 140,k++)
				{	
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py + 10 == i || py + 15 == i) && (fcolor[k] == 1))	
					{	
						score++;
						levelCheck--;
					}
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py + 10 == i || py + 15 == i))	
						fcolor[k] = 0;
					if (fcolor[k])
						DrawSquare( j , i ,22,colors[DARK_SALMON]);	
				}
			}
			
			int k1 = 0;
			for (int i = 120 ; i <= 620 ; i+= 100 )		//Bottom right
			{
				for (int j = 790 ; j <= 1210 ; j+= 140,k1++)
				{	
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py + 10 == i || py + 15 == i) && (f1color[k1] == 1))	
					{	
						score++;
						levelCheck--;
					}
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py + 10 == i || py + 15 == i))
						f1color[k1] = 0;
					if (f1color[k1])
						DrawSquare( j , i ,22,colors[DARK_SALMON]);
				}
			}

			int k2 = 0;
			for (int i = 120 ; i <= 620 ; i+= 100 )		//Bottom Left
			{
				for (int j = 125 ; j <= 545 ; j+= 140,k2++)
				{
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py - 10 == i || py - 15 == i) && (f2color[k2] == 1))	
					{	
						score++;
						levelCheck--;
					}
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px + 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py - 10 == i || py - 15 == i))	
						f2color[k2] = 0;
					if (f2color[k2])
						DrawSquare( j , i ,22,colors[DARK_SALMON]);
				}
			}
			
			int k3 = 0;
			for (int i = 1230 ; i >= 830 ; i-= 100 )	//Top Left
			{
				for (int j = 125 ; j <= 545 ; j+= 140,k3++)
				{	
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px - 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py - 10 == i || py - 15 == i) && (f3color[k3] == 1))
					{	
						score++;
						levelCheck--;
					}
					if ((px - 15 == j || px - 10 == j || px - 5 == j || px == j || px - 10 == j || px + 15 == j) && (py - 15 == i || py - 10 == i || py - 5 == i || py == i || py - 10 == i || py - 15 == i))	
						f3color[k3] = 0;
					if (f3color[k3])
						DrawSquare( j , i ,22,colors[DARK_SALMON]);
				}	
			}
	}
	}
}

/***************************************************************************************************************************/

void DrawLives()
{
	if ((menu == false && pmenu == false) && (start == true || resume == true))
	{
		if (lives == 3)
			DrawString( 300, 1375, "Lives= 03", colors[TEAL]);
		else if (lives == 2)
			DrawString( 300, 1375, "Lives= 02", colors[TEAL]);
		else if (lives == 1)
			DrawString( 300, 1375, "Lives= 01", colors[TEAL]);
		else if (lives == 0)
			DrawString( 300, 1375, "Lives= 00", colors[TEAL]);
	}
}

/***************************************************************************************************************************/

void DrawScores()
{
	if ((menu == false && pmenu == false)  && (start == true || resume == true))
		DrawString(650, 1375, "Score: "+to_string(score), colors[TEAL]);
}

/***************************************************************************************************************************/

void DrawLevel()
{
	if ((menu == false && pmenu == false) && (start == true || resume == true))
	{
		if (level == 1)
			DrawString(1000, 1375, "Level: 01", colors[TEAL]);
		else if (level == 2)
			DrawString(1000, 1375, "Level: 02", colors[TEAL]);
		else if (level == 3)
			DrawString(1000, 1375, "Level: 03", colors[TEAL]);
		else if (level == 4)
			DrawString(1000, 1375, "Level: 04", colors[TEAL]);
	}
		
}

/***************************************************************************************************************************/

void DrawMenu()
{
	if (menu == true)
	{
		DrawString(600, 1000, "START NEW GAME", colors[CRIMSON]);
		DrawString(600, 900, "HIGH SCORES", colors[CRIMSON]);
		DrawString(600, 800, "HELP", colors[CRIMSON]);
		DrawString(600, 700, "EXIT", colors[CRIMSON]);
		
	}

	if (pmenu == true)
	{
		DrawString(600, 1100, "RESUME GAME", colors[CRIMSON]);
		DrawString(600, 1000, "START NEW GAME", colors[CRIMSON]);
		DrawString(600, 900, "HIGH SCORES", colors[CRIMSON]);
		DrawString(600, 800, "HELP", colors[CRIMSON]);
		DrawString(600, 700, "EXIT", colors[CRIMSON]);
		
	}
	
	if (toMenu == true)
	{
			DrawString(450, 1050, "BACK", colors[TEAL]);
	}

	if (help == true)
	{
		DrawString(600, 1000, "Press \"Up Arrow Key\" To Move \"Up\" Through Gap", colors[TEAL]);
		DrawString(600, 900, "Press \"Down Arrow Key\" To Move \"Down\" Through Gap", colors[TEAL]);
		DrawString(600, 800, "Press \"Right Arrow Key\" To Move \"Right\" Through Gap", colors[TEAL]);
		DrawString(600, 700, "Press \"Left Arrow Key\" To Move \"Left\" Through Gap", colors[TEAL]);
		DrawString(600, 600, "Press \"Space Bar\" For \"Boost\"", colors[TEAL]);
		DrawString(600, 500, "Press \"P\" For \"Pause Game\"", colors[TEAL]);
	}

}

/***************************************************************************************************************************/

void GameReset()
{
	{	//Re-set The Game
		if (reset == true)
		{
			gameEnd = false;
			win = false;
			reset = false;
			//	Moving User Car To Initial Positions
			px = 675;
			py = 1230;
			
			//	Moving Opponent Car To Initial Positions 
			x = 125; 
			y = 675;
			
			levelCheck = 80;
			lives = 3;
			score = 0;
			level = 1;
			win = false;
			gameEnd = false;
			reDraw = true;
			s1 = 0.0;
			s2 = 0.0;
			s3 = 0.0;
			speed1 = 5.0;
			
			//For Boost
			cBoost = false;	
			overSpeed = false;
	
			//For Menu
			pmenu = false;				
			menu = true;				
			start = false;				
			highScore = false;			
			help = false;				
			pcheck = false;			
			resume = false;			
			toMenu = false;			
			startCheck = false;	
		}
		
	}
}

/***************************************************************************************************************************/

void PlayerMovement()
{
	{ 	// Movement Of Player Car
		{	//Extreme Road
			if ((px >= 125 && px <= 1210) && (py == 120))	//In bottom road 
			{
				px -= s1;
				if((cBoost == true) && (px - 10 >= 125))
				{
					s1 = 10;
					px -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 125) && (py >= 120 && py <= 1230)) //left vertival movement
			{
				py += s1;
				if((cBoost == true) && (py + 10 <= 1230))
				{
					s1 = 10;
					py += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px >= 125 && px <= 1210) && (py == 1230)) //In top road
			{
				px += s1;
				if((cBoost == true) && (px + 10 <= 1210))
				{
					s1 = 10;
					px += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 1210) && (py >= 120 && py <= 1230)) //right vertical movement
			{
				py -= s1;
				if((cBoost == true) && (py - 10 >= 120))
				{
					s1 = 10;
					py -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
		}
		{	//2nd Extreme Road
			if ((px >= 265 && px <= 1070) && (py == 220))	//In bottom road 
			{
				px -= s1;
				if((cBoost == true) && (px - 10 >= 265))
				{
					s1 = 10;
					px -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 265) && (py >= 220 && py <= 1130)) //left vertival movement
			{
				py += s1;
				if((cBoost == true) && (py + 10 <= 1130))
				{
					s1 = 10;
					py += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px >= 265 && px <= 1070) && (py == 1130)) //In top road
			{
				px += s1;
				if((cBoost == true) && (px + 10 <= 1070))
				{
					s1 = 10;
					px += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 1070) && (py >= 220 && py <= 1130)) //right vertical movement
			{
				py -= s1;
				if((cBoost == true) && (py - 10 >= 220))
				{
					s1 = 10;
					py -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
		}
		{	//3rd Extreme Road
			if ((px >= 405 && px <= 930) && (py == 320))	//In bottom road 
			{
				px -= s1;
				if((cBoost == true) && (px - 10 >= 405))
				{
					s1 = 10;
					px -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 405) && (py >= 320 && py <= 1030)) //left vertival movement
			{
				py += s1;
				if((cBoost == true) && (py + 10 <= 1030))
				{
					s1 = 10;
					py += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px >= 405 && px <= 930) && (py == 1030)) //In top road
			{
				px += s1;
				if((cBoost == true) && (px + 10 <= 930))
				{
					s1 = 10;
					px += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 930) && (py >= 320 && py <= 1030)) //right vertical movement
			{
				py -= s1;
				if((cBoost == true) && (py - 10 >= 320))
				{
					s1 = 10;
					py -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
		}
		{	//4th Extreme Road
			if ((px >= 545 && px <= 790) && (py == 420))	//In bottom road 
			{
				px -= s1;
				if((cBoost == true) && (px - 10 >= 545))
				{
					s1 = 10;
					px -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 545) && (py >= 420 && py <= 930)) //left vertival movement
			{
				py += s1;
				if((cBoost == true) && (py + 10 <= 930))
				{
					s1 = 10;
					py += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px >= 545 && px <= 790) && (py == 930)) //In top road
			{
				px += s1;
				if((cBoost == true) && (px + 10 <= 790))
				{
					s1 = 10;
					px += s1;
					cBoost = false;
					s1 = 5;
				}
			}
			if ((px == 790) && (py >= 420 && py <= 930)) //right vertical movement
			{
				py -= s1;
				if((cBoost == true) && (py - 10 >= 420))
				{
					s1 = 10;
					py -= s1;
					cBoost = false;
					s1 = 5;
				}
			}
		}
	}
}

/***************************************************************************************************************************/

void OpponentMovement()
{
	{	//Movement of Opponent Car
		{	//Extreme Road
			if ((x >= 125 && x <= 1210) && (y == 120))	//In bottom road 
			{
				x += s2;
				if((overSpeed == true) && (x + 10 <= 1210))
				{
					s2 = 10;
					x += s2;
					s2 = speed1;
				}
			}
			if ((x == 125) && (y >= 120 && y <= 1230)) //left vertival movement
			{
				y -= s2;
				if((overSpeed == true) && (y - 10 >= 120))
				{
					s2 = 10;
					y -= s2;
					s2 = speed1;
				}
			}
			if ((x >= 125 && x <= 1210) && (y == 1230)) //In top road
			{
				x -= s2;
				if((overSpeed == true) && (x - 10 >= 125))
				{
					s2 = 10;
					x -= s2;
					s2 = speed1;
				}
			}
			if ((x == 1210) && (y >= 120 && y <= 1230)) //right vertical movement
			{
				y += s2;
				if((overSpeed == true) && (y + 10 <= 1230))
				{
					s2 = 10;
					y += s2;
					s2 = speed1;
				}
			}
		}
		{	//2nd Extreme Road
			if ((x >= 265 && x <= 1070) && (y == 220))	//In bottom road 
			{
				x += s2;
				if((overSpeed == true) && (x + 10 <= 1070))
				{
					s2 = 10;
					x += s2;
					s2 = speed1;
				}
			}
			if ((x == 265) && (y >= 220 && y <= 1130)) //left vertival movement
			{
				y -= s2;
				if((overSpeed == true) && (y - 10 >= 220))
				{
					s2 = 10;
					y -= s2;
					s2 = speed1;
				}
			}
			if ((x >= 265 && x <= 1070) && (y == 1130)) //In top road
			{
				x -= s2;
				if((overSpeed == true) && (x - 10 >= 265))
				{
					s2 = 10;
					x -= s2;
					s2 = speed1;
				}
			}
			if ((x == 1070) && (y >= 220 && y <= 1130)) //right vertical movement
			{
				y += s2;
				if((overSpeed == true) && (y + 10 <= 1130))
				{
					s2 = 10;
					y += s2;
					s2 = speed1;
				}
			}
		}
		{	//3rd Extreme Road
			if ((x >= 405 && x <= 930) && (y == 320))	//In bottom road 
			{
				x += s2;
				if((overSpeed == true) && (x + 10 <= 930))
				{
					s2 = 10;
					x += s2;
					s2 = speed1;
				}
			}
			if ((x == 405) && (y >= 320 && y <= 1030)) //left vertival movement
			{
				y -= s2;
				if((overSpeed == true) && (y - 10 >= 320))
				{
					s2 = 10;
					y -= s2;
					s2 = speed1;
				}
			}
			if ((x >= 405 && x <= 930) && (y == 1030)) //In top road
			{
				x -= s2;
				if((overSpeed == true) && (x - 10 >= 405))
				{
					s2 = 10;
					x -= s2;
					s2 = speed1;
				}
			}
			if ((x == 930) && (y >= 320 && y <= 1030)) //right vertical movement
			{
				y += s2;
				if((overSpeed == true) && (y + 10 <= 1030))
				{
					s2 = 10;
					y += s2;
					s2 = speed1;
				}
			}
		}
		{	//4th Extreme Road
			if ((x >= 545 && x <= 790) && (y == 420))	//In bottom road 
			{
				x += s2;
				if((overSpeed == true) && (x + 10 <= 790))
				{
					s2 = 10;
					x += s2;
					s2 = speed1;
				}
			}
			if ((x == 545) && (y >= 420 && y <= 930)) //left vertival movement
			{
				y -= s2;
				if((overSpeed == true) && (y - 10 >= 420))
				{
					s2 = 10;
					y -= s2;
					s2 = speed1;
				}
			}
			if ((x >= 545 && x <= 790) && (y == 930)) //In top road
			{
				x -= s2;
				if((overSpeed == true) && (x - 10 >= 545))
				{
					s2 = 10;
					x -= s2;
					s2 = speed1;
				}
			}
			if ((x == 790) && (y >= 420 && y <= 930)) //right vertical movement
			{
				y += s2;
				if((overSpeed == true) && (y + 10 <= 930))
				{
					s2 = 10;
					y += s2;
					s2 = speed1;
				}
			}
		}
	}
}

/***************************************************************************************************************************/

void Opponent2Movement()
{
	{	//Movement of Opponent Car
		{	//Extreme Road
			if ((tx >= 125 && tx <= 1210) && (ty == 120))	//In bottom road 
			{
				tx += s2;
			}
			if ((tx == 125) && (ty >= 120 && ty <= 1230)) //left vertival movement
			{
				ty -= s2;
			}
			if ((tx >= 125 && tx <= 1210) && (ty == 1230)) //In top road
			{
				tx -= s2;
			}
			if ((tx == 1210) && (ty >= 120 && ty <= 1230)) //right vertical movement
			{
				ty += s2;
			}
		}
		{	//2nd Extreme Road
			if ((tx >= 265 && tx <= 1070) && (ty == 220))	//In bottom road 
			{
				tx += s2;
			}
			if ((tx == 265) && (ty >= 220 && ty <= 1130)) //left vertival movement
			{
				ty -= s2;
			}
			if ((tx >= 265 && tx <= 1070) && (ty == 1130)) //In top road
			{
				tx -= s2;
			}
			if ((tx == 1070) && (ty >= 220 && ty <= 1130)) //right vertical movement
			{
				ty += s2;
			}
		}
		{	//3rd Extreme Road
			if ((tx >= 405 && tx <= 930) && (ty == 320))	//In bottom road 
			{
				tx += s2;
			}
			if ((tx == 405) && (ty >= 320 && ty <= 1030)) //left vertival movement
			{
				ty -= s2;
			}
			if ((tx >= 405 && tx <= 930) && (ty == 1030)) //In top road
			{
				tx -= s2;
			}
			if ((tx == 930) && (ty >= 320 && ty <= 1030)) //right vertical movement
			{
				ty += s2;
			}
		}
		{	//4th Extreme Road
			if ((tx >= 545 && tx <= 790) && (ty == 420))	//In bottom road 
			{
				tx += s2;
			}
			if ((tx == 545) && (ty >= 420 && ty <= 930)) //left vertival movement
			{
				ty -= s2;
			}
			if ((tx >= 545 && tx <= 790) && (ty == 930)) //In top road
			{
				tx -= s2;
			}
			if ((tx == 790) && (ty >= 420 && ty <= 930)) //right vertical movement
			{
				ty += s2;
			}
		}
	}
}

/***************************************************************************************************************************/

void LivesControl()
{
	{		//Lives Control
		if (level < 4)
		{
			if (((px == x || px == x + 5 || px == x + 10 || px == x + 15) && (py  == y || py == y + 5 || py == y + 10 || py == y + 15)) && lives != 0)
			{
				lives --;
				levelCheck = 80;
			
				//	Moving User Car To Initial Positions
				px = 675;
				py = 1230;
			
				//	Moving Opponent Car To Initial Positions 
				x = 125; 
				y = 675;
					
				//Food Redrawing
				reDraw = true;	
			
			}
			else if (((px == x || px == x + 5 || px == x + 10 || px == x + 15) && (py  == y || py == y + 5 || py == y + 10 || py == y + 15)) && lives == 0)
			{
				newHighScore = score;
				write1 = true;
				gameEnd = true;		//GameOver
				reset = true;		//Reset the game
				menu= true;			//Open The Menu
			}
		}
		else if (level == 4)
		{
			if (((((px == x || px == x + 5 || px == x + 10 || px == x + 15) && (py  == y || py == y + 5 || py == y + 10 || py == y + 15))) || ((px == tx || px == tx + 5 || px == tx + 10) && (py  == ty || py == ty + 5 || py == ty + 10))) && lives != 0)
			{
				lives --;
				levelCheck = 80;
			
				//	Moving User Car To Initial Positions
				px = 675;
				py = 1230;
			
				//	Moving Opponent Car To Initial Positions 
				x = 125; 
				y = 675;
			
				if (level == 4)
				{	//Moving 2nd Opponent Car To Initial Positions
					tx = 675; 
					ty = 120;
				}
						
				//Food Redrawing
				reDraw = true;	
			
			}
			else if (((((px == x || px == x + 5 || px == x + 10 || px == x + 15) && (py  == y || py == y + 5 || py == y + 10 || py == y + 15))) || ((px == tx || px == tx + 5 || px == tx + 10) && (py  == ty || py == ty + 5 || py == ty + 10))) && lives == 0)
			{
				newHighScore = score;
				write1 = true;
				gameEnd = true;		//GameOver
				reset = true;		//Reset the game
				menu= true;			//Open The Menu
			}
		}
	}
}

/***************************************************************************************************************************/

void LevelControl()
{
	{	//Level Control
		if (levelCheck == 0 && level <= 3)
		{
			level ++;			//Level Increase
			reDraw = true;		//Food Re-Draw
			
			//	Moving User Car To Initial Positions
			px = 675;
			py = 1230;
			
			//	Moving Opponent Car To Initial Positions 
			x = 125; 
			y = 675;
			
			levelCheck = 80;	//Check Fruits Back to Original
		}
		else if (levelCheck == 0 && level == 4)
		{
			newHighScore = score;
			write1 = true;
			win = true;			//Game Won
			reset = true;
			menu = true;
		}
	
	}
}

/***************************************************************************************************************************/

void DrawHighScore()
{
	if (highScore == true)
	{
		DrawString(600, 1000, "1) 	"+to_string(*(high_Scores + 0)), colors[TEAL]);
		DrawString(600, 950, "2) 	"+to_string(*(high_Scores + 1)), colors[TEAL]);
		DrawString(600, 900, "3) 	"+to_string(*(high_Scores + 2)), colors[TEAL]);
		DrawString(600, 850, "4) 	"+to_string(*(high_Scores + 3)), colors[TEAL]);
		DrawString(600, 800, "5) 	"+to_string(*(high_Scores + 4)), colors[TEAL]);
		DrawString(600, 750, "6) 	"+to_string(*(high_Scores + 5)), colors[TEAL]);
		DrawString(600, 700, "7) 	"+to_string(*(high_Scores + 6)), colors[TEAL]);
		DrawString(600, 650, "8) 	"+to_string(*(high_Scores + 7)), colors[TEAL]);
		DrawString(600, 600, "9) 	"+to_string(*(high_Scores + 8)), colors[TEAL]);
		DrawString(600, 550, "10)	"+to_string(*(high_Scores + 9)), colors[TEAL]);
	}
}

/***************************************************************************************************************************/

void sortHighScore()
{
	if (write1 == true)
	{
		if (newHighScore > *(high_Scores + 9))		//Editting HighScore
		{
			*(high_Scores + 9) = newHighScore;
		}
		int temp;
		for (int i = 0 ; i < 10 ; i++)			//Updting In The Array
		{
			for (int j = 0 ; j < 10 ; j++)
			{
				if (*(high_Scores + i) > *(high_Scores + j))
				{
					temp = *(high_Scores + i);
					*(high_Scores + i) = *(high_Scores + j);
					*(high_Scores + j) = temp;
				}
			}
		}
		write1 = false;
	}
}

/***************************************************************************************************************************/

void FileHandling()
{
			sortHighScore();
				
			//reading from a file
			int j = 0;
			ifstream fin ("high score.txt"); //name of the file it is supposed to read
			if (fin.is_open())
			{
				while ( getline (fin, show_highscore) ) //this loop will run depending on the number of lines in the file
				{
		  			*(high_Scores + j++) == stoi(show_highscore);
		  		}
				fin.close();
			}
			
			//writing to a file
			j = 0;
			ofstream fout;
			fout.open ("high score.txt" , ios::app); //this function takes the name of the file that you are writing to
			for (int i = 0; i < 10 ; i++)
			{
				fout << to_string(*(high_Scores + j++)) << endl;
			}
			fout.close();
			
		
}

/***************************************************************************************************************************/

void RandMovement1()						//For 1st Opponent Car
{																					//'1'-'0' for down movement
	if (level == 1 || level == 2 || level == 3 || level == 4)						//'0'-'1' for Up movement
	{
		r1 = 0 +  rand() % 2;
		r2 = 0 +  rand() % 2;	
		if ((r1 == 0 && r2 == 1) && (movement))
		{
			if ((x >= 645 && x <= 760) && (y == 120))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			
			if ((x >= 645 && x <= 760) && (y == 220))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			
			if ((x >= 645 && x <= 760) && (y == 320))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			
		}
		if ((r1 == 0 && r2 == 1) && (movement))
		{
			if ((x >= 645 && x <= 760) && (y == 1130))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			if ((x >= 645 && x <= 760) && (y == 1030))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			if ((x >= 645 && x <= 760) && (y == 930))
			{
				y += 100;
				x += 60;
				movement = false;
			}
			
		}	
		if ((r1 == 1 && r2 == 0) && (movement))
		{
			if ((x >= 645 && x <= 760) && (y == 1230))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
			if ((x >= 645 && x <= 760) && (y == 1130))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
		    if ((x >= 645 && x <= 760) && (y == 1030))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
			
		}
		if ((r1 == 1 && r2 == 0) && (movement))
		{
			if ((x >= 645 && x <= 760) && (y == 220))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
			if ((x >= 645 && x <= 760) && (y == 320))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
			if ((x >= 645 && x <= 760) && (y == 420))
			{
				y -= 100;
				x -= 60;
				movement = false;
			}
		
		}
	}
}

/***************************************************************************************************************************/

void RandMovement2()						//For 1st Opponent Car
{																								//'1'-'0' for right movement
	if (level == 2 || level == 3 || level == 4)													//'0'-'1' for left movement
	{
		r1 = 0 +  rand() % 2;
		r2 = 0 +  rand() % 2;	
		if ((r1 == 0 && r2 == 1) && (movement))
		{
			if ((x == 1210) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y += 60;
				movement = false;
			}
			
			if ((x == 1070) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y += 60;
				movement = false;
			}
			
			if ((x == 930) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y += 60;
				movement = false;
			}
			
		}
		if ((r1 == 0 && r2 == 1) && (movement))
		{
			if ((x == 265) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y -= 60;
				movement = false;
			}
			if ((x == 405) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y -= 60;
				movement = false;
			}
			if ((x >= 545 && x <= 760) && (y >= 640 && y <= 710))
			{
				x -= 140;
				y -= 60;
				movement = false;
			}
			
		}	
		if ((r1 == 1 && r2 == 0) && (movement1))
		{
			if ((x == 790) && (y >= 640 && y <= 710))
			{
				x += 140;
				y += 60;
				movement = false;
			}
			if ((x == 930) && (y >= 640 && y <= 710))
			{
				x += 140;
				y += 60;
				movement = false;
			}
		    if ((x == 1070) && (y >= 640 && y <= 710))
			{
				x += 140;
				y += 60;
				movement = false;
			}
			
		}
		if ((r1 == 1 && r2 == 0) && (movement))
		{
			if ((x == 125) && (y >= 640 && y <= 710))
			{
				x += 140;
				y -= 60;
				movement = false;
			}
			if ((x == 265) && (y >= 640 && y <= 710))
			{
				x += 140;
				y -= 60;
				movement = false;
			}
			if ((x == 405) && (y >= 640 && y <= 710))
			{
				x += 140;
				y -= 60;
				movement = false;
			}
		
		}
	}
}

/***************************************************************************************************************************/

void RandMovement3()						//For 2nd Opponent Car
{																					//'1'-'0' for down movement
	if (level == 1 || level == 2 || level == 3 || level == 4)						//'0'-'1' for Up movement
	{
		r11 = 0 +  rand() % 2;
		r22 = 0 +  rand() % 2;	
		if ((r11 == 0 && r22 == 1) && (movement1))
		{
			if ((tx >= 645 && tx <= 760) && (ty == 120))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			
			if ((tx >= 645 && tx <= 760) && (ty == 220))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			
			if ((tx >= 645 && tx <= 760) && (ty == 320))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			
		}
		if ((r11 == 0 && r22 == 1) && (movement1))
		{
			if ((tx >= 645 && tx <= 760) && (ty == 1130))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			if ((tx >= 645 && tx <= 760) && (ty == 1030))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			if ((tx >= 645 && tx <= 760) && (ty == 930))
			{
				ty += 100;
				tx += 60;
				movement1 = false;
			}
			
		}	
		if ((r11 == 1 && r22 == 0) && (movement1))
		{
			if ((tx >= 645 && tx <= 760) && (ty == 1230))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
			if ((tx >= 645 && tx <= 760) && (ty == 1130))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
		    if ((tx >= 645 && tx <= 760) && (ty == 1030))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
			
		}
		if ((r11 == 1 && r22 == 0) && (movement1))
		{
			if ((tx >= 645 && tx <= 760) && (ty == 220))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
			if ((tx >= 645 && tx <= 760) && (ty == 320))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
			if ((tx >= 645 && tx <= 760) && (ty == 420))
			{
				ty -= 100;
				tx -= 60;
				movement1 = false;
			}
		
		}
	}
}

/***************************************************************************************************************************/

void RandMovement4()						//For 2nd Opponent Car
{																								//'1'-'0' for right movement
																								//'0'-'1' for left movement
		r11 = 0 +  rand() % 2;
		r22 = 0 +  rand() % 2;	
		if ((r11 == 0 && r22 == 1) && (movement1))
		{
			if ((tx == 1210) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty += 60;
				movement1 = false;
			}
			
			if ((tx == 1070) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty += 60;
				movement1 = false;
			}
			
			if ((tx == 930) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty += 60;
				movement1 = false;
			}
			
		}
		if ((r11 == 0 && r22 == 1) && (movement1))
		{
			if ((tx == 265) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty -= 60;
				movement1 = false;
			}
			if ((tx == 405) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty -= 60;
				movement1 = false;
			}
			if ((tx >= 545 && tx <= 760) && (ty >= 640 && ty <= 710))
			{
				tx -= 140;
				ty -= 60;
				movement1 = false;
			}
			
		}	
		if ((r11 == 1 && r22 == 0) && (movement1))
		{
			if ((tx == 790) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty += 60;
				movement1 = false;
			}
			if ((tx == 930) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty += 60;
				movement1 = false;
			}
		    if ((tx == 1070) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty += 60;
				movement1 = false;
			}
			
		}
		if ((r11 == 1 && r22 == 0) && (movement1))
		{
			if ((tx == 125) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty -= 60;
				movement1 = false;
			}
			if ((tx == 265) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty -= 60;
				movement1 = false;
			}
			if ((tx == 405) && (ty >= 640 && ty <= 710))
			{
				tx += 140;
				ty -= 60;
				movement1 = false;
			}
		
		}
}

/***************************************************************************************************************************/

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

	DisplayCars();	//For Displaying The Cars of both User and Opponent
	
	DrawArena();	//For Drawing The Whole Arena
		
	DrawScores();	//Score Drawing
		
	DrawLives();	// For Drawing The Lives
	
	DrawLevel();	//For Drawing Level
	
	DisplayGameOver();	//For Displaying Gameover
	
	DisplayWin();		
	
	DrawFood();		//For Food Drawing and Redrawing
	
	DrawMenu();		//For Drawing Menu
	
	DrawHighScore();	//For Drawing High Score
	
	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
 


void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed..
		{	//right gaps
			if ((px == 1210 || px == 1070 || px == 930) && (py >= 640 && py <= 710))
			{
				px -= 140;
				movement = true;
				movement1 = true;
			}			
		}
		{	//left gaps
			if ((px == 545 || px == 405 || px == 265) && (py >= 640 && py <= 710))
			{
				px -= 140;
				movement = true;
				movement1 = true;
			}		
		}

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {	
		{	//right gaps
			if ((px == 790 || px == 930 || px == 1070) && (py >= 640 && py <= 710))
			{
				px += 140;
				movement = true;
				movement1 = true;
			}			
		}
		{	//left gaps
			if ((px == 125 || px == 265 || px == 405) && (py >= 640 && py <= 710))
			{
				px += 140;
				movement = true;
				movement1 = true;
			}		
		}		
			
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			{ 	//Bottom gaps
				if ((px >= 645 && px <= 760) && (py == 120 || py == 220 || py == 320))
				{
					py += 100;
					movement = true;
					movement1 = true;
				}
				
			}
			{	//Top gaps
				if ((px >= 645 && px <= 760) && (py == 1130 || py == 1030 || py == 930))
				{
					py += 100;
					movement = true;
					movement1 = true;
				}
			}
			
	} else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			{	// Top gaps	
				if ((px >= 645 && px <= 760) && (py == 1230 ||py == 1130 || py == 1030))
				{
					py -= 100;
					movement = true;
					movement1 = true;
				}
			}
			{	//Bottom gaps
				if ((px >= 645 && px <= 760) && (py == 220 || py == 320 || py == 420))
				{
					py -= 100;
					movement = true;
					movement1 = true;
				}
			}
	}
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {

	if (key == 32 && startCheck == true)	
	{
		if (cBoost == false)
			cBoost = true;
	}

	
	if ((key == 'p' || key == 'P') && (startCheck  == true) && (highScore == false) && (help == false))	//For Pausing the game
	{
		if (pmenu == false)
			pmenu = true;	
			overSpeed = false;
		s1 = 0.0;
		s2 = 0.0;
		s3 = 0.0;
		speed1 = 0.0;
		pcheck = true;
	}

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	
	PlayerMovement();		//Movement Of Player Car
	
	OpponentMovement();		//Movement Of Opponent Car
	
	if (level == 4)
		Opponent2Movement();	//Movement Of 2nd Opponent Car
	
	LivesControl();			//For Controlling Lives
	
	LevelControl();			//For Controlling Levels
	
	RandMovement1();
	
	RandMovement2();	
	
	if (level == 4)
	{
		RandMovement3();
	
		RandMovement4();
	}
	
	
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if (menu == true || pmenu == true)
		{
			if ((x >= 600 && x <= 780) && (y >= 225 && y <= 245))	//Resume Menu
			{
				pmenu = false;
				resume = true;
				s1 = 5.0;
				s2 = 5.0;
				speed1 = 5.0;
				if (level == 3)
					overSpeed = true;
				if (level == 4)
					s3 = 5.0;
								
			}
			
			if ((x >= 600 && x <= 820) && (y >= 295 && y <= 315))	//Start Menu
			{
				if ((reset == true) || (re == true))
				{
					speed1 = 5.0;
					//	Moving User Car To Initial Positions
					px = 675;
					py = 1230;
			
					//	Moving Opponent Car To Initial Positions 
					x = 125; 
					y = 675;
					
					GameReset();
				}
				start = true;
				menu = false;
				startCheck = true;
				if(pmenu == true)
				{
					reset = true;
					GameReset();
				}
				
			}
			
			if ((x >= 600 && x <= 665) && (y >= 510 && y <= 530))	//Exit Menu
			{
				delete [] high_Scores;
				exit(1);
			}
			
			if ((x >= 600 && x <= 760) && (y >= 365 && y <= 380))	//Highscore Menu
			{
				if ((gameEnd == true || win == true) && (reset == true))
				{	
					re = true;
					GameReset();
				}
				menu = false;
				pmenu = false;
				start = false;
				resume = false;
				highScore = true;
				toMenu = true;
				if (highScore == true)
				{
					FileHandling();
				}
				
			}
			
			if ((x >= 600 && x <= 670) && (y >= 435 && y <= 455))	//Help Menu
			{
				if ((gameEnd == true || win == true) && (reset == true))
				{
					re = true;
					GameReset();
				}
				menu = false;
				pmenu = false;
				start = false;
				resume = false;
				help = true;
				toMenu = true;
				
			}
		}
		if (toMenu == true)
		{
			if ((x >= 450 && x <= 520) && (y >= 260 && y <= 280))	//Back Menu
			{
				highScore = false;
				help = false;
				if (pcheck == true)
					pmenu = true;
				else
					menu = true;
				toMenu = false;
			}
		}
		
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
	
	srand(time(0));
	//Rndom Car Position
	int c1 = 0 + rand() % 2;
	int c2 = 0 + rand() % 2;
	int c3 = 0 + rand() % 2;
	
	if (c1 == 0)		//Player Car
	{
		 px = 675; 
		 py = 1230; 
	}
	else if (c1 == 1)
	{
		 px = 600; 
		py = 1230; 
	}
	
	if (c2 == 0)		//Opponent 1 Car
	{
		 x = 125; 
		 y = 675; 
	}
	else if (c2 == 1)
	{
		 x = 125; 
		 y = 775; 
	}
	
	if (c3 == 0)
	{
		 tx = 675; 
		 ty = 120; 
	}
	else if (c3 == 1)
	{
		 tx = 800; 
		 ty = 120;  
	}
	
	int width = 1440, height = 1440; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge 'Em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1.0, Timer, 0);
	
	

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
