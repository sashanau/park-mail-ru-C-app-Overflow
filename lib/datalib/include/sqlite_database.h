#ifndef __SQLite_DATABASE_H__
#define __SQLite_DATABASE_H__

#define UNUSED(x) (void)(x)


#include <iostream>
#include <string>
#include <sqlite3.h>
#include "database.h"


class SQLiteDataBase: public IDataBase {
public:
    explicit SQLiteDataBase(const std::string& db_name);
    SQLiteDataBase(SQLiteDataBase &db) = default;
    SQLiteDataBase &operator = (const SQLiteDataBase &db) = default;
    SQLiteDataBase(SQLiteDataBase &&db) = delete;
    SQLiteDataBase &operator = (const SQLiteDataBase &&db) = delete;

    ~SQLiteDataBase() override;
    const sqlite3& get_connection();

    void select_flats();
    void delete_flats();

    bool add_flat(Flat &flat) override;
    bool add_flats(std::vector<Flat> &flats) override;

    std::vector<Flat> get_all_flats() override;
    std::vector<Flat> get_random_flats(int num) override;

private:
    sqlite3 *connection;
    bool create_tables(char **error_msg);
};


#endif  // __SQLite_DATABASE_H__