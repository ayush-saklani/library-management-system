#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;
class bookc{
	public:
	int book_id ;
	string name;
	string author;
	int price ;
	char status;
	int edition;
};
class studentc {
	public:
	char name[20];
	int student_id;
	string password;
	int issue_limit;
};
class adminc{
	public:
	char name[20];
	int admin_id;
	string password;
};
void art(){	
	ifstream ifs ("art.txt");    
	system("cls");
	while (ifs.good ()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	cout<<"date";
    ifs.close ();
}

	vector <bookc> book ; 
	bookc book_available[1000] ;
	bookc book_issued[1000] ;
	vector<studentc> student ;
	adminc admin[100] ;
string dateret(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "DATE: %d/%m/%Y TIME: %X", &tstruct);
    return buf ;
}
int main(){
	//char temp[20];
	//char temp2[20];
	//cin>>temp	;
	//cin>>temp2;
	//cout<<temp;
	//for(int i=0;i<20;i++){
	//	temp[i]=temp2[i];
	//}
	//cout<<temp;
	//cout<<"+++";
	//string date = dateret();
	//cout<< dateret();
	//	
	 
	//studentc temp;
	//for(int i=0;i<3;i++){
    //	
	//		//	cin >> temp.name;
	//			temp.issue_limit	= 5;
	//			temp.password		= "ayush";
	//			temp.student_id	= 21011325;
	//}
//
	//for(int i=0;i<3;i++){
    //	
	//	cout<<  temp.name			<<" ";
	//	cout<<  temp.issue_limit	<<" ";
	//	cout<<  temp.password		<<" ";
	//	cout<<  temp.student_id		<<" ";
	//	cout<<	endl;
	//}
	//for(int i=0;i<3;i++){
    //	
	//		//	cin >> temp.name;
	//			temp.issue_limit	= 5+789456;
	//			temp.password		= "ayush";
	//			
	//			temp.student_id	= 21011325+987654321;
	//}
//																											
	//for(int i=0;i<3;i++){															
    //											
	//	cout<<  temp.name			<<" ";				
	//	cout<<  temp.issue_limit	<<" ";			
	//	cout<<  temp.password		<<" ";				
	//	cout<<  temp.student_id		<<" ";				
	//	cout<<	endl;							
	//}											
	//system("COLOR 1F");						
	//cout<<"\n\n\n\t\t\t Hello World";			
	//   getch();
    system("COLOR F0");
	Sleep(500);
    HANDLE col;
    col =  GetStdHandle(STD_OUTPUT_HANDLE);
																		//	Color id	Color	Color id	Color				
																		//	0 	black	8	Gray	
																		//	1	Blue	9	Light Blue										
																		//	2	Green	A	Lig//			
																		//	3	Aqua	B	Light Aqua						
																		//	4	Red		C	Light Red										
																		//	5	Purple	D	Light Purple						
																		//	6	Yellow	E	Light Yellow				
																		//	7	White	F	Bright White								
																												
    for (int col_code = 1; col_code < 9; col_code++) {																				
			string str= "COLOR F"+col_code;											
        	system( "COLOR F1");//blue
			system( "COLOR F4");//red
		//	Sleep(500);																	
																	
        cout << col_code << "Welcome to CodeSpeedy!\n ";																	
    }
        	system( "COLOR F4");//red
		cout<<"hello";
	getch();
    return 0;

}
