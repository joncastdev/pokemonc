#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main() {    
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "jonathan", "123", "pokemonback", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }

    if (mysql_query(conn, "SELECT id, character_name FROM characters")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }

    res = mysql_store_result(conn);

    // ejemplo con row
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("ID: %s, Character_name: %s\n", row[0], row[1]);
    }

     // ejemplo con array
    //  while ((row =  mysql_fetch_assoc(res)) != NULL) {
    //     printf("ID: %s, Character_name: %s\n", row["id"], row["character_name"]);
    // }
  

    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}