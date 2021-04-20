#ifdef et_hpp

void et::collapse(etNode * &tree){
  if (tree->right==nullptr and tree->left==nullptr) return;
  else if(tree->right!=nullptr and tree->left==nullptr) collapse(tree->right);
  else if(tree->right==nullptr and tree->left!=nullptr) collapse(tree->left);
  else if(tree->right!=nullptr and tree->left!=nullptr){
      collapse(tree->right);
      collapse(tree->left);
  }
}

void et::clear(etNode * &tree){
  collapse(tree);
}

void et::display(etNode *tree, std::ostream &out) const{
  if (tree != nullptr){
    display(tree->left, out);
    std::cout << tree->key<<std::endl;
    display(tree->right, out);
  }
}

et::et(){
  count = 0;
  tree = nullptr;
}

et::et(std::string s){
  count = s.size();
  Stack<etNode*> aux1;
  for (char c: s){
    if (isalpha(c) or isdigit(c)){
      etNode *aux2 = new etNode;
      aux2->key = c;
      aux2->left = aux2->right = nullptr;
      aux1.push(aux2);
    } else if(c == '+' or c == '-' or c == '/' or c == '*' or c=='^'){
      etNode *aux2 = new etNode;
      aux2->key = c;
      aux2->right = aux1.pop();
      aux2->left = aux1.pop();
      aux1.push(aux2);
    }
  }
  tree = aux1.pop();
}

et::et(const et &rhs){
  count = rhs.count;
  tree = rhs.tree;
}

et::~et(){
  clear();
  tree = nullptr;
}

bool et::empty(void) const{
  return (count == 0);
}

void et::clear(void){
  clear(tree);
}

void et::display(std::ostream &out) const{
  display(tree, out);
}

#endif
