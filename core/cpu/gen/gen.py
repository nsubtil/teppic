#  Copyright (C) 2010, Nuno Subtil
#
#  This file is part of Teppic.
#
#  Teppic is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#  
#  Teppic is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with Teppic.  If not, see <http://www.gnu.org/licenses/>.

import sys
import re

# 0: waiting for device line
# 1: waiting for register line
# 2: parsing inside register
state = 0

device = ""
register_list = []

line_no = 1

def err(msg):
    print str(line_no) + ": " + msg

class bit (dict):
    def __init__ (self, name, index):
        self['name'] = name
        self['index'] = index

    def debug(self):
        print " bit %s index %d" % (self['name'], self['index'])

class alias (dict):
    def __init__ (self, name, address):
        self['name'] = name
        self['address'] = address

    def validate(self):
        if 'address' not in self:
            err("alias " + self['name'] + " missing address")
            return False

        return True

    def debug(self):
        print " alias %s at address %x" % (self['name'], self['address'])

class register (dict):
    def __init__(self, name):
        self['name'] = name
        self['aliases'] = [ ]
        self['bits'] = [ ]
        self['power-on-default'] = 0
        self['power-on-default-mask' ] = 0xff
        self['reset-default'] = 0
        self['reset-default-mask'] = 0xff
        self['wake-up-intr-default'] = 0
        self['wake-up-intr-default-mask'] = 0xff

    def __mask_ones(self):
        mask = 0
        for i in range(0, self['size']):
            mask |= (0xff << (i * 8))

        return mask

    def __check_size(self, val):
        if (self[val] & self.__mask_ones()) != self[val]:
            err(val + ' for register ' + self['name'] + ' too large')
            return False

        return True

    def add_alias(self, name, address):
        self['aliases'].append(alias(name, address))

    def add_bit(self, name, index):
        self['bits'].append(bit(name, index))

    def set_once(self, key, val):
        if 'key' in self:
            err(key + ' already set in register ' + self['name'])
            return False

#        print self['name'] + ': ' + key + ' = ' + str(val)
        self[key] = val
        return True

    def __check_set_init_condition(self, name, default):
        if name not in self:
            self[name] = self[default]

        if name + '-mask' not in self:
            self[name + '-mask'] = self[default + '-mask']

        if self.__check_size(name) == False or self.__check_size(name + '-mask') == False:
            return True

        return False

    def validate(self):
        if 'name' not in self:
            err("ooops! i fucked up :)")
            return False

        if 'address' not in self:
            err("register " + self['name'] + " missing address")
            return False

        if 'size' not in self:
            self['size'] = 1

        if 'read-mask' not in self:
            self['read-mask'] = self.__mask_ones()
        elif self.__check_size('read-mask') == False:
                return False

        if 'write-mask' not in self:
            self['write-mask'] = self.__mask_ones()
        elif self.__check_size('write-mask') == False:
            return False

        self['power-on-default-mask'] = self.__mask_ones()
        self['reset-default-mask'] = self.__mask_ones()
        self['wake-up-intr-default-mask'] = self.__mask_ones()

        if self.__check_set_init_condition('power-on', 'power-on-default') or \
           self.__check_set_init_condition('brown-out', 'power-on') or \
           self.__check_set_init_condition('reset', 'reset-default') or \
           self.__check_set_init_condition('mclr-run', 'reset') or \
           self.__check_set_init_condition('mclr-sleep', 'reset') or \
           self.__check_set_init_condition('wdt', 'reset') or \
           self.__check_set_init_condition('stack-ov', 'reset') or \
           self.__check_set_init_condition('stack-uf', 'reset') or \
           self.__check_set_init_condition('wake-up-intr', 'wake-up-intr-default') or \
           self.__check_set_init_condition('wake-up-wdt', 'wake-up-intr'):
            return False

        if 'aliases' in self:
            for reg in self['aliases']:
                if reg.validate() == False:
                    return False

                if reg['address'] - self['address'] > self['size']:
                    err("alias register " + reg['name'] + " out of bounds of parent register " + self['name'])
                    return False

        return True

    def debug(self):
        print 'register %s:' % self['name']
        print ' size: %d' % self['size']
        print ' read-mask: %x' % self['read-mask']
        print ' write-mask: %x' % self['write-mask']
        print ' power-on: %x' % self['power-on']
        print ' power-on-mask: %x' % self['power-on-mask']
        print ' brown-out: %x' % self['brown-out']
        print ' brown-out-mask: %x' % self['brown-out-mask']
        print ' reset: %x' % self['reset']
        print ' reset-mask: %x' % self['reset-mask']
        print ' mclr-run: %x' % self['mclr-run']
        print ' mclr-run-mask: %x' % self['mclr-run-mask']
        print ' mclr-sleep: %x' % self['mclr-sleep']
        print ' mclr-sleep-mask: %x' % self['mclr-sleep-mask']
        print ' wdt: %x' % self['wdt']
        print ' wdt-mask: %x' % self['wdt-mask']
        print ' stack-ov: %x' % self['stack-ov']
        print ' stack-ov-mask: %x' % self['stack-ov-mask']
        print ' stack-uf: %x' % self['stack-uf']
        print ' stack-uf-mask: %x' % self['stack-uf-mask']
        print ' wake-up-intr: %x' % self['wake-up-intr']
        print ' wake-up-intr-mask: %x' % self['wake-up-intr-mask']
        print ' wake-up-wdt: %x' % self['wake-up-wdt']
        print ' wake-up-wdt-mask: %x' % self['wake-up-wdt-mask']

        for i in self['bits']:
            i.debug()

        for i in self['aliases']:
            i.debug()


def strip_comments(line):
    return re.sub(r'\#.*$', '', line)

def strip_whitespace(line):
    l = re.sub(r'[\ \t]+', ' ', line)
    l = re.sub(r'\n', '', l)
    l = re.sub(r'^\ ', '', l)

    return l

reg = register('')

def parse_line_in_register(reg, line):
    simple_value_list = [ 'address', 'size', 'read-mask', 'write-mask' ]
    masked_value_list = [ 'power-on', 'brown-out',
                          'reset', 'mclr-run', 'mclr-sleep', 'wdt', 'stack-ov', 'stack-uf',
                          'wake-up-intr', 'wake-up-wdt' ]

    for s in simple_value_list:
        m = re.match(s + r'\ ([A-Fa-f0-9]+)$', line)
        if m:
            return reg.set_once(s, int(m.group(1), 16))

    for s in masked_value_list:
        m = re.match(s + r'\ ([A-Fa-f0-9]+)(\ mask\ ([A-Fa-f0-9]+))?$', line)
        if m:
            if reg.set_once(s, int(m.group(1), 16)) == False:
                return False

            if m.group(3) != None:
                return reg.set_once(s + '-mask', int(m.group(3), 16))
            else:
                return True

    m = re.match(r'alias\ ([A-Z0-9]+)\ ([A-Fa-f0-9]+)$', line)
    if m:
        name = m.group(1)
        address = int(m.group(2), 16)
        reg.add_alias(name, address)
        return True

    m = re.match(r'bit\ ([A-Z0-9]+) ([A-Fa-f0-9]+)$', line)
    if m:
        name = m.group(1)
        idx = int(m.group(2), 16)
        reg.add_bit(name, idx)
        return True

    if re.match(r'end$', line):
        global state

        if reg.validate() == False:
            return False

        reg.debug()

        register_list.append(reg)
        reg = register('')
        state = 1
        return True

    err('syntax error')
    return False

def parse_file(filename):
    global state
    global device
    global register_list
    global line_no

    file = open(filename, 'r')

    for line in file:
        line = strip_comments(line)
        line = strip_whitespace(line)
        if line != "":
            if state == 0:
                m = re.match(r'device\ (.*?)$', line)
                if m:
                    device = m.group(1)
                    state = 1
                else:
                    err("syntax error")
                    exit(1)
            elif state == 1:
                m = re.match(r'register\ ([A-Z0-9]+)$', line)
                if m:
                    reg = register(m.group(1))
                    state = 2
                else:
                    err("syntax error")
                    exit(1)
            elif state == 2:
                if parse_line_in_register(reg, line) == False:
                    exit(1)
                    
        line_no = line_no + 1


parse_file(sys.argv[1])

print '''
/*
  Copyright (C) 2010, Nuno Subtil

  This file is part of Teppic.

  Teppic is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Teppic is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Teppic.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined(__PIC_REGISTER_FILE__)
#error multiple register file headers included
#else
#define __PIC_REGISTER_FILE__
#endif

// %s MCU register definition file
// Generated from %s

#define __%s__
''' % (str.upper(device), sys.argv[1], str.upper(device))

for reg in register_list:
    print "#define %s 0x%04X" % (reg['name'].ljust(16), reg['address'])
    if 'aliases' in reg:
        for alias in reg['aliases']:
            print "#define  %s 0x%04X" % (alias['name'].ljust(15), alias['address'])

    if 'bits' in reg:
        for bit in reg['bits']:
            print "#define  %s 0x%04X" % (str(reg['name'] + "_" + bit['name']).ljust(15), bit['index'])
