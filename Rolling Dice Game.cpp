#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SwinGame.h"

void draw_button(color clr, float x, float y, int btnWidth, int btnHeight)
{
	fill_rectangle(clr, x, y, btnWidth, btnHeight);
}

bool button_clicked(int xValue, int yValue, int btnWidth, int btnHeight)
{
	float rightValue, bottomValue;
	rightValue = xValue + btnWidth;
	bottomValue = yValue + btnHeight;

	if(mouse_clicked(LEFT_BUTTON))
	{
		if ((mouse_x() >= xValue) && (mouse_x() <= rightValue) && (mouse_y() >= yValue) && (mouse_y() <= bottomValue))
			return true;
	}
}

int RollingDice()
{
	int num = 1+rand()%6;
	return num;
}

void play()
{

	float x = 45, y = 70;
	int btnWidth = 50, btnHeight = 30;
	char str[20];
	int i, j;
	int roll1, roll2;
	int freq [7][7]={0};



	srand(time(NULL));
	
	for (int i = 0; i<36000; i++)
	{
	// roll1 = RollingDice();
	// roll2 = RollingDice();
		roll1=1+rand()%6;
		roll2 = 1+rand()%6;
	switch(roll1)
	{
		case 1:
		++freq[1][roll2];

		break;

		case 2:
		++freq[2][roll2];

		break;

		case 3:
		++freq[3][roll2];

		break;

		case 4:
		++freq[4][roll2];

		break;

		case 5:
		++freq[5][roll2];

		break;

		case 6:
		++freq[6][roll2];

		break;

	}

	}

		for(i = 1; i<=6; i++)
		{
			x = x + 55;

			draw_button(ColorGrey, x, y, btnWidth, btnHeight);
			sprintf(str, "%d", i);
			draw_text(str, ColorWhite, "arial.ttf", 15, x,y);
		}

		x = 45;

		for(i = 1; i<=6; i++)
		{
			y = y + 35;

			draw_button(ColorGrey, x, y, btnWidth, btnHeight);
			sprintf(str, "%d", i);
			draw_text(str, ColorWhite, "arial.ttf", 15, x,y);
		}

		x = 45;
		y = 105;

		for(i = 1; i<=6; i++)
		{
		
			for(j = 1; j<=6; j++)
			{
				x = x + 55;
			

			draw_button(ColorYellow, x, y, btnWidth, btnHeight);
			sprintf(str, "%d", freq[i][j]);
			draw_text(str, ColorRed, "arial.ttf", 15, x,y);
			}

		x = 45;
		y = y + 35;

		}

		if (freq[6][6]>=1000)
		{
			draw_button(ColorDarkGreen, 200, 320, 100, 30);
			draw_text("Player Wins", ColorYellow, "arial.ttf", 15, 205, 320);
			
		}
		else
		{
			draw_button(ColorDarkGreen, 200, 320, 100, 30);
			draw_text("Player Loses", ColorYellow, "arial.ttf", 15, 205, 320);

		} 
}


int main()
{
	float x = 200, y = 25;
	open_graphics_window("Dice Rolling",600, 600);
	clear_screen(ColorLightGreen);

	do{
		process_events();
		draw_button(ColorDarkGreen, x, y, 100, 30);
		draw_text("Play Game", ColorYellow, "arial.ttf", 15, x + 5, y + 5);

		if (button_clicked(x, y, 100, 30))	
			{
				play();
			}	
			refresh_screen(60);

	} while(!(window_close_requested()));
}