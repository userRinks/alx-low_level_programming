#!/usr/bin/python3

def crackme4_hacker(password()):
	if __name__ == '__main__':
		from importlib import import_module
		
		password = import_module('crackme4')
		for key in sorted(dir(password)):
			if key[0:2] != '__':
				print('Module item - {:s}'.format(key))
				print('crackme4 pass = "{}"'.format(password))
