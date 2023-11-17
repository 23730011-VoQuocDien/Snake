﻿#pragma once
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
void game()
{
	ShowCur(0);
	VeKhung();
	KhoiTaoRan();
	TaoQua();
	VeQua();
	int check =2 ;
	int x = toaDoX[0];
	int y = toaDoY[0];
	while (true)
	{
		if (_kbhit())//Kiểm tra xem thằng người dùng có nhập gì ko
		{
			char c = _getch();
			if (c == -32)//vì we set nút điều khiển là phím mũi tên nên theo mã ASCII
			{
				c = _getch();
				if (c == 72&&check != 0)// cái này là nút đi lên cái &&... là để người dùng không cho rắn đi số lùi :))
				{
					check = 1;// cho con rắn đi lên nếu hắn nhấn
				}
				else if (c == 80&&check!=1)
				{
					check = 0;//xuống
				}
				else if (c == 75&&check != 2)
				{
					check = 3;//trái
				}
				else if (c == 77&& check != 3)
				{
					check = 2;//right
				}
			}
		}
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		gotoXY(toaDoX[soDotRan], toaDoY[soDotRan]);// xóa khúc thừa
		cout<<" ";
		VeRan();
		if (GameOver())
		{
			KetThuc();
			diemSo = 0;
			speed = 1;
			fast = 100;
			Menu();
		}
		XuLyRanAnMoi();
		if (diemSo == 20)
		{
			speed=2;
			fast =70;
		}
		else if (diemSo == 40)
		{
			speed = 3;
			fast = 50;
		}
		gotoXY(10, 0); cout << "SCORE:"; gotoXY(17, 0); cout << diemSo;
		gotoXY(20, 0); cout << "SPEED:"; gotoXY(27, 0); cout << speed;
		DiChuyenRan(x, y);
		Sleep(fast);
	}
	
}
void LuuDiem(vector<Score> scores) {
	// Mở file để ghi
	ofstream outfile("s.txt");

	// Duyệt qua tất cả các điểm
	for (Score score : scores) {
		// Ghi tên người chơi và điểm
		outfile << score.name << " " << score.score << endl;
	}

	// Đóng file
	outfile.close();
}
vector<Score> DocDiem() {
	// Mở file để đọc
	ifstream infile("s.txt");

	// Tạo vector để lưu các điểm
	vector<Score> scores;

	// Duyệt qua tất cả các dòng trong file
	string line;
	while (getline(infile, line)) {
		// Cắt tên người chơi và điểm
		int space_pos = line.find(" ");
		string name = line.substr(0, space_pos);
		int score = stoi(line.substr(space_pos + 1));

		// Thêm điểm vào vector
		scores.push_back({ name, score });
	}

	// Đóng file
	infile.close();

	// Trả về vector các điểm
	return scores;
}
void HienThiDiem(vector<Score> scores) {
	VeKhung();
	int i = 5,x=30,x2=60;
	gotoXY(x, 3); cout << "------------HIGH SCORE--------------" << endl;
	gotoXY(x, 4); cout << "Name" << endl;
	gotoXY(x2, 4); cout << "Scores" << endl;
	for (Score score : scores) {
		// Hiển thị tên người chơi và điểm
		gotoXY(x, i);
		cout << score.name << endl;
		gotoXY(x2, i); cout << score.score << endl;
		i++;
		if (i == 23)
		{
			gotoXY(44, i); cout << "-MORE-" << endl;
			_getch();
			system("cls");
			Menu();
		}
	}
	gotoXY(44, 23); cout << "(Press any to exit)" <<endl;
	_getch();
	system("cls");
	Menu();
}


