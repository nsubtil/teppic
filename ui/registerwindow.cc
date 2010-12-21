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

#include "registerwindow.h"

RegisterWindow::RegisterWindow(PICRegisterFile *register_file, QWidget *parent)
  : QDockWidget(parent)
{
    int c;

    ui.setupUi(this);
    registers = register_file;

    c = registers->num_registers();
    ui.registerTable->setRowCount(c);

    for(c = 0; c < registers->num_registers(); c++)
    {
        QTableWidgetItem *i;
        const PICRegister *r;
        char str[128];

        r = registers->get_register(c);

        snprintf(str, 128, "%04x", r->addr);
        i = new QTableWidgetItem(QString(str));
        ui.registerTable->setItem(c, 0, i);

        i = new QTableWidgetItem(QString(r->name));
        ui.registerTable->setItem(c, 1, i);

        i = new QTableWidgetItem(QString("deadf007"));
        ui.registerTable->setItem(c, 2, i);
    }
}
