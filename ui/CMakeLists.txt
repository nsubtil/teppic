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

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

set(qt_SRCS
    mainwindow.cc
    registerwindow.cc
    codeeditor.cc
    main.cc
)

set(qt_MOC_H
    mainwindow.h
    registerwindow.h
    codeeditor.h
)

set(qt_UI
    mainwindow.ui
    registerwindow.ui
)

qt4_automoc(${qt_SRCS})
qt4_wrap_ui(qt_UI_H ${qt_UI})
qt4_wrap_cpp(qt_MOC_SRCS ${qt_MOC_H})

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR} ${teppic_source_dir}/ui)

# xxx: can we just set MACOSX_BUNDLE unconditionally?
if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
  add_executable(teppic-qt MACOSX_BUNDLE ${qt_SRCS} ${qt_MOC_SRCS} ${qt_UI_H})
else()
  add_executable(teppic-qt ${qt_SRCS} ${qt_MOC_SRCS} ${qt_UI_H})
endif()

target_link_libraries(teppic-qt ${QT_LIBRARIES} teppic)

