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
//	I have defined all the funtion at the top because some functions call each other at the time of execution - ayush saklani ;)	//
void fullscreen();								//	It makes the terminal full screen for better expeirence 	(design & aesthetic function)
void Date();									//	It display the date and time 								(design & aesthetic function)
string dateret();								//	It returns date and time in string format					(design & aesthetic function)
void welcome_art();								//	It display welcome when you open the program				(design & aesthetic function)
void exit_art();								//	It displays the thankyou art when you exit the portal 		(design & aesthetic function)
void art();										//	It displays the company name art at the top of the page 	(design & aesthetic function)
void loading_screen();							//	It diplays the loading screen								(design & aesthetic function)

void menu();									//	It opens the menu page 										(main control landing page)
//
void student_corner();							//	It open the page for students to login and register 		(menu control)
void student_login();							//	It open the page for registered student to login				(student protective control)
void students_portal(int studentid,int i);		//	It open the student portal											(student menu)
void book_issue(int studentid,int i);			//	It helps the students to issue any available book						(student exclusive control)
void book_return(int studentid,int i);			//	It helps the students to return any available book						(student exclusive control)
void show_student_issued_book(int studentid);	//	It display all the books issued by a particular student					(student exclusive control)
void changepassword(int studentd,int i);		//	It changes password of the logged in student							(student exclusive control)
void add_new_student ();						//	It open the page for new students to register 					(student protective control)
//
void admin_login();								//	It open the page for admins to login 						(menu control || admin protective control)	
void admins_portal(int adminid,int i);			//	It open admin portal												(admin menu)
void add_new_admin(int admindid);				//	It adds new admins to the system										(admin exclusive control || admin protective control) 		
void show_all_book();							//	It display all the books in the system									(admin exclusive control)		
void add_book(int adminid,int i);				//	It adds new books to the database										(admin exclusive control) 			
void delete_book(int adminid,int j);			//	It deletes new books to the database									(admin exclusive control) 			
void show_available_book();						//	It display all the available books available for issuing				(admin exclusive control)				
void show_issued_book();						//	It display all the books currently issued to students					(admin exclusive control)		
void show_all_student();						//	It display all the students registered to portal						(admin exclusive control)		
void reset_book(int adminid,int i);				//	It resets all the availability of all books								(admin exclusive control)		
void readlogs();								//	It display log history to the admin										(admin exclusive control)											
//
void rules_and_regulations();					//	It diplays the rules on how to handle college property		(menu control) 			
//														
int book_count();								//	It count the total no of books saved in the system 			(work assistive function)				
int issued_book_count();						//	It count the total no of books issued from the system 		(work assistive function)				
int student_count();							//	It count the total no of student registered in portal 		(work assistive function)				
int admin_count();								//	It count the total no of admin controlling the system  		(work assistive function)				
//
void read_students_details();					//	It reads and stores data from database to local variable	(essential database function)
void read_allbook ();							//	It reads and stores data from database to local variable	(essential database function)
void read_admins();								//	It reads and stores data from database to local variable	(essential database function)
void save_database();							//	It reads and stores data from local variables to database 	(essential database function)

class bookc{
	public:
	int book_id ;
	string name;
	int price ;
	char status;	// 'I' for issued and 'A' for available
	int owner;      // '1111111' is library code for owner
	int edition;
};
class studentc {
	public:
	string name;
	int student_id;
	char password[20];
	int issue_limit;
};
class adminc{
	public:
	string name;
	int admin_id;
	char password[20];
};
	vector <bookc>		book ;
	vector <adminc>		admin ;
	vector <studentc>	student ;
	vector <bookc>		book_issued ;

void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void Date(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "\n\t  \t\t\t\t\t\tDATE: %d/%m/%Y TIME: %X", &tstruct);
    cout<< buf<<endl;
}
string dateret(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "DATE: %d/%m/%Y TIME: %X", &tstruct);
    return buf ;
}
void welcome_art(){
	ifstream ifs ("welcome.txt");    
	system("cls");
	while (ifs.good()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	cout<<"\n\t  \t\t\t\t\t\t\t";
	ifs.close ();
	Sleep(3000);
}
void exit_art(){
	ifstream ifs ("exit art.txt");    
	system("cls");
	while (ifs.good ()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
    cout<<"\n\t  \t\t\t\t\t\t\t";
    ifs.close ();
    Sleep(3000);
    exit(0);
}
void art(){	
	ifstream ifs ("art.txt");    
	system("cls");
	while (ifs.good ()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	Date();
    ifs.close ();
}
void loading_screen(){
	for(int i=0;i<101;i++){
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n       \t\t\t\t\t\t\t\t\t loading ........"<<i<<"%";
        Sleep(40);
    }
        Sleep(1000);
    //cout<<"\n\t\t\t\t\t\tpress any key to continue........"<<endl;
    //cout<<"\t\t\t\t\t";
    //getch();	
}

void menu(){ 
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. Student Portal";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. Admin Portal";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. Terms and conditions";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. Exit"<<endl<<"\n";
	cout<<"\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		student_corner();
	}
	else if(x==2){
		admin_login();
	}
	else if(x==3){
		rules_and_regulations();
		getch();
	}
	else if(x==4){
		cout << "\n\n\n\n";
        save_database();
		exit_art();
		Sleep(1000);
		exit(0);
	}
	else if(x==5){	//easter egg (; <3
	string timee=	"\n\n\n\n\n\n\n\t  \t\t\t\t\t\t    ______ ____ __  ___ ______\n\t  \t\t\t\t\t\t   /_  __//  _//  |/  // ____/\n\t  \t\t\t\t\t\t    / /   / / / /|_/ // __/\n\t  \t\t\t\t\t\t   / /  _/ / / /  / // /___\n\t \t\t\t\t\t\t  /_/  /___//_/  /_//_____/\n\t  \t\t\t\t\t\t     ";
	for(int z=0;z<=5;z++){
		system("cls");
		cout<<timee;
		Date();
		Sleep(1000);
	}
		system("cls");
		menu();
	}
	else{
		system("COLOR F4");//red
		system("cls");
		art();
		cout<<"\n\n\n\n";
		cout<<"\n\t  \t\t\t\t\t\t\t  Invalid Choice.......";
		cout<<"\n\t  \t\t\t\t\t\t\t  Try Again.....";
		Sleep(1000);
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
		menu();
	}
	
}

void student_corner(){
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. Student Login";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. Register";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. Go to Main Menu"<<endl;
	cout<<"\n\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		student_login();
	}	
	else if (x==2){
		add_new_student();
	}	
	else if (x==3){
		menu();
	}	
}
void student_login(){ 
	cout<<"\n\n\n";
	art();
	cout << endl;
	int studentid;
	cout << "\n\t  \t\t\t\tPlease enter student id : ";
	cin >> studentid;
	int coutoo=0;
	char temppassword[20];
	for (int i = 0 ; i < student_count() ; ++i){
		if (studentid == student[i].student_id){
			cout << "\n\t  \t\t\t\tPlease enter password : ";
			cin>>temppassword;
			//cout<<student[i].student_id<<"+"<<student[i].password<<"+"<<temppassword<<"+"<<endl;
				if(strcmp(temppassword, student[i].password) == 0){
					
					system("COLOR F1");//blue
					coutoo++;
					system("cls");
					art();
					cout << endl;
					cout<<"\n\t  \t\t\tWELCOME ";
					cout << student[i].name;
					cout<<"\t  \tStudent ID : ";
					cout << student[i].student_id<<endl;
					cout<<"\n\t  \t\t\tRedirecting to student's portal.."<<endl<<endl;
    				cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
    				cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    				cout<<"\t  \t\t\t";
						ofstream log;
						log.open("logfile.txt",ios::app);
						log<<dateret()<<"\t"<<student[i].name<<" logged in to the system 	Student ID : "<<student[i].student_id<<endl;
						log.close();
    				getch();
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
    				students_portal(student[i].student_id,i);
				}
				else{					
					system("COLOR F4");//red
					cout<<"\t  \t\t\tWrong Password.."<<endl<<endl;
					cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    				cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
    				cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    				cout<<"\t  \t\t\t";
    				getch();
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
    				student_corner();
				}
		}
	}
	if(coutoo==0){
			system("COLOR F4");//red
			cout<<endl;
    		cout<<"\t  \t\t\tUser not found ......"<<endl;
			Sleep(500);
    		cout<<"\t  \t\t\tReturning to student's corner.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
			system("COLOR F0");//black
			Sleep(500);
    		student_corner();
	}
}
void students_portal(int studentid,int i){
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. Issue Book";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. Return Book";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. List of issued books";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. Change Password";
	cout<<"\n\t  \t\t\t\t\t\t\t  5. Log Out"<<endl<<"\n";
	cout<<"\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		book_issue(studentid,i);
	}
	else if(x==2){
		book_return(studentid,i);
	}
	else if(x==3){
		cout<<"working";
		show_student_issued_book(studentid);
        cout<<"\n\n\n\n\t  \t\t\tReturning to student's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        students_portal(studentid,i);
	}
	else if(x==4){
		changepassword(studentid,i);
	}
	else if(x==5){
		ofstream log;
		log.open("logfile.txt",ios::app);
		log<<dateret()<<"\t"<<student[i].name<<" logged out from the system 	"<<"student ID : "<<studentid;
		log<<endl<<"=========================================================================================================================================================================="<<endl;
		log.close();

		menu();
	}
	else{
		system("COLOR F4");//red
		system("cls");
		art();
		cout<<"\n\n\n\n";
		cout<<"\n\t  \t\t\t\t\t\t\t  Invalid Choice.......";
		cout<<"\n\t  \t\t\t\t\t\t\t  Try Again.....";
		Sleep(1000);
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
		students_portal(studentid,i);
	}
}
void book_issue(int studentid,int i){
	system("cls");
	art();
	if(student[i].issue_limit>0){
		show_available_book();
		int x;
		cout << endl;
		cout<<"\n\t  \t\t\t\t\t\t\t  Enter book ID to issue the book :";
		cin>>x;
		int present=0;
		for (int j = 0; j < book.size(); j++){
			if(book[j].book_id==x){
				if(book[i].status=='A'){
					student[i].issue_limit--;
					book[j].owner=studentid;
					book[j].status='I';
					present++;
					system("COLOR F1");//blue
					cout<<"\n\n\n\t  \t\t\t\t\t\t\t  Book issued to "<<student[i].name<<" current limit for issuing book is "<<student[i].issue_limit<<endl;
					Sleep(500);
	    			cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
	    			cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
	    			cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
	    			cout<<"\t  \t\t\t";
						ofstream log;
						log.open("logfile.txt",ios::app);
						log<<dateret()<<"\t"<<book[j].name<<" issued by the user\tbook ID : "<<book[j].book_id <<endl;
						log.close();
					
	    			getch();
					//system("COLOR F5");
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
					save_database();
	    			students_portal(studentid,i);
				}
				else{
					system("COLOR F4");//red
					cout<<"\nYou are trying to issue a book not currently issued to someone else";
					Sleep(500);
    				cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    				cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
    				cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    				cout<<"\t  \t\t\t";
    				getch();
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
    				students_portal(studentid,i);
				}
			}
		}
		if(present==0){
			system("COLOR F4");//red
			cout<<"\n\n\t  \t\t\tBook not found in library!";
			Sleep(500);
			cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
			cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
			cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
			cout<<"\t  \t\t\t";
			getch();
			system("cls");
			system("COLOR F0");//black
			Sleep(500);
			students_portal(studentid,i);
		}
	}
	else{
		system("COLOR F4");//red
		cout<<"Sorry! You have reached your limit of issued books.";
		Sleep(500);
    	cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    	cout<<"\t  \t\t\t"<<endl;
		Sleep(1000);
    	cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    	cout<<"\t  \t\t\t";
    	getch();
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
    	students_portal(studentid,i);	
	}
}
void book_return(int studentid,int i){
	system("cls");
	art();
	if(student[i].issue_limit>=0){
		show_student_issued_book(studentid);
		int x;
		cout << endl;
		cout<<"\n\t  \t\t\t\t\t\t\t  Enter book ID to Return the book :";
		cin>>x;
		int present=0;
		for (int j = 0; j < book.size(); j++){
			if(book[j].book_id==x){
				if(book[j].owner==studentid){
					system("COLOR F1");//blue
					student[i].issue_limit++;
					book[j].owner= 1111111;
					book[j].status='A';
					present++;
					cout<<"\n\n\n\t  \t\t\t\t\t\t\t  Book Returned Successfully "<<" current limit for issuing book is "<<student[i].issue_limit<<endl;
					Sleep(500);
    				cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    				cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
    				cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    				cout<<"\t  \t\t\t";

						ofstream log;
						log.open("logfile.txt",ios::app);
						log<<dateret()<<"\t"<<book[j].name<<" returned by the user\t\tbook ID : "<<book[j].book_id <<endl;
						log.close();
    				getch();
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
					save_database();
    				students_portal(studentid,i);
				}
				else{
					system("COLOR F4");//red
					cout<<"\nYou are trying to return a book not issued to you";
					Sleep(500);
    				cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    				cout<<"\t  \t\t\t"<<endl;
					Sleep(1000);
    				cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    				cout<<"\t  \t\t\t";
    				getch();
					system("cls");
					system("COLOR F0");//black
					Sleep(500);
    				students_portal(studentid,i);
				}
			}
		}
		if(present==0){
			system("COLOR F4");//red
			cout<<"\n\n\t  \t\t\tBook not found in your issued book list";
			Sleep(500);
			cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
			cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
			cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
			cout<<"\t  \t\t\t";
			getch();
			system("cls");
			system("COLOR F0");//black
			Sleep(500);
			students_portal(studentid,i);
		}
	}
	else{
		system("COLOR F4");//red
		cout<<"Sorry! You dont have any book issued.";
		Sleep(500);
    	cout<<"\t  \t\t\tReturning to student's portal.."<<endl<<endl;
    	cout<<"\t  \t\t\t"<<endl;
		Sleep(1000);
    	cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    	cout<<"\t  \t\t\t";
    	getch();
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
    	students_portal(studentid,i);	
	}
}
void show_student_issued_book(int studentid){
	system("cls");
	art();
	cout<<endl;
	cout << "\t    book id\t"									<< setw(15 )<<"name"<<"\t\t\tprice\tcurrently issued to\tstatus\tedition" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < book.size(); i++){
		if(book[i].owner==studentid){
			cout << "\t    " << book[i].book_id <<"\t"<<setw(25) <<book[i].name<<"\t"	<<  book[i].price << "\t      " << book[i].owner << "\t\t   " << book[i].status << "\t "<< book[i].edition << endl;
		}
	}
}
void changepassword(int studentid,int i){
	system("cls");
	art();
	cout<<endl;
	char temppass[20];
	char temppass2[20],temppass3[20];
	cout<<"\n\t  \t\t\t\t\tWELCOME ";
	cout<<"\n\t\t  \tStudent name : ";
	cout<< student[i].name;
	cout<<"\n\t\t  \tStudent ID : ";
	cout<< student[i].student_id;
	cout<<"\n\n\t\t	 \tEnter old Password :";
	cin >> temppass;
	//cout<<temppass<<" "<<student[i].password;
	if(strcmp(temppass, student[i].password) == 0){
		retry:
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
		art();
		cout<<endl;
		cout<<"\n\n\n\t  \t\t\tOld password was correct!"<<endl;
		cout<<"\t  \t\t\tEnter  new  password : ";
		cin>>temppass2;
		//cin.ignore();
		cout<<"\t  \t\t\tConfirm new password : ";
		cin>>temppass3;
		if(strcmp(temppass3, temppass2) == 0){
			for(int t=0;t<20;t++){
				student[i].password[t]=temppass2[t];
			}
			system("COLOR F1");//blue
			cout<<"\n\t\t\t\t  \t\t\tPassword changed successfully "<<endl;
			cout<<"\t  \t\t\tRedirecting to student's portal.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
				ofstream log;
				log.open("logfile.txt",ios::app);
				log<<dateret()<<"\t"<<student[i].name<<" Password change successfully!!   	Student ID : "<<student[i].student_id<<endl;
				log.close();
    		getch();
			system("cls");
			system("COLOR F0");//black
			Sleep(500);
			save_database();
    		students_portal(studentid,i);	
		}
		else{
			system("COLOR F4");//red
			cout<<"\n\t\t\t\t  \t\t\tPassword does not Match "<<endl;
			cout<<"\t  \t\t\tEnter Password again.... "<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";	
			getch();
			system("COLOR F0");//black
			Sleep(500);
			goto retry;
		}
	}
	else{
		system("COLOR F4");//red
		cout<<"\n\n\n\t\t\t\t  \t\t\tPassword does not Match "<<endl;
		cout<<"\t  \t\t\tRedirecting to student's portal.."<<endl<<endl;
    	cout<<"\t  \t\t\t"<<endl;
		Sleep(1000);
    	cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    	cout<<"\t  \t\t\t";
			ofstream log;
			log.open("logfile.txt",ios::app);
			log<<dateret()<<"\t"<<student[i].name<<" Password change attempt failed!! 	Student ID : "<<student[i].student_id<<endl;
			log.close();
    	getch();
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
		save_database();
    	students_portal(studentid,i);	
	}
}
void add_new_student (){
	cout<<"\n\n\n";
	art();
	cout << endl;

	studentc temp;
	cout << "\n\t  \t\t\t\tPlease enter student id : ";
	cin >> temp.student_id;
	cin.ignore();
	cout << "\n\t  \t\t\t\tPlease enter name : ";
	getline(cin, temp.name); 
	cout << "\n\t  \t\t\t\tPlease enter password : ";
	cin >> temp.password;
	temp.issue_limit=5;
	student.push_back(temp);
	
	system("cls");
	cout<<"\n\n\n";
	art();
	cout << endl;
	int i=student.size();
	system("COLOR F1");//blue
	cout<<"\t  \t\t\tUser added successfull ......................."<<endl;
	cout<<"\n\t  \t\t\t\t\tWELCOME ";
	cout << student[i-1].name;
	cout<<"\t  \tStudent ID : ";
	cout << student[i-1].student_id;
					ofstream log;
					log.open("logfile.txt",ios::app);
					log<<dateret()<<"\t"<<student[i-1].name<<" Registered to the system with student ID :"<<student[i-1].student_id;
					log<<endl<<"=========================================================================================================================================================================="<<endl;
					log.close();
	cout<<"\t  \t\t\tReturning to student portal to continue ......"<<endl<<endl<<endl;
    cout<<"\t  \t\t\t"<<endl;
	save_database();
	Sleep(1000);
    cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    cout<<"\t  \t\t\t";
    getch();
	system("COLOR F0");//black
	Sleep(500);
	system("cls");
    student_corner();	
}
void admin_login(){
	
}
void admin_login(){
	system("cls");
	art();
	cout << endl;
	string password;
	int adminid;
	int coutoo=0;
	cout << "\n\t  \t\t\t\tPlease enter Admin id : ";
	cin >> adminid;
	char c;
	for (int i = 0 ; i < admin_count() ; i++){
		if (adminid == admin[i].admin_id){
			cout << "\n\t  \t\t\t\tPlease enter password : ";
			while(c != '\r'){ 
    		    	c = getch();
    		    	if(c == '\b'){  
    		    	    if(password.size() != 0){  
    		    	       cout << "\b \b";
    		    	       password.erase(password.size() - 1, 1);
    		    	    }
    		    	    continue;
    		    	}
    		    	else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
    		    	    password += c;
    		    	    cout << "*";
    		    	}
    		    	else{
    		    	    continue;
					}
    		    }
			if(password==admin[i].password){
				system("COLOR F1");//blue
				coutoo++;
                system("cls");
	            art();
	            cout << endl;
				cout<<"\n\t  \t\t\t\t\tWELCOME ";
				cout << admin[i].name;
				cout<<"\t  \tAdmin ID : ";
				cout << admin[i].admin_id<<endl;
				cout<<"\n\t  \t\t\tRedirecting to admin's portal.."<<endl<<endl;
    			cout<<"\t  \t\t\t"<<endl;
				Sleep(1000);
						
    			cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    			cout<<"\t  \t\t\t";
						fflush(stdin);
						ofstream log;
						log.open("logfile.txt",ios::app);
						log<<dateret()<<"\t"<<admin[i].name<<" logged in to the system    Admin  ID  : "<<admin[i].admin_id<<endl;
						log.close();
				getch();
				system("cls");
				system("COLOR F0");//black
				Sleep(500);
    			admins_portal(admin[i].admin_id,i);
			}
			else{
				system("COLOR F4");//red
				cout<<"\t  \t\t\tWrong Password.."<<endl<<endl;
				cout<<"\t  \t\t\tReturning to Main Menu.."<<endl<<endl;
    			cout<<"\t  \t\t\t"<<endl;
				Sleep(1000);
    			cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    			cout<<"\t  \t\t\t";
    			getch();
				system("cls");
				system("COLOR F0");//black
				Sleep(500);
    			menu();
			}
		}
	}
	if(coutoo==0){
			system("COLOR F4");//red
			cout<<endl;
    		cout<<"\t  \t\t\tAdmin ID not found ......"<<endl;
			Sleep(500);
    		cout<<"\t  \t\t\tReturning to Main Menu.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
			system("COLOR F0");//black
			Sleep(500);
    		menu();
	}
}
void admins_portal(int adminid,int i){
    system("cls");
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. Add new Admin";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. Show All books (issued out and Available )";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. Add new book";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. Delete a book";
	cout<<"\n\t  \t\t\t\t\t\t\t  5. Show available books  ";
	cout<<"\n\t  \t\t\t\t\t\t\t  6. Show issued books  ";
	cout<<"\n\t  \t\t\t\t\t\t\t  7. show all students";
	cout<<"\n\t  \t\t\t\t\t\t\t  8. Reset book availability";
	cout<<"\n\t  \t\t\t\t\t\t\t  9. Read System Logs";
	cout<<"\n\t  \t\t\t\t\t\t\t 10. Log out"<<endl<<"\n";
	cout<<"\n\t  \t\t\t\t\t\t\tInput ::";
	cin>>x;
	system("cls");
	if (x==1)	  {	add_new_admin(adminid);		}	
	else if (x==2){
		show_all_book();
		cout<<"\n\n\n\n\t  \t\t\tReturning to admin's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        admins_portal(adminid,i);
	}
	else if (x==3){	add_book(adminid,i);				}
	else if (x==4){	delete_book(adminid,i);			}
	else if (x==5){
		show_available_book();
		cout<<"\n\n\n\n\t  \t\t\tReturning to admin's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        admins_portal(adminid,i);
	}
	else if (x==6){
		show_issued_book();
		cout<<"\n\n\n\n\t  \t\t\tReturning to admin's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        admins_portal(adminid,i);
	}
	else if (x==7){
		show_all_student();
		cout<<"\n\n\n\n\t  \t\t\tReturning to admin's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        admins_portal(adminid,i);
	}
	else if (x==8){	reset_book(adminid,i);			}
	else if (x==9){
        system("cls");
			ofstream log;
			log.open("logfile.txt",ios::app);
			log<<dateret()<<"\t"<<admin[i].name<<" accessed log history \t\t Admin ID : "<<admin[i].admin_id <<endl;
			log.close();
		readlogs();
		cout<<"\n\n\n\n\t  \t\t\tReturning to admin's portal.."<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
        Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
        system("cls");
        admins_portal(adminid,i);
	}
	else if (x==10){
		save_database();
		ofstream log;
		log.open("logfile.txt",ios::app);
		log<<dateret()<<"\t"<<admin[i].name<<" logged out from the system 	"<<"Admin ID : "<<adminid; ;
		log<<endl<<"=========================================================================================================================================================================="<<endl;
		log.close();
		menu();
		}
	else{
		system("COLOR F4");//red
		system("cls");
		art();
		cout<<"\n\n\n\n";
		cout<<"\n\t  \t\t\t\t\t\t\t  Invalid Choice.......";
		cout<<"\n\t  \t\t\t\t\t\t\t  Try Again.....";
		Sleep(1000);
		system("cls");
		system("COLOR F0");//black
		Sleep(500);
		admins_portal(adminid,i);
	}
}
void add_new_admin(int adminid){
	art();
	cout << endl;

	adminc temp;
	cout << "\n\t  \t\t\t\tPlease enter Admin id : ";
	cin >> temp.admin_id;
    cin.ignore();
	cout << "\n\t  \t\t\t\tPlease enter Name : ";
	getline(cin, temp.name); 
	cout << "\n\t  \t\t\t\tPlease enter Password : ";
	std::cin >> temp.password;
	admin.push_back(temp);
	
	system("cls");
	cout<<"\n\n\n";
	art();
	system("COLOR F1");//blue
	
	cout << endl;
	int i=admin.size();
	cout<<"\t  \t\t\tAdmin added successfull ......................."<<endl;
	cout<<"\n\t  \t\t\t\t\tWELCOME ";
	cout << admin[i-1].name;
	cout<<"\t  \tAdmin ID : ";
	cout << admin[i-1].admin_id;
	Sleep(1000);
					ofstream log;
					log.open("logfile.txt",ios::app);
					log<<dateret()<<"\t\t\t"<<" New Admin Registered to the system :"<<endl;
					log<<dateret()<<"\t"<<"New Admin name : "<< admin[i-1].name <<" New Admin ID :"<<admin[i-1].admin_id <<endl;
					log<<dateret()<<"\t"<<"Admin Added by Admin id :"<<adminid <<endl;
					log<<dateret()<<"\t"<<adminid<<" logged out from the system for security purposes " ;
					log<<endl<<"=========================================================================================================================================================================="<<endl;
					log.close();

    save_database();
	cout<<"\t  \t\t\tReturning to Main Menu for security purposes .."<<endl<<endl;
    cout<<"\t  \t\t\t"<<endl;
	Sleep(1000);
    cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    cout<<"\t  \t\t\t";
    getch();
	system("COLOR F0");//black
	Sleep(500);
	system("cls");
    menu();	
}
void show_all_book(){
	system("cls");
	art();
	cout<<endl;
	cout << "\t    book id\t"									<< setw(15 )<<"name"<<"\t\t\tprice\tcurrently issued to\tstatus\tedition" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < book.size(); i++){
		cout << "\t    " << book[i].book_id <<"\t"<<setw(25) <<book[i].name<<"\t"	<<  book[i].price << "\t      " << book[i].owner << "\t\t   " << book[i].status << "\t "<< book[i].edition << endl;
	}
}		
void add_book(int adminid,int i){
    cout<<"\n\n\n";
	art();
	cout << endl;

	bookc temp;
	cout << "\n\t  \t\t\t\tPlease enter new book id : ";
	cin >> temp.book_id;
	cin.ignore();
	cout << "\n\t  \t\t\t\tPlease enter new book name : ";
	getline(cin, temp.name); 
	cout << "\n\t  \t\t\t\tPlease enter new book price: ";
	cin >> temp.price;
	cout << "\n\t  \t\t\t\tPlease enter new book edition: ";
	cin >> temp.edition;
	temp.status = 'A';
	temp.owner=1111111;
	book.push_back(temp);
	
	system("cls");
	cout<<"\n\n\n";
	art();
	cout << endl;
					system("COLOR F1");//blue
	
	cout<<"\t  \t\t\tbook added successfull ......................."<<endl;
	cout<<"\t  \t\t\tReturning to admin portal to continue ......"<<endl<<endl<<endl;
    cout<<"\t  \t\t\t"<<endl;
	Sleep(1000);
					ofstream log;
					int j= book.size();
					log.open("logfile.txt",ios::app);
					log<<dateret()<<"\t"<<book[j-1].name<<" Book Registered to the system from Admin ID :"<<adminid<<"Book ID :"<<temp.book_id<<endl;
					log.close();
    cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    cout<<"\t  \t\t\t";
    getch();
	system("cls");
					system("COLOR F0");//black
					Sleep(500);
    save_database();
    admins_portal(adminid,i);	
}				
void delete_book(int adminid,int j){
    cout<<"\n\n\n";
	art();
	cout << endl;

	int x;
    bookc temp;
    show_all_book();
	cout << "\n\t  \t\t\t\tPlease enter book id to delete : ";
	cout << "\n\t  \t\t\t\t";
	cin>>x;
	int check=0, tempsto1;
    string tempsto;
	for (int i = 0; i < book.size(); i++){
		if(book[i].book_id==x){
			tempsto=book[i].name;
			tempsto1=book[i].book_id;
            check++;
			for(int j= i;j<book.size()-1;j++){
                book[j]=book[j+1];
            }
            book.pop_back();
            break;
		}
	}
    save_database();
    if(check>0){
	    system("cls");
	    cout<<"\n\n\n";
	    art();
					system("COLOR F1");//blue
	    cout << endl;
	    cout<<"\t  \t\t\tbook ("<<x<<") deleted successfully ......................."<<endl;
	    cout<<"\t  \t\t\tReturning to admin portal to continue ......"<<endl<<endl<<endl;
        cout<<"\t  \t\t\t"<<endl;
					ofstream log;
					int i= book.size();
					log.open("logfile.txt",ios::app);
					log<<dateret()<<"\t"<<tempsto<<" Book deleted from the system from Admin ID :"<<adminid<<"Book ID :"<<tempsto1<<endl;
					log.close();
	    Sleep(1000);
        cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
        cout<<"\t  \t\t\t";
        getch();
	    system("cls");
					system("COLOR F0");//black
					Sleep(500);
		save_database();
        admins_portal(adminid,j);	
    }
    else if(check==0){
					system("COLOR F4");//red
        cout<<"\n\n\t  \t\t\tBook ("<<x<<") not found ";
		Sleep(500);
	    cout<<"\t  \t\t\tReturning to admin portal to continue ......"<<endl<<endl<<endl;
		cout<<"\t  \t\t\t"<<endl;
		Sleep(1000);
		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
		cout<<"\t  \t\t\t";
		getch();
		system("cls");
					system("COLOR F0");//black
					Sleep(500);
		admins_portal(adminid,j);
    }
}			
void show_available_book(){
	//system("cls");
	//art();
	cout<<endl;
	cout << "\t    book id\t"									<< setw(15 )<<"name"<<"\t\t\tprice\tcurrently issued to\tstatus\tedition" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < book.size(); i++){
		if(book[i].status=='A'){
			cout << "\t    " << book[i].book_id <<"\t"<<setw(25) <<book[i].name<<"\t"	<<  book[i].price << "\t      " << book[i].owner << "\t\t   " << book[i].status << "\t "<< book[i].edition << endl;
		}
	}
}	
void show_issued_book(){
	system("cls");
	art();
	cout<<endl;
	cout << "\t    book id\t"									<< setw(15 )<<"name"<<"\t\t\tprice\tcurrently issued to\tstatus\tedition" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < book.size(); i++){
		if(book[i].status=='I'){
			cout << "\t    " << book[i].book_id <<"\t"<<setw(25) <<book[i].name<<"\t"	<<  book[i].price << "\t      " << book[i].owner << "\t\t   " << book[i].status << "\t "<< book[i].edition << endl;
		}
	}
}		
void show_all_student(){
	system("cls");
	art();
	cout<<endl;
	cout << "\t    student id\t"									<< setw(25 )<<"student name"<<"\t password\tissue limit" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < student.size(); i++){
		cout << "\t    " <<student[i].student_id <<"\t"<<setw(25) <<student[i].name<<"\t"	<<  student[i].password << "\t      " << student[i].issue_limit << endl;
	}
}		
void reset_book(int adminid,int i){
	for(int z=0;z<6;z++){
	    system("cls");
	    art();
	    cout << endl;
             if(z==0||z==3){cout<<"\n\n\n\t  \t\t\t Resetting in progress ..";}
        else if(z==1||z==4){cout<<"\n\n\n\t  \t\t\t Resetting in progress .....";}
        else if(z==2||z==5){cout<<"\n\n\n\t  \t\t\t Resetting in progress ........";}
		Sleep(1000);
	}
    system("cls");
	art();
	cout << endl;

	for (int k = 0; k < book.size(); k++){
		book[k].status='A';
		book[k].owner=1111111;
	}
    for (int j = 0; j < student.size(); j++){
		student[j].issue_limit=5;
	}
					system("COLOR F1");//blue
	cout<<"\t  \t\t\tBooks resetted successfully ......................."<<endl;
	cout<<"\t  \t\t\tReturning to admin's portal to continue ......"<<endl<<endl<<endl;
    cout<<"\t  \t\t\t"<<endl;
	Sleep(1000);
					ofstream log;
					log.open("logfile.txt",ios::app);
					log<<dateret()<<"\t"<<admin[i].name <<" Performed book availability reset "<<endl;
					log<<dateret()<<"\tBook resetted with Admin ID :"<<adminid<<endl;
					log.close();
    cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    cout<<"\t  \t\t\t";
    getch();
	system("cls");
					system("COLOR F0");//black
					Sleep(500);
	save_database();
    admins_portal(adminid,i);	
}			
void readlogs(){
	system("cls");
	ifstream ifs ("logfile.txt");    
	while (ifs.good()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	cout<<"\n\t  \t\t\t\t\t\t\t";
	ifs.close ();
	Sleep(3000);
}

void rules_and_regulations(){
	art();
	cout<<endl;
	cout<<"\n\t  \t\t\t1. SRUDENTS MUST REGISTER THEMSELF BEFORE USING THE PORTAL.";
	cout<<"\n\t  \t\t\t2. LIBRARY MEMBERSHIP IS NOT TRANSFERABLE.";
	cout<<"\n\t  \t\t\t3. BOOKS FROM THE LIBRARY CAN BE XEROXED AS WE BELIEVE EDUCATIONAL RESORCES SHOULD BE FREE .";
	cout<<"\n\t  \t\t\t4. ANY SORT OF MODIFICATIONS TO THE BOOKS IS NOT ALLOWED.";
	cout<<"\n\t  \t\t\t5. IN CASE OF DAMAGED OR LOST BOOKS THE BOOKS SHOULD BE REPLACED BY EXACT COPY OR TWO TIMES ITS ACTUAL COST. ";
	cout<<"\n\t  \t\t\t6. ANYONE WHO VIOLATES THE RULES AND REGULATIONS OF THE LIBRARY WOULD BE LIABLE TO LOSE THE PRIVILEGE OF LIBRARY MEMBERSHIP.";
	cout<<"\n\t  \t\t\t   HAPPY LEARNING FOLKS! ;) ";
	cout<<"\n\n\n\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE.........\n\t\t\t\t ";	
	getch();
	system("cls");
	menu();
}

int book_count(){
	int no_of_books = 0;
	ifstream ifs("book_details.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	no_of_books++;
	}
	ifs.close();
	return no_of_books;
}
int student_count(){
	int no_of_student = 0;
	ifstream ifs("student_details.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	no_of_student++;
	}
	ifs.close();
	return no_of_student;
}
int admin_count(){
	int no_of_admins = 0;
	ifstream ifs("admin_details.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	no_of_admins++;
	}
	ifs.close();
	return no_of_admins;
}
int issued_book_count(){
	int no_of_issued_books = 0;
	for(int i=0;i<book.size();i++){ 
		if(book[i].status=='I'){
			no_of_issued_books++;
		}
	}
	return no_of_issued_books;
}

void read_students_details(){
	ifstream ifs;
	ifs.open("student_details.txt");
	int student_number = 0;
	studentc tempobj;
	while (!ifs.eof()){
		ifs >> tempobj.student_id;
		ifs.ignore();
		ifs >> tempobj.issue_limit;
		ifs.ignore();
		ifs.getline(tempobj.password,20,' ');
		getline(ifs,tempobj.name);
		student.push_back(tempobj);
		student_number++;
		ifs>>ws;
	} 
	ifs.close();
}
void read_allbook (){
	ifstream ifs;
	ifs.open("book_details.txt");
	int book_number = 0;
	bookc tempobj;
	while(!ifs.eof()){
		cout<<"worksb"<<endl;
		ifs >> tempobj.book_id;
		ifs.ignore();
		ifs >> tempobj.owner;
		ifs.ignore();
		ifs >> tempobj.price;
		ifs.ignore();
		ifs >> tempobj.edition;
		ifs.ignore();
		ifs >> tempobj.status;
		ifs.ignore();
		getline(ifs,tempobj.name);
		book.push_back(tempobj);
		book_number++;
		ifs>>ws;
	}
	ifs.close();
}
void read_admins(){
	ifstream ifs;
	ifs.open("admin_details.txt");
	int admin_number = 0;
	adminc tempobj;
	while (!ifs.eof()){
		ifs >>tempobj.admin_id;
		ifs.ignore();
		ifs.getline(tempobj.password,20,' ');
		getline(ifs,tempobj.name);
		admin.push_back(tempobj);
		admin_number++;
		ifs>>ws;
	} 
	ifs.close();
}
void save_database(){
	art();
	cout << endl;
	
	ofstream aofs,sofs,bofs,iofs;
	aofs.open("temp_admin_details.txt" 		, fstream::app);
	sofs.open("temp_student_details.txt" 	, fstream::app);
	bofs.open("temp_book_details.txt" 		, fstream::app);
		
	for(int i=0;i<admin.size();i++){	
		aofs << admin[i].admin_id << " ";
		aofs << admin[i].password << " ";
		aofs << admin[i].name	  << endl;
	}
	for(int i=0;i<student.size();i++){	
		sofs << student[i].student_id  << " ";		
		sofs << student[i].issue_limit << " ";		
		sofs << student[i].password	   << " ";		
		sofs << student[i].name		   << endl;		
	}
	for(int i=0;i<book.size();i++){			
		bofs << book[i].book_id << " ";		
		bofs << book[i].owner	<< " ";		
		bofs << book[i].price 	<< " ";		
		bofs << book[i].edition << " ";		
		bofs << book[i].status 	<< " ";		
		bofs << book[i].name	<< endl;	
	}										

	aofs.close();
	sofs.close();
	bofs.close();

	remove("admin_details.txt");
	remove("student_details.txt");
	remove("book_details.txt");

	rename("temp_admin_details.txt" 	 ,"admin_details.txt" 	   );
	rename("temp_student_details.txt" 	 ,"student_details.txt"    );
	rename("temp_book_details.txt" 		 ,"book_details.txt" 	   );
}

int main(){
	fullscreen();
	Sleep(1000);
	system("COLOR F2");//green					
	Sleep(500);
    loading_screen();
	system("cls");
	system("COLOR F0");//black
	Sleep(300);
	welcome_art();
	system("cls");
	
	read_students_details();
	read_allbook ();
	read_admins();
	menu();
	return 0;
}
//system("COLOR F1");	//blue  text on white background 
//system("COLOR F2");	//green text on white background 
//system("COLOR F4");	//red   text on white background 
//system("COLOR F0");	//black text on white background 
//Sleep(500);
