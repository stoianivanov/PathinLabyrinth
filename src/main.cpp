//============================================================================
// Name        : debatupieclipse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.h"
#include "Path.h"
#include <vector>

void readMaps(std::vector<DynamicString>& vector){
	DynamicString string;
	std::cin>>string;
	while(string!="exit"){
			vector.push_back(string);
			std::cin>>string;

	}

}
int main() {
	/*cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	List<int> list;
	cout<<"exooo";
	cout<<list.isEmpty();
	list.addLast(1);
	cout<<list.isEmpty();
	for(size_t i =0 ; i <100; ++i){
		list.addFront(i);
	}
	cout<<endl<<list.isEmpty();
	for(size_t i =0 ; i <101; ++i){
		cout<<list.removeLast();
	}
	cout<<endl<<list.isEmpty();*/
//	DynamicString string("file1.txt");
//	DynamicString string2("file2.txt");
//	DynamicString string3 ( "file3.txt");
//	List<DynamicString> list;
//	list.addLast(string);
//	list.addLast(string2);
	std::vector<DynamicString> vector;
//	vector.push_back(string);
//	vector.push_back(string2);
//	vector.push_back(string3);
	readMaps(vector);
	//list.addLast(string3);
	Path path(vector);
	path.printPath();
	path.printPath2();
	path.printPath3();
	/*try{
		path.next(0);
		path.print1();
		std::cout<<"Jump to second map\n";

	}catch (...) {
		std::cout<<"catch exception";
	}

	try{
		path.next(1);
		path.print1();
	}catch (...) {

	}
	try{
		path.next(2);
		path.print1();

	}catch (...) {

	}*/


	return 0;
}
