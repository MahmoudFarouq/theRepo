#ifndef SORTER_H
#define SORTER_H


class Sorter
{
    public:
        Sorter();
        virtual void Sort(int arr[], int sz) = 0;
        virtual ~Sorter();

    protected:

    private:
};

#endif // SORTER_H
