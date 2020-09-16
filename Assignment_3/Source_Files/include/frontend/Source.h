/**
 * Source class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <fstream>
#include <string>

namespace frontend {

using namespace std;

class Source
{
private:
    ifstream source;
    string sourceFileName;
    int  lineNum;      // current source line number
    char currentCh;    // current source character

    //Used for 'peeking' at next character without consuming it
    bool hold;
    char heldCh;

public:
    static const char EOL = '\n';

    /**
     * Constructor
     * @param sourceFileName the source file name.
     */
    Source(string sourceFileName) : lineNum(1),hold(false),heldCh(0)
    {
        source.open(sourceFileName);

        if (source.fail())
        {
            cout << "*** ERROR: Failed to open " << sourceFileName << endl;
            exit(-1);
        }

        currentCh = nextChar();  // read the first character of the file
    }

    /**
     * Getter.
     * @return the current source line number.
     */
    int lineNumber() const { return lineNum; }

    /**
     * Getter.
     * @return the current source character.
     */
    char currentChar() const { return currentCh; }

    /**
     * Read and return the next input source character.
     * @return the character, or EOF if at the end of the file.
     */
    char nextChar()
    {
        if(hold)
        {
            //There is a 'held' character, replace read with load
            hold = false;
            currentCh = heldCh;

            if(heldCh == EOL){
                //Account for 'peeking' possibly incrementing newlines
                lineNum--;
            }
        }
        else{
            //Get next character normally
            currentCh = source.get();
        }

        if (source.eof()) currentCh = EOF;
        else if (currentCh == EOL) lineNum++;

        else if (source.fail())
        {
            cout << "*** ERROR: Failed to read " << sourceFileName << endl;
            exit(-1);
        }

        return currentCh;
    }

    /**
     * Read the next input character without consuming it,
     * such that the next call to 'nextChar' will still return it
     * @return
     */
    char peek()
    {
        char current = currentCh;
        char nextCh = nextChar();
        hold = true;
        heldCh = nextCh;
        currentCh = current;

        return nextCh;
    }
};

}  // namespace frontend

#endif /* SOURCE_H_ */
