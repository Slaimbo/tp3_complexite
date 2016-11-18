#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char ** argv)
{
	unsigned int nb_sommet = atoi(argv[1]);
	unsigned int nb_arcs   = atoi(argv[2]);
	argv += 3;

	cout << "p cnf " << nb_sommet << ' ' << (nb_sommet + nb_arcs) << endl;

	for( unsigned int i = 0; i < nb_arcs*2 ; i+=2 )
	{
		cout << "-" << argv[i] << " -" << argv[i+1] << " 0" << endl;
	}

	for ( unsigned int i = 0; i < nb_sommet; i++)
	{
		cout << i+1 << ' ';
		for( unsigned int j = 0; j < nb_arcs*2 ; j+=2 )
		{
			if( i+1 == (unsigned int) atoi( argv[j] ) )
				cout << argv[j+1] << ' ';
		}
		cout << '0' << endl;
	}

	return 0;
}
