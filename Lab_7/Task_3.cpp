#include <iostream>
#include <string>

using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, const string& name, double p, const string& d, const string& dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout<<"Ticket reserved for "<<passengerName<<" on "<<date<<" to "<<destination<<endl;
    }

    virtual void cancel() {
        cout<<"Ticket for "<<passengerName<<" has been canceled."<<endl;
    }

    virtual void displayTicketInfo() {
        cout<<"Ticket ID:"<<ticketID<<", Passenger:"<<passengerName<<", Price:"<<price
            <<", Date:"<<date<<", Destination:"<<destination<<endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, const string& name, double p, const string& d, const string& dest,
                 const string& airline, const string& flightNo, const string& sClass)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flightNo), seatClass(sClass) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout<<", Airline:"<<airlineName<<", Flight:"<<flightNumber<<", Seat Class:"<<seatClass<<endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, const string& name, double p, const string& d, const string& dest,
                const string& tNum, const string& cType, const string& depTime)
        : Ticket(id, name, p, d, dest), trainNumber(tNum), coachType(cType), departureTime(depTime) {}

    void reserve() override {
        cout<<"Train Ticket for "<<passengerName<<" has been auto-assigned a seat."<<endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout<<", Train Number:"<<trainNumber<<", Coach:"<<coachType<<", Departure:"<<departureTime<<endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, const string& name, double p, const string& d, const string& dest,
              const string& company, const string& seatNo)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seatNo) {}

    void cancel() override {
        cout<<"Bus Ticket for "<<passengerName<<" canceled with a last-minute refund."<<endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout<<", Bus Company:"<<busCompany<<", Seat:"<<seatNumber<<endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, const string& name, double p, const string& d, const string& dest,
                  const string& artist, const string& v, const string& sType)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(sType) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout<<", Artist:"<<artistName<<", Venue:"<<venue<<", Seat Type:"<<seatType<<endl;
    }
};

int main() {
    FlightTicket flight(301, "Ali Rooman", 500, "2025-04-10", "Dubai", "Emirates", "EK202", "Business");
    TrainTicket train(302, " Azlan", 100, "2025-05-15", "Lahore", "Green Line", "AC Sleeper", "10:00 AM");
    BusTicket bus(303, "Murtaza", 50, "2025-04-20", "Islamabad", "Daewoo Express", "B12");
    ConcertTicket concert(304, "Wasay", 80, "2025-06-01", "Karachi", "Atif Aslam", "Expo Center", "VIP");

    cout<<"--- Ticket Information ---"<<endl;
    flight.displayTicketInfo();
    train.displayTicketInfo();
    bus.displayTicketInfo();
    concert.displayTicketInfo();

    cout<<"\n--- Reservation Process ---"<<endl;
    train.reserve();
    
    cout<<"\n--- Cancellation Process ---"<<endl;
    bus.cancel();

    return 0;
}
