// yangfan.c

//inherit F_LEADER;
inherit NPC;


#include <ansi.h>
void create()
{
	set_name("�", ({ "yang fan", "yang"}) );
	set("gender", "����" );
	set("age", 28);
	set("title","ɽ�� ����");
        set("nickname",HIY"��ͷ"NOR);
	set("long",
"���Ǹ��������ֵ������ˣ�ԲԲ������һ˫�۾�ȴ��ϸ�ֳ�����ܴ�ͷ���󣬿�����
�е�����˽䡣����������ȴ�ܴ����򶨣���������˵���е����������ӡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�գ��գ�ۣ��ֺǺǺ���С������ͷ��ͷ�����겻�������ɡ�����д�ͷ��\n",
    }) );
        set("inquiry",  ([
                "ɽ��" : "ɽ��ֻ��һȺ��ƽ�����ˣ���ȴ��Ϊ��һ����ƽ������������ڡ�\n",
                "shanliu" : "ɽ��ֻ��һȺ��ƽ�����ˣ���ȴ��Ϊ��һ����ƽ������������ڡ�\n",
                "Ѫ��ϭ": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                "questnpc": "Ѫ��ϭ���˽Գư�һ���ĺڵ����ɣ�����С�ӡ�\n",
                ])                      );

	set("combat_exp", 80000000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 100);
	set("force",50000);
	set("max_force",50000);
	set("force_factor",500);
	set("org_ranks",({
"��ʿ","����","����ʹ��","ƽ������" }));

	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("changquan", 200);
        set_skill("fall-steps", 200);
        map_skill("unarmed", "changquan");
        map_skill("dodge", "fall-steps");
	setup();
        carry_object("obj/armor/cloth")->wear();
	create_organization("ɽ��",1,"��");
}


void init()
{
	object ob;
	::init();
	if( userp(ob = this_player()))
	if(ob->query_temp("ɽ��/������"))
	{
		remove_call_out("greeting");
                call_out("greeting", 30, ob);
        }
	add_action("do_kill","kill");
	add_action("do_answer","answer");
}

void greeting(object me)
{
	if(!me ||environment(me)!=environment())
		return ;
	if(!living(me))
		me->revive();
	message_vision(CYN"$N������˫�ֳ���ϸ���۾�����$nЦ��Ц˵�����ֹ�Ȼ��ͬ�����ˡ�\n"NOR,this_object(),me);
	message_vision(CYN"$NͻȻ��ɫ��Ȼ��֣�صض�$n˵���ã������Ը��ɽ������Ȼ��ӭ���롺ɽ������\n��join yang fan����\n"NOR,this_object(),me);
	return ;
}


void accept_member(object me)
{
	command("smile");
	command("enroll "+me->query("id"));
        message_vision(HIC"$N����Ƭ������Ȼ�������������������ڹ��ᣬ��ͼ�������ºڵ��������ڵ�����
�޲��յ��䡺��������������뽫��Ѫ��ϭ����questnpc���и������۵��������֮��
���ظ��֣��¹ؽ���������˥����������С�����£�\n"NOR,this_object(),me);
	me->delete("��ɽ��");
	me->delete_temp("ɽ��");
}

void attempt_join(object me)
{
	if(me->query_temp("ɽ��/������"))
		accept_member(me);
	else
		message_vision("�ϸüһ�壬��������֣��������ð�����ġ�\n",this_object());
}


int do_kill(string arg)
{
	object me;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
		me->set("ɽ��/ʧ��",time());
	return 0;
}

/*
int do_answer(string arg)
{
	
	for (i=0;i<=10 ; i++)
	{
		say(string(i)+"\n");
		if ((string)i == arg)
			break
	}
}
*/