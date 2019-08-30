#include <iostream>
#include <string>
using namespace std;

int h;

void palindrome(string word, int &k){
	k = 1;
	for(int i=0;i < (h/2) && (k==1); i++){
		if(word[i]!=word[h-i-1])
			k=0;
	}
}
string reverse(string newword){
	for (int i = 0; i < h/2 ; i++)
	{
		switch(newword[i]){
			case '3':
				newword[i] = 'E';
				break;
			case '2':
				newword[i] = 'S';
				break;
			case '5':
				newword[i] = 'Z';
				break;
			case 'J':
				newword[i] = 'L';
				break;
			case 'E':
				newword[i] = '3';
				break;
			case 'S':
				newword[i] = '2';
				break;
			case 'Z':
				newword[i] = '5';
				break;
			case 'L':
				newword[i] = 'J';
				break;
		}
	}
	return newword;
}
void mirrored(string newword, int &b){
	b = 1;
	for (int i = 0; (i < h) && (b==1); i++)
		if (newword[i] == 'B'||
			newword[i] == 'C'||
			newword[i] == 'D'||
			newword[i] == 'F'||
			newword[i] == 'G'||
			newword[i] == 'K'||
			newword[i] == 'N'||
			newword[i] == 'P'||
			newword[i] == 'Q'||
			newword[i] == 'R'||
			newword[i] == '4'||
			newword[i] == '6'||
			newword[i] == '7'||
			newword[i] == '9')
				b=0;
	if(b==1)
		palindrome(newword,b);
	if((b == 1) && (h % 2 == 1))
			if (newword[h/2] != 'A'&&
				newword[h/2] != 'H'&&
				newword[h/2] != 'I'&&
				newword[h/2] != 'M'&&
				newword[h/2] != 'O'&&
				newword[h/2] != 'T'&&
				newword[h/2] != 'U'&&
				newword[h/2] != 'V'&&
				newword[h/2] != 'W'&&
				newword[h/2] != 'X'&&
				newword[h/2] != 'Y'&&
				newword[h/2] != '1'&&
				newword[h/2] != '8')
					b=0;
	}

int main(){
	string word,newword;
	int k,b;
	while(cin >> word){
	h = word.length();
	for (int i = 0; i < h; i++)
		if(word[i]=='0')
			word[i] = 'O';
	newword=word;
	palindrome(word,k);
	newword = reverse (newword);
	mirrored(newword,b);
	if(k == 0 && b == 0)
		cout<<word<<" -- is not a palindrome."<< endl << endl; 
	else if(k == 1 && b == 0)
		cout<<word<<" -- is a regular palindrome."<< endl << endl;
	else if(k == 0 && b == 1)
		cout<<word<<" -- is a mirrored string."<< endl <<endl;
	else if(k == 1 && b == 1)
		cout<<word<<" -- is a mirrored palindrome."<< endl <<endl;
	}
	return 0;
}