#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <vector>
#include <msclr/marshal.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

struct Train
{
	int flightNumber;
	std::string arrivalTime;
	std::string departureTime;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string conditionOfTheTrain;
	int trackNumber;
};

std::string FirstPart(std::string one);
std::string SecondPart(std::string one);
bool isCorrectTime(std::string one, std::string two);
void writeData(Train train);
int init();
void readFromFile(Train train);
void  changeDataInFile(int track);
void deleteFromFile(int flight);
void readForChange(Train &train);
std::vector<Train> readAll();
bool isBusyTrack(int track);
bool isCorrectTrack(int track);
bool isBusyFlight(int flight);

std::string String_to_string(System::String^ s); 
System::String^ string_to_String(std::string s);