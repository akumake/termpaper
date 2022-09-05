#include "Functions.h"

Train buff;


std::string FirstPart(std::string one)
{
	std::string buff;
	int i = 0;
	while (one[i] != ':')
	{
		buff.append(one, i, 1);
		i++;
	}

	return buff;
}

std::string SecondPart(std::string one)
{
	std::string buff;

	for (size_t i = FirstPart(one).size() + 1; i < one.size(); i++)
		buff.append(one, i, 1);

	return buff;
}

bool isCorrectTime(std::string one, std::string two)
{

	bool isFlag = true;

	if (atoi(FirstPart(one).c_str()) != 23 && atoi(FirstPart(two).c_str()) != 0)
	{
		if (atoi(FirstPart(one).c_str()) < atoi(FirstPart(two).c_str()))
			return isFlag;
		else
			if (atoi(SecondPart(one).c_str()) < atoi(SecondPart(two).c_str()))
				return isFlag;

		return !isFlag;
	}

	return isFlag;
}

void writeData(Train train)
{
	std::fstream f;

	f.open("termpaper.dat", std::ios::binary | std::ios::app);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		return;
	}
	else
	{

		size_t len;
		f.write((char*)&train.trackNumber, sizeof(int));
		f.write((char*)&train.flightNumber, sizeof(int));

		len = train.departureTime.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(train.departureTime.data(), len);

		len = train.arrivalTime.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(train.arrivalTime.data(), len);

		len = train.conditionOfTheTrain.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(train.conditionOfTheTrain.data(), len);

		len = train.placeOfArrival.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(train.placeOfArrival.data(), len);

		len = train.placeOfDeparture.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(train.placeOfDeparture.data(), len);

	}
	f.close();
}

int init()
{
	std::fstream f;
	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		std::cout << "Error occured while opening file" << std::endl;
		return 0;
	}

	Train train;

	int numOfElements = 0;

	

	while (f.read((char*)&train.trackNumber, sizeof(int)))
	{
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		numOfElements++;

		delete[] buff;
	}

	
	return numOfElements;

}

void readFromFile(Train train)
{
	std::fstream f;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		return;
	}

	if (init() == 0)
	{
		MessageBox::Show("There are no records yet");
		return;
	}



	while (f.read((char*)&train.trackNumber, sizeof(int)))
	{
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		delete[] buff;
	}



	f.close();
}

void  changeDataInFile(int track)
{
	std::fstream f,f1;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		return;
	}

	Train train;
	int num, num1;
	num = init();
	num1 = init();
	std::vector<Train> v;


	for (size_t i = 0; i < num; i++)
	{
		f.read((char*)&train.trackNumber, sizeof(int));
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		v.push_back(train);
		delete[] buff;
	}



	f.close();

	f.open("termpaper.dat", std::ios::binary | std::ios::out);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file"); 
		return;
	}

	

	for (int i = 0; i < num1; i++)
		if (track == v[i].trackNumber)
		{
			for (size_t j = i; j < num1 - 1; j++)
				std::swap(v[j], v[j + 1]);
			num1--;
		}


	for (size_t i = 0; i < num - 1; i++)
	{
		
			size_t len;
			f.write((char*)&v[i].trackNumber, sizeof(int));
			f.write((char*)&v[i].flightNumber, sizeof(int));

			len = v[i].departureTime.length();
			f.write((char*)&len, sizeof(size_t));
			f.write(v[i].departureTime.data(), len);

			len = v[i].arrivalTime.length();
			f.write((char*)&len, sizeof(size_t));
			f.write(v[i].arrivalTime.data(), len);

			len = v[i].conditionOfTheTrain.length();
			f.write((char*)&len, sizeof(size_t));
			f.write(v[i].conditionOfTheTrain.data(), len);

			len = v[i].placeOfArrival.length();
			f.write((char*)&len, sizeof(size_t));
			f.write(v[i].placeOfArrival.data(), len);

			len = v[i].placeOfDeparture.length();
			f.write((char*)&len, sizeof(size_t));
			f.write(v[i].placeOfDeparture.data(), len);
	}
	
	f.close();

	f1.open("buff.dat", std::ios::binary | std::ios::out);

	if (!f1.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		return;
	}

	size_t len;
	f1.write((char*)&v[num - 1].trackNumber, sizeof(unsigned int));
	f1.write((char*)&v[num - 1].flightNumber, sizeof(unsigned int));

	len = v[num - 1].departureTime.length();
	f1.write((char*)&len, sizeof(size_t));
	f1.write(v[num - 1].departureTime.data(), len);

	len = v[num - 1].arrivalTime.length();
	f1.write((char*)&len, sizeof(size_t));
	f1.write(v[num - 1].arrivalTime.data(), len);

	len = v[num - 1].conditionOfTheTrain.length();
	f1.write((char*)&len, sizeof(size_t));
	f1.write(v[num - 1].conditionOfTheTrain.data(), len);

	len = v[num - 1].placeOfArrival.length();
	f1.write((char*)&len, sizeof(size_t));
	f1.write(v[num - 1].placeOfArrival.data(), len);

	len = v[num - 1].placeOfDeparture.length();
	f1.write((char*)&len, sizeof(size_t));
	f1.write(v[num - 1].placeOfDeparture.data(), len);

	f1.close();

}


void readForChange(Train &train)
{
	std::fstream f;

	f.open("buff.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		return;
	}
	else
	{

		f.read((char*)&train.trackNumber, sizeof(int));
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		delete[] buff;
	}

	f.close();
}

void deleteFromFile(int flight)
{
	std::fstream f;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
	
		return;
	}

	Train* v;
	Train train;
	v = new Train[init()];

	int  i = 0;

	while (f.read((char*)&train.trackNumber, sizeof(int)))
	{
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		v[i] = train;

		i++;
	}

	f.close();


	int b = init();
	for (int i = 0; i < b; i++)
		if (flight == v[i].flightNumber)
		{
			for (size_t j = i; j < b - 1; j++)
				std::swap(v[j], v[j + 1]);
			b--;
			MessageBox::Show("Element was delete");
		}

	f.open("termpaper.dat", std::ios::binary | std::ios::out);

	if (!f.is_open())
	{
		std::cout << "Error occured while opening file" <<std::endl;
		return;
	}

	for (size_t i = 0; i < b; i++)
	{
		size_t len;
		f.write((char*)&v[i].trackNumber, sizeof(unsigned int));
		f.write((char*)&v[i].flightNumber, sizeof(unsigned int));

		len = v[i].departureTime.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(v[i].departureTime.data(), len);

		len = v[i].arrivalTime.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(v[i].arrivalTime.data(), len);

		len = v[i].conditionOfTheTrain.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(v[i].conditionOfTheTrain.data(), len);

		len = v[i].placeOfArrival.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(v[i].placeOfArrival.data(), len);

		len = v[i].placeOfDeparture.length();
		f.write((char*)&len, sizeof(size_t));
		f.write(v[i].placeOfDeparture.data(), len);

	}

	f.close();

	delete[] v;
}




std::vector<Train> readAll()
{
	std::fstream f;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
	
	}

	if (init() == 0)
	{
		MessageBox::Show("There are no records yet");
	}

	Train train;
	std::vector<Train> v;

	while (f.read((char*)&train.trackNumber, sizeof(unsigned int)))
	{
		f.read((char*)&train.flightNumber, sizeof(unsigned int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		delete[] buff;

		v.push_back(train);
	}



	f.close();

	return v;
}



bool isCorrectTrack(int track)
{
	bool isFlag = true;

	if (track < 0 || track > 13)
		return isFlag;
}

bool isBusyTrack(int track)
{
	std::fstream f;

	bool isFlag = true;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");
		
	}

	Train train;
	
	std::vector<Train> v;


	for (size_t i = 0; i < init(); i++)
	{
		f.read((char*)&train.trackNumber, sizeof(int));
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		v.push_back(train);
		delete[] buff;
	}


	for (size_t i = 0; i < init(); i++)
		if (track == v[i].trackNumber)
			return isFlag;



	return !isFlag;
}


bool isBusyFlight(int flight)
{
	std::fstream f;

	bool isFlag = true;

	f.open("termpaper.dat", std::ios::binary | std::ios::in);

	if (!f.is_open())
	{
		MessageBox::Show("Error occured while opening file");

	}

	Train train;

	std::vector<Train> v;


	for (size_t i = 0; i < init(); i++)
	{
		f.read((char*)&train.trackNumber, sizeof(int));
		f.read((char*)&train.flightNumber, sizeof(int));

		size_t len;
		char* buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.departureTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.arrivalTime = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.conditionOfTheTrain = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfArrival = buff;

		f.read((char*)&len, sizeof(size_t));
		buff = new char[len + 1];
		f.read(buff, len);
		buff[len] = 0;
		train.placeOfDeparture = buff;

		v.push_back(train);
		delete[] buff;
	}


	for (size_t i = 0; i < init(); i++)
		if (flight == v[i].flightNumber)
			return isFlag;



	return !isFlag;
}

std::string String_to_string(System::String^ s)
{
	marshal_context^ marshal = gcnew marshal_context();
	const char* native = marshal->marshal_as<const char*>(s);
	delete s;

	return native;
}


System::String^ string_to_String(std::string s)
{
	System::String^ str = gcnew String(s.c_str());

	return str;
}



