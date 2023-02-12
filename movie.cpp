#include "movie.h"
#include "util.h"


Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre) : 
Product(category, name, price, qty){
    rating_ = rating;
    genre_ = genre;
}

Movie::~Movie(){
    
}

std::set<std::string> Movie::keywords() const{
  std::set<std::string> names = parseStringToWords(name_);
  std::set<std::string> auths = parseStringToWords(genre_);

  std::set<std::string> result = setUnion(names, auths);

  result.insert(rating_);

  return result;
}

std::string Movie::displayString() const{
    std::string info = name_;
    info += "\nGenre: "+ genre_ + " Rating: " + rating_;
    info += "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

    return info;
}

void Movie::dump(std::ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
    return true;
}