public class P3Main
{
    public static void main(String[] args) throws Exception
    {

        // Change all these credentials as received in the email
        String server = "cs3743.fulgentcorp.com";
        String database = "cs3743_pfl955";
        String user = "pfl955";
        String password = "bURKmt9C8hfKecnClx9Z";


        P3Program pgm = new P3Program( server, database, user, password);
        pgm.runProgram();
    }
}
