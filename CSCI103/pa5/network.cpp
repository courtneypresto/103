#include "network.h"
//#include "user.h"
//#include "user.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;


Network::Network (){
}
/*********************************READ THE FILE**********************/
int Network::read_friends(char* fname){
   
    ifstream ifile(fname); 
    if (ifile.fail() ==1){
        return 1;
    }
       
    int network_size;                     
     //first thing in the file is network size
    ifile >> network_size;
     
    
    for (int i = 0; i < network_size; i++){ 
        int ids;    
        string first_names;
        string last_names;
        int years;
        int zips;
        vector <int> boy;
        string temp;        
        string my_friends;
        int very_temp;

           

        ifile >> ids;
        ifile >> first_names;
        ifile >> last_names;
        ifile >> years;
        ifile >> zips;
        getline(ifile, temp);      // does a getline to just continue to the 
                                    //next line
        getline(ifile, my_friends);             
        stringstream ss (my_friends);
        
        while (ss >> very_temp){
        boy.push_back(very_temp);
        }      

       
        User any_user(ids, first_names, last_names, years,  zips, boy);
                                               
 //makes objects for all the users
        indexy.push_back(any_user);             
//adds all the users to the index
        }
    return 0;
}

/**********ADD THE USER*****************************/    
void Network::add_user (User bob){
    indexy.push_back(bob);                      
    // adds a new user to the index
    }    




/******ADD FRIEND CONNECTION****/  

void Network::add_connection (int id1, int id2){
                    
    indexy[id1].addFriend(id2);
    indexy[id2].addFriend(id1);
    return;
    
 }
      
/********REMOVE CONNECTION********************/  

void Network::remove_c(int id1, int id2){
   indexy[id1].deleteFriend(id2);  // makes a user object for user at id1
   indexy[id2].deleteFriend(id1);  // makes a user object for user at id2

    return;
}
            
    

/***********WRITE TO FILE***************/

int Network::write_friend (char* fname){
    ofstream ofile (fname);  
    
    if (ofile.fail()){      
     // quit id we can't successfully make an output file
        return -1;
    }    
    
  else{
ofile << indexy.size() << endl;
    for (int i =0; i < (int)indexy.size(); i++){ 
         User lola = indexy[i];             
    // creates user objects to print in output file
         ofile <<  lola.what_id() << "\n\t" << lola.what_first_name() << " " 
<< lola.what_last_name() << "\n\t" << lola.what_year() << "\n\t" <<
        lola.what_zip() << "\n\t";
        for (unsigned int j=0; j<indexy[i].what_friends().size(); j++) 
            ofile << indexy[i].what_friends()[j] << " ";
        ofile << endl;
    }
    ofile.close();
    return 0;
    }
}


/************GET_ID*****************************/
int Network::get_id (string fname, string lname){
    for (int i=0; i < (int)indexy.size(); i++){
        User bob = indexy[i];    // creates user for index[i]
        if ((bob.what_first_name() == fname) && (bob.what_last_name() 
        ==lname)){
            return bob.what_id();  //return's user id
         }
     }

 return -1;      //return's -1 if user is not in index
   }     
/*********INDEX SIZE *******************/

int Network::what_size (){
    return (int) indexy.size(); // returns index size
}    

/*********Return user*****************/

User Network::what_user (int a){
    return (indexy[a]);     // returns user at index 
}

/**********Shortest Path**************************/
vector<int> Network::shortest_path(int from, int to){

        // reset pred
    for (int i=0; i< (int) indexy.size(); i++){
        indexy[i].change_pred(-1);
    }  




    vector <int> queue;                         // initialize a queue
    int head =0;                                // initialize a head
    queue.push_back(from);               
              // put from as the first person in q                           
    vector<int> path;                           // path 
    vector<int> path1;                          // path 1
    indexy[from].change_pred(-1);               // from's pred is -1
    indexy[from].is_not_eli();
    
    int possible =-10;                          // check variable

    while (head != (int) queue.size()){         
// while head is not at the end

        vector <int> some_friends =indexy[queue[head]].what_friends(); 
// creates a vector for whatever's 
                                                    
// in the que at elemet head
        

        for (int i=0; i < (int) some_friends.size(); i++){
            User harold = indexy[some_friends[i]];
            if (indexy[some_friends[i]].is_eli() == true){
                if(some_friends[i] == to){
                    possible = 10;
                    queue.push_back(some_friends[i]);
                    indexy[some_friends[i]].is_not_eli();
                    indexy[some_friends[i]].change_pred(queue[head]); 
                    break;
                }
                else{
                    queue.push_back(some_friends[i]);
                    indexy[some_friends[i]].is_not_eli();
                    indexy[some_friends[i]].change_pred(queue[head]);
                 }  
            }
        }  
                      
        head++; 
     }
    

    int loc = to;

    if (possible == 10){                            // if we found the path
        while(loc != from){
            path.push_back(loc);
            User jim = indexy[loc];
            loc = indexy[loc].return_pred();
            User bob = indexy[loc];
            }
        path.push_back(from);
    }

    int j =0;
    int i = (int) (path.size()-1);  
    while(i >=0){
        path1.push_back(path[i]);
        j++;
        i--;
    }
 
    return path1;
 
}
/**********************Groups********************************************/
vector<vector<int> > Network::groups(){
    
    int a_check=0;                       // check variable
    vector<vector<int> > big_vector;       // THE ULTIMATE VECTOR!!!
    
    for (int i=0; i< (int) indexy.size(); i++){     
//resets the bool variable
        indexy[i].reset_visit();
    }

    while (a_check < (int) indexy.size()){ 
// until we visit every user in the indexy
        a_check = 0;                    
        for (int i=0; i < (int)indexy.size(); i++){
            if (indexy[i].get_visit() == false){      
//if we haven't visited wayne b4
            big_vector.push_back(this->one_group(i)); 
// call one_group to make a group starting with him
             }
        }
           
            for (int i=0; i < (int) indexy.size(); i++){ 
// first, see where we are with the check 
                if (indexy[i].get_visit() == true){
                    a_check++;                           
// how many people in the index                 
                }                                        
// have been checked already?
            }
    }
   
     return big_vector;
} 
 /***************Create Vector of One Group*************/
vector<int> Network::one_group(int a){
      vector<int> queue1;
      vector <int> test = indexy[a].what_friends(); 
    //vector for wayne's friends
    
    queue1.push_back(a);
    indexy[a].has_visited();
    int head1=0;

    while (head1 !=(int) queue1.size()){
        vector <int> some_friends1 =indexy[queue1[head1]].what_friends();
    
        int i =0;

        while (i < (int) some_friends1.size()){
                if (indexy[some_friends1[i]].get_visit() == false){  
    // if not visited
                        queue1.push_back(some_friends1[i]);
                        indexy[some_friends1[i]].has_visited();
                        
                 }           
            i++;

           }              
       head1++; 
     }
    return queue1;
}
     
/****************** Friend Suggestion********************/
vector<int> Network::suggest_friends(int who, int& score){
   //cout << "who is "<< who << endl;
    vector <int> testA = indexy[who].what_friends();       
    // vector for this guy's friends
    vector <int> mutual;                               
     // vector to hold all mutual friends     

    
    
    for (int i=0; i< (int) indexy.size(); i++){ // resets bool variable 
        indexy[i].reset_pos();
        indexy[i].reset_score();
        indexy[i].reset_mutual();
    }

    for (int i = 0; i < (int) testA.size(); i++){ //set friends as ineligable
        indexy[testA[i]].not_pos();
        
    }
      indexy[who].not_pos();       
          
                    // Deals with the score //
    for (int i=0; i< (int) testA.size(); i++){                      
        // for all of who's friends
        vector <int> paul_f = indexy[testA[i]].what_friends(); 
        // vector for (who's friends friend)

        
        for(int j=0; j < (int) paul_f.size(); j++){          
     // for all of who's friends friends
            if (indexy[paul_f[j]].return_pos_mut() == true){         
     // if they are eligable  
                 indexy[paul_f[j]].add_score();                    
     // score goes up
                
                if (indexy[paul_f[j]].is_on_mutual() == false){ 
    // if they aren't in the mutual vect
                 mutual.push_back(indexy[paul_f[j]].what_id()); 
    // put in vetor
                 indexy[paul_f[j]].change_mutual();             
    // no longer mutal
                }
            }
        }
    }



   
                    // creates a vector of friend suggestions//
int scorey =0;
vector <int> suggest;

   for (int i=0; i < (int) mutual.size(); i++){  
     // goes through the list of mutual friends
        User phi = indexy[mutual[i]];
        if (phi.what_score() > scorey){
            scorey = phi.what_score();               
    // finds what the highest score is
        }
    }

    score = scorey;

    for (int i=0; i < (int) mutual.size(); i++){    
    // goes through the list of mutual friends 
        if (indexy[mutual[i]].what_score() == scorey){
            suggest.push_back(indexy[mutual[i]].what_id());     
    // creates a vector of everyone with the 
                                                                
    //highest score
        }
    }

 return suggest;
}
        


