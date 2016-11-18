#include <iostream>
#include <stdlib.h>

#define taille 9

using namespace std;

bool intinliste( int * liste)
{
	int i;
	for( i = 0; i < taille and liste[i] != 0; i++);
	if( i == 9 )
		return false;
	return true;
}


bool inik_fix(int matrice[taille][taille], int k)
{
	for(int j = 0; j < taille; j++)
	{
		if(matrice[j][k] == 0)
			return true;
	}
	return false;
}

bool injk_fix(int matrice[taille][taille][taille], int k, int j)
{
	for(int i = 0; i < taille; i++)
	{
		if( matrice[i][j][k] == 0 )
			return true;
	}
	return false;
}

bool ink_fix_inter(int matrice[taille][taille][taille], int k, int min_i, int max_i, int min_j, int max_j)
{
	
	for(int i = min_i; i < max_i; i++)
	{
		for(int j = min_j; j < max_j; j++)
		{
			if(matrice[i][j][k] == 0)
				return true;
		}
	}
	return false;
}





int main(int argc, char** argv)
{
	//recuperation et creation de la matrice 3d de notre sudoku partiellement rempli
	int grille_sudoku[taille][taille][taille];
	int var_name = 1;
	int curr = 0;
	int nb_set = 0;

	for( int i = 0; i < taille; i++)
	{
		for( int j = 0; j < taille; j++)
		{
			for( int k = 0; k < taille; k++)
			{
				if( (k + 1) ==  argv[1][curr] - 48 ) //si la case est rempli
				{
					grille_sudoku[i][j][k] = 0;
					nb_set++;
				}
				else
				{
					grille_sudoku[i][j][k] = var_name++;
				}
			}
			curr++;			
		}
	}

	//Entete minisat
	cout << "p cnf " << 729-nb_set << " ght\n\n";


	//Creation de phi 1
	for( int i = 0; i < taille; i++)
	{
		for(int j = 0; j < taille; j++)
		{
			if( !intinliste( grille_sudoku[i][j] ) )
			{
				for(int k = 0; k < taille; k++)
				{
					cout << grille_sudoku[i][j][k] << ' ';
				}
				cout << '0' << endl;
			}
		}
	}


	//Creation de phi 2
	//cout << "------------------------------------------------------\n";
	for( int i = 0; i < taille; i++ ) 
	{
		for( int k = 0; k < taille; k++)
		{
			if( !inik_fix(grille_sudoku[i], k))
			{
				for(int j = 0; j < taille; j++)
				{
					cout << grille_sudoku[i][j][k] << ' ';
				}
				cout << '0' << endl;
			}
		}
	}

	//Creation de phi 3
	//cout << "------------------------------------------------------\n";
	for( int j = 0; j < taille; j++ ) 
	{
		for( int k = 0; k < taille; k++)
		{
			if( !injk_fix(grille_sudoku, k, j))
			{
				for(int i = 0; i < taille; i++)
				{
					cout << grille_sudoku[i][j][k] << ' ';
				}
				cout << '0' << endl;
			}
		}
	}

	//Creation de phi 4
	//cout << "------------------------------------------------------\n";
	for( int a = 0; a < 3; a++)
	{
		for(int b = 0; b < 3; b++)
		{
			for(int k = 0; k < taille; k++)
			{
				if( !ink_fix_inter(grille_sudoku, k, 3 * a, 3 + 3 * a, 3 * b, 3 + 3 * b))
				{
					for(int i = 3 * a; i < 3 + 3 * a; i++)
					{
						for(int j = 3 * b; j < 3 + 3 * b; j++)
						{
							cout << grille_sudoku[i][j][k] << ' ';
						}
					}
					cout << '0' << endl;
				}
			}
		}
	}

	//Creation de phi 5
	//cout << "------------------------------------------------------\n";
	for( int i = 0; i < taille; i++)
	{
		for( int j = 0; j < taille; j++)
		{
			for( int k1 = 0; k1 < taille; k1++)
			{
				for( int k2 = 0; k2 < taille; k2++)
				{
					if( k1 != k2 )
					{
						if( grille_sudoku[i][j][k1] != 0 )
							cout << '-' << grille_sudoku[i][j][k1] << ' ';
						if( grille_sudoku[i][j][k2] != 0 )
							cout << '-' << grille_sudoku[i][j][k2] << ' ';
						if( (grille_sudoku[i][j][k1] == 0) and (grille_sudoku[i][j][k2] == 0) )
						{
							cout << "UNSATISFABLE" << endl;
							exit(1);
						}
						cout << '0' << endl;
					}
				}
			}
		}
	}

	//Creation de phi 6
	//cout << "------------------------------------------------------\n";
	for( int i = 0; i < taille; i++)
	{
		for( int k = 0; k < taille; k++)
		{
			for( int j1 = 0; j1 < taille; j1++)
			{
				for( int j2 = 0; j2 < taille; j2++ )
				{
					if( j1 != j2 )
					{
						if( grille_sudoku[i][j1][k] != 0 )
							cout << '-' << grille_sudoku[i][j1][k] << ' ';
						if( grille_sudoku[i][j2][k] != 0 )
							cout << '-' << grille_sudoku[i][j2][k] << ' ';
						if( (grille_sudoku[i][j1][k] == 0) and (grille_sudoku[i][j2][k] == 0) )
						{
							cout << "UNSATISFABLE" << endl;
							exit(1);
						}
						cout << '0' << endl;
					}
				}
			}
		}
	}

	//Creation de phi 7
	//cout << "------------------------------------------------------\n";
	for( int j = 0; j < taille; j++)
	{
		for( int k = 0; k < taille; k++)
		{
			for( int i1 = 0; i1 < taille; i1++)
			{
				for( int i2 = 0; i2 < taille; i2++ )
				{
					if( i1 != i2 )
					{
						if( grille_sudoku[i1][j][k] != 0 )
							cout << '-' << grille_sudoku[i1][j][k] << ' ';
						if( grille_sudoku[i2][j][k] != 0 )
							cout << '-' << grille_sudoku[i2][j][k] << ' ';
						if( (grille_sudoku[i1][j][k] == 0) and (grille_sudoku[i2][j][k] == 0) )
						{
							cout << "UNSATISFABLE" << endl;
							exit(1);
						}
						cout << '0' << endl;
					}
				}
			}
		}
	}

	//Creation de phi 8
	//cout << "------------------------------------------------------\n";
	for( int a = 0; a < 3; a++)
	{
		for( int b = 0; b < 3; b++)
		{
			for( int k = 0; k < taille; k++)
			{
				for( int i1 = 3*a; i1 < 3+3*a; i1++ )
				{
					for( int i2 = 3*a; i2 < 3+3*a; i2++ )
					{
						if( i1 != i2 )
						{
							for( int j1 = 3*b; j1 < 3+3*b; j1++)
							{
								for( int j2 = 3*b; j2 < 3+3*b; j2++)
								{
									if( j1 != j2 )
									{				
										if( grille_sudoku[i1][j1][k] != 0 )
											cout << '-' << grille_sudoku[i1][j1][k] << ' ';
										if( grille_sudoku[i2][j2][k] != 0 )
											cout << '-' << grille_sudoku[i2][j2][k] << ' ';
										if( (grille_sudoku[i1][j1][k] == 0) and (grille_sudoku[i2][j2][k] == 0) )
										{
											cout << "UNSATISFABLE" << endl;
											exit(1);
										}
										cout << '0' << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
