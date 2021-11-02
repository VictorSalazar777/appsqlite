//
//  DatabaseUtils.hpp
//  sqlite1
//
//  Created by manuel on 7/27/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef DatabaseUtils_hpp
#define DatabaseUtils_hpp

#include <string>
#include <list>
#include <sqlite3.h>
#include "db_connection/SqliteConnection2.hpp"

using namespace std;

namespace DatabaseUtils {
    string getDatabasePath();
    
    string insertSqlGenerator(string tableName, list<string> columnNames);
    
    list<string> getColumnNamesFromDb(sqlite3 *db, const string tableName);
    
//    struct DbDeleter {
//        void operator()(sqlite3* db) {
//            sqlite3_close(db);
//        }
//    };
    using uniqueDbPtr = unique_ptr<sqlite3, SqliteConnection2::DbDeleter>;
    uniqueDbPtr getDb();
    
    struct StmtDeleter {
        void operator()(sqlite3_stmt* stmt) {
            sqlite3_finalize(stmt);
        }
    };
    using uniqueStmtPtr = unique_ptr<sqlite3_stmt, StmtDeleter>;
    uniqueStmtPtr getStmt(const uniqueDbPtr& db, string sql);
    
    void printDbMsgError(const uniqueDbPtr& db, string tag);
};

#endif /* DatabaseUtils_hpp */
