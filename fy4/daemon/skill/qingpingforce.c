// qingpingforce.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","��ƽ�ڹ�");
	set("type","force");
	set("usage/force",1);
	set("skill_class","shenshui");
	set("effective_level",100);
	set("difficulty",150);
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)< 90)
		return notify_fail("�������������ӿ��˿��㣬˵�����Ů������һЩ�������Ұգ���90����\n");

	return 1;
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("qingpingforce", 1);
		if (me->query("class") == "shenshui") {
/*	    	if (s == 100) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ������ƽ�ڹ��ġ�Ǭ��Ų�ơ���Ҳ�����ھ����ķ��С�\n"
	    				"��ѧ���˾����ķ��ġ�Ǭ��Ų�ơ���\n"NOR);
	    		me->set("pfm/9moon-qiankun",1); 
	    	} */
	    	if (s == 150) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ������ƽ�ڹ�������֮����Ҳ�����ھ����ķ��С�\n"
	    				"������ķ��ġ����������Ĺ�Ч��ǿ�ˡ�\n"NOR);
//	    		me->set("pfm/qingpingforce-9moon",1); 
	    	} 
    	}
    	return;
}


int help(object me)
{
	write(@HELP   
��ϰ��ƽ�ڹ���Ҫ90�����Ů��

L100 �������ľ�����������ķ�

L150 ��ǿ�����ķ��ġ����������Ĺ�Ч

HELP
    );
    return 1;
}
