#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"̴ľ��"NOR, ({ "tanmubox"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long",
"һ����ƽ����̴ľ�У�û���������ƺ�����һ�����Ϳ��Դ򿪸��ӡ� \n"NOR);
        }
	::init_item();
}
void init()
{
	if(this_player()==environment())
	{
		add_action("do_open","open");
	}
}

int do_open(string arg)
{
	object	me, ob;
    if(  arg != "tanmubox")
        return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N��$n��\n", me, ob);
	message_vision("ֻ����������Ľ��ޣ�����һ��ֽǩ�� 
����һ���ƾɵ�ֽǩ�������ʲݵ�д���� 
        ���޳��ţ����Լ�����\n ",me);
	set("open",1);
	set("long","һ���򿪵�̴ľ��,��������Ľ��ޣ�����һ��ֽǩ�� 
����һ���ƾɵ�ֽǩ�������ʲݵ�д���� 
        ���޳��ţ����Լ����� 
\n");
	if (me==query("�Ͷ�����"))
	{
		me->set("ɽ��/ʧ��",time());
		me->delete("��ɽ��/ȡ���˲�");
		me->delete("��ɽ��/�������");
		me->delete_temp("��ɽ��/�Ͷ���");
	}
	remove_action("do_open","open");
    return 1;
}

