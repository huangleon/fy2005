// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	generate_name();
	set_weight(10);
	set("unit", "��");
    	set("long", "һ����ɫ�����廨���죨shootf����\n");
	set("value", 0);
	set("level", 100);
	set("no_drop", 1);
	set("no_burn",1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootf");
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage;
	string msg;
	
	me = this_player();
	if (!arg) return notify_fail("��Ҫ��˭ʹ�÷�����\n");
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
	
	msg  = query("color") + "$N����ԣ�����ϼ������������һ" + query("unit") + name()+query("color")+"��";
	msg += query("color") + "\nֻ�����ز���ӿ��$n����\n\n"NOR;

	if (COMBAT_D->do_magic_attack( me, target, "magic", "gin", 50)) {
//		damage = 2000, 1000 +random(2000), gin :500+random(1000), kee, 333+random(666)
//		/2
		msg +=  query("color") + "$n��û�������У������ͻ�������ţ����ɾ�ƣ������\n" NOR;
		
		damage = me->query_skill("alchemy",1)* level /30;
		damage = damage/2 + random(damage);
		damage = COMBAT_D->magic_modifier(me, target, "gin", damage/2);
		target->receive_wound("gin",damage/2, me);
		target->receive_wound("kee", damage/3, me);
		if (userp(target)) {
		if (target->query("force") > damage)
			target->add("force", 1 - damage);
		else
			target->set("force", 0);
		}
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

void generate_name(){
	string *color = ({HIM, HIR, HIY});
	string *action = ({"¾", "��", "��","��"});
	string *kind = ({"��", "��","��"});
	string m_color =(color[random(sizeof(color))]);
	set_name( m_color +(action[random(sizeof(action))]) 
		   + (kind[random(sizeof(kind))])
		   + "�"NOR, ({ "fan" , "flag"}) );
	set("color", m_color);
	
}
