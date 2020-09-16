/**
 * Token class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#include <string>
#include <map>
#include <ctype.h>

#include "Object.h"
#include "frontend/Token.h"

namespace frontend {

using namespace std;

map<string, TokenType> Token::reservedWords;

void Token::initialize()
{
    reservedWords["PROGRAM"]    = PROGRAM;
    reservedWords["BEGIN"]      = BEGIN;
    reservedWords["END"]        = END;
    reservedWords["REPEAT"]     = REPEAT;
    reservedWords["UNTIL"]      = UNTIL;
    reservedWords["WRITE"]      = WRITE;
    reservedWords["WRITELN"]    = WRITELN;

    //Newly added tokens
    reservedWords["DIV"]        = DIV;
    reservedWords["MOD"]        = MOD;
    reservedWords["AND"]        = AND;
    reservedWords["OR"]         = OR;
    reservedWords["NOT"]        = NOT;
    reservedWords["CONST"]      = CONST;
    reservedWords["TYPE"]       = TYPE;
    reservedWords["VAR"]        = VAR;
    reservedWords["PROCEDURE"]  = PROCEDURE;
    reservedWords["FUNCTION"]   = FUNCTION;
    reservedWords["WHILE"]      = WHILE;
    reservedWords["DO"]         = DO;
    reservedWords["FOR"]        = FOR;
    reservedWords["TO"]         = TO;
    reservedWords["DOWNTO"]     = DOWNTO;
    reservedWords["IF"]         = IF;
    reservedWords["THEN"]       = THEN;
    reservedWords["ELSE"]       = ELSE;
    reservedWords["CASE"]       = CASE;
    reservedWords["OF"]         = OF;
}

Token *Token::Word(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    // Loop to get the rest of the characters of the word token.
    // Append letters and digits to the token.
    for (char ch = source->nextChar(); isalnum(ch); ch = source->nextChar())
    {
        token->text += ch;
    }

    // Is it a reserved word or an identifier?
    string upper = toUpperCase(token->text);
    if (Token::reservedWords.find(upper) != Token::reservedWords.end())
    {
        token->type = Token::reservedWords[upper];
    }
    else
    {
        token->type = TokenType::IDENTIFIER;
    }

    return token;
}

Token *Token::Number(char firstChar, Source *source)
{
    /*bool isNegative = false;
    if(firstChar == '-'){
        isNegative = true;
        firstChar = source->nextChar();
    }*/

    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();
    int pointCount = 0;

    // Loop to get the rest of the characters of the number token.
    // Append digits to the token.
    for (char ch = source->nextChar();
         isdigit(ch) || (ch == '.');
         ch = source->nextChar())
    {
        if (ch == '.') pointCount++;
        token->text += ch;
    }

    // Integer constant.
    if (pointCount == 0)
    {
        token->type    = TokenType::INTEGER;
        token->value.L = stol(token->text);
        token->value.D = token->value.L;  // allow using integer value as double
    }

    // Real constant.
    else if (pointCount == 1)
    {
        token->type    = TokenType::REAL;
        token->value.D = stod(token->text);
    }

    else tokenError(token, "Invalid number");

    /*if(isNegative){
        token->value.L = -1 * token->value.L;
        token->value.D = -1 * token->value.D;
    }*/
    return token;
}

Token *Token::String(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);  // the leading '
    token->lineNumber = source->lineNumber();

    // Loop to append the rest of the characters of the string,
    bool EOS = false; //End-of-String
    for (char ch = source->nextChar();!EOS; ch = source->nextChar())
    {
        //Check if we've reached the end of the file
        if(ch == EOF)
        {
            //Reached end of file
            tokenError(token, "String not closed");
            token->type = TokenType::ERROR;
            return token;
        }
        else if(ch == '\'')
        {
            //Check if it is the end of string or literal quote
            char nextChar = source->nextChar();
            if(nextChar != '\'')
            {
                //End of string
                EOS = true;
                token->text += ch;
                break;
            }
        }

        token->text += ch;
    }

    token->type = TokenType::STRING;

    // Don't include the leading and trailing '.
    token->value.S = token->text.substr(1, token->text.length() - 2);

    return token;
}

Token *Token::SpecialSymbol(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    switch (firstChar)
    {

        case ';' : token->type = TokenType::SEMICOLON;  break;
        case '+' : token->type = TokenType::PLUS;       break;
        case '-' : token->type = TokenType::MINUS;      break;
        case '*' : token->type = TokenType::STAR;       break;
        case '/' : token->type = TokenType::SLASH;      break;
        case '=' : token->type = TokenType::EQUALS;     break;
        case '(' : token->type = TokenType::LPAREN;     break;
        case ')' : token->type = TokenType::RPAREN;     break;

        //Newly added
        case ',' : token->type = TokenType::COMMA;      break;
        case '[' : token->type = TokenType::LBRACKET;   break;
        case ']' : token->type = TokenType::RBRACKET;   break;
        case '^' : token->type = TokenType::CARAT;     break;

        case '.' :
        {
            char nextChar = source->peek();

            //Is it the .. symbol?
            if (nextChar == '.')
            {
                token->text += source->nextChar();
                token->type = TokenType::DOT_DOT;
            }

            // It's just the . symbol
            else
            {
                token->type = TokenType::PERIOD;
            }

            break;
        }

        case '<' :
        {
            char nextChar = source->peek();

            // Is it the <> symbol?
            if (nextChar == '>')
            {
                token->text += source->nextChar();
                token->type = TokenType::NOT_EQUALS;
            }

            // Is it the <= symbol?
            else if (nextChar == '=')
            {
                token->text += source->nextChar();
                token->type = TokenType::LESS_EQUALS;
            }

            // It's just the < symbol
            else
            {
                token->type = TokenType::LESS_THAN;
            }

            break;
        }

        case '>' :
        {
            char nextChar = source->peek();

            // Is it the >= symbol?
            if (nextChar == '=')
            {
                token->text += source->nextChar();
                token->type = TokenType::GREATER_EQUALS;
            }

            // It's just the > symbol
            else
            {
                token->type = TokenType::GREATER_THAN;
            }

            break;
        }

        case ':' :
        {
            char nextChar = source->peek();

            // Is it the := symbol?
            if (nextChar == '=')
            {
                token->text += source->nextChar();
                token->type = TokenType::COLON_EQUALS;
            }

            // No, it's just the : symbol.
            else
            {
                token->type = TokenType::COLON;
                return token;  // already consumed :
            }

            break;
        }

        case EOF : token->type = END_OF_FILE; break;

        default:{
            tokenError(token, "Invalid Token");
            token->type = TokenType::ERROR;
        }
    }

    source->nextChar();  // consume the special symbol
    return token;
}

void Token::tokenError(Token *token, string message)
{
    printf("TOKEN ERROR at line %d: %s at '%s'\n",
           token->lineNumber, message.c_str(), token->text.c_str());
}

}  // namespace frontend
