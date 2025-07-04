#include<iostream>
using namespace std;
int main(){
	
//	Temperature Converter
    double temperature,convertedTemperature;
   
    cout << "Welcome to the Temperature Converter!" << endl;
    
    while(true){
    	   
    	    cout<<"1. Celsius to Fahrenheit"<<endl;
    	    
    	    
//        	cout<<"2. Fahrenheit to Celsius"<<endl;
        	
        	
    	    cout<<"3. Celsius to Kelvin"<<endl;
    	    cout<<"4. Kelvin to Celsius"<<endl;
    	    cout<<"5. Exit"<<endl;
    	    
    	    int choice;
    	    cout<<"Enter your choice: ";
    	    cin>>choice;
    	    
    	    if(choice==1){
    	    	cout<<"Enter temperature in Celsius  = ";
    	    	cin>>temperature;
    	    	convertedTemperature = (temperature * 9/5) + 32;
    	    	cout<<"Temperature in Celsius to Fahrenheit is ::"<<convertedTemperature<<endl;

			}else if(choice==2){
    	    	cout<<"Enter temperature in Fahrenheit = ";
    	    	cin>>temperature;
    	    	convertedTemperature=(temperature-32)*5/9;
    	    	cout<<"Temperature in Fahrenheit to Celsius is ::"<<convertedTemperature<<endl;
    	    	
    	    }else if(choice==3){
    	    	cout<<"Enter temperature in Celsius = ";
    	    	cin>>temperature;
    	    	convertedTemperature=temperature+273.15;
    	    	cout<<"Temperature in Celsius to Kelvin is ::"<<convertedTemperature<<endl;
    	    	
    	    	
    	    }else if(choice==4){
    	    	cout<<"Enter temperature in Kelvin = ";
    	    	cin>>temperature;
    	    	convertedTemperature=temperature-273.15;
    	    	cout<<"Temperature in Kelvin to Celsius is ::"<<convertedTemperature<<endl;


            }else if(choice==5){
    	    	cout<<"Program is End "<<endl;
    	    	break;
    	    	
    	    	
    	    }else {
    	    	cout<<"Enter Valid Temperature"<<endl;
			}
    
	
	
		    
	}
	
	return 0;
}
