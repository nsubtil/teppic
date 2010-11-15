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

cmake_minimum_required(VERSION 2.6)
project(teppic)

include_directories(${teppic_SOURCE_DIR})

add_subdirectory(cpu)
add_subdirectory(mem)

add_executable(teppic main.cc)
target_link_libraries(teppic cpu mem)

