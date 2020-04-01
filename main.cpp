#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

void menuu()
{
    cout<<"What set of numbers do you want to sort?" <<endl;
    cout<<"1. Set of random numbers."<<endl;
    cout<<"2. Set of increasing numbers."<<endl;
    cout<<"3. Set of descending numbers"<<endl;
    cout<<"4. Set of constant numbers"<<endl;
    cout<<"5. Set of A-shaped numbers<<endl;
}

void random(int tabl [], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        tabl[i] = rand() % 2147483647;
    }
    /* for (int k = 0; k < n; k++)
     {
         cout << tabl[k]<<endl;
     }*/
    cout<<endl<<endl<<endl;


}
void increasing( int tabr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tabr[i] = i;
    }
    /* for (int k = 0; k < n; k++)
     {
         cout << tabr[k]<<endl;
     }*/
    cout<<endl<<endl<<endl;
}

void descending( int tabm[], int n)
{
    int helper;
    helper = n + 1;
    for (int i = 0; i < n; i++)
    {
        tabm[i] = helper;
        helper -= 1;
    }
    /* for (int k = 0; k < n; k++)
     {
         cout << tabm[k]<<endl;
     }*/
    cout<<endl<<endl<<endl;

}
void constant(int tabs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tabs[i] = 7;
    }
    /*  for (int k = 0; k < n; k++)
      {
          cout << tabs[k]<<endl;
      }*/
    cout<<endl<<endl<<endl;

}
void A_shaped(int taba[], int n)
{
    int helper = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % 2 == 0)
        {
            if (i <(n / 2))
            {
                helper += 1;
                taba[i] = helper;

            }
            if (i >= (n / 2))
            {
                helper -= 1;
                taba[i] = helper;
            }
        }
        else
        {
            if (i <= (n / 2))
            {
                helper += 1;
                taba[i] = helper;

            }
            if (i > (n / 2))
            {
                helper -= 1;
                taba[i] = helper;
            }
        }
    }
    /* for (int k = 0; k < n; k++)
     {
         cout << taba[k]<<endl;
     }*/
    cout<<endl<<endl<<endl;

}
void selection_sort(int tab[], int n)
{
    int k;
    for( int i = 0; i < n; i++ )
    {
        k = i;
        for( int j = i + 1; j < n; j++ )
            if( tab[ j ] < tab[ k ] )
                k = j;

        swap( tab[ k ], tab[ i ] );
    }
    /*  for (int k = 0; k < n; k++)
      {
          cout << tab[k]<<endl;
      }*/
}

void insertion_sort(int tab[], int n)
{
    int helper, j;
    for(int i=1; i<n; i++)
    {
        helper=tab[i];
        for ( j=i-1; j>=0 && tab[j]>helper; j--)
        {
            tab[j+1] = tab[j];
        }
        tab[j+1]=helper;

    }
    /*  for (int k = 0; k < n; k++)
      {
          cout << tab[k]<<endl;
      }*/
}
void shell_sort (int tab[], int n)
{
    int h, k, i;
    for (h=1; h<n;)
    {
        h=3*h+1;
    }
    h/=9;
    if (h==0)
        h=1;

    while (h)
    {
        for (int j= n-h-1; j>=0; j-- )
        {
            k=tab[j];
            i=j+h;
            while ((i<n) && (k>tab[i]))
            {
                tab[i-h]=tab[i];
                i+=h;
            }
            tab[i-h]=k;
        }
        h/=3;
    }
    /* for (int x = 0; x < n; x++)
     {
         cout << tab[x]<<endl;
     }*/
}

void heap_restoration(int tab[], int n, int i)
{
    int k = i;
    int left=2*i+1;
    int right= 2*i+2;

    if(left<n && tab[1]>tab[k])
        k=left;
    if(right<n && tab[right]> tab[k])
        k=right;
    if (k != i)
    {
        swap(tab[i], tab[k]);
        heap_restoration(tab, n, k);
    }

}
void heap_sort (int tab[],int n)
{
    for(int i=n/2-1; i>=0; i--)
        heap_restoration(tab, n, i);

    for(int i=n-1; i>=0; i--)
    {
        swap(tab[0], tab[i]);
        heap_restoration(tab, i, 0);
    }
    /*  for(int i=0; i<n; i++)
      {
          cout<<tab[i]<<endl;

      }*/
}
void quick_sort_right(int *tab, int left, int right, int x)
{
    if(right <= left) return;
    int i, j;

    i = left - 1;
    j = right + 1;

    while(1)
    {
        while(x>tab[++i]);

        while(x<tab[--j]);

        if( i <= j)
            swap(tab[i],tab[j]);

        else
            break;
    }

    if(j > left)
        quick_sort_right(tab, left, j, tab[j]);
    if(i < right)
        quick_sort_right(tab, i, right, tab[right]);
}

void quick_sort_random(int *tab, int left, int right)
{
    if(right <= left) return;
    int i, j, k, x;
    k=left+int((right-left+1)* rand()/(RAND_MAX+1.0));
    x=tab[k];
    i = left - 1;
    j = right + 1;

    while(1)
    {
        while(x>tab[++i]);

        while(x<tab[--j]);

        if( i <= j)
            swap(tab[i],tab[j]);
        else
            break;
    }
    if(j > left)
        quick_sort_random(tab, left, j);

    if(i < right)
        quick_sort_random(tab, i, right);
}

int main()
{
    int menu,n, c;
    int a=1;
    int tab;
    double stoper;
    clock_t start, stop;
    do
    {
        cout << "Welcome to the program that will sort your life!" << endl<<endl;
        cout << " How do you want to do it?"<<endl;
        cout << "1. Selection sort." << endl;
        cout << "2. Insertion sort." << endl;
        cout << "3. Shell sort." << endl;
        cout << "4. Heap sort." << endl;
        cout << "5. Quick sort (right key)." << endl;
        cout << "6. Quick sort (random key)."<<endl;
        cout << "7. End program." <<endl;
        cin >> menu;

        switch(menu)
        {
        case 1:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start = clock();
            selection_sort(tab, n);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is: "<<time<<"ms"<<endl;
            break;
        }
        case 2:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start=clock();
            insertion_sort(tab, n);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is: "<<time<<"ms"<<endl;
            break;
        }
        case 3:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start=clock();
            shell_sort(tab, n);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is: "<<time<<"ms"<<endl;
            break;
        }
        case 4:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start=clock();
            heap_sort(tab, n);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is: "<<time<<"ms"<<endl;
            break;

        }
        case 5:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start=clock();
            quick_sort_right(tab, 0, n-1, tab[n-1]);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is "<<time<<"ms"<<endl;
            /* for(int k=0; k<n; k++)
             {
                 cout<<tab[k]<<endl;
             }*/
            break;
        }
        case 6:
        {
            menuu();
            cin>>c;
            cout << "Enter the size of the array: " << endl;
            cin >> n;
            int *tab=new int [n];
            if (c==1)
                random(tab, n);
            if (c==2)
                increasing(tab, n);
            if (c==3)
                descending(tab, n);
            if (c==4)
                constant(tab, n);
            if (c==5)
                A_shaped(tab, n);
            start=clock();
            quick_sort_random(tab, 0, n-1);
            stop = clock();
            long time=(long)(stop-start);
            cout<<"The algorithm time is: "<<time<<"ms"<<endl;
            /* for(int k=0; k<n; k++)
             {
                 cout<<tab[k]<<endl;
             }*/
            break;
        }
        case 7:
        {
            cout<<"Thank you for using the program."<<endl;
            a=0;
            break;
        }
        default:
            cout<<"There is no such sorting. Goodnight :)"<<endl;
            break;
        }
    }
    while(a==1);
    return 0;
}
