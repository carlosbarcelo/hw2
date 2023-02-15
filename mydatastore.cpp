#include "mydatastore.h"

MyDataStore::MyDataStore(){
  
}

MyDataStore::~MyDataStore(){
  std::map<std::string, User*>::iterator it;
  std::map<std::string, Product*>::iterator pit;
  
  for(it = users_.begin(); it != users_.end(); it++){
    delete it->second;
  }
  for(pit = prods_.begin(); pit != prods_.end(); pit++){
    delete pit->second;
  }
}

void MyDataStore::addUser(User* u){
  users_.insert(std::make_pair(u->getName(), u));
}

void MyDataStore::addProduct(Product* p){
  std::set<std::string> keys = p->keywords();
  for(std::set<std::string>::iterator it = keys.begin(); it != keys.end(); it ++){
    keyprods_.insert(std::make_pair(*it, p));
  }
  prods_.insert(std::make_pair(p->getName(), p));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  std::vector<Product*> found;
  if(type == 1){
  for(size_t i = 0; i < terms.size(); i++){
    std::map<std::string, Product*>::iterator it = keyprods_.find(terms[i]);
    if (it != keyprods_.end()){
      found.push_back(it->second);
    }
  }
  return found;
  }
  else{
  bool allfound = true;
  for(size_t i = 0; i < terms.size() && allfound; i++){
    std::map<std::string, Product*>::iterator it = keyprods_.find(terms[i]);
    if (it != keyprods_.end()){
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
  std::map<std::string, User*>::iterator uit;

  ofile << "<products>\n";
  for(it = prods_.begin(); it != prods_.end(); it++){
    it->second->dump(ofile);
  }
  ofile << "</products>\n<users>" << std::endl;
  for(uit = users_.begin(); uit != users_.end(); uit++){
    uit->second->dump(ofile);
  }
  ofile << "</users>";
}