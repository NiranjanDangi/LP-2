public class Geometry {
    public Double radius{get;set;}
    public Double side{get;set;}
    public Double length{get; set;}
    public Double breadth{get; set;}
    public Double circle{get; set;}
    public Double square{get; set;}
    public Double rectangle{get; set;}
    
    public void show(){
        circle = Math.PI * Math.pow(radius,2);
        square = side * side;
        rectangle = length * breadth;
    }
}