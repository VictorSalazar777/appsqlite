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

using namespace std;

namespace DatabaseUtils {
    string getDatabasePath();
    
    void printDbMsgError(sqlite3* db, string tag);
    
    string insertSqlGenerator(string tableName, list<string> columnNames);
    
    list<string> getColumnNamesFromDb(sqlite3 *db, const string tableName);
    
    struct DbDeleter {
        void operator()(sqlite3* db) {
            sqlite3_close(db);
        }
    };
    using uniqueDbPtr = unique_ptr<sqlite3, DbDeleter>;
    uniqueDbPtr getDb();
    
    struct StmtDeleter {
        void operator()(sqlite3_stmt* stmt) {
            sqlite3_finalize(stmt);
        }
    };
    using uniqueStmtPtr = unique_ptr<sqlite3_stmt, StmtDeleter>;
    uniqueStmtPtr getStmt(sqlite3* db, string sql);
};

#endif /* DatabaseUtils_hpp */
