/*************************************************************************/
//*************************************************************************/
//       -*-     Program of "2-Player Chess"     -*-                //
//-------------------------------------------------------------------------//
//       -*-       Language  :-  C-Graphics & C.     -*-                //
//-------------------------------------------------------------------------//
//       -*-       Compilier :-  Turbo C & C++.        -*-                //
//-------------------------------------------------------------------------//
//       -*-         By- Srinivas R. Vaidya            -*-                //
//*************************************************************************//
//*************************************************************************//



#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<process.h>
#include<ctype.h>

/********** global variables ***********/
int c[9][9];

/** rs1 rs2 rs3 rs4 initial and final index coordinate of red pawn  **/
int rs1,rs2,rs3,rs4;  

/** gs1 gs2 gs3 gs4 initial and final graphical coordinate of green pawn **/
int gs1,gs2,gs3,gs4;  

int rv1,rv2,rv3,rv4;
int gv1,gv2,gv3,gv4;

/** Value of Chessmen **/
//-------------------------
/**	
	:::RED:::
	
	Pawn : 10
	Rook : 20
	Knight : 30
	Bishop : 40
	Queen : 50
	king : 60
	
	:::Green:::
	
	Pawn : 11
	Rook : 22
	Knight : 33
	Bishop : 44
	Queen : 55
	king : 66
//--------------------------	
**/


void soldergreen(int x,int y)
/* Paints Solder Green in the specified (x,y) location */
{
	setcolor(GREEN);
	line(x+5,y+35,x+35,y+35);
	for(int i=x+5;i<=x+35;i++)
	{
		line(x+20,y+15,i,y+30);
	}
	line(x+8,y+30,x+32,y+30);
	line(x+5,y+35,x+20,y+15);
	line(x+35,y+35,x+20,y+15);
	circle(x+20,y+10,5);
}

void solderred(int x,int y)
/* Paints Solder red in the specified (x,y) location */
{
	setcolor(RED);
	line(x+5,y+35,x+35,y+35);
	for(int i=x+5;i<=x+35;i++)
	{
		line(x+20,y+15,i,y+30);
	}
	line(x+8,y+30,x+32,y+30);
	line(x+5,y+35,x+20,y+15);
	line(x+35,y+35,x+20,y+15);
	circle(x+20,y+10,5);

}
void elephantgreen(int e1,int e2)
/* Paints Elephant Green in the specified (e1,e2) location */
{
	setcolor(GREEN);
	rectangle(e1+12,e2+5,e1+28,e2+35);
	line(e1+12,e2+30,e1+28,e2+30);
	line(e1+12,e2+10,e1+28,e2+10);
	for(int i=e2+10;i<=e2+30;i++)
	{
		line(e1+12,i,e1+28,i);
	}

}
void elephantred(int e1,int e2)
/* Paints Elephant red in the specified (e1,e2) location */
{
	setcolor(RED);
	rectangle(e1+12,e2+5,e1+28,e2+35);
	line(e1+12,e2+30,e1+28,e2+30);
	line(e1+12,e2+10,e1+28,e2+10);
	for(int i=e2+10;i<=e2+30;i++)
	{
		line(e1+12,i,e1+28,i);
	}

}
void horsered(int h1,int h2)
/* Paints Horse red in the specified (h1,h2) location */
{
	setcolor(RED);
	line(h1+10,h2+5,h1+10,h2+35);
	line(h1+10,h2+10,h1+15,h2+10);
	line(h1+15,h2+10,h1+15,h2+20);
	line(h1+15,h2+20,h1+30,h2+20);
	line(h1+30,h2+20,h1+30,h2+35);

	line(h1+30,h2+35,h1+25,h2+35);
	line(h1+25,h2+35,h1+25,h2+25);
	line(h1+25,h2+25,h1+15,h2+25);
	line(h1+15,h2+25,h1+15,h2+35);
	line(h1+15,h2+35,h1+10,h2+35);
	line(h1+10,h2+33,h1+15,h2+33);
	line(h1+30,h2+33,h1+25,h2+33);
	for(int i=h1+10;i<=h1+20;i=i+2){line(i,h2+5,i,h2+10);}
	for(i=h2+10;i<=h2+20;i=i+2){line(h1+15,i,h1+20,i);}
	for(i=h1+10;i<=h1+15;i++){line(i,h2+10,i,h2+33);}
	for(i=h1+15;i<=h1+30;i++){line(i,h2+20,i,h2+25);}
	for(i=h1+25;i<=h1+30;i++){line(i,h2+25,i,h2+33);}

}

void horsegreen(int h1,int h2)
/* Paints Horse Green in the specified (h1,h2) location */
{
	setcolor(GREEN);
	line(h1+10,h2+5,h1+10,h2+35);
	line(h1+10,h2+10,h1+15,h2+10);
	line(h1+15,h2+10,h1+15,h2+20);
	line(h1+15,h2+20,h1+30,h2+20);
	line(h1+30,h2+20,h1+30,h2+35);

	line(h1+30,h2+35,h1+25,h2+35);
	line(h1+25,h2+35,h1+25,h2+25);
	line(h1+25,h2+25,h1+15,h2+25);
	line(h1+15,h2+25,h1+15,h2+35);
	line(h1+15,h2+35,h1+10,h2+35);
	line(h1+10,h2+33,h1+15,h2+33);
	line(h1+30,h2+33,h1+25,h2+33);
	for(int i=h1+10;i<=h1+20;i=i+2){line(i,h2+5,i,h2+10);}
	for(i=h2+10;i<=h2+20;i=i+2){line(h1+15,i,h1+20,i);}
	for(i=h1+10;i<=h1+15;i++){line(i,h2+10,i,h2+33);}
	for(i=h1+15;i<=h1+30;i++){line(i,h2+20,i,h2+25);}
	for(i=h1+25;i<=h1+30;i++){line(i,h2+25,i,h2+33);}

}
void camalred(int c1,int c2)
/* Paints Camal red in the specified (c1,c2) location */
{
	setcolor(RED);
	line(c1+10,c2+35,c1+30,c2+35);
	line(c1+10,c2+35,c1+20,c2+5);
	line(c1+30,c2+35,c1+20,c2+5);
	line(c1+15,c2+30,c1+25,c2+30);
	line(c1+15,c2+30,c1+10,c2+35);
	line(c1+25,c2+30,c1+30,c2+35);
	for(int i=c1+15;i<=c1+25;i++)
	{
		line(c1+20,c2+5,i,c2+30);
	}
}
void camalgreen(int c1,int c2)
/* Paints Camal green in the specified (c1,c2) location */
{
	setcolor(GREEN);
	line(c1+10,c2+35,c1+30,c2+35);
	line(c1+10,c2+35,c1+20,c2+5);
	line(c1+30,c2+35,c1+20,c2+5);
	line(c1+15,c2+30,c1+25,c2+30);
	line(c1+15,c2+30,c1+10,c2+35);
	line(c1+25,c2+30,c1+30,c2+35);
	for(int i=c1+15;i<=c1+25;i++)
	{
		line(c1+20,c2+5,i,c2+30);
	}
}


void queenred(int k1,int k2)
/* Paints queen red in the specified (k1,k2) location */
{
	setcolor(RED);
	line(k1+5,k2+35,k1+35,k2+35);
	line(k1+5,k2+35,k1+35,k2+10);
	line(k1+35,k2+35,k1+5,k2+10);
	line(k1+5,k2+10,k1+35,k2+10);
	for(int i=k1+5;i<=k1+35;i=i+4){line(i,k2+4,i,k2+10);}
	for(i=k1+7;i<=k1+35;i=i+4){line(i,k2+2,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+35);}

}

void queengreen(int k1,int k2)
/* Paints queen green in the specified (k1,k2) location */
{
	setcolor(GREEN);
	line(k1+5,k2+35,k1+35,k2+35);
	line(k1+5,k2+35,k1+35,k2+10);
	line(k1+35,k2+35,k1+5,k2+10);
	line(k1+5,k2+10,k1+35,k2+10);
	for(int i=k1+5;i<=k1+35;i=i+4){line(i,k2+4,i,k2+10);}
	for(i=k1+7;i<=k1+35;i=i+4){line(i,k2+2,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+35);}

}


void kinggreen(int q1,int q2)
/* Paints king green in the specified (q1,q2) location */

{
	setcolor(GREEN);
	rectangle(q1+5,q2+15,q1+35,q2+35);
	rectangle(q1+10,q2+10,q1+30,q2+30);
	for(int i=q2+10;i<=q2+30;i++){line(q1+12,i,q1+28,i);}
	for(i=q1+10;i<=q1+30;i=i+2){line(i,q2+4,i,q2+10);}

}

void kingred(int q1,int q2)
/* Paints king red in the specified (q1,q2) location */
{
	setcolor(RED);
	rectangle(q1+5,q2+15,q1+35,q2+35);
	rectangle(q1+10,q2+10,q1+30,q2+30);
	for(int i=q2+10;i<=q2+30;i++){line(q1+12,i,q1+28,i);}
	for(i=q1+10;i<=q1+30;i=i+2){line(i,q2+4,i,q2+10);}
}

	
	
void INITIAL_SET()
{
	for(int i=160;i<480;i=i+40)
	{
		soldergreen(i,60);
		solderred(i,260);
	}
	
	elephantred(160,300);
	elephantgreen(160,20);
	elephantred(440,300);
	elephantgreen(440,20);

	horsered(200,300);
	horsered(400,300);
	horsegreen(200,20);
	horsegreen(400,20);

	camalred(240,300);
	camalred(360,300);
	camalgreen(240,20);
	camalgreen(360,20);

	queenred(280,300);
	queengreen(280,20);

	kingred(320,300);
	kinggreen(320,20);


/***** Initialization of the ChessMatrix with chessmen values **********/

/**** rook red  *****/ 
	c[1][1]=c[1][8]=20;
/**** rook green  ***/	
	c[8][1]=c[8][8]=22;

/**** knight red  ***/	
	c[1][2]=c[1][7]=30;  

/**** knight green  ***/	
	c[8][2]=c[8][7]=33;   

/****** Bishop red and green ***/
	c[1][3]=c[1][6]=40;  
	c[8][3]=c[8][6]=44;

/****** Queen and King red  ***/
	c[1][4]=50; 
	c[1][5]=60; 

/****** Queen and King Green ***/
	c[8][4]=55; 
	c[8][5]=66; 

/****** soilder red  *********/
	for(i=1;i<=8;i++)  
		c[2][i]=10;

/***** soilder green  **********/
	for(i=1;i<=8;i++)  
		c[7][i]=11;

}

void clear(int x,int y)
{
	setcolor(WHITE);
	for(int i=x;i<=x+40;i++)
	{
		line(i,y+1,i,y+40);
	}
	setcolor(GREEN);
}

void viewp1()
{
	setviewport(310,355,335,385,1);
	clearviewport();
	setviewport(369,355,390,385,1);
	clearviewport();
	setviewport(0,0,639,479,1);
}

void viewp2()
{
	setviewport(310,395,335,415,1);
	clearviewport();
	setviewport(369,395,390,415,1);
	clearviewport();
	setviewport(0,0,639,479,1);
}

/********* Checks if the input given by user is valid or not ************/
int validinput(char r1,char r2,char r3,char r4)
{
	// r1 and r3 should be in the set {a,b,c,d,e,f,g,h}
	// r2 and r2 should be in the set {1-8}
	
	if(((r1>=97)&&(r1<=104))&&((r2>=49)&&(r2<=56))&&((r3>=97)&&(r3<=104))&&((r4>=49)&&(r4<=56)))
	{
		return 1;  // Valid
	}
	else
	{
		return 0;  // Invalid
	}
}

/*** Prints the chessBoard Matrix **********/
void matrix()
{
		printf("\n\n");
		for(int i=8;i>=1;i--)
		{
			for(int j=1;j<=8;j++)
			{
				printf("     %d",c[i][j]);
			}
			printf("\n");
		}
		printf("\n(%d,%d)(%d,%d) ",rs1,rs2,rv1,rv2);
		printf("\nvalue = %d\n ",c[rs1][rs2]);
		printf("\n(%d,%d)(%d,%d) ",rs3,rs4,rv3,rv4);
		printf("\nvalue = %d\n ",c[rs3][rs4]);
		printf("\n(%d,%d)(%d,%d) ",gs1,gs2,gv1,gv2);
		printf("\nvalue = %d\n",c[gs1][gs2]);
		printf("\n(%d,%d)(%d,%d) ",gs3,gs4,gv3,gv4);
		printf("\nvalue =  %d\n",c[gs3][gs4]);
}


/***** Maps board number to board co-ordinates  ********/ 
void coordinate(char r1,char r2,int *p,int *q,int *r,int *s)
{

	  switch(tolower(r1))
	  {
	  case 'a':
			switch(r2)
			{
			case '1': *p=1,*q=1;
				  *r=160,*s=300; break;
			case '2': *p=2,*q=1;
				  *r=160,*s=260; break;
			case '3': *p=3,*q=1;
				  *r=160,*s=220; break;
			case '4': *p=4,*q=1;
				  *r=160,*s=180; break;
			case '5': *p=5,*q=1;
				  *r=160,*s=140; break;
			case '6': *p=6,*q=1;
				  *r=160,*s=100; break;
			case '7': *p=7,*q=1;
				  *r=160,*s=60; break;
			case '8': *p=8,*q=1;
				  *r=160,*s=20; break;
			}
			break;
	  case 'b':
			switch(r2)
			{
			case '1': *p=1,*q=2;
				  *r=200,*s=300; break;
			case '2': *p=2,*q=2;
				  *r=200,*s=260; break;
			case '3': *p=3,*q=2;
				  *r=200,*s=220; break;
			case '4': *p=4,*q=2;
				  *r=200,*s=180; break;
			case '5': *p=5,*q=2;
				  *r=200,*s=140; break;
			case '6': *p=6,*q=2;
				  *r=200,*s=100; break;
			case '7': *p=7,*q=2;
				  *r=200,*s=60; break;
			case '8': *p=8,*q=2;
				  *r=200,*s=20; break;
			}
			break;
	  case 'c':
			switch(r2)
			{
			case '1': *p=1,*q=3;
				  *r=240,*s=300; break;
			case '2': *p=2,*q=3;
				  *r=240,*s=260; break;
			case '3': *p=3,*q=3;
				  *r=240,*s=220; break;
			case '4': *p=4,*q=3;
				  *r=240,*s=180; break;
			case '5': *p=5,*q=3;
				  *r=240,*s=140; break;
			case '6': *p=6,*q=3;
				  *r=240,*s=100; break;
			case '7': *p=7,*q=3;
				  *r=240,*s=60; break;
			case '8': *p=8,*q=3;
				  *r=240,*s=20; break;
			}
			break;
	  case 'd':
			switch(r2)
			{
			case '1': *p=1,*q=4;
				  *r=280,*s=300; break;
			case '2': *p=2,*q=4;
				  *r=280,*s=260; break;
			case '3': *p=3,*q=4;
				  *r=280,*s=220; break;
			case '4': *p=4,*q=4;
				  *r=280,*s=180; break;
			case '5': *p=5,*q=4;
				  *r=280,*s=140; break;
			case '6': *p=6,*q=4;
				  *r=280,*s=100; break;
			case '7': *p=7,*q=4;
				  *r=280,*s=60; break;
			case '8': *p=8,*q=4;
				  *r=280,*s=20; break;
			}                    			break;

	   case 'e':
			switch(r2)
			{
			case '1': *p=1,*q=5;
				  *r=320,*s=300; break;
			case '2': *p=2,*q=5;
				  *r=320,*s=260; break;
			case '3': *p=3,*q=5;
				  *r=320,*s=220; break;
			case '4': *p=4,*q=5;
				  *r=320,*s=180; break;
			case '5': *p=5,*q=5;
				  *r=320,*s=140; break;
			case '6': *p=6,*q=5;
				  *r=320,*s=100; break;
			case '7': *p=7,*q=5;
				  *r=320,*s=60; break;
			case '8': *p=8,*q=5;
				  *r=320,*s=20; break;
			}
			break;
	    case 'f':
			switch(r2)
			{
			case '1': *p=1,*q=6;
				  *r=360,*s=300; break;
			case '2': *p=2,*q=6;
				  *r=360,*s=260; break;
			case '3': *p=3,*q=6;
				  *r=360,*s=220; break;
			case '4': *p=4,*q=6;
				  *r=360,*s=180; break;
			case '5': *p=5,*q=6;
				  *r=360,*s=140; break;
			case '6': *p=6,*q=6;
				  *r=360,*s=100; break;
			case '7': *p=7,*q=6;
				  *r=360,*s=60; break;
			case '8': *p=8,*q=6;
				  *r=360,*s=20; break;
			}
			break;
	     case 'g':
			switch(r2)
			{
			case '1': *p=1,*q=7;
				  *r=400,*s=300; break;
			case '2': *p=2,*q=7;
				  *r=400,*s=260; break;
			case '3': *p=3,*q=7;
				  *r=400,*s=220; break;
			case '4': *p=4,*q=7;
				  *r=400,*s=180; break;
			case '5': *p=5,*q=7;
				  *r=400,*s=140; break;
			case '6': *p=6,*q=7;
				  *r=400,*s=100; break;
			case '7': *p=7,*q=7;
				  *r=400,*s=60; break;
			case '8': *p=8,*q=7;
				  *r=400,*s=20; break;
			}
			break;
	   case 'h':
			switch(r2)
			{
			case '1': *p=1,*q=8;
				  *r=440,*s=300; break;
			case '2': *p=2,*q=8;
				  *r=440,*s=260; break;
			case '3': *p=3,*q=8;
				  *r=440,*s=220; break;
			case '4': *p=4,*q=8;
				  *r=440,*s=180; break;
			case '5': *p=5,*q=8;
				  *r=440,*s=140; break;
			case '6': *p=6,*q=8;
				  *r=440,*s=100; break;
			case '7': *p=7,*q=8;
				  *r=440,*s=60; break;
			case '8': *p=8,*q=8;
				  *r=440,*s=20; break;
			}
			break;


	  default: break;

		 }// end of switch

}// end of funtion


int legal(int i,int j,int m,int n,int p)
/*** 
	Checks if the move is LEGAL or NOT 
	 move from (i,j) to (m,n)   	
	 p = 1 :: RED chessMen
	 p = 2 :: GREEN chessMen
***/
{

		/** If trying to move to its own place **/
		if((c[i][j]==0)||((i==m)&&(j==n)))
		return 0;


		/** Looking if moving pawn belong to that user or not **/
		switch(p)
		{
		case 1: if(c[i][j]%10 != 0)
			return 0;

			break;
		case 2: if(c[i][j]%10 == 0)
			return 0;

			break;
		default: printf("\n\n \t default legal");
		}

	  int u,v;
	  
/** Checking with RULES of the chessmen being moved  **/
	  
	  switch(c[i][j])
	  {
		// pawn - red
		case 10: 
		
			// checking for move into empty slot.
			if((i+1)==m&&(j==n)&&(c[m][n]==0))
				return 1;

			if((i==2) && (i+2)==m && j==n && c[m][n]==0 && c[m+1][n]==0)
				return 1;

			if((i+1)==m && (j+1)==n && c[m][n]%10!=0)
				return 1;

			if(i+1==m && j==n+1 && c[m][n]%10!=0)
				return 1;

			else
			return 0;

		// pawn - green
		case 11:
			if((m+1)==i&&(j==n)&&(c[m][n]==0))
				return 1;

			if((i==7) && (m+2)==i && j==n && c[m][n]==0 && c[m-1][n]==0)
				return 1;

			if((m+1)==i && (n+1)==j && c[m][n]!=0 && c[m][n]%10 == 0)
			{
		      
				return 1;
			}

			if(i-1==m && j+1==n && c[m][n]%10==0 && c[m][n]!=0)
				return 1;
			else
				return 0;


		case 20:
		case 22: // rook 
			
			// Checking if rook trying to move diagonally. 
			if(i!=m && j!=n)
				return 0;

			if(j==n) // vertical movement
			{
					// Vertically moving upwards.
			       if(m>i)
			       {
					  for(int a=i+1;a<m;a++)
					  {
							// checking if path of rook is empty or not.
							if(c[a][n]!=0)
							{ 
								return 0;
							}
					  }
		
				  // if dest. location is empty or its occupied by opposite player chessmen.
				  if(c[m][n]==0 || c[m][n]%10!=0)
				  return 1;

			       }
			       // Vertically moving downwards.
			       if(i>m)
			       {
					  for(int a=i-1;a>m;a--)
					  {
						if(c[a][n]!=0)
						return 0;
					  }
					 if(c[m][n]==0 || c[m][n]%10!=0)
						return 1;

			       }

			}
			/*******  horizontal movement  *************/
			else  
			{
					// rook movement towards right
			       if(j<n)
			       {
						for(int a=j+1;a<n;a++)
						{
							// checking if path of rook is empty or not.
							if(c[m][a]!=0)
							{ 
								return 0;
							}
						}
		
						if(c[m][n]==0 || c[m][n]%10!=0)
							return 1;
					}
				
				   // rook movement towards left	
			       if(j>n)
			       {
					  for(int a=j-1;a>n;a--)
					  {
							if(c[m][a]!=0)
								return 0;
					  }
					  if(c[m][n]==0 || c[m][n]%10!=0)
						return 1;

			       }

			}
			break;
			
		/******* knight red : Rules compatibility *********/
		case 30:   
		       if(c[m][n]==0||c[m][n]%10!=0)
		       {
					if(i+2==m && j+1==n)
						return 1;
					else
					if(i+2==m && j-1==n)
						return 1;
					else
					if(i+1==m && j-2==n)
						return 1;
					else
					if(i-1==m && j-2==n)
						return 1;
					else
					if(i-2==m && j-1==n)
						return 1;
					else
					if(i-2==m && j+1==n)
						return 1;
					else
					if(i-1==m && j+2==n)
						return 1;
					else
					{
						if(i+1==m && j+2==n)
						return 1;
						else
						return 0;
					}
			}
			else
				return 0;
		
		/******* knight Green : Rules compatibility *********/
		case 33:

		       if(c[m][n]==0||c[m][n]%10==0)
		       {
					if(i+2==m && j+1==n)
						return 1;
					else
					if(i+2==m && j-1==n)
						return 1;
					else
					if(i+1==m && j-2==n)
						return 1;
					else
					if(i-1==m && j-2==n)
						return 1;
					else
					if(i-2==m && j-1==n)
						return 1;
					else
					if(i-2==m && j+1==n)
						return 1;
					else
					if(i-1==m && j+2==n)
						return 1;
					else
					{
						if(i+1==m && j+2==n)
							return 1;
						else
							return 0;
					}
				}
				else
					return 0;
		
		
		/******* bishop red : Rules compatibility *********/
		case 40:
		
			// cross - movement 
			if((i-m)==(j-n) || (m-i)==(j-n))
			{    
				if(m>i)
				{
					if(n>j)
					{
						u=i+1;
						v=j+1;
						for(int r=0;r<(m-i)-1;r++)
						{
							if(c[u++][v++] != 0)
							return 0;
						}
					   if(c[m][n]==0 || c[m][n]%10!=0)
					   return 1;
					   else
					   return 0;

					 }
					else
					 {

						u=i+1;
						v=j-1;
						for(int r=0;r<(m-i)-1;r++)
						{

							if(c[u++][v--] != 0)
							return 0;
						}
					}
				}
				else  // i>m
				{
					if(n>j)
					{
						u=i-1;
						v=j+1;
						for(int r=0;r<(i-m)-1;r++)
						{

							if(c[u--][v++] != 0)
							return 0;
						}
					 }
					 else
					 {
						u=i-1;
						v=j-1;
						for(int r=0;r<(i-m)-1;r++)
						{
						       if(c[u--][v--] != 0)
						       return 0;
						}
					 }


				}

				 if(c[m][n]==0 || c[m][n]%10!=0)
				 return 1;
				 else
				 return 0;


			}
			else
			return 0;
		
		/******* knight Green : Rules compatibility *********/
		case 44:
			if((i-m)==(j-n) || (m-i)==(j-n))
			{ 
				if(m>i)
				{
					if(n>j)
					{
						u=i+1;
						v=j+1;
						for(int r=0;r<(m-i)-1;r++)
						{
							if(c[u++][v++] != 0)
							return 0;
						}
					   if(c[m][n]==0 || c[m][n]%10==0)
							return 1;
					   else
							return 0;

					 }
					else
					 {
			   
						u=i+1;
						v=j-1;
						for(int r=0;r<(m-i)-1;r++)
						{
			
							if(c[u++][v--] != 0)
							return 0;
						}
					}
				}
				else  // i>m
				{
					if(n>j)
					{
						u=i-1;
						v=j+1;
						for(int r=0;r<(i-m)-1;r++)
						{
			
							if(c[u--][v++] != 0)
							return 0;
						}
					 }
					 else
					 {
						u=i-1;
						v=j-1;
						for(int r=0;r<(i-m)-1;r++)
						{
						       if(c[u--][v--] != 0)
						       return 0;
						}
					 }


				}

				 if(c[m][n]==0 || c[m][n]%10==0)
				 return 1;
				 else
				 return 0;
			}
			else
			return 0;
			
			
		case 60:
			if(c[m][n]==0||c[m][n]%10!=0)
			{
				if(i+1==m&&j+1==n)
					return 1;
				else
				if(i+1==m&&j==n)
					return 1;
				else
				if(i+1==m&&j-1==n)
					return 1;
				else
				if(i==m&&j-1==n)
					return 1;
				else
				if(i-1==m&&j-1==n)
					return 1;
				else
				if(i-1==m&&j==n)
					return 1;
				else
				if(i-1==m&&j+1==n)
					return 1;
				else
				{
					if(i==m&&j+1==n)
						return 1;
					else
						return 0;
				}
			}
			else
				return 0;
		
		case 66:
			if(c[m][n]==0||c[m][n]%10==0)
			{
				if((i+1)==m&&(j+1)==n)
					return 1;
				else
				if((i+1)==m&&j==n)
					return 1;
				else
				if((i+1)==m&&j-1==n)
					return 1;
				else
				if(i==m&&j-1==n)
					return 1;
				else
				if(i-1==m&&j-1==n)
					return 1;
				else
				if(i-1==m&&j==n)
					return 1;
				else
				if(i-1==m&&j+1==n)
					return 1;
				else
				{
					if(i==m&&j+1==n)
						return 1;
					else
						return 0;
				}
			}
			else
				return 0;
		
		
		/******* QUEEN : Rules compatibility *********/
		case 50:
		case 55:
		 // elephant red code

			if(j==n) // vertical movement
			{
			       if(m>i)
			       {
				  for(int a=i+1;a<m;a++)
				  {
					if(c[a][n]!=0)
					{ 
					  return 0;
					}
				  }
	
				 if(c[m][n]==0 || c[m][n]%10!=0)
					return 1;

			       }
			       if(i>m)
			       {
					  for(int a=i-1;a>m;a--)
					  {
						   if(c[a][n]!=0)
								return 0;
					  }
					  if(c[m][n]==0 || c[m][n]%10!=0)
						   return 1;

			       }

			}
			else  // for horizontal movement
			if(i==m)
			{
			       if(j<n)
			       {
						for(int a=j+1;a<n;a++)
						{
							if(c[m][a]!=0)
							{ 
								return 0;
							}
        			    }

				   if(c[m][n]==0 || c[m][n]%10!=0)
						return 1;

			       }
			       if(j>n)
			       {
					  for(int a=j-1;a>n;a--)
					  {
						if(c[m][a]!=0)
							return 0;
					  }
      			  	  if(c[m][n]==0 || c[m][n]%10!=0)
							return 1;

			       }

			}
			// camel code
			else
			if((i-m)==(j-n) || (m-i)==(j-n))
			{  
				if(m>i)
				{
					if(n>j)
					{
						u=i+1;
						v=j+1;
						for(int r=0;r<(m-i)-1;r++)
						{
							if(c[u++][v++] != 0)
							return 0;
						}
						if(c[m][n]==0 || c[m][n]%10!=0)
							return 1;
					    else
							return 0;

					 }
					else
					 {
					
						u=i+1;
						v=j-1;
						for(int r=0;r<(m-i)-1;r++)
						{
							if(c[u++][v--] != 0)
							return 0;
						}
					}
				}
				else  // i>m
				{
					if(n>j)
					{
						u=i-1;
						v=j+1;
						for(int r=0;r<(i-m)-1;r++)
						{
			
							if(c[u--][v++] != 0)
							return 0;
						}
					 }
					 else
					 {
						u=i-1;
						v=j-1;
						for(int r=0;r<(i-m)-1;r++)
						{
						       if(c[u--][v--] != 0)
						       return 0;
						}
					 }


				}

				 if(c[m][n]==0 || c[m][n]%10!=0)
				 return 1;
				 else
				 return 0;
			}
			else
			return 0;



		default: return 0;
	  }//sitch end

	  return 0;
	 }  // fun end

int getcolour(int i,int j)            
/** 1 : White
    2 : Black
**/
{

		switch(i)
		{
		case 1:
			switch(j)
			{
			case 1: return 2;
			case 2: return 1;
			case 3: return 2;
			case 4: return 1;
			case 5: return 2;
			case 6: return 1;
			case 7: return 2;
			case 8: return 1;
			}
		case 2:
			switch(j)
			{
			case 1: return 1;
			case 2: return 2;
			case 3: return 1;
			case 4: return 2;
			case 5: return 1;
			case 6: return 2;
			case 7: return 1;
			case 8: return 2;
			}
		case 3:
			switch(j)
			{
			case 1: return 2;
			case 2: return 1;
			case 3: return 2;
			case 4: return 1;
			case 5: return 2;
			case 6: return 1;
			case 7: return 2;
			case 8: return 1;
			}
		case 4:
			switch(j)
			{
			case 1: return 1;
			case 2: return 2;
			case 3: return 1;
			case 4: return 2;
			case 5: return 1;
			case 6: return 2;
			case 7: return 1;
			case 8: return 2;
			}
		case 5:
			switch(j)
			{
			case 1: return 2;
			case 2: return 1;
			case 3: return 2;
			case 4: return 1;
			case 5: return 2;
			case 6: return 1;
			case 7: return 2;
			case 8: return 1;
			}
		case 6:
			switch(j)
			{
			case 1: return 1;
			case 2: return 2;
			case 3: return 1;
			case 4: return 2;
			case 5: return 1;
			case 6: return 2;
			case 7: return 1;
			case 8: return 2;
			}
		case 7:
			switch(j)
			{
			case 1: return 2;
			case 2: return 1;
			case 3: return 2;
			case 4: return 1;
			case 5: return 2;
			case 6: return 1;
			case 7: return 2;
			case 8: return 1;
			}
		case 8:
			switch(j)
			{
			case 1: return 1;
			case 2: return 2;
			case 3: return 1;
			case 4: return 2;
			case 5: return 1;
			case 6: return 2;
			case 7: return 1;
			case 8: return 2;
			}
		default: 
		}
		return 0;
	 }
	 
void move(int i,int j,int m,int n,int c1,int c2,int c3,int c4)
{

		if(getcolour(c1,c2)==1)
		{
			clear(i,j);
		}
		if(getcolour(c1,c2)==2)
		{
			setviewport(i+1,j+1,i+39,j+39,1);
			clearviewport();
			setviewport(0,0,639,479,1);
		}
		if(getcolour(c3,c4)==1)
		{
			clear(m,n);
		}
		if(getcolour(c3,c4)==2)
		{
			setviewport(m+1,n+1,m+39,n+39,1);
			clearviewport();
			setviewport(0,0,639,479,1);
		}


			switch(c[c3][c4])
			{
				case 10: solderred(m,n);break;
				case 11: soldergreen(m,n);break;
				case 20: elephantred(m,n);break;
				case 22: elephantgreen(m,n);break;
				case 30: horsered(m,n);break;
				case 33: horsegreen(m,n);break;
				case 40: camalred(m,n);break;
				case 44: camalgreen(m,n);break;
				case 60: kingred(m,n);break;
				case 66: kinggreen(m,n);break;
				case 50: queenred(m,n);break;
				case 55: queengreen(m,n);break;
				defalut: break;
			}
}

int check(int p) 
/*** return value ***/  
/*** 0 => check   ***/
/*** 1 => no check ***/
{

		int x,y;
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				if(p==2)
				{
		
				switch(c[i][j])
				{
				case 11: /**** soilder green tryin to check red king   ********/

					if(c[i-1][j+1]==60||c[i-1][j-1]==60)
						return 0;
					break;
				case 22: /****    inside rook section!!   *********/ 

					for(x=j+1;x<=8;x++) // right move of King
					{

						if(c[i][x]!=0)
						{
							if(c[i][x]==60)
								return 0;
							else
								break;
						}
					}
					for(x=j-1;x>=1;x--) // left move of King
					{
						if(c[i][x]!=0)
						{
							if(c[i][x]==60)
								return 0;
							else
								break;
						}
					}
					for(x=i+1;x<=8;x++) // Up move of king
					{
						if(c[x][j]!=0)
						{

							if(c[x][j]==60)
								return 0;
							else
								break;
						}
					}
					for(x=i-1;x>=1;x--) // down movt
					{
				  
						if(c[x][j]!=0)
						{
							if(c[x][j]==60)
								return 0;
							else
								break;
						}
					}


					break;
			       case 44:
					// for upright;
					for(x=i+1,y=j+1;x<=8&&y<=8;x++,y++)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
								return 0;
							else
								break;
						}
					}
					// upleft
					for(x=i+1,y=j-1;x<=8 && y >=1; x++,y--)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
							return 0;
							else
							break;
						}
					}
					// bottom right
					for(x=i-1,y=j+1;x>=1&&y<=8; x--,y++)
					{
				     	if(c[x][y]!=0)
						{
							if(c[x][y]==60)
								return 0;
							else
								break;
						}
					}
					// bottom left
					for(x=i-1,y=j-1;x>=1&&y>=1;x--,y--)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
								return 0;
							else
								break;
						}
					}
					break;
			      case 33:
						if(c[i+2][j+1]==60)
							return 0;
						else
						if(c[i+2][j-1]==60)
							return 0;
						else
						if(c[i+1][j-2]==60)
							return 0;
						else
						if(c[i-1][j-2]==60)
							return 0;
						else
						if(c[i-2][j-1]==60)
							return 0;
						else
						if(c[i-2][j+1]==60)
							return 0;
						else
						if(c[i-1][j+2]==60)
							return 0;
						else
						{
							if(c[i+1][j+2]==60)
								return 0;
							else
							{
							}
							//return 1;
						}
						   break;

			  case 55:
					for(x=j+1;x<=8;x++) // right movement
					{

						if(c[i][x]!=0)
						{
							if(c[i][x]==60)
							return 0;
							else
							break;
						}
					}
					for(x=j-1;x>=1;x--) // left
					{
						if(c[i][x]!=0)
						{
							if(c[i][x]==60)
							return 0;
							else
							break;
						}
					}
					for(x=i+1;x<=8;x++) // up movement
					{
						if(c[x][j]!=0)
						{

							if(c[x][j]==60)
							return 0;
							else
							break;
						}
					}
					for(x=i-1;x>=1;x--) // down movt
					{
				   //	printf("\t down");

						if(c[x][j]!=0)
						{
							if(c[x][j]==60)
							return 0;
							else
							break;
						}
					}
					// for upright;
					for(x=i+1,y=j+1;x<=8&&y<=8;x++,y++)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
							return 0;
							else
							break;
						}
					}
					// upleft
					for(x=i+1,y=j-1;x<=8 && y >=1; x++,y--)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
							return 0;
							else
							break;
						}
					}
					// bottom right
					for(x=i-1,y=j+1;x>=1&&y<=8; x--,y++)
					{
				     //	printf("\n a");
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
							return 0;
							else
							break;
						}
					}
					// bottom left
					for(x=i-1,y=j-1;x>=1&&y>=1;x--,y--)
					{
				      //	printf("\n ala ");
						if(c[x][y]!=0)
						{
							if(c[x][y]==60)
							return 0;
							else
							break;
						}
					}
					break;

				case 66:

						if(c[i+1][j+1]==60)
							return 0;
						else
						if(c[i+1][j]==60)
							return 0;
						else
						if(c[i+1][j-1]==60)
							return 0;
						else
						if(c[i][j-1]==60)
							return 0;
						else
						if(c[i-1][j-1]==60)
							return 0;
						else
						if(c[i-1][j]==60)
							return 0;
						else
						if(c[i-1][j+1]==60)
							return 0;
						else
						{
							if(c[i][j+1]==60)
								return 0;
							else
							{}
						}


			   default: break;
				} // switch
			    }  // if

			    if(p==1)
			    {
				switch(c[i][j])
				{
				case 10: // soilder green tryin to check red king

					if(c[i-1][j+1]==66||c[i-1][j-1]==66)
					return 0;
					break;
				case 20:
				    //    inside rook section!! 

					for(x=j+1;x<=8;x++) // right movement
					{

						if(c[i][x]!=0)
						{
							if(c[i][x]==66)
							return 0;
							else
							break;
						}
					}
					for(x=j-1;x>=1;x--) // left
					{
						if(c[i][x]!=0)
						{
							if(c[i][x]==66)
							return 0;
							else
							break;
						}
					}
					for(x=i+1;x<=8;x++) // up movement
					{
						if(c[x][j]!=0)
						{

							if(c[x][j]==66)
							return 0;
							else
							break;
						}
					}
					for(x=i-1;x>=1;x--) // down movt
					{
				   //	printf("\t down");

						if(c[x][j]!=0)
						{
							if(c[x][j]==66)
							return 0;
							else
							break;
						}
					}


					break;
			       case 40:
					// for upright;
					for(x=i+1,y=j+1;x<=8&&y<=8;x++,y++)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// upleft
					for(x=i+1,y=j-1;x<=8 && y >=1; x++,y--)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// bottom right
					for(x=i-1,y=j+1;x>=1&&y<=8; x--,y++)
					{
				     //	printf("\n a");
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// bottom left
					for(x=i-1,y=j-1;x>=1&&y>=1;x--,y--)
					{
				      //	printf("\n ala ");
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					break;
			      case 30:
						if(c[i+2][j+1]==66)
							return 0;
						else
						if(c[i+2][j-1]==66)
							return 0;
						else
						if(c[i+1][j-2]==66)
							return 0;
						else
						if(c[i-1][j-2]==66)
							return 0;
						else
						if(c[i-2][j-1]==66)
							return 0;
						else
						if(c[i-2][j+1]==66)
							return 0;
						else
						if(c[i-1][j+2]==66)
							return 0;
						else
						{
							if(c[i+1][j+2]==66)
								return 0;
							else
							{
							}
							//return 1;
						}
						   break;

			  case 50:
					for(x=j+1;x<=8;x++) // right movement
					{

						if(c[i][x]!=0)
						{
							if(c[i][x]==66)
								return 0;
							else
								break;
						}
					}
					for(x=j-1;x>=1;x--) // left
					{
						if(c[i][x]!=0)
						{
							if(c[i][x]==66)
								return 0;
							else
								break;
						}
					}
					for(x=i+1;x<=8;x++) // up movement
					{
						if(c[x][j]!=0)
						{

							if(c[x][j]==66)
								return 0;
							else
								break;
						}
					}
					for(x=i-1;x>=1;x--) // down movt
					{
			
						if(c[x][j]!=0)
						{
							if(c[x][j]==66)
							return 0;
							else
							break;
						}
					}
					// for upright;
					for(x=i+1,y=j+1;x<=8&&y<=8;x++,y++)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// upleft
					for(x=i+1,y=j-1;x<=8 && y >=1; x++,y--)
					{
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// bottom right
					for(x=i-1,y=j+1;x>=1&&y<=8; x--,y++)
					{
				     //	printf("\n a");
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					// bottom left
					for(x=i-1,y=j-1;x>=1&&y>=1;x--,y--)
					{
				      //	printf("\n ala ");
						if(c[x][y]!=0)
						{
							if(c[x][y]==66)
							return 0;
							else
							break;
						}
					}
					break;

				case 60:

						if(c[i+1][j+1]==66)
							return 0;
						else
						if(c[i+1][j]==66)
							return 0;
						else
						if(c[i+1][j-1]==66)
							return 0;
						else
						if(c[i][j-1]==66)
							return 0;
						else
						if(c[i-1][j-1]==66)
							return 0;
						else
						if(c[i-1][j]==66)
							return 0;
						else
						if(c[i-1][j+1]==66)
							return 0;
						else
						{
							if(c[i][j+1]==66)
								return 0;
							else
							{}
						}


			   default: break;
				} // switch
			    }  // if

			}
		  }

  return 1;
 }

void main()
{
	int i,xm,ym,gmode,gd=DETECT;
	char n1[10],n2[10],n4[10],n3[10];
	char m1[10],m2[10],m4[10],m3[10];

	char r1,r2,r3,r4,g1,g2,g3,g4;

	initgraph(&gd,&gmode,"c:\\tc\\bgi");
	setcolor(WHITE);
	setbkcolor(BLACK);
	xm=getmaxx();
	ym=getmaxy();
	rectangle(5,5,xm-5,ym-5);

/****** Outer layout of board ************/

	rectangle(160,20,480,340);  

/******  horizontal lines     ***********/

	for(i=200;i<=480;i=i+40)
	{
		line(i,20,i,340);
	}
	
/*****   vertical lines        **********/
	for(i=60;i<=340;i=i+40)
	{
		line(160,i,480,i);
	}
	
	
/*******   Chequred Board      *********/	
	
	for(i=22;i<=340;i=i+80)
		floodfill(162,i,WHITE);

	for(i=62;i<=340;i=i+80)
		floodfill(202,i,WHITE);

	for(i=22;i<=340;i=i+80)
		floodfill(242,i,WHITE);

	for(i=62;i<=340;i=i+80)
		floodfill(282,i,WHITE);

	for(i=22;i<=340;i=i+80)
		floodfill(322,i,WHITE);

	for(i=62;i<=340;i=i+80)
		floodfill(362,i,WHITE);

	for(i=22;i<=340;i=i+80)
		floodfill(402,i,WHITE);

	for(i=62;i<=340;i=i+80)
		floodfill(442,i,WHITE);

	INITIAL_SET();

//	matrix();


/*******       Board Numbering    **********/
	outtextxy(175,350,"a");
	outtextxy(215,350,"b");
	outtextxy(255,350,"c");
	outtextxy(295,350,"d");
	outtextxy(335,350,"e");
	outtextxy(375,350,"f");
	outtextxy(415,350,"g");
	outtextxy(455,350,"h");

	outtextxy(490,35,"8");
	outtextxy(490,75,"7");
	outtextxy(490,115,"6");
	outtextxy(490,155,"5");
	outtextxy(490,195,"4");
	outtextxy(490,235,"3");
	outtextxy(490,275,"2");
	outtextxy(490,315,"1");


	outtextxy(200,370,"Player1:  Move");
	outtextxy(335,370," to ");

	outtextxy(200,395,"Player2:  Move");
	outtextxy(335,395," to ");

	A:

	r1=getch();
	if(r1==8)
	{
		goto A;

	}
	sprintf(n1,"%c",r1);
	outtextxy(320,370,n1);

	r2=getch();
	if(r2==8)
	{
	       viewp1();
	       goto A;
	}
	sprintf(n2,"%c",r2);
	outtextxy(328,370,n2);

	r3=getch();
	if(r3==8)
	{
	    viewp1();
	    goto A;
	}
	sprintf(n3,"%c",r3);
	outtextxy(370,370,n3);

	r4=getch();
	if(r4==8)
	{
	   viewp1();
	   goto A;
	}
	sprintf(n4,"%c",r4);
	outtextxy(378,370,n4);

	E:
	char ttt=getch();
	if(ttt==27)
	exit(0);

	if(ttt==13)
	{
	    if(validinput(tolower(r1),r2,tolower(r3),r4)==0)
	    {
			viewp1();
			goto A;
	    }
	    //
	    coordinate(r1,r2,&rs1,&rs2,&rv1,&rv2); // rs1 rs2 index's
	    coordinate(r3,r4,&rs3,&rs4,&rv3,&rv4);
	    if(legal(rs1,rs2,rs3,rs4,1)==1)
	    {
		c[rs3][rs4]=c[rs1][rs2];
		c[rs1][rs2]=0;

			if(check(2)==1)
			{
				move(rv1,rv2,rv3,rv4,rs1,rs2,rs3,rs4);
			}
			else
			{
				 //	outtextxy(335,395," ");
				c[rs1][rs2]=c[rs3][rs4];
				c[rs3][rs4]=0;
				viewp1();
				goto A;
			}

	    }
	    else
	    {
			viewp1();
			goto A;
	    }

       }
       else
       {
		if(ttt==8)
		{
			viewp1();
			goto A;
		}
	    goto E;
	}



	B:
	setcolor(GREEN);
	g1=getch();
	if(g1==8)
	{
		goto B;

	}
	sprintf(m1,"%c",g1);
	outtextxy(320,395,m1);

	g2=getch();
	if(g2==8)
	{
	       viewp2();
	       goto B;
	}
	sprintf(m2,"%c",g2);
	outtextxy(328,395,m2);

	g3=getch();
	if(g3==8)
	{
	    viewp2();
	    goto B;
	}
	sprintf(m3,"%c",g3);
	outtextxy(370,395,m3);

	g4=getch();
	if(g4==8)
	{
	   viewp2();
	   goto B;
	}
	sprintf(m4,"%c",g4);
	outtextxy(378,395,m4);

	D:
	char tt=getch();
	if(tt==27)
	exit(0);

	if(tt==13)
	{
	    if(validinput(tolower(g1),g2,tolower(g3),g4)==0)
	    {
			viewp2();
			goto B;
	    }
	    //
	    coordinate(g1,g2,&gs1,&gs2,&gv1,&gv2);
	    coordinate(g3,g4,&gs3,&gs4,&gv3,&gv4);
	    if(check(1)==0)
	    {
			outtextxy(230,430," CHECK ");
	    }
	    if(legal(gs1,gs2,gs3,gs4,2)==1)
	    {
			c[gs3][gs4]=c[gs1][gs2];
			c[gs1][gs2]=0;

			if(check(1)==1)
			{
			move(gv1,gv2,gv3,gv4,gs1,gs2,gs3,gs4);
			}
			else
			{
				c[gs1][gs2]=c[gs3][gs4];
				c[gs3][gs4]=0;
				viewp2();
				goto B;
			}

	    }
	    else
	    {
			viewp2();
			goto B;
	    }

	}
	else
	{
	    goto D;
	}

	viewp1();
	viewp2();
	goto A;

}
