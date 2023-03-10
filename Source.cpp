#include"Header.h"

/*void DateTime::printDateTime(DateTime d) {
	cout << "Date: " << d.day << "/" << d.month << "/" << d.year << " " << d.hour << ":" << d.minute << ":" << d.second << endl;
}
*/

void Book::printBook() {
	cout << "ISBN: " << isbn << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Language: " << language << endl;
	cout << "Publish Year: " << publishedYear << endl;
	cout << "Price: " << price << endl;
	cout << "Stock level: " << stockLevel << endl;
	cout << "Input date: " << inputDate.getYear() << "-" << inputDate.getMonth() << "-" << inputDate.getDay() << endl;
}


void Utility::sortPrice(vector<Book>bookData,vector<Book>temp){
	
	for (int i = 0; i < bookData.size() - 1; i++)
	{
		for (int j = 0; j < bookData.size() - i - 2; j++)
		{
			if (temp[j].getPrice() > temp[j + 1].getPrice()) {
				swap(temp[j], temp[j + 1]);
			}
		}
	}
}
void Utility::sortTitle(vector<Book>bookData, vector<Book> temp){
	for (int i = 0; i < bookData.size() - 1; i++)
	{
		for (int j = 0; j < bookData.size() - i - 2; j++)
		{
			if (temp[j].getPrice() == temp[j + 1].getPrice() && temp[j].getTitle() > temp[j + 1].getTitle()) {
				swap(temp[j], temp[j + 1]);
			}
		}
	}
}



void BookStore::addBookToStore(Book book) {
	data.push_back(book);
}

void BookStore::loadBookStore(string fileName, string& nameStore) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Can't open the file " << fileName << "!" << endl;
		return;
	}
	getline(file, nameStore);
	cout << "Welcome to " << nameStore << "!" << endl;
	string tempLine;
	getline(file, tempLine);
	while (getline(file, tempLine)) {
		istringstream is(tempLine);
		string isbn, title, author, language, publishedYearStr, priceStr, stockLevelStr, yearStr, monthStr, dayStr;
		double price;
		int stockLevel, publishedYear,year,month,day;
		getline(is, isbn, ';');
		getline(is, title, ';');
		getline(is, author, ';');
		getline(is, language, ';');
		getline(is, publishedYearStr, ';');
		getline(is, priceStr, ';');
		getline(is, stockLevelStr, ';');
		getline(is, yearStr, '-');
		getline(is, monthStr, '-');
		getline(is, dayStr, '-');

		year = stoi(yearStr);
		month = stoi(monthStr);
		day = stoi(dayStr);
		publishedYear = stoi(publishedYearStr);
		price = stod(priceStr);
		stockLevel = stoi(stockLevelStr);
		Book book(isbn, title, author, language, publishedYear, stockLevel, price, year,month,day);
		addBookToStore(book);
	}
	file.close();
}

void Utility::showBooksWithCondition(vector<Book>book,int limitNumber) {
	
	for (int i = 0; i < limitNumber; i++)
	{
		Book elem = book.at(i);
		cout << "ISBN: " << elem.getISBN() << endl;
		cout << "Title: " << elem.getTitle() << endl;
		cout << "Author: " << elem.getAuthor() << endl;
		cout << "Language: " << elem.getLanguage() << endl;
		cout << "Published Year: " << elem.getPublishedYear() << endl;
		cout << "Price: " << elem.getPrice() << endl;
		cout << "Stock Level: " << elem.getStockLevel() << endl;
		cout << "Input Date: " << elem.getInputDate().getYear() << "-" << elem.getInputDate().getMonth() << "-" << elem.getInputDate().getDay() << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}

void Utility::showBooks(vector<Book>book) {
	int quantity = book.size();
	for (int i = 0; i < quantity; i++)
	{
		Book elem = book.at(i);
		cout << "ISBN: " << elem.getISBN() << endl;
		cout << "Title: " << elem.getTitle() << endl;
		cout << "Author: " << elem.getAuthor() << endl;
		cout << "Language: " << elem.getLanguage() << endl;
		cout << "Published Year: " << elem.getPublishedYear() << endl;
		cout << "Price: " << elem.getPrice() << endl;
		cout << "Stock Level: " << elem.getStockLevel() << endl;
		cout << "Input Date: " << elem.getInputDate().getYear() << "-" << elem.getInputDate().getMonth() << "-" << elem.getInputDate().getDay() << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}

void BookStore::showSortBooks() {
	vector<Book> temp;
	Utility util;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i]);
	}
	//Sap xep sach theo gia
	util.sortPrice(data, temp);

	//Sap xep sach theo ten
	util.sortTitle(data,temp);

	util.showBooks(temp);
}



void BookStore::showNewestBooks() {
	int size = this->data.size();
	vector<Book>filterDate;
	int maxYear = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (this->data[i].getInputDate().getYear() > maxYear) {
			maxYear = this->data[i].getInputDate().getYear();
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (this->data[i].getInputDate().getYear() == maxYear) {
			filterDate.push_back(this->data[i]);
		}
	}
	for (int i = 0; i < filterDate.size() - 1; i++) {

		for (int j = 0; j < filterDate.size() - i - 1; j++) {
			if (filterDate[j].getInputDate().getDay() < filterDate[j + 1].getInputDate().getDay()) {
				swap(filterDate[j], filterDate[j + 1]);
			}
		}
	}
	for (int i = 0; i < filterDate.size() - 1; i++) {

		for (int j = 0; j < filterDate.size() - i - 1; j++) {
			if (filterDate[j].getInputDate().getMonth() < filterDate[j + 1].getInputDate().getMonth()) {
				swap(filterDate[j], filterDate[j + 1]);
			}
		}
	}
	Utility util;
	util.showBooksWithCondition(filterDate,10);
};

void BookStore::addMoreBooks() {
	cin.ignore();
	int size = this->data.size();
	string isbn, title, author, language;
	double price;
	int stockLevel, publishedYear, year, month, day;
	DateTime currentTime;
	cout << "Add book option: Type all below information that is relevant to the book..." << endl;
	cout << "ISBN: ";
	getline(cin, isbn);
	while (isbn.size() != 13) {
		cout << "The ISBN has been typed is invalid. Make sure it includes 13 characters!" << endl;
		cout << "Retype ISBN: ";
		getline(cin, isbn);
	}
	for (int i = 0; i < size; i++)
	{
		if (data[i].getISBN() == isbn) {
			data[i].setIncreaseStockLevel();
			cout << "The book has already existent in this bookstore and has not been out of stock. Therefore, increase stock level of this book by 1." << endl;
			return;
		}
	}
	cout << "Title: ";
	getline(cin, title);
	cout << "Author: ";
	getline(cin, author);
	cout << "Language: ";
	getline(cin, language);
	cout << "Published Year: ";
	cin >> publishedYear;
	cout << "Price: ";
	cin >> price;
	currentTime.setCurrentTime();
	year = currentTime.getYear();
	month = currentTime.getMonth();
	day = currentTime.getDay();
	Book book(isbn, title, author, language, publishedYear, 1, price, year, month, day);
	this->data.push_back(book);
	cout << "Added new book to the store successfully!" << endl;
}

void BookStore::addToCart(vector<Book>&cartBook) {
	cin.ignore();
	string isbn;
	int size = this->data.size();
	cout << "Type ISBN that customer wants to purchase: ";
	getline(cin, isbn);
	cout << isbn << endl;
	for (int i = 0; i < size; i++)
	{
		if (this->data[i].getISBN() == isbn) {
			if(this->data[i].getStockLevel()>0){
				cartBook.push_back(data[i]);
				this->data[i].setDecreaseStockLevel();
				cout << "Added book to cart!" << endl;
			}
			else {
				cout << "This book is out of stock. Can't add to cart!" << endl;
			}
			return;
		}
	}
	cout << "The ISBN has been typed, is not existent in the BookStore." << endl;
}


void BookStore::purchaseBook(vector<Book>&booksFromCart) {
	int choose; 
	float totalMoney = 0;
	DateTime datePurchase;
	datePurchase.setCurrentTime();
	string customerName = "Anonymous";
	string fileName;
	string convert;

	//Tách cái ngày mua thành nhiều thành phần để đặt tên file
	convert = to_string(datePurchase.getYear());
	fileName = fileName + convert + "-";
	convert = to_string(datePurchase.getMonth());
	fileName = fileName + convert + "-";
	convert = to_string(datePurchase.getDay());
	fileName = fileName + convert + " ";
	convert = to_string(datePurchase.getHour());
	fileName = fileName + convert + "-";
	convert = to_string(datePurchase.getMinute());
	fileName = fileName + convert + "-";
	convert = to_string(datePurchase.getSecond());
	fileName = fileName + convert + ".txt";
	//à mà chắc không cần đâu thầy :> These above code is for decoration :))
	cout << fileName;
	cout << "Finish adding books to cart and Generate a bill for purchasing?" << endl;
	cout << "Type 0 to No or 1 to Yes." << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		return;
	case 1:
		if (booksFromCart.size() == 0) {
			cout << "No book to purchase! Please add books that need selling first." << endl;
			return;
		}
		else {
			string fileName = "bills.txt";
			ifstream inFile(fileName);
			string content((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
			// Đóng file
			inFile.close();
			// Mở file lại để ghi nội dung mới vào đầu file
			ofstream outFile(fileName, ios::out | ios::trunc);
			if (outFile.is_open()) {
				// Ghi nội dung mới vào đầu file
				cin.ignore();
				cout << "Customer's name: ";
				getline(cin, customerName);
				outFile << "-----------------------------------------------------------------------" << endl;
				outFile << "PURCHASED BOOKS BILL" << endl;
				outFile << endl;
				outFile << endl;
				outFile << "Customer: " << customerName << endl;
				outFile << "Purchase Date: " << datePurchase.getYear() << "-" << datePurchase.getMonth() << "-" << datePurchase.getDay() << " " << datePurchase.getHour() << ":" << datePurchase.getMinute() << ":" << datePurchase.getSecond() << endl;
				outFile << "Total books: " << booksFromCart.size() << endl;

				for (int i = 0; i < booksFromCart.size(); i++)
				{
					outFile << "Book " << i + 1 << ":" << endl;
					outFile << "ISBN: " << booksFromCart[i].getISBN() << endl;
					outFile << "Title: " << booksFromCart[i].getTitle() << endl;
					outFile << "Author: " << booksFromCart[i].getAuthor() << endl;
					outFile << "Language: " << booksFromCart[i].getLanguage() << endl;
					outFile << "Publish Year: " << booksFromCart[i].getPublishedYear() << endl;
					outFile << "Price: " << booksFromCart[i].getPrice() << endl;
					outFile << "Input date: " << booksFromCart[i].getInputDate().getYear() << "-" << booksFromCart[i].getInputDate().getMonth() << "-" << booksFromCart[i].getInputDate().getDay() << endl;
					totalMoney = totalMoney + booksFromCart[i].getPrice();
					outFile << endl;
				}

				outFile << "Total money: " << totalMoney << "$" << endl;
				outFile << "-----------------------------------------------------------------------" << endl;
				booksFromCart.clear();
				cout << endl;
				cout << endl;
				cout << endl;
				outFile << content; // Ghi lại nội dung cũ vào sau nội dung mới
				outFile.close(); // Đóng file
				outFile.close();
			/*ofstream outFile("orders.txt", ios::app | ios::ate);
			if (outFile.is_open()) {
				cin.ignore();
				cout << "Customer's name: ";
				getline(cin, customerName);
				outFile.seekp(0);
				outFile << "-----------------------------------------------------------------------" << endl;
				outFile << "PURCHASED BOOKS BILL" << endl;
				outFile << endl;
				outFile << endl;
				outFile << "Customer: " << customerName << endl;
				outFile << "Purchase Date: " << datePurchase.getYear() << "-" << datePurchase.getMonth() << "-" << datePurchase.getDay() << " " << datePurchase.getHour() << ":" << datePurchase.getMinute() << ":" << datePurchase.getSecond() << endl;
				outFile << "Total books: " << booksFromCart.size() << endl;
				
				for (int i = 0; i < booksFromCart.size(); i++)
				{
					outFile << "Book " << i + 1 << ":" << endl;
					outFile << "ISBN: " << booksFromCart[i].getISBN() << endl;
					outFile << "Title: " << booksFromCart[i].getTitle() << endl;
					outFile << "Author: " << booksFromCart[i].getAuthor() << endl;
					outFile << "Language: " << booksFromCart[i].getLanguage() << endl;
					outFile << "Publish Year: " << booksFromCart[i].getPublishedYear() << endl;
					outFile << "Price: " << booksFromCart[i].getPrice() << endl;
					outFile << "Input date: " << booksFromCart[i].getInputDate().getYear() << "-" << booksFromCart[i].getInputDate().getMonth() << "-" << booksFromCart[i].getInputDate().getDay() << endl;
					totalMoney = totalMoney + booksFromCart[i].getPrice();
					outFile << endl;
				}
				
				outFile << "Total money: " << totalMoney << "$" << endl;
				outFile << "-----------------------------------------------------------------------" << endl;
				booksFromCart.clear();
				cout << endl;
				cout << endl;
				cout << endl;
				
				outFile.close();*/
			}
			else {
				cout << "Error: Could not open file" << endl;
			}
		}
		cout << "Export bill successfully! Recheck all paid stuff please!" << endl;
		break;
	default:
		cout << "Invaid choice! Only type 0 or 1." << endl;
		break;
	}
}


void BookStore::showStock() {
	
	int size = this->data.size();
	if (this->data.size() == 0) {
		cout << "There is no book to show!" << endl;
		return;
	}
	cout << "LOW STOCK BOOKS: " << endl;
	cout << endl;
	for (int i = 0; i <size ; i++)
	{
		if (this->data[i].getStockLevel() < 50) {
			this->data[i].printBook();
			cout << "-----------------------------------------------------------------------" << endl;
		}
	}
}

void BookStore::saveBeforeExit(string nameStore) {
	
	int size = this->data.size();
	ofstream outFile("booklist.txt", ios::out | ios::trunc);
	if (outFile.is_open()) {
		outFile << nameStore << endl;
		for (int i = 0; i < size; i++) {
			outFile << this->data[i].getISBN() << ";" << this->data[i].getTitle() << ";" << this->data[i].getAuthor() << ";" << this->data[i].getLanguage() << ";" << this->data[i].getPublishedYear() << ";" << this->data[i].getPrice() <<";"<< this->data[i].getStockLevel()<< ";"<< this->data[i].getInputDate().getYear()<<"-"<< this->data[i].getInputDate().getMonth()<<"-"<< this->data[i].getInputDate().getDay() << endl;
		}
		outFile.close();
	}
}

int main() {
	vector<Book> origin, booksFromCart;
	BookStore bookStore;
	Utility util;
	string nameStore;
	int choice;
	bookStore.loadBookStore("booklist.txt", nameStore);
	cout << "Choose your option below: " << endl;
	do {
		cout << "Choose an option: " << endl;
		cout << "1. Sort books by price" << endl;
		cout << "2. View newest books" << endl;
		cout << "3. Add a book" << endl;
		cout << "4. Sell a book" << endl;
		cout << "5. Checkout and save bill" << endl;
		cout << "6. View low stock books" << endl;
		cout << "7. Clear screen" << endl;
		cout << "0. Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			bookStore.showSortBooks();
			cout << endl;
			break;
		case 2:
			bookStore.showNewestBooks();
			cout << endl;
			break;
		case 3:
			bookStore.addMoreBooks();
			cout << endl;
			break;
		case 4:
			bookStore.addToCart(booksFromCart);
			cout << endl;
			break;
		case 5:
			bookStore.purchaseBook(booksFromCart);
			cout << endl;
			break;
		case 6:
			bookStore.showStock();
			cout << endl;
			break;
		case 7:
			system("cls");
			cout << endl;
			break;
		case 0:
			cout << "Goodbye!"<<endl;
			bookStore.saveBeforeExit(nameStore);
			break;
		default:
			cout << "Invalid choice. Please choose again.";
			cout << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}