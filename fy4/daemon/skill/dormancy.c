// dormancy.c

#include <ansi.h>

inherit SKILL;

void setup() {
	set("name","Ϣ������");
	set("skill_class","legend");
	set("type","knowledge");
	set("effective_level",150);
	set("difficulty",120);
}


int valid_learn(object me)
{
	if (me->query("class")!= "legend")
		return notify_fail("Ψ����ѩ���ӷ�������Ϣ������֮����\n");
	return ::valid_learn(me);
}

/*
void skill_improved(object me)
{
	int s;
	s = me->query_skill("dormancy", 1);
          
        if (s > 100 && s < 301 && !(s%10)) {
		if ( (s-100)*5 < me->query("marks/dormancy")) {
			tell_object(me, HIW "���������Ϣ�������������Ѫ����ˡ�\n" NOR);
			me ->set("Add_kee/dormancy", (s-100)*5);
			me ->add("max_kee",50);
			me ->add("marks/dormancy",50);
		}
		if (s == 300)
			tell_object(me,HIR"�����Ѫ�Ѿ�����ͨ��Ϣ������������ˡ�\n"NOR);
		
	}
        
}*/

int help(object me)
{
	write(@HELP   
Ϣ����������ѩ�����书�Ļ�������������ѩ��Ҷ����������Ѫ��������
HELP
    );
    return 1;
}
