Description
============
This is a set of examples of use of the interpreter of the Attack Specification Language (ADL) for ASF++.
 

Usage
=====
To interpret all '.adl' files contained in the dir 'example' use:

``` sh
$ python interpret-all-examples.py
```

To interpret one single '.adl' file use:

``` sh
$ python path/interpreter.py -i inputfile -o outputfile
```
-i inputfile is mandatory

-o outputfile is optional

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ADL description in the input file.


Input file
==========
The input file of the interpreter is an ADL file having the extension '.adl' (e.g. 'myattacks.adl').
The interpreter accepts also other types of extensions, like '.txt', and files without extension (e.g. 'myattacks.txt' or 'myattack').


Output file
===========
The interpreter produces always an '.xml' file.


ADL details
===========
To obtain further details on ADL (of ASF++) read the user manual or see the sub-dirs in 'examples'.


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>
