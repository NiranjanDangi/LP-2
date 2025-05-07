public class checkPrime {
    public Integer input{get; set;}
    public String res{get; set;}
    
    public void check(){
        if(input <= 1) res = ' Not a Prime number ';
        
        Boolean flag = true;
        for(Integer i = 2; i <= Math.sqrt(input); i++){
            if(Math.mod(i,2) == 0){
                flag = false;
                break;
            }
        }
        
        if(flag){
			res = ' Prime Number ';            
        }
        else{
            res = ' Not a Prime number ';
        }
        
    }
}