# Read from the file words.txt and output the word frequency list to stdout.
# 57.77% (4 ms), 96.43% (3.1 MB), grep
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
# 28.70% (8 ms), 96.43% (3.1 MB), sed
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
# 100.00% (0 ms), 14.29% (3.3 MB), awk
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt