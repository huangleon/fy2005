//Xxder@fy3
inherit ITEM;
void create()
{
	set_name("�ݱ�����", ({ "insect" }) );
	set_weight(150);
        set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���òݱ������\n");
		set("value", 2);
	}
}
int is_container() { return 1; }
