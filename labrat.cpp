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

int main(){
	for(int z=0;z<6;z++){
	    system("cls");
	    art();
	    cout << endl;
             if(z==0||z==3){cout<<"\n\n\n\t  \t\t\t Resetting in progress ..";}
        else if(z==1||z==4){cout<<"\n\n\n\t  \t\t\t Resetting in progress ....";}
        else if(z==2||z==5){cout<<"\n\n\n\t  \t\t\t Resetting in progress ......";}
		Sleep(1000);
	}
	//sort(book.begin(), book.end());
	for(int i=0;i<5;i++){
    	
		cout<<  student[i].name			<<" ";
		cout<<  student[i].issue_limit	<<" ";
		cout<<  student[i].password		<<" ";
		cout<<  student[i].student_id	<<" ";
		cout<<	endl;
	}
	cout << "\t    student id\t"									<< setw(25 )<<"student name"<<"\t password\tissue limit" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < 5; i++){
		cout << "\t    " <<student[i].student_id <<"\t"<<setw(25) <<student[i].name<<"\t"	<<  student[i].password << "\t      " << student[i].issue_limit << endl;
	}
    
}