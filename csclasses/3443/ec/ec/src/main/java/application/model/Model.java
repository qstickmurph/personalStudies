package application.model;

import java.time.LocalDate;
import java.time.Period;

public class Model {
	
	public float basicCalculate(long number1, long number2, String operator) {
		
		// Basic operations we are expecting from our calculator 
		//+, -, *, /
		
		switch (operator) {
		case "+":
			return number1 + number2;
		case "-":
			return number1 - number2;
		case "*":
			return number1 * number2;
		case "/":
			if(number2 == 0)
				return 0;
			return ((float) number1) / ((float) number2);
			
		//case "%":
			
		default:
			return 0;
		}
	}

    public int[] dateCalculate(int[] f, int[] t){
        LocalDate from = LocalDate.of(f[2], f[0], f[1]);
        LocalDate to  = LocalDate.of(t[2], t[0], t[1]);
        Period p = Period.between(from, to);
        int[] ret = new int[3];
        ret[0] = p.getMonths();
        ret[1] = p.getDays();
        ret[2] = p.getYears();
        return ret;
    }
    
    public static enum tempConversion{
        FC,
        CF;
    }

    public double tempCalculate(double temp, tempConversion convertTo){
        switch(convertTo){
            case FC:
                return ((temp - 32.0) / 9.0 ) * 5.0;
            case CF:
                return ((temp * 9.0) / 5.0) + 32.0;
        }
        return 0;
    }
}
