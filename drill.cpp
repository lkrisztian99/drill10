#include "std_lib_facilities.h"

struct Points
{
    double x,y;

};





int main(){
    try{

    double x, y;
    vector<Points> original_points;
    cout << "Please enter seven x,y pairs" << endl;
    while(cin >> x >> y){
        original_points.push_back(Points{x,y});
        if(original_points.size() == 6)
            break;
    }
    
    //ofstream        
    ofstream ost {"mydata.txt"};
    if(!ost)
        error("can't open output file 'mydata.txt'");
    for(auto i : original_points){
        ost << i.x << "," << i.y << endl;
    }
    ost.close();

    cout << endl << "Original points: " << endl;
    for(auto i : original_points){
        cout << i.x << ',' << i.y << endl;
    }
    //ifstream
    cout << endl << "Processed points: " << endl;
    vector<string> processed_points;
    ifstream ist {"mydata.txt"};
    if(!ost)
        error("can't open output file 'mydata.txt'");
    string line;
    while(getline(ist,line)){
        processed_points.push_back(line);
    }
    ist.close();
    for(auto i : processed_points){
        cout << i << endl;
    }

    //checking
    if(original_points.size() != processed_points.size())
        cout << "Something's wrong!" << endl;
    

}catch(runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Some error\n";
	return 2;
}
}