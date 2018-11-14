Description
============
Example of use of the primitive 'disable'.

The primitive 'disable' disables a node, i.e. the node can't communicate.

It is a physical primitive.


Sintax
======
disable(nodeId, occurrenceTime)

args:
 + nodeId is the Id of the node to disable
 + occurenceTime is the start time of the action


Usage of the interpreter
========================
``` sh
$ python path/interpreter.py -i inputfile -o outputfile
```

or you can use the bash script for convenience:

``` sh
$ ./bash_script.sh
```

Example
=======
``` sh
$ python ../../interpreter.py -i disable-one.adl -o disable-one.xml
```

or

``` sh
$ python ../../interpreter.py -i disable-one.adl
```

or you can use the pre-built bash script

``` sh
$ ./disable-one.sh
```


Authors
=======
+ Francesco Racciatti  	<racciatti.francesco@gmail.com>
