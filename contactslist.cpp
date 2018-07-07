struct TrieNode
{
    bool EOW;
    TrieNode *child[26];  
    int count;
};

TrieNode* getNode()
{
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));
    for(int i=0;i<26;i++)
        node -> child[i] = NULL;
    node -> count = 0;
    node -> EOW = false;
    return node;
}

TrieNode* insert(TrieNode* root, string s)
{
    TrieNode* p = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(!p->child[x])
            p->child[x] = getNode();
        p = p->child[x];
        // cout<<p->count<<" -- ";
        p->count++;
        // cout<<p->count<<" ";
    }
    // cout<<endl;
    p->EOW = true;
    return root;
}

void search(TrieNode* root, string s)
{
    int num = 0;
    TrieNode* p = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(p -> child[x])
            p = p->child[x];
        else
        {
            cout<<0<<endl;
            return;
        }
    }
    cout<<p->count<<endl;
    return;
}

void contacts(TrieNode* &root, string op, string contact)
{
    if(op == "add")
        root = insert(root, contact);
    else
        search(root,contact);
}
