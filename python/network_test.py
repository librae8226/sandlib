#!/usr/bin/env python

import unirest
import time

domestic_url = 'https://gitee.com/alios-things/AliOS-Things/raw/master/README.md'
foreign_url = 'https://raw.githubusercontent.com/alibaba/AliOS-Things/master/README.md'
begin_time = time.time()
end_time = 0
domestic_flag = True
def domestic_cb(res):
    global end_time
    if (res.code == 200 and end_time == 0):
        end_time = time.time()
        domestic_flag = True
        print('domestic elapse: %.2f' %(end_time - begin_time))
    return
def foreign_cb(res):
    global end_time
    if (res.code == 200 and end_time == 0):
        end_time = time.time()
        domestic_flag = False
        print('foreign elapse: %.2f' %(end_time - begin_time))
    return

def main():

    try:
        unirest.timeout(2)
        t1 = unirest.get(domestic_url, callback = domestic_cb)
        print(t1)
    except Exception:
        pass

    try:
        unirest.timeout(2)
        t2 = unirest.get(foreign_url, callback = foreign_cb)
        print(t2)
    except Exception:
        pass


    while (end_time == 0):
        time.sleep(0.1)

    if (domestic_flag == True):
        t2.join(0.1)
    else:
        t1.join(0.1)

main()
