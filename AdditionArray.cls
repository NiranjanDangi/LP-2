public class AdditionArray {
    public String inputArray1{get; set;}
    public String inputArray2{get; set;}
    public String result{get; set;}
    
    public void showResult(){
        List<Integer> arr1 = splitandreturn(inputArray1);
        List<Integer> arr2 = splitandreturn(inputArray2);
        
        if(arr1.size() != arr2.size()) result = 'Array must be of same length';
        
        List<Integer> res = new List<Integer>();
        for(Integer i = 0; i < arr1.size(); i++){
            res.add(arr1[i] + arr2[i]);
        }
        
        result = 'Resultant array is ' + String.join(res,', ');
    }
    
    public List<Integer> splitandreturn(String name){
        List<String> parts = name.replaceAll('\\s+','').split(',');
        List<Integer> ans = new List<Integer>();
        for(String part : parts){
            ans.add(Integer.valueOf(part));
        }
        return ans;
    }
}