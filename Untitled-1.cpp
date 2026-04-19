#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float score;
    Student* next;
};

int main() {
    Student* head = NULL;
    int n;

    cout << "Nhap so hoc sinh: ";
    cin >> n;
    cin.ignore();

    // Nhập dữ liệu
    for(int i = 0; i < n; i++) {
        Student* sv = new Student;
        cout << "\nHoc sinh " << i+1 << ":\n";
        cout << "ID: "; cin >> sv->id; cin.ignore();
        cout << "Ten: "; getline(cin, sv->name);
        cout << "Diem: "; cin >> sv->score; cin.ignore();
        sv->next = NULL;

        // Thêm vào danh sách
        if(!head) head = sv;
        else {
            Student* t = head;
            while(t->next) t = t->next;
            t->next = sv;
        }
    }

    // Sắp xếp điểm giảm dần 
    for(Student* i = head; i; i = i->next) {
        for(Student* j = i->next; j; j = j->next) {
            if(i->score < j->score) {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->score, j->score);
            }
        }
    }

    // In kết quả
    cout << "\n===DIEM===\n";
    for(Student* p = head; p; p = p->next) {
        cout << p->id << " - " << p->name << " - " << p->score << endl;
    }

    return 0;
}

