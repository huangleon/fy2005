// garrison.c

#include <ansi.h>

inherit NPC;
#define LOWER_LIMIT 800000
#define DUMP_PLACE  AREA_LAOWU"road0.c"
void create()
{
        set_name("����˪", ({ "leng ruoshuang", "leng" }) );
        set("long",
"��λ������������������һ�ָ߲����ʣ�������˪�ĸо���
������̫��������̫�������ԣ������������ʶ��ʶ���������\n");
        set("attitude", "heroism");
		set("title", HIW "��ɽ"NOR);
		set("gender", "Ů��");
		set("per", 30);
		set("age",19);
        set("combat_exp", 100000);

		set("inquiry", ([
			"��ɲ��": "��ɲ������������ɲ����ɽ֮����ȴ������������˶ĳ��������ӣ�
û�뵽ȴ�ֱ������ӵ�����͵�ߣ����¶�����ɲ֪���˿϶�������ݣ�
��������ֻ�������汳���ˡ�\n",
			"��ɲ": "��ɲ������������ɲ����ɽ֮����ȴ������������˶ĳ��������ӣ�
û�뵽ȴ�ֱ������ӵ�����͵�ߣ����¶�����ɲ֪���˿϶�������ݣ�
��������ֻ�������汳���ˡ�\n",
			"��ɲ��": "��ɲ������������ɲ����ɽ֮����ȴ������������˶ĳ��������ӣ�
û�뵽ȴ�ֱ������ӵ�����͵�ߣ����¶�����ɲ֪���˿϶�������ݣ�
��������ֻ�������汳���ˡ�\n",
			"������":	"��������������ϰ壬���ں�����᷿�\n",
			"����ɲ":	"����ɲ��������̵�ͷ�����û����֪����������Ŀ��\n",		
			"������":	YEL"��ɲ��"CYN"���¶����ܵ��и���"YEL"����"CYN"���У������������ʵ����"YEL"����"CYN"��
�������ӣ��ҾͲ���Ϊ���ˡ�\n",
			"����":	"�������ӣ��ҾͲ���Ϊ���ˡ�\n",	
			"����":		(: command("point") :),		
			"�汳":		(: command("point") :),		
			"����":		"�����Ǹ���ϼѽ��\n",
			"��ϼ":		"���ˣ��Ҳ����ˣ�\n",
		]));
				
		
		
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/move", 100);

        setup();
        carry_object(__DIR__"obj/goldcloth")->wear();
}

void init()
{
	::init();
	add_action("do_know","know");
}

int do_know()
{
	object me;
	object dump;
	me = this_player();
	if((int) me->query("combat_exp") >= LOWER_LIMIT)
	{
		tell_object(me,"����˪̾�˿���������������ֻ��������"YEL"������"NOR"�ˣ���\n");
		tell_object(me,"����˪���㲻�������ķ���һ�����˯Ѩ��\n");
		me->unconcious();
		if (REWARD_D->riddle_check(me,"��ȡ��ɲ")<1)
			REWARD_D->riddle_set( me, "��ȡ��ɲ",1);
		dump = find_object(DUMP_PLACE);
		if (!dump) dump = load_object(DUMP_PLACE);
		me->move(dump);
	}	
	else
	{
		message_vision("$N��$n����һ˿��ǿ��Ц�ݣ����������ˣ���ﲻ���ң���\n",this_object(),me);
	}
	return 1;
}

int accept_object(object who, object ob){
	
	if (!REWARD_D->riddle_check(who,"��ȡ��ɲ"))	return 0;
	
	if (!ob->query("money_id"))	return 0;
	
	if (ob->query("value")<50000)	{
		command("say ��ô�����ֻ�����ϵ�ù�ˡ�");
		return 0;
	}
	
	command("sigh");
	command("say �ðɣ����Ҿ��������ˡ�");
	REWARD_D->riddle_clear(who,"��ȡ��ɲ");
	return 1;
}