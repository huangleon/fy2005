inherit ITEM;

void create()
{
	::init_item();
	
	set_name("�������", ({ "yaopai", "yao pai" }) );
	set_weight(70);
	set("yp",1);
	set("long", "һ���������������������ƣ����Գ�ʾ��show����\n");
	set("unit", "��");
	set("value", 0);
}

void init()
{
        if (environment(this_object()) == this_player())
        	add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	if( !arg || arg != "yaopai" )
                return notify_fail("��Ҫ��ʾʲô��\n");
        
        me = this_player();
        ob = this_object();
        if(me->is_fighting() )
        	return notify_fail("��ս���г�ʾ����û���ã�����������˵��\n");
        if(me->is_busy() )
        	return notify_fail("����һ��������û����ɡ�\n");
        message_vision("$N��ʾһ��$n���е�����������̣��ĳ���£�ǧ�����أ�һͳ��������\n", me, ob);
    	return 1;
}
