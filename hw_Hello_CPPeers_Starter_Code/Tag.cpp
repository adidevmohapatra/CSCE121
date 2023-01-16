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
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if (tagName.size()<2){
    throw std::invalid_argument("Invalid Tag Name: Size Error");
  }
  if (tagName[0]!='#'){
    throw std::invalid_argument("Invalid Tag Name: No pound sign for first character");
  }
  if (tagName[1]<'a' || tagName[1]>'z'){
    throw std::invalid_argument("Invalid Tag Name: No lower case letter for second character");
  }
  for (unsigned int i=0;i<tagName.size();++i){
    if (tagName[i]>='A' && tagName[i]<='Z'){
    throw std::invalid_argument("Invalid Tag Name: Upper case letter detected");
    }
  }
  if(tagName.at(tagName.size()-1)=='!' || tagName.at(tagName.size()-1)==',' || tagName.at(tagName.size()-1)=='.' || tagName.at(tagName.size()-1)=='?'){
    throw std::invalid_argument("Invalid Tag Name: Punctuation detected");
  }

  this->tagName=tagName;
}

string Tag::getTagName() {
  // TODO(student): implement getter

  return this->tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return this->tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if(post==nullptr){
    throw std::invalid_argument("Invalid Tag Name: Post is Nullptr");
  }
  this->tagPosts.push_back(post);
}
