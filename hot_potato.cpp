#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> people;
    list<int> passed;
    int N, M;

    cout << "Enter the number of people: ";//To allocate how many people playing in the game.
    cin >> N;
    cout << "Enter the passed counts: ";// To allocate how many counts before a person is eliminated.
    cin >> M;

    for(int i=0; i<N; i++){ // Allocating how many people playing in the game.
        people.push_back(i+1);// {1,2,3,....N} starting with 1.
    }
    list<int>::iterator potato = people.begin();// Starting from the first person.
    //Potato's index is 1.

    while(people.size() > 1){
        for(int j=0; j < M; j++){
            potato++;//Passing the potato to the next person.
            if(potato == people.end()){//If the potato reaches the last person,
                potato = people.begin();//then that person would be the first one in the next round.
            }
            if(j == M-1){//When the passing counts reach M, the person holding the potato is eliminated.
                passed.push_back(*potato);//Recording the order of elimination.
                potato = people.erase(potato);//Eliminating the person holding the potato.
            }
        }
    }
    cout << "The people who have been eliminated in order: ";
    for(auto p : passed){//Output the order of elimination.
        cout << p << " ";
    }
    cout << endl;
    cout << "The last person standing is: " << people.front() << endl;
    return 0; 
}

