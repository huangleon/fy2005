// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("��̦", ({ "lichen" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("long", "��̦����ʯͷ�ı����ö���⻬��\n");
                set("value", 0);
        }
	::init_item();
}

