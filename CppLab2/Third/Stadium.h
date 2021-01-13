#pragma once

class Stadium
{
public:	
	static int cnt;
	//==================== constructors / destructor ====================
	
	Stadium();
	Stadium(std::string footballClub, std::string address,  int sectorsNum, int capacity, int attendance);
	Stadium(const Stadium& s);
	Stadium& operator=(Stadium s);
	void swap(Stadium s);
	~Stadium();

	//==================== setters / getters ====================

	void set(std::string footballClub, std::string address, int sectorsNum, int capacity, int attendance);
	void setAddress(std::string address);
	void setClub(std::string footballClub);
	void setSectorsNum(int sectorsNum);
	void setCapacity(float capacity);
	void setAttendance(float attendance);
	void setAvgPerc(float avgPerc);
	std::string getAddress() const;
	std::string getClub() const;
	int getSectorsNum() const;
	float getCapacity() const;
	float getAttendance() const;
	float getAvgPerc() const;

	//==================== other functions ====================

	void print();
	void serialize();
	void serialize(const std::string& filename);
	void deserialize();
	void deserialize(const std::string& filename);
	static void sort(Stadium** arr, int size);

	//==================== variables ====================
private:
	std::string address_;
	std::string footballClub_;
	int sectorsNum_;
	float capacity_, attendance_, avgPerc_;
};