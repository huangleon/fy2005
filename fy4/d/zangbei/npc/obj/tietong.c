#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name("��Ͳ", ({ "box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��ڵ���Ͳ�����䰵������Ͳ������֮���ɣ����ƻ�������������
�µġ�����ʮ�أ���ħ���롻֮�ϡ�
LONG);
                set("material", "iron");
        }
        ::init_item();
}


void init()
{
	add_action("do_shoot","shoot");
}


int do_shoot(string arg)
{
	return notify_fail("�㲦Ū�˼��£��ƺ��Ҳ�������Ļ��ء�\n");
	
}
