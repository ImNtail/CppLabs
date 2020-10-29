#pragma once

class Stadium
{
	static int cnt;
public:
	//==================== constructors / destructor ====================
	
	Stadium();
	Stadium(std::string footballClub, std::string address,  int sectorsNum, int capacity, int attendance);
	Stadium(const Stadium& s);
	Stadium& operator=(Stadium s);
	void swap(Stadium s);
	~Stadium();

	//==================== setters / getters ====================

	void set( std::string footballClub, std::string address, int sectorsNum, int capacity, int attendance);
	void setAddress(std::string address);
	void setClub(std::string footballClub);
	void setSectorsNum(int sectorsNum);
	void setCapacity(int capacity);
	void setAttendance(int attendance);
	std::string getAddress() const;
	std::string getClub() const;
	int getSectorsNum() const;
	int getCapacity() const;
	int getAttendance() const;

	//==================== other functions ====================

	void print();
	void serialize();
	void serialize(const std::string& filename);
	void deserialize();
	void deserialize(const std::string& filename);

	//==================== variables ====================
private:
	std::string address_;
	std::string footballClub_;
	int sectorsNum_, capacity_, attendance_;
};