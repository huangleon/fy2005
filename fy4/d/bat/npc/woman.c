
#include <ansi.h>
inherit NPC;

void create()
{
    set_name("������", ({ "woman" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 30);
	set("long", 
"
��խС�ġ��ڰ��ķ��ӣ���������ȫ��������ȫ�����硣 
������û���꣬û���£�Ҳ�ֲ�����ҹ��
��ֻ����Զ�ںڰ��е��ţ�������ĵ��ţ��ȵ�������
�����û���κθ��εĻ�����(������)��
\n"
    );
	set("combat_exp", 300000);
	set("attitude", "friendly");

	setup();
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
	object me , *inv;
	int i;
	me = this_player();
	message_vision("$N���ּ��������˻���Ұ����Ϣ�ŵ�������ѽ����$n�Ѿ����ˣ�����ʲô?\n",
	this_object(),me);
        message_vision("$N����ӿ��һ��Ī��������ı�����������\n", me);
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;

}

