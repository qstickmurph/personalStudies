import java.sql.*;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class P3Program
{
    private Connection connect = null;
    private Statement statement = null;
    private PreparedStatement preparedStatement = null;
    private ResultSet resultSet = null;
    public static final int ER_DUP_ENTRY = 1062;
    public static final int ER_DUP_ENTRY_WITH_KEY_NAME = 1586;
    public static final String[] strPropertyIdM =
            {   "MTNDDD"
                    ,"NYCCC"
                    ,"HOMEJJJ"
                    ,"END"
            };

    public P3Program (String server, String database, String user, String password) throws Exception
    {
        String port = "3306";

        String url = "jdbc:mysql://" + server + ":" + port + "/" + database;
        //String url = "jdbc:mysql://" + server + ":" + port;

        try
        {
            // This will load the MySQL driver, each DBMS has its own driver
            connect  = DriverManager.getConnection(url, user, password);
            connect.setTransactionIsolation(Connection.TRANSACTION_READ_COMMITTED);

        }
        catch (Exception e)
        {
            throw e;
        }

    }

    public void runProgram() throws Exception
    {

        // Code the #3 functionalities that start in page 5 of the problem statement
        statement = connect.createStatement();

        // functionality 3.a
        resultSet = statement.executeQuery("select c.* from Customer c");
        printCustomers("Beginning Customers", resultSet);

        // functionality 3.b
        resultSet = statement.executeQuery("select m.* from Property m");
        MySqlUtility.printUtility("Beginning Properties", resultSet);

        // functionality 3.c
        try{
            statement.executeUpdate("insert into Customer"
                    + "(`custNr`, `name`, `baseLoc`, `birthDt`, `gender`)"
                    + "values(1999, \"Quinn Murphey\", \"TX\", \"2000-12-05\", \"M\")");
        }
        catch (SQLException e)
        {
            switch (e.getErrorCode())
            {
                case ER_DUP_ENTRY:
                case ER_DUP_ENTRY_WITH_KEY_NAME:
                    System.out.printf("Duplicate key error: %s\n", e.getMessage());
                    break;
                default:
                    throw e;
            }
        }
        catch (Exception e)
        {
            throw e;
        }

        // functionality 3.d
        resultSet = statement.executeQuery("select c.* from Customer c");
        printCustomers("Customers after I was added", resultSet);

        // functionality 3.e
        resultSet = statement.executeQuery("select TABLE_SCHEMA, TABLE_NAME, INDEX_NAME, "
                + "SEQ_IN_INDEX, COLUMN_NAME, CARDINALITY "
                + "from INFORMATION_SCHEMA.STATISTICS "
                + "where TABLE_SCHEMA = \"cs3743_pfl955\" "
                + "and TABLE_NAME = \"Rental\" "
                + "order by INDEX_NAME, SEQ_IN_INDEX");
        MySqlUtility.printUtility("My Rental Indexes", resultSet);

        // functionality 3.f
        preparedStatement = connect.prepareStatement("insert into Rental "
                +"values (?, ?, ?, ?)");

        // functionality 3.g
        double cost = 200.0;
        for(String s : strPropertyIdM){
            if( s.equals("END") )
                break;

            preparedStatement.setInt(1, 1999);

            preparedStatement.setString(2, s);

            java.sql.Date date = java.sql.Date.valueOf("2019-12-14");
            preparedStatement.setDate(3, date);

            preparedStatement.setDouble(4, cost);
            cost += 10.0;

            try{
                preparedStatement.executeUpdate();
            }
            catch (SQLException e)
            {
                switch (e.getErrorCode())
                {
                    case ER_DUP_ENTRY:
                    case ER_DUP_ENTRY_WITH_KEY_NAME:
                        System.out.printf("Duplicate key error: %s\n", e.getMessage());
                        break;
                    default:
                        throw e;
                }
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        // functionality 3.h
        preparedStatement = connect.prepareStatement("select * from Rental r "
                + "where r.custNr = ?");
        preparedStatement.setInt(1,1999);
        resultSet = preparedStatement.executeQuery();
        MySqlUtility.printUtility("My rentals", resultSet);
        
        // functionality 3.i
        resultSet = statement.executeQuery("select r.propId, c.custNr, c.name, r.totalCost "
                + "from Rental r, Customer c "
                + "where r.custNr = c.custNr "
                + "and not c.custNr = 1999 "
                + "and exists( "
                    + "select * from Rental r1 "
                        + "where r1.propId = r.propId "
                        + "and r1.custNr = 1999)");
        MySqlUtility.printUtility("Other customers renting my properties", resultSet);

        // functionality 3.j
        try{
            statement.executeUpdate("update Rental r "
                    + "set r.totalCost = r.totalCost*0.90 "
                    + "where r.custNr = 1999");
        }
        catch (SQLException e)
        {
            switch (e.getErrorCode())
            {
                case ER_DUP_ENTRY:
                case ER_DUP_ENTRY_WITH_KEY_NAME:
                    System.out.printf("Duplicate key error: %s\n", e.getMessage());
                    break;
                default:
                    throw e;
            }
        }
        catch (Exception e)
        {
            throw e;
        }

        // functionality 3.k
        preparedStatement = connect.prepareStatement("select * from Rental r "
                + "where r.custNr = ?");
        preparedStatement.setInt(1,1999);
        resultSet = preparedStatement.executeQuery();
        MySqlUtility.printUtility("My cheaper rentals", resultSet);

        // functionality 3.l
        resultSet = statement.executeQuery("select r.propId, count(*) "
                + "from Rental r "
                + "group by r.propId "
                + "having count(*) > 1");
        MySqlUtility.printUtility("Properties having more than 2 rentals", resultSet);

        // functionality 3.m
        try{
            statement.executeUpdate("delete from Rental "
                    + "where custNr = 1999");
        }
        catch (SQLException e)
        {
            switch (e.getErrorCode())
            {
                case ER_DUP_ENTRY:
                case ER_DUP_ENTRY_WITH_KEY_NAME:
                    System.out.printf("Duplicate key error: %s\n", e.getMessage());
                    break;
                default:
                    throw e;
            }
        }
        catch (Exception e)
        {
            throw e;
        }

        // functionality 3.n
        resultSet = statement.executeQuery("select r.propId, c.custNr, c.name, r.totalCost "
                + "from Rental r, Customer c "
                + "where r.custNr = c.custNr "
                + "and not c.custNr = 1999 "
                + "and exists( "
                    + "select * from Rental r1 "
                        + "where r1.propId = r.propId "
                        + "and r1.custNr = 1999)");
        MySqlUtility.printUtility("Other customers renting my properties", resultSet);

        // Remember to close the statement and connect(ion)
        preparedStatement.close();
        statement.close();
        connect.close();
    }

    private void printCustomers(String title, ResultSet resultSet) throws SQLException
    {
        // Your output for this must match the format of my sample output exactly.
        // custNr, name, baseLoc, birthDt, gender
        
        // Print title
        System.out.println(title);

        // Print column names
        System.out.printf("    %-6s %-30s %-5s %-10s %-6s\n", 
                "CustNr", "Name", "State", "Birth Dt", "Gender");

        // Print each row 
        while(resultSet.next()){

            String custNr = Integer.toString(resultSet.getInt("custNr"));

            String name = resultSet.getString("name");
            if(name == null)
                name = "---";

            String baseLoc = resultSet.getString("baseLoc");
            if(baseLoc == null)
                baseLoc = "---";
            
            String birthDtStr = null;
            DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
            Date birthDt = resultSet.getDate("birthDt");
            if(birthDt== null)
                birthDtStr = "---";
            else
                birthDtStr = dateFormat.format(birthDt);

            String gender = resultSet.getString("gender");
            if(gender == null)
                gender = "---";

            
            System.out.printf("    %-6s %-30s %-5s %-10s %-6s\n", 
                    custNr, name, baseLoc, birthDtStr, gender);
        }

        // remember to close your resultSet
        resultSet.close();
    }
}
