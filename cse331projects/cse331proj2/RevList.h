/*
// Name :         RevList.h
// Description :  Simple doubly linked list with reversing feature.
// Project:02
 * Yingfei Li
 * A47225481
*/

#ifndef REVLIST_H
#define REVLIST_H

//#include <iostream>

template<class T> class CRevList
{

public:
  // Constructor.  Sets to an empty list.
  CRevList() 
  {
      m_head = NULL;
      m_tail = NULL;
      isReversed= false;
      size = 0;
      
  }

  // Destructor.  Deletes everything in the list.
  ~CRevList()
  {
      Clear();
      isReversed = false;
      m_head= NULL;
      m_tail=NULL;
      size=0;
  }

  // Copy constructor.  Copies another list.
  CRevList(const CRevList &b)
  {
      Node *new_head=m_head;
      for (unsigned i=0; i<b.size;i++){
          b.PopFront(new_head);
          new_head=new_head->m_next;
      }
  }

  // Assignment operator.  Copies another list.
  void operator=(const CRevList &b);

  // Clear the list.
  void Clear()
  {
      for (unsigned i=0; i<size;i++)
          PopBack();
  }


  //
  // class Node
  // The nested node class for objects in our linked list.
  //
  // YOU MAY NOT MODIFY THIS CLASS!
  class Node 
  {
  public:
    friend class CRevList;
  
    Node() {m_next = 0;  m_prev = 0;}
    Node(const T &t) {m_payload = t;  m_next = 0;  m_prev = 0;}
  
    T Data() {return m_payload;}
    const T Data() const {return m_payload;}
  
  private:
    Node    *m_next;
    Node    *m_prev;
    T       m_payload;
  };
  
  // Determines if the list is empty
  bool IsEmpty() const {
      if (size ==0)
          return true;
      else 
          return false;
  }

  //methods to add data to the front or the back of the list
  void PushFront(const T &t) {
      Node * new_head = new Node(t);
      if (IsEmpty()) {
          this->m_head = new_head;
          size +=1;
      }
      else if (size ==1 ) {
          m_tail = m_head;
          new_head->m_next=m_head;
          m_head=new_head;
          m_head->m_next=m_tail;
          m_head->m_prev=m_tail;
          m_tail->m_next=m_head;
          m_tail->m_prev=m_head;
          size++;              
      }
      else {
          new_head->m_next=m_head;
          m_head->m_prev = new_head;
          m_head= new_head;
          size++;
      }
  }
  void PushBack(const T &t) {
      Node *new_tail = new Node(t);
      if (IsEmpty()){
          m_head=new_tail;
          m_tail=new_tail;
      }
      else if (size ==1){
          this->m_tail =new_tail;
          m_head->m_next=m_tail;
          m_head->m_prev=m_tail;
          m_tail->m_next=m_head;
          m_tail->m_prev=m_head;     
      }
      else{
          m_tail->m_next=new_tail;
          new_tail->m_prev=m_tail;
          new_tail->m_next=m_head;
          m_head->m_prev= new_tail;
          m_tail=new_tail;
          size++;       
      }
  }
  void PopFront() {
      if (size ==1){//if there is only one number in the list
          delete m_head;
          m_head = NULL;
          m_tail = NULL;
          size--;   
      }
      else if(size ==2){//if there are two members in the list 
          m_head=m_tail;
          delete m_head->m_prev;
          m_tail= NULL;
          size--;
      }
      else {
          m_head=m_head->m_next;
          delete m_head->m_prev;
          m_head->m_prev=m_tail;
          m_tail->m_next=m_head;
          size--;
          ;
      }
  }
  
  //removes the object at the end of the list.
  void PopBack() { 
      if (size ==1){
          delete m_head;
          m_head= NULL;
          m_tail= NULL;
          size--;
      }
      else if (size ==2){
          delete m_tail;
          m_tail=NULL;
          size--;
      }
      else{
          m_tail=m_tail->m_prev;
          delete m_tail->m_next;
          m_tail->m_next=m_head;
          m_head->m_prev=m_tail;
          size--;
      }
  }

  //Get a pointer to the first node in the list
  const Node *Begin() const {
      return this->m_head;
  }
  Node *Begin() {
      return this->m_head;
  }

  //get a pointer to the last node in the list
  const Node *End() const {
      return this->m_tail;
  }
  Node *End() {return this->m_tail;}

  //get a pointer to node next in the list
  const Node *Next(const Node *n) const { 
      Node *next_one = new Node();
      if(isReversed()){
          next_one=n->m_prev;
          return next_one;
      }
      else{
          next_one=n->m_next;
          return next_one;
      }
  }
  Node *Next(const Node *n) {
      Node *next_one = new Node();
      if(isReversed()){
          next_one=n->m_prev;
          return next_one;
      }
      else{
          next_one=n->m_next;
          return next_one;
      }
  }

  //Find a node with the specified key
  const Node *Find(const T &t) const {
      Node *key_node =m_head;
      while (m_tail!=key_node){
          if(key_node->Data() == t){
              return key_node;
          }
          key_node=key_node->m_next;
      }
  }
  Node *Find(const T &t) {
  }

  //Delete the given node
  void Delete(Node *n){
      if (n==m_head){
          m_head=n->m_next;
          m_head->m_prev=m_tail;
          m_tail->m_next=m_head;
      }
      else if (n==m_tail){
          m_tail->m_next=m_head;
          m_tail->m_prev=m_tail;
          
      }
      else{
          n->m_next->m_prev=n->m_prev;
          n->m_prev->m_next=n->m_next;
      }
      delete n;
  }

  //Reverse the list in O(1) time
  void Reverse() {
      if (isReversed==true){
          isReversed=false;
      }
      else
          isReversed=false;
  }

  

private:

  //NOTE: you may add any private member variables or 
  //      methods you need to complete the implementation

  Node    *m_head;             // Head node
  Node    *m_tail;
  unsigned size;
  bool isReversed;
};

// Assignment operator.  Copies another list.
template<class T> void CRevList<T>::operator=(const CRevList<T> &b){
    Node *new_head=m_head;
    for (unsigned i =0; i<b.size;i++){
        b.PushFront(new_head);
        new_head=new_head->m_next;
    }
    return *this;
}

//template<class T> (CRevList<T>::Node *) CRevList<T>::Begin1() //
{return m_reverse ? m_head.m_prev : m_head.m_next;}


#endif
