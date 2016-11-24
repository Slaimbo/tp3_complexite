#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main (int argc, char** argv)
{
	ifstream file(argv[1], ios::in);
	int i = 0;
	char car;
	char sudoku[9][9];
	string str;
	
	if(!file)
	{
		cout << "Erreur d'ouverture du fichier" << endl;
		return 1;
	}
	
	while((car = argv[2][i]) != '\0')
	{
		if(car == '.')
		{
			getline(file, str);
			car = atoi(str.c_str()) % 9;
			if(car == 0)
				car = 9;
			sudoku[i/9][i%9] = car;		
		}
		else
			sudoku[i/9][i%9] = car - 48;
		i++;
	}
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << (int) sudoku[i][j] << ' ';
		}
		cout << endl;
	}
	file.close();
	return 0;
}
