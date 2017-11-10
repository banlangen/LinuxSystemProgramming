#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#ifdef __cplusplus
extern "C" {
#endif
   DIR *opendir(const char *name);
   int closedir(DIR *dirp);
#ifdef __cplusplus
};
#endif

using namespace std;

class cmp {
    public : 
        bool operator()(const string &l, const string &r)  {
            return l > r;
        }
};

int main(void) {
    DIR *dir = opendir(".");
    priority_queue<string, vector<string>, cmp> heap;
    struct dirent *de;
    while ((de = readdir(dir)) != NULL) {
        //cout << de->d_name << endl;
        string tmp = de->d_name;
        if (tmp[0] == '.') {
            continue;
        }
        heap.push(tmp);
    }
    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
    return 0;
}
