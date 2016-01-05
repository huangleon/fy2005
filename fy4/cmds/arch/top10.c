#include <ansi.h>
#include <mudlib.h>
#include <combat.h>

inherit F_CLEAN_UP;

string topten_query(object me,string type);
int top_list_exp(object ob1,object ob2);
int top_list_rich(object ob1,object ob2);
int top_list_pker(object ob1,object ob2);
int top_list_age(object ob1,object ob2);
int get_score_exp(object ob);
int get_score_rich(object ob);
int get_score_pker(object ob);
int get_score_age(object ob);

int main(object me, string arg)
{
	string str;
	string type;

	if (!arg||arg=="")
	return notify_fail("ָ���ʽ : top10 ��������
Ŀǰ�����������У�\n
	������2005-�������¡�����ʮ�����    ��highhand��
	������2005-�������¡�����ʮ����    ��richman��
	������2005-�������¡�����ʮ��ɱ��    ��pker��
	������2005-�������¡�����ʮ�����˼�  ��oldguy��\n");
        if(arg=="highhand"||arg=="exp")
              type="exp";
        else if(arg=="richman"||arg=="rich")
              type="rich";
        else if(arg=="killer"||arg=="pker")
              type="pker";
        else if(arg=="oldguy"||arg=="age")
              type="age";
        else 
              type=arg;   
	str = topten_query(me,type);
	write(str+"\n");
	return 1;
}

string topten_query(object me,string type)
{
	object *topten_list,*players;
	string msg;
	int i,k;
	
	string *top = ({
		HIW"        ����������    ����2005-����ʮ��������а�    ����������\n"NOR,
		YEL"        ����������    ����2005-����ʮ�������а�    ����������\n"NOR,
		RED"        ����������    ����2005-����ʮ��ɱ�����а�    ����������\n"NOR,
		CYN"        ����������   ����2005-����ʮ�����˼����а�   ����������\n"NOR,
		});
	string *divide = ({
		HIW"    ---------------------------------------------------------------\n"NOR,
		YEL"    ---------------------------------------------------------------\n"NOR,
		RED"    ---------------------------------------------------------------\n"NOR,
		CYN"    ---------------------------------------------------------------\n"NOR,
		});
	players = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        switch(type)
	{
		case "exp":
			k=0;
			topten_list = sort_array(players, (: top_list_exp :));
			break;
		case "rich":
                        k=1;
                        topten_list = sort_array(players, (: top_list_rich :));
			break;
		case "pker":
			k=2;
			topten_list = sort_array(players, (: top_list_pker :));
			break;
		case "age":
			k=3;
			topten_list = sort_array(players, (: top_list_age :));
			break;
                default:
			return "�Բ�����ʱû���������а�\n";
	}

	msg = top[k] + divide[k];
	msg += "    |     ����      |            ���             |     ����      |\n";
        msg += divide[k];
        for (i = 0 ;i < 10 ; i++) {
		if(i >= sizeof(topten_list)) 
			msg += "    ***��ʱ��ȱ***�� \n";
		else {
			if(topten_list[i] == me) msg += YEL;
		msg += sprintf("         %-3s          %-32s%          -10s\n"NOR,chinese_number(i+1),topten_list[i]->query("name")+"("+
			capitalize(topten_list[i]->query("id"))+")", topten_list[i]->query("family")?  topten_list[i]->query("family/family_name"):"��ͨ����");
		}
	}
        msg += divide[k];
	return msg;
}

int top_list_exp(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score_exp(ob1);
	score2 = get_score_exp(ob2);

	return score2 - score1;
}

int top_list_rich(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score_rich(ob1);
	score2 = get_score_rich(ob2);

	return score2 - score1;
}

int top_list_pker(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score_pker(ob1);
	score2 = get_score_pker(ob2);

	return score2 - score1;
}

int top_list_age(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score_age(ob1);
	score2 = get_score_age(ob2);

	return score2 - score1;
}

int get_score_exp(object ob)
{
	int exp;
	int score;
	exp = (int) ob->query("combat_exp");
//	score = (int) ob->query("score");
//	score = exp /10 + score;
	score = exp;
	return score;
}

int get_score_rich(object ob)
{
	int money;
	money=(int)ob->query("deposit");
	return money;
}

int get_score_pker(object ob)
{
	int pks;
	pks=(int)ob->query("PKS");
	return pks;
}

int get_score_age(object ob)
{
	int age;
	age=(int)ob->query("mud_age");
	return age;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	top10 <��������>[0m
[0;1;37m����������������������������������������������������������������[0m   

Ŀǰ������������:
	Highhand  ʮ�����
	Richman   ʮ����
	Pker      ʮ��ɱ��
	Oldguy    ʮ�����˼�
	
[0;1;37m����������������������������������������������������������������[0m   	
HELP
    );
    return 1;
}