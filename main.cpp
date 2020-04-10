#include <iostream>
#include <math.h>
#include <vector>

const size_t SCREEN_WIDTH=80;
const size_t MAX_ASTERISK=76;

using namespace std;

vector<double> input_numbers(size_t count)
{

    vector<double> result(count);
    for (size_t i=0; i<count; i++)
    {
        cin>>result[i];
    }
    return result;
}




void find_minmax (vector<double> numbers, double &min, double& max,size_t count)
{
    min=numbers[0];
    for(size_t i=0; i<count; i++)
    {
        if(min>numbers[i])

        {
            min=numbers[i];
        }

    }

    max=numbers[0];
    for(size_t i=0; i<count; i++)
    {
        if(max<numbers[i])

        {
            max=numbers[i];
        }

    }
    return ;
}

vector<size_t> make_histogram(vector<double> numbers,size_t bin_count,double max,double min)
{
    vector<size_t> bins(bin_count,0);
    for(double x:numbers )
    {
        size_t bin_index=(x-min)/(max-min)*bin_count;
        if(bin_index==bin_count)
        {
            bin_index--;
        }
        bins[bin_index]++;
    }
    return bins;
}





void show_histogram_text(vector<size_t> bins, size_t bin_count)
{
    size_t max_bin;
    size_t height;
    double factor;
    max_bin=bins[0];
    for(int i=0; i<bin_count; i++)
    {
        if(bins[i]>max_bin)
        {
            max_bin=bins[i];
        }
    }

    if(max_bin>MAX_ASTERISK)
    {
        factor=MAX_ASTERISK/max_bin;
    }
    else factor=1;
    for(size_t bin:bins)
    {
        height=bin*factor;
    }


    for (size_t bin:bins)
    {
        if (bin<10)
        {
            cout<<" ";
        }
        if (bin<100)
        {
            cout<<" ";
        }

        cout<<bin;
        cout<<"|";
        for(int i=0; i<bin; i++)
        {
            cout<<"*";

        }
        cout<<endl;
    }

}




int main()
{


    size_t number_count;
    cout<<"Enter number count:";
    cin>>number_count;

    const vector<double> numbers=input_numbers(number_count);



    size_t bin_count;
    cout<<"Enter bin_count";
    cin>>bin_count;

//vector<size_t> bins (bin_count,0);
    double min,max;
    find_minmax(numbers,min,max,number_count);
    cout<<"min,max"<<min<<max<<endl;

    vector<size_t> bins=make_histogram(numbers,bin_count,max,min);

    show_histogram_text(bins,bin_count);


    return 0;

}
