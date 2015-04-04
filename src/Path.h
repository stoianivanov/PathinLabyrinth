#pragma once
#include "DynamicMatrix.h"
#include "DynamicString.h"
#include "List.h"
#include "Door.h"
#include <fstream>
#include <vector>
#include <list>
class Path{
public:
	Path(std::vector<DynamicString> );
	~Path();
	List<char> getPath();
	void print();
	void printPath();
	void printPath2();
	void printPath3();
	void printPath4();
	void print1();
	void findPath(int row, int col , char direction);
	void next(size_t );
	void find(int row , int col , char direction,char);
private:
	void openNextMap();
	void findKey(int& x , int& y, char key);
	void findExit();
	void initArray(char*);
	void nextMap();
	void initDoor(std::ifstream& );
	void initMap(std::ifstream& );
	void findStart(int& x, int& y);
	void openDoor(int);
	void addPath(int , int);
private:
	DynamicMatrix map;
	List<Door> doors;
	std::list<char> path;
	std::vector<DynamicString> maps;
	char* currentPath;
	int position;
	size_t finishedMap;
};
