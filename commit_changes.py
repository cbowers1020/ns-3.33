#!/usr/bin/python3
from subprocess import call
import sys
import os

with open("status.txt", "r") as fn:
	lines = fn.readlines()
	for line in lines:
			line = line.strip()
			if("modified" in line):
				comps = line.replace(" ", "").split(":")
				print("Committing file: {chng}".format(chng=comps[1]))
				cmd = "git add {file}".format(file=comps[1])
				call(cmd, shell=True)
				# print(comps[0])
				# print(comps[1])
			elif("deleted" in line):
				comps = line.replace(" ", "").split(":")
				print("Deleting file: {chng}".format(chng=comps[1]))
				cmd = "git rm {file}".format(file=comps[1])
				call(cmd, shell=True)
				# print(comps[0])
				# print(comps[1])
			elif(os.path.exists(line.replace(" ", ""))):
				comp = line.replace(" ", "")
				print("Adding {file} to version control".format(file=comp))
				cmd = "git add {file}".format(file=comp)
				call(cmd, shell=True)
			else:
				continue