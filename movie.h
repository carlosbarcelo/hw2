#include "product.h"

class Movie: public Product{
public:
  Movie(const std::string category, const std::string name, double price, int qty, const std::string rating, const std::string genre); 

  ~Movie();

  std::set<std::string> keywords() const;

  bool isMatch(std::vector<std::string>& searchTerms) const;

  std::string displayString() const;

  void dump(std::ostream& os) const;

private:
  std::string rating_;
  std::string genre_;
};