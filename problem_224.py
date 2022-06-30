# Problem 224
# Given mathematical expression, calculate its result

class Node:
    def __init__(self):
        self.val = 0
        self.prev = ''
        self.next = None

class Solution:
    def calculate(self, s: str) -> int:
        n = len(s) + 1
        ans = Node()
        cur = 0
        s += "+"
        
        for i in range(0, n):
            if s[i] == ' ':
                continue
            elif s[i] == '+' or s[i] == '-':
                if ans.prev == '-':
                    cur = -cur
                ans.val += cur
                ans.prev = s[i]
                cur = 0
            elif s[i] =='(':
                old = ans
                ans = Node()
                ans.next = old
            elif s[i] == ')':
                if ans.prev == '-':
                    cur = -cur
                ans.val += cur
                cur = ans.val
                ans = ans.next
            else:
                cur *= 10
                cur += int(s[i])
                
        return ans.val