public class ConvertorTemperature {
    public Double input {get; set;}
    public Double res {get;set;}
    
    public void convertToFarenhite(){
        res = (input * 9 / 5) + 32;
    }
    
    public void convertToCelsius(){
        res = (input - 32) * 5/9;
    }
}