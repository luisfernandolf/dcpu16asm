# Standard Line #

_:label_ **opcode operand, operand**<br>
This works like in Notch's example, with the exception the label can have the : in front or back or not at all.<br>
<br>
<b>label .EQU | = value</b> <br>You can have a label equal some constant or formula<br>
<i>ex.  :stringtable = string_consts + (const_offset + 50)</i>

<i>label</i> <b>.ORIGIN expression</b><br>
This will change the location of the folowing code or labels to a new memory address<br>
<br>
<i>label</i> <b>.BYTE expression [, expression]</b><br>
This will push byte values into the memory of whatever expressions.  Hex, numbers and strings.  Be aware that the dcpu16 is word alligned.  That is if an odd number of bytes are put in it will add an extra byte (0) to align it.<br>
<i>ex. :stringtable .BYTE "This is a null term string",0</i><br>
<i>ex. :rawdata     .BYTE 0x43, 0x53, 5, 2, offset + 3</i>
<b>STRINGS ARE NOT SUPPORTED YET</b>

<i>label</i> <b>.WORD expression [, expression]</b><br>
This will push word (16-bit) values into the memory of whatever expressions.  Hex, numbers and strings.  If your pushing a string, it will store each character in a separate word.  <br>
<i>ex. :stringtable .WORD "This is a null term string",0</i><br>
<i>ex. :rawdata     .WORD 0x43, 0x53, 5, 2, offset + 3</i>
<b>STRINGS ARE NOT SUPPORTED YET</b>

<b>JSR opcode</b>
JSR is a hard jump.  If the jump is less than 0x20, this assembler will property modify the value for it so its one word.<br>
<br>
<h2>BUGS</h2>
Right now the listing is showing a byte pc counter with a memory space of 0x20000.  I do not believe the hex file is coming out right either.<br>
<br>
The next phase will be for me to gut the half-assed C code I have in there and move it to c++ but I wanted to push this version to play around with and see what kind of macros the community wants to support<br>
<br>
JSR also uses the operand grammar, so it will emit the same value for the operands on the normal op-codes, this is incorrect but again changing stuff.