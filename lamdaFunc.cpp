// [ capture clause ] (parameters) -> return-type  
// {   
//    definition of method   
// } 

// auto square = [](int i)
//     {
//         return i * i;
//     };

//comparator lamda function for sorting ;
sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });
