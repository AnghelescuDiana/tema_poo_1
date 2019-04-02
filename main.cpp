/*Anghelescu Diana Livia
 Grupa 211
 Tema 1 ex.4-Cozi de caractere*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Nod
{
    friend class Coada;
    //friend ostream& operator<<(ostream&, const Nod&);
    //friend istream& operator>>(istream&, const Nod&);

private:
    char val;
public:
    void set_char(char value)
    {
        this->val = value;
    }
    char get_value()
    {
        return this->val;
    }
    friend istream& operator>>(istream& input, Nod &n)
    {
        input>>n.val;
        return input;
    }
    friend ostream& operator<<(ostream& output,const Nod &n)
    {
        output<<n.val;
        return output;
    }
};

class Coada
{
private:
    friend class Nod;
    Nod* my_array,current_array;
    int counter,indx;
    int MAX_SIZE;
public:

    Coada()
    {
        my_array = NULL;
        counter=0;
    }
    Coada(int MAX_SIZE)
    {
        this->counter = MAX_SIZE;
        this->my_array = new Nod[MAX_SIZE];
    }

    ~Coada()
    {
        delete[] this->my_array;
    }

    int get_counter()
    {
        return this->counter;
    }

    void push(char value)
    {

        Nod n;
        n.set_char(value);
        my_array[counter]=n;
        counter++;
    }

    void push(Nod n)
    {
        counter++;
        if(counter>MAX_SIZE)
        {
            cout<<"counter e la max";
            return;
        }

        my_array[counter-1]=n;
    }

    Nod* pop()
    {
        if(counter != 0)
        {

            Nod current_array[counter];
            for(int i = 0; i < counter; i++)
            {
                my_array[i]=my_array[i+1];
            }
            counter--;
        }
        else
        {
            cout << "Nu mai sunt elemente in coada";
        }

    }
    Nod top()
    {
        cout<< this->my_array[0];
    }
    Nod index(int t)
    {
         return this->my_array[t];
    }
    Coada operator+(Coada &coada2)
    {

        Coada coada3 = Coada(100);
        for(int i = 0; i < this->get_counter(); i++)
        {
            coada3.push(this->my_array[i]);

        }
        for(int i = 0; i < coada2.get_counter(); i++)
        {
            coada3.push(coada2.my_array[i]);
        }

        return coada3;
    }

    Coada operator-( Coada &coada2)
    {
        Nod* my_array;
        while (this->top().val == coada2.top().val)
        {
            this->pop();
            coada2.pop();

        }
        cout<<this->my_array;
    }

    int operator[](int indx)
    {
        cout<< this->index(indx).get_value()<<"\n";
        return -1;
    }
    friend istream& operator>>(istream& input, Coada &c)
    {
        for(int i = 0; i < c.get_counter(); i++)
        {
            input>>c.my_array[i];
        }
        return input;
    }
    friend ostream& operator<<(ostream& output, Coada &c)
    {
        for(int i = 0; i < c.get_counter(); i++)
        {
            output<<c.my_array[i]<<" ";
        }
        return output;
    }
};



int main()
{
    //int counter;
    //Coada array[counter];
    /*Coada c1;
    c1 = Coada(5);
    cin>>c1;
    cout<<c1;*/
    int choice, exit_p = 1;
    Coada obj;
    char a;
    obj= Coada(5);
    cin>>obj;

    obj.pop();
    cout<<obj<<"\n";
    cin>>a;

    do
    {


        cout << "\n1.Push \n2.Pop \n3.Top\n 4.[] ";
        cout << "\nSelector: : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            obj.push(a);
            cout<<obj<<"\n";
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.top();
            break;
        case 4: {int i;
                 cin>>i;
                 cout<<obj[i];}break;


        default:
            exit_p = 0;
            break;
        }
    }
    while (exit_p);

    return 0;

}


