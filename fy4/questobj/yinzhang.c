#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"֪��ӡ��"NOR, ({ "yinzhang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "stone");
        	        set("long", @LONG
һ�����Ž�ߵ�֪����ӡ�������������ϸ��£�����죩��
һ������͸�������İ�����Ȼʱ�������������Ͽ̻��������µĺۼ���
������Ϊ�����˴��������ߵ����������������Բ��������������Ҳ
��������ºͶ��������ر��Գ����ĵ�λ�Ͳ�����һ������������ϵ�
׭�ģ��������õ�ʹ�ú��Ѿ�ģ���ı��ϲ������ֵķֽ��ߣ����Ǵ�
��û���κ��˻��ɹ��������Ȩ�������š�
LONG);
	}
	::init_item();
}

void init()
{
        add_action("do_seal", "seal");
}

int do_seal(string arg)
{
	object obj;

	if (environment(this_object())!=this_player())
		return 0;
	if (!arg)
		return notify_fail("��Ҫ�������ӡ��\n");
	if (!objectp(obj=present(arg,this_player())))
		return notify_fail("��Ҫ��ʲô�ط���ӡ��\n");
	if (obj==this_object())
		return notify_fail("�㲻����ӡ�±����ϸ�ӡ��\n");
	
	message_vision("$N��"+this_object()->query("name")+"���˿�������"+obj->query("name")+"��С������ظ���һ��ӡ�¡�\n",this_player());
	obj->set("sealed",1);

	return 1;
}
