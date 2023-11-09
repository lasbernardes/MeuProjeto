package verboPkg;

import java.util.Scanner;

public class VerboClass {
	private String radical;
	private String sufixo;
	
	/*construtor gerado por eclipse*/
	public VerboClass(String _radical, String _sufixo) {
		super();
		this.radical = _radical;
		this.sufixo = _sufixo;
	}
	public String getRadical() {
		return radical;
	}
	public void setRadical(String radical) {
		this.radical = radical;
	}

	public String getSufixo() {
		return sufixo;
	}
	public void setSufixo(String sufixo) {
		this.sufixo = sufixo;
	}



	public void conjugar() {
		System.out.println("Eu   "+radical+"o");
		System.out.println("Tu   "+radical+"as");
		System.out.println("Ele  "+radical+"a");
		System.out.println("Nós  "+radical+"amos");
		System.out.println("Vós  "+radical+"ais");
		System.out.println("Eles "+radical+"am");
		
	}
	public void separe() {
		String radical1;
		
		sufixo = radical.substring(radical.length()-2);
		radical = radical.substring(0,radical.length()-2);
		System.out.println("radical: "+ radical);
	}
	public static void main(String[] args) {
		
		Scanner rad = new Scanner(System.in);
		String strrad =rad.nextLine();
		
		Scanner suf = new Scanner(System.in);
		String strsuf =suf.nextLine();

		separe();
		VerboClass verbo = new VerboClass(strrad, strsuf);
		
		verbo.conjugar();
	}
}
