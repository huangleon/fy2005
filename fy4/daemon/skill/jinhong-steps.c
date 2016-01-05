// jinhong-steps.c

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","��粽��");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("difficulty",200);
	set("skill_class","assassin");
	set("dodge_msg", ({
		"$nһ�С���Ǯ���ء��������ɵر��˿�ȥ��\n",
		"ֻ��$n��Ӱһ�Σ�һʽ���������ԡ����ѱ����߳�֮�⡣\n",
		"$nʹ�����ƻ����ء����������ɵ�������\n",
		"$n����һ�㣬һ�С��������¡��ڿն��𣬱��˿�ȥ��\n",
		"����$nʹһ�С������ٷ硻����������Ʈ�˿�ȥ��\n",
	}) );
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("jinhong-steps", 1);
    	if (s== 100 && me->query("class")=="assassin") {
       		tell_object(me,HIW "��Խ�粽�����˽�����һ����Ծ��\n"NOR);
       } 
    	if (s== 150 && me->query("class")=="assassin") {
       		tell_object(me,HIW "��Խ�粽�����˽�����һ����Ծ��\n"NOR);
       		tell_object(me,HIW "��ġ�����է�֡�����ʹ������æ�����ˣ�\n"NOR);
       } 
    	if (s== 160 && me->query("class")=="assassin") {
       		tell_object(me,HIW "���Ȼ���ã�������Լ����ټ�����������ȼ��Ļ���\n"NOR);
       		tell_object(me,HIW "���ܹ��ѽ�粽����Ч�������һЩ��\n"NOR);
       	} 
       	if (s== 200 && me->query("class")=="assassin") {
       		tell_object(me,HIW "��ϲ�㣬��Ľ�粽���Ѵﵽ��ǰ�޹��˵ľ��硣\n"NOR);
       	}
}
