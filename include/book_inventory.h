#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

struct Book
{
  std::string title;          // title of the book
  std::string author;         // author of the book
  float cost;                 // cost of the book
  std::string isbn;           // a unique string assigned to each book
  std::string language_code;  // language of the book
  int num_pages;              // number of pages
  std::string publisher;      // publisher of the book
  int count;                  // how many books left in the inventory
};

using Books = std::vector<Book>;

namespace book {
Books read_database(std::string );
std::string search(Books , std::string );
bool order(Books& , Books& , std::string );
double get_receipt(Books );
}