#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( WHT"������"NOR, ({ "hong tianlei" , "lei"}) );
	set_weight(10);
	set("unit", "��");
    	set("long", "һ������������Բ�ΰ������ڲػ�ҩ�������������ˣ�shoot����\n");
	set("value", 1000);
	set("level", 50);
	set("no_drop", 1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage, exp_bonus, resist;
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
   
	t_exp = (int) target->query("combat_exp");
	exp   = (int) me->query("combat_exp");
	msg  = HIW"$N����ԣ�ָ������������һ" + query("unit") + name();
	msg += HIW"\nֻ��һ���׹⼱��"NOR"$n����\n\n"NOR;
	if( random(exp)*level/20 + exp/2 > t_exp ) {
		damage = me->query_skill("perception",1)* level /10;
		damage = damage + random(damage);
		if (userp(me)) exp_bonus= me->query("combat_exp")/1000*damage/4000;
		damage = damage + exp_bonus;
		if (damage>6000) damage = 6000;
		msg +=  name() +HIW "��һ�����������$n����\n" NOR;
		target->receive_wound("kee",damage,me);
		target->receive_wound("sen", damage/4, me);
		} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        }
   	me->start_busy(2);
	destruct(this_object());
	return 1;
}

