#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","����");
	set("type","knowledge");
	set("effective_level",150);
	set("skill_class","shenshui");
	set("difficulty",150);
}


void skill_improved(object me) {
	string att = "per";
	string c_att = "����";
	int s = me->query_skill("charm", 1);
	
	if (s > 50 && s < 201 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "�����������������Խ��ԽƯ���ˡ�\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 200)
			tell_object(me,HIR"���"+c_att+"�Ѿ�������ͨ��"+ name()+ "����ˡ�\n"NOR);
		
	}
}
