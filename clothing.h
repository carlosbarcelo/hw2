#include "product.h"

class Clothes: public Product{
public:
  Clothes(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size); 

  ~Clothes();

  std::set<std::string> keywords() const;

  bool isMatch(std::vector<std::string>& searchTerms) const;

  std::string displayString() const;

  void dump(std::ostream& os) const;

private:
  std::string brand_;
  std::string size_;
};