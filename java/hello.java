class hello {
  public static void main(String[] args) {
    double kgval = 94d, poundval;
    poundval = kgval * 2.204;
    System.out.println("val in kg:" + kgval);
    System.out.println("val in pound:" + poundval);
    char uni = '\u0069';
    System.out.println("val in unicode val:" + uni);
    String test = "my weight is " + kgval + " KGs";
    System.out.println("string val: " + test);

    boolean is_gay = true;

    if (is_gay)
      System.out.println("he is gay? " + is_gay);

    System.out.println("the sum of 1 and 2 is :" + myadd2(1, 2));
  }

  public static int myadd2(int a, int b) {
    int x = a + b;
    return x;
    // System.out.println("Hello my name is niger");
  }
}
