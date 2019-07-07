## Python
	
### hexdiff
Compare files using hexadecimal format.

**usage:** hexdiff [\-h] [\-a] ref\_file cmp\_files [cmp\_files ...]

Compare multiple files in hexadecimal.
For each block of data at the same offset, is printed :
 * the current offest,
 * the block from the reference file, colored and on a single line,
 * the block from each compared file, on one line for each. Bytes responsible for the difference are highlighted in red. If no file differs from the reference, the block is not printed, unless option -a/-all is given.

---
### translate

prints a file's content in binary, octal, decimal, hexadecimal, UTF-8.

**usage:** translate file\_name

---


