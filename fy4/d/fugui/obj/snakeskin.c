inherit ITEM;
void create()
{
	set_name("�˻���Ƥ", ({ "snake skin","skin"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long",
			"һ��˻��߹�����ȥ�ġ���Ƥ����\n");
		set("value", 0);
		set("material", "food");
	}
	::init_item();
}
