#pragma once

class Door{
public:
	Door(char key, char doorNumber);
	Door();
	char getKey()const ;
	char getDoorNumber()const;
	void setKey(char key);
	void setDoorNumber(char door);

private:
	char key;
	char doorNumber;

};
