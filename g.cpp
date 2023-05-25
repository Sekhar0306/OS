#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
// Check if a string is a keyword
bool isKeyword(const string& str) {
vector<string> keywords;
keywords.push_back("if");
keywords.push_back("else");
keywords.push_back("while");
keywords.push_back("for");
keywords.push_back("int");
keywords.push_back("float");
keywords.push_back("char");
keywords.push_back("void");
    // Add more keywords as needed
return find(keywords.begin(), keywords.end(), str) != keywords.end();
}
// Check if a character is an operator
bool isOperator(char c)
{
    string operators = "+-*/=";
    return operators.find(c) != string::npos;
}
// Check if a character is a special symbol
bool isSpecialSymbol(char c)
{
    string symbols = "(){}[],;.";
    return symbols.find(c) != string::npos;
}
int main() {
    string sourceCode;
    // Read the source program from user input
    cout << "Enter the source program:\n";
    getline(cin, sourceCode);
    string token;
    regex identifierRegex("[a-zA-Z_][a-zA-Z0-9_]*");
    sregex_iterator it(sourceCode.begin(), sourceCode.end(), identifierRegex);
        sregex_iterator end;
    // Lexical analysis
    while (it != end) {
    string identifier = it->str(); if (isKeyword(identifier)) {
    cout << "Keyword: " << identifier << endl; } else {
    cout << "Identifier: " << identifier << endl; }
    ++it; }
    return 0;
}
