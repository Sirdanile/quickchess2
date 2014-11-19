#include <iostream>
#include <vector>
#include <cstdlib>

//Contains Priority Queue
#include <queue>

#include "pieces.h"
#include "king.h"
#include "board.h"

using namespace std;

//
//This is the custom function that compares boards 
//in the Priority Queue based on h' value
//
//bool compare(board x, board y)
//{
//   return (x.getHeuristic() < y.getHeuristic());
//}
//

int main(){
	
	//Typedefs a Priority queue in order to customize the compare function it uses
	//typedef priority_queue<board, std::vector<board>, compare> PriQTy;
    	//PriQTy myQueue;
    	//bool gameOver = false;
	board b;
	b.display();
	char c;
	int curplayer;
	pair<int, int> first;
	pair<int, int> second;
	bool gameover = true;
	//myQueue.push(b);
	
	cout << "Who will move first? w/b: ";
	cin >> c;
	while (c !='w' && c != 'b'){
		cout << "Invalid entry" << endl << endl;
		cout << "Who will move first? w/b: ";
		cin >> c;
	}
	
	if (c == 'w'){
		b.startingmove(0);
		curplayer = 0;
	}
	else{
		b.startingmove(1);
		curplayer = 1;
	}
		
//
//This is the part that should expand nodes, board needs an expand function for this to work
//If I place a thing like this in just the space for our move, it'll look for the best possible
//move on this turn, however to check actual best moves it'll have to view things from the enemy perspective 
//Should implement an alpha-beta version of this search soon
//
//    while(!myQueue.empty() && !gameOver && time != 240)
//    {
//        //Priority queue is not needed for only 1 turn ahead, as the highest h' 
//        //will be the best state to go down as it should be, the need arises 
//        //when looking multiple turns into the future for the overall set 
//        //of best moves.
//        vector<board> temp;
//        temp = myQueue.top().expand();
//        while(!myQueue.empty())
//        {
//            myQueue.pop();
//        }
//        for(int i = 0; i < temp.size(); i++)
//        {
//            myQueue.push(temp[i]);
//        }
//        
//        //Add checks for victory/loss (simple h' check should work))
//        //To set gameOver to true and print useful information
//    }  

for (int x = 0; x <8; x++){
	
	if (curplayer == 0)
		cout << "White's turn:" <<endl;
	else
		cout << "Black's Turn:"<<endl;
	cout << "	first X: ";
	cin >> get<0>(first);
	cout << "	first Y: ";
	cin >> 	get<1>(first);
	cout << "	second X: ";
	cin >> get<0>(second);
	cout << "	second Y: ";
	cin >> get<1>(second);
	
	b.move(first, second);
	b.display();
	
	cout << endl << endl;
	curplayer = abs(curplayer - 1);

}

	return 0;
}
