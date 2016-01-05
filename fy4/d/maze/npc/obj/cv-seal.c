inherit ITEM;

void create()
{
	set_name("��а���", ({"seal"}) );
	set_weight(5);
	set("long",
		"���Ƕ��˷��÷���д�ɵ�һ�Ż����������䣨burn����\n");
	set("unit", "��");
        set("value", 0);
        set("fast_grab",1);
}


void init()
{
	add_action("do_burn", "burn");
}

int do_burn(string arg)
{
	string sheet, dest;
	object sobj;
	if( !arg || sscanf(arg, "%s", sheet)!=1 )
		return notify_fail("ָ���ʽ��burn <����>\n");
	if( !objectp(sobj = present(sheet, this_player()))) 
	        return notify_fail("��Ҫʹ�����ŷ��䣿\n");
	if( this_player()->is_busy())
		return notify_fail("������û���շ���\n");
	if(environment(this_player())->query("no_magic"))
           	return notify_fail("���ﲻ�����÷��䡣\n");
        if (query("paper_owner")!=this_player())
        	return notify_fail("���ŷ�����������á�\n");
	message_vision("\n$N����һ������а�����ȼ��������\n",this_player());
	tell_object(this_player(),"һ��������������˲��ɢȥ��������\n");
	
	if (REWARD_D->riddle_check(this_player(),"�ǻ�Ѫ��")==1)
		REWARD_D->riddle_set(this_player(),"�ǻ�Ѫ��",2);
	destruct(this_object());
	return 1;
}
