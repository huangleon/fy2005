// xiaodao.c edit by hippo 2009 sh site
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","Т��");
	set("skill_class","basic");
	set("difficulty",100);
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",150);
}	

void skill_improved(object me) {
			int s;
			s = me->query_skill("xiaodao", 1);
		   	if (s == 50 || s == 100 || s == 150 || s == 200) 
	    		tell_object(me,WHT"������ѧТ�������������Ϣ��˳���ˡ�\n"NOR);
			return;
}

int valid_learn(object me)
{

	if (me->query_skill("xiaodao",1) >= me->query_skill("theorem",1)*2)
		return notify_fail("�������֮����򲻹���\n");

	return ::valid_learn(me);
}

int help(object me)
{
	write(@HELP   
������/2�ȼ�������֮����ѧ�ɺ����ߣ������
����硡��顡�����Ļظ�Ч�ʣ������ѧ�á�
�˼���Ϊ�������ܣ�����Enable�����Զ���Ч��
L0�� �ظ���Ϊ100%
L50���ظ���Ϊ107%
L100���ظ���Ϊ115%
L150���ظ���Ϊ122%
L200���ظ���Ϊ130%
ע�����⻹�����ĳЩ���⼼�ܵ�ɱ��������
HELP
);
    return 1;
}