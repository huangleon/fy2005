#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("���߸������", ({ "letter", "��"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                                set("long",
"һ���û���������ʵʵ���ܺ������ƺ���������ػ����Կ���˺��(tear)\n"NOR);
        }
	::init_item();
}

void init()
{
  if(this_player()==environment()){
	add_action("do_tear","tear");

	}
}

int do_tear(string arg)
{
	object		me, ob;
        if(  arg != "letter" )
                return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N��$n�ķ��˺����ȡ�������е��ż�\n", me, ob);
	set("open",1);
	set("long","�߸����֣���������ã�������˵��ɴ��ã�
��ʾ��ȥ·�������ѻ٣�����˲������á� ���� ����\n");
	if (me==query("�Ͷ�����"))
	{
		me->set("ɽ��/ʧ��",time());
		me->delete("��ɽ��/ȡ���˲�");
		me->delete("��ɽ��/�������");
		me->delete_temp("��ɽ��/�Ͷ���");
	}
	remove_action("do_tear","tear");
    return 1;
}

