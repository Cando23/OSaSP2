#include "Table.h";
#include <fstream>
#include <sstream>
Table::Table(string path) {
	ReadDataFromFile(path);
}
void Table::ReadDataFromFile(string path) {
	string line;
	ifstream File(path);

	while (getline(File, line)) {
		vector<string> line_data;
		string value;
		stringstream sstream(line);
		while (getline(sstream, value, ';')) {
			line_data.push_back(value);
		}
		data.push_back(line_data);
	}
	this->rowCount = data.size();
	this->columnCount = data[0].size();
	File.close();
}
void DrawRow(HDC hdc, int x, int y) {
	MoveToEx(hdc, 0, y, nullptr);
	LineTo(hdc, x, y);
}
void DrawColumn(HDC hdc, int x, int y) {
	MoveToEx(hdc, x, 0, nullptr);
	LineTo(hdc, x, y);
}
void Table::Draw(HDC hdc, RECT clientRect) {
	TEXTMETRIC tm;
	GetTextMetrics(hdc, &tm);
	int tmHeight = tm.tmHeight;
	int cellWidth = (clientRect.right - clientRect.left) / this->columnCount;
	int tableHeight = 0;
	DrawRow(hdc, clientRect.right, tableHeight);
	for (int i = 0; i < this->rowCount; i++) {
		int maxHeight = 0;
		for (int j = 0; j < this->columnCount; j++) {
			RECT cell = { j * cellWidth, tableHeight + tmHeight, (j + 1) * cellWidth, clientRect.bottom };
			LPCSTR value = this->data[i][j].c_str();
			int cellHeight = DrawTextA(hdc, value, -1, &cell, DT_WORDBREAK | DT_CENTER);
			if (cellHeight > maxHeight) maxHeight = cellHeight;
		}
		tableHeight += maxHeight + 2 * tmHeight;
		DrawRow(hdc, clientRect.right, tableHeight);
	}
	for (int j = 0; j < this->data[0].size(); j++) {
		DrawColumn(hdc, j * cellWidth, tableHeight);
	}
}