// stormdance.c
// annie 07.2003
// dancing_faery@hotmail.com


#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","��������Ӱ");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",175);
	set("difficulty",200);
	set("skill_class","berserker");
	set("dodge_msg", ({
		"$n���ӵ�����һ���߳�����$N�������ɣ�\n",
		"$n����һЦ��˫��һת�����߶�����$N��֮�£���æ�ù�һ�ߡ�\n",
		"����$n������ȥ������ڵ���һ�㣬��������$N���ţ�$N��æһ���ܿ���\n",
	}) );
}

mixed dodge_ob(object victim, object me,int attack_type)
{
	mapping buff;
	if (userp(me) && me->query("class")!="berserker")		return 0;
	if (me->query_skill("xifengying",1)<100)	return 0;

	if (ANNIE_D->check_buff(victim,"lockfield"))	return 0;

	buff =
		([
			"caster":me,
			"who":victim,
			"type":"lockfield",
			"att":"curse",
			"name":"��������Ӱ����������",
			"time":30,
			"buff_msg":MAG"\n$n"NOR+MAG"��ǹ���һ˿�������޵�΢Ц��ʳ������ָ�������۾���Ļ��Σ�$N"NOR+MAG"��
������ֻ�۾������˽�ȥ��\n"NOR,
		]);
	
	ANNIE_D->buffup(buff);
	tell_object(victim,CYN"��ǰ�ľ�ɫ������һ�㵭�������������ģģ����������ˮ�澵Ӱ��Ť��������
��ֻ��΢΢��ѣ��������Щ��㱣��·��ݽ����ξ�һ�㡣\n"NOR);
	me->perform_busy(1);

	return 0;
}	

int help(object me)
{
	write(@HELP   
	
�ȼ�100���ϵ�����Ӱ��ս���п���ʹ���������޷����ѡ�

HELP
    );
    return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
