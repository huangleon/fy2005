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
	set("no_drop",1);
	set("no_burn",1);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootc");
	add_action("do_shoot", "shoot");
}

int do_shoot(string arg){
	object me, target;
	int level, mod;
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
	
	if (target->is_busy())
		return notify_fail("�Է��Ѿ���æ�����ˡ�\n");
	
	level = (int) query("level");
   	   
	msg  = query("color") + "\n$N����ԣ�����һ" + query("unit") + name() +"��";
	msg += query("color") + "\n\n����������ض���������С�\n����������Ϣ����Ȼ�����������ӿ��з�����$n��������\n\n"NOR;
	
	mod = COMBAT_D->can_busy(me, target, "alchemy");	
	if (!mod)	mod = 10000;
	if (COMBAT_D->do_busy_attack(me, target,"chain", "step", 200, mod))
	{
		msg +=  query("color") + "������������������$n��Χ��$nһ����æ���ң�\n" NOR;
		target->force_busy(4);
		target->set_temp("busy_timer/chain",time());
		message_vision(msg, me, target);
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
	string *color = ({YEL, WHT, MAG});
	string *action = ({"��", "��", "��","��"});
	string *kind = ({"����", "����","����"});
	string m_color =(color[random(sizeof(color))]);
	set_name( m_color +(action[random(sizeof(action))]) 
		   + (kind[random(sizeof(kind))])
		   + NOR, ({ "lian" , "chain"}) );
	set("color", m_color);
	
}
