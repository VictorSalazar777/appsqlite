//
//  DatabaseUtils.cpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "DatabaseUtils.hpp"
#include <iostream>

using namespace std;

namespace DatabaseUtils {
    string getDatabasePath() {
        return "db/cliente.db";
    }
    
    void printDbMsgError(sqlite3* db, string tag) {
        cerr << tag << ", db error msg: " << sqlite3_errmsg(db) << endl;
    }
    
    string insertSqlGenerator(string tableName, list<string> columnNames) {
        string sql = "INSERT INTO " + tableName + "(";
        string sqlValues = " VALUES(";
        int counter = 0;
        for (string columnName : columnNames) {
            if (counter < columnNames.size() - 1) {
                sql += columnName + ",";
                sqlValues += "?,";
            } else if (counter == columnNames.size() - 1) {
                sql += columnName + ")";
                sqlValues += "?)";
            }
            ++counter;
        }
        sql += sqlValues;
        return sql;
    }
    
    list<string> getColumnNamesFromDb(sqlite3 *db, const string tableName) {
        sqlite3_stmt *stmt;
        list<string> columnNames;
        string sql = "SELECT * FROM `" + tableName + '`';
        if (int err = sqlite3_prepare_v2(db, sql.c_str(), static_cast<int>(sql.size()), &stmt, NULL) != SQLITE_OK) {
            cerr << "prepare stmt error code: " << sqlite3_errstr(err) << endl;
            columnNames.clear();
        }
        
        for (int i = 1; i < sqlite3_column_count(stmt); i++) {
            string name = sqlite3_column_name(stmt, i);
            columnNames.push_back(name);
        }
        sqlite3_finalize(stmt);
        return columnNames;
    }

    uniqueDbPtr getDb(sqlite3* db) {
        return uniqueDbPtr(db);
    }
    
    uniqueStmtPtr getStmt(sqlite3* db, string sql) {
        sqlite3_stmt *stmt = nullptr;
        uniqueStmtPtr stmtPtr = nullptr;
        if (int err = sqlite3_prepare_v2(db, sql.c_str(), static_cast<int>(sql.size()), &stmt, nullptr) != SQLITE_OK) {
            cerr << "prepare stmt error code: " << sqlite3_errstr(err) << endl;
            return stmtPtr;
        }
        stmtPtr = uniqueStmtPtr(stmt);
        return stmtPtr;
    }
};
