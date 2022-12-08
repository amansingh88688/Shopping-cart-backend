#include <bits/stdc++.h>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 40),
    Product(2, "mango", 30),
    Product(3, "guava", 50),
    Product(4, "banana", 60),
    Product(5, "strawberry", 100),
    Product(6, "pineapple", 80)};

Product *chooseProduct()
{

    string productList;
    cout << "Available Products" << endl;

    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;

    cout << "-----------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product Not found!" << endl;
    return NULL;
}


bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in Cash : ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thank you for Shopping  <3";
        return true;
    }

    else{
        cout<<"Not enough Cash!"<<endl;
        return false;
    }

}


int main()
{

    char action;
    Cart cart;

    while (true)
    {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if (action == 'a')
        {
            Product * product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }

        }
        else if (action == 'v')
        {
            cout<<"---------------------"<<endl;
            cout<<cart.viewCart()<<endl;
            cout<<"---------------------"<<endl;   
        }
        else
        {
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }

    return 0;
}
