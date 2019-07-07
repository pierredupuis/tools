#! /usr/bin/python3

import sys
from argparse import *

# Compare multiple files in hexadecimal.
# For each block of data at the same offset :
#   Offset is printed
#   The block from the reference file is printed in cyan on one line.
#   Each following line is a block from the other files. Bytes that differs from their respective bytes in the reference file are highlighted in red
#   A blank line is printed to separate the next block



parser = ArgumentParser(description='Compare files as hexadecimal')
parser.add_argument('ref_file', type=str, help='Reference file for the comparison')
parser.add_argument('cmp_files', type=str, nargs='+', help='files to compare')
#parser.add_argument('-c', '--columns', dest='cols', type=int, default=16, choices=[4,8,16], help='Number of bytes (columns) to show in one line')
#parser.add_argument('-v', '--verbose', dest='verbose', action='store_true')
parser.add_argument('-a', '--all', dest='print_all', action='store_true')

args = parser.parse_args()

# Handles a file. Reads the file by blocks of a given size. Each block will produce one output line.
#  filename:    File read by this object
#  file:        file object
#  color:       Output color
#  line_byte:   
class CompFile:
    def __init__(self, filename, color='\033[1m\033[96m'):
        self.filename = filename
        self.color = color

        self.file = open(self.filename, 'rb')
        self.end = False
        self.line_byte = 0
        
        self.reset_line()
        

    # reset the string
    def reset_line(self):
        self.str = '  '
        self.line_byte = 0
    
    # Stock and return a read byte.
    def read(self):
        if not self.end:
            self.byte = self.file.read(1)
            if self.byte:
                return self.byte
            else:
                self.end = True
                return None
        else:
            return None     

    # Append a read byte to the object's string
    def append(self, colored=False):
        if self.byte:
            if colored:
                self.str += self.color + self.byte.hex() + '\033[0m'
            else:
                self.str += self.byte.hex()
            self.byte = None
            self.line_byte += 1

            if self.line_byte == 4 or self.line_byte == 12:
                self.str += 2*' '
            elif self.line_byte == 8:
                self.str += 4*' '
            else:
                self.str += ' '
            
            return colored
        else:
            return None


    # Print the object's string then resets it (preparing it for next appends that will form the next line)
    def print_line(self):
        if not self.end or self.str:
            print(self.str)
            self.reset_line()
        else:
            print('END')

    def close(self):
        self.file.close()


# Print ref file's line,
# Print all comparing files' lines.
# A print will also reset file object's line

def print_blocks(ref, cmps, offset_line):
    print('0x{:08x}:'.format(offset_line))
    
    ref.print_line()
    for f in cmps:
        f.print_line()
    print()

# Read arguments, creates file objects
ref_file = CompFile(args.ref_file)
cmp_files = []
for filename in args.cmp_files:
    cmp_files.append(CompFile(filename, '\033[91m'))


nb_bytes = 0
ref_byte = '1'
all_end = False # if True, all files have reached the end (EOF).
offset_line = 0
change = False

while not all_end:
    ref_byte = ref_file.read()
    ref_file.append(True)

    nb_bytes += 1
    
    all_end = ref_file.end

    # Read and compares bytes of each comparing file. If all return True, and ref_file returns True too, it's the end of the block.
    for cf in cmp_files:
        change = cf.append(cf.read() != ref_byte) or change # If ref value  != read value, color
        all_end = all_end and cf.end
    
    # block has been treated. Prints it if there is a difference or if user asked to print everything (-a/--all)
    if nb_bytes % 16 == 0 or all_end:
        if change or args.print_all:
            print_blocks(ref_file, cmp_files, offset_line)
            change = False
        else:
            ref_file.reset_line()
            for f in cmp_files:
                f.reset_line()

        offset_line += 16


