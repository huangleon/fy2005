
inherit ITEM;

void create()
{
        set_name("����", ({"paper", "letter"}) );
		set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_split",1);
                set("long", "СֽƬ��ֻ���������У�

�㵽�������Ű��죬���ж�����Ҫɱ�㣿��Ҫ��Ҫ�˰��㣿
                
            ��ү
\n");
                set("value", 1);
        }
}

