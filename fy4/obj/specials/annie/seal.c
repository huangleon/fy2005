#include <ansi.h>
#include <combat.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name(CYN"������"NOR,({"paper seal","seal"}));
	set_weight(10);
	set("unit", "��");
   	set("long", "һ�Ż������������ķ�ֽ��\n");
  	set("base_unit","��");
  	set("base_weight",50);
  	set("base_value",0);
  	set("volumn",1);
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
//	set("lore",1);
  	set_amount(1);
	::init_item();
}

void init(){
  	if(this_player()==environment())
  		add_action("do_shoot",({ "burn","burn" }));
}

int do_shoot(string arg)
{
	object me, target;
	int extra=150,myexp;
	string msg;

	
	me = this_player();
	if (!arg) return notify_fail("��Ҫ��˭ʹ�÷�����\n");
	if( !me->is_busy() )
		return notify_fail("�������޷�ʹ�ø�������\n");
	
	extra=me->query_busy()/2+random(me->query_busy());

	target = present(arg,environment(me));
	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) ) 
		return notify_fail( this_object()->name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");	

	extra += target->query_busy();

	message_vision(HIY"\n$N"HIY"����һ�Ÿ�����ֽ��ֻ��"NOR,  me); 
	message_vision(HIY"����к�âһ����һ�������ڿն�����������\n����$N"HIY"��ת��\n"NOR, target); 
	message_vision(HIW"$N���������ͣ���ʱ�������á�\n"NOR, target); 
	myexp=target->query("no_busy");
	target->delete("no_busy");
	target->force_busy(extra);
	target->set("no_busy",myexp);
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




