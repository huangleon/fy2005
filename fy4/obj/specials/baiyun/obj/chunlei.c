// - neon
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"����"NOR, ({ "chunlei", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 70);
		set("long", "���������������ƺ��ϴ֣�������Ҫ�ܸߵ����༼�����ǹŴ�����֮һ��\n");
		
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N���񵯲����ң�"HIC"����"NOR"�����ͳ������죬�����׳��������Ļꡣ\n",this_player());
	return 1;
}













