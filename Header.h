#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include <sstream>
#include<cstring>

using namespace std;



class DateTime {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public: 
	//constructor
	DateTime() {};	//default - mặc định
	DateTime(int y, int m, int d, int h, int min, int sec); //parameters - tham số
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	int getHour() {
		return hour;
	}
	int getMinute() {
		return minute;
	}
	int getSecond() {
		return second;
	}

	//Hàm set time theo thời gian hiện tại của máy
	void setCurrentTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		year = 1900 + ltm->tm_year;
		month = 1 + ltm->tm_mon;
		day = ltm->tm_mday;
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		second = ltm->tm_sec;
	}
	void setYear(int year) {
		this->year = year;
	}
	void setMonth(int month) {
		this->month = month;
	}
	void setDay(int day) {
		this->day = day;
	}
};

class Book {
private:
	string isbn;
	string title; 
	string author; 
	string language;
	int publishedYear; 
	int stockLevel;
	double price;
	DateTime inputDate;
public:
	//constructor tham số nè``
	Book(string isbn, string title, string author, string language, int publishedYear, int stockLevel, double price, int year,int month,int day) {
		this->isbn = isbn;
		this->title = title;
		this->author = author;
		this->language = language;
		this->publishedYear = publishedYear;
		this->stockLevel = stockLevel;
		this->price = price;
		this->inputDate.setYear(year);
		this->inputDate.setMonth(month);
		this->inputDate.setDay(day);
	}
	string getISBN() {
		return isbn;
	};
	string getTitle() {
		return title;
	};
	string getAuthor() {
		return author;
	};
	string getLanguage() {
		return language;
	};
	int getPublishedYear() {
		return publishedYear;
	};
	double getPrice() {
		return price;
	};
	int getStockLevel() {
		return stockLevel;
	};
	DateTime getInputDate() {
		return inputDate;
	};
	void printBook();
	//Tăng lượng sách đang có của một sách
	void setIncreaseStockLevel() {
		stockLevel++;
	};
	//giảm lượng sách đang có của một sách
	void setDecreaseStockLevel() {
		stockLevel--;
	};
	void setInputDate(DateTime id);
};

class BookStore {
private:
	string name;
	vector<Book> data;
public:
	vector<Book> getBookVector() {
		return this->data;
	}
	
	void addBookToStore(Book book);							//Thêm sách vào kho
	void loadBookStore(string fileName, string& nameStore);	//Load nhà sách có sẵn
	void showSortBooks();									//Sắp xếp sách theo giá và tên
	void showNewestBooks();									//Sắp xếp sách mới nhất tính theo ngày nhập InputDate
	void addMoreBooks();									//Hmmmmmm
	void addToCart(vector<Book>&cartBook);					//Thêm sách vào giỏ hàng...giàu ghê :)))
	void purchaseBook(vector<Book>&booksFromCart);			//Thanh toán sách...here is my visa!!
	void showStock();										//Kiểm tra hàng còn không?
	void saveBeforeExit(string nameStore);					//Lưu dữ liệu vào file sau các xử lí(những lần sử dụng các chức năng)
};

//Hàm tiện ích
class Utility {
public:
	//Sắp xếp theo giá vector các sách (ít -> nhiều)
	void sortPrice(vector<Book>bookData, vector<Book> temp);
	//Sắp xếp tên sách vector các sách (A -> Z)
	void sortTitle(vector<Book>bookData, vector<Book> temp);
	//In danh sách các sách với số lượng tự cho
	void showBooksWithCondition(vector<Book>book, int limitNumber);
	//In toàn bộ sách của vector chứa chúng
	void showBooks(vector<Book>book);
};