# Read from the file words.txt and output the word frequency list to stdout.
# 57.13% (4 ms), 82.76% (3.3 MB), sort/uniq/awk
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr -k 1 | awk '{ print $2, $1 }'