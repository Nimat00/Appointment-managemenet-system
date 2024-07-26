#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Appointment {
    string date;
    string time;
    string description;
};

class AppointmentManager {
private:
    vector<Appointment> appointments;

public:
    void addAppointment(const string& date, const string& time, const string& description) {
        Appointment appt = {date, time, description};
        appointments.push_back(appt);
        cout << "\nAppointment added successfully!" << endl;
    }

    void viewAppointments() const {
        if (appointments.empty()) {
            cout << "\nNo appointments to show." << endl;
            return;
        }

        cout << "\n" << setw(12) << "Date" << setw(10) << "Time" << setw(30) << "Description" << endl;
        cout << string(52, '-') << endl;

        for (const auto& appt : appointments) {
            cout << setw(12) << appt.date << setw(10) << appt.time << setw(30) << appt.description << endl;
        }
    }

    void deleteAppointment(const string& date, const string& time) {
        auto it = remove_if(appointments.begin(), appointments.end(), [&date, &time](const Appointment& appt) {
            return appt.date == date && appt.time == time;
        });

        if (it != appointments.end()) {
            appointments.erase(it, appointments.end());
            cout << "\nAppointment deleted successfully!" << endl;
        } else {
            cout << "\nAppointment not found." << endl;
        }
    }
};

void printHeader() {
    cout << "\n===================================" << endl;
    cout << "        Appointment Manager        " << endl;
    cout << "===================================" << endl;
}

int main() {
    AppointmentManager manager;
    int choice;

    do {
        printHeader();
        cout << "\n1. Add Appointment" << endl;
        cout << "2. View Appointments" << endl;
        cout << "3. Delete Appointment" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Ignore leftover newline character

        if (choice == 1) {
            string date, time, description;
            cout << "\nEnter date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter time (HH:MM): ";
            getline(cin, time);
            cout << "Enter description: ";
            getline(cin, description);

            manager.addAppointment(date, time, description);
        } else if (choice == 2) {
            manager.viewAppointments();
        } else if (choice == 3) {
            string date, time;
            cout << "\nEnter date (YYYY-MM-DD) of appointment to delete: ";
            getline(cin, date);
            cout << "Enter time (HH:MM) of appointment to delete: ";
            getline(cin, time);

            manager.deleteAppointment(date, time);
        } else if (choice != 4) {
            cout << "\nInvalid choice, please try again." << endl;
        }
    } while (choice != 4);

    cout << "\nExiting program. Goodbye!" << endl;
    return 0;
}
