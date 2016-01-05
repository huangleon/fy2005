// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( WHT"����׶"NOR, ({ "luoyun zhui" , "zhui"}) );
	set_weight(10);
	set("unit", "��");
    	set("long", "һ�����������ķ�׶�������������ˣ�shootz����\n");
	set("value", 0);
	set("level", 50);
	set("no_drop", 1);
	set("no_burn",1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootz");
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, damage, exp_bonus;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("��Ҫ��˭��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");	
	
	level = (int) query("level");
   	damage = 0;
   
	msg  = HIW"$N����ԣ�ָ������������һ" + query("unit") + name()+HIW"��";
	msg += HIW"\nֻ��һ���׹⼱��$n����\n\n"NOR;

//	 success rate:1/2+ random(5)
//	damage = 200*100/10= 2000, 2000+random(2000); at 8M 3000+random(3000);
//	/3
	if (COMBAT_D->do_magic_attack( me, target, "magic", "sen", 50)) {
		msg +=  name() +HIW "��һ�����������$n����\n" NOR;
		damage = me->query_skill("alchemy",1)* level /30;
		damage = damage + random(damage);
		if (userp(me)) exp_bonus= (me->query("combat_exp")-4000000)/1000*damage/8000;
		damage = damage + exp_bonus;
		if (damage>6000) damage = 6000;
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage/3);
		target->receive_wound("kee",damage,me);
		target->set_temp("damaged_during_attack", 2);
           	message_vision(msg, me, target);
           	COMBAT_D->report_status(target);
           	COMBAT_D->win_lose_check(me,target,1);
           	
	} else
	{
		msg += YEL"���Ǳ�$n����ض㿪�ˡ�\n"NOR;
		message_vision(msg, me, target);
	}
   	me->start_busy(2);
	destruct(this_object());
	return 1;
}

