#pragma once
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/////////////////////////////////////////////////
/* SOME OFF THE LEETCODE.COM PROBLEMS I SOLVED */
/////////////////////////////////////////////////

/*****************************/
/** 58. Length of Last Word **/
/*****************************/
/*
  Given a string s consisting of words and spaces, 
  return the length of the last word in the string.
  A word is a maximal substring consisting of non-space characters only.
*/
int lengthOfLastWord(std::string s) {
  int wordLength = 0;

  for(int i = s.length() - 1; i >= 0; --i) {

    if(s[i] != ' ') {
      wordLength++;
      continue;
    }
    
    if(wordLength > 0) {
      return wordLength;
    }

    wordLength  = 0;
  }

  return wordLength;
}