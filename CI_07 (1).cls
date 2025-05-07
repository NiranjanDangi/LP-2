public class CI_07{
    public Decimal principal {get; set;}
    public Decimal rate {get; set;}
    public Integer timePeriod {get; set;}
    public Decimal compoundInterest {get; set;}
    public Decimal simpleInterest {get; set;}
    
    public void calculateCI(){
        
            Double base = 1 + (rate / 100);
            Double exponent = Double.valueOf(timePeriod);
            Double amt = Double.valueOf(principal) * Math.pow(base,exponent);
            compoundInterest = Decimal.valueOf(amt) - principal;
    }
    public void calculateSI(){
            simpleInterest = (principal * rate * timePeriod)/100.0;
    }
}