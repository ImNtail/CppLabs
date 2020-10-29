/*
�������� ����������� �����, � ������������ � ���������.
������������������ � ���� ������������ ������,
���������� ������������� ��� ���������� � � ����������� ��� ������������� ������.
����� ������ ��������� ����� serialize() ��� ���������� ������ ������ � ����
� ����� deserialize() ��� ������ ������ ������ �� ����� �� ��������� � ������� ����������,
� ����� ������������� ������ serialize(const std::string& filename)
� deserialize(const std::string& filename) ��� ������ � ������ � ��������� � ��������� ������.

����� �������.
������: �����, ���������� ����, ���������� ��������, �����������, ������������.
������� 2 �������� � ���� � ���� � �����. ���������� ������ ������ ���� � �������
��������, ������ �������� ���������� � ������������ � �����������.
� ������� ������� �������������� ������ ����� � ��������� ������� ������������
���������� ��������� ����������� � ���������� ������� ���������� ������� ��������.
������� ���������� � ���������, ������������ �� � ������� �������� �������� �������� ���������� �� ������ �����.
*/

#include <iostream>
#include <fstream>
#include <ctime>
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
	int fillPercentage1_1, fillPercentage2_1, fillPercentage3_1;
	s1->setAttendance(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s2->setAttendance(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s3.setAttendance(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	fillPercentage1_1 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_1 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_1 = s3.getAttendance() / s3.getCapacity();

	// The second match
	int fillPercentage1_2, fillPercentage2_2, fillPercentage3_2;
	s1->setAttendance(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s2->setAttendance(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s3.setAttendance(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	fillPercentage1_2 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_2 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_2 = s3.getAttendance() / s3.getCapacity();

	// The third match
	int fillPercentage1_3, fillPercentage2_3, fillPercentage3_3;
	s1->setAttendance(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s2->setAttendance(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s3.setAttendance(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	fillPercentage1_3 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_3 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_3 = s3.getAttendance() / s3.getCapacity();

	// The fouth match
	int fillPercentage1_4, fillPercentage2_4, fillPercentage3_4;
	s1->setAttendance(((s1->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s2->setAttendance(((s2->getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	s3.setAttendance(((s3.getCapacity() - 0) * ((float)rand() / RAND_MAX)) + 0);
	fillPercentage1_4 = s1->getAttendance() / s1->getCapacity();
	fillPercentage2_4 = s2->getAttendance() / s2->getCapacity();
	fillPercentage3_4 = s3.getAttendance() / s3.getCapacity();

	int avgPerc1 = (fillPercentage1_1 + fillPercentage1_2 + fillPercentage1_3 + fillPercentage1_4) / 3;
	int avgPerc2 = (fillPercentage2_1 + fillPercentage2_2 + fillPercentage2_3 + fillPercentage2_4) / 3;
	int avgPerc3 = (fillPercentage3_1 + fillPercentage3_2 + fillPercentage3_3 + fillPercentage3_4) / 3;


}