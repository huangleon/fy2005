inherit ITEM;

void create()
{
        set_name("������",({ "butterfly" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "paper");
                set("long", "һֻ�ۺ�ɫ�ĺ�����\n");
        }
	::init_item();
}
