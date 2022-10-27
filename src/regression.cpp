#include "regression.h"
using namespace regression;

Data regression::read_database(std::string filepath)
{
    Data Data1;
    std::vector<double> v;
    std::ifstream file(filepath);
    if (!(file.is_open()))
        throw std::runtime_error("Invalid Path!");
    else{
    std::string line = "";
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string substr;
        v.push_back(1);
        while (getline(ss, substr, ',')) {

            float num_float = std::stof(substr);
            v.push_back(num_float);
        }
        Data1.push_back(v);
        v.clear();
    }
    file.close();
    return Data1;
    }
}

double regression::hypothesis(std::vector<double> theta, std::vector<double> x)
{
    double res {};
    if(theta.size()!=x.size())
        throw std::logic_error("Invalid Path!");
    else
    for (std::size_t i = 0; i < x.size(); i++)
        res += theta[i] * x[i];
    return res;
}

std::vector<double> regression::update(Data dataset, std::vector<double> theta, double lr)
{
    std::vector<double> v;
    std::vector<double> updated_theta;
    for (std::size_t j = 0; j < theta.size(); j++) {
        double temp = 0;
        for (std::size_t i = 0; i < dataset.size(); i++) {
            v = std::vector<double>(dataset[i].begin(), dataset[i].end() - 1);
            temp += (regression::hypothesis(theta, v) - dataset[i][4]) * dataset[i][j];
        }
        updated_theta[j] = theta[j] - lr * temp;
    }
    return updated_theta;
}

double regression::cost_function(Data dataset, std::vector<double> theta)
{
    double sum { 0 };
    double cost { 0 };
    std::vector<double> v;
    for (std::size_t i = 0; i < dataset.size(); i++) {
        v = std::vector<double>(dataset[i].begin(), dataset[i].end() - 1);
        sum += pow((hypothesis(theta, v) - dataset[i][4]), 2); // Data1[i][4]: fifth column of the ith row in Data1set
    }
    cost = 0.5 * sum;
    return cost;
}

std::vector<double> regression::linear_regression(Data dataset, std::vector<double> init_theta, double lr){
    int i{1000};
    double cost { 0 };
    while(i){
        init_theta = regression::update(dataset, init_theta, lr);
        cost = regression::cost_function(dataset, init_theta);
        std::cout<<i<<"cost is: "<<cost<<std::endl;
        i--;
    }
    return init_theta;
}

