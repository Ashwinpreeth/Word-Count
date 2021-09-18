#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(int argc, char **argv)
{
        string line, word;
        int word_count=0,line_count=0,arr[30];
        if(argc==2)
        {
                ifstream file;
                file.open(argv[1],ios::in);
                if(!file)
                {
                        cout<<"File does not exist\n";
                }
                else
                {
                        while(!file.eof())
                        {
                                getline(file, line, '.');
                                stringstream String(line);
                                while (String >> word)
                                {
                                        ++word_count;
                                }
                                arr[line_count]=word_count;
                                line_count++;
                                word_count=0;
                        }
                        file.close();
                        cout<<"\n\t\tHistogram\n\n";
                        cout<<"..........................................\n\n";
                        for(int i=0;i<line_count-1;i++)
                        {
                                cout<<i+1<<"\t";
                                for(int j=0; j<arr[i]; j++)
                                {
                                        cout<<"* ";
                                }
                                cout<<arr[i];
                                cout<<endl;
                        }
                }
        }
        else
        {
                cout<<"Enter One file name!!" << endl;
        }
    return 0;
}