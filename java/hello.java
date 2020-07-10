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

  }
}
