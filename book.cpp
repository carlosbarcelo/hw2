#include "book.h"
#include "util.h"


Book::Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author) : 
Product(category, name, price, qty){
    ISBN_ = ISBN;
    author_ = author;
}

Book::~Book(){
    
}

std::set<std::string> Book::keywords() const{
  std::set<std::string> names = parseStringToWords(name_);
  std::set<std::string> auths = parseStringToWords(author_);

  std::set<std::string> result = setUnion(names, auths);

  result.insert(ISBN_);

  return result;
}

std::string Book::displayString() const{
    std::string info = name_;
    info += "\nAuthor: "+ author_ + " ISBN: " + ISBN_;
    info += "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return info;
}

void Book::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << std::endl;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
return true;
}
