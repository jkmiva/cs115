/***************************************************************************
 Week 8 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/
#include <iostream>
using namespace std;

int marioCount(int x,int y){
	if (x==1 || y==1)
		return 1;
	return marioCount(x-1,y)+marioCount(x,y-1);
}


int main(){
	int num;
	num = marioCount(3,3);
	cout<<"number of paths for 3x3 : "<<num<<endl;
	num = marioCount(4,4);
	cout<<"number of paths for 4x4 : "<<num<<endl;
	num = marioCount(10,12);
	cout<<"number of paths for 10x12 : "<<num<<endl;
	return 0;
}
