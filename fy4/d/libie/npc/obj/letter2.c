#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("�Ϲ�ʮ���ɵ���", ({ "letter", "��"}) );
        set_weight(50);
        set("for_di",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                                set("long",
"���Ƿ���������飺
      ����֮���Ѱ��ס�
      
      			�Ϲ�ʮ����"NOR);
        }
	::init_item();
}
