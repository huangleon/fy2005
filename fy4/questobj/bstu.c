#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "��ɽͼ" NOR, ({ "bstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ϸ�İ�ɽ��ͼ�����½�д��һ��С�֣�
���ƳǶ�ʮ��������ģ�����˫ʱ����\n");
          }
    ::init_item();
}
