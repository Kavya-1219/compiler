#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[100];
    int type; 
    int scope; 
    int lineNo;
} Symbol;
typedef struct {
    Symbol* symbols;
    int size;
    int capacity;
} SymbolTable;

SymbolTable* createSymbolTable(int capacity) {
    SymbolTable* symbolTable = (SymbolTable*)malloc(sizeof(SymbolTable));
    symbolTable->symbols = (Symbol*)malloc(sizeof(Symbol) * capacity);
    symbolTable->size = 0;
    symbolTable->capacity = capacity;
    return symbolTable;
}

void insertSymbol(SymbolTable* symbolTable, char* name, int type, int scope, int lineNo) {
    if (symbolTable->size == symbolTable->capacity) {
        printf("Symbol table is full. Cannot insert symbol %s.\n", name);
        return;
    }
    strcpy(symbolTable->symbols[symbolTable->size].name, name);
    symbolTable->symbols[symbolTable->size].type = type;
    symbolTable->symbols[symbolTable->size].scope = scope;
    symbolTable->symbols[symbolTable->size].lineNo = lineNo;
    symbolTable->size++;
}
int searchSymbol(SymbolTable* symbolTable, char* name) {
    for (int i = 0; i < symbolTable->size; i++) {
        if (strcmp(symbolTable->symbols[i].name, name) == 0)
            return i;
    }
    return -1;
}

void printSymbolTable(SymbolTable* symbolTable) {
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolTable->size; i++) {
        printf("Name: %s, Type: %d, Scope: %d, Line No: %d\n",
               symbolTable->symbols[i].name,
               symbolTable->symbols[i].type,
               symbolTable->symbols[i].scope,
               symbolTable->symbols[i].lineNo);
    }
}

int main() {
    SymbolTable* symbolTable = createSymbolTable(10);
    insertSymbol(symbolTable, "x", 1, 1, 5);
    insertSymbol(symbolTable, "y", 1, 1, 6);
    insertSymbol(symbolTable, "main", 2, 1, 1);
    printSymbolTable(symbolTable);
    printf("Search result for 'x': %d\n", searchSymbol(symbolTable, "x"));
    printf("Search result for 'z': %d\n", searchSymbol(symbolTable, "z"));
    return 0;
}
