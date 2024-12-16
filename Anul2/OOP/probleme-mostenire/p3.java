import java.util.*;

class Main
{
	public static void main (String[] args)
	{
		Autoturism a1 = new Autoturism("MH69BOS", 4, 0.3);
		Autoturism a2 = new Autoturism("DJ05UGI", 5, 0.25);
		Autoturism a3 = new Autoturism ("GJ88BMW", 4.5, 0.15);
		Camion cam = new Camion ("B314ZDA", 10);
		cam.adaugaAutoturism(a1);
		cam.adaugaAutoturism(a2);
		Bac bac = new Bac(20);
		bac.adaugaAutovehicul(cam);
		bac.adaugaAutovehicul(a3);
		System.out.println(bac);
	}
}

abstract class Autovehicul 
{
	protected String nrInmatriculare;
	protected double greutate;
	public Autovehicul (String nrInmatriculare, double greutate)
	{
		this.nrInmatriculare = nrInmatriculare;
		this.greutate = greutate;
	}
	abstract public double calculeazaGreutateTotala();
}

class Autoturism extends Autovehicul
{
	private double greutatePasageri;
	
	public Autoturism (String nrInmatriculare, double greutate, double greutatePasageri)
	{
		super(nrInmatriculare, greutate);
		this.greutatePasageri = greutatePasageri;
	}
	
	public double getGreutate ()
	{
		return greutate;
	}
	
	public double calculeazaGreutateTotala ()
	{
		return greutate + greutatePasageri;
	}
	
	public String toString ()
	{
		return "Numar inmatriculare: " + nrInmatriculare + ", Greutate autovehicul: " + greutate + ", Greutate pasageri: " + greutatePasageri;
	}
}

class Camion extends Autovehicul
{
	private ArrayList<Autoturism> autoturisme = new ArrayList(20);
	public Camion (String nrInmatriculare, double greutate)
	{
		super(nrInmatriculare, greutate);
	}
	
	public void adaugaAutoturism (Autoturism auto)
	{
		autoturisme.add(auto);
	}
	
	public double calculeazaGreutateTotala ()
	{
		double sum = greutate;
		for (Autoturism a : autoturisme)
			sum += a.getGreutate();
		return sum;
	}
	
	public String toString ()
	{
		String str =  "Numar inmatriculare: " + nrInmatriculare + ", Greutate autovehicul: " + greutate + ", (";
		for (Autoturism a : autoturisme)
			str += " " + a;
		return str + " )";
	}
}

class Bac
{
	private double greutateMax;
	private ArrayList<Autovehicul> autovehicule = new ArrayList(30);
	private double greutateCurenta = 0;
	
	public Bac (double greutateMax)
	{
		this.greutateMax = greutateMax;
	}
	
	public boolean adaugaAutovehicul (Autovehicul auto)
	{
		if (greutateCurenta + auto.calculeazaGreutateTotala() <= greutateMax)
		{
			greutateCurenta += auto.calculeazaGreutateTotala();
			autovehicule.add(auto);
			return true;
		}
		return false;
	}	
	
	public String toString ()
	{
		String str = "Greutate maxima: " + greutateMax + ", (";
		for (Autovehicul a : autovehicule)
			str += " " + a;
		return str + " )";
	}
}