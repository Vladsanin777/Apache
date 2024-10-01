#include <iostream>
#include <thread>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void apache(string url){
	while(true){
		system(("ab -t 600 -c 1000 -k "+url).c_str());
	}
	return;
}

int main(){
	string url;
	while(true){	
		cout<<"Input url for apache: ";
		cin>>url;
		thread t(apache, url);
		t.detach();
		cout<<endl<<"Start apache url: "<<url<<endl;
	}
	return 0;
}
