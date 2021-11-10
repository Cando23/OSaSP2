#pragma once
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;
class Table {
private:
	vector<vector<string>> data;
	int rowsCount;
	int colCount;
public:
	Table();
	~Table();
	void Draw(HDC hdc, RECT windowRect);
	void ReadDataFromFile(string path);
};
