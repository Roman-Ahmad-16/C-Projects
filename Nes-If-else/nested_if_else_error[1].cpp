#include <iostream>
using namespace std;
int main ()
{
	int a;
	int b;
	int c;
	cout<<"ENTER YOUR NUMBERS="<<endl;
	cin>>a>>b>>c;
	if (a>b){
		
		if (a>c){
			cout<<a<<"a is max number "<<endl;
		}else {
				cout<<c<<" is maxiumum"<<endl;
			}
}else{
  
			 	if (b>c)
				{
					cout<<b<<"is maxx"<<endl;
				}
		           else
					{
						cout<<c<<"is maxed up "<<endl;
					}
}
		return 0;
}
