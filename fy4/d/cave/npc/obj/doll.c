
inherit ITEM;
void create()
{
    set_name("������" , ({ "doll"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ��������ϸ�Ĳ����ޣ��ɰ���Ȥ���Ǹ�����Զ�������͸�˫˫�ġ�\n");
        set("value", 5);
	}
	::init_item();
}



