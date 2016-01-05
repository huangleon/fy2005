inherit SMART_NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
	object weapon;
    	set_name("÷", ({ "mei"}) );
    	set("nickname", BLU"��"NOR);
    	set("gender", "Ů��" );
    	set("class","beggar");

		set("title",YEL"�������"NOR);
    
    	set("reward_npc", 1);
    	set("difficulty", 6);
    
    	set("age", 34);
    	set("per", 35);
    	set("attitude","friendly");

		set("combat_exp", 6100000);
    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
     	}) ); 		

		auto_npc_setup("wang",200,190,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
        setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set("nodrop_weapon",1);
        weapon->set_name("��÷֦", ({ "meizhi" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�䶬��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

/*
int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);
	return 1;
}
*/
/*
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
		message_vision(CYN"\n÷����һЦ������ƮŲ������ƿ�г��һ��÷֦��\n\n"NOR,me);
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("��÷֦", ({ "meizhi" }) );
		weapon->set("value",0);
		weapon->wield();
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

		if (COMBAT_D->do_busy_attack( me, target, "dagou-stick/banzijue", "step", 300, COMBAT_D->can_busy(me, target, "dagou-stick")))
		{
			msg = HIG"\nֻ��"+ weapon->name() + HIG"���ڵ��£����ᵯ��$n"HIG"�ƺ���һ����������ȥһ����\n"
			HIR+ weapon->name()+HIR"��ž����һ�����ݺ�����$n"HIR"�ֹ��ϣ�"NOR"\n\n"
			WHT"���ų����ҽУ�$n��ͨһ�µ��ڵ��ϣ�\n\n"NOR;
			target->force_busy(3);
			target->receive_wound("kee", extra+random(extra*2), me);
			call_out("get_up",3, me,target);
			message_vision(msg,me,target);
			target->set_temp("busy_timer/dagou-stick",time());
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
*/

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
