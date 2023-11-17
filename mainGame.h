#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "lib.h"
#define MAX 100

using namespace std;
struct Score {
	string name;
	int score;
};
vector<Score> scores;
int toaDoX[MAX] = { 0 };
int toaDoY[MAX] = { 0 };
int soDotRan = 4;
int xQua = -1;
int yQua = -1;
int diemSo = 0;
int speed = 1;
int fast = 100;
char c;
//----------Snake---------
void KhoiTaoRan();
void VeRan();
void XuLyRanAnMoi();
void DiChuyenRan(int x, int y);
//-----------Các hàm khởi tạo mồi------
void TaoQua();
void VeQua();
//---------Các hàm làm màu cho game--------
void VeKhung();
void ShowLuaChon();
void ShowMuiten(int a);
void Logo();
void Menu();
void KetThuc();
void game();
//----List các loại Hàm kiểm tra-------
bool RanAnMoi();//kiểm tra xem rắn có ăn mồi ko
bool KiemTraRanDeQua();
bool KiemTraTuSat();
bool GameOver();
//-----Xử lý Điểm-----------------
void LuuDiem(vector<Score> scores);// lưu 
vector<Score> DocDiem();//đọc
void HienThiDiem(vector<Score> scores);//hiện

//--------------------------------

void VeKhung()
{
	for (int x = 10; x <= 95; x++)
	{
		gotoXY(x, 1);
		cout << "+";
		gotoXY(x, 25);
		cout << "+";
	}
	for (int y = 1; y <= 25; y++)
	{
		gotoXY(10,y);
		cout << "+";
		gotoXY(95, y);
		cout << "+";
	}
}
void KhoiTaoRan()
{
	int xDauVao = 50;
	int yDauVao = 13;
	for (int i = 0; i < soDotRan; i++)
	{
		toaDoX[i] = xDauVao--;
		toaDoY[i] = yDauVao;
	}

}
void VeRan()
{
	for (int i = 0; i < soDotRan; i++)
	{
		gotoXY(toaDoX[i], toaDoY[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}
void DiChuyenRan(int x, int y)
{
	for (int i = soDotRan; i > 0; i--)
	{
		toaDoX[i] = toaDoX[i - 1];
		toaDoY[i] = toaDoY[i - 1];
	}

	toaDoX[0] = x;
	toaDoY[0] = y;

}
bool KiemTraTuSat()
{
	for (int i = 1; i <= soDotRan; i++)
	{
		if (toaDoX[0] == toaDoX[i] && toaDoY[0] == toaDoY[i])
		{
			return true;
		}
	}return false;
}
bool GameOver()
{
	if (toaDoX[0] == 10 || toaDoX[0] == 95 || toaDoY[0] == 1 || toaDoY[0] == 25)
	{
		return true;
	}
	return KiemTraTuSat();
}
bool KiemTraRanDeQua()
{
	for (int i = 0; i < soDotRan; i++)
	{
		if (xQua == toaDoX[i] && yQua == toaDoY[i])
		{
			return true;
		}
	}return false;
}
void TaoQua()
{
	do{
		xQua = rand() % (93 - 11 + 1) + 11;
		yQua = rand() % (24 - 1 + 1) + 1;
	} while (KiemTraRanDeQua());// con rắn nó spawn trên cái quả thì cho tạo quả lại 
}
void VeQua()
{
	gotoXY(xQua, yQua); cout << "@";
}
bool RanAnMoi()
{
	if (toaDoX[0] == xQua && toaDoY[0] == yQua)
	{
		return true;
	}
	return false;
}
void XuLyRanAnMoi()
{
	if (RanAnMoi())
	{
		soDotRan++;
		TaoQua();
		VeQua();
		diemSo++;
	}
}
//editbasic


