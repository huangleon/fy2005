#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"������˫��"NOR, ({ "xiayiling" }) );
    set_weight(100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "���ǡ��޹�ɽׯ��������������ȥ�ǽ�����ʵؼ�Ӳ�ޱȣ�������Ȼ�к�⸡�֣�\n����ִ�����ߣ������޹�ɽׯׯ���������������֣�Ī�Ҳ��ӡ�\n");
          }

    ::init_item();
}
