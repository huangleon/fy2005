// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit ITEM;

void create()
{
        set_name("ī", ({ "mo", "��ī", }) );
        set_weight(700);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ķ��þ�֮һ��\n");
                set("value", 1000);
                set("color", "��");
        }
	::init_item();
}