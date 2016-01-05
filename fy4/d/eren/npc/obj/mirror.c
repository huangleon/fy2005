// neon@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void generate_name();

void create()
{	generate_name();
	set_weight(10);
	set("unit", "��");
    	set("long", "һ���������ı���(shootm)��\n");
	set("value", 0);
	set("level", 50);
	set("no_drop", 1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootm");
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
	msg  = query("color") + "$N����ԣ�����һ��������һ" + query("unit") + name();
	msg += query("color") + "\nֻ��һƬҫ�۵Ĺ�â����"NOR"$n����\n\n"NOR;
	//if( random(exp)/2 + exp/2 > t_exp ) {
	if( random(exp)*level/10 + exp/3 > t_exp ) {
		damage = me->query_skill("alchemy",1)* level /10;
		damage = damage/2 + random(damage);
		msg +=  query("color") + "$n����Ӱ��ʱ�������â��û�����ɵ�һ��ͷ���ۻ���\n" NOR;
		target->receive_wound("kee", damage/10, me);
		target->add("sen",-damage);
		target->add("eff_sen",-damage);
		target->receive_wound("sen",10,me);
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
	string *color = ({HIC, HIB, HIW});
	string *action = ({"��", "��", "׷","��"});
	string *kind = ({"��", "��","��"});
	string m_color =(color[random(sizeof(color))]);
	set_name( m_color +(action[random(sizeof(action))]) 
		   + (kind[random(sizeof(kind))])
		   + "��"NOR, ({ "jing" , "mirror"}) );
	set("color", m_color);
	
}
