http://0x10c.com
Old Specs: http://0x10c.com/doc/dcpu-16.txt
New Specs: http://dcpu.com/highnerd/dcpu16.txt

This is my assembler. I noticed allot of people building some fairly basic assemblers with no expression parsing or even macros so this is mine that includes that.

Right now I support .BYTE/.WORD lists.  An .ORIGIN and full expressions with Boolean operations.  It outputs a debug list file and an Intel Hex file.  Its still in the air on how this cpu will support what kind of rom formats so I figure Intel hex is a no brainier.

Use bison to rebuild the grammar files, but it "should" compile as is.  I am fairly proud I did this all in ANSI C, but probably going to switch to C++ if just for the STL.

NOTE:  Right now the source is set from the previous cpu design.  I am in the process of updating it.