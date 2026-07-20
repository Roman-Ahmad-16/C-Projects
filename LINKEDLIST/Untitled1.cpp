#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <cstdio>

#pragma comment(lib, "odbc32.lib")

using namespace std;

int main()
{
    int rollNo, marks;

    cout << "Enter Roll No: ";
    cin >> rollNo;

    cout << "Enter Marks: ";
    cin >> marks;

    SQLHENV hEnv;
    SQLHDBC hDbc;
    SQLHSTMT hStmt;

    // Initialize ODBC
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);

    SQLSetEnvAttr(
        hEnv,
        SQL_ATTR_ODBC_VERSION,
        (SQLPOINTER)SQL_OV_ODBC3,
        0
    );

    SQLAllocHandle(
        SQL_HANDLE_DBC,
        hEnv,
        &hDbc
    );

    // Access Database Path
    SQLCHAR connStr[] =
        "Driver={Microsoft Access Driver (*.mdb, *.accdb)};"
        "DBQ=C:\\DB\\Result123.accdb;";

    SQLRETURN ret = SQLDriverConnect(
        hDbc,
        NULL,
        connStr,
        SQL_NTS,
        NULL,
        0,
        NULL,
        SQL_DRIVER_COMPLETE
    );

    if (ret != SQL_SUCCESS &&
        ret != SQL_SUCCESS_WITH_INFO)
    {
        cout << "Database Connection Failed!" << endl;
        system("pause");
        return 1;
    }

    cout << "Database Connected!" << endl;

    SQLAllocHandle(
        SQL_HANDLE_STMT,
        hDbc,
        &hStmt
    );

    char query[200];

    sprintf(
        query,
        "INSERT INTO [Result] ([roll_no], [marks]) VALUES (%d,%d)",
        rollNo,
        marks
    );

    ret = SQLExecDirect(
        hStmt,
        (SQLCHAR*)query,
        SQL_NTS
    );

    if (ret == SQL_SUCCESS ||
        ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "Data Saved Successfully!" << endl;
    }
    else
    {
        cout << "Insert Failed!" << endl;
    }

    // Cleanup
    SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    system("pause");
    return 0;
}
