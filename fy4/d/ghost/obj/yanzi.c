inherit ITEM;

void create()
{
        set_name("С����",({ "yanzi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "paper");
                set("long", "һֻС���ӡ�\n");
        }
	::init_item();
}
