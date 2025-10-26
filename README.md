/**
 * Interface yang menyediakan method perhitungan nilai akhir siswa.
 */
public interface Calculated {

    /**
     * Menghitung nilai akhir siswa berdasarkan nilai dan kehadiran.
     *
     * @param s objek {@link Student} yang berisi data nilai dan kehadiran.
     * @return nilai akhir hasil perhitungan.
     */
    static double calculateFinalScore(Student s) {
        return s.getGrade() * School.SCORE_RATE + s.getAttendance() * School.ATTEND_RATE;
    }
}


/**
 * Kelas yang merepresentasikan sistem sekolah untuk menghitung hasil akhir siswa.
 * Mengimplementasikan interface {@link Calculated}.
 */
class School implements Calculated {

    /** Bobot nilai akademik. */
    public static final double SCORE_RATE = 0.8;

    /** Bobot kehadiran siswa. */
    public static final double ATTEND_RATE = 0.2;

    /**
     * Menampilkan hasil perhitungan nilai akhir seluruh siswa.
     *
     * @param s daftar {@link Student} yang akan dihitung nilainya.
     */
    public void printResult(ArrayList<Student> s) {
        System.out.println("=== RESULT(S) ===");
        for (Student s1 : s) {
            double score = Calculated.calculateFinalScore(s1);
            if (score >= 75) {
                System.out.println(s1.getName() + " passed with score :" + score);
            } else {
                System.out.println(s1.getName() + " failed with score :" + score);
            }
        }
    }
}


/**
 * Kelas yang merepresentasikan data siswa.
 */
class Student {
    private String name;
    private int grade;
    private int attendance;

    /**
     * Konstruktor untuk membuat objek siswa baru.
     *
     * @param name nama siswa.
     * @param grade nilai akademik siswa.
     * @param attendance tingkat kehadiran siswa.
     */
    public Student(String name, int grade, int attendance) {
        this.name = name;
        this.grade = grade;
        this.attendance = attendance;
    }

    /** @return nama siswa. */
    public String getName() { return name; }

    /** @param name nama baru untuk siswa. */
    public void setName(String name) { this.name = name; }

    /** @return nilai akademik siswa. */
    public int getGrade() { return grade; }

    /** @param grade nilai akademik baru. */
    public void setGrade(int grade) { this.grade = grade; }

    /** @return kehadiran siswa. */
    public int getAttendance() { return attendance; }

    /** @param attendance kehadiran baru untuk siswa. */
    public void setAttendance(int attendance) { this.attendance = attendance; }
}


/**
 * Kelas utama untuk menjalankan program perhitungan nilai akhir siswa.
 */
public class Mainapp {

    /**
     * Method utama yang menjadi titik awal eksekusi program.
     *
     * @param args argumen baris perintah (tidak digunakan).
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Student> std = new ArrayList<>();
        int jumlah;

        System.out.println("=== CALCULATE FINAL SCORE ===");
        System.out.print("Enter the number of Students: ");
        jumlah = input.nextInt();

        for (int i = 0; i < jumlah; i++) {
            addStudent(std, i);
        }

        School school = new School();
        school.printResult(std);
    }

    /**
     * Menambahkan data siswa baru ke dalam daftar.
     *
     * @param std daftar {@link Student}.
     * @param i indeks siswa saat ini.
     */
    public static void addStudent(ArrayList<Student> std, int i) {
        Scanner input = new Scanner(System.in);
        String name;
        int grade;
        int attend;

        System.out.println("==STUDENT " + (i + 1) + " ==");
        System.out.print("Insert Student Name: ");
        name = input.nextLine();
        System.out.print("Insert Student Grade: ");
        grade = input.nextInt();
        System.out.print("Insert Student Attendance: ");
        attend = input.nextInt();
        System.out.println();

        std.add(new Student(name, grade, attend));
    }
}

