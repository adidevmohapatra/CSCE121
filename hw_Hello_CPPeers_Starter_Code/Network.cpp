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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"


using std::string;
using std::vector;
using std::stringstream;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream file;
  file.open(fileName);
  if (!file.is_open()){
      throw std::invalid_argument("File Does Not Open");
    }
  string line;
  string user_post;
  while(getline(file,line)){
  user_post="";
  stringstream ss(line);
  ss>>user_post; 
    
    if(user_post=="User"){
      string userName;
      ss>>userName;
      if(ss.fail()){
        throw std::runtime_error("b");
      }

      try {
        addUser(userName);
      }
      catch(const std::invalid_argument& e) {
        throw std::runtime_error("c");
      }
      

    }
    else if(user_post=="Post"){
      string userName;
      unsigned int postid;
      string posttext;

      ss>>postid;
      if(ss.fail()){
        throw std::runtime_error("d");
      }

      ss>>userName;
      if(ss.fail()){
        throw std::runtime_error("e");
      }

      
      getline(ss,posttext);
      if(ss.fail()){
        throw std::runtime_error("f");
      }
      try {
        addPost(postid,userName,posttext);
      }
      catch(const std::invalid_argument& e) {
        throw std::runtime_error("g");
      }
    }
    else{
      if(user_post!=""){
        throw std::runtime_error("h");
      }
      if (user_post!="User" || user_post!="Post"){
        throw std::runtime_error("a");
      }
    }

  }

}


void Network::addUser(string userName) {
  // TODO(student): create user and add it to network

  for(unsigned int i=0;i<userName.size();++i){
    if (userName[i]>='A' && userName[i]<='Z'){
        userName[i]=tolower(userName[i]);
    }
  }
  for(unsigned int i=0;i<users.size();++i){
    if(users[i]->getUserName()==userName){
      throw std::invalid_argument("Username Match");
    }
  }
User *newname=new User(userName);
users.push_back(newname);

std::cout<<"Added User "<<userName<<std::endl;

}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network

  // test
  //std::cout << "postID: " << postId << std::endl;
  //std::cout << "userName: " << userName << std::endl;
  //std::cout << "postText: " << postText << std::endl;

  // make sure user is in database
  bool nouser=false;
  for(unsigned int i=0;i<users.size();++i){
    if(users[i]->getUserName()==userName){ 
      nouser=true;
    }
  }
  // test
  //std::cout << "user: " << nouser << std::endl;

  if (!nouser){
    throw std::invalid_argument("No Username");
  }


  for(unsigned int i=0;i<posts.size();++i){
    Post* post=posts[i];
    if(post->getPostId()==postId){
      throw std::invalid_argument("Same post");
    }
  }
  Post* newpost=new Post(postId,userName,postText);
  posts.push_back(newpost);

  for(unsigned int i=0;i<users.size();++i){
    if (users[i]->getUserName()==userName){
       users[i]->addUserPost(newpost);
     }
  }

  vector<string>candidate_hashtag;

  candidate_hashtag=newpost->findTags();
  
  for(unsigned int i=0;i<candidate_hashtag.size();++i){
    bool noadd=false;
    for(unsigned int j=0;j<tags.size();++j){
      if (tags[j]->getTagName()==candidate_hashtag[i]){
        tags[j]->addTagPost(newpost);
        noadd=true;
      }
    }
    if (!noadd){
    try
        {
          Tag*newtag=new Tag(candidate_hashtag[i]);
          tags.push_back(newtag);
          newtag->addTagPost(newpost);
        }
        catch(const std::exception& e)
        {
          continue;
        }
    }
  } 

std::cout<<"Added Post "<<postId<<" by "<<userName<<std::endl;

}







vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if (userName==""){
    throw std::invalid_argument("Error with username");
  }

  for (unsigned int i=0;i<users.size();++i){
     if (users[i]->getUserName()==userName){
       return users[i]->getUserPosts();
     }
  }
  throw std::invalid_argument("Error with username");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
    if (tagName==""){
    throw std::invalid_argument("Error with username");
  }

  for (unsigned int i=0;i<tags.size();++i){
     if (tags[i]->getTagName()==tagName){
       return tags[i]->getTagPosts();
     }
  }
  throw std::invalid_argument("Error with username");
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
 //step 1 itterate thouh all the hashtags
 //g
 vector<string>populartag;

 unsigned int maintag=tags[0]->getTagPosts().size();

 for(unsigned int i=0;i<tags.size();++i){
    if (maintag<tags[i]->getTagPosts().size()){
      maintag=tags[i]->getTagPosts().size();
    }
 }

 for(unsigned int i=0;i<tags.size();++i){
    if (maintag==tags[i]->getTagPosts().size()){
      populartag.push_back(tags[i]->getTagName());
    }
 }

return populartag;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }

}
