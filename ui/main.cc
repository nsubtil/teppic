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

#include "mainwindow.h"
#include "registerwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow win;
    win.setWindowTitle(QObject::tr("Teppic"));
    win.show();

    RegisterWindow regwin(&win);
    regwin.setWindowTitle(QObject::tr("Register map"));
    regwin.setFloating(true);
    regwin.show();

    return app.exec();
}

