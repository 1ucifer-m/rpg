#include<iostream>
#include<vector>    

int main(){

    std::vector<std::string> cookies;
    cookies.reserve(10); // Reserve space for 10 cookies to avoid reallocations
    cookies.push_back("Chocolate Chip");
    cookies.push_back("Oatmeal Raisin");
    cookies.push_back("Peanut Butter");
    cookies.push_back("Snickerdoodle");
    cookies.push_back("Sugar Cookie");
    cookies.push_back("Gingerbread");
    cookies.push_back("Macadamia Nut");
    cookies.push_back("Double Chocolate");
    cookies.push_back("Shortbread");
    cookies.push_back("Lemon Cookie");
    cookies.push_back("Almond Biscotti");

    std::cout << cookies.size() << " types of cookies available." << std::endl;
    std::cout<< cookies.capacity() << " is the capacity of the vector." << std::endl;

    // std::cout << "Welcome to the Cookie Store!" << std::endl;
    // std::cout << "Here are the cookies we have available:" << std::endl;
    // std::cout << "----------------------------------------" << std::endl;
    // std::cout<< cookies[0] << std::endl;
    // std::cout<< cookies[1] << std::endl;
    // std::cout<< cookies[2] << std::endl;
    // std::cout<< cookies[3] << std::endl;
    // std::cout<< cookies[4] << std::endl;
    // std::cout<< cookies[5] << std::endl;
    // std::cout<< cookies[6] << std::endl;
    // std::cout<< cookies[7] << std::endl;
    // std::cout << "----------------------------------------" << std::endl;
    // return 0;

    for(size_t i=0; i< cookies.size();i++){
        std::cout<< cookies[i] << '\n';
    }
}