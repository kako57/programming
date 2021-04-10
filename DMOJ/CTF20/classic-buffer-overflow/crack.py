#!/usr/bin/env python3

from pwn import *

elf = ELF('./main')
p = process(elf)
