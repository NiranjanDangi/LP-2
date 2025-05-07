public class AdditionMatrix {
    public String inputMatrix1 { get; set; }
    public String inputMatrix2 { get; set; }
    public String result { get; set; }

    public void showResult() {
        List<List<Integer>> mat1 = parseMatrix(inputMatrix1);
        List<List<Integer>> mat2 = parseMatrix(inputMatrix2);

        if (mat1.size() != mat2.size() || mat1[0].size() != mat2[0].size()) {
            result = 'Matrices must be of the same dimensions.';
            return;
        }

        List<List<Integer>> sumMatrix = new List<List<Integer>>();
        for (Integer i = 0; i < mat1.size(); i++) {
            List<Integer> row = new List<Integer>();
            for (Integer j = 0; j < mat1[i].size(); j++) {
                row.add(mat1[i][j] + mat2[i][j]);
            }
            sumMatrix.add(row);
        }

        // Convert matrix to string
        List<String> rows = new List<String>();
        for (List<Integer> row : sumMatrix) {
            rows.add(String.join(row, ', '));
        }
        result = 'Resultant Matrix:\n' + String.join(rows, '\n');
    }

    public List<List<Integer>> parseMatrix(String input) {
        List<List<Integer>> matrix = new List<List<Integer>>();
        input = input.replaceAll('\\s+', ''); // remove spaces
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