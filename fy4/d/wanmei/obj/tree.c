inherit COMBINED_ITEM;
void create()
{
	set_name("÷������", ({ "tree", "plum tree" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","������������磬Ҳ������������죨����壩Щ������\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10000);
		set("base_value", 1);
	}
	set_amount(1);
}


void init()
{
    if(this_player()==environment()) {
        	add_action("do_make","make");
    }
}


int do_make()
{
	object boat;
	string msg;

	if(query_amount() < 15)
		return notify_fail("��Сľ��������Ҫ15��ľ�ġ�\n");
	seteuid(getuid());
	boat = new(__DIR__"boat");
    
    msg = "$N�����ɵ�˫�������һֻСľ��";
    if(!boat->move(this_player()))
    {
    	boat->move(environment(this_player()));
    	msg += "������ߡ�\n";
    } else
    	msg +="��\n";
    message_vision(msg, this_player());
	destruct(this_object());
	return 1;
			
}
