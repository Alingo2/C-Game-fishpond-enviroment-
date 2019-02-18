#pragma once
#define WID      800
#define HEI     600
struct cao
{
	float x = 0, y = 0;
	float dy = 0;
	int situa = 0;
};
struct pingyi
{
	float x = 0, y = 0;
	float dx = 0, dy = 0;
	float life = 100;
	int type;
	int situa = 0;
	int time = 0;
};
struct vege
{
	float x, y;
	int time = 0;
	float dx;
	int situa = 1;
};
struct shuicao
{
	int x;
	int y;
};
struct G
{
	int x, y;
	float  dy = 0;
	float life;
	int situa = 0;
};
void i_c(char *a, int b)
{
	int heihei[5];
	int x = 5;
	for (int i = 0; i < 5; i++)
	{
		*(a + i) = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		heihei[i] = b % 10;
		b = b / 10;
	}
	for (int i = 4; i >= 0; i--)
	{
		if (heihei[i] == 0 && heihei[i - 1] != 0)
		{
			x = i;
			break;
		}
	}
	for (int i = 0; i < x; i++)
	{
		*(a + i) = heihei[x - 1 - i] + 48;
	}
}
void cwxd1(float *y, float*dy)
{
	float ddy = 0.04;
	if (*y < 565)
	{
		if (*dy < 3.2)
			*dy += ddy;
		*y += *dy;
	}
}
void cwxd(int *y, float*dy)
{
	float ddy = 0.04;
	if (*y < 565)
	{
		if (*dy < 3.2)
			*dy += ddy;
		*y += *dy;
	}
}
void push(float *x1, float *y1, float *x2, float *y2)
{
	if ((fabs(*x1 - *x2) <= 20) && (fabs(*y1 - *y2) <= 20))
	{
		*x2 -= (*x1 - *x2);
		*y2 -= (*y1 - *y2);
	}
}
void show(float *x, float *y, float *dx, float *life, PIMAGE img1, PIMAGE img2)
{
	if (*life > 0)
	{
		if (*dx >= 0)
			putimage_transparent(NULL, img2, *x, *y, 0x58c5c7);
		else
			putimage_transparent(NULL, img1, *x, *y, 0x58c5c7);
	}
}
void chiachi(float *x, float *y, float *life)
{
	*life -= 0.1;
	if (*life > 0 && *life <= 100)
	{
		setfillcolor(0xf71d27);
		bar(*x - 10, *y - 10, *x - 10 + *life*0.5, *y - 20);
	}
	if (*life > 100 && *life <= 200)
	{
		setfillcolor(0xf71d27);
		bar(*x - 10, *y - 10, *x - 10 + 50, *y - 20);
		setfillcolor(0xf7fd49);
		bar(*x - 10, *y - 10, *x - 10 + (*life - 100)*0.5, *y - 20);
	}
	if (*life > 200 && *life <= 300)
	{
		setfillcolor(0xf7fd49);
		bar(*x - 10, *y - 10, *x - 10 + 50, *y - 20);
		setfillcolor(0x4cdf61);
		bar(*x - 10, *y - 10, *x - 10 + (*life - 200)*0.5, *y - 20);
	}
	if (*life > 300 && *life <= 400)
	{
		setfillcolor(0x4cdf61);
		bar(*x - 10, *y - 10, *x - 10 + 50, *y - 20);
		setfillcolor(0x767ea7);
		bar(*x - 10, *y - 10, *x - 10 + (*life - 300)*0.5, *y - 20);
	}
	if (*life > 400 && *life <= 500)
	{
		setfillcolor(0x767ea7);
		bar(*x - 10, *y - 10, *x - 10 + 50, *y - 20);
		setfillcolor(0xb84cea);
		bar(*x - 10, *y - 10, *x - 10 + (*life - 400)*0.5, *y - 20);
	}
}
void youayou(float *x, float *y, float *dx, float *dy, float *life, float*x_, int *time)
{
	float ddy = 0.04;
	if (*time > 0)
		time--;
	if (*time < 0)
	{
		*time = 0;
		*dx = 0;
	}
	if (*x_ - *x > 0 && *x_ - *x < 20 && *y>134 && *y < 164)
	{
		*dy = -1;
		*dx = -10;
		*time = 90;
		*life -= 100;
	}
	if (*y < 160)
	{
		*dy += ddy;
		*y += *dy;
		*x += *dx;
	}
	else
	{
		int test = rand() % 60;
		if (test == 1)
		{
			if (*dx < 0)
			{
				*dx = randomf() * 1.4;
				*x += *dx;
				*dy = randomf() * 1.4;
				*y += *dy;
			}
			else
			{
				float a = randomf() * 1.4;
				float b = randomf() * 1.4;
				*dx = -a;
				*x += *dx;
				*dy = -b;
				*y += *dy;
			}
		}
		else
		{
			*x += *dx;
			*y += *dy;
		}
		if (*life <= 200)
		{
			if (*x < 400)
			{
				*dx = 1;
			}
			else if (*x > 580)
			{
				*dx = -1;
			}
			else if (*y < 525)
			{
				*dy = 1;
			}
		}
		if (*y > 550)
		{
			*dy = -*dy;
			*y = 550;
		}
	}
}
void push2(float *x1, float *y1, float *dx1, float *dy1, float *x2, float *y2, float *dx2, float *dy2)
{
	if ((fabs(*x1 - *x2) <= 20) && (fabs(*y1 - *y2) <= 20))
	{
		*dx1 = -(*dx1);
		*dx2 = -(*dx2);
		*dy1 = -(*dy1);
		*dy2 = -(*dy2);
	}
}
void fangyu(float *x_, int *situa_, int *yunum, char get)
{
	float life_ = 0;
	if (get == '1')
		life_ = 100;
	else if (get == '2')
		life_ = 200;
	else if (get == '3')
		life_ = 300;
	else if (get == '4')
		life_ = 400;
	else if (get == '5')
		life_ = 500;
	if (*yunum < 15)
	{
		int x = 0, y = 0;
		mousepos(&x, &y);
		*yunum = *yunum + 1;
		*(x_ + (*yunum - 1) * 8) = x;
		*(x_ + (*yunum - 1) * 8 + 1) = y;
		if (y < 160)
		{
			*(x_ + (*yunum - 1) * 8 + 2) = 0;
			*(x_ + (*yunum - 1) * 8 + 3) = 0;
		}
		else
		{
			*(x_ + (*yunum - 1) * 8 + 2) = 1;
			*(x_ + (*yunum - 1) * 8 + 3) = 1;
		}
		*(x_ + (*yunum - 1) * 8 + 4) = life_;
		*(situa_ + (*yunum - 1) * 8) = 1;
	}
	else
	{
		for (int i = 0; i < *yunum; i++)
		{
			if (*(situa_ + 8 * i) != 1)
			{
				int x = 0, y = 0;
				mousepos(&x, &y);
				*(x_ + i * 8) = x;
				*(x_ + i * 8 + 1) = y;
				if (y < 160)
				{
					*(x_ + i * 8 + 2) = 0;
					*(x_ + i * 8 + 3) = 0;
				}
				else
				{
					*(x_ + i * 8 + 2) = 1;
					*(x_ + i * 8 + 3) = 1;
				}
				*(x_ + i * 8 + 4) = life_;
				*(situa_ + i * 8) = 1;
				break;
			}
		}
	}
}
void dongshenxiluo(float *x1, float *y1, float *x2, float *y2, float *dx1, float *dy1, float *dx2, float *dy2, int *time, PIMAGE img1, PIMAGE img2)
{
	if (*time == 0) //月亮下降
	{
		*x1 = 380;
		*y1 = 16;
		*dx1 = 0.9;
		*dy1 = 0.3;
	}
	if (*time == 165)//太阳上升
	{
		*x2 = 0;
		*y2 = 170;
		*dx2 = 1;
		*dy2 = -0.4;
	}
	if (*time == 292)//太阳不动
	{
		*dx2 = 0;
		*dy2 = 0;
	}
	if (*time == 470)//太阳下降
	{
		*dx2 = 0.85;
		*dy2 = 0.28;
	}
	if (*time == 635)//月亮上升
	{
		*x1 = 0;
		*y1 = 170;
		*dx1 = 1;
		*dy1 = -0.4;
	}
	if (*time == 762)//月亮不动
	{
		*dx1 = 0;
		*dy1 = 0;
	}
	*x1 += *dx1;
	*y1 += *dy1;
	*x2 += *dx2;
	*y2 += *dy2;
	if (*time >= 165 && *time < 635)
		putimage_transparent(NULL, img2, *x2, *y2, 0xffffff);
	else
		putimage_transparent(NULL, img1, *x1, *y1, 0xffffff);
}
void piaoapiao(float *x, float *dx)
{
	if (*x < 0)
	{
		*dx = -*dx;
		*x = 0;
	}
	if (*x > 400)
	{
		*dx = -*dx;
		*x = 400;
	}
	if (*dx > 0)
	{
		*x -= *dx;
		*dx = *dx - 0.005;
		if (*dx <= 0)
		{
			int q = rand() % 2;
			if (q == 1)
			{
				*dx = randomf()*1.3;
			}
			else
			{
				float m = randomf()*1.3;
				*dx = -m;
			}
		}
	}
	else
	{
		*x -= *dx;
		*dx = *dx + 0.005;
		if (*dx >= 0)
		{
			int q = rand() % 2;
			if (q == 1)
			{
				*dx = randomf()*1.3;
			}
			else
			{
				float m = randomf()*1.3;
				*dx = -m;
			}
		}
	}
}
void feiafei(float *x, float *y, float *dx, float *dy, float *tx, int *tj)
{

	if (*tj == 1)
	{
		int k = 0;
		if (*tx - *x >= 0)
			k = 1;
		else
			k = -1;
		*dx = 5 * k;
		if (fabs(*tx - *x) < 10)
			*dy = 1;
		else
			*dy = fabs((180 - *y) / (*tx - *x)) * 5;
		*y += *dy;
		*x += *dx;
		if (*y > 180)
			*tj = 0;
	}
	else
	{
		int k = rand() % 30;
		if (*y > 70)
		{
			*dy = -2;
			*dx = 1;
		}

		else
		{
			if (*dy == -2 && *dx == 6)
			{
				*dy = rand() % 2;
				*dx = rand() % 2;
			}
			if (k == 1)
			{
				int q = 0;
				q = rand() % 2;
				if (q == 0)
					*dx = rand() % 10 / 5;
				else
					*dx = -rand() % 10 / 5;
				if (*dx == 0)
					*dx = 1;
			}

			*dy = 0;
		}
		*y += *dy;
		*x += *dx;
	}
}
void yun(float *x)
{
	for (int i = 0; i < 3; i++)
	{
		*(x + 8 * i) = rand() % 800;
		*(x + 8 * i + 1) = rand() % 100 + 20;
		*(x + 8 * i + 2) = 0.8;
	}
}
void tiankong(int *mytime, int *mytime2, int *mytimedx, int *day, int *pinglv)
{
	*pinglv += 1;
	if (*pinglv > 2)/*天空变化频率*/
	{
		*pinglv = 0;
	}
	if (*pinglv == 2)
	{
		*mytime += *mytimedx;/*画天空*/
		*mytime2 += 1;
	}
	if (*mytime2 >= 1100)
	{
		*mytime2 = 0;
		*day += 1;
	}
	if (*mytime >= 400)/*15是白色  25-15=10 白天持续10个单位*/
	{
		*mytimedx = -1;
	}
	if (*mytime <= -150)
	{
		*mytimedx = 1;
	}
	int liangdu = 0x010101;
	int myrealtime = *mytime;
	if (myrealtime >= 255)
	{
		myrealtime = 255;
	}
	if (myrealtime <= 0)
	{
		myrealtime = 1;
	}
	setfillcolor(liangdu*myrealtime);
	bar(0, 185, 800, 0);//画天空
	int basecolor = 0x000100;//画海水
	double yanse = 0;
	if (myrealtime <= 165)
		yanse = 0x0040aa + myrealtime / 2*3 * 0x010000;
	if (myrealtime > 165)
		yanse = 0xff002d + (myrealtime - 165) /1 * 0x00101;
	if (myrealtime == 0)
		yanse = 0x00f8ff;
	for (int i = 0; i < 80; i++)
	{
		yanse += 2 * basecolor;
		setfillcolor(yanse);
		bar(0, 585 - 5 * i, 800, 585 - 5 * i - 5);
	}
}
void star_(int *mytime2, PIMAGE star)
{
	if (*mytime2 < 165 || *mytime2 >= 635)
	{
		if (*mytime2 % 30 != 0 && *mytime2 % 30 != 1 && *mytime2 % 30 != 2 && *mytime2 % 30 != 3)
		{
			putimage_transparent(NULL, star, 300, 40, 0xffffff);
			putimage_transparent(NULL, star, 158, 72, 0xffffff);
			putimage_transparent(NULL, star, 421, 27, 0xffffff);
			putimage_transparent(NULL, star, 666, 44, 0xffffff);
		}
	}
}
void jiayu(float *x_, int *situa, int *yunum, int *num)
{
	if (keystate('F'))
	{
		if (*yunum < 15)
		{
			int x = 0, y = 0;
			mousepos(&x, &y);
			*yunum += 1;
			*(x_ + (*yunum - 1) * 8) = x;
			*(x_ + (*yunum - 1) * 8 + 1) = y;
			if (y < 160)
			{
				*(x_ + (*yunum - 1) * 8 + 2) = 0;
				*(x_ + (*yunum - 1) * 8 + 3) = 0;
			}
			else
			{
				*(x_ + (*yunum - 1) * 8 + 2) = 1;
				*(x_ + (*yunum - 1) * 8 + 3) = 1;
			}
			*(x_ + (*yunum - 1) * 8 + 4) = 100 * (rand() % 6);
			*(situa + (*yunum - 1) * 8) = 1;
		}
		else
		{
			for (int i = 0; i < 15; i++)
			{
				if (*(situa + i * 8) != 1 && *(situa + i * 8) != 4)
				{
					int x = 0, y = 0;
					mousepos(&x, &y);
					*(x_ + i * 8) = x;
					*(x_ + i * 8 + 1) = y;
					if (y < 160)
					{
						*(x_ + i * 8 + 2) = 0;
						*(x_ + i * 8 + 3) = 0;
					}
					else
					{
						*(x_ + i * 8 + 2) = 1;
						*(x_ + i * 8 + 3) = 1;
					}

					*(x_ + i * 8 + 4) = 100 * (rand() % 6);
					*(situa + i * 8) = 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (*(situa + i * 8) == 1)
			*num += 1;
	}
	{
		if (keystate('1'))
			fangyu(x_, situa, yunum, '1');
		if (keystate('2'))
			fangyu(x_, situa, yunum, '2');
		if (keystate('3'))
			fangyu(x_, situa, yunum, '3');
		if (keystate('4'))
			fangyu(x_, situa, yunum, '4');
		if (keystate('5'))
			fangyu(x_, situa, yunum, '5');
	}
}
void caocao(float *x_, int *situa, int *yunum)
{
	if (keystate('6'))
	{
		int k = 0;
		if (*yunum < 10)
		{
			int x = 0, y = 0;
			mousepos(&x, &y);
			*yunum = *yunum + 1;
			*(x_ + (*yunum - 1) * 4) = x;
			*(x_ + (*yunum - 1) * 4 + 1) = y;
			*(situa + (*yunum - 1) * 4) = 1;
		}
		else
			for (int i = 0; i < 10; i++)
			{
				if (*(situa + i * 4) == 0)
				{
					int x = 0, y = 0;
					mousepos(&x, &y);
					*(x_ + i * 4) = x;
					*(x_ + i * 4 + 1) = y;
					*(situa + i * 4) = 1;
					break;
				}
			}
	}
}
void yunyun(int *situa)
{
	if (keystate('D'))
	{
		for (int i = 0; i < 2; i++)
		{
			if (*(situa + 8 * i) == 0)
			{
				*(situa + 8 * i) = 1;
				break;
			}
		}
	}
}
void niaoniao(int *situa)
{
	if (keystate('S'))
	{
		*situa = 1;
	}
}
void cmove(float *x, int *situa)
{
	if (keystate(key_up))   	/*测试人员开挂！！！*/
	{
		*(x + 1) -= 1;
		if (keystate(key_shift))
		{
			*(x + 1) -= 8;
		}
	}
	if (keystate(key_down))
	{
		*(x + 1) += 1;
		if (keystate(key_shift))
		{
			*(x + 1) += 8;
		}
	}
	if (keystate(key_left))
	{
		*x -= 1;
		*situa = 1;
		if (keystate(key_shift))
		{
			*x -= 8;
		}
	}
	if (keystate(key_right))
	{
		*x += 1;
		*situa = 0;
		if (keystate(key_shift))
		{
			*x += 8;
		}
	}
}
void jineng(float *cx, float *x, int *situa)
{
	if (keystate(key_space))//杀鱼术
	{
		setcolor(0xe4ff4f);
		setlinewidth(2);
		circlef(*cx + 15, *(cx + 1) + 15, 60);
		for (int i = 0; i < 15; i++)
		{
			if (*(situa + 8 * i) == 1 && sqrt((*(cx + 1) - *(x + 8 * i + 1))*(*(cx + 1) - *(x + 8 * i + 1)) + (*cx - *(x + 8 * i))*(*cx - *(x + 8 * i))) <= 60)
			{
				*(x + 8 * i + 4) -= 1;
			}
		}
	}
	if (keystate(key_enter))//吸鱼术
	{
		for (int i = 0; i < 15; i++)
		{
			if (*(situa + 8 * i) == 1 && (fabs(*(x + 8 * i) - *cx) >= 40) && fabs((*(x + 8 * i + 1) - *(cx + 1))) >= 40)
			{
				if (*(x + 8 * i) < *cx)
				{
					*(x + 8 * i + 2) += 1;
				}
				else
				{
					*(x + 8 * i + 2) -= 1;
				}
				if (*(x + 8 * i + 1) < *(cx + 1))
				{
					*(x + 8 * i + 3) += 1;
				}
				else
				{
					*(x + 8 * i + 3) -= 1;
				}
			}
			if (*(situa + 8 * i) == 1 && (fabs(*(x + 8 * i) - *cx) < 40) && (fabs(*(x + 8 * i + 1) - *(cx + 1)) < 40))
			{
				*(x + 8 * i + 2) = 0;
				*(x + 8 * i + 3) = 0;
			}
		}
	}
	if (keystate('V'))//瞬移术
	{
		for (int i = 0; i < 15; i++)
		{
			if (*(situa + 8 * i) == 1)
			{
				*(x + 8 * i) = *cx + 15;
				*(x + 8 * i + 1) = *(cx + 1) + 15;
			}
		}
	}
}
void fishing(int *tj, int *tj3, float *x, int *situa, float *nx)
{
	if (keystate('T'))
	{
		*tj = 1;
		*(*tj3 * 8 + situa) = 1;
		for (int i = 0; i < 15; i++)
		{
			if (*(situa + 8 * i) == 1)
			{
				if (*(x + 8 * i + 1) > 150 && *(x + 8 * i + 1) < 200)
				{
					*tj3 = i;
					break;
				}
			}
		}
	}
	if (fabs(*nx - *(x + *tj3 * 8) <= 20 && fabs(*(nx + 1) - *(x + *tj3 * 8 + 1)) <= 20))
	{
		*(*tj3 * 8 + situa) = 4;
		*(x + *tj3 * 8) = *nx + 10;
		*(x + *tj3 * 8 + 1) = *(nx + 1) + 10;
		*(x + *tj3 * 8 + 4) -= 1;
		*tj = 0;
	}
}
void cpush(int *yunum, float *cx, float *x)
{
	for (int i = 0; i < *yunum; i++)
	{
		push(cx, cx + 1, x + 8 * i, x + 8 * i + 1);
	}
}
void clook(float *cx, PIMAGE god, PIMAGE god2, int *cs)
{
	if (*cs == 0)
	{
		putimage_transparent(NULL, god, *cx, *(cx + 1), 0x58c5c7);
	}
	if (*cs == 1)
	{
		putimage_transparent(NULL, god2, *cx, *(cx + 1), 0x58c5c7);
	}

}
void langligelang(float *x)
{
	*x -= *(x + 2);
	*(x + 2) -= 0.1;
	if (*x <= -500)
	{
		*x = 800;
	}
	if (*(x + 2) <= 0)
	{
		*(x + 2) = 3.5;
	}
}
void shipship(float *x)
{
	*x -= *(x + 2);
	if (*x <= -700)
	{
		*x = 800;
	}
}
void ymove(int *situa, float *x)
{
	for (int i = 0; i < 3; i++)
	{
		if (*(situa + 8 * i) == 1)
			piaoapiao(x + 8 * i, x + 8 * i + 2);
	}
}
void N_D(int *gs, int *gx, int *situa, float *x)
{
	for (int i = 0; i < 15; i++)
	{
		if (*(x + 8 * i + 4) <= 0 && *(situa + 8 * i) != 3)
		{
			*(situa + 8 * i) = 3;
			*(gs + 5 * i) = 3;
			*(gx + 5 * i) = *(x + 8 * i);
			*(gx + 5 * i + 1) = *(x + 8 * i + 1);
		}
	}
}
void nmove(int *ns, float *nx, float *x, int *tj, int *tj3, float *dx, PIMAGE bird2, PIMAGE bird)
{
	if (*ns == 1)
	{
		feiafei(nx, nx + 1, nx + 2, nx + 3, x + 8 * *tj3, tj);
		if (*dx <= 0)
			putimage_transparent(NULL, bird2, *nx, *(nx + 1), 0x58c5c7);
		if (*dx > 0)
			putimage_transparent(NULL, bird, *nx, *(nx + 1), 0x58c5c7);
	}
}
void chiyu(float *x_,int *situa_,int *gx,int *gs,int *yunum)
{
	for (int x = 0; x < *yunum; x++)
	{
		if (*(situa_+8*x) == 1)
		{
			
				for (int y = x + 1; y < *yunum; y++)
				{
					if (*(situa_+8*y) == 1)
					{
						if ((fabs(*(x_+8*x) - *(x_ + 8 * y)) <= 20) && (fabs(*(x_ + 8 * x+1) - *(x_ + 8 * y+1)) <= 20))
						{
							if (int(*(x_+8*x+4)/ 100) > int(*(x_ + 8 * y + 4) / 100))
							{
								*(x_ + 8 * x + 4) += *(x_ + 8 * y + 4);
								*(x_ + 8 * y + 4) = 0;
								*(gx+5*x) = *(x_ + 8 * x);
								*(gx + 5 * x+1) = *(x_ + 8 * x + 1);
								*(x_ + 8 * y + 2) = 0;
								*(x_ + 8 * y + 3) = 0;
								*(situa_+8*y) = 0;
								*(gs+5*y) = 3;
								break;
							}
							else if (int(*(x_+8*x+4) / 100) < int(*(x_ + 8 * y + 4) / 100))
							{
								*(x_ + 8 * y + 4) += *(x_ + 8 * x + 4);
								*(x_ + 8 * x + 4) = 0;
								*(gx+5*x) = *(x_+8*x);
								*(gx + 5 * x+1) = *(x_ + 8 * x+1);
								*(x_ + 8 * x + 2) = 0;
								*(x_ + 8 * x + 3) = 0;
								*(situa_+8*x) = 0;
								*(gs+5*x)= 3;
								break;
							}
						}
					}
				}
		}
	}
}
void skulldown(int *gs, PIMAGE body, int *gx,float *gdy)
{
	for (int i = 0; i < 15; i++)//骨头随重力下落
	{
		if (*(gs+5*i) == 3)
		{
			cwxd(gx+5*i+1, gdy+8*5);
			putimage_transparent(NULL, body, *(gx+5*i), *(gx + 5 * i+1), 0xffffff);
		}
	}
}
void chicao(int *yunum,int *situa,float *x,int *cs1,int *cs2,float *cx1,float *cx2)
{
	for (int i = 0; i < *yunum; i++)
	{
		if (*(situa+8*i) == 1)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((fabs(*(x+8*i) - *(cx1+5*j)) <= 30) && (fabs(*(x+8*i+1) - *(cx1 + 5 * j+1)) <= 30))
				{
					if (*(cs1 +5*j) == 1)
					{
						*(x+8*i+4) += 20;
						*(cs1 + 5 * j) = 0;
					}
				}
				if ((fabs(*(x + 8 * i) - *(cx2+4*j)) <= 30) && fabs(*(x + 8 * i+1) - *(cx2 + 4 * j+1)) <= 30)
				{
					if (*(cs2+4*j)== 1)
					{
						*(x + 8 * i + 4) += 20;
						*(cs2 + 4 * j) = 0;
						*(cx2+4*j+2) = 0;
					}
				}
			}
		}
	}
}
void drawvege(int *cs1,int *cs2,PIMAGE plant,PIMAGE plant2,float *cx1,float *cx2)
{
	for (int j = 0; j < 5; j++)
	{
		if (*(cs1+j*5)== 1)
			putimage_transparent(NULL, plant2, *(cx1+j*5), *(cx1 + j * 5+1), 0x58c5c7);
		if (*(cs1 + (j+5) * 5) == 1)
			putimage_transparent(NULL, plant, *(cx1 + (j+5) * 5), *(cx1 + (j + 5) * 5+1), 0x58c5c7);
	}
	for (int i = 0; i < 10; i++)
	{
		if (*(cs2+i*4) == 1)
			putimage_transparent(NULL, plant, *(cx2+i*4), *(cx2 + i * 4+1), 0x58c5c7);
	}
}
void count_live(int *situa,int *yunum2)
{
	for (int i = 0; i < 15; i++)
	{
		if (*(situa+i*8) == 1)
			*yunum2 += 1;
	}
}
void wingwing(float *x,int *t,int *situa)
{
	if (*x<= 465)//摆动海草
	{
		*(x+3) = 0.2;
	}
	else if (*x >= 485)
	{
		*(x + 3) = -0.2;
	}
	*x += *(x + 3);
	for (int i = 0; i < 5; i++)
	{
		*(x+5*i) = *x + 35 * i;
		*(x + 5 * i+1) = 525;
		*(x + 5 * (i+5)) = 475 + 35 * i;
		*(x + 5 * (i + 5)+1) = 550;
	}
	for (int i = 0; i < 10; i++)
	{
		if (*(situa+5*i) == 0)
		{
			*(t+5*i)+=1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (*(t + 5 * i) == 1000)
		{
			*(situa + 5 * i) = 1;
			*(t + 5 * i) = 0;
		}
	}
}
void vegedown(int *situa,float *y)
{
	for (int i = 0; i < 10; i++)
	{
		if (*(situa+4*i) == 1)
			cwxd1(y+4*i, y+4*i+1);
	}
}
void dispose_pic(PIMAGE *tp1,PIMAGE *tp2,PIMAGE fish1, PIMAGE fish12, PIMAGE hotfish, PIMAGE hotfish2, PIMAGE wuzei, PIMAGE wuzei2, PIMAGE jing, PIMAGE jing2, PIMAGE beauty, PIMAGE beauty2,float *life,int *yunum)
{
	for (int i = 0; i < *yunum; i++)
	{
		if (*(life+8*i) > 0 && *(life + 8 * i) <= 100)
		{
			*(tp1+i) = fish1;
			*(tp2 + i) = fish12;
		}
		else if (*(life + 8 * i) > 100 && *(life + 8 * i) <= 200)
		{
			*(tp1 + i) = hotfish;
			*(tp2 + i) = hotfish2;
		}
		else if (*(life + 8 * i) > 200 && *(life + 8 * i) <= 300)
		{
			*(tp1 + i) = wuzei;
			*(tp2 + i) = wuzei2;
		}
		else if (*(life + 8 * i) > 300 && *(life + 8 * i) <= 400)
		{
			*(tp1 + i) = jing;
			*(tp2 + i) = jing2;
		}
		else if (*(life + 8 * i) > 400)
		{
			*(tp1 + i) = beauty;
			*(tp2 + i) = beauty2;
		}
		if (*(life + 8 * i) >= 500)
		{
			*(life + 8 * i) = 500;
		}
	}
}
void showyun(int *s,float *x,PIMAGE cloud)
{
	for (int i = 0; i < 3; i++)
	{
		if (*(s+i*8) == 1)
			putimage_transparent(NULL, cloud, *(x+i*8), *(x + i * 8+1), 0xffffff);
	}
}
void samepush(int *yunum,float *x)
{
	for (int i = 0; i < *yunum; i++)//同类鱼互推
	{
		for (int j = i + 1; j < *yunum; j++)
		{
			if ((*(x+i*8+4) / 100) == (*(x + j * 8 + 4) / 100))
			{
				push2(x+8*i, x + 8 * i+1, x + 8 * i+2, x + 8 * i+3,x+8*j, x + 8 * j+1, x + 8 * j+2, x + 8 * j+3);
				break;
			}
		}
	}
}
void core(int *situa,float *x,float *sx,PIMAGE *t1,PIMAGE*t2)
{
	for (int a = 0; a < 15; a++)
	{
		if (*(situa+8*a)== 1 || *(situa + 8 * a) == 4)
		{
			if (*(situa + 8 * a) == 1)
				youayou(x+8*a, x + 8 * a+1, x + 8 * a+2, x + 8 * a+3, x + 8 * a+4, sx, situa+1);
			chiachi(x+8*a, x+8*a+1, x+8*a+4);
			show(x+8*a, x+8*a+1, x+8*a+2, x+8*a+4, *(t1+a), *(t2+a));
		}
	}
}