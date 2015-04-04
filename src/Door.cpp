#include "Door.h"

Door::Door(char key, char doorNumber){
	this-> key=key;
	this->doorNumber=doorNumber;
}
Door::Door(){
	this-> key=' ';
	this->doorNumber=' ';
}
char Door::getKey()const{
	return this->key;
}

char Door::getDoorNumber()const {
	return this->doorNumber;
}
