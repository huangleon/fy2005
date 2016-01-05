// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	generate_name();
	set_weight(10);
	set("unit", "��");
    	set("long", "һ�������߰��������shootc����\n");
	set("value", 0);
	set("level", 50);
	set("no_drop", 1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootc");
}

int do_shoot(string arg){
	object me, target;
	int level, exp, t_exp, damage;
	int busy_num;
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
	msg  = query("color") + "\n$N����ԣ�����һ" + query("unit") + name();
	msg += query("color") + "\n\n����������ض���������С�\n����������Ϣ����Ȼ�����������ӿ��з�����$n��������\n\n"NOR;
	//if( random(exp)/2 + exp/2 > t_exp ) {
	if( random(exp)*level/50 + 4*exp/5 > t_exp ) {
		damage = me->query_skill("alchemy",1)* level /10;
		damage = damage/2 + 2 * random(damage);
		msg +=  query("color") + "������������������$n��Χ��$nһ����æ���ң�\n" NOR;
		target->receive_wound("kee", damage/20, me);
		target->add("sen",-damage/5);
		target->add("eff_sen",-damage/5);
		target->receive_damage("sen", 1, me);
		if (target->query("no_busy")) {
			busy_num = target->query("no_busy");
			target->delete("no_busy");
			call_out ("busy_recover",12, busy_num, target);
		}

		target->start_busy(4);
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

void generate_name(){
	string *color = ({YEL, WHT, MAG});
	string *action = ({"��", "��", "��","��"});
	string *kind = ({"����", "����","����"});
	string m_color =(color[random(sizeof(color))]);
	set_name( m_color +(action[random(sizeof(action))]) 
		   + (kind[random(sizeof(kind))])
		   + NOR, ({ "lian" , "chain"}) );
	set("color", m_color);
	
}

int busy_recover (int busy_num, object obj)
{
	obj->set("no_busy",busy_num);
	return 1;
}	