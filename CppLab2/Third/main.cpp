/*
Написать собственный класс, в соответствии с вариантом.
Продемонстрировать в коде инкапсуляцию данных,
применение конструкторов без параметров и с параметрами для инициализации данных.
Класс должен содержать метод serialize() для сохранения данных класса в файл
и метод deserialize() для чтения данных класса из файла по умолчанию в текущей директории,
а также перегруженные методы serialize(const std::string& filename)
и deserialize(const std::string& filename) для работы с файлом с указанным в параметре именем.

Класс СТАДИОН.
Данные: адрес, футбольный клуб, количество секторов, вместимость, посещаемость.
Создать 2 стадиона в куче и один в стеке. Установить данные первых двух с помощью
сеттеров, данные третьего установить в конструкторе с параметрами.
В главной функции проимитировать четыре матча – случайным образом сформировать
количество пришедших посетителей и просчитать процент заполнения каждого стадиона.
Вывести информацию о стадионах, отсортировав их в порядке убывания среднего процента заполнения за четыре матча.
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include "Stadium.h"

void main()
{
	Stadium* s1 = new Stadium();
	s1->setClub("Shakhtar");
	s1->setAddress("2 Chelyuskintsev street");
	s1->setSectorsNum(4);
	s1->setCapacity(100000);
	s1->setAttendance(84029);

	Stadium* s2 = new Stadium();
	s2->set("RSK Olympic", "133 Artyoma street", 3, 35000, 29350);

	Stadium s3("Metallurg", "56 Kirova street", 2, 17000, 12601);

	s2->print();

	s1->serialize();
	s2->serialize();
	s3.serialize();
	s3.serialize("META");

	s1->deserialize();
	s2->deserialize();
	s3.deserialize();
	s3.deserialize("META");

	//======================== Simulation ========================

	srand((unsigned int)time(NULL));

	// The first match
	float fillPercentage1_1, fillPercentage2_1, fillPercentage3_1;
	s1->setAttendance((int)(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s2->setAttendance((int)(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s3.setAttendance((int)(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	fillPercentage1_1 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_1 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_1 = s3.getAttendance() / s3.getCapacity();

	// The second match
	float fillPercentage1_2, fillPercentage2_2, fillPercentage3_2;
	s1->setAttendance((int)(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s2->setAttendance((int)(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s3.setAttendance((int)(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	fillPercentage1_2 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_2 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_2 = s3.getAttendance() / s3.getCapacity();

	// The third match
	float fillPercentage1_3, fillPercentage2_3, fillPercentage3_3;
	s1->setAttendance((int)(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s2->setAttendance((int)(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s3.setAttendance((int)(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	fillPercentage1_3 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_3 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_3 = s3.getAttendance() / s3.getCapacity();

	// The fourth match
	float fillPercentage1_4, fillPercentage2_4, fillPercentage3_4;
	s1->setAttendance((int)(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s2->setAttendance((int)(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	s3.setAttendance((int)(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0));
	fillPercentage1_4 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_4 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_4 = s3.getAttendance() / s3.getCapacity();

	//calc avg percentages
	float avgPerc1 = (fillPercentage1_1 + fillPercentage1_2 + fillPercentage1_3 + fillPercentage1_4) / 4;
	float avgPerc2 = (fillPercentage2_1 + fillPercentage2_2 + fillPercentage2_3 + fillPercentage2_4) / 4;
	float avgPerc3 = (fillPercentage3_1 + fillPercentage3_2 + fillPercentage3_3 + fillPercentage3_4) / 4;

	s1->setAvgPerc(avgPerc1);
	s2->setAvgPerc(avgPerc2);
	s3.setAvgPerc(avgPerc3);

	//sorting avg percentages
	Stadium* arr[3];
	arr[0] = s1;
	arr[1] = s2;
	arr[2] = &s3;

	std::cout << s1->getAvgPerc() << ", " << s2->getAvgPerc() << ", " << s3.getAvgPerc() << std::endl;
	std::cout << arr[0]->getAvgPerc() << ", " << arr[1]->getAvgPerc() << ", " << arr[2]->getAvgPerc() << std::endl;
	std::cout << Stadium::cnt << std::endl;

	Stadium::sort(arr, 3);

	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
	}

	std::cout << s1->getAvgPerc() << ", " << s2->getAvgPerc() << ", " << s3.getAvgPerc() << std::endl;
	std::cout << arr[0]->getAvgPerc() << ", " << arr[1]->getAvgPerc() << ", " << arr[2]->getAvgPerc() << std::endl;
	std::cout << Stadium::cnt << std::endl;

	s1->~Stadium();
	s2->~Stadium();
}