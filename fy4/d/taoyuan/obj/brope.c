
inherit ITEM;

void create()
{
    	set_name("������", ({ "rope" }) );
    	set_weight(10000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "��ɫ�����������������͵Ĺ�����Ҳ�����������˩סʲô������壩��\n");
        	set("value", 0);
    	}
    	::init_item();
}

void init() {
	
	add_action("do_use", "tie");
}

int do_use(string arg)
{
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
	if (!environment(this_player())->tie_notify(this_object()))
		return notify_fail("���Ĵ����˿������ûʲô�ط���������˩ס���ӡ�\n");
	destruct(this_object());
        return 1;
}
