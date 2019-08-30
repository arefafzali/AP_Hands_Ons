//hands on 14 main
int main(){
	Stack<int> s(10);
	Stack<string> a(20);
	s.push(4);
	s.push(400);
	a.push("ali");
	a.push("mamad");
	int sum=0;
	Stack<int>::Iterator it = s.get_iterator();
	while(it.has_more_elements()){
		sum += it.next_element();
	}
	cout <<sum<<endl;
	return 0;
}