inherit ITEM;

void create()
{
    set_name("��ɫ��ҩ", ({ "powder" }) );
    set_weight(5000);
    set("explosive",1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit","Ͱ");
        set("long", "һͰ��Ϊ���ҵĻ�ҩ��\n");
        set("value", 1);
    }
    ::init_item();
}