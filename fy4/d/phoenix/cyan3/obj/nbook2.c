
inherit ITEM;
void create()
{
	string *num = ({"���о�","�󷽹�ʮ�־�","Ե���¾�","�����ƽ侭"});
	set_name( num[2] , ({ "buddhism book","book"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ֳ��ķ𾭡�\n");
		set("unit", "��");
		set("value", 0);
	}
	::init_item();
}

