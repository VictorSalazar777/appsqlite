//
//  SqliteConnection2.cpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "SqliteConnection2.hpp"
#include "utils/DatabaseUtils.hpp"
#include <iostream>

namespace SqliteConnection2 {
    uniqueDbPtr getDb() {
        sqlite3* db;
        int rc = sqlite3_open(DatabaseUtils::getDatabasePath().c_str(), &db);
        if (rc) {
            std::cerr << "Can't open database from \"" << DatabaseUtils::getDatabasePath().c_str() << "\"" << std::endl;
            sqlite3_close(db);
            return nullptr;
        }
        return uniqueDbPtr(db);
    }
}
