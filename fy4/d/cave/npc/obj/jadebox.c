inherit ITEM;
void create()
{
    set_name("ȸ�����", ({ "jadebox", "box", "jade box" }) );
	set_weight(500);        
	set_max_encumbrance(800);	
	set("prep","on");        
	if( clonep() )                
		set_default_object(__FILE__);        
	else 
	{
		set("unit", "��");
       	set("long", "һ�������ɶ��칤�İ�����ӡ�\n");
		set("prep", "��");
		set("value", 100);
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
        if( !arg || arg != "jadebox" )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	message_vision("$NС�������$n��\n", me, ob);
	ob->set("closed",0);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
