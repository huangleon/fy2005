#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"����"NOR, ({ "qipan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            	        set("long", @LONG
���߶��ݣ�������֮������ս������Ͷ�����ң��������ƣ�������˧��
�����������ù�����Ȼ�����ӱϾ���û���������ľ���������ݺ�
ʮ�ŵ������ϣ���Ȼ�������������µı仯�������Ծ��г����Ϊ����
���ߡ�
LONG);
          }

    ::init_item();
}
