// iron-cloth.c

inherit SKILL;
#include <ansi.h>
void setup() {
	set("name","������");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("absorb_msg", ({
		"$n����׼�������Ų�æ��������������\n",
        	"$n��Ŀ��������ȫ������Ӳ���ﵽ�۷�״̬��\n",
        	"$n���١���һ�������㲻��������������ӭ��$N��\n",
	}) );
}	
/*
void skill_improved(object me)
{
    int s;

    s = me->query_skill("iron-cloth", 1);
    if( s%10==9 && (int)me->query("fle") < s/5) {
        tell_object(me, HIW "����������������������������ˡ�\n" NOR);
	me->set("fle",(s+1)/5);
    }
}

*/