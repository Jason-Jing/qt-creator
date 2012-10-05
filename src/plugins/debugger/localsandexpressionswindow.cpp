/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "localsandexpressionswindow.h"

#include <coreplugin/minisplitter.h>

#include <QVBoxLayout>
#include <QSplitter>
#include <QStackedWidget>

namespace Debugger {
namespace Internal {

LocalsAndExpressionsWindow::LocalsAndExpressionsWindow(
        QWidget *locals, QWidget *inspector, QWidget *returnWidget,
        QWidget *watchers, QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);

    m_splitter = new Core::MiniSplitter(Qt::Vertical);
    layout->addWidget(m_splitter);

    m_localsAndInspector = new QStackedWidget();
    m_localsAndInspector->addWidget(locals);
    m_localsAndInspector->addWidget(inspector);
    m_localsAndInspector->setCurrentWidget(inspector);

    m_splitter->addWidget(m_localsAndInspector);
    m_splitter->addWidget(returnWidget);
    m_splitter->addWidget(watchers);

    m_splitter->setStretchFactor(0, 3);
    m_splitter->setStretchFactor(2, 1);
    m_splitter->setStretchFactor(3, 1);
}

void LocalsAndExpressionsWindow::setShowLocals(bool showLocals)
{
    m_localsAndInspector->setCurrentIndex(showLocals ? 0 : 1);
}

} // namespace Internal
} // namespace Debugger
