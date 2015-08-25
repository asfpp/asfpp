Description
============
Example of use of the primitive 'change'.

The primitive 'change' changes the content of a certain field (of a certain layer) in a packet.

It is a logical primitive, i.e. a primitive that can be used in conditional or unconditional attacks.


Sintax
======
change(packetName, layer.field, value)

args:
 + packetName is the name of the target packet
 + layer.field specifies the layer in which search a certain field
 + value is the value to overwrite in the field


Usage of the interpreter
========================
$ python <relative_path/interpreter.py> -i <file_input> -o <file_output>

or you can use the bash script for conveniente (if present, else you can build it):

$ ./bash_script.sh

The command above produces the XML Attack Configuration File (aka ACF) for ASF++, according to the ASL description in the input file.


Example
=======
$ python ../../interpreter.py -i change.asl -o change.xml

or

$ python ../../interpreter.py -i change.asl

or you can use the pre-built bash script

$ ./change.sh


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>


Maintainer
==========
+ Francesco Racciatti	<racciatti.francesco@gmail.com>
