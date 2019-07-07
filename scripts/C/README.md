## C

### to_clip

Copies the given string into the clipboard (Windows only)



**usage:** `to_clip.exe arg1[ arg2[...]]`

**other usage:** You can set this program as the default application to open particular links in your browser. The link will go to your clipboard instead of opening another program (ex: mailto links).

* 1 argument: directly copies it to the clipboard
* 1+ arguments: concatenates all arguments, with spaces, then copies it to the clipboard

How to compile: `gcc to_clip.c -o to_clip.exe`

---
