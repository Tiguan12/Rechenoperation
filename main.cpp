//#include "mainwindow.h"
//#include "ui_mainwindow.h""
//#include <QApplication>
//#include <QDebug>
//#include <iostream>
//#include <chrono>
//#include <thread>

//using namespace std;

//double find_Q_min(double Q_t[], int size);

//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    double SOC = 0.0; // State of Charge
//    double SOH = 0.0; // State of Health

//    double t_1 = 1.0; // Startzeit
//    double t_2 = 5.0; // Endzeit

//    double I_t1 = 6.0; // Strom zum Zeitpunkt t_1
//    double I_t2 = 7.0; // Strom zum Zeitpunkt t_2

//    double Q_N = 500.0; // Nennkapazität einer Zelle
//    double Q_0 = 256.34; // Ladung einer vollen Zelle

//    double Array[] = {25.3, 33.4, 55.3, 4.5, 37.64, 55.6, 33.3, 2.3, 12.2, 7.7}; // Mindestladungen für verschiedene Zeitpunkte

//    int reihe = 10, spalte = 3;

//    double** tabelle = new double*[reihe];
//    for (int i = 0; i < reihe; i++) {
//        tabelle[i] = new double[spalte];
//        tabelle[i][0] = Q_0;
//        tabelle[i][1] = SOC;
//        tabelle[i][2] = SOH;

//        double Q_t = (t_2 * I_t2) - (t_1 * I_t1);
//        SOC = ((Q_0 - Q_t) / Q_0) * 100;
//        double min_charge = find_Q_min(Array, i + 1);
//        SOH = ((Q_0 - min_charge) / (Q_N - min_charge)) * 100;

//        qDebug() << "min_charge:" << min_charge;

//        qDebug() << i;
//        qDebug() << "Q_t:" << Q_t;
//        qDebug() << "Q_t:" << tabelle[i][0];
//        qDebug() << "SOC:" << SOC;
//        qDebug() << "SOH:" << SOH;
//        qDebug() << "Hello World";
//        qDebug() << "Q_min:" << min_charge;

//        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 Sekunde
//    }

//    return 0;
//}

//double find_Q_min(double Q_t[], int size) {
//    double Q_min = Q_t[0];
//    for (int i = 1; i < size; i++) {
//        if (Q_t[i] < Q_min) {
//            Q_min = Q_t[i];
//        }
//    }
//    return Q_min;
//}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

double find_Q_min(double Q_t[], int size);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    double SOC = 0.0; // State of Charge
    double SOH = 0.0; // State of Health

    double t_1 = 1.0; // Startzeit
    double t_2 = 5.0; // Endzeit

    double I_t1 = 6.0; // Strom zum Zeitpunkt t_1
    double I_t2 = 7.0; // Strom zum Zeitpunkt t_2

    double Q_N = 500.0; // Nennkapazität einer Zelle
    double Q_0 = 256.34; // Ladung einer vollen Zelle

    double Array[] = {25.3, 33.4, 55.3, 4.5, 37.64, 55.6, 33.3, 2.3, 12.2, 7.7}; // Mindestladungen für verschiedene Zeitpunkte

    int reihe = 10, spalte = 3;

    double** tabelle = new double*[reihe];
    for (int i = 0; i < reihe; i++) {
        tabelle[i] = new double[spalte];
        tabelle[i][0] = Q_0;
        tabelle[i][1] = SOC;
        tabelle[i][2] = SOH;

        double Q_t = (t_2 * I_t2) - (t_1 * I_t1);
        SOC = ((Q_0 - Q_t) / Q_0) * 100;
        double min_charge = find_Q_min(Array, i + 1);
        SOH = ((Q_0 - min_charge) / (Q_N - min_charge)) * 100;

        qDebug() << "min_charge:" << min_charge;

        qDebug() << i;
        qDebug() << "Q_t:" << Q_t;
        qDebug() << "Q_t:" << tabelle[i][0];
        qDebug() << "SOC:" << SOC;
        qDebug() << "SOH:" << SOH;
        qDebug() << "Hello World";
        qDebug() << "Q_min:" << min_charge;

        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 Sekunde
        a.processEvents(); // Events verarbeiten, um die GUI zu aktualisieren
    }

    return a.exec(); // QApplication Ereignisschleife starten
}

double find_Q_min(double Q_t[], int size) {
    double Q_min = Q_t[0];
    for (int i = 1; i < size; i++) {
        if (Q_t[i] < Q_min) {
            Q_min = Q_t[i];
        }
    }
    return Q_min;
}
