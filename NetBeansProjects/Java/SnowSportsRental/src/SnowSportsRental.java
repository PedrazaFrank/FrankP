
public class SnowSportsRental {

    public static void main(String[] args) {
        Ski a = new Ski(true, 25, 156);
        Snowboard b = new Snowboard(true, 20, 385);
        SnowMobile c = new SnowMobile(false, 18, 519);
        
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(c.toString());
    }
}
