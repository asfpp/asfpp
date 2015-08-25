Description
============
This is the interpreter of the Attack Specification Language (ASL) for ASF++.


Usage
=====
``` sh
$ python path/interpreter.py -i inputfile -o outputfile
```
-i inputfile is mandatory

-o outputfile is optional

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Input file
==========
The input file of the interpreter is an ASL file having the extension '.asl' (e.g. 'myattacks.asl').
The interpreter accepts also other types of extensions, like '.txt', and files without extension (e.g. 'myattacks.txt' or 'myattack').


Output file
===========
The interpreter produces always an '.xml' file.


ASL details
===========
To obtain further details on ASL (of ASF++) read the user manual or see the sub-dir 'examples'.


Authors
=======
+ Alessandro Pischedda	<alessandro.pischedda@gmail.com>
+ Marco Tiloca		    	<marco.tiloca84@gmail.com>
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
