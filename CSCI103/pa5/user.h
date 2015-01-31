#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using namespace std;


class User {
 public:
    User (int id1, string name1, string name2, int year1, int zip1, 
        vector <int> friends1);
    void addFriend (int id1);
    void deleteFriend (int id1);   
    int what_id();
    string what_first_name ();
    string what_last_name ();    
    int what_year();
    int what_zip();
    vector <int> what_friends(); 
    int many_friends();
    int which_friend(int i);
    
    bool is_friends(int number);

    //Shortest path
    bool is_eli();
    void is_not_eli();
    void change_pred(int x);
    int return_pred();

    //groups    
    void has_visited();
    bool get_visit();
    void reset_visit();

    //other
//
    void add_score();
    void reset_score();
    int what_score();
//
    bool is_on_mutual();
    void reset_mutual();
    void change_mutual();
//
    bool return_pos_mut();
    void not_pos();
    void reset_pos();
    

 private:
    int id;
    string namef;
    string namel;
    int year;
    int zip;
    bool visit;
    bool eli;
    int score;
    bool on_mutual;
    vector <int> friends; //vector to hold the friends of a person 
    int depth;
    int pred; 
    bool pos_mut;
    
};


#endif
