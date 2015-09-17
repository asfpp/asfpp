# Deep test.
#
# authors: 
#  + Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 2
list targetList = {3, 4, 9, 10, 15, 16}

list targetList3 = {3}
list targetList4 = {4}
list targetList9 = {9}
list targetList10 = {10}
list targetList15 = {15}
list targetList16 = {16}



# conditional statement
from 200 nodes in targetList3 do {
    filter(("APP.appNetInfoExchange.source" % 3) == 0)
        change(original, "APP.data", 60)
}

from 200 nodes in targetList4 do {
    filter(("APP.appNetInfoExchange.source" % 4) == 0)
        change(original, "APP.data", 60)
}

from 200 nodes in targetList9 do {
    filter(("APP.appNetInfoExchange.source" % 9) == 0)
        change(original, "APP.data", 60)
}

from 200 nodes in targetList10 do {
    filter(("APP.appNetInfoExchange.source" % 10) == 0)
        change(original, "APP.data", 60)
}

from 200 nodes in targetList15 do {
    filter(("APP.appNetInfoExchange.source" % 15) == 0)
        change(original, "APP.data", 60)
}

from 200 nodes in targetList16 do {
    filter(("APP.appNetInfoExchange.source" % 16) == 0)
        change(original, "APP.data", 60)
}


