#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name(HIR"�Ǻ�«"NOR, ({ "candy"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������������𣬹���һ�㱡���������ǵ��Ǻ�«��\n");
		set("unit", "��");
		set("value", 1500);
		set("food_remaining", 2);
		set("food_supply", 3);
		set("material", "food");
	}
	::init_item();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
