//
// Implementation
//
template <typename E>					// constructor
  AVLTree<E>::AVLTree() : ST() { }

template <typename E>					// node height utility
  int AVLTree<E>::height(const TPos& v) const
    { return (v.isExternal() ? 0 : (*v).height()); }

template <typename E>					// set height utility
  void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));			// max of left & right
  }

template <typename E>					// is v balanced?
  bool AVLTree<E>::isBalanced(const TPos& v) const {	
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
  }

template <typename E>					// get tallest grandchild
  typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))			// left child taller
      if (height(zl.left()) >= height(zl.right()))
        return zl.left();
      else
        return zl.right();
    else 						// right child taller
      if (height(zr.right()) >= height(zr.left()))
        return zr.right();
      else
        return zr.left();
  }


//
// ToDo
//

template <typename E>					// remove key k entry
  void AVLTree<E>::erase(const K& k) {
    TPos v = finder(k, ST::root());
    TPos w = eraser(v);
    rebalance(w);
  }

template <typename E>					// insert (k,x)
  typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    TPos v = ST::inserter(k, x);
    setHeight(v);
    rebalance(v);
    return Iterator(v);
  }
  
template <typename E>					// rebalancing utility
  void AVLTree<E>::rebalance(const TPos& v) {
    TPos z = v;
    while (!(z == ST::root()))
    {
        z = z.parent();
        setHeight(z);
        if (!isBalanced(z))
        {
            TPos x = tallGrandchild(z);
            z = restructure(x);
            setHeight(z.left());
            setHeight(z.right());
            setHeight(z);
        }
    }
  }

template <typename E>				// Binary Search Tree Rotation
  typename AVLTree<E>::TPos AVLTree<E>::restructure(const TPos& v) {

    TPos x = v;
    TPos y = v.parent();    //parent node of x
    TPos z = y.parent();    //parent node of y(== grandparent node of x)
    TPos GP = z;    //grandparent node is z, it needs to compare with great grand parent
    TPos GGP = z.parent();  //great grand parent node is parent node of z

    K key_z = (*z).key();
    K key_y = (*y).key();
    K key_x = (*x).key();

    if(key_z < key_y) // Left rotation
    {
        if(key_y < key_x)   //RR rotation
        {
            TPos ylc = y.left();
            y.v->par = z.v->par;
            z.v->right = ylc.v;
            y.v->left = z.v;
            z.v->par = x.v->par = y.v;
            ylc.v->par = z.v;
            if(GGP.left() == GP)
                GGP.v->left = y.v;
            else if(GGP.right() == GP)
                GGP.v->right = y.v;
            return y;
        }
        else if(key_y > key_x)  //RL rotation
        {
            TPos xlc = x.left();
            TPos xrc = x.right();
            x.v->par = y.v->par;    //LL rotation begins
            y.v->left = xrc.v;
            x.v->right = y.v;
            xlc.v->par = y.v->par = x.v;
            xrc.v->par = y.v;   //LL rotation ends
            x.v->par = z.v->par;    //RR rotation begins
            z.v->right = xlc.v;
            x.v->left = z.v;
            z.v->par = y.v->par = x.v;
            xlc.v->par = z.v; //RR rotation ends
            if(GGP.left() == GP)
                GGP.v->left = x.v;
            else if(GGP.right() == GP)
                GGP.v->right = x.v;
            return x;
        }
    }
    else  //Right rotation
    {
        if(key_y > key_x)   //LL rotation
        {
            TPos yrc = y.right();
            y.v->par = z.v->par;
            z.v->left = yrc.v;
            y.v->right = z.v;
            z.v->par = x.v->par = y.v;
            yrc.v->par = z.v;
            if(GGP.left() == GP)
                GGP.v->left = y.v;
            else if(GGP.right() == GP)
                GGP.v->right = y.v;
            return y;
        }
        else if(key_y < key_x)  //LR rotation
        {
            TPos xlc = x.left();
            TPos xrc = x.right();
            x.v->par = y.v->par;    //RR rotation begins
            y.v->right = xlc.v;
            x.v->left = y.v;
            y.v->par = xrc.v->par = x.v;
            xlc.v->par = y.v;   //RR rotation ends
            x.v->par = z.v->par;    //LL rotation begins
            z.v->left = xrc.v;
            x.v->right = z.v;
            z.v->par = y.v->par = x.v;
            xrc.v->par = z.v; //LL rotatiion ends
            if(GGP.left() == GP)
                GGP.v->left = x.v;
            else if(GGP.right() == GP)
                GGP.v->right = x.v;
            return x;
        }
    }
return NULL;    //if an error occurs
  }

