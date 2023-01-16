/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if (userName==""){
    throw std::invalid_argument("Invalid Tag Name: No lower case letter for second character");
  }
  if (userName[0]<'a' || userName[0]>'z'){
    throw std::invalid_argument("Invalid Tag Name: No lower case letter for second character");
  }
  for (unsigned int i=0;i<userName.size();++i){
    if (userName[i]>='A' && userName[i]<='Z'){
    throw std::invalid_argument("Invalid Tag Name: Upper case letter detected");
    }
  }

  this->userName=userName;
}

string User::getUserName() {
  // TODO(student): implement getter
  return this->userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return this->userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post==nullptr){
    throw std::invalid_argument("Invalid Tag Name: Post is Nullptr");
  }
  this->userPosts.push_back(post);
}
