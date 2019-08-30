#include<iostream>
#include<vector>

using namespace std;

vector<char> read_network(int num_of_inputs,int num_of_stages){
	char n;
	vector<char> read_networks;
	for(int i=0;i<num_of_inputs;i++)
		for(int j=0;j<num_of_stages;j++){
			cin>>n;
			read_networks.push_back(n);
		}
	return read_networks;
}

vector<int> read_numbers(int num_of_inputs){
	int n;
	vector<int> read_number;
	for(int i=0;i<num_of_inputs;i++){
		cin>>n;
		read_number.push_back(n);
	}
	return read_number;
}

bool is_valid_network(vector<char> network,int num_of_stages){
	int c;


	for(int k=0;k<num_of_stages;k++)
		for (int i=k;i<network.size();i+=num_of_stages)
		{
			c=0;
			if(network[i]!='-'){
				for(int j=k;j<network.size();j+=num_of_stages)
					if(network[i]==network[j])
						c++;
				if(c!=2)
					return false;
			}
		}
	for(int i=0;i<network.size();i++)
			if((network[i] <'a' || network[i]> 'z') && network[i] != '-')
				return false;
	return true;
}

vector<int> apply_stage(vector<char> network,int j,vector<int> numbers, int num_of_stages){
	int c=0,d=0;
	for(int i=j;i<network.size();i+=num_of_stages){
		if(network[i]!='-')
			for(int k=i + num_of_stages;k<network.size();k+=num_of_stages){
				c++;
				if(network[i]==network[k]&&network[k]!='-')
					if(numbers[d]>numbers[c]){
						int t;
						t=numbers[d];
						numbers[d]=numbers[c];
						numbers[c]=t;
					}
			}
		d++;
		c=d;
	}
	return numbers;
}


bool is_sorted(vector<int> numbers){
	for(int i=1;i<numbers.size();i++)
		if(numbers[i-1]>numbers[i])
			return false;
	return true;
}


void process_testcase (int num_of_inputs, int num_of_stages)
{
  vector<char> network = read_network(num_of_inputs, num_of_stages);
  vector<int> numbers = read_numbers(num_of_inputs);


  if (!is_valid_network(network, num_of_stages))
  {
    cout << "Invalid Network" << endl;
    return;
  }
  for (int j = 0; j < num_of_stages; j++)
    numbers=apply_stage(network, j, numbers,num_of_stages);
  if (is_sorted(numbers))
    cout << "Sorted" << endl;
  else
    cout << "Not Sorted" << endl;
}


int main ()
{
  int num_of_stages;
  int num_of_inputs;

  cin >> num_of_inputs >> num_of_stages;
  process_testcase(num_of_inputs, num_of_stages);
}
