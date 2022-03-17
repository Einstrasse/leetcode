#!/usr/bin/env python3
import sys

def decomp(text, start=0, times=1):
    for _ in range(times):
        i = start

        while i < len(text) and text[i] != ']': #process outermost onion-peel
            if text[i].islower():
                yield text[i]
                i += 1
            else:
                sub_times = 0
                while text[i].isdigit():
                    sub_times = sub_times * 10 + int(text[i])
                    i += 1        
                i += 1 #skip [
                for item in decomp(text, i, sub_times):
                    if isinstance(item, str):
                        yield item
                    else:
                        i = item #jump to next index
                i += 1 # skip ]
        if start > 0:
            yield i 

def decompress(text):
    for letter in decomp(text):
        sys.stdout.write(letter)
    print()

if __name__ == '__main__':
    decompress(sys.argv[1])
