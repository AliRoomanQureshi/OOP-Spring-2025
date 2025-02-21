#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
	    string model;
	    float rentalPrice;
	    bool available;
	
	public:
		Car(){
			brand = "Unknown";
			model = "Generic";
			rentalPrice = 0.0;
			available = true;
		}
        void updateDetail(string newBrand, string newModel,float nrP,bool avail){
            brand = newBrand;
            model = newModel;
            rentalPrice = nrP;
            available = avail;
        }
        bool availability(){
            return available;
        }
		void rentalRequest(){
			if(available){
                available = 0;
				cout<<"Car is succesfully rented"<<endl;
			}
			else{
				cout<<"car is Not available to rent";
			}
		}
		void displayCar() {
        cout<<"Brand: "<<brand<<"\nModel: "<<model<<"\nRental Price: $"<<rentalPrice<<"\nAvailability: "<<(available ?"Available":"Rented")<<endl;
    }
};
int main(){
	Car c;
    c.updateDetail("Toyota","Sedan",12.5,true);
	c.displayCar();
    cout<<"\n";
	c.rentalRequest();
    c.displayCar();	
	return 0;
}