// force.c

#include <ansi.h>

inherit SKILL;

void setup() {
	set("name","�ڹ��ķ�");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("eff_learn_level", 150);
	set("no_refund","attr");
}

void skill_improved(object me)
{
	string att = "con";
	string c_att = "����";
	int s = me->query_skill("force", 1);
	
	if (s > 50 && s < 201 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "�������ڹ������гɣ�������ʸ����ˡ�\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 200)
			tell_object(me,HIR"���"+c_att+"�Ѿ�������ͨ��"+ name()+ "����ˡ�\n"NOR);
		
	}
	
}
