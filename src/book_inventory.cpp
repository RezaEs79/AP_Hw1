#include"book_inventory.h"

using namespace book;

Books book::read_database(std::string filepath){
    Books arr_book;
    std::vector<std::string> v;
    std::ifstream file(filepath);
    if (!(file.is_open()))
        throw std::runtime_error("Invalid Path!");
    else{
        std::string line = "";
        int i{0},j{0};
        while (getline(file, line)) {
            arr_book.push_back(Book());
            std::stringstream ss(line);
            std::string substr = "";
            while (getline(ss, substr, ',')) {
                v.push_back(substr);
            }
            arr_book[i].title = v[++j];
            arr_book[i].author =  v[++j];
            arr_book[i].cost = std::stof(v[++j]);
            arr_book[i].isbn = v[++j];
            arr_book[i].language_code= v[++j];
            arr_book[i].num_pages =  std::stoi(v[++j]);
            arr_book[i].publisher =  v[++j];
            arr_book[i].count=  std::stoi(v[++j]);
            i++;j=0;
            v.clear();
        }
        i--;
        return arr_book;
    }   
}

std::string book::search(Books inventory, std::string title){
    for (auto q: inventory){        
        if (q.title==title)
            return q.isbn;   
    }
    return "none";
}

bool book::order(Books& inventory, Books& shopinglist, std::string isbn){
    for (auto& q: inventory){
        if (q.isbn==isbn){
            shopinglist.push_back(q);
            q.count--;
            return true;
        }
            
    }
    return false;
}

double book::get_receipt(Books shopinglist){
    std::cout<<"\t"<<std::left << std::setw(80)<<std::cout.fill('*')<<std::cout.fill(' ')<<std::endl; // line
    std::cout <<"\t" << "|" <<"\t" << std::left << std::setw(30)<<"title" <<"|";
    std::cout<<"\t"<<std::setw(15)<<"isbn" << "|" <<"\t" <<std::setw(17) <<"price";
    std::cout<<"|"<<std::endl;
    std::cout<<"\t"<<std::left << std::setw(80)<<std::cout.fill('-')<<std::cout.fill(' ')<<std::endl;
    double sum{0};
    for (auto q: shopinglist){
        if(q.title.length()>25){
            std::string r = q.title.substr(0, 20);
            r=r+"...";
            std::cout <<"\t" << "|" <<"\t" << std::left << std::setw(30)<< r <<"|"<<"\t";
            std::cout<<std::setw(15)<<q.isbn << "|" <<"\t" <<"$ "<<std::setw(15) <<std::setprecision(8)<<q.cost;
            std::cout<<"|"<<std::endl;
            sum += q.cost;
        } else {
            std::cout <<"\t" << "|" <<"\t" << std::left << std::setw(30)<<q.title <<"|"<<"\t";
            std::cout<<std::setw(15)<<q.isbn << "|" <<"\t"<<"$ " <<std::setw(15) <<std::setprecision(8)<<q.cost;
            std::cout<<"|"<<std::endl;
            sum += q.cost;
    
        }
        }
    std::cout<<"\t"<<std::left << std::setw(80)<<std::cout.fill('-')<<std::cout.fill(' ')<<std::endl;
    std::cout <<"\t" << "|"  << std::left << std::setw(38)<<" ";
    std::cout<<std::setw(16)<<" Total price" << "|" <<"\t" <<"$ "<<std::setw(15) <<sum;
    std::cout<<"|"<<std::endl;
    std::cout<<"\t"<<std::left << std::setw(80)<<std::cout.fill('*')<<std::cout.fill(' ')<<std::endl;
    return sum; 
}

