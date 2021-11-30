package application.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

import application.model.Model;

public class Controller {
    @FXML
    private Label result;

    @FXML
    private TextField fromM;

    @FXML
    private TextField toM;

    @FXML
    private TextField fromD;

    @FXML
    private TextField fromY;

    @FXML
    private TextField toD;

    @FXML
    private TextField toY;

    @FXML
    private Button dateCalcButton;

    @FXML
    private Label outY;

    @FXML
    private Label outM;

    @FXML
    private Label outD;

    @FXML
    private TextField celsius;

    @FXML
    private TextField fahrenheit;

    @FXML
    private Button tempConvertButton;

	private long number1 = 0;
	private String operator = "";
	private boolean start = true;
	private Model model = new Model();
	
	@FXML
	public void processNumber(ActionEvent event) {
		if (start) {
			result.setText("");
			start = false;
		}
		String value = ((Button)event.getSource()).getText();
		result.setText(result.getText()+ value); 
	}
	
	@FXML
	public void processOperator(ActionEvent event) {
		String value = ((Button)event.getSource()).getText();
		
		if (!value.equals("=")){
			if(!operator.isEmpty())
				return;
			operator = value;
			number1 = Long.parseLong(result.getText());
			result.setText("");
		} else {
			if(operator.isEmpty())
				return;
			long number2 = Long.parseLong(result.getText());
			
			float output = model.basicCalculate(number1, number2, operator);
			
			result.setText(String.valueOf(output));
			
			operator = "";
			start = true;
			
			
		}
	}

    @FXML
    public void pressDateCalcButton(ActionEvent event) {
        int[] from = new int[3];
        int[] to = new int[3];

        from[0] = (fromM.getText().matches("\\d+") ) ? Integer.parseInt(fromM.getText()) : 0;
        from[1] = (fromD.getText().matches("\\d+") ) ? Integer.parseInt(fromD.getText()) : 0;
        from[2] = (fromY.getText().matches("\\d+") ) ? Integer.parseInt(fromY.getText()) : 0;

        to[0] = (toM.getText().matches("\\d+") ) ? Integer.parseInt(toM.getText()) : 0;
        to[1] = (toD.getText().matches("\\d+") ) ? Integer.parseInt(toD.getText()) : 0;
        to[2] = (toY.getText().matches("\\d+") ) ? Integer.parseInt(toY.getText()) : 0;
        
        int[] out = model.dateCalculate(from, to);

        outM.setText(Integer.toString(out[0]));
        outD.setText(Integer.toString(out[1]));
        outY.setText(Integer.toString(out[2]));
    }

    @FXML
    public void pressTempConvertButton(ActionEvent event) {
        if(celsius.getText().matches("\\d+")){
            fahrenheit.setText(Double.toString(model.tempCalculate(Double.parseDouble(celsius.getText()), Model.tempConversion.CF)));
        }else if(fahrenheit.getText().matches("\\d+")){
            celsius.setText(Double.toString(model.tempCalculate(Double.parseDouble(fahrenheit.getText()), Model.tempConversion.FC)));
            
        }
    }
}
