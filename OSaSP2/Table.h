#pragma once
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;
class Table {
private:
	vector<vector<string>> data;
	int rowCount;
	int columnCount;
public:
	Table(string path);
	void Draw(HDC hdc, RECT clientRect);
	void ReadDataFromFile(string path);
};
