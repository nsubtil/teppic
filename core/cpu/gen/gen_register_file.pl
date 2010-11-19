#!/usr/bin/perl

open(FILE, "$ARGV[0]") or die;

$base = "";
$state = 0;

$header = 
"/*
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

#if defined (__PIC_REGISTER_FILE__)
#error multiple register file headers included
#else
#define __PIC_REGISTER_FILE__
#endif

";

print $header;

while(<FILE>)
{

    if (/^\;\ \ MPASM\ PIC(.*?)\ processor/)
    {
        print "// PIC$1 processor register definition file\n";
        print "// Generated from $ARGV[0]\n\n";
        print "// This header file defines configurations, registers, and other useful\n";
        print "// bits of information for the PIC$1 microcontroller.  These names\n";
        print "// are taken to match the data sheets as closely as possible.\n\n";

        print "#define __PIC$1__\n\n";
    }

    if (/^\;(.*?)$/)
    {
        print "// $1\n";
    }

    if (/^(.*?)EQU.*?H\'(.*?)\'/)
    {
        print "#define $1 0x$2\n";
    }
}
