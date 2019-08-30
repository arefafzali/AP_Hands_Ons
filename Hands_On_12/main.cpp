#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct instanceOfRoles{
	int count=0;
	string name;
};


int cToi(char n){
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

int sToi(string name){
	int n=0;
	for(int i=0;i<name.size();i++){
		n+=cToi(name[i]);
		n*=10;
	}
	n=n/10;
	return n;
}

bool Check_Strings(string fname,string sname){
	if(fname.size()==sname.size()){
		for(int i=0;i<fname.size();i++){
			if(fname[i]!=sname[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Roles{
public:
	// string Set_Name(string name){return name;}
	virtual int Pass_Count(){return count;}
	virtual void Set_Count(int c){count=c;}
	virtual string Pass_Role_Type()=0;
// private:
	// string name;
protected:
	int count;
};
class Mafia:public Roles{
public:
	string Pass_Role_Type(){return "Mafia";}
	// int Set_Count(int c)
private:
};
class Joker:public Roles{
public:
	string Pass_Role_Type(){return "Joker";}
private:
};
class Villager:public Roles{
public:
	string Pass_Role_Type(){return "Villager";}
private:
};
class Detective:public Roles{
public:
	string Pass_Role_Type(){return "Detective";}
private:
};
class Doctor:public Roles{
public:
	string Pass_Role_Type(){return "Doctor";}
private:
};
class RouinTan:public Roles{
public:
	string Pass_Role_Type(){return "RouinTan";}
private:
};
class GodFather:public Roles{
public:
	string Pass_Role_Type(){return "GodFather";}
private:
};
class Silencer:public Roles{
public:
	string Pass_Role_Type(){return "Silencer";}
private:
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Room{
public:
	~Room(){
		for(int i=0;i<roles.size();i++){
			delete roles[i];
		}
	}
	string Pass_Name(){return roomname;}
	template <class T>
	void Set_Roles(T roletype,int count);
	void Get_Room_name(string name){roomname=name;}
	void Check_Name(vector<Room> rooms,string roomname);
	string Pass_Room_name(){return roomname;}
private:
	vector<Roles*> roles;
	string roomname;
	//int room_number;
};
template <class T>
void Room::Set_Roles(T roletype,int count){
	bool repeated=false;
	// cout<<count<<"kjhgfcxznbhgvcxbvcx"<<endl;
	if(count<0){
		throw "Invalid Role Number!";
	}
	for(int i=0;i<roles.size();i++){
		if(roles[i]->Pass_Role_Type()==roletype.Pass_Role_Type()){
			repeated=true;
			roles[i]->Set_Count(count);
		}
	}
	if(!repeated){
		roles.push_back(new T());
		roles[roles.size()-1]->Set_Count(count);
	}
}
void Room::Check_Name(vector<Room> rooms,string roomname){
	for(int i=0;i<rooms.size();i++){
		if(Check_Strings(roomname,rooms[i].Pass_Name())){
			string chert;
			getline(cin,chert);
			throw "Room Name Has Been Used Before!";
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class God{
public:
	void Create_Room(vector<Room>& rooms,string& command);
};
void God::Create_Room(vector<Room>& rooms,string& command){
	string roomname;
	cin>>roomname;
	bool endofline=false;
	Room room;
	room.Check_Name(rooms,roomname);
	room.Get_Room_name(roomname);
	// room.Check_Roles()
	string line;
	vector<instanceOfRoles> roles;
	getline(cin,line);
	// bool notanumber=true,notaname=false;
	line.erase(line.begin());
	string roletype;
	for(int i=0;i<line.size();i++){
		if(line[i]!=' '){
			roletype.push_back(line[i]);
		}
		else{
			instanceOfRoles instance;
			instance.name=roletype;
			string num;
			for(i++;line[i]!=' ' && i<line.size();i++){
				num.push_back(line[i]);
			}
			// cout<<roletype<<endl;
			instance.count= sToi(num);
			roles.push_back(instance);
			roletype.erase(roletype.begin(),roletype.end());
			// i--;
		}
	}
	// cout<<"hiiiiiiiiiiiiiiii"<<endl;
	for(int i=0;i<roles.size();i++){
		roles[i].name.erase(roles[i].name.begin());
		if(roles[i].name=="Mafia"){
			Mafia mafia;
			room.Set_Roles(mafia,roles[i].count);
		}
		else if(roles[i].name=="Villager"){
			Villager villager;
			room.Set_Roles(villager,roles[i].count);
		}
		else if(roles[i].name=="Joker"){
			Joker joker;
			room.Set_Roles(joker,roles[i].count);
		}
		else if(roles[i].name=="Detective"){
			Detective detective;
			room.Set_Roles(detective,roles[i].count);
		}
		else if(roles[i].name=="Doctor"){
			Doctor doctor;
			room.Set_Roles(doctor,roles[i].count);
		}
		else if(roles[i].name=="RouinTan"){
			RouinTan rouintan;
			room.Set_Roles(rouintan,roles[i].count);
		}
		else if(roles[i].name=="Silencer"){
			Silencer silencer;
			room.Set_Roles(silencer,roles[i].count);
		}
		else if(roles[i].name=="GodFather"){
			GodFather godFather;
			room.Set_Roles(godFather,roles[i].count);
		}
		else{
			// string chert;
			// getline(cin,chert);
			throw "Invalid Role!";
		}
	}
	rooms.push_back(room);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	God god;
	vector<Room> rooms;
	Room room;
	string command;
	while(cin>>command){
		//cout<<"hiiiiiiiiiiiiiiii"<<endl;
		try{
			if(command=="Create_room"){
				god.Create_Room(rooms,command);
				room=rooms[rooms.size()-1];
			}
			else if(command=="Switch_room"){
				string line,roomname;
				bool hasname=false,hasroom=false;
				getline(cin,line);
				for(int i=0;i<line.size();i++){
					if(line[i]!=' '){
						hasname=true;
						roomname.push_back(line[i]);
					}
				}
				if(!hasname){
					throw "Invalid room name";
				}
				for(int i=0; i<rooms.size();i++){
					if(Check_Strings(roomname,rooms[i].Pass_Room_name())){
						room=rooms[i];
						hasroom=true;
					}
				}
				if(!hasroom){
					throw "Invalid room name";
				}
			}
			else if(command=="Join"){

			}
			else{
				string chert;
				getline(cin,chert);
				throw "Command Not Found!";
			}
			
		}catch(const char* except){
			cerr<<except<<endl;
		}
	}
	return 0;
}