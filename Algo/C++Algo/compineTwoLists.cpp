#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int>& F(list<int>& f, list<int>& s)
{
    list<int>::iterator fitS = f.begin(), fitE = f.end();         // First Iterator Start, End
    list<int>::iterator sitS = s.begin(), sitE = s.end();         // Second Iterator Start, End
    while(fitS != fitE && sitS != sitE)
    {
        if(*fitS > *sitS){
            f.insert(fitS, *sitS);
            sitS++;
        }else{
            fitS++;
        }
    }
    if(sitS != sitE) f.insert(fitE, sitS, sitE);
    s.clear();
    return f;
}


struct Node
{
    Node(int v = 0, Node* n = 0){value = v; next = n;}

    Node(std::initializer_list<int> args)
    {
        int len = args.size();
        int i = 0;
        Node *temp;
        for(auto&& arg : args)
        {
            if(i == 0){value = arg;temp = this;}
            else{
                temp->next = new Node(arg, 0);
                temp = temp->next;
            }
            if(i == len-1)break;
            i++;
        }
    }
    int value;
    Node* next;
};



Node* F(Node* f, Node* s)
{
    Node* Parent = new Node(-1, f);
    Node* res = Parent;
    while(f != NULL && s != NULL)
    {
        if(f->value >= s->value){
            Parent->next = s;
            Parent = s;
            Node* temp = s->next;
            s->next = f;
            s = temp;
        }
        else{
            Parent = f;
            f = f->next;
        }
    }
    if(f == NULL) Parent->next = s;
    return res->next;
}



int main()
{

    Node *f = new Node({2,5,9,15,36,41});

    Node *s = new Node({1,4,5,8,9,12,15});


    f = F(s, f);
    while(f != NULL)
    {
        cout << f->value << " ";
        f = f->next;
    }

    /*list<int> f = {2,5,9,15,36,41};
    list<int> s = {1,4,5,8,9,12,15};

    F(f, s);

    copy(f.begin(), f.end(), ostream_iterator<int>(cout, " "));*/



    return 0;
}








