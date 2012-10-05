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

#ifndef PROPERTYBINDINGCONTAINER_H
#define PROPERTYBINDINGCONTAINER_H

#include <QDataStream>
#include <qmetatype.h>
#include <QString>


namespace QmlDesigner {

class PropertyBindingContainer
{
    friend QDataStream &operator>>(QDataStream &in, PropertyBindingContainer &container);

public:
    PropertyBindingContainer();
    PropertyBindingContainer(qint32 instanceId, const QString &name, const QString &expression, const QString &dynamicTypeName);

    qint32 instanceId() const;
    QString name() const;
    QString expression() const;
    bool isDynamic() const;
    QString dynamicTypeName() const;

private:
    qint32 m_instanceId;
    QString m_name;
    QString m_expression;
    QString m_dynamicTypeName;
};

QDataStream &operator<<(QDataStream &out, const PropertyBindingContainer &container);
QDataStream &operator>>(QDataStream &in, PropertyBindingContainer &container);

} // namespace QmlDesigner

Q_DECLARE_METATYPE(QmlDesigner::PropertyBindingContainer)
#endif // PROPERTYBINDINGCONTAINER_H
