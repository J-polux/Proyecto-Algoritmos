#ifndef et_hpp
#define et_hpp

#include<cstdlib>
#include<string>
#include<iostream>
#include"stack.hpp"

class et{
private:
	struct etNode{
		std::string key;
		etNode *right;
    etNode *left;
    etNode *parent;
	};

  size_t count;
	etNode *tree;

//etNode * copy(etNode *tree) const;
void collapse(etNode * &tree);
void clear(etNode * &tree);
void display(etNode *tree, std::ostream &out) const;

public:
	et();
	et(std::string s);
  et(const et &rhs);
	~et();

  bool empty(void) const;
  void clear(void);
  void display(std::ostream &out = std::cout) const;
};

#include "et.cpp"
#endif
