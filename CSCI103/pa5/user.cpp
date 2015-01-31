#include "user.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


User::User (int id1, string name1, string name2, int year1, 
    int zip1, vector<int> friends1)
{                                                   // id = arraynumber1;
    namef = name1;
    namel = name2;
    year = year1;
    zip = zip1;
    friends = friends1;
    id = id1;
    visit = false;
    eli = true;
    score = 0;
    on_mutual = false;
    pred = -1;
    pos_mut = true; 
}

int User::what_id () {                      // returns a user's id #
    return id;
    }

string User::what_first_name(){             // returns a user's first name
    return namef;
    }

string User::what_last_name(){              // returns a user's last name
    return namel;
    }

int User::what_year(){                      // returns a user's birth year
    return year;
    }

int User::what_zip(){                       // returns a user's zip
    return zip;
    }

vector <int> User:: what_friends(){         // returns all user's friends     
    return friends;
    }
 

void User::addFriend(int id1){              // adds an id to the friend vector
    friends.push_back(id1);
    }

void User::deleteFriend(int id1){           // deletes an id to the friend vector

    int check =-1;
    for (int i=0; i< (int) friends.size(); i++){
        if (friends[i] == id1){
            check = i;
            }
        }

       friends[check]= friends[(int)friends.size()-1];
       friends.pop_back(); 
   
}

int User::many_friends(){            // returns size of friend vector
    return (int) friends.size();
}
        

int User::which_friend(int i){ //returns friend at position i in friend 
                                //vector
    return friends[i];
}

void User::has_visited(){
    visit = true;
}

bool User::get_visit(){
    return visit;
}

void User:: reset_visit(){
    visit =false;
}

bool User:: is_friends(int number){
    bool friendly = false;   
     for (int i=0; i< (int) friends.size(); i++){
        if (friends[i] ==number ){
             friendly = true;
        }
    }
         return friendly;
}
        
bool User:: is_eli(){
    return eli;
}

void User:: is_not_eli(){
    eli = false;
}

void User:: change_pred(int x){
    pred = x;
}

int User:: return_pred(){
    return pred;
}


/*******Friend Suggestion*********/
// possible mutual
bool User:: return_pos_mut(){
    return pos_mut;
}

void User:: not_pos(){
    pos_mut =false;
}

void User:: reset_pos(){
    pos_mut =true;
}

//score
void User:: add_score(){
    score++;
}

int User:: what_score(){
    return score;
}

void User:: reset_score(){
    score =0;
}
// mutual vector
bool User:: is_on_mutual(){
    return on_mutual;
}

void User:: change_mutual(){
    on_mutual= true;
}

void User:: reset_mutual(){
    on_mutual = false;
}





