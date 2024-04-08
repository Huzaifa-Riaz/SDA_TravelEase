using namespace std;
#include <iostream>
#include <vector>
#include<string>

/*
                            DESCRIPTION:

User Management: The system has a User class as a foundation, with specialized subclasses for Employee, Customer, and Admin.
                  This handles authentication (login/logout) and basic user profile management.

Booking System: Flight and Hotel classes inherit from an abstract Booking class.
                The prototype pattern is used to efficiently create new bookings based on existing ones.

Itinerary Management: The Itinerary class allows customers to plan their trips, including dates, destinations, a list of associated bookings, and additional notes.

Reviews:Customers can leave reviews with the Review class, storing ratings and textual feedback.

Payment: The Payment class handles payment details and related transactions.

Administration: The Admin class (using the singleton pattern) provides functions to manage employees within the system.

*/


class User {
private:
    int user_id; // Unique identifier for each user
    string username;
    string password;
    string address;
    string cnic; 
    string name;
    int phone_number;
    string user_email;

public:
    bool login(int user_id, string password); // Authenticates a user 
    void logout(); // Ends a user's session
    void Register(); // Method for new user registration

};

class Employee : public User {
private:
    int empId; // Unique identifier for each employee
    string role; // Employee's job title or function

public:
    int addBooking(int cust_id); // Creates a new booking for a customer
    void cancelBooking(int booking_id);
    void editBooking(int booking_id);
    void addCustomer(); // Adds a new customer to the system
    void deleteCustomer(int cust_id);
    void editCustomer(int cust_id);
    int processPayment(int booking_id, int cust_id); // Handles payment transactions
};

class Customer : public User {
private:
    int cust_id; // Unique identifier for each customer

public:
    void trackBooking(int cust_id); // Allows customers to view their booking status
    void getHelp(int cust_id); // Provides a way for customers to get assistance 
    bool checkAvaiabliltyofFlight(int flight_id); // Checks flight availability 
    bool checkAvaiabliltyofHotel(int hotel_id); // Checks hotel availability 
};



class Review {
private:
    int review_id;
    int cust_id;
    string statement;
    int rating;
public:
    void addReview();
    void deleteReview();
    void editReview();


};

///                                             SINGLETON PATTERN USED HERE


class Admin : public User {
private:
    int admin_id;
    static Admin* userAdmin; // Static member to hold the instance

    // Constructor and assignment operators
    Admin();
    Admin(const Admin&);
    Admin& operator=(const Admin&);
public:
    static Admin* getInstance(int user_id, string password);  
    void addEmployee();
    void deleteEmployee();
    void editEmployee();


};


class Itinerary {
private:
    int itinerary_id;
    int cust_id;
    string start_date; 
    string end_date;
    string status;
    vector<string> destinations;
    vector<int> bookings;
    string additional_notes;

public:


    // Methods
    void add_booking(int booking_id);
    void remove_booking(int booking_id);
    double calculate_cost();
    void view_itinerary_details();
    void modify_itinerary();
};


////                                                PROTOTYPE PATTERN USED HERE



class Booking {
private:
    int booking_id;
    int payment_id;
    int cust_id;
    string bookingType;

public:
    void viewDetails(int id);
    void viewImages(int id);
    virtual ~Booking() = default; 
    virtual Booking* clone() const = 0; // Abstract clone method for prototype design pattern
};


class Flight : public Booking {
private:
    int flight_id;
    string flight_arrival;
    string flight_departure;
    string flight_company;
    vector<string> images;
        
public:

    Booking* clone() const override {
        return new Flight(*this);
    }

    void viewDetails(int flight_id);
    void viewImages(int flight_id);
};





class Hotel : public Booking {
private:
    int hotel_id;
    string hotel_name;
    string hotel_address;
    bool availability;
    vector<string> images;

public:

    Hotel* clone() const override {
        return new Hotel(*this);
    }

    void viewDetails(int hotel_id);
    void viewImages(int hotel_id);
};

class Payment {
private:
    int payment_id;
    int booking_id;
    int amount;
    string date;
    int cust_id;

public:
    void display_payment_info();
    void save_payment_details();
    void modify_payment_details();
};
