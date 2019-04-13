///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef UTIL
#define UTIL

#include <utility>

namespace util
{
    bool Min(std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.second < b.second;
    }

    class Search
    {
    public:
        int val;

        Search(int v) :val(v) {}

        bool operator()(const std::pair<int, int> a) const
        {
            return (a.first == val);
        }
    };

    class stack
    {
    public:
        stack() : s(nullptr), curr_size(0) {}

        // Initiate the stack
        void init(int);

        // Find element in the stack
        int find(int);
        
        // Push element into stack
        void push(int);

        // Pop element from stack
        // void pop();

        // Update the stack
        void update(int);

        int get_size();
    
    private:
        int* s;
        int size;
        int curr_size;
    };

    void stack::init(int size)
    {
        s = new int[size];
        this -> size = size;
    }

    void stack::push(int process)
    {
        for(int i = size-1; i > 0; --i)
        {
            s[i] = s[i-1];
        }

        s[0] = process;

        if(curr_size < size)
            curr_size++;
    }

    int stack::find(int process)
    {
        for(int i = 0; i < size; ++i)
        {
            if(s[i] == process)
                return i;
        }

        return -1;
    }

    void stack::update(int process)
    {
        int pos = find(process);

        for(int i = pos; i > 0; --i)
            s[i] = s[i-1];
        
        s[0] = process;
    }

    int stack::get_size()
    {
        return curr_size;
    }
} // util


#endif /* UTIL */