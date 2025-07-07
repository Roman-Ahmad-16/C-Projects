//Create a Movie struct with movie name, release year, and rating.
// Write a constructor and a function to check if the movie rating is above 8 and print "Highly Rated".

#include<iostream>
using namespace std; 
struct Movie
{
	string name;
	int release_year;
	float rating;
	
		Movie(string a , int b , float c)
		{
			name=a;
			release_year=b;
			rating=c;
		}
		
	Rating_Check()
	{
		cout<<"MOVIE NAME : "<<name<<endl;
		cout<<"RELEASING YEAR : "<<release_year<<endl;
		cout<<"RATING : "<<rating<<endl;
		
		if(rating>=8.0){
			cout<<"HIGHLY RATED MOVIE"<<endl;
		}else{
			cout<<"NOT HIGHLY RATED"<<endl;
		}
	}
};

int main(){
	
	Movie m("SARDAAR JI" , 2025 , 8.0);
	Movie m1("LOVE GURU", 2025 , 7.9);
	
	cout << "\n--- Movie 1 ---\n";
	m.Rating_Check();
	
	cout << "\n--- Movie 2 ---\n";
	m1.Rating_Check();
	
	return 0;
}
