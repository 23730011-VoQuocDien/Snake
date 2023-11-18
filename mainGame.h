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

void Logo()
{
	
	VeKhung();
	gotoXY(30, 8);
	cout << "________________________" << endl;
	gotoXY(30, 9);
	// Định nghĩa các ký tự đặc biệt
	char vertical_line = '||';
	// Xuất chữ "snake"	
	cout << vertical_line << " s " << vertical_line << endl;
	gotoXY(30, 10);
	cout << vertical_line << " n " << vertical_line << endl;
	gotoXY(30, 11);
	cout << vertical_line << " a " << vertical_line << endl;
	gotoXY(30, 12);
	cout << vertical_line << " k " << vertical_line << endl;
	gotoXY(30, 13);
	cout << vertical_line << " e " << vertical_line << endl;
	gotoXY(38, 13);
	cout  << "_-_-_-_-_-_-_" << endl;
	gotoXY(30, 14);
	cout << "________________________" << endl;
	gotoXY(54, 9);
	cout << "*    * *  *" << endl;
	gotoXY(54, 10); 
	cout << "  *   *NEW VERSION  *" << endl;
	gotoXY(54, 11);
	cout << "*       *" << endl;
	gotoXY(54, 12);
	cout << "    *  2023   * " << endl;
	gotoXY(54, 13);
	cout << "*     *   * *" << endl;

}
void ShowLuaChon() {
	gotoXY(40, 9); cout << "1. New game  " << endl;
	gotoXY(40, 10); cout << "2. High score" << endl;
	gotoXY(40, 11); cout << "3. Info    *" << endl;
	gotoXY(40, 12); cout << "4. Exit  *" << endl;
}
void ShowMuiten(int a) {
	if (a == 1)
	{
		gotoXY(38, 9); cout << "->";
		gotoXY(38, 10); cout << "  ";
		gotoXY(38, 11); cout << "  ";
		gotoXY(38, 12); cout << "  ";
	}
	else if (a == 2)
	{
		gotoXY(38, 9); cout << "  ";
		gotoXY(38, 10); cout << "->";
		gotoXY(38, 11); cout << "  ";
		gotoXY(38, 12); cout << "  ";
	}
	else if (a == 3)
	{
		gotoXY(38, 9); cout << "  ";
		gotoXY(38, 10); cout << "  ";
		gotoXY(38, 11); cout << "->";
		gotoXY(38, 12); cout << "  ";
	}
	else if (a == 4)
	{
		gotoXY(38, 9); cout << "  ";
		gotoXY(38, 10); cout << "  ";
		gotoXY(38, 11); cout << "  ";
		gotoXY(38, 12); cout << "->";
	}
}

void KetThuc()		
{		
"	system(""cls"");"		
"	VeKhung();"		
"	string name;"		
"	gotoXY(40"	 9); cout << "Enter your name:" << endl;	
"	gotoXY(58"	 9); getline(cin	 name);
"	scores.push_back({ name"	 diemSo });	
"	LuuDiem(scores);"		
"	"		
}		
void Menu()
{
	ShowCur(0);
	Logo();
	ShowLuaChon();
	int choose = 0;
	while (true) {
		if (_kbhit())
		{
			c = _getch();
			if (c == '1')
			{
				Logo();
				ShowLuaChon();
				ShowMuiten(1);
				choose = 1;
			}
			else if (c == '2')
			{
				Logo();
				ShowLuaChon();
				ShowMuiten(2);
				choose =2;
			}
			else if (c == '3')
			{
				Logo();
				ShowLuaChon();
				ShowMuiten(3);
				choose = 3;
			}
			else if (c == '4')
			{
				Logo();
				ShowLuaChon();
				ShowMuiten(4);
				choose = 3;
			}
			else if (c == 13)
			{
				if (choose == 1)
				{
					system("cls");
					game();
				}
				else if (choose == 2)
				{
					system("cls");
					scores = DocDiem();
					HienThiDiem(scores);
					break;
				}
				else if (choose == 3)
				{
					system("cls");
					VeKhung();
					gotoXY(14, 3); cout << "#guide play----" << endl;
					gotoXY(14, 4); cout << "-Players use keyboard arrow keys to move" << endl;
					gotoXY(14, 5); cout << "-The goal is to eat '@' to make the snake grow longer, each '@' will add 1 point" << endl;
					gotoXY(14, 6); cout << "#Note that the snake's speed will have three levels, default level 1" << endl;
					gotoXY(14, 7); cout << "-Level 2 is unlocked when you earn 20 points" << endl;
					gotoXY(14, 8); cout << "-Level 3 is unlocked when you earn 40 points (very fast)" << endl;
					gotoXY(44, 22); cout << "(Press any to exit)" << endl;
					gotoXY(44, 23); cout << "----@2023-11-11----" << endl;
					_getch();
					system("cls");
					Menu();
					
					break;
				}
				else if (choose == 4)
				{
					system("cls");
					cout << "Goodbye" << endl;
					break;
				}


			}
		}
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
			soDotRan=4;
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
