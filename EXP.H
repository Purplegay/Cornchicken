#include<iostream>
#include<windows.h> 
#include <stdlib.h>
using namespace std;
int pre(int a,int b)
{
	int i;
	double m;
	HANDLE consolehwnd;
    consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);
    m=(a*1.0/b)*10;
	if ((m-((a*10)/b))>=0.5)
	{
		m=((a*10)/b)+1;
	}
	if ((m<0.5)&&(m>0))
		m=1;
    if (m>3)
    {
	    for (i=1;i<=m;i++)
		{
		     cout<<"#";
		}
    }
	else  
	{   SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE); 
        for (i=1;i<=m;i++)
		{
		     cout<<"#";
		}
	}
	    SetConsoleTextAttribute(consolehwnd,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
		for (i=1;i<=(10-m);i++)
		{
			cout<<"#";
		}
    cout<<endl;
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	return 0;



}