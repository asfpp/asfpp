Description
============
Example of use of the primitive 'clone'.

The primitive 'clone' produces a perfect copy of a given packet.

It is a logical primitive, i.e. a primitive that can be used in conditional or unconditional attacks.


Sintax
======
clone(srcPacketName, dstPacketName)

args:
 + srcPacketName is the name of the source packet
 + dstPacketName is the name of the new packet


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i clone.asl -o clone.xml

or

$ python ../../interpreter.py -i clone.asl

or you can use the pre-built bash script

$ ./clone.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
