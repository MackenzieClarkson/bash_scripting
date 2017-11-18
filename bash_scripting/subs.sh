#! /bin/sh

read -p 'Enter substring: ' substring #read input and set it to substring
echo Number of occurrences: $(grep -o $substring sample.txt | wc -l) #print number of occurrences using grep
