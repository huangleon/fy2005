//tieflag.c
inherit ITEM;
void create()
{
    set_name("��Ѫ����", ({ "flag" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 0);
            set("material", "cloth");
            set("long", "һ������ѪȾ�ɵ����ģ�����Ѫ�������������\n");
          }

    ::init_item();
}
