#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB "������" NOR, ({ "shengsibu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", @LONG
����һ��������С���ӣ���������������ʹ�׭���������������ഫ����
��֮�˿ɽ��Լ������ֹ������ó������ϣ���һ��ʱ�����粻��֮�͵���
�ܵظ���������й٣������������׻�������սս�����ط������ӣ���ʧ
�����ط�������ȫ���������������ģ������Ҳ���������֣�
LONG);
          }

    ::init_item();
}
