
Problem: You want to find all the possible ways of arranging 2 boys and 1 girl on 3 benches. 
Constraint: Girl should not be on the middle bench.
Solution: There are a total of 3! = 6 possibilities. We will recursively  try all the possibilities and get the possible solutions.


class Main{								0  1  2
	static void arrangments(String str[], int index){		G  B1 B2
		if(index==str.length){					i=0
			if(!str[1].equals("G")){				ind=0
				for(String s: str){				ind=1
					System.out.print(s+" ");		ind=2
				}						ind=3
				System.out.println();			i=1
			}							index=1
		}								index=2
		else{							i=0	
			for(int i=index ; i<str.length ; i++){			index=0
				swap(str, index, i);				index=1
				arrangments(str, index+1);	Output:	B1 B2 G
				swap(str, index, i);			B2 B1 G
			}						G  B1 B2
		}							G  B2 B1
	}

	static void swap(String str[], int index, int i){
			String temp = str[index];
			str[index] = str[i];
			str[i] = temp;
	}

	public static void main(String []args){
		String str[] = {"B1", "B2", "G"};
		arrangments(str, 0);
	}
}

