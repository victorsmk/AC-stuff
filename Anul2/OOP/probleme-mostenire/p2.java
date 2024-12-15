import java.util.*;

class Main
{
	public static void main (String[] args)
	{
		ClassicWhiskey cw = new ClassicWhiskey("RL", 45);
		JackAndHoney jnh = new JackAndHoney("JD", 40, 50);
		BlendedWhiskey bw = new BlendedWhiskey("Epic blend");
		bw.add(cw);
		bw.add(jnh);
		System.out.println(bw);
		System.out.println(bw.getConcentratieAlcool());
		System.out.println(bw.getNrCalorii(150));
	}
}

abstract class Whiskey
{
	abstract public double getNrCalorii (int mL);
	abstract public double getConcentratieAlcool();
}

class ClassicWhiskey extends Whiskey
{
	private String nume;
	private double concentratie;
	
	public ClassicWhiskey (String nume, double concentratie)
	{
		this.nume = nume;
		this.concentratie = concentratie;
	}
	
	public double getConcentratieAlcool()
	{
		return concentratie;
	}
	
	public double getNrCalorii(int mL)
	{
		return concentratie*mL*5;
	}
	
	public String toString ()
	{
		return nume + ", Concentratie alcool: " + concentratie + "%, Calorii pe 100 ml: " + this.getNrCalorii(100) + "kcal"; 
	}
}

class JackAndHoney extends Whiskey
{
	private String nume;
	private double concentratie;
	private int indulcitor;
	
	public JackAndHoney (String nume, double concentratie, int indulcitor)
	{
		this.nume = nume;
		this.concentratie = concentratie;
		this.indulcitor = indulcitor;
	}
	
	public double getConcentratieAlcool()
	{
		return concentratie;
	}
	
	public double getNrCalorii(int mL)
	{
		return concentratie*mL*5 + indulcitor*mL*15;
	}
	
	public String toString ()
	{
		return nume + ", Concentratie alcool: " + concentratie + "%, Calorii pe 100 ml: " + this.getNrCalorii(100) + "kcal, Cantitate indulcitor: " + indulcitor + "g"; 
	}
}

class BlendedWhiskey extends Whiskey
{
	private String nume;
	private ArrayList<Whiskey> whiskeys = new ArrayList(32);
	
	public BlendedWhiskey (String nume)
	{
		this.nume = nume;
	}

	public void add (Whiskey whiskey)
	{
		whiskeys.add(whiskey);
	}
	
	public double getConcentratieAlcool()
	{
		int nr = 0, sum = 0;
		for (Whiskey w : whiskeys)
		{
			nr++;
			sum += w.getConcentratieAlcool();
		}
		if (nr != 0)
			return sum / nr;
		else
			return 0;
	}
	
	public double getNrCalorii(int mL)
	{
		int sum = 0;
		for (Whiskey w: whiskeys)
			sum += w.getNrCalorii(mL);
		return sum;
	}
	
	public String toString ()
	{
		String str = nume + ", Concentratie alcool: " + this.getConcentratieAlcool() + "%, Calorii pe 100ml: " + this.getNrCalorii(100) + "kcal, Compozitie: ";  
		for (Whiskey w : whiskeys)
			str += w + " ";
		return str;
	}
}