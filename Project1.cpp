#include<iostream>
#include<array>
using namespace std;

///////////////////////////Variables Declarations/////////////////////////////////////
array<string, 100>names;
array<int, 100>ages;

int counter =0;
int user_id_no=0;
string return_name;
int return_age;

//////////////////////user options 1.add 2.fetch 3.quit///////////////
enum class user_option{
       add=1,
       fetch=2,
       quit=3
};

///////////////extraction opeator overloading/////////////////////////
istream& operator>>(istream &input_stream, user_option &result){
    int input_option;
    input_stream>>input_option;
    result=static_cast<user_option>(input_option);
    return input_stream;
}

//////////////////print msg///////////////////////////////////
void print_msg(const std::string & msg){
    cout<<msg;
}

/////////////////application name/////////////////////////
void app_name(){
   print_msg("*******User signUp Application******\n");
}

///////////////////show_menu///////////////////////////
void show_menu() {
    print_msg("Please select an option:\n 1.Add Record\n 2.Fetch Record\n 3.Quit program\n\n");
    print_msg("Enter Option:");
}
/////////user option selection input////////////////////////
user_option option2(){
    user_option option;
    cin>>option;
    return option;
}
/////////////////////////user selection action////////////////////
user_option user_select(user_option opt ){

     if(opt==user_option::add){
       return user_option::add;
     }
     else if(opt==user_option::fetch){
        return user_option::fetch;
     }
     else if(opt==user_option::quit){
        return user_option::quit;
     }
     else
     {
        return user_option::quit;
     }

}
/////////////print option user selection/////////////////////////////
void print_option_user(user_option opt){
     if(opt==user_option::add){
       print_msg("\nAdd user, please enter user name and age:\n");
     }
     else if(opt==user_option::fetch){
        print_msg("\nPlease enter user ID(note id started from 0): ");
     }
     else if(opt==user_option::quit){
        print_msg("\n******Quit Program*******\n");
     }
}
///////////////////add user name//////////////////////
string add_user_name(){
    string name;
    print_msg("name:");
    cin>>name;
    return name;
}
///////////////////add user age///////////////////////////
const int add_user_age(){
   int age;
   print_msg("age: ");
   cin>>age;
   return age;

}
///////////////add user names array/////////////////////
array<string, 100>  add_user_names (string user_name, int count){
    array<string,100>names;
    names[count-1]=user_name;
    return names;

}
////////////////add user ages array////////////////////////////
array<int, 100>  add_user_ages (int age, int count){
    array<int,100>ages;
    ages[count-1]=age;
    return ages;
}
//////////////print added successfully////////////////////////
void print_added_successfully(){
  print_msg("user record added successfully\n\n");
}
/////////////////////user id //////////////////////////////////////
int user_id(){
    int user_id;
    cin>>user_id;
    return user_id;
}
//////////////Fetch Record///////////////////////////////////////
pair<string, int> Fetch_Record(int id){
     string selected_name=names[id];
     int selected_age=ages[id];
     return {selected_name,selected_age};
}

/////////////////////////////print fetch output///////////////////
void fetch_output(string name,int age,int counter){
    cout<<("\nuser ID: ")<<(counter)<<"\n";
    cout<<("User Name: ")<<name<<"\n";
    cout<<("User Age :")<<age<<"\n\n";
}
class person{
    public:
    string user_name;
    int age_user;
    person(){
     user_name=add_user_name();
     age_user=add_user_age();
    
}};

// ///////////////////////Add_Records/////////////////////////////////
void Add_Record(string name, int age){
       counter=counter+1;
       names[counter-1]=name;
       ages[counter-1]=age; 
}

////////////////////////main function//////////////////////////
int main(){
    app_name();
    user_option return_option=user_option::add;
    while(return_option!=user_option::quit){
    show_menu();
    return_option=option2();
    print_option_user(return_option);
    user_select(return_option);
    switch(return_option){
        case(user_option::add):{ 
        person p;
        Add_Record(p.user_name,p.age_user);
        print_added_successfully();
        break;
        }
        case(user_option::fetch):{
        user_id_no=user_id();
        auto return_output = Fetch_Record(user_id_no);
         return_name=return_output.first;
         return_age=return_output.second;
         fetch_output(return_name,return_age,counter);
        break;
        }
    }
    }
}
