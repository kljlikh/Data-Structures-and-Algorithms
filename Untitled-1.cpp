#include <iostream>
using namespace std;

// Cấu trúc sinh viên
struct Student {
    int id;
    string name;
    float score;
    Student* next;
};

// Danh sách liên kết
class StudentList {
private:
    Student* head;         // danh sách hợp lệ
    Student* invalidHead;  // danh sách không hợp lệ

public:
    StudentList() {
        head = NULL;
        invalidHead = NULL;
    }

    // Thêm vào danh sách bất kỳ
    void addToList(Student*& listHead, int id, string name, float score) {
        Student* newStudent = new Student{id, name, score, NULL};

        if (listHead == NULL) {
            listHead = newStudent;
        } else {
            Student* temp = listHead;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newStudent;
        }
    }

    // Thêm sinh viên (có kiểm tra)
    void addStudent(int id, string name, float score) {
        if (score < 0 || score > 10) {
            cout << "Loi: Sinh vien " << name << " co diem khong hop le!\n";
            addToList(invalidHead, id, name, score); // lưu vào danh sách sai
        } else {
            addToList(head, id, name, score); // lưu vào danh sách đúng
        }
    }

    // Hiển thị danh sách
    void displayList(Student* listHead) {
        if (listHead == NULL) {
            cout << "Danh sach rong!\n";
            return;
        }

        Student* temp = listHead;
        while (temp != NULL) {
            cout << temp->id << " - " << temp->name << " - " << temp->score << endl;
            temp = temp->next;
        }
    }

    // Hiển thị tất cả
    void displayAll() {
        cout << "\nDanh sach sinh vien hop le:\n";
        displayList(head);

        cout << "\nDanh sach sinh vien KHONG hop le:\n";
        displayList(invalidHead);
    }

    // Hàm trộn
    Student* merge(Student* a, Student* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->score > b->score) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    // Tách danh sách
    void split(Student* source, Student** front, Student** back) {
        Student* slow = source;
        Student* fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }

    // Merge Sort
    void mergeSort(Student** headRef) {
        Student* head = *headRef;
        if (!head || !head->next) return;

        Student* a;
        Student* b;

        split(head, &a, &b);

        mergeSort(&a);
        mergeSort(&b);

        *headRef = merge(a, b);
    }

    // Sắp xếp danh sách hợp lệ
    void sortStudents() {
        mergeSort(&head);
    }
};

int main() {
    StudentList list;

    list.addStudent(1, "An", 7.5);
    list.addStudent(2, "Binh", 11);
    list.addStudent(3, "Chi", -2);

    list.displayAll();

    list.sortStudents();

    cout << "\nSau khi sap xep danh sach hop le:\n";
    list.displayAll();

    return 0;
}
