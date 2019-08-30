#include <iostream>
#include <vector>
using namespace std;

void print_board(vector<int> &v)
{
	int n= v.size();
	for(int j=0;j<n;j++){
		for (int i = 0; i < n; i++)
		{
			if(v[j]==i)
				cout<<"#";
			else
				cout<<".";
			if(i!=n-1)
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void f(vector<int> &v , int n)
{
	int i=v.size();
	if(i==n)
	{	
		print_board (v);
		return;
	}
	for(int j=0;j<n ; j++)
	{
		bool tekrari=false;
		for(int k=0;k<v.size();k++)
			if(v[k]==j)
				tekrari =true;

		bool ghotri=false;
		for(int k=0;k<v.size() ; k++)
		 	if(k-v.size() == v[k]-j || k-v.size()== -(v[k]-j))
		 		ghotri = true; 

		bool asb=false;
		for(int k=0; k<v.size() ; k++)
		{
			if((v.size()-k == 2 && (j-v[k]==1||j-v[k]==(-1)) ||(v.size()-k==1 && (j-v[k]==2||j-v[k]==(-2)))))
				asb=true;
		}
		if(tekrari  || ghotri || asb) 
			continue;

		v.push_back(j);
		f(v,n);
		v.pop_back();
	}
	
}
int main()
{
	int n;
	cin>> n;
	vector <int> v;
	f(v,n);
}