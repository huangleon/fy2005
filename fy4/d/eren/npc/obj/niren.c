inherit ITEM;
void create()
{
	set_name("С����" , ({ "small toy" , "toy"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("24dao_ren",1);
		set("unit", "��");
		set("long", "һ��������ɵ�С�ˣ����������ɣ�������ӨӨ�Ĺ�â��
һ����֪������ȥ����һ��С��������ߣ����˵ĵײ�
����һ�����̡��֡�\n");
		set("value", 100);
	}
	::init_item();
}



