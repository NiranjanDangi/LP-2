public class MultiplicationMatrix {
    public String inputMatrix1 { get; set; }
    public String inputMatrix2 { get; set; }
    public String result { get; set; }

    public void showResult() {
        List<List<Integer>> mat1 = parseMatrix(inputMatrix1);
        List<List<Integer>> mat2 = parseMatrix(inputMatrix2);

        Integer rows1 = mat1.size();
        Integer cols1 = mat1[0].size();
        Integer rows2 = mat2.size();
        Integer cols2 = mat2[0].size();

        if (cols1 != rows2) {
            result = 'Number of columns in Matrix 1 must equal number of rows in Matrix 2.';
            return;
        }

        List<List<Integer>> product = new List<List<Integer>>();
        for (Integer i = 0; i < rows1; i++) {
            List<Integer> row = new List<Integer>();
            for (Integer j = 0; j < cols2; j++) {
                Integer sum = 0;
                for (Integer k = 0; k < cols1; k++) {
                    sum += mat1[i][k] * mat2[k][j];
                }
                row.add(sum);
            }
            product.add(row);
        }

        List<String> formattedRows = new List<String>();
        for (List<Integer> row : product) {
            formattedRows.add(String.join(row, ', '));
        }
        result = 'Product Matrix:\n' + String.join(formattedRows, '\n');
    }

    public List<List<Integer>> parseMatrix(String input) {
        List<List<Integer>> matrix = new List<List<Integer>>();
        input = input.replaceAll('\\s+', '');
        List<String> rows = input.split(';');
        for (String rowStr : rows) {
            List<String> elements = rowStr.split(',');
            List<Integer> row = new List<Integer>();
            for (String el : elements) {
                row.add(Integer.valueOf(el));
            }
            matrix.add(row);
        }
        return matrix;
    }
}