#include <ansi.h>
#include <combat.h>
inherit COMBINED_ITEM;


void create()
{
  	set_name(CYN"��늷�"NOR,({"paper seal","seal"}));
	set_weight(10);
	set("unit", "��");
   	set("long", "һ�Ż����������Ƶķ�ֽ���������æ�����غϡ�\n");
  	set("desc_ext","������burn <����id>��");
  	set("base_unit","��");
  	set("base_weight",50);
  	set("base_value",500);
  	set("volumn",1);
	set("value", 0);
//	set("lore",1);
  	set_amount(1);
	::init_item();
}

void init(){
  	if(this_player()==environment())
  		add_action("do_shoot",({ "burn"}));
}

int do_shoot(string arg){
	object me, target;
	int extra=150,myexp;
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
   
	myexp = me->query("combat_exp")*2/5+ random(me->query("combat_exp") / 100 * extra);
	message_vision(HIY"\n$N"HIY"����һ�ż����ֽ��ֻ��"NOR,  me); 
	if(myexp >target->query("combat_exp")&& !target->query("boss") && !target->query("big_boss"))
	{
		message_vision(HIY"����к�âһ����һ�����������\n�ܶ���ֱû��$N"HIY"ǰ��֮�С�\n"NOR, target); 
 		message_vision(HIW"$N��ʱ�������꣬���������������á�\n"NOR, target); 
		extra=target->query("no_busy");
		target->delete("no_busy");
		target->force_busy(3);
		target->set("no_busy",extra);
	}
	else
		message_vision(HIY"��ֽ��������Ϊ�ҽ���ȴʲôҲû�з�����\n"NOR, target, me); 
	me->perform_busy(1);
	add_amount(-1);
	return 1;
}

    
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
