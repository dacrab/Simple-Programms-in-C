#include <iostream>
#include <string>

using namespace std;

class Restaurant {
    private:
        string month;
        double receipts[30];
    
    public:
        Restaurant() {
            month = u8"January";
            for (int i = 0; i < 30; i++) {
                receipts[i] = 0.0;
            }
        }
        
        Restaurant(string m, double r[]) {
            month = m;
            for (int i = 0; i < 30; i++) {
                receipts[i] = r[i];
            }
        }
        
        void SetData(string m, double r[]) {
            month = m;
            for (int i = 0; i < 30; i++) {
                receipts[i] = r[i];
            }
        }
        
        double Avg(int start, int end) {
            double sum = 0.0;
            for (int i = start; i <= end; i++) {
                sum += receipts[i];
            }
            return sum / (end - start + 1);
        }
        
        double Min() {
            double minAvg = Avg(0, 9);
            for (int i = 1; i < 21; i++) {
                double avg = Avg(i, i + 9);
                if (avg < minAvg) {
                    minAvg = avg;
                }
            }
            return minAvg;
        }
        
        void GetTenDaysWithLowestReceipts() {
            double minAvg = Min();
            int start = 0;
            for (int i = 0; i < 21; i++) {
                double avg = Avg(i, i + 9);
                if (avg == minAvg) {
                    start = i;
                    break;
                }
            }
            int end = start + 9;
            cout << "The ten-day period with the lowest receipts in the month" << month << "was from the Day" << start + 1 << "until the Day" << end + 1 << "with an average" << minAvg << "." << endl;
        }
        
        string GetMonth() {
            return month;
        }
};

int main() {
    double receipts[30] = {100.23, 45.67, 87.45, 123.56, 78.34, 98.76, 65.43, 54.32, 76.54, 89.67,
                            234.56, 123.45, 345.67, 456.78, 567.89, 678.90, 345.67, 456.78, 567.89, 678.90,
                            123.45, 345.67, 456.78, 567.89, 678.90, 345.67, 456.78, 567.89
};

Restaurant r(u8"January", receipts);
r.GetTenDaysWithLowestReceipts();

return 0;
}
