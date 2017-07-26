/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#include "sqlitetransaction.h"

#include "sqlitedatabase.h"
#include "sqlitedatabasebackend.h"
#include "sqlitewritestatement.h"

namespace Sqlite {

SqliteAbstractTransaction::~SqliteAbstractTransaction()
{
    if (!m_isAlreadyCommited)
        m_databaseBackend.execute(Utf8StringLiteral("ROLLBACK"));
}

void SqliteAbstractTransaction::commit()
{
    m_databaseBackend.execute(Utf8StringLiteral("COMMIT"));
    m_isAlreadyCommited = true;
}

SqliteAbstractTransaction::SqliteAbstractTransaction(SqliteDatabaseBackend &backend)
    : m_databaseBackend(backend)
{
}

SqliteAbstractTransaction::SqliteAbstractTransaction(SqliteDatabase &database)
    : SqliteAbstractTransaction(database.backend())
{
}

SqliteTransaction::SqliteTransaction(SqliteDatabase &database)
    : SqliteAbstractTransaction(database)
{
    m_databaseBackend.execute(Utf8StringLiteral("BEGIN"));
}

SqliteImmediateTransaction::SqliteImmediateTransaction(SqliteDatabase &database)
    : SqliteAbstractTransaction(database)
{
    m_databaseBackend.execute(Utf8StringLiteral("BEGIN IMMEDIATE"));
}

SqliteExclusiveTransaction::SqliteExclusiveTransaction(SqliteDatabase &database)
    : SqliteAbstractTransaction(database)
{
    m_databaseBackend.execute(Utf8StringLiteral("BEGIN EXCLUSIVE"));
}

} // namespace Sqlite
