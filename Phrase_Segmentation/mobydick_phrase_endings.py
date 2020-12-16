# -*- coding: utf-8 -*-
"""
Created on Thu Jun 18 12:19:16 2020

@author: am_ka
"""

import string
import operator 
import nltk
from nltk.book import *
from nltk import word_tokenize 

moby = gutenberg.sents('melville-moby_dick.txt')
print("\nCorpus Loaded")

def TagMaker(word):
    text = word_tokenize(word)
    tagged = nltk.pos_tag(text)
    return tagged[0][1]

clean_tokens = []
rec = {}


# Iterate through each sentence in 'Moby Dick' and contruct a dictionary
# entry for each word-pairing it ends with (attempting to avoid punctuation)
# and its corresponding frequency. 
# If one instance of a specific word pairing already exists within the
# dictionary, increase its frequency count by one instead of creating an entry.
 
''' N.B. This could've been accomplished with nltk's 'bigrams' function, but 
    it only works for nltk corpora. I wanted this to work with any large body
    of text, for which the formatting process would come easily. '''
    
for sentence in moby:
    if len(sentence) < 3:
        continue
    
    x = -1
    
    while sentence[x].isalpha() != True or sentence[x - 1].isalpha() != True or sentence[x] in string.punctuation:
        x -= 1
        if sentence[x] == i[0]:
            break
    if (len(sentence) + x) < 1:
        continue
    
    end_pair = sentence[x - 1] + "/" + sentence[x]
    
    if end_pair not in rec:
        rec[end_pair] = 1
    else: 
        rec[end_pair] += 1

print("\nRecord Complete")    
# Output the 15 word pairings with the highest counts
end_pairs =  dict(sorted(rec.items(), key=operator.itemgetter(1), reverse=True)[:15])
print("\nMost Frequent End Pairings\n" + "-"*26)
print(end_pairs)

# Construct a dictionary now of word-type pairings coupled with their frequencies
# within the prevously constructed dictionary.
codex = {}
for i in rec.keys():
    split_key = i.split("/")
    
    j = TagMaker(split_key[0])
    k = TagMaker(split_key[1])
    
    tag_pair = j + "/" + k
    
    if tag_pair not in codex:
        codex[tag_pair] = 1
    else:
        codex[tag_pair] += 1
        
# Output the 15 word-type pairings with the highest counts   
end_pair_tags =  dict(sorted(codex.items(), key=operator.itemgetter(1), reverse=True)[:15])
print("\nMost Frequent End Pairing Tags\n" + "-"*30)
print(end_pair_tags)