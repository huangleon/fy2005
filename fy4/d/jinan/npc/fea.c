inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
    	set_name("����", ({ "fea"}) );
    	set("nickname", WHT "ǧ����ʣ�����һĬ"NOR);
    	set("gender", "����" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 12);
    
    	set("age", 34);
    	set("per", 35);
    	set("int",30);

    	set("attitude","friendly");
    
    	create_family("ؤ��", 7, "ִ�ȳ���");

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: smart_fight() :),
             }) );

    	set("combat_exp", 10000000);
    
    	set_skill("perception", 200);
    	set_skill("move", 200);
    	set_skill("parry",200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("unarmed",200);
    	set_skill("doggiesteps",170);
    	set_skill("dragonstrike",220);
    	set_skill("huntunforce",150);
    	set_skill("staff",400);
    	set_skill("dagou-stick",220);
    	
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dagou-stick");
    	
    	
    setup();
    carry_object(__DIR__"obj/9bagcloth")->wear();
    carry_object(__DIR__"obj/ego")->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
//	stop_busy();	// lets cheat a bit
//	ccommand("perform banzijue");
	smart_fight();
	return 1;
}

void smart_fight()
{
	object *enemy,target,weapon,me;
	int i,extra, myexp, enemyexp, lvl, mod;
	string msg;

	if (is_busy())
		return;

	me = this_object();
	enemy = me->query_enemy();
	weapon = me->query_temp("weapon");

	if (!weapon)
	{
		message_vision(CYN"\n����΢΢һЦ������ƿ�г��һ��÷֦��\n\n"NOR,me);
	    carry_object(__DIR__"obj/ego")->wield();
		weapon = me->query_temp("weapon");
	}

	lvl = me->query_skill("dagou-stick",1);

	extra = me->query_skill("staff");	
	myexp = me->query("combat_exp");

	for (i=0;i<sizeof(enemy); i++)
	{
		target = enemy[i];
		enemyexp = target->query("combat_exp");


		if (i == 0)
			msg = YEL"\n$N"YEL"��׼$n"YEL"����������������"+ weapon->name() + YEL"�����ѵ�ˮ����������$n"YEL"���̡�\n" NOR;
		else
			msg = YEL+"\n"+weapon->name()+YEL"���ڵ��ϣ�΢΢һ�ߣ���������˳������$n"+YEL"���̡�\n"NOR;

		if (target->query_temp("disable_type") && target->query_temp("is_unconcious"))
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		else 
			message_vision(msg,me,target); 

		if ( myexp/3 + random(myexp/80*extra) > enemyexp)
		{
			msg = HIG"\nֻ��"+ weapon->name() + HIG"���ڵ��£����ᵯ��$n"HIG"�ƺ���һ����������ȥһ����\n"
			HIR+ weapon->name()+HIR"��ž����һ�����ݺ�����$n"HIR"�ֹ��ϣ�"NOR"\n\n"
			WHT"���ų����ҽУ�$n��ͨһ�µ��ڵ��ϣ�\n\n"NOR;
			target->force_busy(3);
			target->receive_wound("kee", extra+random(extra*2), me);
			call_out("get_up",3, me,target);
			message_vision(msg,me,target);
			COMBAT_D->report_status(target);
			COMBAT_D->win_lose_check(me,target,1);
		}
		else
		{
			me->add_temp("apply/attack", extra/2);
			me->add_temp("apply/damage", extra/2);
			msg = HIR"\n�ۼ�$nѸ�ٱ任������$Nֻ����ʽͻ����һ�����ֻӳ���\n"NOR;
			COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
			me->add_temp("apply/attack", -extra/2);
			me->add_temp("apply/damage", -extra/2);
		}

	}
	me->perform_busy(2);
	return ;
}


void get_up(object me,object target)
{
	if(!target || !living(target) || target->is_ghost())
		return ;
	message_vision(YEL "\n\n$N�ڵ��ϴ��˼�������������ʹ�Ǳ�������������������\n\n" NOR, target);
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
