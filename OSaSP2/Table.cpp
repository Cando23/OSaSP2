#include "Table.h";
#include <fstream>
#include <sstream>
Table::Table(string path){
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
void Table::Draw(HDC hdc, RECT windowRect) {

}