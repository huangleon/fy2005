//
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;
void init()
{
        if(environment()==this_player())
	        add_action("do_drink", "drink");
        if(environment()==this_player())
	        add_action("do_fill", "fill");

}

void create()
{
	set_name(HIR"��˹�����Ѿ�"NOR, ({ "wine" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ˮ����������͸����Һ��������ϸС�����ݼ���������\n");
		set("unit", "յ");
		set("value", 1500);
        set("liquid", ([
        "type": "wine",
        "name": "��˹�����Ѿ�",
        "remaining": 1,
        "drunk_apply": 1,
        ]) );	
	}
	 ::init_item();
}

int do_fill()
{
	write("���ˮ����̫С�ˣ�ʲôҲװ��������\n");
	return 1;
}
