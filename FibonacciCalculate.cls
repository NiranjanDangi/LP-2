public class FibonacciCalculate {
    public Integer input{get; set;}
    public String result{get;set;}
    
    public void show(){
        List<Integer> ans = new List<Integer>();
        Integer a = 0, b = 1, c;
        ans.add(a);
        ans.add(b);
        for(Integer i = 0; i < input; i++){
            c = a + b;
            ans.add(c);
            a = b;
            b = c;
        }
        
        result = 'The Fibbonacci Sequence is ' + String.join(ans,', ');
    }
}