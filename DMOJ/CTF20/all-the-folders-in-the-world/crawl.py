#!usr/bin/python2

import sys
import os

# extractors
targz = "tar -xf"
zip7 = "7z x"
rpa = "~/rpatool/rpatool -x" # download rpatool from github for this to work
extractors = [zip7, targz, rpa]

rootpath = "/home/dre/programming/DMOJ/CTF20/all-the-folders-in-the-world/DBCB125552D893D3"

def crawl(path):
    os.chdir(path)
    for tool in extractors:
        for f in os.listdir(path):
            if not os.path.isdir(f):
                l = "{} {}/{}".format(tool, path, f)
                print l
                os.system(l)
    dirs = []
    for f in os.listdir(path):
        if os.path.isdir(f):
            dirs.append("{}/{}".format(path,f))
    for d in dirs:
        crawl(d)

crawl(rootpath)
