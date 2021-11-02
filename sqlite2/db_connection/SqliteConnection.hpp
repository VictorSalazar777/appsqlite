//
//  SqliteConnection.hpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef SqliteConnection_hpp
#define SqliteConnection_hpp

#include <sqlite3.h>

class SqliteConnection {
private:
    static SqliteConnection *m_instance;
    sqlite3 *m_db;
    SqliteConnection();
public:
    static SqliteConnection *getInstance();
    sqlite3 *getSqliteConnection();
};

#endif /* SqliteConnection_hpp */
