/***********************************
 * Node declaration
 ***********************************/

class list;

class node
{ friend list;
  public:
    node(string argf="",string argl="",int arga=0);  // Default constructor
    ~node();                                         // Destructor 
    void put(ostream &out);                          // Put
    void fore(ostream &out);                         // Output list forwards
    void back(ostream &out);                         // Output list backwards
    void insert(node *p);                            // Recursive insert
    bool operator == (const node &);                 // Equal
    bool operator < (const node &);                  // Less than
    bool operator > (const node &);                  // Greater than
  private:
    string first,last;
    int age;
    node *next;
};

typedef node * node_ptr;
