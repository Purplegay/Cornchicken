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
	cout<<"请按任意键继续"<<endl;
    int hp=210,mp=210,ma=0,attack=30,attackd=30,hpd=210,money=1000,i,savedat=0,mpd=210,plusmoney=200,goldmoney=300,monster_hp=180,monster_at=20;
	int exp1=0/*自身经验*/,exp2=0/*杀怪获得经验*/,exp3=1/*升级所需经验*/,lv=1;
    string skilla="妹抖",skillb="妈的阿库娅",skillc="EX咖喱棒",skilld="董文一最帅";
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
    int mpdamage_a=50/*逐渐增加伤害*/,mpdamage_b=0.25/*buff技能,增加25%法术伤害,持续1回合*/, mpdamage_c=100,mpdamage_d=250;
    int mpdamage_ad=50; 
    getchar();
    system("cls");
    cout<<"是否读取存档:1.是,2.不是"<<endl; 
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
	cout<<"Lv:"<<lv<<" "<<"你的血量为"<<hp<<endl; 
    /*血量表示*/
    pr(hp,hp); 
    cout<<"你的魔法值为"<<mp<<endl; 
	    /*蓝条表示*/
	prw(mp,mp);
    cout<<"你的经验"<<endl; 
	    /*经验条表示*/
	pre(exp1,exp3);
    cout<<"你的攻击力为"<<attack<<endl;
    cout<<"你的法强为"<<ma<<endl;
    cout<<"你的金币为"<<money<<endl;
    cout<<"输入1或其他键进入，输入0跳过"<<endl;
    string shop="0";
    cin>>shop;
    system("cls");
    while (shop!="0"){  
              cout<<"按1购买300hp,并消耗600金币"<<endl
                     <<"按2购买30物理攻击力，并消耗200金币"<<endl
                     <<"按3购买40魔法值，并消耗300金币"<<endl
                     <<"按4购买60法强，并消耗400金币"<<endl 
                     <<"按0退出"<<endl;
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
                        cout<<"你的余额不足" <<endl; 
              } 
              cout<<"Lv:"<<lv<<" "<<"你的血量为"<<hp<<endl;
    /*血量表示*/
    pr (hp,hp);
    cout<<"你的魔法值为"<<mp<<endl; 
	    /*蓝条表示*/
	prw(mp,mp);
	cout<<"你的经验"<<endl; 
	    /*经验条表示*/
	pre(exp1,exp3);
    cout<<"你的攻击力为"<<attack<<endl;
    cout<<"你的法强为"<<ma<<endl;
    cout<<"你的金币为"<<money<<endl;
    cout<<"是否继续购买？"
        <<"0.退出"<<endl
        <<"1或者其他数字键.继续"<<endl;
    cin>>shop;
    system("cls");
              
    }    
    cout<<"准备战斗，按任意键继续"<<endl;
    getchar();
	system("cls");
    int monster_hpd;
    monster_hp=monster_hp+lv*pow(1.05,pow(lv,0.5));
    monster_at+=10;
    cout<<"战斗开始"<<endl;
    cout<<"第"<<gameturn<<"关" <<endl; 
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
        cout<<"怪物的血量为"<<monster_hpd<<"/"<<monster_hp<<endl; 
        pr(monster_hpd,monster_hp);
	    cout<<"Lv:"<<lv<<" "<<"我的血量为"<<hpd<<"/"<<hp<<endl; 
	    pr(hpd,hp);
	    cout<<"我的魔法值为"<<mpd<<"/"<<mp<<endl; 	
	    prw(mpd,mp);
		cout<<"你的经验"<<endl; 
	    /*经验条表示*/
	    pre(exp1,exp3);
	    turngame+=1;
        cout<<"第"<<turngame<<"轮"<<endl; 	
        cout<<"选择1或其他键进行物理攻击，选择2准备释放魔法"<<endl;
     	cin>>choice;
	    system("cls");
	    if (choice!="2"){
		    cout<<"怪物受到"<<attackd<<"物理伤害"<<endl; 
	        monster_hpd-=attackd;
			Sleep(1500);
		    turnskillakuya-=1;	
		}
        else{
    	    cout<<"我的魔法值为"<<mpd<<"/"<<mp<<endl;
    	    prw(mpd,mp);
	        cout<<"按其他键取消并进行物理攻击"<<endl;
    	    cout<<"选择q"<<" "<<skilla<<" "<<"消耗"<<skmpa<<"魔法值"<<endl
		        <<"造成"<<(mpdamage_ad+0.1*ma)*skmp_mBuff<<"点魔法伤害(0.1法强加成)，再次使用会增加50点该技能伤害。"<<endl<<endl
		        <<"选择w"<<" "<<skillb<<" "<<"消耗"<<skmpb<<"魔法值"<<endl
		        <<"下回合法术伤害增加25%"<<endl<<endl
		        <<"选择e"<<" "<<skillc<<" "<<"消耗"<<skmpc<<"魔法值"<<endl
		        <<"造成"<<(mpdamage_c+2*ma)*skmp_mBuff<<"点魔法伤害(2.0法强加成)并最多恢复"<<prehp<<"点生命值"<<endl<<endl
		        <<"选择r"<<" "<<skilld<<" "<<"消耗"<<skmpd<<"魔法值"<<endl
			    <<"造成"<<(mpdamage_d+ma)*skmp_mBuff<<"点魔法伤害(1.0法强加成),并额外造成怪物已损失体力值的30%伤害"<<endl<<endl;
    	    char choicemp;
		    cin>>choicemp;
		    system("cls");

		    switch(choicemp){
		     	case'q':
		     	    if(mpd>=skmpa){
					
				       mpd-=skmpa;
				       cout<<"怪物受到"<<(mpdamage_ad+ma*0.1)*skmp_mBuff<<"点魔法伤害"<<endl;   
				       monster_hpd=monster_hpd-(mpdamage_ad+ma*0.1)*skmp_mBuff; 
					   Sleep(1500);                   
                       if (skilla=="妹抖"){
                	       mpdamage_ad+=50;
                	       
				        } 
				    }
				    else{
				    	cout<<"我没有足够法力值，我自动进行物理攻击"<<endl; 				    	
		                cout<<"怪物受到"<<attackd<<"物理攻击"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd;
				    	
					}
				   turnskillakuya=0;              
				   break;
			    case'w':
			    	turnskillakuya=0; 
				    if(mpd>=skmpb){
				    	mpd-=skmpb;
					   if (skillb=="妈的阿库娅"){
					         cout<<"魔法伤害提高了"<<endl;
					         Sleep(1500);
                	         skmp_mBuff=1.25;
                	         turnskillakuya=1; 
				        }
				    }
				    else{
				    	cout<<"我没有足够法力值，我自动进行物理攻击"<<endl;  				    	
		                cout<<"怪物受到"<<attackd<<"物理攻击"<<endl; 
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
				             	cout<<"怪物受到"<<(mpdamage_c+ma*2)*skmp_mBuff<<"点魔法伤害,我恢复了"<<hp-hpd<<"点生命值"<<endl;
				             	hpd=hp;
				                Sleep(1500);
							 }
							 else{
							    hpd=hpd+prehp;
								cout<<"怪物受到"<<(mpdamage_c+ma*2)*skmp_mBuff<<"点魔法伤害,我恢复了"<<prehp<<"点生命值"<<endl;
				                Sleep(1500);
				                 }
				             }
				    else{
				    	cout<<"我没有足够法力值，我自动进行物理攻击"<<endl;  				    	
		                cout<<"怪物受到"<<attackd<<"物理攻击"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd;
					    }
				    turnskillakuya=0;
				    break;
			    case'r':
			    	if(mpd>=skmpd){
				             mpd-=skmpd;
				             cout<<"怪物受到"<<(mpdamage_d+ma)*skmp_mBuff+((monster_hp-monster_hpd)*0.3)<<"魔法伤害"<<endl;
				             Sleep(1500);
				             monster_hpd=monster_hpd-(mpdamage_d+ma)*skmp_mBuff-((monster_hp-monster_hpd)*0.3); 
				             }
				    else{
				    	cout<<"我没有足够法力值，我自动进行物理攻击"<<endl; 
		                cout<<"怪物受到"<<attackd<<"物理攻击"<<endl; 
		                Sleep(1500);
	                    monster_hpd-=attackd; 
					    }
				    turnskillakuya=0;
				    break;
			    default:
			        cout<<"怪物受到"<<attackd<<"点物理伤害"<<endl; 
			        Sleep(1500);
	                monster_hpd-=attackd;
				    turnskillakuya=0;
				    break;	
		}/*switch*/ 
	}/*else我的魔法值*/ 
	    if(monster_hpd>0){
	    hpd-=monster_at;
	    cout<<"你受到了怪物"<<monster_at<<"点伤害"<<endl; 
		Sleep(1500);
	    system("cls");
	    }
	}
    if(monster_hpd<=0){
      	exp1=exp1+exp2;
		if(exp3<=exp1)
	{	
		lv=lv+exp1/exp3;
		cout<<"你升级了！等级为"<<lv<<endl;
		cout<<"你可以加属性点"<<endl;
		/* 属性点升级以及代码*/
		hp=hp+30;
		mp=mp+50;
		exp1=exp1-exp3;
		exp3=exp3+pow(exp3,0.5);
	} 	
		cout<<"怪物的血量为0,战斗胜利。"<<endl; 
   	    money+=goldmoney;
   	    plusmoney*=1.25;
   	    goldmoney+=plusmoney;
   	    gameturn+=1;
   	    cout<<"是否保存？1保存，其他数字键不保存"<<endl;
		cin>>savekey; 
		if(savekey!="1"){
	         system("cls");
	    	}
	    cout<<"是否继续,1继续，其他数字键退出"<<endl; 
	    cin>>startkey;
	}
	if(hpd<=0){
		cout<<"怪物的血量为"<<monster_hpd<<"/"<<monster_hp<<endl; 
        pr(monster_hpd,monster_hp);
      	cout<<"你的血量为0,战斗失败。"<<endl; 
		Sleep(1500);
      	cout<<"按1游戏继续并回档"<<" "<<"按其他数字键结束游戏"<<endl; 
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
	     
     }/*最初的startkey括号*/ 

   	
    return 0;
}
