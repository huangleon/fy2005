inherit ITEM;

void create()
{
    set_name("���ͷ", ({ "fish bone" , "���ͷ"}) );
    set("marks/catfood",1);
    set_weight(20);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ�����Եĸɸɾ��������ͷ�� \n");
        set("value", 0);
    }
    ::init_item();
}


