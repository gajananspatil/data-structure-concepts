#include <vector>

namespace gpds
{

    template<typename TYPE>
    class heap
    {

    private:
        std::vector<TYPE> storage;

    public:

        heap() { }
        
        void push(TYPE data)
        {
            storage.push_back(data);
            upHeapify(storage.size() -1);

        }


        void pop()
        {
            if(storage.size() == 0 )
                return;

            auto data = storage[0];
            storage[0] = storage[ storage.size() -1];
            storage.pop_back();
            
            if(storage.size() > 0 )
                downHeapify(0);

        }

        TYPE peek()
        {
            if( storage.size() > 0 )
                return *storage.begin() ;
            else
                throw;
        }

        size_t size()
        {
            return storage.size();
        }

private:

        void downHeapify(int index)
        { 
            int lc = (2 * index) + 1;
            int rc = (2 * index) + 2;
            
            size_t length = storage.size() -1;

            if(lc > length and rc > length)
                return ;

            if( rc > length  and storage[index] < storage[lc] )
            {
                std::swap(storage[index], storage[lc]);
                index = lc;
            } 
            else if ( storage[index] < storage[lc]  || storage[index] < storage[rc] )
            {
                if(storage[lc] > storage[rc])
                {
                    std::swap(storage[index], storage[lc]);
                    index = lc;
                }
                else
                {
                    std::swap(storage[index], storage[rc]);
                    index = rc;
                }
            }
            else 
                return;

            downHeapify(index);
        }

        void upHeapify(int index)
        {
            if( index == 0 ) 
                return ;

            int  pi = (index - 1) /2 ;

            if(storage[index] > storage[pi])
            {
                std::swap(storage[index], storage[pi] );
                upHeapify(pi);
            }

        }

    };

}
