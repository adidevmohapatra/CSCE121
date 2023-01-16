/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  istringstream ss(postText);
  vector<string> tags1;
  string thetags;

  while(ss>>thetags) {
    string newtag;
    if (thetags==""){
      continue;
    }
    if (thetags[0]!='#'){
      continue;
    }
    //bool one;
    for(unsigned int i=0;i<thetags.size();++i){
      if (thetags[i]>='A' && thetags[i]<='Z'){
        newtag+=tolower(thetags[i]);
      }
      else if (thetags[i]!='!' && thetags[i]!=',' && thetags[i]!='.' && thetags[i]!='?'){
        newtag+=thetags[i];
        //bool one=true;
        //break;
      }
  }
  tags1.push_back(newtag);
  }
  return tags1;
}
