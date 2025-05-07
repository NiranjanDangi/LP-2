public class ConvertorCurrency {
    public Double input {get; set;}
    public Double result {get; set;}
    
    public void inrtousd(){
        result = input / 83.0;
    }
    public void inrtoeur(){
        result = input / 91.0;
    }
    public void inrtogbp(){
        result = input / 101.0;
    }
    public void inrtojpy(){
        result = input / 11.2;
    }
    public void inrtoaud(){
        result = input / 45.0;
    }
    
    public void usdtoinr(){
        result = input * 83.0;
    }
    public void eurtoinr(){
        result = input * 91.0;
    }
    public void gbptoinr(){
        result = input * 101.0;
    }
    public void jpytoinr(){
        result = input * 11.2;
    }
    public void audtoinr(){
        result = input * 45.0;
    }

}