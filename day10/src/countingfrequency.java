//counting frequency:
//input:- ABCDABEDABCEA
//
//output:-
//A - 4
//B - 3
//C - 2
//D - 2
//E - 2

//for (int i=65;i<=80;i++){
//    int frequency=0;
//    for(int j=0; j<str.lenght();j++){
//        if(str.charAt(j)==char(i))
//            frequency++;
//    }
//    if(frequency!=0)
//        cout<<(char)i<<" - "<<frequency;
//}

public class countingfrequency  {
    public static void main(String[] args) {
        String str = "ABCDABEDABCEA";
        str = str.toUpperCase();  // ensure all uppercase

        for (int i = 65; i <= 80; i++) {  // A (65) to Z (90)
            char ch = (char) i;
            int frequency = 0;

            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == ch) {
                    frequency++;
                }
            }

            if (frequency != 0) {
                System.out.println(ch + " - " + frequency);
            }
        }
    }
}

