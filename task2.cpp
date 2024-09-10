#include <iostream>
#include <string>
#include <fstream>
 


using namespace std;
void login();
void signup();
void studentgrade();
void printdata(string filename, string startword , string endword);
void adminsignup();
void adminlogin();

   
bool check(string check ){
//string  checking = "records.txt";
string line_to_check = check;

bool line_exists = false;
ifstream infile("records.txt");
string currentline; int k=0;
while (getline(infile ,  currentline)){
   if (currentline == line_to_check){
      line_exists = true;
      cout<<"you already register :"<<endl;
      k++;
      break;
      login();
   }
   
}
infile.close();
if(k==0)
{
  // cout << "You have not registered :" << endl;
   return false;
}
else 
return true;
}

bool markscheck(string check ){
//string  checking = "records.txt";
string line_to_check = check;

bool line_exists = false;
ifstream infile("records.txt");
string currentline; int k=0;
while (getline(infile ,  currentline)){
   if (currentline == line_to_check){
      line_exists = true;
      cout<<"marks :- "<<endl;
      k++;
      
      
   }
   
}
infile.close();
if(k==0)
{
   cout << "marks are not updated :" << endl;
   return false;
}
else 
return true;
}

 void studentgrade(){
         ofstream updategrade;
         int  c2 ,c3,c4,c5,c6 ;
         double spi ,c;
          double total ;
            total= 0.0;
         string  name,s1,s2,s3,s4;
         updategrade.open("records.txt",ios::app);
         if (updategrade.is_open()){
            cout<<"enter which semester mark do you want to update 1 to 8:"<<endl;
            cin>>c3;
         cout<<"enter no. of course in this semester : "<<endl;
         cin>>c;
         cout<<"please give marks between 0 to 10 :"<<endl;
          cout <<"enter student name with branch  also mention semister \nexample abhay.cse.1 for semister 1:"<<endl;
            cin>>name;
            updategrade<<name<<"\n";
            updategrade<<"samester "<<c3<<" marks :-"<<"\n";
         for ( int i=1 ; i<=c ; i++){
            double  m ;
            string c1;
          cout <<"enter course code like ph107 : "<<endl;
          cin>>c1;
          cout<<"update grades for "<<c1<<" is :";
          cin>>m;
          updategrade<<c1<<" :- "<<m<<"\n";
          total = total + m;
         }
          spi = (total / c);
          
          updategrade<<"spi :- "<<spi<<"\n";
          cout<<"enter user id of studentn:"<<endl;
          cin>>s1;
          updategrade<<"userid :- "<<s1<<"\n";
          updategrade<<"\n";
          cout<<"marks are updated :"<<endl;
         updategrade.close();
         }
      }
      

void printdata(const string filename,
const string startword,
const  string endword ){
    

   ifstream infile;
   infile.open("records.txt");
   if (!infile.is_open()){
 cout<<"unable to search data :"<<endl;
   }
   string line;
   bool printing =false;//a sign to start printing
   while ( getline(infile,line)){
      //if(line.find(startword) !=string::npos)
      if(line.find(startword) != -1)
      {
         printing = true; //start printing from this line
      }
      if (printing){
         cout<<line<<endl;
      }
      if (line.find(endword) == 0  && printing){
         //stop printing
         break;
      }
   }
     if (printing = false) {
      cout<<"your data are not found :"<<endl;
     }
  
   infile.close();
}
  
 void signup(){
    string name,branch,mailid , password, userid,cpassword;
       
       ofstream signup;
       signup .open("records.txt",ios::app);
       if (signup.is_open()){
       cout<<"enter your userid :"<<endl;
       cin>>userid;
        if (check( "userid :- " + userid) == false) {
       signup<<"userid :- "<<userid<<"\n";
       
       cout<<"enter your name without space :"<<endl;
       cin>>name;
        signup<<"Name :- "<<name<<"\n";

        cout<<"enter your institute mailid : "<<endl;
        cin>>mailid;
        signup<<"maid id :- "<<mailid<<"\n";

        cout<<"Enter your branch :"<<endl;
        cin>>branch;
        signup<<"Department :- "<<branch<<"\n"; 

        cout<<"Set your password :"<<endl;
        cin>>password;
        signup<<"password :- "<<password<<"\n";
        signup<<"\n";
        cout<<"Your registration is done :"<<endl;
       }
       }

       else {
         cout<<"unable to open file to store data  :"<<endl;
       }
       signup.close();//closing the file 
 }
//function for login 
 void login(){
    int a;
    string name ,rollno,userid ,password,startword ,endword ,mark;
    string login = "records.txt";

    cout<<"Enter your userid :"<<endl;
    cin>>userid;
   cout<<"Enter your password :"<<endl;
   cin>>password;
    startword = "userid :- " + userid;
    endword = "password :- " + password;
   //call the function to print data 
   printdata(login , startword ,endword);
   
   cout<<"if you want to view your grade then press 1 :"<<endl;
   cout<<"if you want to exit then press 2 :"<<endl;
   cin>>a;
   if (a==1){
      cout<<"enter your name and branch also mention semister in this format \nfor example abhay.cse.1 for semister 1 :"<<endl;
      cin>>mark;
      markscheck(mark);
      printdata(login , mark ,startword);
   }
   else if (a==2) {
      cout<<"exit"<<endl;
   }
   else{
      cout<<"chose valid option :"<<endl;
      
   }
   
    
 }
  void adminsignup(){
   ofstream adminsignup;
   string admin1,admin2,admin3, admin4,st4,st5,st6, st7;
   int a;
     string login = "records.txt";
         adminsignup .open("records.txt",ios::app);
       if (adminsignup.is_open()){
       cout<<"enter your userid like ph107 :"<<endl;
       cin>>admin1;
        if (check( "userid :- " + admin1) == false) {
       adminsignup<<"userid :- "<<admin1<<"\n";
       cout<<"enter your name without space :"<<endl;
       cin>>admin3;
       adminsignup<<"name :- "<<admin3<<"\n";
       cout<<"enter your subject :"<<endl;
       cin>>admin4;
       adminsignup<<"subject :- "<<admin4<<"\n";
        cout<<"set your password :- "<<endl;
      cin>>admin2;
      adminsignup<<"password :- "<<admin2<<"\n";
      adminsignup<<"\n"; 
         adminsignup.close() ;
         cout<<"you are successfully signup :"<<endl;
         cout<<"if you want update student marks then press 1 :"<<endl;
         cout << "if you want to view grade of register student then press 2 :"<<endl;
         cin>>a;
      if (a==1){
         studentgrade();
      }
      if (a==2){
         cout<<"enter your student name & branch : \nfor example - abhay.cse"<<endl;
         cin>>st4;
         cout<<"enter student userid :"<<endl;
         cin>>st5;
         st6 = "userid :- "+ st5;
         markscheck(st4);
         printdata(login , st4,st6 );
      }
     
      } 
       }
         else {
            cout << " unable to signup plese try again :"<<endl;
            return ;
         }
         
  }
     


     void adminlogin(){
      int ad1;
      string login1, login2,login3,adminstart,adminend , st4,st5,st6;
      string adminlogin1= "records.txt";
      cout<<"enter your userid :"<<endl;
      cin>>login1;
      cout<<"enter your password :"<<endl;
      cin>>login2;
      adminstart = "userid :- " + login1;
      adminend ="password :- " + login2;
      //call the function to print data 
      printdata(adminlogin1 , adminstart , adminend);
      cout<<"you are successfully login :"<<endl;
      cout<<"if you want to update student marks then press 1 :"<<endl;
      cout << "if you want to view grade of register student then press 2 :"<<endl;
 
            cout<<"if you want to add new student press 3 :"<<endl;
           
      cin>>ad1;
      if (ad1==1){
         studentgrade();
      }
      if (ad1==2){
          cout<<"enter your student name & branch : \nfor example - abhay.cse"<<endl;
         cin>>st4;
         cout<<"enter student userid :"<<endl;
         cin>>st5;
         st6 = "userid :- "+ st5;
         markscheck(st4);
         printdata(adminlogin1 , st4,st6 );
      }
        if ( ad1==3){
        
               cout<<"Enter following detail of your student :"<<endl;
               
               signup();
           
        }
      else {
         cout <<"you chose invalid option"<<endl;
         return ;
      }

     }


 int main(){
    int a ,b ,c,d,e,f;
    string st1,sst2,st3,st4;
    cout <<"Press 1 if your are a student :"<<endl;
    cout<< "Press 2 if your a admin :"<<endl;
    cin>>a;
    if (a==1){
        cout<<"Enter 1 for signup :"<<endl;
        cout<<"Enter 2 for login :"<<endl;
        cin>>b;
        if(b==1){
            cout<<"Fill your details :"<<endl;
       signup();
       return 1;
    }
 
    
       else if (b==2){
       login();
       
       cout <<"press 1 for exit"<<endl;
       cin>>e;
      

       if (e==1){
         return 0;
       }
       else {
         cout<<"enter valid option :"<<endl;
       }
       }
       else {
        cout<<"enter valid number"<<endl;
       }
    }

         if (a==2){
            cout<<"press 1 if you want to signup"<<endl;
            cout<<"press 2 if you want to login"<<endl;
            cin>>c;
            if ( c==1) {
            adminsignup();
            }  

            if (c==2){
             adminlogin()  ;
            }
         }
         else{
            cout<<"chose valid option :"<<endl;
         }
       // else{
       //     cout <<"Enter vallid number"<<endl;
       // }
    
        return 0;
    
    }
 