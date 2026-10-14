#include <iostream>
#include <cstdio>
#include "Stack.h"


using namespace std;

bool isVoid(string tag) 
{
     string voidElements[] = {
        "area", "base", "br", 
        "col", "embed", "hr",
        "img", "input", "link", 
        "meta", "source", "track", 
        "wbr"
    };

    for (string s : voidElements) {
        if (s == tag) return true;
    }
    return false;
}

int main(int argc, char** argv) {

	//check amount of params
	if (argc < 2) {
		cout << "Not enough arguments! You called: " << argv[0] << endl;
		return EXIT_FAILURE;
	}
	else 
	{
		cout << "OK, You calleds: " << argv[0] << " " << argv[1] << endl;
		FILE* fp = NULL;
		errno_t error = fopen_s(&fp, argv[1], "r");

		if (fp == NULL) 
		{
			cout << "ERROR Opening file: " << argv[1] << endl;
			return EXIT_FAILURE;
		}

		Stack<string> s;
		bool readingInsideTag = false; //true after reading a "<" false after reading a ">"
		bool tagClose = false; //true after reading a "/"
		string currentTagName = ""; //Name of the tag that's being checked
		bool writingTagName = false; //true when writing currentTagName, turned to false after encountering whitespaces
        char c;

		//Read file one char at a time
        while ((c = fgetc(fp)) != EOF) {

            if (c == '<') {
                readingInsideTag = true;
                currentTagName = ""; //clear possible previous name
                writingTagName = true;
                tagClose = false;

                char nextChar = fgetc(fp); //Check for "/" to see if its a closing tag
                if (nextChar != EOF) 
                {
                    if (nextChar == '/') {
                        tagClose = true;
                    }
                    else {
                        currentTagName += nextChar;
                    }
                }
            }
            else if (c == '>' && readingInsideTag) {
                readingInsideTag = false;
                writingTagName = false;

                if (!currentTagName.empty() && isVoid(currentTagName) == false) {
                    if (!tagClose) {
                        s.Push(currentTagName);
                    }
                    else {
                        if (s.IsEmpty()) {
                            cout << "No matching tag found for: </" << currentTagName << "> in stack" << endl;
                            fclose(fp);
                            return EXIT_FAILURE;
                        }

                        //check if popped tag matches
                        string tagOnTop = s.Pop();
                        if (tagOnTop != currentTagName) {
                            cout << "Tags from stack arent matching. Sopped reading at </" << currentTagName << ">, while still expecting </" << tagOnTop << ">." << endl;
                            fclose(fp);
                            return EXIT_FAILURE;
                        }
                    }
                }
            }
            else if (readingInsideTag) {

                //stop writing tag name when encountering a whitespace
                if (isspace(c)) 
                {
                    writingTagName = false;
                }

                else if (writingTagName) 
                {
                    currentTagName += c; //since we didnt hit the ">" yet, keep adding letters to currentTagName
                }

            }
		}
		fclose(fp);
		return EXIT_SUCCESS;

		//Stack<int> s;

		//for (int i = 0; i < 10; i++)
		//{
		//	s.Push(i);
		//	cout << s.Top() << endl;
		//}
		//cout << "-x-x-x-" << endl;
		//for (int i = 0; i < 10; i++)
		//{
		//	int value = s.Pop();
		//	cout << value << endl;
		//}
	}
}