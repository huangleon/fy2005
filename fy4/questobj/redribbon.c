// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIR"��˿��"NOR, ({ "red-ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIR
"��˿�������������̫�����κ������������˿������Զ��Ҫ�������Ŀ�ꡣ
��Ϊ˭Ҳ������û���������ϵ���ĺ�˿�У�������û���˿����������Ǹ��ˡ�
ϵ�����˿���ͱ�ʾ�����Ҫ�ܶ����ף���Ҳ�������κ�����ǰʾ����
���˿��ı���·���ܴ�����һ�ֲ������ӵ�������  \n"NOR);
        set("value",0);
		set("material", "cloth");
        set("armor_prop/armor", 5);
	}
	::init_head();
}
