// - neon
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"���"NOR, ({ "luqi", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 30);
		set("long", "���尵����ɫ���ǹŴ�����֮һ��\n");
		
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N�Ღ���ң�"HIG"���"NOR"���������峪�����ɫ��\n",this_player());
	return 1;
}













