#include "network.h"
#include "user.h"
//#include "network.cpp"
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>


using namespace std;

int main(int argc, char *argv[])
{

// *******************SECTION A - FILE INPUT******************

    Network social;                                   //declare the network
f 
    int checky;
    checky = social.read_friends(argv[1]);            //reads from the file

if (checky == 1){                 //makes sure you put the input file in 
    cout << "\nYou forgot to specify the input file, silly goose!\n" << endl;
    return 1;
    }
// *****************SECTION B - Initial Menu & Choices *****************

cout << "Please choose an option:" << endl;
cout << "1 - Add a user: Enter \"1 FirstName LastName BirthYear Zip\" " << 
endl;
cout << "2 - Add a connection: Enter \"2 User1 User2\"" << endl;
cout << "3 - Remove a friend connection: Enter \"3 User1 User2\"" << endl;
cout << "4 - Print users: Enter \"4\"" << endl;
cout << "5 - Print friends of a user: Enter \"5 User\"" << endl;
cout << "6 - Write to file: Enter \"6 file_name\"" << endl;
cout << "7 - Shortest Path Between Friends: Enter \" 7  User1 User2 \"" << 
endl;
cout << "8 - Groups: Enter \" 8 \"" << endl;  
cout << "9 - Friend Suggestion: Enter \"9 User \"" << endl; 
cout << "10 - End program" << endl;   
     
int user_option;
cin >> user_option;

while (user_option < 10 && user_option > 0){



//****************************Option 1 ********************************
    if (user_option == 1) {  
        string first_name;         // declares neccesary variables
        string last_name;
        int birth_year;
        int zip_code;
        vector <int> vecty;
        int length = (int) social.what_size();// determines size of network

        cin >> first_name;
        cin >> last_name;
        cin >> birth_year;
        cin >> zip_code;
        User bobby(length, first_name, last_name, birth_year, zip_code, 
        vecty);
                                       // creates a new user object
        social.add_user(bobby);        // adds that user to the network
    }


    // **********Option 2 Add Friend********************************


    if (user_option == 2)  //the user enters the names of two existing people
        string Fname;
        string Lname;
        string Fname1;
        string Lname1;
        //int what_check;
        cin >> Fname >>Lname>> Fname1 >>Lname1;  

        int this_id = social.get_id(Fname, Lname);      // determines id for 
                                                    //first person
        int that_id = social.get_id(Fname1, Lname1);      // determines id 
                                            //for second person
        
     social.add_connection(this_id, that_id);   //checks whether or not 
                                        //      these people
   
    
}

    // *******Option 3 Delete Friend******************

    if (user_option == 3){
        string Fnamea;
        string Lnamea;
        string Fnameb;
        string Lnameb;
        cin >> Fnamea >>Lnamea>> Fnameb >>Lnameb;    
        
        int a_id = social.get_id(Fnamea, Lnamea);  // determines id of first 
                                                //person
        int b_id = social.get_id(Fnameb, Lnameb);  // determines id of 
                                                         // second person 

        social.remove_c(a_id, b_id);                // removes connection //
                                                //between them
     }


    //****************Option 4 Print Users********************************

    if (user_option == 4) {
        ostringstream storage;
        
        /*storage << setw(1) << "ID " << setw(10) << "Name " << setw(10) <<
        "Birth Year " << setw(10) << "Zip  "<< endl;
        ***** this was my attempt at trying to format a table 
              storage << setw(50) << setfill(" ") << endl;*/

        cout << "ID        NAME        BIRTH YEAR        ZIP        " << endl;
        cout << "===================================================" << endl;
       
     int size = social.what_size(); // determines size of network 
        vector <int> tester;   //creates an empty int vect                   
    
      
        for (int i=0; i< size; i++){
            User bobb = social.what_user(i); // creates user object for all 
                                                //users in index
            string FFname;
            string SSname;
            
            cout << bobb.what_id() << "        " << bobb.what_first_name() 
<<" "<<
            bobb.what_last_name () <<"        "<< bobb.what_year() 
<< "        " << bobb.what_zip
            (); // prints user information               
            cout<< endl;
        }
           /* storage<< setw(1) << bobb.what_id() <<bobb.what_first_name() 
            << 
            setw(1) << bobb.what_last_name() << setw(10) <<bobb.what_year() 
              << 
            setw(10) << bobb.what_zip()<< endl;*/

           
}
    /*cout << storage.str();*/

    //**********Option 5  Print Friends of Users *********************

    if (user_option == 5){

        string frF;
        string frL;
        cin >> frF >>frL;

        int fr_id = social.get_id(frF, frL);     //ID number of target
       
     if (fr_id !=-1){
            

        User jeb = social.what_user(fr_id);     // makes an user object for 
                                                //target

         vector<int> list = jeb.what_friends(); //declares a vector to hold 
                                                //target's friends

        //stringstream storage;
        
        /*storage << setw(1) << setfill('ID') << setw(10) << setfill('NAME') 
            << 
        setfill('Birth Year') << set(10) << setfill('Zip') << endl;
        storage << setw(50) << setfill('=') << endl;*/

        cout << "ID        NAME        BIRTH YEAR        ZIP        " << 
endl;
        cout << "===================================================" << 
endl;

        for (int i=0; i <(int) list.size(); i++){
            int temp = list[i];       
            User tom = social.what_user(temp);    //creates a user from 
                                                //friends list index
        
   cout << tom.what_id() << "     " << tom.what_first_name() << "      " << 
tom.what_last_name()<< "     " << tom.what_year()<< "     " << tom.what_zip
() << endl;
            // prints that user's information


           }
        }

        /* storage<< setw(1) << setfill(tom.what_id) <<setfill
(tom.what_first_name) << 
 
           setw(1) << setfill(tom.what_last_name) << setw(10) << setfill
(tom.what_year) << 
            setw(10) << setfill(tom.what_zip)<< endl;*/
            
        

    }

    //************Option 6 Write to File******************
    if (user_option == 6){
        char filefile[80];         //declares variable to hold user 
                                        //specified filename
        cin >> filefile;

        social.write_friend(filefile); //calls network function to write 

    
    }


    /****Option 7 Shortest Path********************************/
    if (user_option == 7){
    string FIRST1;
    string LAST1;
    string FIRST2;
    string LAST2;
    
    cin >> FIRST1 >> LAST1 >> FIRST2 >> LAST2;    

   int oneid = social.get_id(FIRST1, LAST1);
   int twoid = social.get_id(FIRST2, LAST2);
    
    
    vector <int> shortest;

    shortest = social.shortest_path(oneid, twoid);
     
    cout << "Distance: " << shortest.size() << endl;
    
    for (int i= 0; i < (int) shortest.size(); i++){
        User jennifer = social.what_user(shortest[i]);
     cout << jennifer.what_first_name() << " " << jennifer.what_last_name();
        if (i != (int)shortest.size()-1){
            cout << " -> ";
        }
    }
}


/********Option 8 Disjoint**************************************/
  if (user_option ==8){
    
    vector<vector<int> > hold_vectors;
   
    hold_vectors =  social.groups();
    
    for (int i=0; i < (int) hold_vectors.size(); i++){
        cout << "Set " << i << " => ";
        vector <int> temporary = hold_vectors[i];
            for (int j=0; j < (int) temporary.size(); j++){
               User okay = social.what_user(temporary[j]);
               cout<< okay.what_first_name() << " " << okay.what_last_name();
                    if (j != (int) temporary.size()-1){
                        cout << ", ";
                    }
               }
            cout << endl;
    }
         

}
/**********Option 9 Friend Suggestion***************************/
 if (user_option == 9){
   string the_first;
   string the_last;

    cin >> the_first >> the_last;

    int the_id = social.get_id(the_first, the_last);
    
    vector <int> the_suggest;
   
    int score = 0;
  
    the_suggest = social.suggest_friends(the_id, score);
    
    cout << "Score is: " << score << endl;
    for(int i=0; i < (int) the_suggest.size(); i ++){
        User out = social.what_user(the_suggest[i]);
        cout << out.what_first_name() << " " << out.what_last_name() << endl;
    }
} 
    




  //****************Loop*******************************************/

    cout << "\n \nPlease choose an option:" << endl;
    cout << "1 - Add a user: Enter \"1 FirstName LastName BirthYear Zip\" " 
<< endl;
    cout << "2 - Add a connection: Enter \"2 User1 User2\"" << endl;
    cout << "3 - Remove a friend connection: Enter \"3 User1 User2\"" << 
endl;
    cout << "4 - Print users: Enter \"4\"" << endl;
    cout << "5 - Print friends of a user: Enter \"5 User\"" << endl;
    cout << "6 - Write to file: Enter \"6 file_name\"" << endl;
    cout << "7 - Shortest Path Between Friends: Enter \" 7  User1 User2 \"" 
<< endl;
    cout << "8 - Groups: Enter \" 8 \"" << endl;
    cout << "9 - Friend Suggestion: Enter \"9 User \"" << endl;    
    cout << "10 - End program" << endl;    
    cin >> user_option;
    }





  return 0;
}








