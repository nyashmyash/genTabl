// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>


using namespace std;

class Table
{
private:
	std::vector<std::vector<int>> table;
	int size_R, size_C;
public:
	
	Table::Table(std::vector<std::vector<int>> mas, int size_r, int size_c);
	
	void setValue(int row, int col, int val);
	void setSize(int size_r, int size_c);
	
	std::string GetTable();

};

Table::Table(std::vector<std::vector<int>>  mas, int size_r, int size_c)
{
	for (int i = 0; i < size_r; i++ )
	{
		std::vector<int> row;
		for (int j = 0; j < size_c; j++ )
		{
			row.push_back(mas[i][j]);
		}
		table.push_back(row);
	}
	size_R = size_r;
	size_C = size_c;
}

void Table::setValue(int row, int col, int val)
{
	if (row>size_R||col>size_C)
		setSize(row, col);
	table[row][col] = val;
}

void Table::setSize(int size_r, int size_c)
{
	for (int i = 0; i < table.size(); i++ )
	{
		if (i >= size_r)
		{
			table.resize(size_r);
			break;
		}
		else
			if(table[i].size() >= size_c) 
				table[i].resize(size_c);
	}
	for (int i = 0; i < size_r; i++ )
	{
		std::vector<int> row;
		if (i >= table.size())
		{
			for (int j = 0; j < size_c; j++ )
				row.push_back(0);
			
			table.push_back(row);
		}
		else
		{
			for (int j = 0; j < size_c; j++ )
			{
				if (j >= table[i].size() ) table[i].push_back(0);
			}
		}
	}
	size_R = size_r;
	size_C = size_c;
}

std::string Table::GetTable()
{
	std::string str;
	str.append("<table>");
	for (int i =0; i< size_R; i++)
	{
		str.append("<tr>");
		for (int j =0; j< size_C; j++)
		{
			char appstr[100];
			sprintf_s(appstr,"<td>%i</td>",table[i][j]);
			str.append(appstr);
		}
		str.append("</tr>");
	}
	str.append("</table>");
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::vector<int>>  mas;
	int rows = 5;
	int cols = 3;


	for (int i =0; i < rows; i++)
	{
		std::vector<int> add;
		for (int j =0; j < cols; j++)
		{
			add.push_back(rand()%1000);
		}
		mas.push_back(add);
	}
	
	Table tab = Table(mas,rows,cols);
	
	std::cout<<tab.GetTable().c_str();
	int newRow=0, newCol=0;
	std::cout<<endl;
	setlocale(LC_ALL, "Russian");
	std::cout<<"Введите новый размер таблицы\n";

	while (newCol==0 || newRow==0)
	{
		char srow[10];
		char scol[10];
		std::cin>>srow;
		std::cin>>scol;
		newRow = atoi(srow);
		newCol = atoi(scol);
		if ( newCol==0 || newRow==0)
			std::cout<<"Неправильно введены размеры\n";
	}
	tab.setSize(newRow,newCol);
	std::cout<<tab.GetTable().c_str();

	int gg;
	std::cin>>gg;

	return 0;
}

