# Read from the file words.txt and output the word frequency list to stdout.
# 97.73% (4 ms), 50.00% (3.6 MB), awk-for-if
awk '
{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}
' file.txt