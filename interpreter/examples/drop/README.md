Description
============
Example of use of the primitive 'drop'.

The primitive 'drop' drops a packet.

It is a logical primitive, i.e. a primitive that can be used in conditional or unconditional attacks.


Sintax
======
drop(packetName, likelyhood)

args:
 + packetName is the name of the packet to drop
 + likelyhood is the probability that the drop action occurs


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i drop-original.asl -o drop-original.xml

or

$ python ../../interpreter.py -i drop-original.asl

or you can use the pre-built bash script

$ ./drop-one.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
