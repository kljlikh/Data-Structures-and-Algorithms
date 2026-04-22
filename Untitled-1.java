import java.util.*;

class Student {
    int id;
    String name;
    float score;

    public Student(int id, String name, float score) {
        this.id = id;
        this.name = name;
        this.score = score;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> list = new ArrayList<>();

        System.out.print("Nhap so hoc sinh: ");
        int n = sc.nextInt();
        sc.nextLine();

        // Nhập dữ liệu
        for (int i = 0; i < n; i++) {
            System.out.println("\nHoc sinh " + (i + 1) + ":");

            System.out.print("ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Ten: ");
            String name = sc.nextLine();

            System.out.print("Diem: ");
            float score = sc.nextFloat();
            sc.nextLine();

            list.add(new Student(id, name, score));
        }

        // Sắp xếp giảm dần theo điểm
        Collections.sort(list, (a, b) -> Float.compare(b.score, a.score));

        // In kết quả
        System.out.println("\n===DIEM===");
        for (Student s : list) {
            System.out.println(s.id + " - " + s.name + " - " + s.score);
        }

        sc.close();
    }
}