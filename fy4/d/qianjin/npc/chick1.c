#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("�Ѻ�", ({ "girl" }) );
	set("title", HIM "��������"NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
�Ѻ��Ƿ��Ƴǵ����ˣ���������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 3000);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
		if((int)obj->value() >= 1000) me->add_temp("marks/chick1",1);
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
	if((int)me->query_temp("marks/chick1") <=0)
	{
        command("say ��Ӵ��������λ" + RANK_D->query_respect(me) +
	"������û���;���ռ�˼ҵı���ô��");
	return 1;
	}
	me->add_temp("marks/chick1",-1);
	message_vision("$N��ƮƮ����$n�߹���������ĸ�Ū$n�ĺڷ�������\n",this_object(),me);
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
        if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		if(!DROP_CMD->do_drop(me, inv[i])) {
			destruct(inv[i]);
		}
	}
	me->unconcious();
	me->full_me();
	wo = new(__DIR__"obj/wo");
	wo->move(me);
	return 1;
}
