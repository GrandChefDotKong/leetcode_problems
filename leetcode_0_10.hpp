#pragma once
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <limits.h>

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

/****************/
/** 1. TWO SUM **/
/****************/
/*
  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
*/
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> map;
  std::unordered_map<int,int>::iterator it;
  int diff;

  for(short int i = 0; i < nums.size(); ++i) {
    diff = target - nums[i];
    it = map.find(diff);
    if(it != map.end() && it->second != i) {
        return std::vector<int>{i, it->second};
    }

    map[nums[i]] = i;
  }

  return {};
}
/***********************/
/** 2. ADD TWO NUMBER **/
/***********************/
/*
  You are given two non-empty linked lists representing two non-negative integers. 
  The digits are stored in reverse order, and each of their nodes contains a single digit. 
  Add the two numbers and return the sum as a linked list.
  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
  Given an array of integers nums and an integer target, 
  return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* sum = new ListNode();
  ListNode* temp = sum;
  int carryOver = 0;

  while(l1 != nullptr || l2 != nullptr) {
    int value = carryOver;

    if(l1 != nullptr) {
      value += l1->val;
      carryOver += l1->val;
      l1 = l1->next;         
    }

    if(l2 != nullptr) {
      value += l2->val;
      carryOver += l2->val;
      l2 = l2->next;         
    }

    value = value % 10;
    carryOver /= 10;

    temp->next = new ListNode(value);
    temp = temp->next;
  }

  if(carryOver > 0) {
    temp->next = new ListNode(carryOver);
  }

  return sum->next;
}
/**************************************/
/** 5. Longest Palindromic Substring **/
/**************************************/
/*
  Given a string s, return the longest palindromic substring in s.
*/
class Solution {
public:

    std::string longestPalindrome(std::string s) {
// NAIVE APPROCH
/*
        if(s.length() == 1) {
            return s;
        }
        
        int maxLength = 1;
        int start = 0;
        for(int i = 0; i < s.length(); ++i) {
            int begin = i;
            int end = s.length();
            int k = s.length()-1;
            int j = s.length()-1;
            while(j > begin) {
                if(s[j] == s[begin]) {
                    begin++;
                } else {
                    if(begin != i) {
                        j = k;
                        k--;
                    }

                    begin = i;
                    end = j;
                }

                j--;
            }

            if((end - i) > maxLength) {
                maxLength = (end - i); 
                start = i;
            }
        }
                
        return s.substr(start, maxLength);
    }
*/
        if(s.length() <= 1) {
            return s;
        }

        int maxLength = 1, start = 0;

        for(int i = 0; i < s.length(); ++i) {
            int lengthA = searchFromMiddle(s, i, i+1);
            int lengthB = searchFromMiddle(s, i, i);

            int length  = lengthA > lengthB ? lengthA : lengthB; 
            
            if(length > maxLength) {
                start = i - ((length - 1) /2);
                maxLength = length;
            }
        }

        return s.substr(start, maxLength);
    }

    int searchFromMiddle(std::string s, int left, int right) {
        if(left > right) {
            return 0;
        }

        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            right++;
            left--;
        }

        return (right - left - 1);
    }

};
/**************************************/
/** 6. Zigzag Conversion **/
/**************************************/
std::string convert(std::string s, int numRows) {
  if(numRows == 1) {
    return s;
  }

  std::string solution = "";
  int increment = (numRows - 1) * 2;
  for(int i = 0; i < numRows; ++i) {    
    for(int j = i; j < s.length(); j += increment) {
      solution += s[j];
      if(i > 0 && i < numRows-1 
      && (j + increment - 2 * i) < s.length()) {
        solution += s[j+increment - 2 * i];
      }     
    }
  }

  return solution;
}
/**************************/
/** 7. Reverse Integer **/
/**************************/
/*
  Given a signed 32-bit integer x, return x with its digits reversed. 
  If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
int reverse(int x) {
  int reverse = 0;

  do {
    int digit = x % 10; 
    
    if((reverse < INT_MIN / 10 || reverse == INT_MIN / 10 && digit < -8) ||
    (reverse > INT_MAX / 10 || reverse == INT_MAX / 10 && digit > 7)) {
      return 0;
    }

    reverse = (reverse * 10) + digit;
    x = x / 10;
      
  } while( x != 0);

  return reverse;
}
/**************************/
/** 9. PALINDROME NUMBER **/
/**************************/
/*
  Given an integer x, return true if x is a palindrome, and false otherwise.
*/
bool isPalindrome(int x) {
  if(x < 0) {
    return false;
  }

  long int temp = x;
  long int reverse = 0;
  int digit;

  do {
    digit = x % 10;
    reverse = (reverse * 10) + digit;
    x = x / 10;
  } while( x > 0);
  
  return reverse == temp;
}