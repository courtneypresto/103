#ifndef NETWORK_H
#define NETWORK_H
#include<string>
#include "user.h"
#include <vector>

using namespace std;

class Network {
 public:
    Network();
    int read_friends (char* fname);
    void add_user(User bob);
    void add_connection(int id1, int id2);
    void remove_c (int id1, int id2);
    int get_id (string fname,string lname);
    int write_friend (char* fname);
    int what_index(User bob);
    int what_size();
    User what_user(int a);

//new stuff    
    int find_lead(int from, int to);
    vector<int> shortest_path(int from, int to);
    vector<vector<int> > groups();
    vector<int> one_group(int a);
    vector<int> suggest_friends(int who, int& score);
   
    
 
private:
    vector<User> indexy;
};


#endif
