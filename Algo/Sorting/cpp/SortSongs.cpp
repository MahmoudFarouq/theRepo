#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PutUnTitledFirst(vector<string> &SongsLibrary, int& start, int& len)
{
    for(int i = 0; i < len; i++)
    {
        int UntitledIndex = SongsLibrary[i].find("Untitled", 0);
        if(UntitledIndex != 0)  //not at first
            continue;
        if(UntitledIndex == -1)    //not found
            continue;
        string temp = SongsLibrary[i];
        SongsLibrary[i] = SongsLibrary[start];
        SongsLibrary[start] = temp;
        start++;
    }
}

void SortRest(vector<string> &SongsLibrary, int& start, int& len)
{
    for(int i = start; i < len; i++)
    {
        string minSong = SongsLibrary[i];
        int index = i;
        for(int j = i; j < len; j++)
        {
            if( SongsLibrary[j] < minSong )
            {
                minSong = SongsLibrary[j];
                index = j;
            }
        }
        string temp = SongsLibrary[i];
        SongsLibrary[i] = SongsLibrary[index];
        SongsLibrary[index] = temp;
    }
}

void BiasedSort(vector<string> &SongsLibrary)
{
    int start = 0;
    int len = SongsLibrary.size();
    PutUnTitledFirst(SongsLibrary, start, len);
    SortRest(SongsLibrary, start, len);

}
void BiasedSort_(vector<string> &SongsLibrary)
{
    int start = 0;
    int len = SongsLibrary.size();
    PutUnTitledFirst(SongsLibrary, start, len);
    sort(&SongsLibrary[0], &SongsLibrary[start]);
    sort(&SongsLibrary[start], &SongsLibrary[SongsLibrary.size()]);
}
void BiasedSort__(vector<string> &SongsLibrary)
{
    int start = 0;
    int len = SongsLibrary.size();
    SortRest(SongsLibrary, start, len);
    PutUnTitledFirst(SongsLibrary, start = 0, len);
}

int main()
{
    vector<string> library;
    library.push_back("assdvsv");
    library.push_back("asdvxczx");
    library.push_back("asvasdv");
    library.push_back("asdvzx");
    library.push_back("Untitled3");
    library.push_back("Untitled2");

    BiasedSort__(library);

    int len = library.size();
    for(int i = 0; i < len; i++)
        cout << library[i] << endl;
    return 0;
}
