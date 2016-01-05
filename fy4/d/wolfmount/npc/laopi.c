#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("��Ƥ", ({ "laopi" }) );
        set("title", "��Ƥ��" );
        set("long",
                "�ߴ����䡢��ò���ã�������ϲ����Ƥ����Ƥ�ȳ�ǽ���񡣡�\n"
                );

        set("attitude", "peaceful");
        set("age", 35);

	set("no_arrest",1);
        set("combat_exp", 50000);

        set("chat_chance", 1);
        set("chat_msg", ({
                (: checking :),
        }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 30);

        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_whisper","whisper");
}

void checking()
{
        object laopi,sunwaiter;
	laopi = this_object();

        if (sunwaiter = present("sun legate",environment()))
	{
		message_vision("$N�ϵع��ڵ��ϣ�����$n���ŵ�˫�㡣\n",laopi,sunwaiter);
	}
	else
        {
        	message_vision("$NͻȻ������ͺǺǵ�ɵЦ������һ����ˮ˳���������...\n",laopi);
	}        
}

int do_whisper(string arg)
{
	object me,laopi;
	string dest, msg;
	me = this_player();
	laopi=this_object();

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲ�᣿\n");
	if (dest != "laopi") return 0;
	
	if (me->is_fighting())	
	{
		tell_object(me,"���ʱ���п���˵����\n");
		return 1;
	}
	if (msg == "С��" || msg == "xiaoma")
	{
		message_vision("$N�ճ����ԣ���֪��λش�$n��\n",laopi,me);
		me->set_temp("marks/wolf_asked_laopi",1);
		return 1;
	}
	else if ((msg == "����" || msg == "friend" || msg == "С�������")&& me->query_temp("marks/wolf_asked_laopi"))
	{
		message_vision("$N��$nգգ�ۣ�������̫��ʹ�ߵĽš�\n",laopi,me);
		me->delete_temp("marks/wolf_asked_laopi");
		me->set_temp("marks/wolf_laopi_friend",1);
		return 1;
	}
	else
		return 0;
}
