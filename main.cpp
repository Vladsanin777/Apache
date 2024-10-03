#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>

using namespace std;

void apache(string url){
	while(true){
		FILE* pipe = popen(("ab -t 1 -c 1000 -k "+url+" &>/dev/null").c_str(), "r");
		if (pipe) {
            pclose(pipe);
        } else {
            cerr << "Error opening pipe for URL: " << url << endl;
            break;        }
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
