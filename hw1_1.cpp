/*
Amirhossein Alibakhshi
id: 9731096
Data Structure and Algorithms Course
Homework #1
Question #1
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

struct person{
	string name;
	int x;// number of ordered breads
};

//global variables
queue<person> q[10]; //creating 10 queues
int breads_numbers = 0;

void add_person_to_queue(person p){
	q[p.x - 1].push(p);
}

void print_queue_front (queue<person> q, int index){
	if (!q.empty()){
//		cout << index << ": " << q.front().name << "(" << q.front().x << ")" << endl;
		cout << index << ": " << q.front().name << endl;
	}
}

void print_all_queues(){
	for (int i = 0; i < 10 ; i++){
		print_queue_front(q[i], i + 1);
	}
}

void bake (int x){
	breads_numbers+=x;
	for (int i = 0; i< 10; i++){
		while(!q[i].empty()){
			if(x < q[i].front().x){
				q[i].front().x -= x;
				return;
			}else{
				x -= q[i].front().x;
				q[i].pop();
			}
		}
	}
}

int main(){
    int n;
    int t;
    cin >> n;
    string command;
    person person_tmp;
    string name_tmp;
    int x_tmp;
    for (int i = 0; i < n; i++){
    	cin >> command;
    	if (!command.compare("ADD")){	//done	
    		cin >> name_tmp >> x_tmp >> t;
   			person_tmp.	name = name_tmp;
   			person_tmp.x = x_tmp;
			add_person_to_queue(person_tmp);
		}else if (!command.compare("BAKE")){		
			cin  >> x_tmp >> t;
			bake(x_tmp);
		}else if (!command.compare("PRINT")){//done
    		cin >> t;
    		print_all_queues();
		}
	}
}
