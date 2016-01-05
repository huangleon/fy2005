#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","����ȭ");
	set("type","unarmed");
	set("effective_level",100);
	set("difficulty",200);
	set("practice_limit",30);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("parry_msg",			({
			"$n��ͬ�С���ֻ�š�һ�㣬����ŤŤ�����˿�ȥ��\n",
			})
	);
	set("unarmed_parry_msg", 	({
			"$n��ͬ�С���ֻ�š�һ�㣬����ŤŤ�����˿�ȥ��\n",
			})
	);
	action = ({
			([	"action":		"$N����һ�ᣬ����һȭ����$n��ȥ",
				"dodge":		210,
				"parry":		210,
				"damage_type":	"����"
			]),
			([	"action":		"$N����һ��������һȭ����$n��ȥ",
				"dodge":		210,
				"parry":		210,
				"damage_type":	"����"
			]),
	});
}


mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	me->set_temp("annie/birdiestrike",act+1);
	return action[act];
}

mixed hit_ob(object me, object victim)
{
	int act, pro, dam,i;
	
	
/*	if (ANNIE_D->check_buff(me,"tx-turtle-stance")>0) {
			me->ccommand("say nope"); 
			return 0;	
	}*/
		
	act=me->query_temp("annie/birdiestrike");
	if (act == me->query_temp("annie/birdiestrike2") && victim == me->query_temp("annie/birdiestrike4"))
	{
		me->add_temp("annie/birdiestrike3",1);
		pro = me->query_temp("annie/birdiestrike3");
//		me->ccommand("say pro ="+pro);
		if (pro * 20 > me->query_skill("birdiestrike",1))
			pro = me->query_skill("birdiestrike",1)/20;
		// 20/40/60(res. 10lv)/80/100/120/140/160
		// 64/128/256/512/1024/2052/4108/8216
//		me->ccommand("say pro ="+pro);
		if (pro < 1)
			pro = 1;
		dam = 32;
		for (i=0; i<pro; i++)
			dam*=2;
				
		dam = COMBAT_D->magic_modifier(me, victim, "kee", dam);
		victim->receive_damage("kee",dam,me);
//		me->ccommand("say extra damage ="+dam);
		return HIG"����$N����ʽ��һ�����������ľ�������$n���澭����֮�У���\n" NOR;
	}
	else
	{
		me->set_temp("annie/birdiestrike2",act);
		me->set_temp("annie/birdiestrike3",0);
		me->set_temp("annie/birdiestrike4",victim);
	}
	return 0;
}

int effective_level(object me)
{
	int skill,n;

	if (me && userp(me))
	{
		skill= me->query_skill("birdiestrike",1);
		if (skill <= 32)	return 200;	// enable 64
		if (skill <= 49)	return 205;	// enable 100
		if (skill <= 51)	return 210;	// enable 107 (research->)
		if (skill <= 61)	return 220;	// enable 134
		if (skill <= 99)	return 250;	// enable 247
		if (skill >= 161)	return 270;	// enable 432
	}
	return 220;
}

int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill=this_player()->query_skill("birdiestrike",1);
		if (skill <= 41)
			return 300;
		if (skill <= 51)
			return 400;
		if (skill <= 61)	// 51-61 21470 pot
			return 500;		
		if (skill <= 99)	// 61-99 435740 pot
			return 600;
		if (skill <= 160)	// 99-160 253455 pot
			return 800;
		return 1000;			// 161-200 391300 pot
	}
	return 300;
}

int help(object me)
{
	write(@HELP   
����ȭ��һ�����ص�ȭ����������ʽ�ܼ򵥣�ֻ�����У���һȭ����
һȭ�����ǵ�������ͬ����ʽ�������ж���ʱ��������ɶ�����˺���
�����˺���=32*2^n ��nΪ������ͬ��ʽ����Ŀ��
���nͬʱ�ܵ�����ȭ�ȼ������ƣ�n<=������ȭ/20)
Ҳ����˵��������ж�ʮ������ȭ���������˺�=64
�������160�������������˺�=32*2^8=8192

����ȭ��ϵ���漶����߶���ߣ�ѧϰ�Ѷ�Ҳ�𲽼Ӵ󣬵���ĳЩ��
�����һЩ��ֵĵ͹�
�书ϵ����200(<=32)��205(<=49)��210(<=51)��220(<=61)��
250(<=99)��200(<=160)��270(>160)
ѧϰ�Ѷȣ�300(<=41)��400(<=51)��500(<=61)��600(<=99)��
800(<=160)��1000(>160)
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
