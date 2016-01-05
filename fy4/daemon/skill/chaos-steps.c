#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","�������ǲ�");
	set("effective_level",170);
	set("type","step");
	set("skill_class","shenshui");
	set("usage/dodge",1);
	set("usage/move",1);
	set("difficulty",150);
	
	set("practice_limit",1);
	set("dodge_msg", 			({
			"$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
			"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
			"$nʹ������ת��Ȩ�����������ɵ�������\n",
			"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
			"����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
			"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
			"����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
			})
	);
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)<160)
		return notify_fail("�������������ӿ��˿��㣬˵�����Ů������һЩ�������Ұգ���160����\n");

	return ::valid_learn(me);
}

void skill_improved(object me)
{
		int s;
		s = me->query_skill("chaos-steps", 1);
		if (me->query("class") == "shenshui") {
	    	if (s == 50 && !me->query("pfm/chaos-9moon")) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ���⵹�����ǲ������ţ���Ҳ�����ھ������С�\n"
	    				"��ľ����������һ������\n"NOR);
//	    		me->set("pfm/chaos-9moon",10); 
	    	} else if (s == 100) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ���⵹�����ǲ������ţ���Ҳ�����ھ������С�\n"
	    				"��ľ����������һ������\n"NOR);
/*	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ���⵹�����ǲ��ġ���������Ҳ�����ھ������С�\n"
	    				"��ѧ���˾������ġ�����ʽ����\n"NOR);
	    		me->set("pfm/9moon-feiyanshi",1);*/ 
//	    		me->set("pfm/chaos-9moon",20); 
	    	} 
/*	    	else if (s == 120) {
	    		tell_object(me,WHT"���������ͻ�����⵹�����ǲ��ġ�������������Ͼ�����ץ�ġ���­����\n"
	    				"��ѧ���˾������ġ�׷��ʽ����\n"NOR);
	    		me->set("pfm/9moon-zhuimingshi",1); 
	    	} */
	    	else if ( s == 150) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ���������ǲ���������Ҳ�����ھ������С�\n"
	    				"�����㣬��ľ������뵹�����ǲ������ڻ��ͨ��\n"NOR);
//	    		me->set("pfm/chaos-9moon",30);
	    	}
		}
		return;
}


int help(object me)
{
	write(@HELP   
��ϰ�������ǲ�������Ҫ160�����Ů��

L50  ����������Чϵ�����160
L100 ����������Чϵ�����170
L150 ����������Чϵ�������180
HELP
);
    return 1;
}


