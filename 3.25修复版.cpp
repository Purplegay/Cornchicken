#include<iostream>
#include<string>
#include <stdlib.h>
#include <math.h>
#include<windows.h> 
#include<fstream>
#include <io.h>
#include "hp.h"
#include "mp.h"
#include "EXP.h"
#include <stdio.h> 
using namespace std;
using std::string;
int main()
{
    _finddata_t file;
	int k;
    k=_findfirst("save.dat", &file);
    if (k==-1) 
	{    
		const char* path ="save.dat";
	    ofstream fout( path );
	    fout.close();
    }
	cout<<"�밴���������"<<endl;
    int hp=210,mp=210,ma=0,attack=30,attackd=30,hpd=210,money=1000,i,savedat=0,mpd=210,plusmoney=200,goldmoney=300,monster_hp=180,monster_at=20;
	int exp1=0/*������*/,exp2=0/*ɱ�ֻ�þ���*/,exp3=1/*�������辭��*/,lv=1;
    string skilla="�ö�",skillb="��İ����",skillc="EX��ର�",skilld="����һ��˧";
    string startkey="1",savekey; 
    double sav[20];
    int gameturn=1; 
    sav[1]=hp;
	sav[2]=mp;
	sav[3]=money;
	sav[4]=attack;
	sav[5]=monster_hp;
	sav[6]=monster_at;
	sav[7]=plusmoney;
	sav[8]=goldmoney;
	sav[9]=ma;
	sav[10]=gameturn;
	sav[11]=lv;
	sav[12]=exp1;
	sav[13]=exp3;	
    double skmp_mBuff=1;
    double skmp_aBuff=1;
    int skmpa=25,skmpb=40,skmpc=80,skmpd=100;
    int mpdamage_a=50/*�������˺�*/,mpdamage_b=0.25/*buff����,����25%�����˺�,����1�غ�*/, mpdamage_c=100,mpdamage_d=250;
    int mpdamage_ad=50; 
    getchar();
    system("cls");
    cout<<"�Ƿ��ȡ�浵:1.��,2.����"<<endl; 
    cin>>savedat;
	if (savedat==1&&k!=-1){
        ifstream infile("save.dat",ios::in);
		for(i=1;i<=13;i++)
	        infile>>sav[i];
	    hp=sav[1];
		mp=sav[2];
		money=sav[3];
		attack=sav[4];
		monster_hp=sav[5];
		monster_at=sav[6];
		plusmoney=sav[7];
		goldmoney=sav[8];
		ma=sav[9];
		gameturn=sav[10];
		lv=sav[11];
	    exp1=sav[12];
	    exp3=sav[13];		
		infile.close();
	} 
    while (startkey=="1"){

    exp2=monster_hp*monster_at/5000;
	if (exp2==0)
		exp2=1;
	cout<<"Lv:"<<lv<<" "<<"���Ѫ��Ϊ"<<hp<<endl; 
    /*Ѫ����ʾ*/
    pr(hp,hp); 
    cout<<"���ħ��ֵΪ"<<mp<<endl; 
	    /*������ʾ*/
	prw(mp,mp);
    cout<<"��ľ���"<<endl; 
	    /*��������ʾ*/
	pre(exp1,exp3);
    cout<<"��Ĺ�����Ϊ"<<attack<<endl;
    cout<<"��ķ�ǿΪ"<<ma<<endl;
    cout<<"��Ľ��Ϊ"<<money<<endl;
    cout<<"����1�����������룬����0����"<<endl;
    string shop="0";
    cin>>shop;
    system("cls");
    while (shop!="0"){  
              cout<<"��1����300hp,������600���"<<endl
                     <<"��2����30����������������200���"<<endl
                     <<"��3����40ħ��ֵ��������300���"<<endl
                     <<"��4����60��ǿ��������400���"<<endl 
                     <<"��0�˳�"<<endl;
              cin>>shop;
              if (shop=="2"&&money>=200){
                       attack+=30;
                       money-=200;
                       }
              else if(shop=="1"&&money>=600){
                       hp+=300;
                       money-=600;
                       }
              else if(shop=="3"&&money>=300){
              	       mp+=40;
              	       money-=300;
			  }
			  else if (shop=="4"&&money>=400){
			  	       ma+=60;
			  	       money-=400;
			  } 
              else if(shop=="0"){
                       break;
                       }
              else   {
                        cout<<"�������" <<endl; 
              } 
              cout<<"Lv:"<<lv<<" "<<"���Ѫ��Ϊ"<<hp<<endl;
    /*Ѫ����ʾ*/
    pr (hp,hp);
    cout<<"���ħ��ֵΪ"<<mp<<endl; 
	    /*������ʾ*/
	prw(mp,mp);
	cout<<"��ľ���"<<endl; 
	    /*��������ʾ*/
	pre(exp1,exp3);
    cout<<"��Ĺ�����Ϊ"<<attack<<endl;
    cout<<"��ķ�ǿΪ"<<ma<<endl;
    cout<<"��Ľ��Ϊ"<<money<<endl;
    cout<<"�Ƿ��������"
        <<"0.�˳�"<<endl
        <<"1�����������ּ�.����"<<endl;
    cin>>shop;
    system("cls");
              
    }    
    cout<<"׼��ս���������������"<<endl;
    getchar();
	system("cls");
    int monster_hpd;
    monster_hp=monster_hp+lv*pow(1.05,pow(lv,0.5));
    monster_at+=10;
    cout<<"ս����ʼ"<<endl;
    cout<<"��"<<gameturn<<"��" <<endl; 
    hpd=hp;
    mpd=mp;
    attackd=attack;
    monster_hpd= monster_hp;
    mpdamage_ad=mpdamage_a;
    int turnskillakuya=0;
    int turngame=0;
    double prehp=(80+2*ma)*skmp_mBuff;
	while (monster_hpd>0&&hpd>0){
		if (turnskillakuya<=0){
		   	skmp_mBuff=1;
		   	turnskillakuya=0;
	     }
		string choice;
        cout<<"�����Ѫ��Ϊ"<<monster_hpd<<"/"<<monster_hp<<endl; 
        pr(monster_hpd,monster_hp);
	    cout<<"Lv:"<<lv<<" "<<"�ҵ�Ѫ��Ϊ"<<hpd<<"/"<<hp<<endl; 
	    pr(hpd,hp);
	    cout<<"�ҵ�ħ��ֵΪ"<<mpd<<"/"<<mp<<endl; 	
	    prw(mpd,mp);
		cout<<"��ľ���"<<endl; 
	    /*��������ʾ*/
	    pre(exp1,exp3);
	    turngame+=1;
        cout<<"��"<<turngame<<"��"<<endl; 	
        cout<<"ѡ��1��������������������ѡ��2׼���ͷ�ħ��"<<endl;
     	cin>>choice;
	    system("cls");
	    if (choice!="2"){
		    cout<<"�����ܵ�"<<attackd<<"�����˺�"<<endl; 
	        monster_hpd-=attackd;
			Sleep(1500);
		    turnskillakuya-=1;	
		}
        else{
    	    cout<<"�ҵ�ħ��ֵΪ"<<mpd<<"/"<<mp<<endl;
    	    prw(mpd,mp);
	        cout<<"��������ȡ��������������"<<endl;
    	    cout<<"ѡ��q"<<" "<<skilla<<" "<<"����"<<skmpa<<"ħ��ֵ"<<endl
		        <<"���"<<(mpdamage_ad+0.1*ma)*skmp_mBuff<<"��ħ���˺�(0.1��ǿ�ӳ�)���ٴ�ʹ�û�����50��ü����˺���"<<endl<<endl
		        <<"ѡ��w"<<" "<<skillb<<" "<<"����"<<skmpb<<"ħ��ֵ"<<endl
		        <<"�»غϷ����˺�����25%"<<endl<<endl
		        <<"ѡ��e"<<" "<<skillc<<" "<<"����"<<skmpc<<"ħ��ֵ"<<endl
		        <<"���"<<(mpdamage_c+2*ma)*skmp_mBuff<<"��ħ���˺�(2.0��ǿ�ӳ�)�����ָ�"<<prehp<<"������ֵ"<<endl<<endl
		        <<"ѡ��r"<<" "<<skilld<<" "<<"����"<<skmpd<<"ħ��ֵ"<<endl
			    <<"���"<<(mpdamage_d+ma)*skmp_mBuff<<"��ħ���˺�(1.0��ǿ�ӳ�),��������ɹ�������ʧ����ֵ��30%�˺�"<<endl<<endl;
    	    char choicemp;
		    cin>>choicemp;
		    system("cls");

		    switch(choicemp){
		     	case'q':
		     	    if(mpd>=skmpa){
					
				       mpd-=skmpa;
				       cout<<"�����ܵ�"<<(mpdamage_ad+ma*0.1)*skmp_mBuff<<"��ħ���˺�"<<endl;   
				       monster_hpd=monster_hpd-(mpdamage_ad+ma*0.1)*skmp_mBuff; 
					   Sleep(1500);                   
                       if (skilla=="�ö�"){
                	       mpdamage_ad+=50;
                	       
				        } 
				    }
				    else{
				    	cout<<"��û���㹻����ֵ�����Զ�����������"<<endl; 				    	
		                cout<<"�����ܵ�"<<attackd<<"������"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd;
				    	
					}
				   turnskillakuya=0;              
				   break;
			    case'w':
			    	turnskillakuya=0; 
				    if(mpd>=skmpb){
				    	mpd-=skmpb;
					   if (skillb=="��İ����"){
					         cout<<"ħ���˺������"<<endl;
					         Sleep(1500);
                	         skmp_mBuff=1.25;
                	         turnskillakuya=1; 
				        }
				    }
				    else{
				    	cout<<"��û���㹻����ֵ�����Զ�����������"<<endl;  				    	
		                cout<<"�����ܵ�"<<attackd<<"������"<<endl; 
				        Sleep(1500);
	                    monster_hpd-=attackd;
	                    turnskillakuya=0; 
					    }				
				    break;
			    case'e':
				    if(mpd>=skmpc){
				             mpd-=skmpc;
				             monster_hpd=monster_hpd-(mpdamage_c+ma*2)*skmp_mBuff; 
				             if ((prehp+hpd)>hp){
				             	cout<<"�����ܵ�"<<(mpdamage_c+ma*2)*skmp_mBuff<<"��ħ���˺�,�һָ���"<<hp-hpd<<"������ֵ"<<endl;
				             	hpd=hp;
				                Sleep(1500);
							 }
							 else{
							    hpd=hpd+prehp;
								cout<<"�����ܵ�"<<(mpdamage_c+ma*2)*skmp_mBuff<<"��ħ���˺�,�һָ���"<<prehp<<"������ֵ"<<endl;
				                Sleep(1500);
				                 }
				             }
				    else{
				    	cout<<"��û���㹻����ֵ�����Զ�����������"<<endl;  				    	
		                cout<<"�����ܵ�"<<attackd<<"������"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd;
					    }
				    turnskillakuya=0;
				    break;
			    case'r':
			    	if(mpd>=skmpd){
				             mpd-=skmpd;
				             cout<<"�����ܵ�"<<(mpdamage_d+ma)*skmp_mBuff+((monster_hp-monster_hpd)*0.3)<<"ħ���˺�"<<endl;
				             Sleep(1500);
				             monster_hpd=monster_hpd-(mpdamage_d+ma)*skmp_mBuff-((monster_hp-monster_hpd)*0.3); 
				             }
				    else{
				    	cout<<"��û���㹻����ֵ�����Զ�����������"<<endl; 
		                cout<<"�����ܵ�"<<attackd<<"������"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd; 
					    }
				    turnskillakuya=0;
				    break;
			    default:
			        cout<<"�����ܵ�"<<attackd<<"�������˺�"<<endl; 
			        Sleep(1500);
	                monster_hpd-=attackd;
				    turnskillakuya=0;
				    break;	
		}/*switch*/ 
	}/*else�ҵ�ħ��ֵ*/ 
	    if(monster_hpd>0){
	    hpd-=monster_at;
	    cout<<"���ܵ��˹���"<<monster_at<<"���˺�"<<endl; 
		Sleep(1500);
	    system("cls");
	    }
	}
    if(monster_hpd<=0){
      	exp1=exp1+exp2;
		if(exp3<=exp1)
	{	
		lv=lv+exp1/exp3;
		cout<<"�������ˣ��ȼ�Ϊ"<<lv<<endl;
		cout<<"����Լ����Ե�"<<endl;
		/* ���Ե������Լ�����*/
		hp=hp+30;
		mp=mp+50;
		exp1=exp1-exp3;
		exp3=exp3+pow(exp3,0.5);
	} 	
		cout<<"�����Ѫ��Ϊ0,ս��ʤ����"<<endl; 
   	    money+=goldmoney;
   	    plusmoney*=1.25;
   	    goldmoney+=plusmoney;
   	    gameturn+=1;
   	    cout<<"�Ƿ񱣴棿1���棬�������ּ�������"<<endl;
		cin>>savekey; 
		if(savekey!="1"){
	         system("cls");
	    	}
	    cout<<"�Ƿ����,1�������������ּ��˳�"<<endl; 
	    cin>>startkey;
	}
	if(hpd<=0){
		cout<<"�����Ѫ��Ϊ"<<monster_hpd<<"/"<<monster_hp<<endl; 
        pr(monster_hpd,monster_hp);
      	cout<<"���Ѫ��Ϊ0,ս��ʧ�ܡ�"<<endl; 
		Sleep(1500);
      	cout<<"��1��Ϸ�������ص�"<<" "<<"���������ּ�������Ϸ"<<endl; 
      	cin>>startkey;
		savekey="0";
		ifstream infile("save.dat",ios::in);
		for(i=1;i<=13;i++)
	        infile>>sav[i];
	    hp=sav[1];
		mp=sav[2];
		money=sav[3];
	    attack=sav[4];
	    monster_hp=sav[5];
	    monster_at=sav[6];
	    plusmoney=sav[7];
		goldmoney=sav[8];
		ma=sav[9];
		gameturn=sav[10];
	    lv=sav[11];
	    exp1=sav[12];
	    exp3=sav[13];	
		
        infile.close(); 
	}
		if(savekey=="1") {
			system("cls");
	        ofstream outfile("save.dat",ios::out);
		    sav[1]=hp;
		    sav[2]=mp;
		    sav[3]=money;
		    sav[4]=attack;
		    sav[5]=monster_hp;
	        sav[6]=monster_at;
		    sav[7]=plusmoney;
		    sav[8]=goldmoney;
			sav[9]=ma; 
			sav[10]=gameturn;
			sav[11]=lv;
	        sav[12]=exp1;
	        sav[13]=exp3;	
	        for(i=1;i<=13;i++){
	            outfile<<sav[i]<<endl;
	           }
	        outfile.close();
		    }
	     
     }/*�����startkey����*/ 

   	
    return 0;
}
