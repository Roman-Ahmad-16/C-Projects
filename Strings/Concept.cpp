
	
      								String Declaration & Initialization

	
C-Style Strings ko do tareeqon se declare kiya ja sakta hai:

Method 1: Automatic Null Terminator

char name[] = "Hello"; // Null terminator '\0' automatically added



Method 2: Manual Character Array

char name[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Manually adding '\0'
Agar \0 na ho, to garbage values aa sakti hain.
	
	
	
	
	
	
																	Taking Input in C-Style Strings
C-Style Strings ka input lene ke do tareeqe hain:

Method 1: cin (Stops at Space)




    char name[20];
    cout << "Enter your name: ";
    cin >> name; // Takes input but stops at space
    cout << "Hello, " << name << "!" << endl;
    
    
Input:

Enter your name: Ali Ahmed



Output:

 Ali!
Issue: cin sirf Ali tak input lega, Ahmed ko ignore karega.
	
	
	
	
	
	
	
	
	
											Method 2: cin.getline() (Takes Full Line)


    char name[20];
    cout << "Enter your full name: ";
    cin.getline(name, 20); // Takes full input including spaces
    cout << "Hello, " << name << "!" << endl;


Input:

Enter your full name: Ali Ahmed


Output:

Ali Ahmed!
cin.getline(name, size); space ko bhi input mein include karta hai.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

