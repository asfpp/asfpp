Description
===========
The simulation scenario is made as follows:

```sh
   cluster 1        cluster 2        cluster 3
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  
| s1       s2  |   s3       s4   |  s5       s6  |
|              |                 |               |
| s7   H   s8  |   s9  (H)  s10  |  s11   H  s12 |
|              |                 |               |
| s13      s14 |   s15      s16  |  s17      s18 |
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
```

Legend:
 + s *sensor*
 + H *heather*
 + (H) *heather & sink node* 


Source tree
===========
roomMonitoring/
 + attacks/ *contains a ready-to-use set of attacks*
 + plot/ *contains the routine to plot the simulations's results*
 + script/ *contains scripts to process the simulations's results*
 + deeptest/ *contains results of simulations (test purpose)*

Attacks
=======
The folder *attacks* contains a ready-to-use set of attacks. It contains also a Python
script that is usefull to interpret all the attacks.

``` sh
attacks$ python interpter-all-attacks.py
```

If you write a new attack, remember to:
 + interpret it;
 + add a configuration in the .ini file to link the new attack.


Usage
=====
``` sh
$ ../../bin/Castalia -c config
$ ./compute.sh
$ cd plot
plot$ gnuplot plot.plt
```

To interpret the attacks contained in the folder *attacks*, use:
``` sh
$ cd attacks
attacks$ python interpter-all-attacks.py
```


Example
=======
``` sh
$ ../../bin/Castalia -c drop-cluster-1
$ ./compute.sh
$ cd plot
plot$ gnuplot plot.plt
```


Author(s)
=========
+ Francesco Racciatti <racciatti.francesco@gmail.com>
