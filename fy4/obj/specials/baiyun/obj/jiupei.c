// - neon

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(MAG"����"NOR, ({ "jiupei", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 60);
		set("long", "����һ�����٣���ɫ����ϲ����ʽ�����履�����������ᣬ������ɰ��
֮ɫ�� ���ξ�ѣ�Ϊ����֮��Ʒ����\n");
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N�����������ң�"MAG"����"NOR"��������֮����������ɽ���ꡣ\n",this_player());
	return 1;
}













