#include <iostream>

using namespace std;

int n;
void rock(char [9][9] , int );



int main()
{
	
	while(cin >> n){
		char chess[9][9];
		int r=0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				chess[i][j]=' ';
		rock(chess, r);

	}
	return 0;
}


void rock(char chess[9][9] , int r){
	if(r==n){
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++){
				cout<< chess[i][j];
				if(j!=n-1)
					cout<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}

	char newchess[9][9];
	for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				newchess[i][j]=chess[i][j];

		int i=r;
		for (int j = 0; j < n; j++)
			if(newchess[i][j]==' ')
			{
				for (int k = 0; k < n; k++)
					newchess[i][k]='.';
				for (int k = 0; k < n; k++)
					newchess[k][j]='.';
				newchess[i][j]='R';
				rock(newchess ,r+1);
				for (int l = 0; l < n; l++)
					for (int m = 0; m < n; m++)
						newchess[l][m]=chess[l][m];
			}
	
}