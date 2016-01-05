// yaopai.c

inherit ITEM;

void create()
{
	::init_item();
	
	set_name("����", ({ "yaopai", "yao pai" }) );
	set_weight(70);
	set("yp",1);
	set("long", "һ��֤��������ݵ����ƣ��참ʱ���Գ�ʾ��show����\n");
	set("unit", "��");
	set("lore",1);
	set("value", 0);
}

void init()
{

        add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	if( !arg || arg != "yaopai" )
                return notify_fail("��Ҫ��ʾʲô��\n");
        
        me = this_player();
        ob = this_object();
        if( me->is_fighting() )
        	return notify_fail("��ս���г�ʾ����û���ã�����������˵��\n");
        if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ����ܳ��ԡ�\n");
        message_vision("$N��ʾһ��$n���е������鰸�ˣ������˵�����ϣ���������\n", me, ob);
    	environment(me)->show_notify(ob,0);
    	return 1;
}
