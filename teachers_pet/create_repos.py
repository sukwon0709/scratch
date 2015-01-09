#!/usr/bin/env python

import sys
from subprocess import call

def main():
    if len(sys.argv) < 2:
        sys.exit("Usage: {0} <repos file>".format(sys.argv[0]))
    with open(sys.argv[1]) as f:
        for repo_name in f:
            print repo_name.rstrip('\n')
            call(["teachers_pet", "create_repos", "--organization", "UoT-CSC30x-W15", "--repository", repo_name])

if __name__ == '__main__':
    main()
