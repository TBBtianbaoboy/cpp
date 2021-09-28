class SearchObj{
    private:
        int *arr;
        int length;
    public:
        SearchObj():arr(nullptr),length(0){}
        SearchObj(int* a,int l):arr(a),length(l){}
        int* getaddr()const {
            return arr;
        }

        int getlength()const {
            return length;
        }
};

class Search{
    public:
        static bool bs(SearchObj&,const int&);
};

bool Search::bs(SearchObj& obj, const int& aim)
{
    int l{},r = obj.getlength();
    int* arr_p = obj.getaddr();
    do {
        int flag = (l+r)/2;
        if(arr_p[flag]==aim)
            return true;
        else if(arr_p[flag]>aim)
            r = flag - 1;
        else 
            l = flag + 1;
    }while (r>=l);
    return false;
}
