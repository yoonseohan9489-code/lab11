#pragma once //헤더가드
#include <iostream>
#include <string>
namespace HanYoonseo2649055
{
    class book
    {
        std::string title;
        int id;     
        int price;  //price: 0~50000 won
        void testID() //id: 1~1000
        {
            if(id < 1 || id > 1000)
            {
                std::cout << "Invalid book id\n";
                std::exit(1);
            }
        }
        void testPrice() //price: 0~50000 won
        {
            if(price < 0 || price > 50000)
            {
                std::cout << "Invalid book price\n";
                std::exit(1);
            }
        }
    public:
        book(const std::string& t = "no title yet", int d = 1, int p = 0)
        :title{t}, id{d}, price{p}
        {
            testID(); testPrice();
        }// book b; b.input(std::cin);

        void input(std::istream& is = std::cin)// book b; b.input;
        { //std::cin --> is
            std::cout << "Enter book title: ";
            std::getline(is >> std::ws, title);//std::cin >> title;
            std::cout << "Enter book id: ";
            is >> id; testID();
            std::cout << "Enter book price: ";
            is >> price; testPrice();
        }
        friend std::istream& operator>>(std::istream& is, book& b)
        {
            b.input(is);
            return is;
        }
        void setID(int d){id = d; testID();}
        void setPrice(int p){price = p; testPrice();}
        void setTitle(const std::string& t){title = t;}
        void print(std::ostream& os = std::cout) const //book b; b.print();
        {
            os << title << "(";
            os.width(4); os.fill('0');
            os << id << "): " <<price << "won\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const book& b)
        {//-출력연산자<<: print함수를 이용
            b.print(os);
            return os;
        }
        const std::string& getTitle() const {return title;}
        int getID() const {return id;}
        int getPrice() const {return price;}
        book operator++(){return book{title, id, ++price};}
        book operator++(int)
        {
            book temp{title, id, price};
            price++;
            return temp;
            //return book{id, price++};
        }
        friend bool operator==(const book& b1, const book& b2)
        {
            return b1.id == b2.id && b1.price == b2.price;
        }
        friend int operator+(const book& b1, const book& b2)
        {
            return b1.price + b2.price;
        }

    };
} 