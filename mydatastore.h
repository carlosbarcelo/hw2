#include "datastore.h"
#include <map>

class MyDataStore: public DataStore{
  public:
    MyDataStore();
    ~MyDataStore();

    void addUser(User* u);

    void addProduct(Product* p);
    
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void dump(std::ostream& ofile);

    std::map<std::string, Product*> prods_;
    std::map<std::string, User*> users_;
};