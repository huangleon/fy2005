#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	int i;
   string *order=({"����", "��ˮ", "ת��", "����",
"����","���","ȴа","���"});
	i=random(8);

    set_name("�ϵ���"+order[i], ({ "broken sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit", "��");
	set("long", "һ�Ѷϵ���"+order[i]+"����˵��Խ���˽�֮һ����˵��˽�����Զ��ʱ��һ��������ʯ
��Ϊ�˿�����ɣ���˵���ǰ˿鼯�룬��������������֮�ˣ����о������������\nu");
	set("value", 100);
	set("no_reset",1);
	set("material", "steel");
	}

    ::init_sword(1);
}

