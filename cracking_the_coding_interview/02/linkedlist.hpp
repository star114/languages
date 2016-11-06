/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.hpp
 *
 *    Description:  linkedlist declaration.
 *
 *        Version:  1.0
 *        Created:  08/28/15 15:46:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Heesik Shin (star114), star114.shin@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include <iostream>
#include "base.hpp"

namespace dev_base
{

template <typename T> class linkedlist;

template <typename U>
class node {
  template <typename T> friend class linkedlist;
  U data;
  node<U>* next;
  node<U>* before;
public:
  node(U u):data(u), next(NULL), before(NULL){}
  ~node(){}
};

template <typename T>
class linkedlist 
{
public:
  linkedlist() : head(NULL), tail(NULL), count(0) {}
  linkedlist(T t) : head(new node<T>(t)), tail(head), count(1) {}
  ~linkedlist()
  {
    if (!isEmpty())
    {
      node<T>* iter = head;
      while (iter != tail)
      {
        head = iter;
        iter = iter->next;
        delete head;
      }
    }
  }

  void print()
  {
    node<T>* runner = head;
    while (NULL != runner)
    {
      std::cout << runner->data << std::endl;
      runner = runner->next;
    }
  }

  void push_back(T t)
  {
    node<T>* new_node = new node<T>(t);
    if (!isEmpty())
    {
      tail->next =new_node;
      new_node->before = tail;
      tail = new_node;
    }
    else
    {
      head = new_node;
      tail = head;
    }
    count++;
  }

  T pop_back()
  {
    T ret_val;
    if (!isEmpty())
    {
      node<T>* temp_node = tail;
      if (head == tail)
      {
        head = NULL;
        tail = NULL;
      }
      else
        tail = tail->before;
      ret_val = temp_node->data;
      remove(temp_node);
      count--;
    }
    else
      throw;
    return ret_val;
  }

  void remove(node<T>* target)
  {
    node<T>* temp_node = target;
    if (target->before) target->before->next = target->next;
    if (target->next) target->next->before = target->before; 
    delete target;
  }

  void unique()
  {
    if (!isEmpty())
    {
      node<T>* runner = head;
      while (NULL != runner)
      {
        T value = runner->data;
        node<T>* runner_checker = runner->next;
        
        while (NULL != runner_checker)
        {
          node<T>* temp_node = runner_checker->next;
          if (value == runner_checker->data)
          {
            if (tail == runner_checker)
              tail = tail->before;
            remove(runner_checker);
          }
          runner_checker = temp_node;
        }

        runner = runner->next;
      }
    }
  }

  /*  char version
  void unique()
  {
    bool check_chars[MAX_CHAR] = {false, };
    if (!isEmpty())
    {
      node<T>* runner = head;
      while( NULL != runner)
      {
        node<T>* temp_node = runner->next;
        char c = runner->data;
        if (check_chars[c])
        {
          if (tail == runner)
            tail = tail->before;
          remove(runner);
        }
        else
          check_chars[c] = true;
        runner = temp_node;
      }
    }
  }
  */
  
  bool isEmpty()
  {
    if (NULL == head && NULL == tail) return true;
    else return false;
  }
  size_t size()
  {
    return count;
  }
private:
  size_t count;
  node<T>* tail;
  node<T>* head;
};
}

