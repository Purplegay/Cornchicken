#include<windows.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;
int prw(int a,int b){
	int i;
	double n;
	HANDLE consolehwnd;
    consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consolehwnd,FOREGROUND_BLUE);
    n=(a*1.0/b)*10;
	if ((n-((a*10)/b))>=0.5)
	{
		n=((a*10)/b)+1;
	}
	if ((n<0.5)&&(n>0))
		n=1;
    if (n>3)
    {
	    for (i=1;i<=n;i++)
		{
		     cout<<"#";
		}
    }
	else  
	{   SetConsoleTextAttribute(consolehwnd,FOREGROUND_RED); 
        for (i=1;i<=n;i++)
		{
		     cout<<"#";
		}
	}
	    SetConsoleTextAttribute(consolehwnd,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
		for (i=1;i<=(10-n);i++)
		{
			cout<<"#";
		}
    cout<<endl;
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
	return 0;
} 
