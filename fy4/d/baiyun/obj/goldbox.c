inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"�������"NOR, ({ "gold box", "box","�������" }) );
	set_weight(5000);        
	set_max_encumbrance(2000);	
	set("prep","on");        
	if( clonep() )                
		set_default_object(__FILE__);        
	else 
	{
		set("unit", "��");
		set("long", "���������ӵ������ڣ����Ƕ���ƺ����Դ򿪣�������\n");
		set("value", 5000);
		set("closed", 1);
	}
	::init_item();
}

int is_container() 
{ 
	return 1; 
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}
int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "gold box"&& arg != "box"&& arg != "�������" )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	message_vision("$N�����$n��\n", me, ob);
	ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
