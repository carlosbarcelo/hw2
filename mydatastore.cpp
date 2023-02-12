#include "mydatastore.h"

MyDataStore::MyDataStore(){
  
}

MyDataStore::~MyDataStore(){
  
}

void MyDataStore::addUser(User* u){
  users_.insert(std::make_pair(u->getName(), u));
}

void MyDataStore::addProduct(Product* p){
  for(std::set<std::string>::iterator it = p->keywords().begin(); it != p->keywords().end(); it ++){
    prods_.insert(std::make_pair(*it, p));
  }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  std::vector<Product*> found;
  if(type == 1){
  for(size_t i = 0; i < terms.size(); i++){
    std::map<std::string, Product*>::iterator it = prods_.find(terms[i]);
    if (it != prods_.end()){
      found.push_back(it->second);
    }
  }
  return found;
  }
  else{
  bool allfound = true;
  for(size_t i = 0; i < terms.size() && allfound; i++){
    std::map<std::string, Product*>::iterator it = prods_.find(terms[i]);
    if (it != prods_.end()){
      allfound = true;
      if(i == terms.size()-1) found.push_back(it->second);
    }
    else{
      allfound = false;
    }
  }
  return found;
  }
}

void MyDataStore::dump(std::ostream& ofile){
  std::map<std::string, Product*>::iterator it;
  for(it = prods_.begin(); it != prods_.end(); it++){
    it->second->dump(ofile);
  }
}
