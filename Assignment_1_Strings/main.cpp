#include <iostream>
#include <string>

using namespace std;


string fileExtension (string file) {

    /*find the index where the delim exit*/
    int len;
    size_t pos = file.rfind(".");
    size_t last = file.rfind(" ");
    
    len = last - pos;
    return (file.substr(pos+1, len-1));

}

int fileSize (string file)
{
    int len;
    int size;
    string str;
    size_t pos = file.rfind(" ");
    size_t last = file.rfind("b");
    
    len = last - pos;
    
    if (len != 0)
    {
        size = stoi(file.substr(pos, len));
        return size;
    }
    
    else 
    {
        
        cout << "Please enter the file size : " << endl;
        cin >> size; 
        return size;
    }
}

void TestCase (int line, int* sizeM, int* sizeI, int* sizeF, int* sizeO) 
{
    int i;
    string s, ext;
    int sizeprev;

    for (i = 0; i < line; i++)
    {
        cout << "please enter the file name " << i+1 << "  " << endl;
        cin.ignore();
        getline(cin,s);

        ext = fileExtension(s);
        sizeprev = fileSize(s);


        if (ext == "mp3" || ext == "acc" || ext == "flac")
        {
            *sizeM += sizeprev;
        } 

        else if (ext == "jpg" || ext == "bmp" || ext == "gif")
        {
            *sizeI += sizeprev;
        }

        else if (ext == "mp4" || ext == "avi" || ext == "mkv")
        {
            *sizeF += sizeprev;
        }

        else
        {
            *sizeO += sizeprev;
        }
    }
}


int main(void) {

    int entry, sizeM, sizeI, sizeF, sizeO;

    /*input for number of test cases*/
    cout << "Please enter number of Test Cases: ";
    cin >> entry;

    /*to store the exetension size and number of line in each case*/
    int ExtensionSize[entry][4];
    int lines[entry];

    /*input for lines*/
    cout << "Enter number of line in each test case: ";
    for (int i = 0; i < entry; i++) {
        cin >> lines[i];
    }

    for (int i = 0; i < entry; i++)
    {
        sizeM = 0;
        sizeF = 0;
        sizeI = 0;
        sizeO = 0;
        TestCase(lines[i], &sizeM, &sizeI, &sizeF, &sizeO);
        cout << "music " << sizeM <<"b"<<"\t"<< "images " << sizeI <<"b"<< "\tmovies " << sizeF <<"b"<< "\tothers " << sizeO <<"b"<< endl;
    }

    return 0;

}