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

/********************************/
/** 35. Search Insert Position **/
/********************************/
/*
  Given a sorted array of distinct integers and a target value, 
  return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.
  You must write an algorithm with O(log n) runtime complexity.
*/
int searchInsert(std::vector<int>& nums, int target) {
  int begin = 0;
  int end = nums.size() -1;

  while(begin <= end) {
    int mid = (end - begin) / 2 + begin;

    if(nums[mid] == target) {
      return mid;
    }

    if(nums[mid] > target) {
      end = mid - 1;
    } else {
      begin = mid + 1;
    }
  }

  return begin;
}