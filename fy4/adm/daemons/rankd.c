// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
	string bangname,bangrank,tmpstr;
	string setname;
	int exp;
	exp = (int) ob->query("combat_exp");
	if( ob->is_ghost() ) return HIB "��  ��  ��  ��" NOR;
	if( (int) ob->query("title_race") == -1 )
	{
		if( strlen((string) ob->query("env/title_race")) ==2){
		setname = ob->query("env/title_race");
		return HIR "�����Ƶ�һ"+ setname +"��" NOR;}
		else return HIR "�� ���Ƶ�һ ��" NOR;
	}
        if( (int) ob->query("title_race") == -2 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "�����Ƶڶ�"+ setname +"��" NOR;}
                else return HIR "�� ���Ƶڶ� ��" NOR;
	}
        if( (int) ob->query("title_race") == -3)
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "�����Ƶ���"+ setname +"��" NOR;}
                else return HIR "�� ���Ƶ��� ��" NOR;
	}
	bangname = ob->query("marks/����");
	if (bangname!=0) {
		tmpstr = "marks/" + bangname;
		bangrank = ob->query(tmpstr);
		return HIB"�� "+bangname+bangrank+"��" NOR;
	}
                        if (exp >= 1000000)
                                return HIW "�� �����콾 ��" NOR;
                        else if (exp >= 800000)
                                return HIC "�� ����̩�� ��" NOR;
                        else if ( exp >= 600000)
                                return HIC "�� ������ʦ ��" NOR;
                        else if (exp>= 400000)
                                return HIM "�� �������� ��" NOR;
                        else if (exp>= 100000)
                                return HIM "�� ���ƴ��� ��" NOR;
                        else if (exp>= 50000)
                                return HIB "�� �������� ��" NOR;
			else if (exp>= 25000)
                                return HIB "�� ����С�� ��" NOR;
                        else if (exp>= 10000)
                                return HIG "�� ���Ƹ��� ��" NOR;
                        else if (exp >= 5000)
                                return HIG "�� �������� ��" NOR;

	switch(ob->query("gender")) {
	case "Ů��":
		switch(wizhood(ob)) {
			case "(admin)":			return HIR "��  Ů  ��  ��" NOR;
			case "(arch)":			return HIY "��  ��ħŮ  ��" NOR;
			case "(wizard)":		return HIG "��  ħ  Ů  ��" NOR;
			case "(apprentice)":	return HIC "��  СħŮ  ��" NOR;
			case "(immortal)":		return HIC "��  ��  Ů  ��" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "��  ɱ��ħ  ��";
				if( (int)ob->query("thief") > 50 ) return "��  ��  ��  ��";
				switch(ob->query("class")) {
					case "bonze":		return "��  ��  ��  ��";
					case "taoist":		return "��  Ů  ��  ��";
					case "ghost":		return "��  ��  ��  ��";
					case "bandit":		return "��  Ů����  ��";
					case "dancer":		return "��  ��  ��  ��";
                                        case "legend":          return "��  ��  Ů  ��";
					case "scholar":		return "��  ��  Ů  ��";
                    case "official":    return "��  Ů  ��  ��";
					case "fighter":		return "��  Ů����  ��";
					case "traveller" :	return "��  ��  ��  ��";
					case "lishi" :      	return "��  Ů����  ��";
					case "swordsman":	return "��  Ů��ʿ  ��";
					case "assassin":	return "��  ɱ  ʿ  ��";
					case "ninemoon":        return "��  а  Ů  ��";
					case "shaman":		return "��  ��  ҽ  ��";
					case "lama":		return "��  ��  ��  ��";
					case "yinshi":          return "��  ��  ʿ  ��";
					case "beggar":		return "��  �л���  ��";
					default:			return "��  ƽ  ��  ��";
			}
		}
	default:
		switch(wizhood(ob)) {
			case "(admin)":			return HIR "��  ��  ��  ��" NOR;
			case "(arch)":			return HIY "��  ����ʦ  ��" NOR;
			case "(wizard)":		return HIG "��  ��  ʦ  ��" NOR;
			case "(apprentice)":		return HIC "�� ��ʦѧͽ ��" NOR;
			case "(immortal)":		return HIC "��  ��  ��  ��" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "��  ɱ��ħ  ��";
				if( (int)ob->query("thief") > 10 ) return "��  ��  ��  ��";
				switch(ob->query("class")) {
					case "bonze":		return "��  ɮ  ��  ��";
					case "taoist":		return "��  ��  ʿ  ��";
					case "ghost":		return "��  ��  ��  ��";
					case "bandit":		return "��  ��  ��  ��";
					case "scholar":		return "��  ��  ��  ��";
                                        case "legend":          return "��  ��  ��  ��";
                    case "official":    return "��  ��  ��  ��";
					case "fighter":		return "��  ��  ��  ��";
					case "lishi":		return "��  ��  ��  ��";
					case "swordsman":	return "��  ��  ʿ  ��";
					case "traveller" :      return "��  ��  ��  ��";
					case "assassin":	return "��  ɱ  ʿ  ��";
					case "shaman":		return "��  ��  ҽ  ��";
					case "yinshi":          return "��  ��  ʿ  ��";
                                        case "lama":        	return "��  ��  ɮ  ��";
					case "beggar":		return "��  �л���  ��";
					default:			return "��  ƽ  ��  ��";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ̫";
				else return "ʦ̫";
				break;
			case "taoist":
				if( age < 18 ) return "С�ɹ�";
				else return "�ɹ�";
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ��";
				else return "��ʦ";
				break;
			case "taoist":
				if( age < 18 ) return "����";
				else return "����";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "С�ϵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ǰ��";
				break;
			default:
				if( age < 20 ) return "С�ֵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ү��";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				return "����";
				break;
			case "taoist":
				return "��Ů";
				break;
			default:
				if( age < 30 ) return "С����";
				else return "����̫��";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "taoist":
				return "��ţ����";
				break;
			default:
				if( age < 20 ) return "С���˵�";
				if( age < 50 ) return "����";
				else return "��ƥ��";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
			case "lama":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			case "official":

			default:
				if( age < 50 ) return "СŮ��";
				else return "���";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
			case "shaolin":
			case "lama":
				if( age < 50 ) return "ƶɮ";
				else return "����";
				break;
			case "taoist":
				return "ƶ��";
				break;
			case "official":
				return "�¹�";
			default:
				if( age < 50 ) return "����";
				else return "��ͷ��";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			case "taoist":
				return "���ɹ�";
			default:
				if( age < 50 ) return "��С��";
				else return "������";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
			case "shaolin":
				if( age < 50 ) return "�������";
				else return "�Ϻ�����";
				break;
			case "lama":
				if(age<40) return "��������";
					return "����ү��";
				break;
			case "official":
				if(age<50) return "����ү��";
					return "̫ү��";
				break;
			case "taoist":
				return "��ɽ��";
				break;
			default:
				if( age < 50 ) return "��ү��";
				else return "����";
				break;
			}
	}
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = ob->query("age"))
                        a1 = this_player()->query("age");
                else {
                        a1 = this_player()->query("mud_age");
                        a2 = ob->query("mud_age");
                }
        } else {
                a1 = this_player()->query("age");
                a2 = 0;
        }



        switch (ob->query("gender")) {
                case "Ů��" :
                case "����" :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
                                return "����";
                        if (a2 - a1 >= 20) return "�ù�";
                        if (a1 - a2 >= 20) return "ֶŮ";
                        if (a1 > a2) return "����";
                        return "���";
                        break;
                default :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
                                return "�๫";
                        if (a2 - a1 >= 20) return "����";
                        if (a1 - a2 >= 20) return "ֶ��";
                        if (a1 > a2) return "�͵�";
                        return "���";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = ob->query("age"))
                        a1 = this_player()->query("age");
                else {
                        a1 = this_player()->query("mud_age");
                        a2 = ob->query("mud_age");
                }
        } else {
                a1 = this_player()->query("age");
                a2 = 0;
        }


        switch (this_player()->query("gender")) {
                case "Ů��" :
                case "����" :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry"))
                                return "�����";
                        if (a1 - a2 >= 20) return "�ù���";
                        if (a2 - a1 >= 20) return "ֶŮ��";
                        if (a1 > a2) return "�����";
                        return "С����";
                        break;
                default :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry"))
                                return "�޷���";
                        if (a1 - a2 >= 20) return "������";
                        if (a2 - a1 >= 20) return "Сֶ��";
                        if (a1 > a2) return "������";
                        return "С����";
        }
}
