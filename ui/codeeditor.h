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

// based on the CodeEditor Qt example

#ifndef __CODEEDITOR_H
#define __CODEEDITOR_H

#include <QPlainTextEdit>
#include <QObject>

class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;

class LineNumberArea;

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

private:
    QWidget *lineNumberArea;

public:
    CodeEditor(QWidget *parent = 0);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
};

class LineNumberArea : public QWidget
{
private:
    CodeEditor *codeEditor;

public:
    LineNumberArea(CodeEditor *editor)
        : QWidget(editor)
    {
        codeEditor = editor;
    };

    QSize sizeHint() const
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    };

protected:
    void paintEvent(QPaintEvent *event)
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    };
};

#endif // ifndef __CODEEDITOR_H
