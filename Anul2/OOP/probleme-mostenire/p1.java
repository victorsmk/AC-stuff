import java.util.*;

class Main
{
	public static void main (String[] args)
	{
		Subscriber sub1 = new Subscriber("sub1", 3);
		Subscriber sub2 = new Subscriber("sub2", 1);
		Creator creator1 = new Creator ("mrstreamer");
		creator1.adaugaSubscriber(sub1);
		creator1.adaugaSubscriber(sub2);
		Subscriber sub3 = new Subscriber("sub3", 2);
		Subscriber sub4 = new Subscriber("sub4", 1);
		Subscriber sub5 = new Subscriber("sub5", 3);
		Creator creator2 = new Creator ("mrsstreamer");
		creator2.adaugaSubscriber(sub3);
		creator2.adaugaSubscriber(sub4);
		creator2.adaugaSubscriber(sub5);
		Subscriber sub6 = new Subscriber("independent", 0);
		Platforma platforma = new Platforma();
		platforma.adaugaUtilizator(creator1);
		platforma.adaugaUtilizator(creator2);
		platforma.adaugaUtilizator(sub6);
		System.out.println(platforma.determinaVIP(30));
	}
}

abstract class Utilizator
{
	abstract public double calculeazaVenit(int minute);
}

class Subscriber extends Utilizator
{
	private String nume;
	private int nivelSubscriptie;
	
	public Subscriber (String nume, int nivelSubscriptie)
	{
		this.nume = nume;
		this.nivelSubscriptie = nivelSubscriptie;
	}
	
	public double calculeazaVenit (int minute)
	{
		return 1.5*minute*nivelSubscriptie;
	}
	
	public String toString ()
	{
		return nume + " - subscriber - " + nivelSubscriptie;
	}
}

class Creator extends Utilizator
{
	private String nume;
	private ArrayList <Subscriber> subs = new ArrayList(32);
	
	public Creator (String nume)
	{
		this.nume = nume;
	}
	
	public void adaugaSubscriber (Subscriber newSub)
	{
		subs.add(newSub);
	}
	
	public double calculeazaVenit (int minute)
	{
		int sum = 0;
		for (Subscriber sub : subs)
			sum += sub.calculeazaVenit(minute);
		return sum;
	}
	
	public String toString ()
	{
		String str = nume + " - creator - ";
		for (Subscriber sub : subs)
			str += sub + " ";
		return str;
	}
}

class Platforma
{
	private Utilizator[] users = new Utilizator[1000];
	private int index = 0;
	
	public boolean adaugaUtilizator (Utilizator user)
	{
		if (index >= 1000)
			return false;
		users[index++] = user;
		return true;
	}
	
	public Utilizator determinaVIP (int minute)
	{
		double max = 0;
		Utilizator vip = null;
		for (int i = 0; i < index; i++)
			if (users[i].calculeazaVenit(minute) > max)
			{
				max = users[i].calculeazaVenit(minute);
				vip = users[i];
			}
		return vip;
	}
}