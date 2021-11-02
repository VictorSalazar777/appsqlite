//
//  SqliteConnection2.hpp
//  sqlite2
//
//  Created by manuel on 8/3/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#ifndef SqliteConnection2_hpp
#define SqliteConnection2_hpp

#include <sqlite3.h>
#include <memory>

namespace SqliteConnection2 {
    struct DbDeleter {
        void operator()(sqlite3* db) {
            sqlite3_close(db);
        }
    };
    using uniqueDbPtr = std::unique_ptr<sqlite3, DbDeleter>;
    uniqueDbPtr getDb();
}

#endif /* SqliteConnection2_hpp */
