#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"����ͼ"NOR, ({ "cansong-tu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "����������̹���������������Ѳ��Ʋ����������й���Ҳ����˥�ܡ�\n");
          }

    ::init_item();
}
