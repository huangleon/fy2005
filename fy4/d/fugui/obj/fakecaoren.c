inherit ITEM;
void create()
{
	set_name("������", ({ "daocao ren","ren" }) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "һ������������ȸ�ĵ����ˣ����ޱ�����ڷ���Ʈ����\n");
		set("value", 1);
	}
	::init_item();
}
