#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("ԭʼ����������ָ��", ({ "hitch hiker's guide","guide"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("oops",1);
                set("long", "�����������������Ҫ��ԭʼ����������ָ�ϣ��������ѣ���������ë��");
                set("value", 3000);
				set("desc_ext","����̽��");
        }
        ::init_item();
}


