inherit ITEM;

void create()
{
        set_name("���ݽ����ͬ", ({ "payoff contract"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ŷ��ݵĺ�ͬ���ִ˿����Լ�������ִ��payoffָ�\n");
                set("value", 100000);
        }
        ::init_item();
}


