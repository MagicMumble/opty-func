import java.io.File;

public class Binding {

    public native double rastrigin_function(double[] mas);
    public native double sphere_function(double[] mas);
    public native double stibinski_tanga_function(double[] mas);
    public native double ekli_function(double[] mas);
    public native double rosenbrock_function(double[] mas);
    public native double bill_function(double[] mas);
    public native double goldman_price_function(double[] mas);
    public native double boot_function(double[] mas);
    public native double bookin_function(double[] mas);
    public native double matias_function(double[] mas);
    public native double levi_function(double[] mas);
    public native double three_hump_camel_function(double[] mas);
    public native double easom_function(double[] mas);

    public native double get_execution_time();

    public native double[] hooke_jeeves_method(double[] mas, String s, double[] res, float err);
    public native double[] luus_jaakola_method(double[] mas, String s, double[] res, float err);
    public native double[] competing_points_method(double[] mas, String s, double[] res);

    public native double[] get_min_x_rastrigin_function(double[] res);
    public native double[] get_min_x_sphere_function(double[] res);
    public native double[] get_min_x_stibinski_tanga_function(double[] res);
    public native double[] get_min_x_ekli_function(double[] res);
    public native double[] get_min_x_rosenbrock_function(double[] res);
    public native double[] get_min_x_bill_function(double[] res);
    public native double[] get_min_x_goldman_price_function(double[] res);
    public native double[] get_min_x_boot_function(double[] res);
    public native double[] get_min_x_bookin_function(double[] res);
    public native double[] get_min_x_matias_function(double[] res);
    public native double[] get_min_x_levi_function(double[] res);
    public native double[] get_min_x_three_hump_camel_function(double[] res);
    public native double[] get_min_x_easom_function(double[] res);

    static {
        System.load("/home/" + System.getProperty("user.name") + "/.local/share/opty-func/binding_java/lib_bind_func_opt.so");
    }

    private static void print_mas(String method, double[] mas) {
        System.out.println(method + ":");
        for (double ma : mas) {
            System.out.print(ma + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Binding b = new Binding();
        double[] mas = {6.0, 2.0};
        double res[] = new double[mas.length];

        System.out.println(b.rastrigin_function(mas));
        System.out.println(b.stibinski_tanga_function(mas));
        System.out.println(b.ekli_function(mas));
        System.out.println(b.sphere_function(mas));
        System.out.println(b.rosenbrock_function(mas));
        System.out.println(b.bill_function(mas));
        System.out.println(b.goldman_price_function(mas));
        System.out.println(b.boot_function(mas));
        System.out.println(b.bookin_function(mas));
        System.out.println(b.matias_function(mas));
        System.out.println(b.levi_function(mas));
        System.out.println(b.three_hump_camel_function(mas));
        System.out.println(b.easom_function(mas));

        print_mas("Hooke_jeeves_method", b.hooke_jeeves_method(mas, "Rastrigin_func", res, 0.001f));
        print_mas("Luus_Jaakola_method", b.luus_jaakola_method(mas, "Rastrigin_func", res, 0.001f));
        print_mas("Competing_points_method", b.competing_points_method(mas, "Rastrigin_func", res));

        System.out.println("Time of competing points method: " + b.get_execution_time());

        print_mas("Mix x for rastrigin func", b.get_min_x_rastrigin_function(res));
        print_mas("Mix x for stibinski tanga func", b.get_min_x_stibinski_tanga_function(res));
        print_mas("Mix x for elki func", b.get_min_x_ekli_function(res));
        print_mas("Mix x for sphere func", b.get_min_x_sphere_function(res));
        print_mas("Mix x for rosenbrock func", b.get_min_x_rosenbrock_function(res));
        print_mas("Mix x for bill func", b.get_min_x_bill_function(res));
        print_mas("Mix x for goldman price func", b.get_min_x_goldman_price_function(res));
        print_mas("Mix x for boot func", b.get_min_x_boot_function(res));
        print_mas("Mix x for bookin func", b.get_min_x_bookin_function(res));
        print_mas("Mix x for matias func", b.get_min_x_matias_function(res));
        print_mas("Mix x for levi func", b.get_min_x_levi_function(res));
        print_mas("Mix x for three hump camel func", b.get_min_x_three_hump_camel_function(res));
        print_mas("Mix x for easom func", b.get_min_x_easom_function(res));

    }
}
