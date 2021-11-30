package application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;                                                                                                                                                                                                                                                                                                                                                                                                   
 
public class Main extends Application{
    @Override
    public void start(Stage stage) throws Exception{
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/application/view/Main.fxml"));
            Parent root = loader.load();
            
            Scene scene = new Scene(root);
            stage.setTitle("Calculator Extra Credit");
            stage.setResizable(false);
            stage.setScene(scene);
            stage.show();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
     
    public static void main(String[] args) {
        launch(args);
    }
}
