
inherit ITEM;
void create()
{
	set_name("������", ({ "rusty device","device"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�̶��ڹ���̨�ϵ������̣��������������ʴ�������������������á�\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}

