#!/usr/bin/env python3
import sys

def check(words, index):
    if len(words) != len(words[0]):
        return False
    for i in range(len(words)):
        if words[index][i] != words[i][index]:
            return False
    return True

def word_square(words, current, used, ans, k, length, table):
    ret = False
    if k == length - 1:
        if all([check(current, i) for i in range(length)]):
            ans.append(tuple([i for i in current]))
            return True
        else:
            return False
    next_ch = current[0][k+1]
    if table[0].get(next_ch) == None:
        return False
    for index in table[0][next_ch]:
        if used[index] == True:
            continue
        used[index] = True
        current.append(words[index])
        if word_square(words, current, used, ans, k+1, length, table):
            ret = True
        used[index] = False
        current.pop()
    return ret
def is_word_square(words):
    ans = []
    if len(words) == 0:
        return res
    length = len(words[0])
    table = [{} for i in range(length)]
    for windex, word in enumerate(words):
        for index, ch in enumerate(word):
            if table[index].get(ch) == None:
                table[index][ch] = [windex]
            else:
                table[index][ch].append(windex)
    current = []
    print (table)
    used = [False for i in range(len(words))]
    for index, word in enumerate(words):
        current.append(word)
        used[index] = True
        word_square(words, current, used, ans, 0, length, table)
        used[index] = False
        current.pop()
    return ans

if __name__ == "__main__":
    print (is_word_square(sys.argv[1:]))
        
    