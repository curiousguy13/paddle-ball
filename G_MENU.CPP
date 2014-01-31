//Name-Kunal Arora
//paddle ball

#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include<time.h>


void setgraph()
{
	int mode,driver=DETECT;
	initgraph(&driver,&mode,"D:\\TC\\BGI");
}

	int t=0,x=0,y=0,i=0,j=0,p=0,q=0,n=2,m=2,score=0,nl=0,clr=0;
	int life=3,k=5,c=0,xx=0,yy=0;
	char cha,g;
void menu()                         //menu ,play,instructions & exit
{
	cleardevice();
	setbkcolor(0);
	settextstyle(7,0,3);
	setcolor(2);


	for(int a=0;a<260;a++)
	{
		setcolor(0);
		outtextxy(85,a-1,"EXIT");
		delay(8);
		setcolor(4);
		outtextxy(85,a,"EXIT");
	}

  int a=0;
	for(a=0;a<230;a++)
	{
		setcolor(0);
		outtextxy(85,a-1,"INSTRUCTIONS");
		delay(8);
		setcolor(2);
		outtextxy(85,a,"INSTRUCTIONS");
	}


	for(a=0;a<200;a++)
	{
		setcolor(0);
		outtextxy(85,a-1,"PLAY");
		delay(8);
		setcolor(15);
		outtextxy(85,a,"PLAY");

	}
	settextstyle(3,0,5);
	for(int ab=0;ab<200;ab++)
	{
		setcolor(0);
		outtextxy(ab-1,50,"PADDLE");
		delay(5);
		setcolor(5);
		outtextxy(ab,50,"PADDLE");

	}
	int ab=0;
	for(ab=640;ab>350;ab--)
	{
		setcolor(0);
		outtextxy(ab+1,50,"BALL");
		delay(5);
		setcolor(5);
		outtextxy(ab,50,"BALL");
	}
	settextstyle(7,0,3);
	setcolor(2);
	outtextxy(40,200+t,"-->");

	do                                      // motion arrow
	{
		if(kbhit())
		{
			cha=getch();


			if(cha==80&&t<60)
			{
				setcolor(0);
				outtextxy(40,200,"-->");
				outtextxy(40,230,"-->");
				outtextxy(40,260,"-->");
				t+=30;
				setcolor(2);
				outtextxy(40,200+t,"-->");
			}
			if(cha==72&&t>0)
			{
				setcolor(0);
				outtextxy(40,200,"-->");
				outtextxy(40,230,"-->");
				outtextxy(40,260,"-->");
				t-=30;
				setcolor(2);
				outtextxy(40,200+t,"-->");
			 }
			 if(cha==13&&t==0)
			 {
				break;
			 }
			if(cha==13&&t==30)
			{
				char ex;
				cleardevice();
				do
				{
					if(kbhit())
					{
						ex=getch();
						if(ex==27)
						{
						cleardevice();
						setcolor(15);
						outtextxy(85,200,"PLAY");
						setcolor(2);
						outtextxy(85,230,"INSTRUCTIONS");
						setcolor(4);
						outtextxy(85,260,"EXIT");
						break;
						}

					 }
		 setcolor(6);
		 setfillstyle(6,1);
		 settextstyle(3,0,2);
		 outtextxy(10,10," 	This game is open for all .To play this game you have");
		 outtextxy(10,40,"	to be skillfull with arrow keys.");

		 outtextxy(10,70,"* press up or down to move the left and right paddles");

		 outtextxy(10,100,"* press left or right to move the upper and lower paddles");

		 outtextxy(10,130,"* AIM OF THE GAME : stop the ball from crossing the");
		 outtextxy(10,160,"  boundary of the screen with the help of paddles.");

		 outtextxy(10,190,"* You have been provided with ** 3 chances.");

		 outtextxy(10,220,"* Every  .save/hit with paddle ** provides a single point.");

		 outtextxy(10,250,"* Compete for high scores and break the records.");

		 outtextxy(10,280,"* BEST 0F Luck ! ! !  & ENJOY !");
		 setcolor(4);


		 }while(ex!=27);
	}
		 if(cha==13 && t==60)
		 {
			exit(0);
		 }

	}
	}while(cha!=27);

}

void game()
{

	setbkcolor(0);
	do
	{

		setcolor(4);
		circle(i,j,10);

		setcolor(0);
		delay(7-q);

		circle(i,j,10);
		i=i+pow(-1,m);  j=j+pow(-1,n);

	if(i>=280+x && i<=360+x && j==455)
	{
			n=1;
			score++;
			nl++;
	}

	if(i>=280+x && i<=360+x && j==25)
	{
			n=2;
			score++;
			nl++;
	}

	if(i==25 && j>=200+y && j<=280+y)
	{
			m=2;
			score++;
			nl++;
	}

	if(i==615 && j>=200+y && j<=280+y)
	{
			m=1;
			score++;
			nl++;
	}

	if(nl==10)
	{
			q=1;
			nl=0;
	}

	if((i>640||i<0 ||j>480||j<0)&&life==3)
	{

		cleardevice();
		life-=1;
		q-=1;
		i=0;
		j=0;
		n=2;
		m=2;
		settextstyle(10,0,1);
		setcolor(2);
		outtextxy(150,200,"You Have 2 lives remaining"); //2nd life indication

		do
		{
			settextstyle(2,0,8);
			setcolor(2);
			outtextxy(50+k,350,"Press enter key to continue ");
			setcolor(0);
			outtextxy(50+k,350,"Press enter key to continue ");

			k++;

			if(kbhit())
			{
				g=getch();
			}

		}while(g!=13);
		getch();
		cleardevice();
	}

	if((i>640||i<0 ||j>480||j<0)&&life==2)
	{
		cleardevice();
		life-=1;
		q-=1;
		i=0;
		j=0;
		n=2;
		m=2;
		settextstyle(10,0,1); //(font type,horizontal,size)
		setcolor(4);     //4=red
		outtextxy(150,200,"You Have 1 life remaining");      //last life indication
		do
		{
			settextstyle(2,0,8);
			setcolor(2);
			outtextxy(50+k,350,"Press enter key to continue ");
			setcolor(0);
			outtextxy(50+k,350,"Press enter key to continue ");
			k++;
			if(kbhit())
			{
				g=getch();
			}
		}while(g!=13);
			getch();
			cleardevice();
	}

	if((i>640||i<0 ||j>480||j<0)&&life==1)
	{
		   break;
	}

	setcolor(5);
	rectangle( 280+x, 465,360+x ,475);

	setcolor(6);
	rectangle(280+x,5,360+x,15);

	setcolor(5);
	rectangle(5,200+y,15,280+y);

	setcolor(6);
	rectangle(625,200+y,635,280+y);
		if(kbhit())
		{
			setcolor(0);

			rectangle(280+x,465,360+x,475);     //paddle 1
			rectangle(280+x,5,360+x,15);        //paddle 2
			rectangle(5,200+y,15,280+y);        //paddle 3
			rectangle(625,200+y,635,280+y);     //paddle 4
			char ch;
			ch=getch();
			if(ch== 75 && x>=-240)
			{
//				//sound(500);     ////sound production during movement of paddle
				delay(13);
				////no//sound();
				x-=40;
			}

			if(ch==77 && x<=240)
			{
			      ////sound(500);
				delay(13);    ////sound production during movement of paddle
	//			//no//sound();
				x+=40;

			}

			if(ch==72 && y>=-160)
			{

			       //sound(500);
				delay(13);    ////sound production during movement of paddle
				//no//sound();
				y-=40;
			}

			if(ch==80 && y<=160)
			{
			     //sound(500);
				delay(13);    ////sound production during movement of paddle
				//no//sound();
				y+=40;
			}

				if(ch==27)
			{
			       //sound(500);
				delay(13);
				//no//sound();    ////sound production during movement of paddle
				exit(0);
			}

		}

	}while(x<=800);
}

void g_over()
{
       cleardevice();
       setbkcolor(0);
       setcolor(2);
       gotoxy(30,25);
       cout<<" [Y0U SC0RED] --> "<<score;       //visibility of score
       outtextxy(45,23,"   BEAT THE HIGHEST - 150 ");
       do
       {
	       setcolor(2+clr);

	       settextstyle(10,0,(1+clr));
	       outtextxy(150,200,"GAME-OVER");

	       settextstyle(10,0,(1+clr));
	       delay(1000);

	       setcolor(0);
	       outtextxy(150,200,"GAME-OVER");
	       clr++;

	       if(clr==4)
	       clr=0;

       }while(!kbhit());
}

void rec()
{
	 setcolor(6);
	 rectangle(1,1,635,475);            // outline rectangled borders
	 rectangle(3,3,633,473);
	 for(int k =0;k<342;k++)
	 {
		 setcolor(7);
		 delay(10);
		 rectangle(140,220,140+k,200);
		 rectangle(140,220,342,200);
		 outtextxy(180,220," just a moment ");    //waiting statement
	 }

}
void ball()
{
	  setcolor(3);
	  int dir=0;
	  for(int i=55,c=0;c<789;c++)   //to change speed of ball change<789

	  {
		 setcolor(2);
		 settextstyle(2,0,5);
		 outtextxy(2,3," Please Wait- Loading.... ");

		 delay(2);

		 setfillstyle(1,17);

		 setcolor(2);
		 circle(i,340,17);
		 setcolor(0);
		 circle(i-1 ,340,17);

		 setcolor(0);
		 circle(i-80 ,340,17);
		 circle(i-60,340,17);

		 setcolor(0);
		 circle(i-30 ,340,17);

		 setcolor(0);
		 circle(i,340,17);

		 if( dir==0 )
		 {
			i++;
			if(i==610)
			dir=1;

		 }

		 if(dir==1)
		 {                        //providing direction to ball during menu
			i--;
			if(i==30)
			dir=0;
		 }
	  }
}

int main()
{
	setgraph();
	rec();          //starting rectangle
	ball();         //starting ball function
	cleardevice;
	menu();         //menu function
	cleardevice();
	game();
	g_over();   //game over function
	return 0;
	closegraph();
}
