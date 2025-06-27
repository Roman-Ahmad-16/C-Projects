#include <iostream>
using namespace std;
int main() {

           int arr[5]={10,20,30,40,50},search,start=0,mid,end=4,loc=-1;
           
           cout<<"ENTER ANY NUMBER TO FIND = ";
           cin>>search;
           
           while(start<=end){
           	     mid=(start+end)/2;
           	       if(arr[mid]==search){
           		     loc=mid;
           		         break;
           		 
			   }else if(search<arr[mid]){
			   	  end=mid-1;
			   	  
			   }else{
			   	 start=mid+1;
			   }			   
		   }
		   if(loc==-1){
			   	cout<<"not found"<<endl;
			   }else{
			   	cout<<"number found at the index = "<<loc<<endl;
			   }
			   
    return 0;
}

