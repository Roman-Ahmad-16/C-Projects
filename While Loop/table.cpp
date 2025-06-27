#include"iostream"
using namespace std;
int main(){
	
	
	int a;
	cout<<"ENTER A NUMBER = ";
	cin>>a;
	
	int b;
	cout<<"ENTER A STARTING NUMBER = ";
	cin>>b;
	
	int c;
	cout<<"ENTER A ENDING NUMBER = ";
	cin>>c;
	
	
	while(b<=c){
		        cout<<a<<"X"<<b<<"="<<b*a<<endl;
		        b++;
	}
	
	

	return 0;
}
