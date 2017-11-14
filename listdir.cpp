#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
//#ifdef __cplusplus
/*extern "C" {
#endif
   DIR *opendir(const char *name);
   int closedir(DIR *dirp);
#ifdef __cplusplus
};
#endif
*/
using namespace std;

class cmp {
    public : 
        bool operator()(const string &l, const string &r)  {
            size_t l_idx = 0;
            size_t r_idx = 0;
            while (l_idx < l.length() && r_idx < r.length()) {
                if (tolower(l[l_idx]) > tolower(r[r_idx])) {
                    return true;
                } else if (tolower(l[l_idx]) < tolower(r[r_idx])) {
                    return false;
                }
                l_idx++;
                r_idx++;
            }
            if (l_idx < l.length()) {
                return true;
            }
            return false;
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
