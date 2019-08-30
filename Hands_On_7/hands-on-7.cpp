#include <iostream>
//#include <string_view>
#include <vector>

using namespace std;


class People
{
public:
	string name;
	vector<string> albums;
	int age;
	string city;
	string get_name();
	int get_age();
	string get_city();
	vector<string> get_albums();
};

vector<string> People::get_albums(){
	string line,notline;
	vector<string> albums;
	int h=0,k=0;
	bool t=false,go=false;
	getline(cin,notline);
	while(t){
		getline(cin,line);
		if(line[0]=='-')
			t=true;
		else{
			for(int i=0;i<line.size();i++){
				if(line[i]=='-')
					go=true;
				if(go){
					if(line[i]!=' ')
						albums[h][k]=line[i];
						k++;
				}
			}
		}
		h++;
	}
	return albums;
}

//moshkel dashtan gereftan voroodi
string People::get_name(){
	string peoplenames,name;
	int k=0;
	bool go=false;
	getline(cin,peoplenames);
	/*for(int i=0;i<100;i++){
		char x;
		cin>>x;
		peoplenames.push_back(x);*/
	for(int i=0;i<peoplenames.size();i++){
		if(peoplenames[i]==':')
			go=true;
		if(go){
			if(peoplenames[i]!=' '){
				name[k]=peoplenames[i];
				//cout<<name[k];
				k++;
			}
		}
		if (go && peoplenames[i]==' ')
			break;
	}
	cout<<name<<"aleki"<<endl;
	return name;
}

int sToi(char n){
	int x;
	switch(n){
		case '0':
			x=0;
			break;
		case '1':
			x=1;
			break;
		case '2':
			x=2;
			break;
		case '3':
			x=3;
			break;
		case '4':
			x=4;
			break;
		case '5':
			x=5;
			break;
		case '6':
			x=6;
			break;
		case '7':
			x=7;
			break;
		case '8':
			x=8;
			break;
		case '9':
			x=9;
			break;
	}
	return x;
}

int People::get_age(){
	string peopleage;
	int age=0;
	bool go=false;
	getline(cin,peopleage);
	for(int i=0;i<peopleage.size();i++){
		if(peopleage[i]==':')
			go=true;
		if(go){
			if(peopleage[i]!=' '){
				age*=10;
				age+=sToi(peopleage[i]);
			}
		}
	}
	return age;
}

string People::get_city(){
	string peoplecity,city;
	int k=0;
	bool go=false;
	getline(cin,peoplecity);
	for(int i=0;i<peoplecity.size();i++){
		if(peoplecity[i]==':')
			go=true;
		if(go){
			if(peoplecity[i]!=' '){
				city[k]=peoplecity[i];
				k++;
			}
		}
	}
	return city;
}

class Albums{
public:
	string name;
	string singer;
	string genre;
	int tracks;
	string get_name();
	string get_singer();
	string get_genre();
	int get_tracks();
};

string Albums::get_name(){
	string albumsname,name;
	int k=0;
	bool go=false;
	getline(cin,albumsname);
	for(int i=0;i<albumsname.size();i++){
		if(albumsname[i]==':')
			go=true;
		if(go){
			if(albumsname[i]!=' '){
				name[k]=albumsname[i];
				k++;
			}
		}
	}
	return name;
}

string Albums::get_singer(){
	string singer,name;
	int k=0;
	bool go=false;
	getline(cin,singer);
	for(int i=0;i<singer.size();i++){
		if(singer[i]==':')
			go=true;
		if(go){
			if(singer[i]!=' '){
				name[k]=singer[i];
				k++;
			}
		}
	}
	return name;
}

string Albums::get_genre(){
	string genre,name;
	int k=0;
	bool go=false;
	getline(cin,genre);
	for(int i=0;i<genre.size();i++){
		if(genre[i]==':')
			go=true;
		if(go){
			if(genre[i]!=' '){
				name[k]=genre[i];
				k++;
			}
		}
	}
	return name;
}

int Albums::get_tracks(){
	string line;
	int tracks=0;
	bool go=false;
	getline(cin,line);
	for(int i=0;i<line.size();i++){
		if(line[i]==':')
			go=true;
		if(go){
			if(line[i]!=' '){
				tracks*=10;
				tracks+=sToi(line[i]);
			}
		}
	}
	return tracks;
}

int main(){
	
	int peoplenum,albumsnum,processnum,num;
	string line;
	cin>>peoplenum;
	People people[peoplenum];
	for(int i=0;i<peoplenum;i++){
		people[i].name=people[i].get_name();
		people[i].age=people[i].get_age();
		people[i].city=people[i].get_city();
		people[i].albums=people[i].get_albums();
	}
	cout<<"hi"<<endl;
	for(int i=0;i<peoplenum;i++){
		cout<<people[i].name;
	}
	cin>>albumsnum;
	Albums albums[albumsnum];
	for(int i=0;i<albumsnum;i++){
		albums[i].name=albums[i].get_name();
		albums[i].singer=albums[i].get_singer();
		albums[i].genre=albums[i].get_genre();
		albums[i].tracks=albums[i].get_tracks();
	}
	cin>>processnum;
	char x;
	for(int i=0;i<processnum;i++){
		string nameperson,singer,genre,city;
		int tracks=0,age=0,c=0,sum=0;
		cin>>num;
		switch(num){
			case 1:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						nameperson[i] = line[i];
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						singer[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(nameperson==people[i].name)
						for(int j=0;j<albumsnum;j++)
							if(singer==albums[j].singer)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;
				break;
			case 2:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						nameperson[i] = line[i];
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						genre[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(nameperson==people[i].name)
						for(int j=0;j<albumsnum;j++)
							if(genre==albums[j].genre)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;
				break;
			case 3:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						age*=10;
						age += sToi(line[i]);
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						singer[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(age==people[i].age)
						for(int j=0;j<albumsnum;j++)
							if(singer==albums[j].singer)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;
				break;
			case 4:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						age*=10;
						age += sToi(line[i]);
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						genre[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(age==people[i].age)
						for(int j=0;j<albumsnum;j++)
							if(genre==albums[j].genre)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;
				break;
			case 5:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						city[i] = line[i];
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						singer[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(city==people[i].city)
						for(int j=0;j<albumsnum;j++)
							if(singer==albums[j].singer)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;

				break;
			case 6:
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '&&c==0){
						city[i] = line[i];
						if(line[i+1]==' ')
							c++;
					}
					else if(line[i]!=' '&& c==1)
						genre[i]=line[i];
				}
				for(int i=0;i<peoplenum;i++)
					if(city==people[i].city)
						for(int j=0;j<albumsnum;j++)
							if(genre==albums[j].genre)
								for(int k=0;k<people[i].albums.size();k++)
									if(albums[j].name==people[i].albums[k])
										sum+=albums[j].tracks;
				break;
		}
		cout<<sum<<endl;
	}

	/*
	char x;
	string line;
	cin>>x;
	getline(cin,line);
	cout<<line;*/
	
	return 0;
}