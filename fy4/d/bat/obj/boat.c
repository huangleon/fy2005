#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "ľ��", ({ "boat" }) );
    set("unit", "��");
    set("value",0);
    set("no_get",1);
    set("long","һ��ľ������������������sail��\n");
    set_weight(150000);
	set("no_stack",1);
    ::init_item();
}

void init()
{
    add_action("do_sail","sail");
}

int do_sail(string arg)
{
    	if (!arg || arg == "boat" || arg == "ľ��") {
    		message_vision(HIY"$N����ľ��������Ưȥ������\n"NOR,this_player());
    		tell_object(this_player(),HIY"���˺ܾã����ڵ��˰��ߡ�\n"NOR);
    		this_player()->move(AREA_EASTCOAST"fchuan");
    		return 1;
    	}
    	write("�����ʻʲô��\n");
    	return 1;
}
