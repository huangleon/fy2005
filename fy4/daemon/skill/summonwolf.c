#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","������");
	set("skill_class","wolfmount");
	set("type","knowledge");
	set("difficulty",150);
	set("effective_level",150);
	set("no_refund",({"wolf-strike","wolf-curse"}));

}

/*
void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("summonwolf", 1);
    	if (s== 150 && me->query("class")=="wolfmount") {
       		tell_object(me,HIW "��Ի���֮�����˽�����һ����Ծ��\n"NOR);
       		tell_object(me,HIW "�㻽�ǵĸ��������ˣ�\n"NOR);
       	} 
    	if (s== 180 && me->query("class")=="wolfmount") {
       		tell_object(me,HIW "��Ի���֮�����˽�����һ����Ծ��\n"NOR);
       		tell_object(me,HIW "����������ڻ����ˣ�\n"NOR);
       }
}

int valid_learn(object me) {
		
    	if(me->query_skill("animal-training",1)<= me->query_skill("summonwolf",1))
    	{
		return notify_fail("��������Ҫ��ͬ�ȼ���ѵ������������\n");
	}
	return ::valid_learn(me);
}*/


int help(object me)
{
	write(@HELP   
����������ɽ�󲿷��书�Ļ�����
�����⹦Ч�ǻ��ǣ����������Ҫ����������
����ο����� help xiao
HELP
    );
    return 1;
}
