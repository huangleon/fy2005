inherit ITEM;
void create()
{
        set_name( "����", ({"gao", "tie gao"}) );
        set_weight(800);
        set_max_encumbrance(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long","һ��Լ���߶೤�����䡣\n");
                set("material", "iron");
        }
	::init_item();
}

void init()
{
        add_action("do_dig","dig");
}

int do_dig()
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if( me->is_fighting() )
        	return notify_fail("��ս�����ٵأ���������\n");
        if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ������ٵء�\n");
	tell_object(me,"���ͳ�һ��"+ob->name()+"�������������ȥ��\n");
    	environment(me)->dig_notify(ob,0);
    	return 1;
}
