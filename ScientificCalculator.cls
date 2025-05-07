public class ScientificCalculator {
    public Double num1 {get; set;}
    public Double num2 {get; set;}
    public Double res {get; set;}
    
    public void add(){
        res = num1 + num2;
    }
    public void sub(){
        res = num1 - num2;
    }
    public void mul(){
        res = num1 * num2;
    }
    public void div(){
        res = num1 / num2;
    }
    public void power(){
        res = Math.pow(num1,num2);
    }
    public void mini(){
        res = Math.min(num1,num2);
    }
    public void maxi(){
        res = Math.max(num1,num2);
    }
}