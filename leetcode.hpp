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

/*********************************************/
/** 26. REMOVE DUPLICATES FROM SORTED ARRAY **/
/*********************************************/
/*
  Given an integer array nums sorted in non-decreasing order, 
  remove the duplicates in-place such that each unique element appears only once. 
  The relative order of the elements should be kept the same. 
  Then return the number of unique elements in nums.
*/
int removeDuplicates(std::vector<int>& nums) {
  int temp = 1;

  for(int i = 1; i < nums.size(); i++){
    if(nums[i] != nums[i - 1]){
      nums[temp] = nums[i];
      temp++;
    }
  }
  return temp;
}
/*************************/
/** 21. MERGE TWO LISTS **/
/*************************/
/*
  You are given the heads of two sorted linked lists list1 and list2.
  Merge the two lists into one sorted list. 
  The list should be made by splicing together the nodes of the first two lists.
  Return the head of the merged linked list.
  Definition for singly-linked list.
 */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  
  if(list1 == nullptr) return list2;
  if(list2 == nullptr) return list1;
  
  ListNode* head = new ListNode();
  ListNode* temp = head;

  while(list1->next != nullptr && list2->next != nullptr) {
    
    if(list1->val < list2->val) {
      temp->next = list1;
      list1 = list1->next;
    } else {
      temp->next = list2;
      list2 = list2->next;
    }

    temp = temp->next;
  }

  if(list1 == nullptr) {
    temp->next = list2;
  } else {
    temp->next = list1;
  }

  return head->next;
}

/***************************/
/** 20. VALID PARENTHESES **/
/***************************/
/*
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.
  An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/

bool is_in_map(const std::map<char, char>& m, const char c) {
  for(auto& it : m) {
    if(it.second == c) {
      return true;
    }
  }

  return false;
}

bool valid_parenthese(std::string s) {
  std::map<char, char> check = {{'}', '{'}, {')', '('}, {']','['}}; 
  std::vector<char> stack;

  for(int i = 0; i < s.size(); ++i) {
    if(is_in_map(check, s[i])) {
      stack.push_back(s[i]);
      continue;
    }

    if(stack.size() == 0) {
      return false;
    }

    if(check[s[i]] != stack[stack.size() -1]) {
      return false;
    }
    
    stack.pop_back();
  }

  return stack.size() == 0;
}

/*******************************/
/** 14. LONGEST COMMON PREFIX **/
/*******************************/
/* 
  Function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".
*/

std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::string output = "";

// SOLUTION 1
/*
  int index = 0;
  while(index < strs[0].length()) {
    int letter = strs[0][index];

    for(short int i = 0; i < strs.size(); ++i) {
      if(letter != strs[i][index] || index >= strs[i].length()) {
        return output;
      }
    }

    output += letter;
    index++;
  }
*/
// SOLUTION 2
  int size = strs.size();
  sort(strs.begin(), strs.end());

  for(short int i = 0; i < strs[0].length() || i < strs[size-1].length(); ++i) {
    if(strs[0][i] != strs[size-1][i]) {
      return output;
    }
    
    output += strs[0][i];
  }

  return output;
}


/**************************/
/** 13. ROMAN TO INTEGER **/
/**************************/
/*
  Convert roman number to integer
*/
int romanToInt(std::string s) {
  std::map<char, int> m = 
    {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int number = 0;
  int length = s.length();

  for(short int i = 0; i < length-1; ++i) {
    if(m[s[i]] < m[s[i+1]]) {
      number -= m[s[i]];
      continue;
    }

    number += m[s[i]];

  }

  return number + m[s[length-1]];
}






