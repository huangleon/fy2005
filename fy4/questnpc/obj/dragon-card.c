#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"������"NOR, ({ "qinglong-ling"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long",
"�����������������Ӵ����֯�������ᣬΪ���ٿ����³��źڵ�ͬ�˴�ᣬ������\n�������ºڵ�Ⱥ���������ƾ������ɸ�Լ�ڵ���ᡣ��ɽ��Ϊ����ֹ��κڵ���\n�ᣬ�������º�����Ѱ��Щ����� \n"NOR);
        }
	::init_item();
}

