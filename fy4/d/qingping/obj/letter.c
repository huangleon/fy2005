//XXDER
inherit ITEM;
void create()
{
        set_name("��", ({ "letter", "��"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ܷ��˵��š�\n");
                set("value", 100);
        }
}
