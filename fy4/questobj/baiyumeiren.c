#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��������"NOR, ({ "yumeiren" }) );
    set_weight(50);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", WHT"һ�����ֵ�ɣ���Ө������İ������ˣ������·�������ӣ���ʳ
�˼��̻𣬵�˧��������Ϊ�������������أ���������ͬ������
�峺��һ����ˮ��̤�¾��ǣ������������ض���\n"NOR);
          }

    ::init_item();
}
