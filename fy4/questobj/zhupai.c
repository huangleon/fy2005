#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"������"NOR, ({ "luanzhu-tie" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "bamboo");
	        set("long", @LONG
�����꺮����֮�������˵������������������ʱ��ͷ���ī������������գ����һӷţ����޽��ɡ�
LONG);
          }

    ::init_item();
}
