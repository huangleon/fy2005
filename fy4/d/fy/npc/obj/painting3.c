inherit ITEM;

void create()
{
        set_name("�������Ϻ�ͼ��", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����澫�µġ������Ϻ�ͼ����ֻ��û��ӡ����Ӧ����ġ֮����\n");
                set("value", 30000);
        }
        ::init_item();
}


