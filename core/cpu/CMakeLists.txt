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

set(cpu_sources
    cpu/pic.cc
    cpu/pic.h
    cpu/pic_registers.h
    cpu/pic_registers.cc
    cpu/pic18f2550.cc
    cpu/pic18f2550.h
    cpu/pic18f2550_registers.cc
    cpu/pic18f2550_registers.h
)

set(teppic_source_files ${teppic_source_files} ${cpu_sources} PARENT_SCOPE)

