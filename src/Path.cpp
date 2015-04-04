#include "Path.h"

Path::Path(std::vector<DynamicString> mapsList){

	this->maps=mapsList;
	std::ifstream file;
	position=0;
	finishedMap=0;
	file.open(maps[0].getString(),std::ios::in);
	initMap(file);
	initDoor(file);
	file.close();

}


///
///Функцията попълва списъка от врати
///
void Path::initDoor(std::ifstream& file){
	char doorNumber;
	char key;
	while(!file.eof()){
		file>>std::ws;
		file >>doorNumber;
		file>>std::ws;
		file>> key;
		Door newDoor(key,doorNumber);
		doors.addLast(newDoor);
	}
}
///
///попълва лабиринта от файл
///
void Path::initMap(std::ifstream& file ){
	if(currentPath!= NULL){
		delete currentPath;
	}
	size_t row,col;
	file>>std::ws;
	file>>row;
	file>>std::ws;
	file>>col;
	currentPath= new char[row*col];
	DynamicMatrix newMap(row,col);
	this->map=newMap;
	file>>map;
}
void Path::print(){
	while(!doors.isEmpty()){
		Door door = doors.removeFirst();
		std::cout<<"Door:"<<door.getDoorNumber()<<" "<<door.getKey();
	}
}

///
///Намиране на път до точка
///

void Path::findPath(int row , int col , char direction){

	int x,y;
	findStart(x,y);
	//първо търся пътищата до всички ключове
	while(doors.getSize()>1){
		Door door= doors.removeFirst();
		int newPosX, newPosY;
		findKey(newPosX,newPosY,door.getKey());// намирам позицията на ключа
		find(x,y,'S',door.getKey());
		openDoor(door.getDoorNumber());
		x=newPosX;

		y=newPosY;

	//	this->print1();
	}
	// след като пътя е чист , търся изхода на дадения лабиринт
	find(x,y,'S','X');
	if(!doors.isEmpty()){
		doors.removeLast();
	}


}

///
///Принтира пътя
///

void Path::printPath(){
	for(int i=0;i <maps.size();++i){
		next(i);
	}


	this->print1();
}
void Path::print1(){
	if(finishedMap==maps.size()){
		for(std::list<char>::iterator it = this->path.begin();
				it!=this->path.end();++it){
			std::cout<<*it;
		}
		std::cout<<std::endl;
	}else{
		std::cout<<"Path not found\n";
	}

}
///
///прехваля на следващия лабиринт,
///като зарежда новите врати, ключове и лабиринта
///
void Path::next(size_t pos){
		std::ifstream file;
		file.open(maps[pos].getString(),std::ios::in);
		initMap(file);
		initDoor(file);
		this->findPath(2,0,'S');
		file.close();
}

///
///намира мястото на старта на дадения лабиринт
///
void Path::find(int row , int col , char direction, char elemFind){

	if(col<0 || row<0 || row >=map.sizeX() || col>=map.sizeY()){
		return;
	}
	currentPath[position]=direction;
	++position;
	if(map.at(row,col)==elemFind){
		if(map.at(row,col)=='X'){
			++finishedMap;// брояч, който отговаря за това от колко лабиринта са намерени изходи
		}
		map.setAt(row,col,' ');
		addPath(0,position);

	}

	if(map.at(row,col)==' '  || map.at(row,col)=='S'){
		map.setAt(row,col,'Y');
		find(row,col-1,'L',elemFind);
		find(row-1,col,'U',elemFind);
		find(row,col+1,'R',elemFind);
		find(row+1,col,'D',elemFind);

		map.setAt(row,col,' ');
	}
	--position;
}

///
///намирам кординатите на старта
///

void Path::findStart(int& x, int& y){
	size_t lenX= map.sizeX();
	size_t lenY = map.sizeY();
	for(size_t i= 0 ; i < lenX; ++i){
		for(size_t j=0; j < lenY; ++j){
			if(map.at(i,j)=='S'){
				x=i;
				y=j;
				return;
			}
		}
	}
}
///
///funkciq koqto namira poziciqta na klucha v labirinta
///

void Path::findKey(int& x , int& y, char key){
	size_t lenX= map.sizeX();
	size_t lenY = map.sizeY();
	for(size_t i= 0 ; i < lenX; ++i){
		for(size_t j=0; j < lenY; ++j){
			if(map.at(i,j)==key){
				x=i;
				y=j;
				return;
			}
		}
	}
}
///
///otvarq vratata za koqto e nameren klu4
///
void Path::openDoor(int door){
	size_t lenX= map.sizeX();
	size_t lenY = map.sizeY();
	for(size_t i= 0 ; i < lenX; ++i){
		for(size_t j=0; j < lenY; ++j){
			if(map.at(i,j)==(char)door){
				map.setAt(i,j,' ');
				return;
			}
		}
	}
}
///
///dobavq tekushtiq put kum ob6tiq put za labirinta
///
void Path::addPath(int startPos, int endPos){
	for(size_t i = startPos+1; i<endPos;++i){
		path.push_back(currentPath[i]);
	}
}

///
///printira putiq kato broi kolko poredni ednakvi hoda ima
///
void Path::printPath2(){
	if(finishedMap==maps.size()){
		size_t size=path.size();
		char* newPath = new char[size];

		initArray(newPath);//pulnq masiva s putq ot spisaka


		size_t counter=1;
		for(size_t i= 1 ; i < size; ++i){
			if(newPath[i-1]==newPath[i]){
				++counter;
			}
			if(newPath[i-1]!=newPath[i]){
				if(counter>1){
					std::cout<<counter<<newPath[i-1];
				}else{
					std::cout<<newPath[i-1];
				}


				counter=1;
			}
		}
		std::cout<<std::endl;
		delete [] newPath;
	}else{
		std::cout<<"Path not found\n";
	}

}
///
///printira putq kato kombira ako ima posledovatelni ednakvi dvoiki hodove
///
void Path::printPath3(){
	if(finishedMap==maps.size()){
		size_t size=path.size();
		char* newPath = new char[size];

		initArray(newPath);// Попълвам силволен низ с пътя от списъка с пътя

		 size_t counter=1;
		char* str= new char[2];
		str[0]=newPath[0];
		str[1]=newPath[1];
		for(size_t i= 2; i <size; ++i){
			if(str[0]==newPath[i-2] && str[1]==newPath[i-1]){
				++counter;
			}else{
				if(counter>1){
					std::cout<<counter<<"("<<str[0]<<str[1]<<")";
				}else{
					std::cout<<str[0];
				}
				str[0]= newPath[i-2];
				str[1]=newPath[i-1];
				counter=1;
			}
		}
		std::cout<<std::endl;
		delete [] newPath;
		delete[] str;
	}else{
		std::cout<<"Path not found\n";
	}

}
void Path::printPath4(){
	size_t size=path.size();
	char* newPath = new char[size];

	initArray(newPath);

	char* buffer= new char[size];
	size_t counter=1;
	size_t bufferCounter=0;
	for(size_t i= 1 ; i < size; ++i){
		if(newPath[i-1]==newPath[i]){
			++counter;
		}
		if(newPath[i-1]!=newPath[i]){
			if(counter>1){
				buffer[bufferCounter]= counter;
				++bufferCounter;
				buffer[bufferCounter]=newPath[i-1];
				++bufferCounter;
			}else{
				buffer[bufferCounter]=newPath[i-1];
				++bufferCounter;
			}


			counter=1;
		}
	}
	delete[] buffer;
	delete[] newPath;
}


///
///funkciq koqto populva char* s putq
///
void Path::initArray(char* array){
	size_t counter=0;
	for(std::list<char>::iterator it = this->path.begin();
					it!=this->path.end();++it){
			array[counter]= *it;
			++counter;
		}
}
Path::~Path(){
	delete [] this->currentPath;
}
