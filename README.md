input format:
./bin_to_hex FILENAME
if this isn't specified it will by default take "source.txt"


Why do you output my input in a text file in the same folder? Don't I already know what it is?
If you get bad results, you can check the file to see if it matches, since it outputs the data that's being used.


Why is there a byte of zeroes at the end?
Null terminator. It's a C string. You can recompile this and go to n-1 if you care.
