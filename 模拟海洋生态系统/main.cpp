// #include "pch.h"
#include <graphics.h>
#include<stdio.h>
#include <math.h>
#include<ctime>
#include<iostream>
#include <string> 
#include"zoology.h"
using namespace std;

PIMAGE get_img(string a){
	PIMAGE name = newimage();
	getimage(name,("./img/"+a+".png").c_str());
	return name;
}

int mainloop()
{
	bool start = 0;
	MUSIC mus;
	mus.OpenFile("./music/bgm.mp3");
	mus.SetVolume(0.2f);
	srand((unsigned)time(NULL));
	PIMAGE shell = get_img("shell");
	PIMAGE tropical_fish = get_img("tropical_fish");
	PIMAGE tropical_fish_r = get_img("tropical_fish_r");
	PIMAGE cloud = get_img("cloud");
	PIMAGE plant = get_img("plant");
	PIMAGE plant_u = get_img("plant_u");
	PIMAGE wave = get_img("wave");
	PIMAGE whale = get_img("whale");
	PIMAGE whale_r = get_img("whale_r");
	PIMAGE fish = get_img("fish");
	PIMAGE fish_r = get_img("fish_r");
	PIMAGE beauty = get_img("beauty");
	PIMAGE beauty_r = get_img("beauty_r");
	PIMAGE octopus = get_img("octopus");
	PIMAGE octopus_r = get_img("octopus_r");
	PIMAGE skull = get_img("skull");
	PIMAGE sun = get_img("sun");
	PIMAGE moon = get_img("moon");
	PIMAGE star = get_img("star");

	PIMAGE pic_1[15] = { 0 };
	PIMAGE pic_2[15] = { 0 };
	item Fish[15] = { 0 };
	vege grass[10] = { 0 };
	item Skull[15] = { 0 };
	grass[0].x = 460;
	item Character,Surf,Ship,Sun,Moon,Bird,Crab;	//Character为操控的角色
	item grass_[10] = { 0 };


	Character.x = 200;
	Character.y = 200;
	Character.life = 500;
	Character.pic = get_img("Character");
	Character.pic_r = get_img("Character_r");

	Surf.dx = 4;
	Surf.x = 800;
	Surf.pic = get_img("Surf");

	Ship.x = 800;
	Ship.dx = 3;
	Ship.pic = get_img("Ship");

	Bird.x = rand() % 800;
	Bird.y = 20 + rand() % 100;
	Bird.situa = 1;
	Bird.dx = 0.8;
	Bird.pic = get_img("Bird");
	Bird.pic_r = get_img("Bird_r");

	Crab.x = 200;
	Crab.dx = 1;
	Crab.pic = get_img("Crab");

	item Cloud[3] = { 0 };
	Cloud_Random(&Cloud[0].x);	//初始化cloud位置

	int frequency = 0;
	int mytime = 0;
	int mytime_2 = 0;
	int mytime_dx = 1;
	int day = 1;
	int Fish_num = 0;
	int condition = 0;
	int condition_2 = 0;
	int grass_num = 0;
	int num = 0;
	char cnt[5] = { 0 };
	char cnt_2[5] = { 0 };
	//前面都是为后续的各个部分初设变量方便后续控制
	int frequence_cnt = 0;
	for (; is_run(); delay_fps(60))//ege的实现动画的函数
	{	
		frequence_cnt ++;
		if (start != 1)//显示菜单
		{
			PIMAGE Menu = get_img("menu");
			putimage(0, 0, Menu);
			if (kbmsg())
			{
				start = 1;
			}
		}
		if (start)
		{	
			int fish_num = 0;
			cleardevice();
			Sky(&mytime, &mytime_2, &mytime_dx, &day, &frequency);
			setfillcolor(0xf4ba3e);//绘制沙地
			bar(0, 585, 800, 600);
			rise_fall(&Moon.x, &Moon.y, &Sun.x, &Sun.y, &Moon.dx, &Moon.dy, &Sun.dx, &Sun.dy, &mytime_2, moon, sun);	//画太阳月亮星星
			star_(&mytime_2, star);//星星闪烁
			Add_Fish(&Fish[0].x, &Fish[0].situa, &Fish_num, &num,&frequence_cnt);//按'1'-'5'可以加不同的类型的鱼，按'F'加随机类型的鱼
			Add_grass(&grass_[0].x, &grass_[0].situa, &grass_num,&frequence_cnt);
			Cloud_on_off(&Cloud[0].situa,&frequence_cnt);
			Bird_on_off(&Bird.situa,&frequence_cnt);
			cmove(&Character.x, &Character.situa);
			Skill(&Character.x, &Fish[0].x, &Fish[0].situa);//管理员的技能
			fishing(&condition, &condition_2, &Fish[0].x, &Fish[0].situa, &Bird.x,&frequence_cnt);//海鸥捕鱼
			cpush(&Fish_num, &Character.x, &Fish[0].x);//管理员与鱼的碰撞
			Move_Inverse(&Character.x, Character.pic, Character.pic_r, &Character.situa);//管理员图片方向随移动方向变化
			vegedown(&grass_[0].situa, &grass_[0].y);
			dispose_pic(&pic_1[0], &pic_2[0], fish, fish_r, tropical_fish, tropical_fish_r, octopus, octopus_r, whale, whale_r, beauty, beauty_r, &Fish[0].life, &Fish_num);
			Tide_Wave(&Surf.x);
			Ship_Move(&Ship.x);
			Core(&Fish[0].situa, &Fish[0].x, &Ship.x, &pic_1[0], &pic_2[0]);
			xmove(&Cloud[0].situa, &Cloud[0].x);
			nmove(&Bird.situa, &Bird.x, &Fish[0].x, &condition, &condition_2, &Bird.dx, Bird.pic_r, Bird.pic);
			cloud_move(&Crab.x, &Crab.dx);
			putimage_transparent(NULL, Crab.pic, Crab.x, 550.0, 0x58c5c7);
			putimage_transparent(NULL, shell, 400.0, 550.0, 0x58c5c7);
			putimage_transparent(NULL, Surf.pic, Surf.x, 149, 0xffffff);
			Natural_Die(&Skull[0].situa, &Skull[0].x, &Fish[0].situa, &Fish[0].x);//鱼自然老死
			cloud_invis(&Cloud[0].situa, &Cloud[0].x, cloud);
			putimage_transparent(NULL, wave, Surf.x + 35, 151, 0xffffff);
			wingwing(&grass[0].x, &grass[0].time, &grass[0].situa);//
			drawvege(&grass[0].situa, &grass_[0].situa, plant, plant_u, &grass[0].x, &grass_[0].x);
			putimage_transparent(NULL, Ship.pic, Ship.x, 154.0, 0xffffff);
			//samepush(&Fish_num, &Fish[0].x);//同类鱼碰撞
			chiyu(&Fish[0].x, &Fish[0].situa, &Skull[0].x, &Skull[0].situa,&Fish_num);//吃鱼
			Skull_Down(&Skull[0].situa, skull, &Skull[0].x, &Skull[0].dy);
			Grass_Eating(&Fish_num, &Fish[0].situa, &Fish[0].x, &grass[0].situa, &grass_[0].situa, &grass[0].x, &grass_[0].x);
			count_live(&Fish[0].situa, &fish_num);

			{// 画帧率文字
				char str[40];
				sprintf(str, "fps %.02f", getfps()); //调用getfps取得当前帧率
				setcolor(BLACK);
				outtextxy(0, 0, str);
				//设置前景色为黑色
				setfont(17, 0, "Arial");
				update_num(cnt, fish_num);
				fish_num = 0;
				outtextxy(0, 20, "Living fishes:");
				outtextxy(150, 20, cnt);
				outtextxy(0, 40, "Days:");
				update_num(cnt_2, day);
				outtextxy(50, 40, cnt_2);
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