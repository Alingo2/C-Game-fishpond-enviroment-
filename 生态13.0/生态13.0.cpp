#include "pch.h"
#include <graphics.h>
#include<stdio.h>
#include <math.h>
#include<ctime>
#include<iostream>
#include"shengtai.h"
using namespace std;
int mainloop()
{
	bool kaishi = 0;
	MUSIC mus;
	mus.OpenFile("./bgm.mp3");
	mus.SetVolume(0.2f);
	srand((unsigned)time(NULL));
	PIMAGE beike = newimage();
	getimage(beike, "./beike.png");
	PIMAGE xie = newimage();
	getimage(xie, "./xie.png");
	PIMAGE hotfish = newimage();
	getimage(hotfish, "./hotfish.png");
	PIMAGE hotfish2 = newimage();
	getimage(hotfish2, "./hotfish2.png");
	PIMAGE surf = newimage();
	getimage(surf, "./surf.png");
	PIMAGE cloud = newimage();
	getimage(cloud, "./cloud.png");
	PIMAGE plant = newimage();
	getimage(plant, "./plant.png");
	PIMAGE plant2 = newimage();
	getimage(plant2, "./plant2.png");
	PIMAGE wave = newimage();
	getimage(wave, "./wave.png");
	PIMAGE jing = newimage();
	getimage(jing, "./jing.png");
	PIMAGE jing2 = newimage();
	getimage(jing2, "./jing2.png");
	PIMAGE ship = newimage();
	getimage(ship, "./ship.png");
	PIMAGE fish1 = newimage();
	getimage(fish1, "./fish1.png");
	PIMAGE fish12 = newimage();
	getimage(fish12, "./fish12.png");
	PIMAGE beauty = newimage();
	getimage(beauty, "./beauty2.png");
	PIMAGE beauty2 = newimage();
	getimage(beauty2, "./beauty.png");
	PIMAGE wuzei = newimage();
	getimage(wuzei, "./wuzei.png");
	PIMAGE wuzei2 = newimage();
	getimage(wuzei2, "./wuzei2.png");
	PIMAGE god = newimage();
	getimage(god, "./god.png");  
	PIMAGE god2 = newimage();
	getimage(god2, "./god2.png");
	PIMAGE bird = newimage();
	getimage(bird, "./bird.png");
	PIMAGE bird2 = newimage();
	getimage(bird2, "./bird2.png");
	PIMAGE body = newimage();
	getimage(body, "./body.png");
	PIMAGE sun = newimage();
	getimage(sun, "./sun.png");
	PIMAGE moon = newimage();
	getimage(moon, "./moon.png");
	PIMAGE star = newimage();
	getimage(star, "./star.png");

	PIMAGE tupian1[15] = { 0 };
	PIMAGE tupian2[15] = { 0 };
	cao cao_[10] = { 0 };
	pingyi yu[15] = { 0 };
	vege cao[10] = { 0 };
	G gutou[15] = { 0 };
	cao[0].x = 460;
	pingyi ceshi;
	ceshi.x = 200;
	ceshi.y = 200;
	ceshi.life = 500;
	pingyi sur;
	sur.dx = 4;
	sur.x = 800;
	pingyi shipp;
	shipp.x = 800;
	shipp.dx = 3;
	pingyi cloudd[3] = { 0 };
	pingyi ri, yue, xing;
	yun(&cloudd[0].x);
	pingyi niao;
	niao.x = rand() % 800;
	niao.y = 20 + rand() % 100;
	niao.dx = 0.8;
	pingyi xiee;
	xiee.x = 200;
	xiee.dx = 1;
	int pinglv = 0;
	int  mytime = 0;
	int  mytime2 = 0;
	int mytimedx = 1;
	int day = 1;
	int yunum = 0;
	int tj = 0;
	int tj4 = 0;
	int tj3 = 0;
	int caonum = 0;
	int num = 0;
	char jishu[5] = { 0 };
	char jishu2[5] = { 0 };
	//前面都是为后续的各个部分初设变量方便后续控制

	for (; is_run(); delay_fps(60))//ege的实现动画的函数
	{
		if (kaishi != 1)//打出封面
		{
			PIMAGE fengmian = newimage();
			getimage(fengmian, "./fengmian.png");
			putimage(0, 0, fengmian);
			if (kbmsg())
			{
				delete fengmian;
				kaishi = 1;
			}
		}
		if (kaishi)
		{
			int yunum2 = 0;
			cleardevice();
			tiankong(&mytime, &mytime2, &mytimedx, &day, &pinglv);
			setfillcolor(0xf4ba3e);//画沙子
			bar(0, 585, 800, 600);
			dongshenxiluo(&yue.x, &yue.y, &ri.x, &ri.y, &yue.dx, &yue.dy, &ri.dx, &ri.dy, &mytime2, moon, sun);	//画太阳月亮星星
			star_(&mytime2, star);//星星乱闪
			jiayu(&yu[0].x, &yu[0].situa, &yunum, &num);//按'1'-'5'可以加不同的类型的鱼，按'F'加随机类型的鱼
			caocao(&cao_[0].x, &cao_[0].situa, &caonum);
			yunyun(&cloudd[0].situa);
			niaoniao(&niao.situa);
			cmove(&ceshi.x, &ceshi.situa);
			jineng(&ceshi.x, &yu[0].x, &yu[0].situa);//管理员的技能
			fishing(&tj, &tj3, &yu[0].x, &yu[0].situa, &niao.x);//海鸥捕鱼
			cpush(&yunum, &ceshi.x, &yu[0].x);//管理员与鱼的碰撞
			clook(&ceshi.x, god, god2, &ceshi.situa);//管理员图片方向随移动方向变化
			vegedown(&cao_[0].situa, &cao_[0].y);
			dispose_pic(&tupian1[0], &tupian2[0], fish1, fish12, hotfish, hotfish2, wuzei, wuzei2, jing, jing2, beauty, beauty2, &yu[0].life, &yunum);
			langligelang(&sur.x);
			shipship(&shipp.x);
			core(&yu[0].situa, &yu[0].x, &shipp.x, &tupian1[0], &tupian2[0]);
			ymove(&cloudd[0].situa, &cloudd[0].x);
			nmove(&niao.situa, &niao.x, &yu[0].x, &tj, &tj3, &niao.dx, bird2, bird);
			piaoapiao(&xiee.x, &xiee.dx);
			putimage_transparent(NULL, xie, xiee.x, 550.0, 0x58c5c7);
			putimage_transparent(NULL, beike, 400.0, 550.0, 0x58c5c7);
			putimage_transparent(NULL, surf, sur.x, 149, 0xffffff);
			N_D(&gutou[0].situa, &gutou[0].x, &yu[0].situa, &yu[0].x);//鱼自然老死
			showyun(&cloudd[0].situa, &cloudd[0].x, cloud);
			putimage_transparent(NULL, wave, sur.x + 35, 151, 0xffffff);
			wingwing(&cao[0].x, &cao[0].time, &cao[0].situa);//
			drawvege(&cao[0].situa, &cao_[0].situa, plant, plant2, &cao[0].x, &cao_[0].x);
			putimage_transparent(NULL, ship, shipp.x, 154.0, 0xffffff);
			//samepush(&yunum, &yu[0].x);//同类鱼互推
			chiyu(&yu[0].x, &yu[0].situa, &gutou[0].x, &gutou[0].situa,&yunum);//吃鱼
			skulldown(&gutou[0].situa, body, &gutou[0].x, &gutou[0].dy);
			chicao(&yunum, &yu[0].situa, &yu[0].x, &cao[0].situa, &cao_[0].situa, &cao[0].x, &cao_[0].x);
			count_live(&yu[0].situa, &yunum2);

			{// 画帧率文字
				char str[40];
				sprintf(str, "fps %.02f", getfps()); //调用getfps取得当前帧率
				setcolor(BLACK);
				outtextxy(0, 0, str);
				//设置前景色为黑色
				setfont(17, 0, "楷体");
				i_c(jishu, yunum2);
				yunum2 = 0;
				outtextxy(0, 20, "现在还活着的鱼：");
				outtextxy(150, 20, jishu);
				outtextxy(0, 40, "天数：");
				i_c(jishu2, day);
				outtextxy(50, 40, jishu2);
				if (mus.GetPlayStatus() == MUSIC_MODE_STOP)
				{
					mus.Play(0);
				}
			}
		}
	}
	return 0;
}
int main()
{
	initgraph(WID, HEI, INIT_RENDERMANUAL);
	setbkcolor(0x00f8ff);
	mainloop();
	getch();
	closegraph();
	return 0;
}