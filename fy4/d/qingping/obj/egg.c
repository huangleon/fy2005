//XXDER
inherit ITEM;
void create()
{
        set_name("С��", ({ "bird egg", "С��"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������л��Ƶ�С�񵰡� \n");
                set("value", 100);
        }
}

