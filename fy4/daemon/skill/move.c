// move.c

#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","�����Ṧ");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("eff_learn_level", 150);
	set("no_refund","attr");
}

void skill_improved(object me)
{
	string att = "agi";
	string c_att = "�ٶ�";
	int s = me->query_skill("move", 1);
	
	if (s > 50 && s < 221 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "����������Ṧ��������ݶ�����ˡ���\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 220)
			tell_object(me,HIR"���"+c_att+"�Ѿ�������ͨ��"+ name()+ "����ˡ�\n"NOR);
		
	}
	
}
