#include "clothing.h"
#include "util.h"


Clothes::Clothes(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size) : 
Product(category, name, price, qty){
    brand_ = brand;
    size_ = size;
}

Clothes::~Clothes(){
    
}

std::set<std::string> Clothes::keywords() const{
  std::set<std::string> names = parseStringToWords(name_);
  std::set<std::string> auths = parseStringToWords(size_);

  std::set<std::string> result = setUnion(names, auths);

  result.insert(brand_);

  return result;
}

std::string Clothes::displayString() const{
    std::string info = name_;
    info += "\nSize: "+ size_ + " Brand: " + brand_;
    info += "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return info;
}

void Clothes::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}

bool Clothes::isMatch(std::vector<std::string>& searchTerms) const{
    return true;
}