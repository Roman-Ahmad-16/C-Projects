#include <iostream>
using namespace std;

	const int months=12;
	
void get_data(int temp[][2]){
	for(int i=0; i<months; i++){
		cout<<"ENTER HIGH TEMPERATURE FOR MONTH :: "<<i+1<<" : ";
			cin>>temp[i][0];
		cout<<"ENTER LOW  TEMPERATURE FOR MONTH :: "<<i+1<<" : ";
			cin>>temp[i][1];
	}
}

float avg_high(int temp[][2]){
	int sum=0;
	for(int i=0; i<months; i++){
		sum+=temp[i][0];
	}
		return 1.0*sum/months;
}

float avg_low(int temp[][2]){
	int sum=0;
	for(int i=0; i<months; i++){
		sum+=temp[i][1];
	}
	return 1.0*sum/months;
}

int high_index(int temp[][2]){
	int maxx_index=0;
	for(int i=1; i<months; i++){
		if(temp[i][0]>temp[maxx_index][0]){
			maxx_index=i;
		}
	}
	return maxx_index;
}

int low_index(int temp[][2]){
	int loww_index=0;
	for(int i=1; i<months; i++){
		if(temp[i][1]<temp[loww_index][1]){
			loww_index=i;
		}
	}
	return loww_index;
}

int main(){
	
	int temp[months][2];
	
	get_data(temp);
	
	cout << "\nAverage High Temperature: " << avg_high(temp) << endl;
    cout << "Average Low Temperature: " << avg_low(temp) << endl;
    
    
int highTempIndex = high_index(temp);
int lowTempIndex = low_index(temp);  



cout << "Month with Highest High Temperature: Month " << (highTempIndex + 1)
     << " (" << temp[highTempIndex][0] << "°C)" << endl;

cout << "Month with Lowest Low Temperature: Month " << (lowTempIndex + 1)
     << " (" << temp[lowTempIndex][1] << "°C)" << endl;

	return 0;
}
