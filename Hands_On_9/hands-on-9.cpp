#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ShapeType{
	public:
		virtual void SetName()=0;
		void setShapeId(string name) {shapeid = name;};
		virtual int Area()=0;
		virtual int Volume()=0;
		string shapeid;
		string shape="null";

};

class Cube:public ShapeType{
	private:
		int x;
		int y;
		int z;
	public:
		int Area(){
			return 2 * (x * y + x * z + y * z);
		}
		int Volume(){
			return x*y*z;
		}
		void SetName(){
			cin>>x>>y>>z;
			shape="cube";
		}
};

class Cylinder:public ShapeType{
	private:
		int r;
		int h;
	public:
		int Area(){
			return 2*((M_PI)*r*(h+r));
		}
		int Volume(){
			return (M_PI)*r*r*h;
		}
		void SetName(){
			cin>>r>>h;
			shape="cylinder";
		}
};
class Cone:public ShapeType{
	private:
		int r;
		int h;
	public:
		int Area(){
			return (M_PI)*r*(r+sqrt(h*h+r*r));
		}
		int Volume(){
			return (M_PI)*r*r*h/3;
		}
		void SetName(){
			cin>>r>>h;
			shape="cone";
		}
};
class Sphere:public ShapeType{
	private:
		int r;
	public:
		int Area(){
			return 4*(M_PI)*r*r;
		}
		int Volume(){
			return 4*(M_PI)*r*r*r/3;
		}
		void SetName(){
			cin>>r;
			shape="sphere";
		}
};

int main(){
	string command;
	string name;
	vector<ShapeType*> shapepoint;
	while(cin>>command){
		if(command =="cube"){
			int d=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++)
				if(name==shapepoint[i]->shapeid){
					cout<<"Command failed!"<<endl;
					d=1;
				}
			if(d==0){
				shapepoint.push_back(new Cube);
				shapepoint[shapepoint.size() - 1]->setShapeId(name);
				shapepoint[shapepoint.size() - 1]->SetName();
			}
		}
		else if(command =="sphere"){
			int d=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++)
				if(name==shapepoint[i]->shapeid){
					cout<<"Command failed!"<<endl;
					d=1;
				}
			if(d==0){
				shapepoint.push_back(new Sphere);
				shapepoint[shapepoint.size() - 1]->setShapeId(name);
				shapepoint[shapepoint.size() - 1]->SetName();
			}
		}
		else if(command =="cone"){
			int d=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++)
				if(name==shapepoint[i]->shapeid){
					cout<<"Command failed!"<<endl;
					d = 1;
				}
			if(d==0){
				shapepoint.push_back(new Cone);
				shapepoint[shapepoint.size() - 1]->setShapeId(name);
				shapepoint[shapepoint.size() - 1]->SetName();
			}
		}
		else if(command =="cylinder"){
			int d=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++)
				if(name==shapepoint[i]->shapeid){
					cout<<"Command failed!"<<endl;
					d=1;
				}
			if(d==0){
				shapepoint.push_back(new Cylinder);
				shapepoint[shapepoint.size() - 1]->setShapeId(name);
				shapepoint[shapepoint.size() - 1]->SetName();
			}
		}
		else if(command =="area"){
			int c=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++){
				if(name==shapepoint[i]->shapeid){
					c=1;
					if(shapepoint[i]->shape=="cube")
						cout<<"Cube area : "<<shapepoint[i]->Area()<<endl;
					else if(shapepoint[i]->shape=="cylinder")
						cout<<"Cylinder area : "<<shapepoint[i]->Area()<<endl;
					else if(shapepoint[i]->shape=="cone")
						cout<<"Cone area : "<<shapepoint[i]->Area()<<endl;
					else if(shapepoint[i]->shape=="sphere")
						cout<<"Sphere area : "<<shapepoint[i]->Area()<<endl;
				}
			}
			if(c==0){
				cout<<"Not found!"<<endl;
			}
		}
		else if(command=="volume"){
			int c=0;
			cin>>name;
			for(int i=0;i<shapepoint.size();i++){
				if(name==shapepoint[i]->shapeid){
					c=1;
					if(shapepoint[i]->shape=="cube")
						cout<<"Cube volume : "<<shapepoint[i]->Volume()<<endl;
					else if(shapepoint[i]->shape=="cylinder")
						cout<<"Cylinder volume : "<<shapepoint[i]->Volume()<<endl;
					else if(shapepoint[i]->shape=="cone")
						cout<<"Cone volume : "<<shapepoint[i]->Volume()<<endl;
					else if(shapepoint[i]->shape=="sphere")
						cout<<"Sphere volume : "<<shapepoint[i]->Volume()<<endl;
				}
			}
			if(c==0)
				cout<<"Not found!"<<endl;
		}
	}
	for(int i=0;i<shapepoint.size();i++){
		delete shapepoint[i];
	}
	return 0;
}