inherit ITEM;

void create()
{
        set_name("��������ѩͼ��", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����澫�µġ�������ѩͼ����ֻ��û��ӡ����Ӧ����ġ֮����\n");
                set("value", 10000);
        }
        ::init_item();
}


