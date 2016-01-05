#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{	set_name( WHT"��������"NOR, ({ "shen zhen" , "zhen"}) );
	set_weight(10);
	set("unit", "��");
    set("long", "һ����Ө�����룬��˵��ǧ�����Ѫ����ݹ������߹��ֽ����������ڲ��ܶ���������æ��һ�֣�������Ҫ��ʮ������֮����ע�⣬�˰�������ʹ��Ч�����ѡ�\n");
	set("desc_ext", "shootz ĳ��");
	set("value", 7000);
	set("level", 50);
	::init_item();
}

void init(){
	add_action("do_shoot", "shootz");
}

int do_shoot(string arg){
	object me, target;
	int mod, level;
	string msg;
	 
	
	me = this_player();
	
	if (!arg) return notify_fail("��Ҫ��˭ʹ�ð�����\n");
	
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	target = present(arg,environment(me));
		
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");	
	if (target->is_busy())
		return notify_fail("�Է��Ѿ����ܶ����ˡ�\n");
	
	level = me->query_skill("theorem",1);
	if (level< query("level")){
		tell_object(me,"����Ҫ"+ query("level")+"������֮������ʹ�ô˰�����\n");
		return 1;
	}
	
	msg  = WHT"\n$N����һ�ӣ�"NOR +name()+WHT"������Ϣ�ش������зɳ���\n\n"NOR;
	
	mod = COMBAT_D->can_busy(me, target, "meihua-biao");	
	if (!mod) mod = 10000;
	
	if (COMBAT_D->do_busy_attack( me, target, "du-anqi","step",300, mod)) {
		msg +=  HIM + "$n����һ�飬�������ã�\n" NOR;
			target->force_busy(3);
	} else
		msg += YEL"���Ǳ�$n����ض㿪�ˡ�\n"NOR;
	
	target->set_temp("busy_timer/meihua-biao",time());
	message_vision(msg, me, target);
	me->perform_busy(1);
	destruct(this_object());
	return 1;
}
