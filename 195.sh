# Read from the file words.txt and output the word frequency list to stdout.
# 74.35% (4 ms), 33.33% (3.8 MB), awk (no `exit` will be slow in big file)
awk 'NR==10 {print; exit}' file.txt
# 74.35% (4 ms), 33.33% (3.8 MB), tail + head
tail -n +10 file.txt | head -1
# 100.00% (0 ms), 76.19% (3.7 MB), sed (slow with big file)
sed -n 10p file.txt