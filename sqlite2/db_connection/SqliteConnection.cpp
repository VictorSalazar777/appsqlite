//
//  SqliteConnection.cpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "SqliteConnection.hpp"
#include <sqlite3.h>
#include "../utils/DatabaseUtils.hpp"
#include <iostream>

using namespace std;

SqliteConnection *SqliteConnection::m_instance = nullptr;

SqliteConnection::SqliteConnection() {
    m_db = nullptr;
}
SqliteConnection *SqliteConnection::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new SqliteConnection();
    }
    return m_instance;
    
}

sqlite3 *SqliteConnection::getSqliteConnection() {
    if (m_db == nullptr) {
        int rc = sqlite3_open(DatabaseUtils::getDatabasePath().c_str(), &m_db);
        if (rc) {
            cerr << "Can't open database from \"" << DatabaseUtils::getDatabasePath().c_str() << "\"" << endl;
            sqlite3_close(m_db);
            return nullptr;
        }
    }
    return m_db;
}


