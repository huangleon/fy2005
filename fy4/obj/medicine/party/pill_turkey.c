inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"����"NOR , ({ "turkey" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  		set("long", RED"һ��ֻ��������Ŀ��𼦣����Ŷ���ˮֱ����\n"NOR);
        	set("unit", "ֻ");
        	set("lore",1);
        	set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
	mapping buff;
	object me = this_player();
	int amount;
	string msg;
	
	if (ANNIE_D->check_buff(me,"strup"))	// it won't show up..just eat it.
		return notify_fail("��ζ���档\n"); 
					
	msg = HIR "$N�˲������ܵ������������̻��ʵĿ�����������ʱ�˿�ң��Զ����������һ������Ǹö�á�\n"NOR;
/*	
	buff =
		([
			"caster": me,
			"who":   me,
			"type": "gks",
			"att":	"bless",
			"name":	"��õ�嶹ɳ�±�",
			"buff1": "kee",
			"buff1_c":1333,
			"buff2": "gin",
			"buff2_c":1888,
			"buff3": "sen",
			"buff3_c":1666, 
			"time":  43200 ,
			"buff_msg": msg,
			"disa_msg": "",
			"special_func":1,
		]);
*/		
		buff =
		([
			"caster":me,
			"who": 	me,
			"type":	"strup",
			"att":	"bless",
			"name":	"����",
			"buff1":"apply/strength",
			"buff1_c":10,
			"time":  43200 ,
			//"buff_msg":BGRN + WHT"$N��������������������죬���ξ�Ȼ�ߴ���һ�أ���\n"NOR,
			"buff_msg":msg,
//			"disa_msg": "",
//			"special_func":1,
		]);
        ANNIE_D->buffup(buff);      
        destruct(this_object());
  	return 1;
}
