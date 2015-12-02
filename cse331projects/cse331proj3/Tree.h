/*********************************************************************
 * Tree 
 * Project 3 
 * Yingfei Li
 * A47225481
 * This program takes a random sequence of numbers and 
 * then it assembles the numbers into a Binary search tree. 
 * The tree is then output in a preorder traversal and 
 * a depth of the tree is also output
*********************************************************************/

#ifndef CTREE_H
#define CTREE_H

#include <iostream>

template<class T> class CTree
{
public:
    CTree() {m_root = 0;}
    ~CTree() {delete m_root;}

    //
    // class Node
    // The nested node class for objects in our tree.
    //

    class Node 
    {
    public:
        friend class CTree;

        Node() {m_ll = 0;  m_rl = 0;}
        Node(const T &t) {m_number = t;  m_ll = 0;  m_rl = 0;}
        ~Node() {delete m_ll;  delete m_rl;}

        T &Data() {return m_number;}
        const T &Data() const {return m_number;}

    private:
        Node    *m_ll;
        Node    *m_rl;
        T       m_number;

    };


//public insert function checks if tree is null, else add a new node
    void Insert(const T &t) 
    { 
	Node* new_one =  new Node(t);
	if(m_root==0){
            m_root=new_one;
        }
       	else{
            Node* root=m_root;
            while(root!=0){
                if(new_one->Data()>root->Data()){
                    if(root->m_rl==0){
			    root->m_rl=new_one;}
		    else{
			    root=root->m_rl;
                        }
		     }
		    else if(new_one->Data()<root->Data()){
			if(root->m_ll==0){
			    root->m_ll=new_one;
                        }
			else{
			    root=root->m_ll;
                        }
		     }
		    else{
                         break;
                    }
		}
	}
    }
    void Preorder(std::ostream &p_str) {
        PreorderRecursion(m_root,p_str);
    }
    

//public depth calls depth recursive function
    int Depth() {return DepthRecur(m_root);}

//no need for find 
    const Node *Find(const T &t) const {}
    Node *Find(const T &t){}

//public delete checks if the value given is zero, else it calls remove 
    void Delete(const T &t)
    {
      if(t == 0)
       { 
          ; 
       } 
       else
          deletion(t, m_root);
    }
   
private:
    Node *m_root;

//finds the max depth of the tree and returns it, if it is not null    
    int DepthRecur(Node *node)
    {
        if (node==NULL)
           return 0;
        else
        {
            //recursive call to find depth
            int l_depth= DepthRecur(node->m_ll);
            int r_depth= DepthRecur(node->m_rl);
 
            //compare the two and return bigger depth+1
            if (l_depth > r_depth)
               return(l_depth+1);
            else return(r_depth+1);
        }
    } 

//traverse the tree and send the results back to p_str output
    void PreorderRecursion(Node* node, std::ostream &p_str )
    {
       if (node == NULL)
           return;
 
       p_str << node->m_number<<" ";
 
       // then recursively call on left subtree
       PreorderRecursion(node->m_ll,p_str); 
 
       // then recursively call right subtree
       PreorderRecursion(node->m_rl,p_str);
    }    


    void deletion( const T & x, Node * & t )
    {
       int y;
       if( t == NULL)
          return; //not found
       if( x < t->m_number )
          deletion( x, t->m_ll ); //call recursive left
       else if( x > t->m_number )
          deletion( x, t->m_rl ); //call recursive right
       else if(t->m_ll == NULL)
          t = t->m_rl;  //if left node is null, then it is a right leaf node
       else if(t->m_rl == NULL)
          t = t->m_ll;  //if right node is null, it is a left leaf node
       else //t has left child ,max of left child becomes the root
       {
          y = deletemin(t->m_rl); 
          t->m_number = y;
       }
    } 
//find min value of right subtree so parent with two children can be deleted
    int deletemin(Node * &t)
    {
       int x;
       if (t == NULL)
          return 0;
       else if(t->m_ll == NULL)
       {
          x= t->m_number;
          t = t->m_rl;
       }
       else //t has a left child, follow left child
          x = deletemin(t->m_ll);

       return x;
    }

};
#endif